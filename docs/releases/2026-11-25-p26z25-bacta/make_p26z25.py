r"""P26z25 (25 Nov 2026) = live P26z24 (ManifestID 2736663053925847662)
  + CHG Addons/41st_Medical.pbo: Bacta Tank fix (Miran's pick via the Omnibus, "Bandaged, even if down"; bacta25/make_bacta25.py).
Nothing else. Publish ONLY on Miran's own typed go naming P26z25. usage: make_p26z25.py OUT_NAME"""
import hashlib, json, os, shutil, sys
from pathlib import Path
DL = Path(r'C:/Users/Miran/Downloads')
BASE = DL / 'Steam-aux-release-20261125-P26z24-qol-thirra11-menufix'
OUT = DL / sys.argv[1]
b = json.loads(Path(r'D:/AuxUpdater/bacta25/out/bacta25_build.json').read_text(encoding='utf-8'))['41st_Medical']
CHG = {'Addons/41st_Medical.pbo': (Path(r'D:/AuxUpdater/bacta25/out/41st_Medical.pbo'), b['pbo_sha256'], b['pbo_bytes'],
       'Bacta Tank fix 25 Nov (Miran: "Bandaged, even if down"): FST_Bacta_Tank treatment works on a living patient, conscious or unconscious, '
       'once bleeding is stopped, medic still; anywhere (treatmentLocations 0). config.cpp only (bacta25/make_bacta25.py)',
       b['src_sha256'])}
live = json.loads((BASE / 'publish-result.json').read_text(encoding='utf-8'))
assert live['status'] == 'Published and verified' and live['content_manifest_id'] == '2736663053925847662', live.get('content_manifest_id')
man = json.loads((BASE / 'RELEASE_MANIFEST.json').read_text(encoding='utf-8'))
assert man['file_count'] == live['file_count'] == 120 and man['total_bytes'] == live['file_size_bytes']
names = {e['file'].lower(): e for e in man['files']}
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
man['base_release'] = BASE.name; man['base_time_updated'] = live['time_updated']; man['base_file_size'] = live['file_size_bytes']
man['base_content_manifest_id'] = live['content_manifest_id']
man['added'] = []; man['changed'] = sorted(CHG); man['removed'] = []
man['file_count'] = len(man['files']); man['total_bytes'] = sum(e['bytes'] for e in man['files'])
man['prepared_at'] = '2026-11-25 Aux Updater (live P26z24 + Bacta Tank fix)'
man['publication_status'] = 'staged variant of %s; NOT published' % BASE.name
(OUT / 'RELEASE_MANIFEST.json').write_text(json.dumps(man, indent=2), encoding='utf-8')
shutil.copy2(BASE / 'publish_release.py', OUT / 'publish_release.py')
(OUT / 'workshop-change-note.txt').write_text('''Bacta Tank fix

- Fixed: Apply Bacta now works on downed (unconscious) patients once all bleeding is bandaged, anywhere.

Let Steam finish the update before joining. Update the server and headless clients, then start a new mission.
''', encoding='utf-8')
print(json.dumps({'out': str(OUT), 'files': man['file_count'], 'bytes': man['total_bytes'], 'changed': man['changed'],
                  'delta_bytes': man['total_bytes'] - live['file_size_bytes']}))
