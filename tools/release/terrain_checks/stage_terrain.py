"""Verify new terrain PBOs and (optionally) add them to the staged Aux release.

usage: python stage_terrain.py --release=DIR [--modlist=FILE] [--stage] PATH=SHA256=BYTES [...]

DIR is a staging folder holding @41st_Kaid_Aux_Release and RELEASE_MANIFEST.json.
FILE lists the op mod folders, one per line (default: client-modlist.txt beside this
script; build it from a running client's -mod= line or the launcher preset). The modset
index is cached in .cache/ - delete it when the modset changes.

Checks per PBO: owner hash/size, header prefix (no CR/LF), config.bin only (no
config.cpp shadowing), no compressed entries, a .wrp present, every requiredAddon
resolved in the op modset (Miran's live client mod list) or the staged Aux, and no
collision of CfgPatches / world / prefix / defined classes (surfaces, clutter,
functions, vehicles ...) with the modset, the staged Aux or the other new PBOs.
Shared-prop redefinitions identical to an existing terrain's are reported as OK.
--stage copies passing PBOs into the staging folder and updates RELEASE_MANIFEST.json.
"""
import hashlib
import json
import os
import pickle
import shutil
import stat
import sys
from pathlib import Path

HERE = Path(__file__).parent
sys.path.insert(0, str(HERE))
from rap_index import summarize_pbo, read_body  # noqa: E402
from check_classes import pbo_classes, SHARED_OK  # noqa: E402
import pbo_tools as pbo  # noqa: E402

ARMA = Path(r'C:\Program Files (x86)\Steam\steamapps\common\Arma 3')
def _arg(name, default=None):
    return next((a.split('=', 1)[1] for a in sys.argv if a.startswith('--' + name + '=')), default)


RELEASE = Path(_arg('release', '.'))
STAGED = RELEASE / '@41st_Kaid_Aux_Release' / 'Addons'
AUX = '@41st Elite Corps Kaid Co Aux Mod'
MODLIST = Path(_arg('modlist', str(HERE / 'client-modlist.txt')))
CACHE = HERE / '.cache' / 'modset-index.pickle'


def sha256(path):
    h = hashlib.sha256()
    with open(path, 'rb') as f:
        for chunk in iter(lambda: f.read(8 << 20), b''):
            h.update(chunk)
    return h.hexdigest()


def class_signature(path, root, name):
    """Canonical hash of one defined class body, to tell identical re-openings apart."""
    rows, _ = pbo.index(path)
    for key, row in rows.items():
        if key.rsplit('/', 1)[-1] != 'config.bin' or row['header'][0] != 0:
            continue
        data = pbo.read(path, key)
        if not data.startswith(b'\0raP'):
            continue
        _, top = read_body(data, 16)
        for kind, rname, off in top:
            if kind == 'class' and rname.lower() == root:
                _, kids = read_body(data, off)
                for kk, cn, coff in kids:
                    if kk == 'class' and cn.lower() == name:
                        def canon(o):
                            inh, entries = read_body(data, o)
                            return [inh] + [(k, n.lower(), canon(p) if k == 'class' else (p if isinstance(p, str) else repr(p)))
                                            for k, n, p in entries]
                        return hashlib.sha1(repr(canon(coff)).encode()).hexdigest()[:12]
    return None


def index_folder(label, folder, patches, worlds, prefixes, classes):
    for p in folder.glob('*.pbo'):
        try:
            s = summarize_pbo(p)
        except Exception:
            continue
        src = '%s | %s' % (label, p.name)
        for name in s['patches']:
            patches.setdefault(name.lower(), []).append(src)
        for w in s['worlds']:
            worlds.setdefault(w.lower(), []).append(src)
        if s['prefix']:
            prefixes.setdefault(s['prefix'].lower().strip('\\'), []).append(src)
        for root, names in pbo_classes(p).items():
            for n in names:
                classes.setdefault((root, n.lower()), []).append((src, str(p)))


def modset_index():
    if CACHE.exists():
        return pickle.loads(CACHE.read_bytes())
    mods = [Path(l.strip().lstrip('\ufeff')) for l in MODLIST.read_text(encoding='utf-8').splitlines() if l.strip()]
    folders = [('vanilla', ARMA / 'Addons')] + [('vanilla:' + d.name, d / 'Addons') for d in ARMA.iterdir()
                                              if d.is_dir() and (d / 'Addons').is_dir() and not d.name.startswith('!')]
    folders += [(m.name, m / 'addons') for m in mods if m.name != AUX]
    idx = ({}, {}, {}, {})
    for label, folder in folders:
        if folder.is_dir():
            index_folder(label, folder, *idx)
    CACHE.parent.mkdir(exist_ok=True)
    CACHE.write_bytes(pickle.dumps(idx))
    return idx


