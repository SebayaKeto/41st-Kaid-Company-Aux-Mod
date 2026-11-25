r"""P26z24 WEEKEND (25 Nov 2026) = live P26z23 (ManifestID 8906419198321423684)
  + ADD Addons/KAID_QoL.pbo (qol24: our own Remove stamina, Remove stamina - ACE 3, No Weapon Sway, More Aircraft Displays)
  + CHG Addons/41st_Menu.pbo: menu fix (Fix A, Miran 25 Nov "Include the menu fix in P26z24").
  + CHG Addons/fst_ember_caldera.pbo: Thirra build 11 (Miran's pick "Build 10, drop pad"; C:/IslandsA/output_whole11) replaces 9c 8776da75.
One folder so players download once before Sat (Omnibus 25 Nov). Supersedes the qol-only P26z24 folder (never published).
Publish ONLY on Miran's own typed go naming P26z24. usage: make_p26z24w.py OUT_NAME"""
import hashlib, json, os, shutil, sys
from pathlib import Path
DL = Path(r'C:/Users/Miran/Downloads')
BASE = DL / 'Steam-aux-release-20261124-P26z23-radiation-kits'
OUT = DL / sys.argv[1]
q = json.loads(Path(r'D:/AuxUpdater/qol24/out/qol24_build.json').read_text(encoding='utf-8'))['KAID_QoL']
ADD = {'Addons/KAID_QoL.pbo': (Path(r'D:/AuxUpdater/qol24/out/KAID_QoL.pbo'), q['pbo_sha256'], q['pbo_bytes'],
       'Aux Updater 25 Nov: our own versions of Remove stamina, Remove stamina - ACE 3, No Weapon Sway and More Aircraft Displays (qol24/src/KAID_QoL)')}
CHG = {'Addons/fst_ember_caldera.pbo': (Path(r'C:/IslandsA/output_whole11/@FST_EmberCaldera/addons/fst_ember_caldera.pbo'),
       '8edc766a1a029e686925677f87e73e24ef3f193c6a11096a54efa808c83133c1', 174827773,
       'Ember Caldera (Thirra) terrain build 11 (Miran pick "Build 10, drop pad"; same 1476 entries as 9c, config.bin byte-equal to 9c; 281 paa/rvmat/roads/wrp changed); C:/IslandsA/output_whole11',
       '8776da75115031ad020d7f5104e5a80fd36da0340f401b7e09365d5868ffe984'),
       'Addons/41st_Menu.pbo': (Path(r'D:/AuxUpdater/clickfix/menustall/out_menufix/41st_Menu.pbo'),
       '1f4d724e629a48721baadd64e7d58fac799a6ef05f28fc047b02f28fab681581', 242200514,
       'Fix A 25 Nov (Miran: "Include the menu fix in P26z24"): 41st_Menu config.cpp only, RscDisplayMainMenuBackground bases restored + stray typeless News removed (clickfix/menustall/make_menufix.py)',
       'c8d45f2a5258111b88c0ddd1df313a03400cc85cdef8c1f08a51005b33c07581')}
live = json.loads((BASE / 'publish-result.json').read_text(encoding='utf-8'))
assert live['status'] == 'Published and verified' and live['content_manifest_id'] == '8906419198321423684', live.get('content_manifest_id')
man = json.loads((BASE / 'RELEASE_MANIFEST.json').read_text(encoding='utf-8'))
assert man['file_count'] == live['file_count'] == 119 and man['total_bytes'] == live['file_size_bytes']
names = {e['file'].lower(): e for e in man['files']}
assert not any(k.lower() in names for k in ADD)
for k, v in CHG.items(): assert names[k.lower()]['sha256'] == v[4], k
def sha(p):
    h = hashlib.sha256()
    with open(p, 'rb') as f:
        for c in iter(lambda: f.read(8 << 20), b''): h.update(c)
    return h.hexdigest()
assert not OUT.exists(), OUT
A = OUT / '@41st_Kaid_Aux_Release'
for e in man['files']:
    dst = A / e['file']; dst.parent.mkdir(parents=True, exist_ok=True)
    if e['file'] in CHG:
        src, h, size, origin, _ = CHG[e['file']]
        shutil.copy2(src, dst); assert sha(dst) == h and dst.stat().st_size == size, e['file']
        e.update({'bytes': size, 'sha256': h, 'origin': origin}); continue
    src = BASE / '@41st_Kaid_Aux_Release' / e['file']; assert src.stat().st_size == e['bytes'], e['file']; os.link(src, dst)
for f, (src, h, size, origin) in ADD.items():
    dst = A / f; shutil.copy2(src, dst); assert sha(dst) == h and dst.stat().st_size == size, f
    man['files'].append({'file': f, 'bytes': size, 'sha256': h, 'origin': origin})
man['base_release'] = BASE.name; man['base_time_updated'] = live['time_updated']; man['base_file_size'] = live['file_size_bytes']
man['base_content_manifest_id'] = live['content_manifest_id']
man['added'] = sorted(ADD); man['changed'] = sorted(CHG); man['removed'] = []
man['file_count'] = len(man['files']); man['total_bytes'] = sum(e['bytes'] for e in man['files'])
man['prepared_at'] = '2026-11-25 Aux Updater (live P26z23 + KAID_QoL + Thirra terrain build 11 + menu fix; weekend release)'
man['publication_status'] = 'staged variant of %s; NOT published' % BASE.name
(OUT / 'RELEASE_MANIFEST.json').write_text(json.dumps(man, indent=2), encoding='utf-8')
shutil.copy2(BASE / 'publish_release.py', OUT / 'publish_release.py')
(OUT / 'workshop-change-note.txt').write_text('''Thirra update + built-in quality of life

- Updated: Thirra terrain (new build).
- Fixed: broken main menu background elements.
- Added: no stamina, no weapon sway, and a pilot ETA + fuel panel are now part of the Aux.
- After this update you can remove these mods from your preset: Remove stamina, Remove stamina - ACE 3, No Weapon Sway, More Aircraft Displays.

Let Steam finish the update before joining. Update the server and headless clients, then start a new mission.
''', encoding='utf-8')
print(json.dumps({'out': str(OUT), 'files': man['file_count'], 'bytes': man['total_bytes'], 'added': man['added'], 'changed': man['changed'],
                  'delta_bytes': man['total_bytes'] - live['file_size_bytes']}))
