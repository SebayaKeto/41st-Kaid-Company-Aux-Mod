"""P26z18: live P26z16 41st_Music.pbo + Suddra Theme 1/2 (Miran 22 Nov, Aux Updater chat). Replaces config.cpp with the repo copy and appends
MissionTracks/Suddra_Theme.ogg + MissionTracks/Suddra_Theme_2.ogg (stored with a backslash) at the end (same pattern as Keep_A_Blaster / Frostwave / All_Star).
Every other entry is byte-identical and in the same order (verified). usage: make_music18.py OUT.pbo"""
import hashlib, json, sys, time
from pathlib import Path
sys.path.insert(0, r'D:/AuxUpdater/gulfix'); import replace_entries as r
REPO = Path(r'C:/Users/Miran/OneDrive/Documents/GitHub/41st-Kaid-Company-Aux-Mod/41st-Kaid-Company-Aux-Mod/PUBLISHED MODPACK/41st_Music')
LIVE = Path(r'C:/Users/Miran/Downloads/Steam-aux-release-20261122-P26z16-weapons-sweep/@41st_Kaid_Aux_Release/Addons/41st_Music.pbo')
BS = bytes([92])  # backslash, spelled out (shell heredoc trap)
ADD = [(b'MissionTracks' + BS + b'Suddra_Theme.ogg', REPO / 'MissionTracks/Suddra_Theme.ogg'),
       (b'MissionTracks' + BS + b'Suddra_Theme_2.ogg', REPO / 'MissionTracks/Suddra_Theme_2.ogg')]
out = Path(sys.argv[1]); assert not out.exists(), out
data = LIVE.read_bytes(); props, ents, hv = r.parse(data)
names = {e[0].lower().replace(b'/', BS) for e in ents}
assert all(n.lower() not in names for n, _ in ADD)
cfg = REPO.joinpath('config.cpp').read_bytes(); k = [i for i, e in enumerate(ents) if e[0] == b'config.cpp']; assert len(k) == 1
ents[k[0]][1][1] = ents[k[0]][1][4] = len(cfg); ents[k[0]][2] = cfg
now = int(time.time())
for n, f in ADD:
    b = f.read_bytes(); ents.append([n, [0, len(b), 0, now, len(b)], b])
out.write_bytes(r.build(props, ents, hv))
nprops, nents, nhv = r.parse(out.read_bytes())
_, old, _ = r.parse(data)
assert nhv == hv and nprops == props and len(nents) == len(old) + len(ADD)
same = 0
for (on, oh, op), (nn, nh, np) in zip(old, nents):
    assert on == nn
    if on == b'config.cpp': assert np == cfg
    else: assert oh == nh and op == np; same += 1
for (n, f), (nn, nh, np) in zip(ADD, nents[len(old):]): assert nn == n and np == f.read_bytes()
h = hashlib.sha256(out.read_bytes()).hexdigest()
print(json.dumps({'out': str(out), 'bytes': out.stat().st_size, 'sha256': h, 'entries': len(nents), 'identical': same, 'replaced': ['config.cpp'], 'added': [n.decode() for n, _ in ADD]}))
