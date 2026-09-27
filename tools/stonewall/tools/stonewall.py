"""Project Stonewall - carry player-built bases from a live op into the next mission.

  extract  RPT(s)            -> snapshot.json   (what stonewall_save.sqf logged)
  clean    snapshot.json     -> kept.json + report.md   (only built objects inside keep areas)
  bake     kept.json MISSION -> NEW mission folder (+ optional .pbo) with a "Stonewall" Eden layer

Nothing is modified in place: every output path must not exist yet.
"""
from __future__ import annotations

import argparse
import datetime as dt
import hashlib
import json
import math
import re
import shutil
import struct
import subprocess
import sys
import tempfile
from collections import Counter, defaultdict
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import sqmtext  # noqa: E402

PRODUCTION = Path(r"D:\Codex\Mapmaking_Omnibus_Production")
sys.path.insert(0, str(PRODUCTION / "vendor"))
sys.path.insert(0, str(PRODUCTION / "preflight"))
from eden_rotation import eden_angles, eden_matrix, basis_enu  # noqa: E402

CFGCONVERT = Path(r"C:/Program Files (x86)/Steam/steamapps/common/Arma 3 Tools/CfgConvert/CfgConvert.exe")
VERSION = "1.2.4"
LINE = re.compile(r'STONEWALL\|([^|"\s]+)\|([HACOE])\|(.*?)"?\s*$')

KEEP_SOURCES = {"fortify", "daidalos", "built"}          # exact tags: never editor objects
OPTIN_SOURCES = {"zeus": "include_zeus", "spawned": "include_spawned"}   # server/HC/Zeus-made: opt-in
DIFF_SOURCES = {"fortify_class", "unknown"}              # kept only if not an editor object of the live mission
DEFAULT_KINDS = {"static", "thing"}                        # static_weapon / other / vehicles / box are opt-in
DEFAULT_EXCLUDE = [r"^ACE_(Wheel|Track)$", r"^ACE_bodyBagObject(_\w+)?$", r"^ACE_Grave"]   # spare parts; body bags (all colours) and graves


def die(msg):
    raise SystemExit(f"stonewall: {msg}")


def fresh(path: Path):
    if path.exists():
        die(f"output already exists, pick a new path: {path}")
    return path


# ---------------------------------------------------------------- extract
O_FIELDS = ["i", "cls", "x", "y", "z", "dx", "dy", "dz", "ux", "uy", "uz", "src", "kind", "alive", "dmg",
            "simple", "sim", "hidden", "scale", "born", "areas", "var"]


def parse_rpt_lines(paths):
    sessions = defaultdict(lambda: {"H": None, "A": {}, "C": {}, "O": {}, "E": None, "files": set()})
    for p in paths:
        with open(p, encoding="utf-8", errors="replace") as f:
            for raw in f:
                m = LINE.search(raw)
                if not m:
                    continue
                sid, kind, rest = m.group(1), m.group(2), m.group(3)
                if raw.rstrip().endswith('"'):          # client copy logged as a quoted string
                    rest = rest.replace('""', '"')
                s = sessions[sid]
                s["files"].add(str(p))
                f_ = rest.split("|")
                if kind == "H":
                    s["H"] = dict(kv.split("=", 1) for kv in f_ if "=" in kv)
                elif kind == "E":
                    s["E"] = dict(kv.split("=", 1) for kv in f_ if "=" in kv)
                elif kind == "C":
                    s["C"][f_[0]] = [a for a in (f_[1] if len(f_) > 1 else "").split(";") if a]
                elif kind == "A":
                    idx, marker, akind, shape, x, y, a, b, d = f_[:9]
                    s["A"][int(idx)] = {"i": int(idx), "marker": marker, "kind": akind, "shape": shape,
                                        "x": float(x), "y": float(y), "a": float(a), "b": float(b),
                                        "dir": float(d), "text": "|".join(f_[9:])}
                elif kind == "O":
                    if len(f_) < len(O_FIELDS) - 1:
                        continue
                    o = dict(zip(O_FIELDS, f_ + [""] * (len(O_FIELDS) - len(f_))))
                    for k in ("x", "y", "z", "dx", "dy", "dz", "ux", "uy", "uz", "dmg", "scale", "born"):
                        o[k] = float(o[k])
                    for k in ("i", "alive", "simple", "sim", "hidden"):
                        o[k] = int(o[k])
                    o["areas"] = [int(a) for a in o["areas"].split(";") if a != ""]
                    s["O"][o["i"]] = o
    return sessions


