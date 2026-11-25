r"""P26z23 (24 Nov 2026) = live P26z22 (ManifestID 8098004868618132953) + Bees 6764d96a "Radiation Fixes and Kit Fixes"
(41st_KitMenu + BUZZ_Radiation rebuilt from the live PBOs by D:/AuxUpdater/rad23/make_rad23.py). Miran typed "Stage P26z23 now".
Publish ONLY on Miran's own typed go naming P26z23. usage: make_p26z23.py OUT_NAME"""
import hashlib, json, os, shutil, sys
from pathlib import Path
DL = Path(r'C:/Users/Miran/Downloads')
BASE = DL / 'Steam-aux-release-20261124-P26z22-halloween'
PARTS = Path(r'D:/AuxUpdater/rad23/out')
OUT = DL / sys.argv[1]
b = json.loads((PARTS / 'rad23_build.json').read_text(encoding='utf-8'))
ORIGIN = {
    '41st_KitMenu': 'Bees 6764d96a: radiation kits offer the player\'s own radiation-protected helmet (ARCs, Merrik and other named players); FST_autoCustoms.sqf + XEN_PreInit.sqf only',
    'BUZZ_Radiation': 'Bees 6764d96a: Zeus Enhanced "Radiation Zone" module (new fnc_zeusZone), Geiger/cough sounds from a local helper object, radiation medical crate lists the full medical contents; 4 entries changed + 1 added',
}
CHG = {'Addons/%s.pbo' % k: (PARTS / ('%s.pbo' % k), v['new_sha256'], v['new_bytes'], ORIGIN[k]) for k, v in b['pbos'].items()}
live = json.loads((BASE / 'publish-result.json').read_text(encoding='utf-8'))
assert live['status'] == 'Published and verified' and live['content_manifest_id'] == '8098004868618132953', live.get('content_manifest_id')
man = json.loads((BASE / 'RELEASE_MANIFEST.json').read_text(encoding='utf-8'))
assert man['file_count'] == live['file_count'] == 119 and man['total_bytes'] == live['file_size_bytes']
assert all(k.lower() in {e['file'].lower() for e in man['files']} for k in CHG)
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
        src, h, size, origin = CHG[e['file']]; shutil.copy2(src, dst)
        assert sha(dst) == h and dst.stat().st_size == size, e['file']; e.update(bytes=size, sha256=h, origin=origin)
    else:
        src = BASE / '@41st_Kaid_Aux_Release' / e['file']; assert src.stat().st_size == e['bytes'], e['file']; os.link(src, dst)
man['base_release'] = BASE.name; man['base_time_updated'] = live['time_updated']; man['base_file_size'] = live['file_size_bytes']
man['base_content_manifest_id'] = live['content_manifest_id']
man['added'] = []; man['changed'] = sorted(CHG); man['removed'] = []
man['file_count'] = len(man['files']); man['total_bytes'] = sum(e['bytes'] for e in man['files'])
man['prepared_at'] = '2026-11-24 Aux Updater (live P26z22 + Bees 6764d96a radiation + kit fixes)'
man['publication_status'] = 'staged variant of %s; NOT published' % BASE.name
(OUT / 'RELEASE_MANIFEST.json').write_text(json.dumps(man, indent=2), encoding='utf-8')
shutil.copy2(BASE / 'publish_release.py', OUT / 'publish_release.py')
(OUT / 'workshop-change-note.txt').write_text('''Radiation and kit fixes

- Added: Zeus can place radiation zones (Zeus Enhanced module "BUZZ Radiation > Radiation Zone").
- Updated: the radiation medical crate now holds the full medical crate contents plus the radiation gear.
- Updated: ARCs, Merrik and other named players can pick their own radiation-protected helmet on radiation kits.
- Fixed: Geiger counter and cough sounds should now play for nearby players (needs a multiplayer test).

Let Steam finish the update before joining. Update the server and headless clients, then start a new mission.
''', encoding='utf-8')
print(json.dumps({'out': str(OUT), 'files': man['file_count'], 'bytes': man['total_bytes'], 'changed': man['changed'],
                  'delta_bytes': man['total_bytes'] - live['file_size_bytes']}))
