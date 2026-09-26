"""Tabulate [GULHILL_R3] lines: climb time, reach, re-engage delay, return time, stall %."""
import ast
import re
import sys
from pathlib import Path

rows = []
for rpt in sys.argv[1:]:
    for line in Path(rpt).read_text(encoding='utf-8', errors='replace').splitlines():
        m = re.search(r'"\[GULHILL_R3\] (.*)"\s*$', line)
        if m:
            rows.append(ast.literal_eval(m.group(1).replace('""', '"').replace('&lt;', '<').replace('&gt;', '>')))
print('variant        lane bin cls     t45  reach  jump  re10  return  stallUp stallBack gait  top anims')
agg = {}
for r in rows:
    v, lane, b, cls, t45, reach, jump, re10, ret, su, sb, frac, gait = r
    top = sorted(frac, key=lambda x: -x[1])[:3]
    print('%-14s %3d %3d %-6s %5.1f %6.1f %5.1f %5.1f %6.1f %7d %9d %4d  %s' % (v, lane, b, cls.split('_')[-2][:6], t45, reach, jump, re10, ret, su, sb, gait,
          ' '.join('%s:%d' % (a.replace('form939_', '').replace('burns_gulanthar_', 'B'), n) for a, n in top)))
    a = agg.setdefault((v, 'up' if b >= 18 else 'flat'), {'t45': [], 'miss': 0, 're10': [], 'ret': [], 'noreturn': 0})
    if t45 >= 0: a['t45'].append(t45)
    else: a['miss'] += 1
    if re10 >= 0: a['re10'].append(re10)
    if ret >= 0: a['ret'].append(ret)
    elif jump >= 0: a['noreturn'] += 1
print()
print('summary: variant/terrain  lanes-reaching-45m  median t45  median re-engage(10m)  median return  no-return')
med = lambda xs: sorted(xs)[len(xs) // 2] if xs else -1
for (v, terr), a in sorted(agg.items()):
    n = len(a['t45']) + a['miss']
    print('  %-14s %-4s  %d/%d  %5.1f  %5.1f  %5.1f  %d' % (v, terr, len(a['t45']), n, med(a['t45']), med(a['re10']), med(a['ret']), a['noreturn']))
