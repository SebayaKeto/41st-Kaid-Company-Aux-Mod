"""P26z16 candidate (sweep after the z15 load test): fix the remaining parentless redeclares in 41st_Weapons that sweep.py found.
Reads entries from live P26z15 41st_Weapons.pbo, writes D:/AuxUpdater/blankfix/src16/41st_Weapons/<dir>/config.cpp (newline style kept).
- DC-15N, DC-15U: the four [41st] light attachments -> FST_Base_Flashlight, Iteminfo: Iteminfo, Flashlight: Flashlight (+ the shared base block).
- DC-15U, DC-1A: Rifle_Base_F -> Rifle_Base_F: Rifle.
Not touched: ACE_muzzle_mzls_338 redeclares (DC-15N/DC-15U, latent: owner ACE loads after us; needs a load-order decision)."""
import re, sys
sys.path.insert(0, r'D:\AuxUpdater\gulfix'); import replace_entries as r
from pathlib import Path
P = Path(r'C:/Users/Miran/Downloads/Steam-aux-release-20261122-P26z15-blank-fixes/@41st_Kaid_Aux_Release/Addons/41st_Weapons.pbo')
OUT = Path(r'D:/AuxUpdater/blankfix/src16/41st_Weapons')
_, entries, _ = r.parse(P.read_bytes())
raw = {e[0].decode('latin1').replace(chr(92), '/'): e[2] for e in entries if e[0].lower().endswith(b'config.cpp')}

def get(name):
    b = raw[name].decode('utf-8'); return b.replace('\r\n', '\n'), ('\r\n' if '\r\n' in b else '\n')

def block_span(s, name):
    m = re.search(r'\n[ \t]*class ' + name + r'\s*:\s*\w+\s*\{', s); assert m, name
    i = m.end(); d = 1
    while d: d += (s[i] == '{') - (s[i] == '}'); i += 1
    return m.start(), i

z6, _ = get('Z6/config.cpp'); a, b = block_span(z6, 'FST_Base_Flashlight'); assert z6[b] == ';'; BASE = z6[a:b + 1].lstrip('\n')
ATT = ['FST_Attachment_Light_Normal_White', 'FST_Attachment_Light_Beam_White', 'FST_Attachment_Module_Light_Normal_White', 'FST_Attachment_Module_Light_Beam_White']

def fix_lights(s, f):
    for name in ATT:
        a, b = block_span(s, name); blk = s[a:b]
        blk2, n0 = re.subn(r'(class ' + name + r'\s*:\s*)acc_flashlight', r'\1FST_Base_Flashlight', blk, count=1)
        blk2, n1 = re.subn(r'class Iteminfo(\s*\{)', r'class Iteminfo: Iteminfo\1', blk2)
        blk2, n2 = re.subn(r'class Flashlight(\s*\{)', r'class Flashlight: Flashlight\1', blk2)
        assert (n0, n1, n2) == (1, 1, 1), (f, name, n0, n1, n2)
        s = s[:a] + blk2 + s[b:]
    m = re.search(r'\n[ \t]*class acc_flashlight;\n', s); assert m and 'class FST_Base_Flashlight' not in s, f
    return s[:m.end()] + BASE + '\n' + s[m.end():]

def fix_rifle(s, f):
    assert not re.search(r'\bclass Rifle\s*[;:{]', s), f
    s2, n = re.subn(r'\n([ \t]*)class Rifle_Base_F(\s*\{)', r'\n\1class Rifle;\n\1class Rifle_Base_F: Rifle\2', s)
    assert n == 1, (f, n); return s2

for f, fixes in (('DC-15N/config.cpp', [fix_lights]), ('DC-15U/config.cpp', [fix_rifle, fix_lights]), ('DC-1A/config.cpp', [fix_rifle])):
    s, nl = get(f)
    for fx in fixes: s = fx(s, f)
    p = OUT / f; p.parent.mkdir(parents=True, exist_ok=True); p.write_bytes(s.replace('\n', nl).encode('utf-8')); print('wrote', f)
    (Path(r'D:/AuxUpdater/blankfix/live16') / f).parent.mkdir(parents=True, exist_ok=True)
    (Path(r'D:/AuxUpdater/blankfix/live16') / f).write_bytes(raw[f])