def cmd_extract(a):
    out = fresh(Path(a.out))
    sessions = parse_rpt_lines([Path(p) for p in a.rpt])
    if not sessions:
        die("no STONEWALL lines found in " + ", ".join(a.rpt))
    if a.sid:
        if a.sid not in sessions:
            die(f"session {a.sid} not found; have: {', '.join(sorted(sessions))}")
        sid = a.sid
    else:
        if len(sessions) > 1 and not a.latest:
            lines = [f"  {k}: mission {v['H'].get('mission') if v['H'] else '?'}, "
                     f"{v['E'].get('objects') if v['E'] else 'INCOMPLETE'} objects" for k, v in sorted(sessions.items())]
            die("several saves in these RPTs - pick one with --sid (or --latest):\n" + "\n".join(lines))
        sid = sorted(sessions)[-1]
    s = sessions[sid]
    if s["H"] is None or s["E"] is None:
        die(f"save {sid} is incomplete (header or end line missing) - was the RPT copied before the save finished?")
    expected = int(s["E"]["objects"])
    in_area = int(s["E"]["in_areas"])
    got = len(s["O"])
    partial = got < expected
    if got < in_area:
        die(f"save {sid}: only {got} of {in_area} in-area object lines were found")
    snap = {"format": "stonewall-snapshot/1", "tool": VERSION, "sid": sid, "header": s["H"], "end": s["E"],
            "partial_copy": partial, "source_files": sorted(s["files"]),
            "areas": [s["A"][k] for k in sorted(s["A"])], "class_addons": s["C"],
            "objects": [s["O"][k] for k in sorted(s["O"])]}
    out.write_text(json.dumps(snap, indent=1), encoding="utf-8")
    print(f"save {sid}: world {s['H'].get('world')}, mission {s['H'].get('mission')}, {got}/{expected} objects"
          f"{' (client copy: in-area objects only)' if partial else ''}, {len(s['A'])} keep areas -> {out}")


# ---------------------------------------------------------------- mission reading
def read_sqm_bytes(b: bytes) -> str:
    if b.startswith(b"\0raP"):
        if not CFGCONVERT.is_file():
            die(f"binarized mission.sqm needs CfgConvert: {CFGCONVERT}")
        with tempfile.TemporaryDirectory(prefix="stonewall-") as t:
            src, dst = Path(t) / "mission.sqm", Path(t) / "mission.txt"
            src.write_bytes(b)
            r = subprocess.run([str(CFGCONVERT), "-txt", "-dst", str(dst), str(src)], capture_output=True, timeout=300)
            if r.returncode != 0 or not dst.is_file():
                die("CfgConvert failed: " + (r.stdout + r.stderr).decode(errors="replace")[-500:])
            b = dst.read_bytes()
    if b.startswith(b"\xef\xbb\xbf"):
        b = b[3:]
    return b.decode("utf-8", errors="surrogateescape")   # non-UTF-8 bytes survive the round trip unchanged


def load_mission_sqm(path: Path):
    """Return (sqm_text, members) for a mission folder, a mission.sqm, or a mission .pbo."""
    path = Path(path)
    if path.is_dir():
        return read_sqm_bytes((path / "mission.sqm").read_bytes()), None
    if path.suffix.lower() == ".sqm":
        return read_sqm_bytes(path.read_bytes()), None
    if path.suffix.lower() == ".pbo":
        from mission_preflight import PBO
        pbo = PBO(path)
        return read_sqm_bytes(pbo.get("mission.sqm")), pbo
    die(f"not a mission folder, mission.sqm or .pbo: {path}")


