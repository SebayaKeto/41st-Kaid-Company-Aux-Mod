"""41st_Armor for the next release: live P26z18/z16 41st_Armor.pbo + House's be6b0fe8 (Miran 22 Nov: "make sure we have House's latest push").
config.cpp = armor19/release_config.cpp (3-way merge live/pre-House/House, live's 16 helmet-name fixes kept, + fix_house.py's 5 unit fixes).
Replaces the 3 textures House changed and appends his 17 new ones (forward-slash names like the live entries). Every other entry byte-identical.
usage: make_armor19.py OUT.pbo"""
import hashlib, json, sys, time, subprocess
from pathlib import Path
sys.path.insert(0, r'D:/AuxUpdater/gulfix'); import replace_entries as r
REPO = Path(r'C:/Users/Miran/OneDrive/Documents/GitHub/41st-Kaid-Company-Aux-Mod/41st-Kaid-Company-Aux-Mod')
ARM = REPO / 'PUBLISHED MODPACK' / '41st_Armor'
LIVE = Path(r'C:/Users/Miran/Downloads/Steam-aux-release-20261122-P26z18-suddra-music/@41st_Kaid_Aux_Release/Addons/41st_Armor.pbo')
CFG = Path(r'D:/AuxUpdater/armor19/release_config.cpp')
COMMIT = 'be6b0fe8'
out = Path(sys.argv[1]); assert not out.exists(), out
rows = subprocess.run(['git', '-C', str(REPO), 'show', '--format=', '--name-status', COMMIT], capture_output=True, text=True, check=True).stdout.splitlines()
pre = 'PUBLISHED MODPACK/41st_Armor/'
files = [(l.split('\t')[0], l.split('\t')[1][len(pre):]) for l in rows if l.split('\t')[1].startswith(pre)]
assert {f for _, f in files if not f.startswith('Data/')} == {'config.cpp'}
mod = [f for st, f in files if st == 'M' and f != 'config.cpp']; add = [f for st, f in files if st == 'A']
assert len(mod) == 3 and len(add) == 17 and len(files) == 21, (len(mod), len(add))
data = LIVE.read_bytes(); props, ents, hv = r.parse(data)
key = lambda n: n.decode('latin1').replace(chr(92), '/').lower()
idx = {key(e[0]): i for i, e in enumerate(ents)}
repl = {'config.cpp': CFG.read_bytes()}
for f in mod: repl[f.lower()] = (ARM / f).read_bytes()
for k, b in repl.items():
    i = idx[k]; ents[i][1][1] = ents[i][1][4] = len(b); ents[i][2] = b
now = int(time.time())
for f in add:
    assert f.lower() not in idx, f
    b = (ARM / f).read_bytes(); assert b[:4] in (b'\xff\x01GG', b'\x01\xffGG') or b[2:4] == b'GG', f
    ents.append([f.encode('latin1'), [0, len(b), 0, now, len(b)], b])
out.write_bytes(r.build(props, ents, hv))
nprops, nents, nhv = r.parse(out.read_bytes()); _, old, _ = r.parse(data)
assert nhv == hv and nprops == props and len(nents) == len(old) + len(add)
same = 0
for (on, oh, op), (nn, nh, np) in zip(old, nents):
    assert on == nn
    if key(on) in repl: assert np == repl[key(on)]
    else: assert oh == nh and op == np; same += 1
for f, (nn, nh, np) in zip(add, nents[len(old):]): assert nn == f.encode('latin1') and np == (ARM / f).read_bytes()
print(json.dumps({'out': str(out), 'bytes': out.stat().st_size, 'sha256': hashlib.sha256(out.read_bytes()).hexdigest(), 'entries': len(nents),
                  'identical': same, 'replaced': sorted(repl), 'added': len(add)}))
