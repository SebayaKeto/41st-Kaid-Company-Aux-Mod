from pathlib import Path
import hashlib,json,zipfile
root=Path(__file__).resolve().parent.parent
out=root/'outputs/testing'
dest=out/'Tonight-Rehearsal.zip'
files=sorted(p for p in (out/'@Kaid_Aux_Candidate').rglob('*') if p.is_file())
files+=sorted(p for p in (out/'missions').rglob('*') if p.is_file())
files += [out/n for n in ['TONIGHT.md','READINESS.md','Verify-Candidate.ps1','final-candidate-manifest.json','daara-mission-audit.json','repair-audit.json']]
expected={}
with zipfile.ZipFile(dest,'w',compression=zipfile.ZIP_DEFLATED,compresslevel=1,allowZip64=True) as archive:
    for p in files:
        name=p.relative_to(out).as_posix()
        h=hashlib.sha256()
        with p.open('rb') as source, archive.open(name,'w',force_zip64=True) as target:
            for data in iter(lambda:source.read(4*1024*1024),b''):
                h.update(data);target.write(data)
        expected[name]=h.hexdigest()
print('Archive written; verifying every entry.',flush=True)
with zipfile.ZipFile(dest) as archive:
    assert set(archive.namelist())==set(expected)
    for name,wanted in expected.items():
        h=hashlib.sha256()
        with archive.open(name) as source:
            for data in iter(lambda:source.read(4*1024*1024),b''):h.update(data)
        assert h.hexdigest()==wanted,name
h=hashlib.sha256()
with dest.open('rb') as source:
    for data in iter(lambda:source.read(4*1024*1024),b''):h.update(data)
report={'archive':dest.name,'bytes':dest.stat().st_size,'sha256':h.hexdigest(),'entries':len(expected),'allEntriesReadBackAndSHA256Verified':True,'contents':expected,'disposition':'Client rehearsal candidate; AAT issue unresolved; no live release signoff.'}
(out/'rehearsal-bundle-audit.json').write_text(json.dumps(report,indent=2))
print(json.dumps({k:v for k,v in report.items() if k!='contents'},indent=2),flush=True)
