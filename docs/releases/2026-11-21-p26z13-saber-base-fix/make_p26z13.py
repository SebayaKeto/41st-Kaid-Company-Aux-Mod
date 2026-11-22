r"""P26z13 (21 Nov) = live P26z12 (ManifestID 1278212285708303239) with FST_Saber_Handling.pbo fixed: 3AS_Saber_01_Base declared with its 3AS parent
Tank_F (the 14 Oct version declared it without a parent and blanked it Tank_F->''; BUZZ_Radiation_Compat_FST had been restoring it). Miran 21 Nov "Yes, stage the fix".
Publish only on his typed go naming P26z13. usage: make_p26z13.py prep OUT_NAME | finish OUT_NAME"""
import hashlib, json, os, shutil, sys
from pathlib import Path
DL = Path(r'C:/Users/Miran/Downloads')
BASE = DL / 'Steam-aux-release-20261121-P26z12-suddra-gg7'
mode, OUT = sys.argv[1], DL / sys.argv[2]
CHG = {'Addons/FST_Saber_Handling.pbo': (r'D:/AuxUpdater/saberhandling/out2/FST_Saber_Handling.pbo',
        'c6917270c419ba734c9badbde6c485f64b9fba8315328ea4af4e21289556a7f1', 1173,
        'Saber handling tune (24 Sep / 14 Oct) with 3AS_Saber_01_Base: Tank_F declared (no longer blanks the 3AS parent); D:/AuxUpdater/saberhandling/src2')}
live = json.loads((BASE / 'publish-result.json').read_text(encoding='utf-8'))
assert live['status'] == 'Published and verified' and live['content_manifest_id'] == '1278212285708303239', live.get('content_manifest_id')
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
man['prepared_at'] = '2026-11-21 Aux Updater (live P26z12 + Saber base fix)'
man['publication_status'] = 'staged variant of %s; NOT published' % BASE.name
(OUT / 'RELEASE_MANIFEST.json').write_text(json.dumps(man, indent=2), encoding='utf-8')
shutil.copy2(BASE / 'publish_release.py', OUT / 'publish_release.py')
(OUT / 'workshop-change-note.txt').write_text('''Saber fix

- Saber tanks: fixed a config conflict so the Saber keeps its full tank settings.

Let Steam finish the update before joining. Update the server and headless clients, then start a new mission.
''', encoding='utf-8')
print(json.dumps({'out': str(OUT), 'files': man['file_count'], 'bytes': man['total_bytes'], 'changed': man['changed'],
                  'delta_bytes': man['total_bytes'] - live['file_size_bytes']}))
