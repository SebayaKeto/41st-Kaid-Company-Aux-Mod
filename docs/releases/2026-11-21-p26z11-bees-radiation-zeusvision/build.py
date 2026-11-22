r"""P26z11 build (21 Nov): live P26z10 PBOs + Bees 6eb56a2d..91ac025d. 41st_KitMenu / 41st_Music: rebuild.py (live==parent for every changed entry).
41st_Armor: rebuild.py then config.cpp = git merge-file(live, parent, head) (live keeps the P26z2/z6 helmet-name fixes). New PBOs BUZZ_Radiation,
BUZZ_ZeusVision packed from repo HEAD (prefix from $PBOPREFIX$, uncompressed, config.cpp as text). usage: build.py"""
import hashlib, json, subprocess, sys, struct
from pathlib import Path
sys.path.insert(0, r'D:/AuxUpdater/gulfix'); import replace_entries as r
PY = r'D:/UmbaraTerrain/.venv/Scripts/python.exe'
REPO = Path(r'C:/Users/Miran/OneDrive/Documents/GitHub/41st-Kaid-Company-Aux-Mod/41st-Kaid-Company-Aux-Mod')
SRC = REPO / 'PUBLISHED MODPACK'
LIVE = Path(r'C:/Users/Miran/Downloads/Steam-aux-release-20261119-P26z10-thirra9c/@41st_Kaid_Aux_Release/Addons')
W = Path(r'D:/AuxUpdater/p26z11'); OUT = W / 'out'; OUT.mkdir(exist_ok=True)
head = subprocess.run(['git', '-C', str(REPO), 'rev-parse', '--short=8', 'HEAD'], capture_output=True, text=True).stdout.strip()
assert head == '91ac025d', head
res = {}
for ad in ('41st_KitMenu', '41st_Music', '41st_Armor'):
    o = subprocess.run([PY, r'D:/AuxUpdater/p26h/rebuild.py', str(LIVE / (ad + '.pbo')), str(OUT / (ad + '.pbo')), 'PUBLISHED MODPACK/' + ad, '6eb56a2d'],
                       capture_output=True, text=True); assert o.returncode == 0, o.stderr; res[ad] = json.loads(o.stdout.strip().splitlines()[-1])
# Armor config.cpp = merged (CRLF if live used CRLF)
data = (OUT / '41st_Armor.pbo').read_bytes(); props, ents, hv = r.parse(data)
livep, livee, _ = r.parse((LIVE / '41st_Armor.pbo').read_bytes())
lc = next(e for e in livee if e[0].lower() == b'config.cpp')[2]
m = (W / 'merge' / 'merged.cpp').read_bytes()
if b'\r\n' in lc: m = m.replace(b'\n', b'\r\n')
e = next(e for e in ents if e[0].lower() == b'config.cpp'); e[2] = m; e[1][1] = len(m); e[1][4] = len(m)
blob = r.build(props, ents, hv); (OUT / '41st_Armor.pbo').write_bytes(blob); r.parse(blob)
res['41st_Armor']['config'] = 'merged live+parent+head, crlf=%s' % (b'\r\n' in lc); res['41st_Armor']['sha256'] = hashlib.sha256(blob).hexdigest(); res['41st_Armor']['bytes'] = len(blob)
def pack(ad):
    d = SRC / ad; prefix = (d / '$PBOPREFIX$').read_text().strip()
    files = sorted((p for p in d.rglob('*') if p.is_file() and p.name != '$PBOPREFIX$'), key=lambda p: str(p.relative_to(d)).lower())
    hdr = b'\0' + b'sreV' + b'\0' * 16 + b'prefix\0' + prefix.encode() + b'\0\0'; body = b''
    for p in files:
        b = p.read_bytes(); assert not b.startswith(b'version https://git-lfs'), p
        hdr += str(p.relative_to(d)).replace('/', chr(92)).encode() + b'\0' + struct.pack('<5I', 0, len(b), 0, int(p.stat().st_mtime), len(b)); body += b
    blob = hdr + b'\0' + b'\0' * 20 + body; blob += b'\0' + hashlib.sha1(blob).digest()
    (OUT / (ad + '.pbo')).write_bytes(blob); r.parse(blob)
    return {'out': str(OUT / (ad + '.pbo')), 'prefix': prefix, 'entries': len(files), 'bytes': len(blob), 'sha256': hashlib.sha256(blob).hexdigest()}
for ad in ('BUZZ_Radiation', 'BUZZ_ZeusVision'): res[ad] = pack(ad)
(W / 'build_report.json').write_text(json.dumps(res, indent=1)); print(json.dumps(res, indent=1))
