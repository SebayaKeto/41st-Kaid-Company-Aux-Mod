import re,glob,json,os
rows={}
for run in ('x1','x3','x6'):
    R=glob.glob(r'D:/AuxUpdater/xehcompat/prof-%s/*.rpt'%run)[0]
    for l in open(R,encoding='latin1'):
        if 'XEHP|root|' not in l: continue
        m=re.search(r'\|owner=([^|]*)\|ownerParent=([^|]*)\|ownerSrc=(\[[^|]*\])\|example',l)
        rows[m.group(1)]=(m.group(1),m.group(2),json.loads(m.group(3).replace('""','"')))
rows=list(rows.values()); print(len(rows))
ours=lambda s: any(re.match(r'(?i)(FST|41st|BUZZ|JMSEF|KAID|MEAP)',a) and not re.match(r'(?i)41st_ODST',a) for a in s)
groups={'41st':[r for r in rows if ours(r[2])],'3P':[r for r in rows if not ours(r[2])]}
for g,rs in groups.items():
    owners={r[0] for r in rs}; byname={r[0]:r for r in rs}; done=[]; seen=set()
    def visit(n):
        if n in seen: return
        seen.add(n); p=byname[n][1]
        if p in byname: visit(p)
        done.append(byname[n])
    for r in sorted(rs): visit(r[0])
    req=sorted({a for r in rs for a in r[2]}|{'cba_xeh'})
    ext=sorted({r[1] for r in rs if r[1] not in owners})
    name='KAID_XEH_Compat_'+g
    out=['// %s: adds CBA Extended Event Handler support to %d unit/static classes whose own'%(name,len(rs)),
         '// "class EventHandlers {...}" has no CBA_Extended_EventHandlers subclass. Without it CBA logs',
         '// "Fall back to loop" and polls every unit on every machine. Generated from an engine probe',
         '// (D:/AuxUpdater/xehcompat); each class keeps its exact parent, so no base class changes.',
         'class CfgPatches','{','\tclass %s'%name,'\t{','\t\tname = "KAID XEH compat (%s)";'%g,'\t\tauthor = "41st Aux Updater";',
         '\t\tunits[] = {};','\t\tweapons[] = {};','\t\trequiredVersion = 2.0;',
         '\t\trequiredAddons[] = {%s};'%', '.join('"%s"'%a for a in req),'\t\tskipWhenMissingDependencies = 1;','\t};','};',
         'class CBA_Extended_EventHandlers_base;','class CfgVehicles','{']
    out+=['\tclass %s;'%p for p in ext]
    for o,p,s in done:
        out+=['\tclass %s: %s'%(o,p),'\t{','\t\tclass EventHandlers','\t\t{','\t\t\tclass CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};','\t\t};','\t};']
    out+=['};','']
    d=r'D:/AuxUpdater/xehcompat/gen/%s'%name; os.makedirs(d,exist_ok=True)
    open(d+'/config.cpp','w',newline='\r\n').write('\n'.join(out))
    print(g,len(rs),'classes; requiredAddons',req)
