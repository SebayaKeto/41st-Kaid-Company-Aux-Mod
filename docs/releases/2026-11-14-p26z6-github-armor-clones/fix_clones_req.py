r"""P26z6: 41st_Other_Clones requiredAddons {} -> {"41st_Addon","JLTS_characters_CloneArmor","OPTRE_Misc_Objects"}.
Catboy 27a716d4 reverted 83b5b79d (load after its parent classes); 6eb56a2d adds CfgGlasses FST_69_Ears: OPTRE_CatEars_P (OPTRE_Misc.pbo objects/config.bin, patch OPTRE_Misc_Objects).
usage: fix_clones_req.py IN_PBO OUT_PBO"""
import sys, hashlib, json
from pathlib import Path
sys.path.insert(0, r'D:\AuxUpdater\gulfix'); import replace_entries as r
src, out = sys.argv[1], Path(sys.argv[2])
props, entries, hv = r.parse(Path(src).read_bytes())
e = next(e for e in entries if e[0].lower() == b'config.cpp'); assert e[1][0] == 0
txt = e[2].decode('latin1')
old = '\t\trequiredAddons[]={};'
assert txt.count(old) == 1 and txt.index(old) < txt.index('units[]')
txt = txt.replace(old, '\t\trequiredAddons[]={"41st_Addon","JLTS_characters_CloneArmor","OPTRE_Misc_Objects"};')
p = txt.encode('latin1'); e[1][1] = len(p); e[1][4] = len(p); e[2] = p
blob = r.build(props, entries, hv); tmp = out.with_suffix('.tmp'); tmp.write_bytes(blob); tmp.replace(out)
np_, ne, nv = r.parse(out.read_bytes()); assert np_ == props and nv == hv and len(ne) == len(entries)
for (a, _, pa), (b, _, pb) in zip(entries, ne): assert a == b and pa == pb
print(json.dumps({'out': str(out), 'bytes': len(blob), 'sha256': hashlib.sha256(blob).hexdigest()}))
