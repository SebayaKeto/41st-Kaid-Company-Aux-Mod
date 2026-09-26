"""Index CfgPatches (and CfgWorlds) across PBOs without launching Arma.

Reads each PBO header, pulls root/sub config.bin (rapified) or config.cpp entries,
and extracts CfgPatches class names with their requiredAddons, plus CfgWorlds
class names. Used to check a new addon's dependencies and name collisions.
"""
import io
import json
import re
import struct
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(REPO / 'tools' / 'meap'))
import pbo_tools as pbo  # noqa: E402


def asciiz(b, pos):
    end = b.index(b'\0', pos)
    return b[pos:end].decode('latin1'), end + 1


def cint(b, pos):
    val = shift = 0
    while True:
        byte = b[pos]
        pos += 1
        val |= (byte & 0x7F) << shift
        if not byte & 0x80:
            return val, pos
        shift += 7


def read_array(b, pos):
    n, pos = cint(b, pos)
    out = []
    for _ in range(n):
        t = b[pos]
        pos += 1
        if t == 0 or t == 4:
            s, pos = asciiz(b, pos)
            out.append(s)
        elif t == 1:
            out.append(struct.unpack_from('<f', b, pos)[0])
            pos += 4
        elif t == 2:
            out.append(struct.unpack_from('<i', b, pos)[0])
            pos += 4
        elif t == 3:
            sub, pos = read_array(b, pos)
            out.append(sub)
        elif t == 6:
            out.append(struct.unpack_from('<q', b, pos)[0])
            pos += 8
        else:
            raise ValueError('array element type %d' % t)
    return out, pos


def read_body(b, pos):
    """Return (inherits, entries) where entries are (kind, name, payload)."""
    inherits, pos = asciiz(b, pos)
    n, pos = cint(b, pos)
    entries = []
    for _ in range(n):
        t = b[pos]
        pos += 1
        if t == 0:
            name, pos = asciiz(b, pos)
            off = struct.unpack_from('<I', b, pos)[0]
            pos += 4
            entries.append(('class', name, off))
        elif t == 1:
            sub = b[pos]
            pos += 1
            name, pos = asciiz(b, pos)
            if sub in (0, 4):
                val, pos = asciiz(b, pos)
            elif sub in (1, 2):
                val = b[pos:pos + 4]
                pos += 4
            elif sub == 6:
                val = b[pos:pos + 8]
                pos += 8
            else:
                raise ValueError('value subtype %d' % sub)
            entries.append(('value', name, val))
        elif t == 2:
            name, pos = asciiz(b, pos)
            arr, pos = read_array(b, pos)
            entries.append(('array', name, arr))
        elif t in (3, 4):
            name, pos = asciiz(b, pos)
            entries.append(('extern' if t == 3 else 'delete', name, None))
        elif t == 5:
            pos += 4
            name, pos = asciiz(b, pos)
            arr, pos = read_array(b, pos)
            entries.append(('array+', name, arr))
        else:
            raise ValueError('entry type %d' % t)
    return inherits, entries


def rap_summary(b):
    if not b.startswith(b'\0raP'):
        raise ValueError('not rapified')
    _, root = read_body(b, 16)
    patches, worlds = {}, []
    for kind, name, off in root:
        if kind != 'class':
            continue
        if name.lower() == 'cfgpatches':
            _, children = read_body(b, off)
            for ck, cname, coff in children:
                if ck != 'class':
                    continue
                _, props = read_body(b, coff)
                req = next((p for k, n, p in props if k.startswith('array') and n.lower() == 'requiredaddons'), [])
                patches[cname] = [x for x in req if isinstance(x, str)]
        elif name.lower() == 'cfgworlds':
            _, children = read_body(b, off)
            worlds += [cname for ck, cname, _ in children if ck == 'class']
    return patches, worlds


CPP_PATCH = re.compile(r'class\s+CfgPatches\s*\{(.*?)\n\s*\};', re.S | re.I)


def cpp_summary(text):
    patches = {}
    m = CPP_PATCH.search(text)
    if m:
        for cm in re.finditer(r'class\s+(\w+)\s*(?::\s*\w+)?\s*\{(.*?)\}\s*;', m.group(1), re.S):
            req = re.search(r'requiredAddons\s*\[\]\s*\+?=\s*\{(.*?)\}', cm.group(2), re.S | re.I)
            patches[cm.group(1)] = re.findall(r'"([^"]+)"', req.group(1)) if req else []
    worlds = []
    wm = re.search(r'class\s+CfgWorlds\s*\{', text, re.I)
    if wm:
        worlds = re.findall(r'^\s*class\s+(\w+)\s*:\s*\w+', text[wm.end():wm.end() + 20000], re.M)[:5]
    return patches, worlds


def summarize_pbo(path):
    rows, props = pbo.index(path)
    result = {'prefix': props.get('prefix', ''), 'patches': {}, 'worlds': [], 'errors': []}
    for key, row in rows.items():
        leaf = key.rsplit('/', 1)[-1]
        if leaf not in ('config.bin', 'config.cpp') or row['header'][0] != 0:
            continue
        if leaf == 'config.cpp' and key.replace('config.cpp', 'config.bin') in rows:
            continue  # engine prefers .cpp, but the .bin carries the same classes here
        try:
            data = pbo.read(path, key)
            if data.startswith(b'\0raP'):
                patches, worlds = rap_summary(data)
            else:
                patches, worlds = cpp_summary(data.decode('utf-8', 'replace'))
            for n, r in patches.items():
                result['patches'][n] = r
            result['worlds'] += worlds
        except Exception as exc:  # keep going; report per entry
            result['errors'].append('%s: %s' % (key, exc))
    return result


if __name__ == '__main__':
    targets = [Path(a) for a in sys.argv[1:]]
    report = {}
    for folder in targets:
        for pbo_path in sorted(folder.glob('*.pbo')):
            try:
                report[str(pbo_path)] = summarize_pbo(pbo_path)
            except Exception as exc:
                report[str(pbo_path)] = {'fatal': str(exc)}
    json.dump(report, sys.stdout, indent=1)