def editor_objects(sqm_text):
    root = sqmtext.parse(sqm_text)
    ents = root.path("Mission", "Entities")
    out = []
    for node, _ in sqmtext.iter_entities(ents):
        if node.prop("dataType") != "Object":
            continue
        pi = node.cls("PositionInfo")
        pos = pi.prop("position") if pi else None
        if not pos or len(pos) != 3:
            continue
        out.append((str(node.prop("type", "")).casefold(), float(pos[0]), float(pos[2]), float(pos[1])))
    return out


# ---------------------------------------------------------------- clean
def in_area(o, ar, margin):
    dx, dy = o["x"] - ar["x"], o["y"] - ar["y"]
    t = math.radians(ar["dir"])
    # marker dir is clockwise from north; rotate the offset into the marker frame
    lx = dx * math.cos(t) - dy * math.sin(t)
    ly = dx * math.sin(t) + dy * math.cos(t)
    a, b = ar["a"] + margin, ar["b"] + margin
    if ar["shape"] == "RECTANGLE":
        return abs(lx) <= a and abs(ly) <= b
    return (lx / a) ** 2 + (ly / b) ** 2 <= 1.0


def area_label(ar):
    text = ar["text"].strip()
    if ar["kind"] == "text":
        words = text.split()[1:]
        words = [w for w in words if not re.fullmatch(r"[\d.]+m?", w)]
        text = " ".join(words)
    if not text and ar["kind"] == "zen":
        return "Zeus area " + ar["marker"].rsplit("_", 1)[-1]
    return text or ar["marker"]


