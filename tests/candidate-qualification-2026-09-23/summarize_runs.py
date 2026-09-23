from pathlib import Path
import re,json,hashlib
root=Path(__file__).resolve().parent.parent
out=root/'outputs/testing'
runs={}
for directory in sorted((out/'runs').glob('run*')):
    result={'checks':[],'completion':[],'scriptErrors':[],'movementGraphErrors':[],'logs':[]}
    for p in sorted(directory.rglob('*.rpt')):
        result['logs'].append({'file':str(p.relative_to(out)),'sha256':hashlib.sha256(p.read_bytes()).hexdigest()})
        for line in p.read_text(errors='replace').splitlines():
            if '[QUAL_CHECK]' in line:
                m=re.search(r'\[QUAL_CHECK\] \[""(.*?)"",(true|false),(.*)',line)
                if m: result['checks'].append({'name':m[1],'passed':m[2]=='true','detail':m[3][:600],'time':line.split('"')[0].strip()})
            if any(x in line for x in ['[QUAL_DONE]','[QUAL_GUARDS_DONE]','[QUAL_EXTENDED_DONE]','[QUAL_FOLLOWUP_DONE]','[QUAL_EDGES_DONE]']):result['completion'].append(line[:2000])
            if any(x in line for x in ['Error in expression','Error position:','Error Undefined']):result['scriptErrors'].append(line[:800])
            if 'CfgMovesBURNSGulanthar' in line and any(x in line for x in ['Bad move','No entry']):result['movementGraphErrors'].append(line)
    result['passed']=sum(c['passed'] for c in result['checks'])
    result['failed']=[c['name'] for c in result['checks'] if not c['passed']]
    runs[directory.name]=result
(out/'runtime-results.json').write_text(json.dumps(runs,indent=2))
for name,r in runs.items():print(name,'pass',r['passed'],'fail',len(r['failed']),'scriptErrors',len(r['scriptErrors']),'completed',len(r['completion']))
