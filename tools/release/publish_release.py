"""Publish the staged release to Workshop item 3048946639 with PublisherCmd, then verify.

Guards: exact staged payload (full re-hash vs RELEASE_MANIFEST.json), unchanged
Workshop baseline, no other Publisher running, Steam registered for this user.
Runs PublisherCmd without a console window. Writes publish-result.json.
"""
import hashlib
import json
import re
import shutil
import subprocess
import sys
import time
import urllib.parse
import urllib.request
import winreg
from datetime import datetime, timezone
from pathlib import Path

RELEASE = Path(__file__).resolve().parent
PAYLOAD = RELEASE / '@41st_Kaid_Aux_Release'
NOTE = RELEASE / 'workshop-change-note.txt'
PUBLISHER = Path(r'C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\Publisher\PublisherCmd.exe')
WORKSHOP_LOG = Path(r'C:\Program Files (x86)\Steam\logs\workshop_log.txt')
ITEM = '3048946639'
API = 'https://api.steampowered.com/ISteamRemoteStorage/GetPublishedFileDetails/v1/'


def now():
    return datetime.now(timezone.utc).strftime('%Y-%m-%dT%H:%M:%SZ')


def sha256(path):
    h = hashlib.sha256()
    with open(path, 'rb') as f:
        for chunk in iter(lambda: f.read(8 * 1024 * 1024), b''):
            h.update(chunk)
    return h.hexdigest()


def details():
    body = urllib.parse.urlencode({'itemcount': '1', 'publishedfileids[0]': ITEM}).encode()
    return json.load(urllib.request.urlopen(API, body, timeout=20))


def fail(msg, **extra):
    record = {'status': 'NOT PUBLISHED', 'reason': msg, 'at': now(), **extra}
    (RELEASE / 'publish-result.json').write_text(json.dumps(record, indent=2), encoding='utf-8')
    sys.exit(msg)


manifest = json.loads((RELEASE / 'RELEASE_MANIFEST.json').read_text(encoding='utf-8'))
files = {e['file']: e for e in manifest['files']}
on_disk = sorted(p.relative_to(PAYLOAD).as_posix() for p in PAYLOAD.rglob('*') if p.is_file())
if on_disk != sorted(files):
    fail('staged file list differs from manifest', extra=sorted(set(on_disk) ^ set(files)))
for rel, e in files.items():
    p = PAYLOAD / rel
    if p.stat().st_size != e['bytes'] or sha256(p) != e['sha256']:
        fail('staged file changed: ' + rel)
print('payload verified:', len(files), 'files,', sum(e['bytes'] for e in files.values()), 'bytes')

base = details()['response']['publishedfiledetails'][0]
if int(base['time_updated']) != manifest['base_time_updated'] or int(base['file_size']) != manifest['base_file_size']:
    fail('Workshop item changed since staging; investigate before publishing', live=base)

running = subprocess.run(['tasklist', '/FI', 'IMAGENAME eq Publisher*'], capture_output=True, text=True).stdout
if 'Publisher' in running:
    fail('another Publisher process is running')
with winreg.OpenKey(winreg.HKEY_CURRENT_USER, r'Software\Valve\Steam\ActiveProcess') as k:
    steam_pid, _ = winreg.QueryValueEx(k, 'pid')
    steam_user, _ = winreg.QueryValueEx(k, 'ActiveUser')
if not steam_pid or not steam_user:
    fail('Steam is not registered/signed in for this user')
# Publisher stages a full copy of the payload in %TEMP% on C: while uploading.
free_c = shutil.disk_usage('C:\\').free
if free_c < manifest['total_bytes'] + 1.5 * 1024 ** 3:
    fail('not enough free space on C: for Publisher staging', free_bytes=free_c)

if '--check' in sys.argv:
    print(json.dumps({'ready': True, 'files': len(files), 'bytes': sum(e['bytes'] for e in files.values()),
                      'workshop_time_updated': int(base['time_updated']), 'steam_pid': steam_pid,
                      'c_free_gb': round(free_c / 1024 ** 3, 1), 'checked_at_utc': now()}, indent=2))
    sys.exit(0)

log_offset = WORKSHOP_LOG.stat().st_size if WORKSHOP_LOG.exists() else 0
started = now()
print('publishing started', started)
proc = subprocess.run(
    [str(PUBLISHER), 'update', '/id:' + ITEM, '/changeNoteFile:' + str(NOTE), '/path:' + str(PAYLOAD), '/nologo', '/nosummary'],
    cwd=str(PUBLISHER.parent), capture_output=True, text=True, creationflags=0x08000000)
(RELEASE / 'publish.stdout.log').write_text(proc.stdout, encoding='utf-8')
(RELEASE / 'publish.stderr.log').write_text(proc.stderr, encoding='utf-8')
print('PublisherCmd exit', proc.returncode)
print(proc.stdout[-1500:])

new_log = ''
if WORKSHOP_LOG.exists():
    with open(WORKSHOP_LOG, 'rb') as f:
        f.seek(log_offset)
        new_log = f.read().decode('utf-8', 'replace')
upload_lines = [l for l in new_log.splitlines() if ITEM in l]

after = None
for _ in range(20):
    item = details()['response']['publishedfiledetails'][0]
    if int(item['time_updated']) > manifest['base_time_updated']:
        after = item
        break
    time.sleep(6)

ok = (proc.returncode == 0 and after is not None and int(after['file_size']) == manifest['total_bytes']
      and any('Upload finished for workshop item ' + ITEM + ' : OK' in l for l in upload_lines))
manifest_ids = re.findall(r'ManifestID (\d+)', '\n'.join(upload_lines))
record = {
    'status': 'Published and verified' if ok else 'CHECK MANUALLY',
    'started_at_utc': started,
    'publisher_exit_code': proc.returncode,
    'workshop_log': upload_lines,
    'content_manifest_id': manifest_ids[-1] if manifest_ids else None,
    'time_updated': int(after['time_updated']) if after else None,
    'published_at_utc': datetime.fromtimestamp(int(after['time_updated']), timezone.utc).strftime('%Y-%m-%dT%H:%M:%SZ') if after else None,
    'file_size_bytes': int(after['file_size']) if after else None,
    'expected_file_size_bytes': manifest['total_bytes'],
    'file_count': len(files),
    'verified_at_utc': now(),
}
(RELEASE / 'publish-result.json').write_text(json.dumps(record, indent=2), encoding='utf-8')
if after:
    (RELEASE / 'workshop-after.json').write_text(json.dumps({'response': {'publishedfiledetails': [after]}}, indent=2), encoding='utf-8')
print(json.dumps(record, indent=2))
sys.exit(0 if ok else 2)
