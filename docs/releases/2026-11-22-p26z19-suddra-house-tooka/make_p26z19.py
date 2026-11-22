r"""P26z19 CANDIDATE (22 Nov) = live P26z16 (ManifestID 7698095297189820764) + P26z18 music (Suddra Theme 1/2) + House be6b0fe8 41st_Armor
(+5 unit fixes) + Tooka a1875ee2 41st_Other_Clones (327th Environmental Troopers). Miran: "Tooka pushed, pull it in and build P26z19".
Supersedes the unpublished P26z18. Publish only on Miran's typed go naming P26z19. usage: make_p26z19.py prep OUT_NAME | finish OUT_NAME"""
import hashlib, json, os, shutil, sys
from pathlib import Path
DL = Path(r'C:/Users/Miran/Downloads')
BASE = DL / 'Steam-aux-release-20261122-P26z16-weapons-sweep'
mode, OUT = sys.argv[1], DL / sys.argv[2]
CHG = {
    'Addons/41st_Music.pbo': (r'D:/AuxUpdater/music18/41st_Music.pbo', '389d1212b07fd2a19e107117d03b8a4e548a01ed055e367d1b3529460d460e26', 1272726706,
        'live P26z16 41st_Music + config.cpp (FST_SuddraTheme, FST_SuddraTheme2) + MissionTracks Suddra_Theme.ogg, Suddra_Theme_2.ogg; D:/AuxUpdater/music18/make_music18.py'),
    'Addons/41st_Armor.pbo': (r'D:/AuxUpdater/armor19/41st_Armor.pbo', '47ee62dce0adb1ae1915531dc9234cd59e446975a7a141a79fcadbec7c7a8048', 2308167544,
        'live + House be6b0fe8 (Party P2 helmet, Draco jump pack, Comedian/Ordo/Overwatch/Red dirty sets, Rick upper, Pole face); config 3-way merged (live helmet-name fixes kept) + 5 unit fixes (armor19/fix_house.py)'),
    'Addons/41st_Other_Clones.pbo': (r'D:/AuxUpdater/clones19/41st_Other_Clones.pbo', '9060ecaca1b1bfbf311ff88671abca0a381f9403ef7d46dc1d4c4a471305ee6f', 16096856,
        'live + Tooka a1875ee2 327th Environmental Troopers (12 units, groups, P2 327 Enviro helmet, 12 loadout scripts); live requiredAddons kept'),
}
live = json.loads((BASE / 'publish-result.json').read_text(encoding='utf-8'))
assert live['status'] == 'Published and verified' and live['content_manifest_id'] == '7698095297189820764', live.get('content_manifest_id')
man = json.loads((BASE / 'RELEASE_MANIFEST.json').read_text(encoding='utf-8'))
assert man['file_count'] == live['file_count'] == 101 and man['total_bytes'] == live['file_size_bytes']
assert all(k.lower() in {e['file'].lower() for e in man['files']} for k in CHG)
def sha(p):
    h = hashlib.sha256()
    with open(p, 'rb') as f:
        for c in iter(lambda: f.read(8 << 20), b''): h.update(c)
    return h.hexdigest()
A = OUT / '@41st_Kaid_Aux_Release'
if mode == 'prep':
    assert not OUT.exists(), OUT
    for e in man['files']:
        if e['file'] in CHG: continue
        src = BASE / '@41st_Kaid_Aux_Release' / e['file']; assert src.stat().st_size == e['bytes'], e['file']
        dst = A / e['file']; dst.parent.mkdir(parents=True, exist_ok=True); os.link(src, dst)
    shutil.copy2(BASE / 'RELEASE_MANIFEST.json', OUT / 'RELEASE_MANIFEST.json')
    print(json.dumps({'prep': str(OUT), 'linked': len(man['files']) - len(CHG)})); sys.exit()
assert mode == 'finish'
for k, (src, h, size, origin) in CHG.items():
    dst = A / k; assert not dst.exists(), dst
    shutil.copy2(Path(src), dst); got = sha(dst); assert got == h and dst.stat().st_size == size, (k, got, dst.stat().st_size)
for e in man['files']:
    if e['file'] in CHG:
        _, h, size, origin = CHG[e['file']]; e.update(bytes=size, sha256=h, origin=origin)
    else:
        assert (A / e['file']).stat().st_size == e['bytes'], e['file']
man['base_release'] = BASE.name; man['base_time_updated'] = live['time_updated']; man['base_file_size'] = live['file_size_bytes']
man['base_content_manifest_id'] = live['content_manifest_id']
man['added'] = []; man['changed'] = sorted(CHG); man['removed'] = []
man['file_count'] = len(man['files']); man['total_bytes'] = sum(e['bytes'] for e in man['files'])
man['prepared_at'] = '2026-11-22 Aux Updater (live P26z16 + Suddra music + House armor + Tooka 327th Environmental)'
man['publication_status'] = 'staged variant of %s; NOT published' % BASE.name
(OUT / 'RELEASE_MANIFEST.json').write_text(json.dumps(man, indent=2), encoding='utf-8')
shutil.copy2(BASE / 'publish_release.py', OUT / 'publish_release.py')
(OUT / 'workshop-change-note.txt').write_text('''Suddra music, new armor sets, 327th Environmental Troopers

- Music: added Suddra Theme and Suddra Theme 2 to 41st - Mission Tracks.
- Armor: added Party P2 helmet, Draco jump pack and Comedian, Ordo, Overwatch and Red dirty armor, helmets and NVGs; updated Rick and Pole.
- Other Clones: added 327th Environmental Troopers.

Let Steam finish the update before joining. Update the server and headless clients, then start a new mission.
''', encoding='utf-8')
print(json.dumps({'out': str(OUT), 'files': man['file_count'], 'bytes': man['total_bytes'], 'changed': man['changed'],
                  'delta_bytes': man['total_bytes'] - live['file_size_bytes']}))
