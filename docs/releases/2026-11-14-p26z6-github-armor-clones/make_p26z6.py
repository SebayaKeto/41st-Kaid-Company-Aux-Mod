"""P26z6 (14 Nov) = live P26z5 (ManifestID 2708147363340149725) + GitHub ae532be7..6eb56a2d (Miran 14 Nov "We need to do an Aux Push with any changes that came in
from Github over the past week"): 41st_Armor (House 38a21bc6 Chimmy cold assault, 5d71aee7 Souls/Gode/NVG/Gaunt/Zombie) + 41st_Other_Clones (Catboy 27a716d4 104th/327th,
6eb56a2d 69th). Rebuilt from live by p26h/rebuild.py base ae532be7 (D:/AuxUpdater/p26z6) + local fixes: helmet names (8 incl. Zombie, fix_helmets2.py) and
Other_Clones requiredAddons (fix_clones_req.py; 27a716d4 reverted 83b5b79d; + OPTRE_Misc_Objects for FST_69_Ears). Usage: make_p26z6.py"""
import hashlib, json, os, shutil, sys
from pathlib import Path
DL = Path(r'C:/Users/Miran/Downloads')
BASE = DL / 'Steam-aux-release-20261112-P26z5-embercaldera'
OUT = DL / 'Steam-aux-release-20261114-P26z6-github-armor-clones'
BURNS = False
assert not OUT.exists(), OUT
CHANGES = {
    'Addons/41st_Armor.pbo': (Path(r'D:/AuxUpdater/p26z6/out/41st_Armor.pbo'), '457e9223ee7af24a9c1042982e1255e8c3fbf6bae09ad14f309d0c5522b3436f', 2282889941,
        'live + 38a21bc6 Chimmy squads cold assault armors + 5d71aee7 Souls upper, Gode armor code, Souls NVGs, Gaunt P2 helmet, Zombie armor + 8 unit helmet names FST_AB_Helmet_X -> FST_Airborne_Helmet_X (incl. Zombie)'),
    'Addons/41st_Other_Clones.pbo': (Path(r'D:/AuxUpdater/p26z6/out/41st_Other_Clones.pbo'), '16fddc6db96807d9f9ae8957cf4ff36e7a56a9c8d12f98340edfdcac8ec055f9', 14905733,
        'live + 27a716d4 104th and 327th clones + 6eb56a2d 69th clone unit + requiredAddons {41st_Addon, JLTS_characters_CloneArmor, OPTRE_Misc_Objects}'),
}
live = json.loads((BASE / 'publish-result.json').read_text(encoding='utf-8'))
assert live['status'] == 'Published and verified' and live['content_manifest_id'] == '2708147363340149725', live.get('content_manifest_id')
man = json.loads((BASE / 'RELEASE_MANIFEST.json').read_text(encoding='utf-8'))
changed = []
for e in man['files']:
    dst = OUT / '@41st_Kaid_Aux_Release' / e['file']; dst.parent.mkdir(parents=True, exist_ok=True)
    if e['file'] in CHANGES:
        src, sha, size, origin = CHANGES[e['file']]
        shutil.copy2(src, dst); data = dst.read_bytes(); h = hashlib.sha256(data).hexdigest()
        assert h == sha and len(data) == size, e['file']
        if h != e['sha256']: changed.append(e['file'])
        e.update(bytes=len(data), sha256=h, origin=origin)
    else:
        os.link(BASE / '@41st_Kaid_Aux_Release' / e['file'], dst)
assert sorted(changed) == sorted(CHANGES), changed
man['base_release'] = BASE.name; man['base_time_updated'] = live['time_updated']; man['base_file_size'] = live['file_size_bytes']
man['base_content_manifest_id'] = live['content_manifest_id']
man['changed'] = sorted(changed); man['added'] = []; man['removed'] = []
man['file_count'] = len(man['files']); man['total_bytes'] = sum(e['bytes'] for e in man['files'])
man['prepared_at'] = '2026-11-14 Aux Updater (P26z5 + GitHub ae532be7..6eb56a2d: 41st_Armor, 41st_Other_Clones)'
man['publication_status'] = 'staged; NOT published'
(OUT / 'RELEASE_MANIFEST.json').write_text(json.dumps(man, indent=2), encoding='utf-8')
shutil.copy2(BASE / 'publish_release.py', OUT / 'publish_release.py')
note = '''Armor and clone unit update

- New armor: Zombie (P2 armor and unit), Gaunt P2 helmet, Souls NVGs and updated Souls armor; Gode and Chimmy squad cold assault armor fixes.
- New clone units: 104th, 327th and 69th.

Let Steam finish the update before joining. Update the server and headless clients, then start a new mission.
'''
(OUT / 'workshop-change-note.txt').write_text(note, encoding='utf-8')
print(json.dumps({'out': str(OUT), 'files': man['file_count'], 'bytes': man['total_bytes'], 'changed': man['changed']}))
