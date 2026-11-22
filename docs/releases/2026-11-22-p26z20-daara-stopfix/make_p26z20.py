r"""P26z20 CANDIDATE (22 Nov) = live P26z19 (ManifestID 71308130429365954) + Project Daara stop fix ck_character_v8.pbo (config.bin only:
CK_Daara_Stp cost 0.06 -> 0.04 in 8 Wlk classes + RunDf; tested server-only by Project Daara on Omnibus BOX OK). Miran: "Yes, stage P26z20".
Publish only on Miran's typed go naming P26z20. usage: make_p26z20.py prep OUT_NAME | finish OUT_NAME"""
import hashlib, json, os, shutil, sys
from pathlib import Path
DL = Path(r'C:/Users/Miran/Downloads')
BASE = DL / 'Steam-aux-release-20261122-P26z19-suddra-house-tooka'
mode, OUT = sys.argv[1], DL / sys.argv[2]
CHG = {
    'Addons/ck_character_v8.pbo': (r'D:/AuxUpdater/incoming/daara_stopfix_20261122/addons/ck_character_v8.pbo',
        '728147be9b98e8dc49d36f204b1f296fe66b2b83cda080474e8873849e7f6bbf', 97674462,
        'live P26m ck_character_v8 (md5 b210eb81) with config.bin only replaced: CK_Daara_Stp cost 0.06 -> 0.04 in CK_Daara_WlkDf/Dfl/Dfr/Dl/Dr/Db/Dbl/Dbr + RunDf (Project Daara stop fix, incoming/daara_stopfix_20261122)'),
}
live = json.loads((BASE / 'publish-result.json').read_text(encoding='utf-8'))
assert live['status'] == 'Published and verified' and live['content_manifest_id'] == '71308130429365954', live.get('content_manifest_id')
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
man['prepared_at'] = '2026-11-22 Aux Updater (live P26z19 + Project Daara stop fix)'
man['publication_status'] = 'staged variant of %s; NOT published' % BASE.name
(OUT / 'RELEASE_MANIFEST.json').write_text(json.dumps(man, indent=2), encoding='utf-8')
shutil.copy2(BASE / 'publish_release.py', OUT / 'publish_release.py')
(OUT / 'workshop-change-note.txt').write_text('''Daara stop fix

- Daara: stopping from a walk or run no longer briefly drops into the standard standing pose.

Let Steam finish the update before joining. Update the server and headless clients, then start a new mission.
''', encoding='utf-8')
print(json.dumps({'out': str(OUT), 'files': man['file_count'], 'bytes': man['total_bytes'], 'changed': man['changed'],
                  'delta_bytes': man['total_bytes'] - live['file_size_bytes']}))
