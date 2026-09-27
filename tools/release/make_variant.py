"""Build a hard-linked variant of a staged Aux release with some terrain PBOs swapped in.

usage: python make_variant.py --base=DIR --out=DIR [--note=TEXT ...] PATH=SHA256=BYTES [...]

Every file of BASE's payload is hard-linked into OUT (same volume, nothing copied). The
given PBOs are then checked and staged by terrain_checks/stage_terrain.py --stage, which
unlinks only OUT's name before copying the new file in, so BASE is never touched. Each
--note becomes a bullet in OUT's change note. Run OUT's publish_release.py --check next.
"""
import json
import os
import shutil
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent


def arg(name):
    return [a.split('=', 1)[1] for a in sys.argv[1:] if a.startswith('--' + name + '=')]


base, out = Path(arg('base')[0]), Path(arg('out')[0])
notes = arg('note')
items = [a for a in sys.argv[1:] if not a.startswith('--')]
if not items:
    sys.exit('nothing to swap in')
if out.exists():
    sys.exit('refusing: %s already exists' % out)

man = json.loads((base / 'RELEASE_MANIFEST.json').read_text(encoding='utf-8'))
for e in man['files']:
    src = base / '@41st_Kaid_Aux_Release' / e['file']
    if src.stat().st_size != e['bytes']:
        sys.exit('base file differs from its manifest: ' + e['file'])
    dst = out / '@41st_Kaid_Aux_Release' / e['file']
    dst.parent.mkdir(parents=True, exist_ok=True)
    os.link(src, dst)
man['publication_status'] = 'staged variant of %s; NOT published' % base.name
(out / 'RELEASE_MANIFEST.json').write_text(json.dumps(man, indent=2), encoding='utf-8')
for f in ('publish_release.py', 'workshop-change-note.txt'):
    shutil.copy2(base / f, out / f)
if notes:
    note = out / 'workshop-change-note.txt'
    lines = note.read_text(encoding='utf-8').splitlines()
    last = max(i for i, l in enumerate(lines) if l.startswith('- '))
    lines[last + 1:last + 1] = ['- ' + n for n in notes]
    note.write_text('\n'.join(lines) + '\n', encoding='utf-8')

r = subprocess.run([sys.executable, 'stage_terrain.py', '--release=' + str(out), '--stage'] + items,
                   cwd=str(HERE / 'terrain_checks'))
if r.returncode:
    sys.exit('stage_terrain refused the swap; %s holds only the unmodified base links' % out)
man = json.loads((out / 'RELEASE_MANIFEST.json').read_text(encoding='utf-8'))
print('VARIANT READY: %s | %d files, %d bytes | added %s | changed %s'
      % (out, man['file_count'], man['total_bytes'], man['added'], man['changed']))
