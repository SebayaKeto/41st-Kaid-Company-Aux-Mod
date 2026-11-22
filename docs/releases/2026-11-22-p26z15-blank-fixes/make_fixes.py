"""P26z15 candidate: declare the real parents where our configs redeclare a class without one (base-class blank to '').
Reads blankfix/live/<pbo>/<entry> (extracted from live P26z14), writes blankfix/src/<pbo>/<entry>. Exact replacements, asserted counts,
original newline style kept. FST_Vehicles_Weapons is config.bin: edited as derapified text, re-binarized later by build.py."""
import re
from pathlib import Path
L = Path(r'D:/AuxUpdater/blankfix/live'); S = Path(r'D:/AuxUpdater/blankfix/src')

def load(rel):
    raw = (L / rel).read_bytes().decode('utf-8')
    return raw.replace('\r\n', '\n'), ('\r\n' if '\r\n' in raw else '\n')

def save(rel, s, nl):
    p = S / rel; p.parent.mkdir(parents=True, exist_ok=True); p.write_bytes(s.replace('\n', nl).encode('utf-8')); print('wrote', rel)

def rep(s, old, new, n=1):
    assert s.count(old) == n, (old[:80], s.count(old)); return s.replace(old, new)

def block_span(s, name):
    m = re.search(r'\n[ \t]*class ' + name + r'\s*:\s*\w+\s*\{', s); assert m, name
    i = m.end(); d = 1
    while d: d += (s[i] == '{') - (s[i] == '}'); i += 1
    return m.start(), i

# 1. 773 Firepuncher: arifle_MX_Base_F keeps Rifle_Base_F (vanilla a3\weapons_f\rifles\mx)
rel = '41st_Weapons/773-firepuncher/config.cpp'; s, nl = load(rel)
s = rep(s, '\tclass arifle_MX_Base_F\n\t{\n\t\tclass WeaponSlotsInfo;', '\tclass Rifle_Base_F;\n\tclass arifle_MX_Base_F: Rifle_Base_F\n\t{\n\t\tclass WeaponSlotsInfo;')
save(rel, s, nl)

# 2-3. DC-15N, DLT-15: Rifle_Base_F keeps Rifle (vanilla a3\weapons_f)
for rel in ('41st_Weapons/dc-15n/config.cpp', '41st_Weapons/dlt15/config.cpp'):
    s, nl = load(rel)
    s = rep(s, '\tclass Rifle_Base_F\n\t{\n\t\tclass WeaponSlotsInfo;', '\tclass Rifle;\n\tclass Rifle_Base_F: Rifle\n\t{\n\t\tclass WeaponSlotsInfo;')
    save(rel, s, nl)

# 4-5. DC-15AS, SBB-3: the four [41st] light attachments inherit FST_Base_Flashlight (as dc15x/z6/t15/dlt15/dp23 do), Iteminfo: Iteminfo, Flashlight: Flashlight
z6, _ = load('41st_Weapons/z6/config.cpp'); a, b = block_span(z6, 'FST_Base_Flashlight'); assert z6[b] == ';'; base = z6[a:b + 1].lstrip('\n')
ATT = ['FST_Attachment_Light_Normal_White', 'FST_Attachment_Light_Beam_White', 'FST_Attachment_Module_Light_Normal_White', 'FST_Attachment_Module_Light_Beam_White']
for rel in ('41st_Weapons/dc-15as/config.cpp', '41st_Weapons/sbb3/config.cpp'):
    s, nl = load(rel)
    for name in ATT:
        a, b = block_span(s, name); blk = s[a:b]
        blk2 = re.sub(r'(class ' + name + r'\s*:\s*)acc_flashlight', r'\1FST_Base_Flashlight', blk, count=1)
        blk2, n1 = re.subn(r'class Iteminfo(\s*\{)', r'class Iteminfo: Iteminfo\1', blk2)
        blk2, n2 = re.subn(r'class Flashlight(\s*\{)', r'class Flashlight: Flashlight\1', blk2)
        assert blk2 != blk and n1 == 1 and n2 == 1, (rel, name, n1, n2)
        s = s[:a] + blk2 + s[b:]
    # define the base once, right after the first 'class acc_flashlight;'
    m = re.search(r'\n([ \t]*)class acc_flashlight;\n', s); assert m and 'class FST_Base_Flashlight' not in s, rel
    s = s[:m.end()] + base + '\n' + s[m.end():]
    save(rel, s, nl)

# 6. LAAT cargo: Helicopter keeps Air
rel = '41st_Vehicles/laatc/config.cpp'; s, nl = load(rel)
s = rep(s, '\tclass Helicopter\n\t{\n\t};', '\tclass Air;\n\tclass Helicopter: Air\n\t{\n\t};')
save(rel, s, nl)

# 7. BUZZ AT-RT cargo patch: FST_ATRT_Base ItemInfo keeps UniformItem (as FST_ATRT defines it)
rel = 'BUZZ_Vehicles/atrt/config.cpp'; s, nl = load(rel)
s = rep(s, '    class ItemCore;\n    class FST_ATRT_Base: ItemCore {\n        class ItemInfo {',
           '    class ItemCore;\n    class UniformItem;\n    class FST_ATRT_Base: ItemCore {\n        class ItemInfo: UniformItem {')
save(rel, s, nl)

# 8. FST_Vehicles_Weapons (config.bin -> text): missiles_titan keeps MissileLauncher
rel = 'FST_Vehicles_Weapons/config.cpp'; s, nl = load(rel)
s = rep(s, '\tclass MissileLauncher;\n\tclass missiles_titan\n\t{', '\tclass MissileLauncher;\n\tclass missiles_titan: MissileLauncher\n\t{')
save(rel, s, nl)
