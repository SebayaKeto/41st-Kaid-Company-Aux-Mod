r"""P26z23 parts (24 Nov 2026, Miran typed "Stage P26z23 now"): Bees 6764d96a "Radiation Fixes and Kit Fixes" (pushed 23 Nov 19:26)
applied to the LIVE P26z22 PBOs 41st_KitMenu.pbo and BUZZ_Radiation.pbo.
- Each changed entry: live bytes == the file at 6764d96a~1 (EOL-normalised) is asserted first, then replaced by the 6764d96a file
  in the live entry's own line-ending style. New entry: functions\BUZZ_Radiation_fnc_zeusZone.sqf.
- Every other entry and the header properties are byte-identical (verified on read-back).
- Checks: compat_41st/config.cpp and the root config.cpp (with its #include of the CfgFunctions hpp, unpacked to a temp dir)
  dupscope 0 + CfgConvert -bin rc 0; bracket balance on the changed SQF; every CfgFunctions file path exists in the PBO.
usage: make_rad23.py OUTDIR"""
import hashlib, json, re, subprocess, sys, tempfile
from pathlib import Path
sys.path.insert(0, r'D:/AuxUpdater/gulfix'); import replace_entries as r
BS = chr(92)
LIVE = Path(r'C:/Users/Miran/Downloads/Steam-aux-release-20261124-P26z22-halloween/@41st_Kaid_Aux_Release/Addons')
REPO = r'C:/Users/Miran/OneDrive/Documents/GitHub/41st-Kaid-Company-Aux-Mod/41st-Kaid-Company-Aux-Mod'
CFGC = r'C:/Program Files (x86)/Steam/steamapps/common/Arma 3 Tools/CfgConvert/CfgConvert.exe'
COMMIT = '6764d96ac40977a3cda76bef981e75fc64eac5dd'
OUT = Path(sys.argv[1]); assert not OUT.exists(), OUT; OUT.mkdir(parents=True)
PLAN = {
    '41st_KitMenu': {'change': ['FST_autoCustoms.sqf', 'XEN_PreInit.sqf'], 'add': []},
    'BUZZ_Radiation': {'change': ['BUZZ_Radiation_CfgFunctions.hpp', 'BUZZ_Radiation_XEH_postInit.sqf', 'compat_41st/config.cpp',
                                  'functions/BUZZ_Radiation_fnc_tick.sqf'], 'add': ['functions/BUZZ_Radiation_fnc_zeusZone.sqf']},
}
def git(rev, path):
    p = subprocess.run(['git', '-C', REPO, 'show', '%s:%s' % (rev, path)], capture_output=True)
    assert p.returncode == 0, (rev, path, p.stderr); return p.stdout
def lf(b): return b.replace(b'\r\n', b'\n')
def sha(b): return hashlib.sha256(b).hexdigest()
def bal(b):
    t = re.sub(rb'"[^"]*"', b'""', re.sub(rb'//[^\n]*', b'', re.sub(rb'/\*.*?\*/', b'', b, flags=re.S)))
    return all(t.count(o) == t.count(c) for o, c in ((b'(', b')'), (b'[', b']'), (b'{', b'}')))
def cfgcheck(root, rel):
    d = subprocess.run([sys.executable, r'D:/AuxUpdater/tools/dupscope.py', str(root / rel)], capture_output=True, text=True)
    assert d.returncode == 0, (rel, d.stdout)
    c = subprocess.run([CFGC, '-bin', '-dst', str(root / (rel + '.bin')), str(root / rel)], capture_output=True, text=True, cwd=str((root / rel).parent))
    assert c.returncode == 0 and (root / (rel + '.bin')).stat().st_size > 0, (rel, c.stdout, c.stderr)
