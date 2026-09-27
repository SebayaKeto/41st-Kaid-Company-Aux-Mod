"""Build Stonewall: sync the paste script from the addon source, lint the addon config, pack the addon PBO.

    python D:\\Stonewall\\tools\\build.py

Outputs: sqf/stonewall_save.sqf (+ .min + _parts), release/@FST_Stonewall/addons/FST_Stonewall.pbo, release/BUILD.json
"""
import hashlib
import json
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(r"D:\Stonewall")
sys.path.insert(0, str(ROOT / "tools"))
import minify_sqf  # noqa: E402
import stonewall  # noqa: E402

SRC = ROOT / "addon" / "FST_Stonewall"
OUT = ROOT / "release" / "@FST_Stonewall" / "addons" / "FST_Stonewall.pbo"


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def main():
    save_src = SRC / "functions" / "fn_save.sqf"
    shutil.copy2(save_src, ROOT / "sqf" / "stonewall_save.sqf")
    text = minify_sqf.minify(save_src.read_text(encoding="utf-8"))
    (ROOT / "sqf" / "stonewall_save.min.sqf").write_text(text, encoding="utf-8", newline="\n")
    pdir = ROOT / "sqf" / "stonewall_save_parts"
    pdir.mkdir(exist_ok=True)
    stamp = str(int(__import__("time").time()))
    for old in pdir.glob("part*_of_*.sqf"):
        old.rename(old.with_name(old.name + f".old-{stamp}"))   # set aside, never delete
    parts = minify_sqf.parts(text)
    for i, p in enumerate(parts, 1):
        (pdir / f"part{i}_of_{len(parts)}.sqf").write_text(p, encoding="utf-8", newline="\n")

    with tempfile.TemporaryDirectory(prefix="stonewall-lint-") as t:
        r = subprocess.run([str(stonewall.CFGCONVERT), "-bin", "-dst", str(Path(t) / "config.bin"), str(SRC / "config.cpp")],
                           capture_output=True, timeout=60)
        if r.returncode != 0:
            raise SystemExit("config.cpp does not parse:\n" + (r.stdout + r.stderr).decode(errors="replace"))

    OUT.parent.mkdir(parents=True, exist_ok=True)
    if OUT.exists():
        OUT.rename(OUT.with_name(OUT.name + f".prev-{int(OUT.stat().st_mtime)}"))
    stonewall.write_pbo(SRC, OUT, props={"prefix": "FST_Stonewall"}, exclude=("$PBOPREFIX$", "pbo.json"))
    (OUT.parents[1] / "mod.cpp").write_text('name = "FST Stonewall (test build)";\n', encoding="utf-8")
    info = {"pbo": str(OUT), "sha256": sha(OUT), "bytes": OUT.stat().st_size,
            "members": sorted(str(p.relative_to(SRC)) for p in SRC.rglob("*") if p.is_file() and p.name not in ("$PBOPREFIX$", "pbo.json")),
            "min_sqf_chars": len(text), "console_parts": len(parts)}
    (ROOT / "release" / "BUILD.json").write_text(json.dumps(info, indent=1), encoding="utf-8")
    print(f"built {OUT} ({info['bytes']} bytes, {len(info['members'])} files), sha256 {info['sha256'][:12]}; "
          f"paste script {len(text)} chars / {len(parts)} parts")


if __name__ == "__main__":
    main()
