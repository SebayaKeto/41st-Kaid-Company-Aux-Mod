r"""P26z22 (Halloween) RELEASE STAGING (24 Nov 2026; Omnibus request relaying Miran's rulings "Yes, Fix 1" (WBK Leaper fix) and the
overnight click-fix work) = live P26z20 (ManifestID 6235468048858355231)
+ click-fix candidate 3 (tested 23 Nov 14:00, exact live 75 proof 24 Nov 01:38): 15 KAID compat PBOs + Aux-own warning fixes in
  41st_Weapons / 41st_Ammo / 41st_Vehicles (same parts as aatcrew/make_clickfix_candidate3.py)
+ candidate 4 WBK Leaper shadow-texture compats (clickfix/wbk_leaper_24nov/out; engine proof f1_1255: 0 "Cannot load texture")
+ Zenoc Halloween terrain w14m fst_zenoc_halloween.pbo 2becbd80 (Zenoc left the Aux 23 Oct; this adds it back).
P26z21's Pole face fix IS included (Miran 24 Nov: "Add Pole face first"). Publish ONLY on Miran's own typed go naming P26z22; publish_release.py --check only until then.
usage: make_p26z22.py OUT_NAME"""
import hashlib, json, os, shutil, sys
from pathlib import Path
DL = Path(r'C:/Users/Miran/Downloads')
BASE = DL / 'Steam-aux-release-20261122-P26z20-daara-stopfix'
CF = Path(r'D:/AuxUpdater/clickfix')
OUT = DL / sys.argv[1]
live = json.loads((BASE / 'publish-result.json').read_text(encoding='utf-8'))
assert live['status'] == 'Published and verified' and live['content_manifest_id'] == '6235468048858355231'
man = json.loads((BASE / 'RELEASE_MANIFEST.json').read_text(encoding='utf-8'))
assert man['file_count'] == live['file_count'] == 101 and man['total_bytes'] == live['file_size_bytes']
build = json.loads((CF / 'out' / 'clickfix_build.json').read_text(encoding='utf-8'))
ORIGIN = {
    '41st_Weapons': 'Aux-own warning fix: dropped attachment names no mod defines (3AS_optic_holo_DC15S, FST_Knife, 41st_bayonet) from compatibleItems in DC-15AS, DC17, SPA-K12, Westar, Z6',
    '41st_Ammo': 'Aux-own warning fix: FST_smoke_Impact SoundSetExplosion {""} -> {}',
    '41st_Vehicles': 'Aux-own warning fix: FST_Heavy_laser_Cannon scope=1 (vehicle cannon had no scope)',
}
CHG = {'Addons/%s.pbo' % k: (CF / 'out' / ('%s.pbo' % k), v['new_sha256'], v['new_bytes'], ORIGIN[k]) for k, v in build['aux'].items()}
assert len(CHG) == 3
# Miran 24 Nov (typed here): "Add Pole face first" -> P26z21's only change rides in P26z22.
CHG['Addons/41st_Armor.pbo'] = (Path(r'D:/AuxUpdater/armor21/41st_Armor.pbo'),
    '69189af4c9decbdf53f882ff48871bce2a43e938fb2688fac836e663014f9f02', 2308166818,
    'live P26z20 41st_Armor (47ee62dc) + House 0ccaa04e Fixed Pole Face: only Data/Faces/FST_Clone_Pole.paa replaced (D:/AuxUpdater/armor21/make_armor21.py; was staged alone as P26z21)')
ADD = {'Addons/%s.pbo' % k: (CF / 'out' / ('%s.pbo' % k), v['pbo_sha256'], v['pbo_bytes'],
       'click-fix compat (Omnibus compat_src 23 Nov, research/unattended_boot_fix_20261123): ' + k) for k, v in build['compats'].items()}
for sub, note in (('out2', 'click-fix compat (rocket-box agent 23 Nov, compat_src folder 13; delete + re-add DBA rocket sound entries as arrays): '),
                  ('out3', 'click-fix optics compat (Aux Updater 23 Nov, clickfix/src3; vanilla optics values): ')):
    b = json.loads((CF / sub / ('clickfix%s_build.json' % sub[-1])).read_text(encoding='utf-8'))
    for k, v in b['compats'].items():
        ADD['Addons/%s.pbo' % k] = (CF / sub / ('%s.pbo' % k), v['pbo_sha256'], v['pbo_bytes'], note + k)
