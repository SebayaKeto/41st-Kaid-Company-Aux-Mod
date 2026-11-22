"""41st_Other_Clones for P26z19: live 41st_Other_Clones.pbo + Tooka's a1875ee2 (327th Environmental Troopers; Miran 22 Nov "Tooka pushed,
pull it in and build P26z19"). config.cpp = repo working tree (Tooka) with live's requiredAddons line kept
({"41st_Addon","JLTS_characters_CloneArmor","OPTRE_Misc_Objects"}; live == pre-Tooka repo apart from that line and EOL).
The 12 changed fn_clone*.sqf are replaced from the repo; Data/FST_Env_Helmet_327.paa is appended (backslash name like the live entries).
Every other entry byte-identical. usage: make_clones19.py OUT.pbo"""
import hashlib, json, sys, time, subprocess
from pathlib import Path
sys.path.insert(0, r'D:/AuxUpdater/gulfix'); import replace_entries as r
BS = chr(92)
REPO = Path(r'C:/Users/Miran/OneDrive/Documents/GitHub/41st-Kaid-Company-Aux-Mod/41st-Kaid-Company-Aux-Mod')
ADDON = REPO / 'PUBLISHED MODPACK' / '41st_Other_Clones'
LIVE = Path(r'C:/Users/Miran/Downloads/Steam-aux-release-20261122-P26z18-suddra-music/@41st_Kaid_Aux_Release/Addons/41st_Other_Clones.pbo')
COMMIT = 'a1875ee2'
out = Path(sys.argv[1]); assert not out.exists(), out
pre = 'PUBLISHED MODPACK/41st_Other_Clones/'
rows = subprocess.run(['git', '-C', str(REPO), 'show', '--format=', '--name-status', COMMIT], capture_output=True, text=True, check=True).stdout.splitlines()
files = [(l.split('\t')[0], l.split('\t')[1]) for l in rows]
assert all(f.startswith(pre) for _, f in files), files
files = [(st, f[len(pre):]) for st, f in files]
mod = [f for st, f in files if st == 'M']; add = [f for st, f in files if st == 'A']
assert len(mod) == 13 and add == ['Data/FST_Env_Helmet_327.paa'], (mod, add)
data = LIVE.read_bytes(); props, ents, hv = r.parse(data)
key = lambda n: n.replace(BS, '/').lower()
idx = {key(e[0].decode('latin1')): i for i, e in enumerate(ents)}
# config: Tooka's file + live requiredAddons line
cfg = (ADDON / 'config.cpp').read_bytes()
live_cfg = ents[idx['config.cpp']][2]
LINE_LIVE = b'requiredAddons[]={"41st_Addon","JLTS_characters_CloneArmor","OPTRE_Misc_Objects"};'
assert live_cfg.count(LINE_LIVE) == 1 and cfg.count(b'requiredAddons[]={};') == 1
cfg = cfg.replace(b'requiredAddons[]={};', LINE_LIVE)
repl = {'config.cpp': cfg}
for f in mod:
    if f != 'config.cpp': repl[f.lower()] = (ADDON / f).read_bytes()
for k, b in repl.items():
    i = idx[k]; ents[i][1][1] = ents[i][1][4] = len(b); ents[i][2] = b
now = int(time.time())
for f in add:
    assert key(f) not in idx
    b = (ADDON / f).read_bytes(); assert b[2:4] == b'GG', f
    ents.append([f.replace('/', BS).encode('latin1'), [0, len(b), 0, now, len(b)], b])
out.write_bytes(r.build(props, ents, hv))
Path(out.parent / 'release_config.cpp').write_bytes(cfg)
nprops, nents, nhv = r.parse(out.read_bytes()); _, old, _ = r.parse(data)
assert nhv == hv and nprops == props and len(nents) == len(old) + len(add)
same = 0
for (on, oh, op), (nn, nh, np) in zip(old, nents):
    assert on == nn
    k = key(on.decode('latin1'))
    if k in repl: assert np == repl[k]
    else: assert oh == nh and op == np; same += 1
print(json.dumps({'out': str(out), 'bytes': out.stat().st_size, 'sha256': hashlib.sha256(out.read_bytes()).hexdigest(), 'entries': len(nents),
                  'identical': same, 'replaced': len(repl), 'added': add}))
