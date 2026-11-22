"""Sweep a PBO's text configs for parentless redeclares: `class X { ... }` (body, no ':') where X (same nesting path) is declared
WITH a parent in some config (this PBO's configs, or an RPT's update lines). Each hit can blank X's parent if it loads after the
owner. Prints path -> files declaring it parentless / with parent. usage: sweep.py PBO [RPT ...]"""
import re, sys, collections
sys.path.insert(0, r'D:\AuxUpdater\gulfix'); import replace_entries as r
from pathlib import Path
pbo = Path(sys.argv[1]); BS = chr(92)
_, entries, _ = r.parse(pbo.read_bytes())
cfgs = {e[0].decode('latin1').replace(BS, '/'): e[2].decode('utf-8', 'replace') for e in entries if e[0].lower().endswith(b'config.cpp')}
tok = re.compile(r'//[^\n]*|/\*.*?\*/|"(?:[^"]|"")*"|\bclass\s+(\w+)\s*(?::\s*(\w+))?\s*([{;])|[{}]', re.S)
noparent = collections.defaultdict(set); withparent = collections.defaultdict(set)
for f, s in cfgs.items():
    stack = []  # (name or None)
    for m in tok.finditer(s):
        t = m.group(0)
        if t.startswith(('//', '/*', '"')): continue
        if m.group(1):
            name, parent, end = m.group(1), m.group(2), m.group(3)
            path = '/'.join(x for x in stack if x) + '/' + name
            key = path.lower()
            if end == '{':
                (withparent if parent else noparent)[key].add(f)
                stack.append(name)
            elif parent:
                withparent[key].add(f)
        elif t == '{': stack.append(None)
        elif t == '}':
            if stack: stack.pop()
rpt_parent = collections.defaultdict(set)
rx = re.compile(r"Updating base class '([^']*)'->'([^']*)', by '[^']*?config\.(?:cpp|bin)/([^']*)/'")
for rp in sys.argv[2:]:
    for line in open(rp, encoding='utf-8', errors='replace'):
        m = rx.search(line)
        if m:
            for v in (m[1], m[2]):
                if v: rpt_parent[m[3].lower()].add(v)
hits = []
for key, fs in sorted(noparent.items()):
    if not key.startswith(('cfgweapons/', 'cfgvehicles/', 'cfgmagazines/', 'cfgammo/')): continue
    if key in withparent or key in rpt_parent:
        hits.append((key, sorted(fs), sorted(withparent.get(key, ())), sorted(rpt_parent.get(key, ()))))
for key, fs, wp, rp in hits:
    print(f'{key}\n   parentless in: {fs}\n   with parent in: {wp}  rpt parents: {rp}')
print(len(hits), 'paths;', len({f for _, fs, _, _ in hits for f in fs}), 'files')