assert len(ADD) == 15
LP = CF / 'wbk_leaper_24nov' / 'out'
ADD['Addons/KAID_WBK_Leaper1ShadowTex_Compat.pbo'] = (LP / 'KAID_WBK_Leaper1ShadowTex_Compat.pbo',
    '18fece6f6895d426868b719909fcb21c177ce3c273fb8ea40e349540e2a9e7e1', 2191811,
    'WBK Leaper fix 24 Nov: supplies zombie3\\addons\\data\\wd_cripple_01_d.paa (byte copy of WBK special_Infected\\textures\\leaper_1_CO.paa; credit WebKnight / Big Red)')
ADD['Addons/KAID_WBK_Leaper2ShadowTex_Compat.pbo'] = (LP / 'KAID_WBK_Leaper2ShadowTex_Compat.pbo',
    'ecce59d0a4bf99007e1320036c7819fa972670dc3e60cba627e1f23fa32468a7', 2155957,
    'WBK Leaper fix 24 Nov: supplies zombiebh\\addons\\data\\wd_cripple_02_d.paa (byte copy of WBK special_Infected\\textures\\leaper_2_CO.paa; credit WebKnight / Big Red)')
ADD['Addons/fst_zenoc_halloween.pbo'] = (Path(r'C:/Halloween_rt/terrain/output_w14m_floorgap_rebuilt/@FST_ZenocHalloween/addons/fst_zenoc_halloween.pbo'),
    '2becbd80ece01c7dee2f8ab191d163e276071326949f7f13af0d87d63a2659dc', 216835341,
    'Zenoc Halloween terrain w14m (w14l + hall-floor z-fight fix; D:/Halloween/OP_READY_WED25NOV.md, delivery DLV4); needs Cytech Core Assets 2764686098 loaded separately')
assert len(ADD) == 18
names = {e['file'].lower() for e in man['files']}
assert all(k.lower() in names for k in CHG) and not any(k.lower() in names for k in ADD)
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
for f, (src, h, size, origin) in ADD.items():
    dst = A / f; shutil.copy2(src, dst); assert sha(dst) == h and dst.stat().st_size == size, f
    man['files'].append({'file': f, 'bytes': size, 'sha256': h, 'origin': origin})
man['base_release'] = BASE.name; man['base_time_updated'] = live['time_updated']; man['base_file_size'] = live['file_size_bytes']
man['base_content_manifest_id'] = live['content_manifest_id']
man['added'] = sorted(ADD); man['changed'] = sorted(CHG); man['removed'] = []
man['file_count'] = len(man['files']); man['total_bytes'] = sum(e['bytes'] for e in man['files'])
man['prepared_at'] = '2026-11-24 Aux Updater (P26z22 Halloween: live P26z20 + click-fix cand3 + WBK Leaper fix + Zenoc terrain w14m + Pole face fix)'
man['publication_status'] = 'staged variant of %s; NOT published' % BASE.name
(OUT / 'RELEASE_MANIFEST.json').write_text(json.dumps(man, indent=2), encoding='utf-8')
shutil.copy2(BASE / 'publish_release.py', OUT / 'publish_release.py')
(OUT / 'workshop-change-note.txt').write_text('''Halloween update

- Added: the Zenoc Halloween map for Wednesday's op (needs [CYTECH] Core Assets And Functions loaded).
- Fixed: the error boxes on game launch (DBA, ACE Extension, OPTRE, IDA, LS, 3AS).
- Fixed: the error boxes after a mission starts (helicopters, tank and static gun sights, Leaper zombies).
- Fixed: missing attachment errors on the DC-15A, DC-17, SPA-K12, Westar and Z6.
- Fixed: the Pole face.
- Updated: tank passenger seats work on more vehicles.

Let Steam finish the update before joining. Update the server and headless clients, then start a new mission.
''', encoding='utf-8')
print(json.dumps({'out': str(OUT), 'files': man['file_count'], 'bytes': man['total_bytes'], 'added': len(ADD), 'changed': man['changed'],
                  'delta_bytes': man['total_bytes'] - live['file_size_bytes']}))
