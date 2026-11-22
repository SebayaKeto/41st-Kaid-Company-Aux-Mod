"""P26z5 (12 Nov) = live P26z4 (ManifestID 4954687947041270642) + NEW terrain Ember Caldera build 5 (fst_ember_caldera.pbo, world fst_ember_caldera).
Omnibus 12 Nov ~19:30 forwarded the PBO (Miran in the Omnibus chat: "We need to make an aux push so they can use it too"); Miran typed "Push it" in the Aux chat.
Hard links every P26z4 file, copies in the one new PBO, rebases the manifest on live P26z4. Usage: make_p26z5.py"""
import hashlib, json, os, shutil
from pathlib import Path
DL = Path(r'C:/Users/Miran/Downloads')
BASE = DL / 'Steam-aux-release-20261108-P26z4-minedetector'
OUT = DL / 'Steam-aux-release-20261112-P26z5-embercaldera'
assert not OUT.exists(), OUT
NEW = 'Addons/fst_ember_caldera.pbo'
SRC = Path(r'C:/IslandsA/output_whole5/@FST_EmberCaldera/addons/fst_ember_caldera.pbo')
SHA, SIZE = '48c05c4ae095641d3c5cf47dc378e33e7de9aa232315a5d4e0708cf40fd7d0d5', 174276876
live = json.loads((BASE / 'publish-result.json').read_text(encoding='utf-8'))
assert live['status'] == 'Published and verified' and live['content_manifest_id'] == '4954687947041270642', live.get('content_manifest_id')
man = json.loads((BASE / 'RELEASE_MANIFEST.json').read_text(encoding='utf-8'))
assert man['file_count'] == live['file_count'] == 95 and man['total_bytes'] == live['file_size_bytes']
assert all(e['file'].lower() != NEW.lower() for e in man['files'])
for e in man['files']:
    src = BASE / '@41st_Kaid_Aux_Release' / e['file']
    assert src.stat().st_size == e['bytes'], e['file']
    dst = OUT / '@41st_Kaid_Aux_Release' / e['file']; dst.parent.mkdir(parents=True, exist_ok=True)
    os.link(src, dst)
dst = OUT / '@41st_Kaid_Aux_Release' / NEW
shutil.copy2(SRC, dst)
h = hashlib.sha256()
with open(dst, 'rb') as f:
    for chunk in iter(lambda: f.read(8 << 20), b''):
        h.update(chunk)
assert h.hexdigest() == SHA and dst.stat().st_size == SIZE, (h.hexdigest(), dst.stat().st_size)
man['files'].append({'file': NEW, 'bytes': SIZE, 'sha256': SHA,
                     'origin': 'Ember Caldera terrain build 5 (islands; world fst_ember_caldera); C:/IslandsA/output_whole5, manifest C:/IslandsA/whole/BUILD5_MANIFEST.md'})
man['base_release'] = BASE.name; man['base_time_updated'] = live['time_updated']; man['base_file_size'] = live['file_size_bytes']
man['base_content_manifest_id'] = live['content_manifest_id']
man['added'] = [NEW]; man['changed'] = []; man['removed'] = []
man['file_count'] = len(man['files']); man['total_bytes'] = sum(e['bytes'] for e in man['files'])
man['prepared_at'] = '2026-11-12 Aux Updater (live P26z4 + Ember Caldera terrain build 5; Miran "Push it")'
man['publication_status'] = 'staged variant of %s; NOT published' % BASE.name
(OUT / 'RELEASE_MANIFEST.json').write_text(json.dumps(man, indent=2), encoding='utf-8')
shutil.copy2(BASE / 'publish_release.py', OUT / 'publish_release.py')
(OUT / 'workshop-change-note.txt').write_text('''New terrain: Ember Caldera

- Adds the Ember Caldera islands terrain for this weekend's operations.

Let Steam finish the update before joining. Update the server and headless clients, then start a new mission.
''', encoding='utf-8')
print(json.dumps({'out': str(OUT), 'files': man['file_count'], 'bytes': man['total_bytes'], 'added': man['added']}))
