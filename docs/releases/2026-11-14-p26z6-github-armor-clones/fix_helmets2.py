r"""P26z6: + Zombie (House 5d71aee7 unit FST_P2_Zombie). Fix unit helmet names in 41st_Armor config.cpp (Miran 7 Nov "Fix all 6"): units list FST_AB_Helmet_X, real classes are FST_Airborne_Helmet_X.
Remedy V2 Dirty class is spelled ..._Drity in config (live arsenal name), so the unit points there. usage: fix_helmets.py IN_PBO OUT_PBO"""
import sys, hashlib, json
from pathlib import Path
sys.path.insert(0, r'D:\AuxUpdater\gulfix'); import replace_entries as r
MAP = {'FST_AB_Helmet_Maska': 'FST_Airborne_Helmet_Mask', 'FST_AB_Helmet_Gode': 'FST_Airborne_Helmet_Gode',
       'FST_AB_Helmet_Prime': 'FST_Airborne_Helmet_Prime', 'FST_AB_Helmet_Sin': 'FST_Airborne_Helmet_Sin',
       'FST_AB_Helmet_Remedy': 'FST_Airborne_Helmet_Remedy', 'FST_AB_Helmet_Remedy_V2_Dirty': 'FST_Airborne_Helmet_Remedy_V2_Drity',
       'FST_AB_Helmet_Blue': 'FST_Airborne_Helmet_Blue', 'FST_AB_Helmet_Zombie': 'FST_Airborne_Helmet_Zombie'}
src, out = sys.argv[1], Path(sys.argv[2])
props, entries, hv = r.parse(Path(src).read_bytes())
e = next(e for e in entries if e[0].lower() == b'config.cpp'); assert e[1][0] == 0
txt = e[2].decode('latin1'); counts = {}
for a, b in MAP.items():
    q = '"' + a + '"'; counts[a] = txt.count(q); txt = txt.replace(q, '"' + b + '"')
    assert ('class ' + b + ':') in txt, b
assert '"FST_AB_Helmet_' not in txt
p = txt.encode('latin1'); e[1][1] = len(p); e[1][4] = len(p); e[2] = p
blob = r.build(props, entries, hv); tmp = out.with_suffix('.tmp'); tmp.write_bytes(blob); tmp.replace(out)
np_, ne, nv = r.parse(out.read_bytes()); assert np_ == props and nv == hv and len(ne) == len(entries)
for (a, _, pa), (b, _, pb) in zip(entries, ne): assert a == b and pa == pb
print(json.dumps({'out': str(out), 'bytes': len(blob), 'sha256': hashlib.sha256(blob).hexdigest(), 'replaced': counts}))
