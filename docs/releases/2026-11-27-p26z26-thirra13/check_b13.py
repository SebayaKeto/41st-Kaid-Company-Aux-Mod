r"""P26z26 pre-stage check of the build-13 terrain PBO (Aux Updater, 27 Nov 2026). Read-only on the sources.
PBO read-back (parse + rebuild byte-equal), entry list vs the live build 11, config.bin -> txt (CfgConvert) -> dupscope."""
import hashlib, json, subprocess, sys, tempfile
from pathlib import Path
sys.path.insert(0, r'D:/AuxUpdater/gulfix'); import replace_entries as r
CFGC = r'C:/Program Files (x86)/Steam/steamapps/common/Arma 3 Tools/CfgConvert/CfgConvert.exe'
B13 = Path(r'C:/IslandsA/output_whole13/@FST_EmberCaldera/addons/fst_ember_caldera.pbo')
B11 = Path(r'C:/Users/Miran/Downloads/Steam-aux-release-20261125-P26z25-bacta/@41st_Kaid_Aux_Release/Addons/fst_ember_caldera.pbo')
def sha(b): return hashlib.sha256(b).hexdigest()
b13, b11 = B13.read_bytes(), B11.read_bytes()
out = {'b13_sha': sha(b13), 'b13_bytes': len(b13), 'b11_sha': sha(b11), 'b11_bytes': len(b11)}
p13, e13, h13 = r.parse(b13); p11, e11, h11 = r.parse(b11)
out['props_b13'] = {k.decode(errors='replace') if isinstance(k, bytes) else str(k): (v.decode(errors='replace') if isinstance(v, bytes) else str(v)) for k, v in (p13.items() if isinstance(p13, dict) else [])} if isinstance(p13, dict) else str(p13)[:300]
out['props_equal_b11'] = p13 == p11
out['rebuild_byte_equal'] = r.build(p13, e13, h13) == b13
n13 = [e[0] for e in e13]; n11 = [e[0] for e in e11]
out['entries_b13'] = len(n13); out['entries_b11'] = len(n11); out['same_entry_names'] = n13 == n11
out['changed_entries'] = sum(1 for a, b in zip(e13, e11) if a[2] != b[2])
cb = [e for e in e13 if e[0].lower().endswith(b'config.bin')]
cb11 = [e for e in e11 if e[0].lower().endswith(b'config.bin')]
out['config_bin_count'] = len(cb); out['config_bin_equal_b11'] = [c[2] for c in cb] == [c[2] for c in cb11]
with tempfile.TemporaryDirectory() as td:
    for i, c in enumerate(cb):
        bp = Path(td) / ('c%d.bin' % i); tp = Path(td) / ('c%d.cpp' % i); bp.write_bytes(c[2])
        cv = subprocess.run([CFGC, '-txt', '-dst', str(tp), str(bp)], capture_output=True, text=True)
        d = subprocess.run([sys.executable, r'D:/AuxUpdater/tools/dupscope.py', str(tp)], capture_output=True, text=True)
        out.setdefault('config_checks', []).append({'entry': c[0].decode(), 'cfgconvert_rc': cv.returncode, 'dupscope_rc': d.returncode, 'dupscope_out': d.stdout.strip()[-300:]})
print(json.dumps(out, indent=1))
Path(r'D:/AuxUpdater/p26z26/check_b13.json').write_text(json.dumps(out, indent=1), encoding='utf-8')