def main(argv):
    do_stage = '--stage' in argv
    items = [a.split('=') for a in argv if not a.startswith('--')]
    patches, worlds, prefixes, classes = [dict(x) for x in modset_index()]
    new_names = {Path(p).name.lower() for p, _, _ in items}
    # staged Aux, minus any file being (re)staged now
    sp, sw, spx, sc = {}, {}, {}, {}
    index_folder('staged Aux', STAGED, sp, sw, spx, sc)
    for d_new, d_old in ((patches, sp), (worlds, sw), (prefixes, spx), (classes, sc)):
        for k, v in d_old.items():
            v = [x for x in v if (x[0] if isinstance(x, tuple) else x).split(' | ')[-1].lower() not in new_names]
            if v:
                d_new.setdefault(k, []).extend(v)
    # other new PBOs in this batch
    batch = {}
    for path, _, _ in items:
        p = Path(path)
        s = summarize_pbo(p)
        batch[p.name] = (p, s, pbo_classes(p))
    report, ok_all = {}, True
    for path, want_sha, want_bytes in items:
        p = Path(path)
        s = batch[p.name][1]
        rows, props = pbo.index(p)
        problems, notes, warnings = [], [], []
        size = p.stat().st_size
        digest = sha256(p)
        if digest != want_sha.lower() or size != int(want_bytes.replace(',', '')):
            problems.append('hash/size mismatch: %s %d' % (digest, size))
        if any('\r' in v or '\n' in v for v in props.values()):
            problems.append('CR/LF in PBO header')
        cfg = [k for k in rows if k.rsplit('/', 1)[-1] in ('config.bin', 'config.cpp')]
        if any(k.endswith('config.cpp') and k.replace('config.cpp', 'config.bin') in rows for k in cfg):
            problems.append('config.cpp and config.bin both present (cpp shadows bin)')
        if any(r['header'][0] != 0 for r in rows.values()):
            problems.append('compressed entries')
        if not any(k.endswith('.wrp') for k in rows):
            notes.append('no .wrp (not a terrain?)')
        for patch, req in s['patches'].items():
            if patch.lower() in patches:
                problems.append('CfgPatches %s also in %s' % (patch, patches[patch.lower()][:3]))
            for r in req:
                inbatch = any(r.lower() in (n.lower() for n in b[1]['patches']) for b in batch.values())
                if r.lower() not in patches and not inbatch:
                    problems.append('requiredAddon %s not found in op modset/staged Aux' % r)
        for w in s['worlds']:
            if w.lower() in worlds:
                problems.append('world %s also in %s' % (w, worlds[w.lower()][:3]))
        pfx = s['prefix'].lower().strip('\\')
        if pfx and pfx in prefixes:
            problems.append('prefix %s also used by %s' % (s['prefix'], prefixes[pfx][:3]))
        mine = batch[p.name][2]
        for root, names in mine.items():
            for n in names:
                if n.lower() in SHARED_OK:
                    continue
                others = list(classes.get((root, n.lower()), []))
                others += [('new | ' + bn, str(bp)) for bn, (bp, _, bc) in batch.items() if bn != p.name and n in bc.get(root, set())]
                if not others:
                    continue
                mysig = class_signature(p, root, n.lower())
                differing = [o for o in others if class_signature(Path(o[1]), root, n.lower()) != mysig]
                ours = [o for o in differing if o[0].startswith(('staged Aux', 'new |'))]
                theirs = [o for o in differing if o not in ours]
                if ours:
                    problems.append('%s class %s conflicts with our %s (load-order dependent)' % (root, n, [o[0] for o in ours][:3]))
                if theirs:
                    same = [o[0] for o in others if o not in differing and o[0].startswith('staged Aux')]
                    live = (' - already live, identical in %s' % same[:2]) if same else ' - NEW global side effect'
                    warnings.append('%s class %s re-defines %s differently%s' % (root, n, [o[0] for o in theirs][:2], live))
                if not differing:
                    notes.append('%s class %s re-opened identically to %s' % (root, n, [o[0] for o in others][:2]))
        report[p.name] = {'sha256': digest, 'bytes': size, 'prefix': s['prefix'], 'worlds': s['worlds'],
                          'patches': list(s['patches']), 'problems': problems, 'warnings': warnings, 'notes': notes[:12]}
        ok_all = ok_all and not problems
    print(json.dumps(report, indent=1))
    if do_stage:
        if not ok_all:
            sys.exit('NOT staged: resolve the problems above first')
        man = json.loads((RELEASE / 'RELEASE_MANIFEST.json').read_text(encoding='utf-8'))
        for path, _, _ in items:
            p = Path(path)
            dst = STAGED / p.name
            if dst.exists():
                # Staged files may be hard links shared with other staging folders, and
                # copies of read-only frozen sources: unlink removes only this name.
                os.chmod(dst, stat.S_IREAD | stat.S_IWRITE)
                dst.unlink()
            shutil.copy2(p, dst)
            os.chmod(dst, stat.S_IREAD | stat.S_IWRITE)
            assert sha256(dst) == report[p.name]['sha256']
            rel = 'Addons/' + p.name
            man['files'] = [e for e in man['files'] if e['file'].lower() != rel.lower()]
            man['files'].append({'file': rel, 'bytes': report[p.name]['bytes'], 'sha256': report[p.name]['sha256'], 'origin': str(p)})
            if rel not in man['added']:
                man['added'].append(rel)
        man['file_count'] = len(man['files'])
        man['total_bytes'] = sum(e['bytes'] for e in man['files'])
        (RELEASE / 'RELEASE_MANIFEST.json').write_text(json.dumps(man, indent=2), encoding='utf-8')
        print('STAGED; manifest now %d files, %d bytes' % (man['file_count'], man['total_bytes']))


if __name__ == '__main__':
    main(sys.argv[1:])
