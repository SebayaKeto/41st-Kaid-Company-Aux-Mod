r"""KAID_QoL PBO (25 Nov 2026): our own versions of Remove stamina, Remove stamina - ACE 3, No Weapon Sway and More Aircraft
Displays (src/KAID_QoL). One PBO, prefix KAID_QoL, two addons (config.cpp + ace\config.cpp), plain text.
Checks: dupscope 0 + CfgConvert -bin rc 0 on both configs; bracket balance on the sqf; the XEH script path matches the PBO;
read-back. usage: make_qol24.py OUTDIR"""
import hashlib, json, re, subprocess, sys, tempfile
from pathlib import Path
sys.path.insert(0, r'D:/AuxUpdater/gulfix'); import replace_entries as r
BS = chr(92)
SRC = Path(r'D:/AuxUpdater/qol24/src/KAID_QoL')
CFGC = r'C:/Program Files (x86)/Steam/steamapps/common/Arma 3 Tools/CfgConvert/CfgConvert.exe'
OUT = Path(sys.argv[1]); assert not OUT.exists(); OUT.mkdir(parents=True)
files = sorted(p.relative_to(SRC).as_posix() for p in SRC.rglob('*') if p.is_file())
assert files == ['XEH_postInitClient.sqf', 'ace/config.cpp', 'config.cpp'], files
def bal(b):
    t = re.sub(rb'"[^"]*"', b'""', re.sub(rb'//[^\n]*', b'', re.sub(rb'/\*.*?\*/', b'', b, flags=re.S)))
    return all(t.count(o) == t.count(c) for o, c in ((b'(', b')'), (b'[', b']'), (b'{', b'}')))
ents = []
for f in files:
    b = (SRC / f).read_bytes()
    assert bal(b), ('brackets', f)
    if f.endswith('config.cpp'):
        with tempfile.TemporaryDirectory() as td:
            t = Path(td) / 'config.cpp'; t.write_bytes(b)
            d = subprocess.run([sys.executable, r'D:/AuxUpdater/tools/dupscope.py', str(t)], capture_output=True, text=True); assert d.returncode == 0, d.stdout
            c = subprocess.run([CFGC, '-bin', '-dst', str(Path(td) / 'config.bin'), str(t)], capture_output=True, text=True); assert c.returncode == 0, (c.stdout, c.stderr)
    ents.append([f.replace('/', BS).encode(), [0, len(b), 0, 0, len(b)], b])
main = (SRC / 'config.cpp').read_bytes()
m = re.search(rb"compileScript \['" + re.escape(BS.encode()) + rb"KAID_QoL" + re.escape(BS.encode()) + rb"([^']+)'\]", main)
assert m and m.group(1).decode() in files, 'xeh path'
pbo = r.build([(b'prefix', b'KAID_QoL')], ents, True)
dst = OUT / 'KAID_QoL.pbo'; dst.write_bytes(pbo)
props, back, hv = r.parse(dst.read_bytes())
assert props == [(b'prefix', b'KAID_QoL')] and hv and [(e[0], e[2]) for e in back] == [(e[0], e[2]) for e in ents]
rep = {'KAID_QoL': {'pbo_bytes': len(pbo), 'pbo_sha256': hashlib.sha256(pbo).hexdigest(), 'entries': [e[0].decode() for e in ents]}}
(OUT / 'qol24_build.json').write_text(json.dumps(rep, indent=2), encoding='utf-8'); print(json.dumps(rep))