rep = {'commit': COMMIT, 'pbos': {}}
for pbo, plan in PLAN.items():
    data = (LIVE / (pbo + '.pbo')).read_bytes()
    props, ents, hv = r.parse(data); _, old, _ = r.parse(data)
    idx = {e[0].decode('latin-1').lower().replace(BS, '/'): i for i, e in enumerate(ents)}
    done = {}
    for rel in plan['change']:
        i = idx[rel.lower()]; e = ents[i]; assert e[1][0] == 0, (pbo, rel, 'compressed')
        path = 'PUBLISHED MODPACK/%s/%s' % (pbo, rel)
        before, after = git(COMMIT + '~1', path), git(COMMIT, path)
        assert lf(e[2]) == lf(before), ('live != pre-Bees', pbo, rel)
        crlf = b'\r\n' in e[2]
        new = lf(after).replace(b'\n', b'\r\n') if crlf else lf(after)
        assert new != e[2]
        if rel.endswith('.sqf') or rel.endswith('.hpp'): assert bal(new), ('brackets', rel)
        e[2] = new; e[1][1] = e[1][4] = len(new)
        done[rel] = {'live_sha256': sha(data[0:0] + bytes(old[i][2])), 'new_sha256': sha(new), 'crlf': crlf}
    sib = next(e for e in ents if e[0].decode('latin-1').lower().replace(BS, '/').endswith('.sqf'))
    crlf_style = b'\r\n' in sib[2]
    for rel in plan['add']:
        assert rel.lower() not in idx
        b = lf(git(COMMIT, 'PUBLISHED MODPACK/%s/%s' % (pbo, rel)))
        b = b.replace(b'\n', b'\r\n') if crlf_style else b
        assert bal(b), ('brackets', rel)
        ents.append([rel.replace('/', BS).encode('latin-1'), [0, len(b), 0, 0, len(b)], b]); done[rel] = {'added': True, 'new_sha256': sha(b)}
    built = r.build(props, ents, hv); dst = OUT / (pbo + '.pbo'); dst.write_bytes(built)
    nprops, nents, nhv = r.parse(dst.read_bytes())
    assert nprops == props and nhv == hv and len(nents) == len(old) + len(plan['add'])
    same = 0
    for (on, oh, op), (nn, nh, np) in zip(old, nents):
        assert on == nn
        if on.decode('latin-1').lower().replace(BS, '/') in [x.lower() for x in plan['change']]: continue
        assert oh == nh and op == np; same += 1
    # unpack text entries to a temp dir for the config checks + CfgFunctions path check
    with tempfile.TemporaryDirectory() as td:
        root = Path(td)
        for n, h, p in nents:
            f = root / n.decode('latin-1').replace(BS, '/'); f.parent.mkdir(parents=True, exist_ok=True); f.write_bytes(p)
        names = {n.decode('latin-1').lower().replace(BS, '/') for n, _, _ in nents}
        cfgs = sorted(x for x in names if x.split('/')[-1] == 'config.cpp')
        for c in cfgs: cfgcheck(root, next(n.decode('latin-1').replace(BS, '/') for n, _, _ in nents if n.decode('latin-1').lower().replace(BS, '/') == c))
        pre = (dict(props).get(b'prefix') or pbo.encode()).decode().lower()
        missing = []
        for n, _, p in nents:
            for m in re.finditer(rb'file\s*=\s*"([^"]+)"', p):
                fp = m.group(1).decode('latin-1').lower().replace(BS, '/').lstrip('/')
                if fp.startswith(pre.replace(BS, '/') + '/') and fp[len(pre) + 1:] not in names: missing.append(fp)
        assert not missing, (pbo, missing)
    rep['pbos'][pbo] = {'live_sha256': sha(data), 'new_sha256': sha(built), 'new_bytes': len(built), 'entries': len(nents),
                        'identical': same, 'changed_or_added': done, 'configs_checked': cfgs}
(OUT / 'rad23_build.json').write_text(json.dumps(rep, indent=2), encoding='utf-8')
print(json.dumps({k: (v['new_sha256'][:12], v['new_bytes'], '%d/%d identical' % (v['identical'], v['entries']), v['configs_checked']) for k, v in rep['pbos'].items()}, indent=1))
