"""Class-level collision check for terrain PBOs (clone safety).

For selected root classes, lists the child classes a PBO *defines* (with a body;
extern declarations are ignored) and reports names that another PBO in the op
modset or the staged Aux also defines. Two terrains defining the same surface,
clutter, function or vehicle class means the later-loaded one silently wins.

usage: python check_classes.py NEW.pbo [NEW2.pbo ...]
"""
import json
import struct
import sys
from pathlib import Path

HERE = Path(__file__).parent
sys.path.insert(0, str(HERE))
import rap_index  # noqa: E402
from rap_index import asciiz, cint, read_body  # noqa: E402
import pbo_tools as pbo  # noqa: E402

ROOTS = ['cfgsurfaces', 'cfgsurfacecharacters', 'cfgworlds', 'cfgworldlist', 'cfgfunctions', 'cfgvehicles',
         'cfgnonaivehicles', 'cfglocationtypes', 'cfgmarkers', 'cfgenvsounds', 'cfgsfx', 'cfgsounds',
         'cfgmusic', 'cfgcloudlets', 'cfglights', 'cfgvehicleclasses', 'cfgeditorcategories',
         'cfgeditorsubcategories', 'cfgfactionclasses']
# Base classes every terrain re-opens to add members; sharing them is normal.
SHARED_OK = {'defaultworld', 'caworld', 'defaultclutter', 'default', 'grid', 'weather', 'overcast', 'lighting',
             'defaultlighting', 'simulweather', 'eden', 'static', 'house', 'house_f', 'nonstrategic', 'building',
             'thing', 'rocks_base_f', 'land_rock_f', 'allvehicles', 'all', 'strategic', 'bis_fnc_sidecolor'}
STAGED = Path('.') / '@41st_Kaid_Aux_Release' / 'Addons'  # standalone use: run from a staging folder
AUX = '@41st Elite Corps Kaid Co Aux Mod'


def defined_children(data):
    """{root: set(child names defined with a body)} for rapified or text config."""
    out = {}
    if data.startswith(b'\0raP'):
        _, root = read_body(data, 16)
        for kind, name, off in root:
            if kind == 'class' and name.lower() in ROOTS:
                _, children = read_body(data, off)
                out.setdefault(name.lower(), set()).update(n for k, n, _ in children if k == 'class')
    return out


def pbo_classes(path):
    rows, _ = pbo.index(path)
    result = {}
    for key, row in rows.items():
        if key.rsplit('/', 1)[-1] != 'config.bin' or row['header'][0] != 0:
            continue
        try:
            for root, names in defined_children(pbo.read(path, key)).items():
                result.setdefault(root, set()).update(names)
        except Exception:
            pass
    return result


def main(new_paths):
    mods = [Path(line.strip().lstrip('\ufeff')) for line in (HERE / 'client-modlist.txt').read_text(encoding='utf-8').splitlines() if line.strip()]
    sources = [(m.name, m / 'addons') for m in mods if m.name != AUX] + [('staged Aux', STAGED)]
    index = {}
    new_names = {Path(p).name.lower() for p in new_paths}
    for label, folder in sources:
        for pbo_path in folder.glob('*.pbo'):
            if pbo_path.name.lower() in new_names:
                continue
            for root, names in pbo_classes(pbo_path).items():
                for n in names:
                    index.setdefault((root, n.lower()), []).append('%s | %s' % (label, pbo_path.name))
    report = {}
    for p in new_paths:
        mine = pbo_classes(Path(p))
        hits = {}
        for root, names in mine.items():
            for n in sorted(names):
                if n.lower() in SHARED_OK:
                    continue
                others = index.get((root, n.lower()))
                if others:
                    hits.setdefault(root, {})[n] = sorted(set(others))[:6]
        report[Path(p).name] = {'defined': {r: len(v) for r, v in mine.items()}, 'collisions': hits}
    print(json.dumps(report, indent=1))


if __name__ == '__main__':
    main(sys.argv[1:])
