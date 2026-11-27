r"""P26z26 (27 Nov 2026) = live P26z25 (ManifestID 2740359259603265369)
  + CHG Addons/fst_ember_caldera.pbo: Thirra terrain build 13 (op 5 Kastro town + pits; Thirra lane, C:/IslandsA/output_whole13).
Nothing else. REAL COPIES of every file (Omnibus ask 27 Nov 04:2x: no hard links into the P26z25 rollback source); each sha-checked.
Publish ONLY on Miran's own typed go naming P26z26. usage: make_p26z26.py OUT_NAME"""
import hashlib, json, shutil, sys
from pathlib import Path
DL = Path(r'C:/Users/Miran/Downloads')
BASE = DL / 'Steam-aux-release-20261125-P26z25-bacta'
OUT = DL / sys.argv[1]
B13 = Path(r'C:/IslandsA/output_whole13/@FST_EmberCaldera/addons/fst_ember_caldera.pbo')
B13_SHA = '6671c7152345502d79484762f307d6c9d16e1afbd0ecfab43d8915a82cbe1278'; B13_BYTES = 174834990
B11_SHA = '8edc766a1a029e686925677f87e73e24ef3f193c6a11096a54efa808c83133c1'
CHG = {'Addons/fst_ember_caldera.pbo': (B13, B13_SHA, B13_BYTES,
       'Thirra terrain build 13 (27 Nov): op 5 isle only - Kastro town box x4340-4800/y16590-17220, pit 1 (3475,16820), pit 2 (7645-7660,16925-16930); '
       '5,280 height points; 218/1,476 entries (WRP, roads, picturemap, 205 S / 7 M tiles); config.bin byte-equal to build 11. '
       'Source C:/IslandsA/output_whole13; checked by p26z26/check_b13.py (read-back byte-equal, dupscope 0)', B11_SHA)}
def sha(p):
    h = hashlib.sha256()
    with open(p, 'rb') as f:
        for c in iter(lambda: f.read(8 << 20), b''): h.update(c)
    return h.hexdigest()
live = json.loads((BASE / 'publish-result.json').read_text(encoding='utf-8'))
assert live['status'] == 'Published and verified' and live['content_manifest_id'] == '2740359259603265369', live.get('content_manifest_id')
man = json.loads((BASE / 'RELEASE_MANIFEST.json').read_text(encoding='utf-8'))
assert man['file_count'] == live['file_count'] == 120 and man['total_bytes'] == live['file_size_bytes']
names = {e['file'].lower(): e for e in man['files']}
for k, v in CHG.items(): assert names[k.lower()]['sha256'] == v[4], k
assert sha(B13) == B13_SHA and B13.stat().st_size == B13_BYTES, 'build-13 PBO is not 6671c715'
assert not OUT.exists(), OUT
A = OUT / '@41st_Kaid_Aux_Release'
for i, e in enumerate(man['files'], 1):
    dst = A / e['file']; dst.parent.mkdir(parents=True, exist_ok=True)
    if e['file'] in CHG:
        src, h, size, origin, _ = CHG[e['file']]
        shutil.copyfile(src, dst); assert sha(dst) == h and dst.stat().st_size == size, e['file']
        e.update({'bytes': size, 'sha256': h, 'origin': origin}); continue
    src = BASE / '@41st_Kaid_Aux_Release' / e['file']
    shutil.copyfile(src, dst)   # real copy, new file id
    assert dst.stat().st_size == e['bytes'] and sha(dst) == e['sha256'], e['file']
    if i % 20 == 0: print(i, 'files', flush=True)
man['base_release'] = BASE.name; man['base_time_updated'] = live['time_updated']; man['base_file_size'] = live['file_size_bytes']
man['base_content_manifest_id'] = live['content_manifest_id']
man['added'] = []; man['changed'] = sorted(CHG); man['removed'] = []
man['file_count'] = len(man['files']); man['total_bytes'] = sum(e['bytes'] for e in man['files'])
man['prepared_at'] = '2026-11-27 Aux Updater (live P26z25 + Thirra build 13); real copies, no hard links'
man['publication_status'] = 'staged variant of %s; NOT published' % BASE.name
(OUT / 'RELEASE_MANIFEST.json').write_text(json.dumps(man, indent=2), encoding='utf-8')
shutil.copyfile(BASE / 'publish_release.py', OUT / 'publish_release.py')
(OUT / 'workshop-change-note.txt').write_text('''Thirra update

- Updated: Kastro town rebuilt with real streets (op 5).
- Fixed: terrain pits on the crater ridge filled.

Let Steam finish the update before joining. Update the server and headless clients, then start a new mission.
''', encoding='utf-8')
print(json.dumps({'out': str(OUT), 'files': man['file_count'], 'bytes': man['total_bytes'], 'changed': man['changed'],
                  'delta_bytes': man['total_bytes'] - live['file_size_bytes']}))
