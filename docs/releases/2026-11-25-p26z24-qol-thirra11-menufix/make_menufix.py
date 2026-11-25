r"""Fix A candidate (Aux Updater, 25 Nov 2026; Omnibus: separate candidate on top of P26z24, Miran decides, never folded in).
41st_Menu.pbo config.cpp, two text edits, nothing else:
  1. RscTitles >> RscDisplayMainMenuBackground >> Controls: restore the vanilla bases (Background: RscText,
     BackgroundLeft/Right: Background, Picture: RscPicture). Same black values as before. Removes the 4 "Updating base class
     X->''" lines and the 8 "no type entry" warnings (the menu-stall marker).
  2. RscDisplayMain >> Controls: remove the stray typeless "class News { x = 2.5; }". Vanilla has no top-level News there,
     so this deletes a brand-new broken control. Removes "no type entry inside class RscDisplayMain/controls/News".
Checks: the source PBO sha = the live P26z23/P26z24 one; exactly 2 replacements; dupscope 0; CfgConvert -bin rc 0; only
config.cpp differs (other entries byte-equal); read-back. usage: make_menufix.py OUTDIR"""
import hashlib, json, re, subprocess, sys, tempfile
from pathlib import Path
sys.path.insert(0, r'D:/AuxUpdater/gulfix'); import replace_entries as r
CFGC = r'C:/Program Files (x86)/Steam/steamapps/common/Arma 3 Tools/CfgConvert/CfgConvert.exe'
SRC = Path(r'C:/Users/Miran/Downloads/Steam-aux-release-20261125-P26z24-qol-thirra11/@41st_Kaid_Aux_Release/Addons/41st_Menu.pbo')
OUT = Path(sys.argv[1]); assert not OUT.exists(); OUT.mkdir(parents=True)
src = SRC.read_bytes(); src_sha = hashlib.sha256(src).hexdigest()
man = json.loads((SRC.parents[2] / 'RELEASE_MANIFEST.json').read_text(encoding='utf-8'))
assert [e['sha256'] for e in man['files'] if e['file'].lower() == 'addons/41st_menu.pbo'] == [src_sha], 'source is not the staged P26z24 41st_Menu'
props, ents, hv = r.parse(src)
idx = [i for i, e in enumerate(ents) if e[0].lower() == b'config.cpp']; assert len(idx) == 1
cfg = ents[idx[0]][2]; nl = b'\r\n' if b'\r\n' in cfg else b'\n'
OLD1 = [b'\t\t\tclass Background      { colorBackground[] = {0,0,0,1}; };',
        b'\t\t\tclass BackgroundLeft  { colorBackground[] = {0,0,0,1}; };',
        b'\t\t\tclass BackgroundRight { colorBackground[] = {0,0,0,1}; };',
        b'\t\t\tclass Picture         { text = "#(argb,8,8,3)color(0,0,0,1)"; };']
NEW1 = [b'\t\t\tclass Background: RscText            { colorBackground[] = {0,0,0,1}; };',
        b'\t\t\tclass BackgroundLeft: Background      { colorBackground[] = {0,0,0,1}; };',
        b'\t\t\tclass BackgroundRight: Background     { colorBackground[] = {0,0,0,1}; };',
        b'\t\t\tclass Picture: RscPicture             { text = "#(argb,8,8,3)color(0,0,0,1)"; };']
old1, new1 = nl.join(OLD1), nl.join(NEW1)
assert cfg.count(old1) == 1, 'block 1 not found exactly once'
cfg2 = cfg.replace(old1, new1)
m = re.findall(rb'\t\tclass News\r?\n\t\t\{\r?\n\t\t\tx="2\.5";\r?\n\t\t\};\r?\n', cfg2); assert len(m) == 1, ('News block', m)
cfg2 = cfg2.replace(m[0], b'')
assert b'class News' not in cfg2
with tempfile.TemporaryDirectory() as td:
    t = Path(td) / 'config.cpp'; t.write_bytes(cfg2)
    d = subprocess.run([sys.executable, r'D:/AuxUpdater/tools/dupscope.py', str(t)], capture_output=True, text=True); assert d.returncode == 0, d.stdout
    c = subprocess.run([CFGC, '-bin', '-dst', str(Path(td) / 'config.bin'), str(t)], capture_output=True, text=True); assert c.returncode == 0, (c.stdout, c.stderr)
e = ents[idx[0]]; ents[idx[0]] = [e[0], [e[1][0], len(cfg2), e[1][2], e[1][3], len(cfg2)], cfg2]
pbo = r.build(props, ents, hv)
dst = OUT / '41st_Menu.pbo'; dst.write_bytes(pbo)
p2, back, hv2 = r.parse(dst.read_bytes())
assert p2 == props and [(b[0], b[2]) for b in back] == [(x[0], x[2]) for x in ents]
_, orig, _ = r.parse(src)
diff = [o[0].decode() for o, b in zip(orig, back) if o[2] != b[2]]; assert diff == ['config.cpp'], diff
(OUT / 'config.cpp.patched').write_bytes(cfg2)
rep = {'41st_Menu': {'src_sha256': src_sha, 'pbo_bytes': len(pbo), 'pbo_sha256': hashlib.sha256(pbo).hexdigest(), 'changed_entries': diff,
                     'cfg_bytes_before': len(cfg), 'cfg_bytes_after': len(cfg2)}}
(OUT / 'menufix_build.json').write_text(json.dumps(rep, indent=2), encoding='utf-8'); print(json.dumps(rep))
