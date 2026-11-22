r"""P26z15 CANDIDATE (21/22 Nov) = live P26z14 (ManifestID 9087755986104411506) with the base-class blank fixes from the 31-blank audit
(D:/AuxUpdater/blankfix/REPORT_BLANKS_P26z15.md): declare the real parents where our configs redeclared a class without one.
Audit asked by Miran "Yes, check them" (relayed by the Omnibus); staging a candidate allowed, no publish. Publish only on his typed go naming P26z15.
usage: make_p26z15.py prep OUT_NAME | finish OUT_NAME"""
import hashlib, json, os, shutil, sys
from pathlib import Path
DL = Path(r'C:/Users/Miran/Downloads')
BASE = DL / 'Steam-aux-release-20261121-P26z14-px10-base-fix'
mode, OUT = sys.argv[1], DL / sys.argv[2]
CHG = {
    'Addons/41st_Vehicles.pbo': (r'D:/AuxUpdater/blankfix/out/41st_Vehicles.pbo', '67172fc1ca656a0b019c1adce4b6043509fbb7c2aad86426624fbf86fd30a675', 687150340,
        'live P26z14 41st_Vehicles with laatc/config.cpp only replaced (Helicopter: Air declared); D:/AuxUpdater/blankfix/src'),
    'Addons/41st_Weapons.pbo': (r'D:/AuxUpdater/blankfix/out/41st_Weapons.pbo', '7489a05920b2403801b6d65c09cbfebf3a2b03607bea25921266f988f22ae3eb', 19762295,
        'live 41st_Weapons with 5 config.cpp replaced: 773-firepuncher (arifle_MX_Base_F: Rifle_Base_F), dc-15n + dlt15 (Rifle_Base_F: Rifle), dc-15as + sbb3 (4 light attachments: FST_Base_Flashlight, Iteminfo: Iteminfo, Flashlight: Flashlight); D:/AuxUpdater/blankfix/src'),
    'Addons/BUZZ_Vehicles.pbo': (r'D:/AuxUpdater/blankfix/out/BUZZ_Vehicles.pbo', '6347c6564b9fc5ed28a4702dece73202fd76d8cefdb6072d06a89a18c2154db3', 12442558,
        'live BUZZ_Vehicles with atrt/config.cpp only replaced (FST_ATRT_Base ItemInfo: UniformItem); D:/AuxUpdater/blankfix/src'),
    'Addons/FST_Vehicles_Weapons.pbo': (r'D:/AuxUpdater/blankfix/out/FST_Vehicles_Weapons.pbo', 'e5210ad62a37ef98d2a5a68e14cd9c41f94e797dde77d5d23097753bdb458146', 26339,
        'live FST_Vehicles_Weapons with config.bin re-binarized (missiles_titan: MissileLauncher; unmodified round-trip byte-identical); D:/AuxUpdater/blankfix/src'),
}
live = json.loads((BASE / 'publish-result.json').read_text(encoding='utf-8'))
assert live['status'] == 'Published and verified' and live['content_manifest_id'] == '9087755986104411506', live.get('content_manifest_id')
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
man['prepared_at'] = '2026-11-22 Aux Updater (live P26z14 + base-class blank fixes)'
man['publication_status'] = 'staged variant of %s; NOT published' % BASE.name
(OUT / 'RELEASE_MANIFEST.json').write_text(json.dumps(man, indent=2), encoding='utf-8')
shutil.copy2(BASE / 'publish_release.py', OUT / 'publish_release.py')
(OUT / 'workshop-change-note.txt').write_text('''Config fixes

- Weapons: fixed config conflicts on several rifles and the [41st] light attachments so they keep their proper base settings.
- Vehicles: fixed config conflicts on the LAAT cargo, AT-RT and vehicle missiles so they keep their proper base settings.

Let Steam finish the update before joining. Update the server and headless clients, then start a new mission.
''', encoding='utf-8')
print(json.dumps({'out': str(OUT), 'files': man['file_count'], 'bytes': man['total_bytes'], 'changed': man['changed'],
                  'delta_bytes': man['total_bytes'] - live['file_size_bytes']}))
