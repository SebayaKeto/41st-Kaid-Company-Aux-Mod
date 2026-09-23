from pathlib import Path
import struct, hashlib

def cstr(f):
    out=bytearray()
    while True:
        b=f.read(1)
        if not b: raise EOFError('Truncated PBO')
        if b==b'\0': return out.decode('latin1')
        out.extend(b)

def index(path):
    rows={}; props={}
    with Path(path).open('rb') as f:
        while True:
            name=cstr(f); header=struct.unpack('<5I',f.read(20))
            if not name and header[0]==0x56657273:
                while True:
                    key=cstr(f)
                    if not key: break
                    props[key]=cstr(f)
                continue
            if not name: break
            key=name.replace('\\','/').lower()
            if key in rows: raise ValueError('Duplicate PBO entry '+key)
            rows[key]={'name':name,'header':header,'size':header[4]}
        offset=f.tell()
        for row in rows.values():
            row['offset']=offset; offset+=row['size']
        if offset>Path(path).stat().st_size: raise ValueError('PBO size mismatch')
    return rows,props

def read(path,name):
    rows,_=index(path); row=rows[name.replace('\\','/').lower()]
    if row['header'][0]!=0: raise ValueError('Compressed entry '+name)
    with Path(path).open('rb') as f:
        f.seek(row['offset']); return f.read(row['size'])

def digest_entry(f,row):
    f.seek(row['offset']); remaining=row['size']; h=hashlib.sha256()
    while remaining:
        b=f.read(min(remaining,4*1024*1024)); remaining-=len(b); h.update(b)
        if not b: raise EOFError()
    return h.hexdigest()

def pack(src,dst,prefix=''):
    src=Path(src); dst=Path(dst)
    files=sorted(p for p in src.rglob('*') if p.is_file() and p.name.lower() not in ['$pboprefix$','pbo.json'] and p.suffix.lower()!='.sqfc')
    def entry(n,size=0,method=0):return n.encode('latin1')+b'\0'+struct.pack('<5I',method,size,0,0,size)
    header=bytearray()
    if prefix: header+=entry('',0,0x56657273)+b'prefix\0'+prefix.encode()+b'\0\0'
    for p in files:header+=entry(str(p.relative_to(src)).replace('/','\\'),p.stat().st_size)
    header+=entry('')
    dst.parent.mkdir(parents=True,exist_ok=True)
    h=hashlib.sha1()
    with dst.open('wb') as out:
        out.write(header);h.update(header)
        for p in files:
            data=p.read_bytes();out.write(data);h.update(data)
        out.write(b'\0'+h.digest())
