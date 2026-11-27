r"""Bacta Tank fix (Aux Updater, 25 Nov 2026). Miran's pick ~22:1x via the Omnibus: "Bandaged, even if down".
41st_Medical.pbo config.cpp, ACE_medical_treatment_actions >> FST_Bacta_Tank only (ACE's own PersonalAidKit untouched):
  - condition: was isInStableCondition (alive, NOT unconscious, no bleeding, stable vitals) + medic still.
               now  alive patient + ace_medical_woundBleeding == 0 + medic still (speed < 1). Conscious or unconscious; no vitals check.
               ACE 3.21.3 canTreat: GET_FUNCTION = getText, compiled, `call`ed inside canTreat's scope, so _medic/_patient are in scope.
  - treatmentLocations = 0 (number): canTreat GET_NUMBER_ENTRY reads a number with getNumber; 0 = TREATMENT_LOCATIONS_ALL (anywhere).
               Inherited was the text "ace_medical_treatment_locationPAK" (the server's PAK location setting).
  - kept from PAK: callbackSuccess fullHeal, medicRequired (medicPAK), allowSelfTreatment (allowSelfPAK), consumeItem, treatmentTime.
Checks: the source PBO sha = live P26z24; exactly 1 replacement; dupscope 0; CfgConvert -bin rc 0; only config.cpp differs; read-back.
usage: make_bacta25.py OUTDIR"""
import hashlib, json, subprocess, sys, tempfile
from pathlib import Path
sys.path.insert(0, r'D:/AuxUpdater/gulfix'); import replace_entries as r
CFGC = r'C:/Program Files (x86)/Steam/steamapps/common/Arma 3 Tools/CfgConvert/CfgConvert.exe'
SRC = Path(r'C:/Users/Miran/Downloads/Steam-aux-release-20261125-P26z24-qol-thirra11-menufix/@41st_Kaid_Aux_Release/Addons/41st_Medical.pbo')
SRC_SHA = 'bb20ab0d7f93946cca564ee1406dd890a58c76cd8418375beefa685342368d2a'
OUT = Path(sys.argv[1]); assert not OUT.exists(); OUT.mkdir(parents=True)
src = SRC.read_bytes(); assert hashlib.sha256(src).hexdigest() == SRC_SHA, 'source is not the live P26z24 41st_Medical'
props, ents, hv = r.parse(src)
idx = [i for i, e in enumerate(ents) if e[0].lower() == b'config.cpp']; assert len(idx) == 1
cfg = ents[idx[0]][2]; nl = b'\r\n'; assert nl in cfg
OLD = b'\t\tcondition = "([_this select 1] call ace_medical_status_fnc_isInStableCondition) && (speed (_this select 0) < 1)";'
NEW = nl.join([
    b'\t\t// Miran 25 Nov "Bandaged, even if down": living patient, conscious or unconscious, all bleeding stopped, medic standing still.',
    b'\t\tcondition = "alive _patient && {(_patient getVariable [\'ace_medical_woundBleeding\', 0]) == 0} && {speed _medic < 1}";',
    b'\t\t// anywhere (0 = all locations), not the server\'s PAK location setting',
    b'\t\ttreatmentLocations = 0;'])
assert cfg.count(OLD) == 1, 'condition line not found exactly once'
cfg2 = cfg.replace(OLD, NEW)
with tempfile.TemporaryDirectory() as td:
    t = Path(td) / 'config.cpp'; t.write_bytes(cfg2)
    d = subprocess.run([sys.executable, r'D:/AuxUpdater/tools/dupscope.py', str(t)], capture_output=True, text=True); assert d.returncode == 0, d.stdout
    c = subprocess.run([CFGC, '-bin', '-dst', str(Path(td) / 'config.bin'), str(t)], capture_output=True, text=True); assert c.returncode == 0, (c.stdout, c.stderr)
    c2 = subprocess.run([CFGC, '-txt', '-dst', str(Path(td) / 'back.cpp'), str(Path(td) / 'config.bin')], capture_output=True, text=True); assert c2.returncode == 0
    back_txt = (Path(td) / 'back.cpp').read_bytes()
    assert b'treatmentLocations=0;' in back_txt.replace(b' ', b'') and b"ace_medical_woundBleeding" in back_txt
e = ents[idx[0]]; ents[idx[0]] = [e[0], [e[1][0], len(cfg2), e[1][2], e[1][3], len(cfg2)], cfg2]
pbo = r.build(props, ents, hv)
dst = OUT / '41st_Medical.pbo'; dst.write_bytes(pbo)
p2, back, hv2 = r.parse(dst.read_bytes())
assert p2 == props and [(b[0], b[2]) for b in back] == [(x[0], x[2]) for x in ents]
_, orig, _ = r.parse(src)
diff = [o[0].decode() for o, b in zip(orig, back) if o[2] != b[2]]; assert diff == ['config.cpp'], diff
(OUT / 'config.cpp.patched').write_bytes(cfg2)
rep = {'41st_Medical': {'src_sha256': SRC_SHA, 'pbo_bytes': len(pbo), 'pbo_sha256': hashlib.sha256(pbo).hexdigest(), 'changed_entries': diff,
                        'cfg_bytes_before': len(cfg), 'cfg_bytes_after': len(cfg2)}}
(OUT / 'bacta25_build.json').write_text(json.dumps(rep, indent=2), encoding='utf-8'); print(json.dumps(rep))
