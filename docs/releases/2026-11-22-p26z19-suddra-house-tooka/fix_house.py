"""Release-copy fixes to House's be6b0fe8 units (merged.cpp -> release_config.cpp), CRLF kept:
- FST_P2_Ordo_Dirty linkedItems "FST_AB_Helmet_Ordo_Dirty" (undefined) -> "FST_Airborne_Helmet_Ordo_Dirty" (same slip live fixed on 16 helmets)
- FST_P2_Overwatch_Dirty linkedItems "FST_P2_Helmet_Overwatch_Dirty" (undefined) -> "FST_Crewman_Helmet_Mk2_Overwatch_Dirty" (House's new dirty Overwatch helmet)
- FST_P2_Comedian_Dirty / Overwatch_Dirty / Red_Dirty uniformclass clean -> the _Dirty uniform House also added (Ordo/Rick/Pole dirty already do this)
Every edit is confined to that unit's class body and counted."""
import re
W = r'D:/AuxUpdater/armor19'
s = open(W + '/merged.cpp', 'rb').read().decode('latin1')

def unit_span(name):
    m = re.search(r'\n\tclass ' + name + r'\s*:[^\n]*\r?\n\t\{', s); assert m, name
    i = m.end(); d = 1
    while d: d += (s[i] == '{') - (s[i] == '}'); i += 1
    return m.start(), i

def sub_in(name, old, new, count):
    global s
    a, b = unit_span(name); body = s[a:b]
    assert body.count(old) == count, (name, old, body.count(old))
    s = s[:a] + body.replace(old, new) + s[b:]

sub_in('FST_P2_Ordo_Dirty', '"FST_AB_Helmet_Ordo_Dirty"', '"FST_Airborne_Helmet_Ordo_Dirty"', 2)
sub_in('FST_P2_Overwatch_Dirty', '"FST_P2_Helmet_Overwatch_Dirty"', '"FST_Crewman_Helmet_Mk2_Overwatch_Dirty"', 2)
for u in ('Comedian', 'Overwatch', 'Red'):
    sub_in('FST_P2_%s_Dirty' % u, 'uniformclass="FST_Uniform_%s";' % u, 'uniformclass="FST_Uniform_%s_Dirty";' % u, 1)
for c in ('FST_Airborne_Helmet_Ordo_Dirty', 'FST_Crewman_Helmet_Mk2_Overwatch_Dirty', 'FST_Uniform_Comedian_Dirty', 'FST_Uniform_Overwatch_Dirty', 'FST_Uniform_Red_Dirty'):
    assert re.search(r'\n\s*class ' + c + r'\s*:', s), c
open(W + '/release_config.cpp', 'wb').write(s.encode('latin1'))
print('ok')
