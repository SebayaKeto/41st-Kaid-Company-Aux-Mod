"""Summarize GulHill RPT: per variant/lane timelines of anim, speed, progress, command, mode."""
import ast
import re
import sys
from pathlib import Path

rpt = Path(sys.argv[1])
want_lanes = {int(x) for x in sys.argv[2].split(',')} if len(sys.argv) > 2 and sys.argv[2] else None
samples, results, lanes = {}, [], {}
for line in rpt.read_text(encoding='utf-8', errors='replace').splitlines():
    m = re.search(r'"\[(GULHILL_SAMPLE|GULHILL_RESULT|GULHILL_LANE)\] (.*)"\s*$', line)
    if not m:
        continue
    kind, body = m.groups()
    body = body.replace('""', '"').replace('&lt;', '<').replace('&gt;', '>').replace('true', 'True').replace('false', 'False')
    try:
        val = ast.literal_eval(body)
    except Exception:
        continue
    if kind == 'GULHILL_SAMPLE':
        variant, lane, t, anim, spd, prog, inc, dist, cmd, mode = val
        samples.setdefault((variant, lane), []).append((t, anim, spd, prog, inc, dist, cmd, mode))
    elif kind == 'GULHILL_RESULT':
        results.append(val)
    else:
        lanes[val[0]] = val

short = {'form939_idle': 'idle', 'form939_idle2': 'idle', 'form939_idle3': 'idle', 'form939_walk': 'WALK', 'form939_sprint': 'SPR',
         'burns_gulanthar_run': 'BRUN', 'burns_gulanthar_climb': 'CLMB', 'fsttest_gallop_run': 'GAL', 'fsttest_gallop_fast': 'GALF',
         'fsttest_flat_run': 'FRUN', 'form939_attack4': 'atk', 'form939_attack6': 'atk'}
print('lane  bin  class')
for k, v in sorted(lanes.items()):
    print('%4d %4s  %s' % (k, v[1], ''))
for (variant, lane), rows in sorted(samples.items(), key=lambda x: (x[0][0], x[0][1])):
    if want_lanes and lane not in want_lanes:
        continue
    parts = []
    for t, anim, spd, prog, inc, dist, cmd, mode in rows[::2]:
        parts.append('%d:%s/%d/%dm/%s%s' % (round(t), short.get(anim, anim[:6]), round(spd), round(prog), (cmd or '-')[:4], mode))
    print('%-12s lane %d: %s' % (variant, lane, ' '.join(parts)))
print()
print('variant       lane bin class       t50   p10 p20 p30 minD spd inc gaitEntries')
for r in results:
    variant, lane, b, cls, t50, p10, p20, p30, minD, spd, inc, frac, entries, rec = r
    print('%-12s %4d %3d %-10s %5.1f %4d %3d %3d %4d %3d %3d %3d' % (variant, lane, b, cls.split('_')[-2], t50, p10, p20, p30, minD, spd, inc, entries))
