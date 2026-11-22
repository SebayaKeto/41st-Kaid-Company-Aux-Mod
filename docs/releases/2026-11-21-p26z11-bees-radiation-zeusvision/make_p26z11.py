r"""P26z11 (21 Nov) = live P26z10 (ManifestID 134245045922254320) + GitHub Bees 6eb56a2d..91ac025d (Miran 21 Nov "We need to push the four commits from bees
to the live aux"): e43bc26b radiation kits / All Star / environmental helmets / BUZZ_Radiation, 034978a1 radiation med crate, d136640a Zeus Vision,
91ac025d All Star ogg fix. PBOs from D:/AuxUpdater/p26z11/build.py. Publish only on Miran's typed "Go P26z11". usage: make_p26z11.py"""
import hashlib, json, os, shutil
from pathlib import Path
DL = Path(r'C:/Users/Miran/Downloads')
BASE = DL / 'Steam-aux-release-20261119-P26z10-thirra9c'
OUT = DL / 'Steam-aux-release-20261121-P26z11-bees-radiation-zeusvision'
assert not OUT.exists(), OUT
B = Path(r'D:/AuxUpdater/p26z11/out'); rep = json.loads(Path(r'D:/AuxUpdater/p26z11/build_report.json').read_text())
ORIGIN = {
 '41st_Armor': 'live + e43bc26b environmental helmets (Trooper, NCO, Woodland); config 3-way merged so live helmet-name fixes stay',
 '41st_KitMenu': 'live + e43bc26b radiation kits + Spawn Radiation Kit Locker module',
 '41st_Music': 'live + e43bc26b All Star (Misc) + 91ac025d fixed ogg',
 'BUZZ_Radiation': 'NEW e43bc26b + 034978a1: radiation zones, dose, iodine / monitor / flush IV, ACE medical entries, radiation medical crate, vehicle panels',
 'BUZZ_ZeusVision': 'NEW d136640a: Zeus trooper detail tags (right-click > Show Trooper Details)'}
CHG = {'Addons/%s.pbo' % k: (B / ('%s.pbo' % k), rep[k]['sha256'], rep[k]['bytes'], v) for k, v in ORIGIN.items()}
live = json.loads((BASE / 'publish-result.json').read_text(encoding='utf-8'))
assert live['status'] == 'Published and verified' and live['content_manifest_id'] == '134245045922254320', live.get('content_manifest_id')
man = json.loads((BASE / 'RELEASE_MANIFEST.json').read_text(encoding='utf-8'))
have = {e['file'] for e in man['files']}
A = OUT / '@41st_Kaid_Aux_Release'
def sha(p):
    h = hashlib.sha256()
    with open(p, 'rb') as f:
        for c in iter(lambda: f.read(8 << 20), b''): h.update(c)
    return h.hexdigest()
for e in man['files']:
    dst = A / e['file']; dst.parent.mkdir(parents=True, exist_ok=True)
    if e['file'] not in CHG: os.link(BASE / '@41st_Kaid_Aux_Release' / e['file'], dst)
added, changed = [], []
for k, (src, h, size, origin) in CHG.items():
    dst = A / k; shutil.copy2(src, dst); got = sha(dst); assert got == h and dst.stat().st_size == size, (k, got)
    if k in have:
        changed.append(k); next(e for e in man['files'] if e['file'] == k).update(bytes=size, sha256=h, origin=origin)
    else:
        added.append(k); man['files'].append({'file': k, 'bytes': size, 'sha256': h, 'origin': origin})
man['files'].sort(key=lambda e: e['file'].lower())
for e in man['files']: assert (A / e['file']).stat().st_size == e['bytes'], e['file']
man['base_release'] = BASE.name; man['base_time_updated'] = live['time_updated']; man['base_file_size'] = live['file_size_bytes']
man['base_content_manifest_id'] = live['content_manifest_id']
man['added'] = sorted(added); man['changed'] = sorted(changed); man['removed'] = []
man['file_count'] = len(man['files']); man['total_bytes'] = sum(e['bytes'] for e in man['files'])
man['prepared_at'] = '2026-11-21 Aux Updater (P26z10 + GitHub Bees 6eb56a2d..91ac025d)'
man['publication_status'] = 'staged; NOT published'
(OUT / 'RELEASE_MANIFEST.json').write_text(json.dumps(man, indent=2), encoding='utf-8')
shutil.copy2(BASE / 'publish_release.py', OUT / 'publish_release.py')
(OUT / 'workshop-change-note.txt').write_text('''Radiation, Zeus Vision and kit update

- New: radiation zones for Zeus and mission makers (radiation, safe and decontamination zones), with Iodine Tablets, Radiation Detection Device and Radiation Flush IV, plus a radiation medical crate.
- New: radiation kits and a Spawn Radiation Kit Locker module.
- New: environmental helmets (Trooper, NCO, Woodland).
- New: Zeus Vision. In Zeus, right-click > Show Trooper Details to tag nearby troopers with their kit and ammo.
- New music: All Star (Misc).

Let Steam finish the update before joining. Update the server and headless clients, then start a new mission.
''', encoding='utf-8')
print(json.dumps({'out': str(OUT), 'files': man['file_count'], 'bytes': man['total_bytes'], 'added': added, 'changed': changed,
                  'delta_bytes': man['total_bytes'] - live['file_size_bytes']}))