def cmd_clean(a):
    snap = json.loads(Path(a.snapshot).read_text(encoding="utf-8"))
    out, rep = fresh(Path(a.out)), fresh(Path(a.report))
    areas = [ar for ar in snap["areas"] if ar["i"] not in set(a.drop_area or [])]
    if not areas:
        die("no keep areas in this save (mark bases with a Zen area marker, a 'KEEP 60' map marker or the Stonewall module)")
    kinds = set(DEFAULT_KINDS) | set(a.include_kind or [])
    excl = [re.compile(p, re.I) for p in DEFAULT_EXCLUDE + (a.exclude_class or [])]
    editor, live_note = [], "no live mission given"
    if a.live_mission:
        editor = editor_objects(load_mission_sqm(Path(a.live_mission))[0])
        live_note = f"{len(editor)} editor objects in {Path(a.live_mission).name}"
    grid = defaultdict(list)
    for e in editor:
        grid[(int(e[1] // 10), int(e[2] // 10))].append(e)

    def is_editor(o):
        c = o["cls"].casefold()
        gx, gy = int(o["x"] // 10), int(o["y"] // 10)
        for i in (-1, 0, 1):
            for j in (-1, 0, 1):
                for e in grid.get((gx + i, gy + j), ()):
                    if e[0] == c and math.hypot(e[1] - o["x"], e[2] - o["y"]) <= a.editor_tolerance \
                            and abs(e[3] - o["z"]) <= 3.0:
                        return True
        return False

    kept, dropped = [], Counter()
    unknown_kept = Counter()
    for o in snap["objects"]:
        hit = [ar for ar in areas if in_area(o, ar, a.margin)]
        if not hit:
            dropped["outside keep areas"] += 1
            continue
        if not o["alive"]:
            dropped["destroyed"] += 1
            continue
        if o.get("hidden"):
            dropped["hidden object"] += 1
            continue
        if o["kind"] not in kinds:
            dropped[f"kind {o['kind']}"] += 1
            continue
        if any(p.search(o["cls"]) for p in excl):
            dropped["excluded class"] += 1
            continue
        src = o["src"]
        if src in OPTIN_SOURCES and not getattr(a, OPTIN_SOURCES[src]):
            dropped["zeus-placed" if src == "zeus" else "spawned by server/HC script (--include-spawned)"] += 1
            continue
        # a tag is just an object variable a client could forge, so every source gets the editor check when possible
        if src not in DIFF_SOURCES and editor and is_editor(o):
            dropped["editor object of the live mission"] += 1
            continue
        if src in DIFF_SOURCES:
            if not a.live_mission and not a.keep_unknown:
                dropped["no build tag (give --live-mission or --keep-unknown)"] += 1
                continue
            if is_editor(o):
                dropped["editor object of the live mission"] += 1
                continue
            if src == "unknown":
                unknown_kept[o["cls"]] += 1
        elif src not in KEEP_SOURCES and src not in OPTIN_SOURCES:
            dropped[f"source {src}"] += 1
            continue
        k = dict(o)
        k["area"] = hit[0]["i"]
        kept.append(k)

    doc = {"format": "stonewall-kept/1", "tool": VERSION, "sid": snap["sid"], "world": snap["header"].get("world"),
           "mission": snap["header"].get("mission"), "areas": areas, "class_addons": snap["class_addons"],
           "objects": kept, "dropped": dict(dropped),
           "settings": {"margin": a.margin, "kinds": sorted(kinds), "include_zeus": a.include_zeus,
                        "include_spawned": a.include_spawned,
                        "exclude_class": a.exclude_class or [], "live_mission": a.live_mission,
                        "editor_tolerance": a.editor_tolerance, "keep_unknown": a.keep_unknown}}
    out.write_text(json.dumps(doc, indent=1), encoding="utf-8")

    L = [f"# Stonewall clean report - save {snap['sid']}", "",
         f"World **{doc['world']}**, mission **{doc['mission']}**. Tool {VERSION}.",
         f"Snapshot: {len(snap['objects'])} objects{' (client copy: in-area objects only)' if snap.get('partial_copy') else ''}. "
         f"Kept **{len(kept)}** in {len(areas)} keep areas. Editor check: {live_note}.", ""]
    if unknown_kept and not a.live_mission:
        L += ["**Warning:** `--keep-unknown` kept objects with no build tag without an editor check, so editor-placed "
              "objects inside the keep areas may be duplicated. Prefer `--live-mission <the op's .pbo>`.", ""]
    if dropped.get("no build tag (give --live-mission or --keep-unknown)"):
        L += ["**Note:** objects with no build tag were dropped because no live mission was given. If the op had no "
              "Stonewall addon, re-run with `--live-mission <the op's .pbo>` to keep them.", ""]
    L += ["## Keep areas", "", "| # | Name | Marker | Shape | Size (m) | Kept | By source | Top classes |",
          "|---|---|---|---|---|---|---|---|"]
    by_area = defaultdict(list)
    for k in kept:
        by_area[k["area"]].append(k)
    for ar in areas:
        ks = by_area.get(ar["i"], [])
        src = ", ".join(f"{s} {n}" for s, n in Counter(k["src"] for k in ks).most_common())
        top = ", ".join(f"{c} x{n}" for c, n in Counter(k["cls"] for k in ks).most_common(5))
        L.append(f"| {ar['i']} | {area_label(ar)} | `{ar['marker']}` ({ar['kind']}) | {ar['shape'].lower()} | "
                 f"{2 * ar['a']:.0f} x {2 * ar['b']:.0f} | {len(ks)} | {src or '-'} | {top or '-'} |")
    L += ["", "## Dropped", ""] + ([f"- {r}: {n}" for r, n in dropped.most_common()] or ["- nothing"])
    scaled = sum(1 for k in kept if abs(k["scale"] - 1.0) > 0.01)
    if scaled:
        L += ["", f"**Note:** {scaled} kept objects were scaled in game; the baked copies load at normal size."]
    if unknown_kept:
        L += ["", "## Kept without a build tag (check these)", ""] + \
             [f"- {c} x{n}" for c, n in unknown_kept.most_common(30)]
    rep.write_text("\n".join(L) + "\n", encoding="utf-8")
    print(f"kept {len(kept)} objects in {len(areas)} areas; dropped {sum(dropped.values())} -> {out}, {rep}")


# ---------------------------------------------------------------- bake
def angles_from_vectors(o):
    d = (o["dx"], o["dy"], o["dz"])
    u = (o["ux"], o["uy"], o["uz"])
    nd = math.sqrt(sum(v * v for v in d))
    d = tuple(v / nd for v in d)
    dot = sum(x * y for x, y in zip(d, u))
    u = tuple(x - dot * y for x, y in zip(u, d))
    nu = math.sqrt(sum(v * v for v in u))
    u = tuple(v / nu for v in u)
    s = (d[1] * u[2] - d[2] * u[1], d[2] * u[0] - d[0] * u[2], d[0] * u[1] - d[1] * u[0])  # dir x up = local east
    ehn = lambda v: (v[0], v[2], v[1])  # noqa: E731
    c0, c1, c2 = ehn(s), ehn(u), ehn(d)
    m = tuple(tuple(col[r] for col in (c0, c1, c2)) for r in range(3))
    ang = eden_angles(m, positive=True, validation_tolerance=1e-6)
    back_d, back_u = basis_enu(eden_matrix(ang))
    err = max(abs(p - q) for p, q in zip(back_d + back_u, d + u))
    if err > 1e-6:
        die(f"rotation round-trip error {err} for {o['cls']}")
    return ang


def fmt(v, nd=6):
    s = f"{v:.{nd}f}".rstrip("0").rstrip(".")
    return "0" if s in ("-0", "") else s


def validate_sqm(text, want_items):
    """Refuse to write a mission the dedicated server would crash on (Item gaps, duplicate ids, stale nextID)."""
    root = sqmtext.parse(text)
    ents = root.path("Mission", "Entities")
    if ents is None or len(ents.classes) != want_items or int(ents.prop("items", -1)) != want_items:
        die(f"bake self-check: Mission > Entities should hold {want_items} items")
    ids = []

    def walk(node):
        e = node.cls("Entities")
        if e is not None:
            if int(e.prop("items", -1)) != len(e.classes):
                die(f"bake self-check: {node.name or 'root'} Entities items={e.prop('items')} but {len(e.classes)} children")
            for k, c in enumerate(e.classes):
                if c.name.casefold() != f"item{k}":
                    die(f"bake self-check: child {k} of {node.name} is named {c.name}")
                if isinstance(c.prop("id"), int):
                    ids.append(c.prop("id"))
                walk(c)
    walk(root.cls("Mission"))
    if len(ids) != len(set(ids)):
        die("bake self-check: duplicate entity ids")
    lst = root.path("AddonsMetaData", "List")
    if lst is not None:
        if int(lst.prop("items", -1)) != len(lst.classes) or any(
                c.name.casefold() != f"item{k}" for k, c in enumerate(lst.classes)):
            die("bake self-check: AddonsMetaData List items/children mismatch")
    idp = root.path("EditorData", "ItemIDProvider")
    if idp is not None and ids and int(idp.prop("nextid", 0)) <= max(ids):
        die("bake self-check: ItemIDProvider nextID is not above the highest id")


def build_layer(doc, first_id, indent, layer_name):
    """Return (text, ids_used, layers_used) for one Layer item holding a sub-layer per keep area."""
    nid = first_id
    T = "\t"

    def block(lines, depth):
        return [T * (indent + depth) + ln for ln in lines]

    by_area = defaultdict(list)
    for o in doc["objects"]:
        by_area[o["area"]].append(o)
    areas = [ar for ar in doc["areas"] if by_area.get(ar["i"])]
    top_id = nid
    nid += 1
    out = block(["{", '\tdataType="Layer";', f"\tname={sqmtext.sqm_string(layer_name)};", f"\tid={top_id};",
                 "\tclass Entities", "\t{", f"\t\titems={len(areas)};"], 0)
    for ai, ar in enumerate(areas):
        lid = nid
        nid += 1
        objs = by_area[ar["i"]]
        out += block([f"class Item{ai}", "{", '\tdataType="Layer";',
                      f"\tname={sqmtext.sqm_string('Keep ' + area_label(ar))};", f"\tid={lid};",
                      "\tclass Entities", "\t{", f"\t\titems={len(objs)};"], 2)
        for oi, o in enumerate(objs):
            a0, a1, a2 = angles_from_vectors(o)
            ang = "" if max(abs(math.remainder(v, math.tau)) for v in (a0, a1, a2)) < 1e-7 else \
                f"\t\tangles[]={{{fmt(a0, 7)},{fmt(a1, 7)},{fmt(a2, 7)}}};"
            attrs = []
            if not o["sim"] and o["kind"] in ("static", "other"):
                attrs.append("\t\tdisableSimulation=1;")
            lines = [f"class Item{oi}", "{", '\tdataType="Object";', "\tclass PositionInfo", "\t{",
                     f"\t\tposition[]={{{fmt(o['x'], 4)},{fmt(o['z'], 4)},{fmt(o['y'], 4)}}};"]
            lines += [ang] if ang else []
            lines += ["\t};", '\tside="Empty";', "\tflags=4;", "\tclass Attributes", "\t{"] + attrs + ["\t};",
                      f"\tid={nid};", f"\ttype={sqmtext.sqm_string(o['cls'])};", "};"]
            nid += 1
            out += block(lines, 4)
        out += block(["\t};", "};"], 2)
    out += block(["\t};", "};"], 0)
    return "\n".join(out), nid - first_id, 1 + len(areas)


def bake_text(sqm_text, doc, layer_name):
    root = sqmtext.parse(sqm_text)
    ents = root.path("Mission", "Entities")
    if ents is None:
        die("mission.sqm has no Mission > Entities")
    n_items = int(ents.prop("items", 0))
    if n_items != len(ents.classes):
        die(f"Mission > Entities says items={n_items} but has {len(ents.classes)} children - fix the source first")
    for k, c in enumerate(ents.classes):
        if c.name.casefold() != f"item{k}":
            die(f"Mission > Entities child {k} is named {c.name} (must be Item{k}) - fix the source first")
    ed = root.cls("EditorData")
    idp = ed.cls("ItemIDProvider") if ed else None
    lip = ed.cls("LayerIndexProvider") if ed else None
    first = max(sqmtext.max_id(root) + 1, int(idp.prop("nextid", 0)) if idp else 0)

    # indent of existing Mission>Entities items
    line_start = sqm_text.rfind("\n", 0, ents.start) + 1
    base_indent = len(sqm_text[line_start:ents.start]) - len(sqm_text[line_start:ents.start].lstrip("\t"))
    layer, used, layers = build_layer(doc, first, base_indent + 1, layer_name)
    item = "\t" * (base_indent + 1) + f"class Item{n_items}\n" + layer + "\n"

    edits = []  # (start, end, replacement)
    close_line = sqm_text.rfind("\n", 0, ents.end) + 1
    if sqm_text[close_line:ents.end].strip():          # "}" shares its line with content: insert right before it
        edits.append((ents.end, ents.end, "\n" + item))
    else:
        edits.append((close_line, close_line, item))
    s, e = ents.spans["items"]
    edits.append((s, e, f"items={n_items + 1};"))
    if idp is not None:
        s, e = idp.spans["nextid"]
        edits.append((s, e, f"nextID={first + used};"))
    if lip is not None and "nextid" in lip.spans:
        s, e = lip.spans["nextid"]
        edits.append((s, e, f"nextID={int(lip.prop('nextid')) + layers};"))

    # addons[] - add CfgPatches the new classes need
    need = []
    for o in doc["objects"]:
        defs = doc["class_addons"].get(o["cls"], [])
        for ad in (defs if isinstance(defs, list) else [defs])[:1]:
            if ad not in need:
                need.append(ad)
    have = [str(x) for x in (root.prop("addons") or [])]
    missing = [ad for ad in need if ad.casefold() not in {h.casefold() for h in have}]
    if missing:
        if "addons" in root.spans:
            s, e = root.spans["addons"]
            allv = have + missing
            edits.append((s, e, "addons[]=\n{\n" + ",\n".join("\t" + sqmtext.sqm_string(x) for x in allv) + "\n};"))
        amd = root.path("AddonsMetaData", "List")
        if amd is not None and "items" in amd.spans:
            k0 = int(amd.prop("items", 0))
            s, e = amd.spans["items"]
            edits.append((s, e, f"items={k0 + len(missing)};"))
            cl = sqm_text.rfind("\n", 0, amd.end) + 1
            one_line = bool(sqm_text[cl:amd.end].strip())
            add = "".join(f"\t\tclass Item{k0 + j}\n\t\t{{\n\t\t\tclassName={sqmtext.sqm_string(ad)};\n"
                          f"\t\t\tname={sqmtext.sqm_string(ad)};\n\t\t}};\n" for j, ad in enumerate(missing))
            edits.append((amd.end, amd.end, "\n" + add) if one_line else (cl, cl, add))

    out = sqm_text
    for s, e, r in sorted(edits, key=lambda t: t[0], reverse=True):
        out = out[:s] + r + out[e:]
    validate_sqm(out, n_items + 1)
    return out, {"first_id": first, "ids": used, "layers": layers, "addons_added": missing,
                 "entities_before": n_items, "entities_after": n_items + 1}


def write_pbo(folder: Path, pbo_path: Path, props=None, exclude=()):
    files = sorted(p for p in folder.rglob("*") if p.is_file() and p.name not in exclude)
    head = bytearray(b"\0" + struct.pack("<5I", 0x56657273, 0, 0, 0, 0))
    for k, v in (props or {}).items():
        head += k.encode() + b"\0" + v.encode() + b"\0"
    head += b"\0"
    body = bytearray()
    for p in files:
        rel = str(p.relative_to(folder)).replace("/", "\\")
        data = p.read_bytes()
        head += rel.encode("utf-8") + b"\0" + struct.pack("<5I", 0, len(data), 0, int(p.stat().st_mtime), len(data))
        body += data
    head += b"\0" + struct.pack("<5I", 0, 0, 0, 0, 0)
    blob = bytes(head + body)
    pbo_path.write_bytes(blob + b"\0" + hashlib.sha1(blob).digest())


def cmd_bake(a):
    doc = json.loads(Path(a.kept).read_text(encoding="utf-8"))
    src = Path(a.into)
    out = fresh(Path(a.out))
    if a.pbo:
        fresh(Path(a.pbo))
    if not doc["objects"]:
        die("kept.json has no objects")
    mname = src.parent.name if src.name.casefold() == "mission.sqm" else src.name
    mname = mname[:-4] if mname.casefold().endswith(".pbo") else mname
    world = mname.rsplit(".", 1)[1] if "." in mname else ""
    if not a.any_world:
        if not world:
            die(f"cannot tell the target mission's world from '{mname}' (expected <name>.<world>); "
                f"the save is from '{doc['world']}' - rename it or pass --any-world")
        if doc["world"] and world.casefold() != doc["world"].casefold():
            die(f"target mission is for world '{world}', the save is from '{doc['world']}' (use --any-world to override)")
    sqm_text, pbo = load_mission_sqm(src)
    name = a.layer_name or f"Stonewall {doc['sid'][:13]} ({doc['mission']})"
    new_text, info = bake_text(sqm_text, doc, name)
    out.mkdir(parents=True)
    if pbo is not None:
        for m in pbo.members.values():
            dst = out / m["name"].replace("\\", "/")
            dst.parent.mkdir(parents=True, exist_ok=True)
            dst.write_bytes(pbo.get(m["name"], max_bytes=1 << 31))
    elif src.is_dir():
        shutil.copytree(src, out, dirs_exist_ok=True)
    else:                                   # a bare mission.sqm: take the rest of its mission folder too
        shutil.copytree(src.parent, out, dirs_exist_ok=True)
    (out / "mission.sqm").write_bytes(new_text.encode("utf-8", errors="surrogateescape"))
    info.update(tool=VERSION, sid=doc["sid"], objects=len(doc["objects"]), source=str(src),
                source_sha256=hashlib.sha256(src.read_bytes()).hexdigest() if src.is_file() else None,
                mission_sqm_sha256=hashlib.sha256((out / "mission.sqm").read_bytes()).hexdigest(),
                layer=name, baked=dt.datetime.now().isoformat(timespec="seconds"))
    if a.pbo:
        write_pbo(out, Path(a.pbo))
        info["pbo"] = a.pbo
        info["pbo_sha256"] = hashlib.sha256(Path(a.pbo).read_bytes()).hexdigest()
    (out.parent / (out.name + ".stonewall.json")).write_text(json.dumps(info, indent=1), encoding="utf-8")
    print(f"baked {len(doc['objects'])} objects as layer '{name}' ({info['layers']} layers, ids {info['first_id']}.."
          f"{info['first_id'] + info['ids'] - 1}, +{len(info['addons_added'])} addons) -> {out}"
          + (f" and {a.pbo}" if a.pbo else ""))


# ---------------------------------------------------------------- cli
def main(argv=None):
    ap = argparse.ArgumentParser(prog="stonewall", description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("extract", help="pull a save out of server/client RPT files")
    p.add_argument("rpt", nargs="+")
    p.add_argument("--sid")
    p.add_argument("--latest", action="store_true", help="take the newest save when there are several")
    p.add_argument("--out", required=True)
    p.set_defaults(fn=cmd_extract)
    p = sub.add_parser("clean", help="keep only built objects inside keep areas")
    p.add_argument("snapshot")
    p.add_argument("--live-mission", help="the op's mission (.pbo, folder or mission.sqm) - excludes its editor objects")
    p.add_argument("--margin", type=float, default=5.0, help="metres added around each keep area (default 5)")
    p.add_argument("--include-zeus", action="store_true", help="also keep Zeus-placed objects")
    p.add_argument("--include-spawned", action="store_true",
                   help="also keep objects created by server/HC scripts (mission scripts, HCSpawn, Zen compositions)")
    p.add_argument("--keep-unknown", action="store_true",
                   help="keep objects with no build tag even without --live-mission (risk: duplicated editor objects)")
    p.add_argument("--include-kind", action="append",
                   choices=["static_weapon", "other", "land_vehicle", "air", "ship", "box"])
    p.add_argument("--exclude-class", action="append", help="regex, repeatable")
    p.add_argument("--drop-area", action="append", type=int, help="keep-area number to ignore, repeatable")
    p.add_argument("--editor-tolerance", type=float, default=1.5)
    p.add_argument("--out", required=True)
    p.add_argument("--report", required=True)
    p.set_defaults(fn=cmd_clean)
    p = sub.add_parser("bake", help="write the kept bases into a copy of the next mission")
    p.add_argument("kept")
    p.add_argument("--into", required=True, help="next mission: folder, mission.sqm or .pbo (never modified)")
    p.add_argument("--out", required=True, help="NEW mission folder")
    p.add_argument("--pbo", help="also pack the new folder to this NEW .pbo")
    p.add_argument("--layer-name")
    p.add_argument("--any-world", action="store_true")
    p.set_defaults(fn=cmd_bake)
    a = ap.parse_args(argv)
    a.fn(a)


if __name__ == "__main__":
    main()
