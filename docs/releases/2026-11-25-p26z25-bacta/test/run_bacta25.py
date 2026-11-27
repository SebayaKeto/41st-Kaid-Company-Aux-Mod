r"""P26z25 Bacta engine test (Aux Updater, 25 Nov 2026). ONLY on the Omnibus BOX OK.
Server via review_boot (probe mission bacta25/probe/BactaProbe.VR, empty terrain mod, port 4593, live 71-mod list with the Aux
swapped to the staged P26z25), then ONE client via relaunch_on_marker.boot_client (zombie guard). Waits for "BACTAPROBE done"
(max 300 s), PrintWindow winshots every 15 s, --stop, copies the client RPT to bacta25/logs.
PASS = case1 (bleeding, unconscious) bacta canTreat=false with bleeding > 0; case2 (bandaged, still unconscious) bacta canTreat=true
with bleeding 0; treatment started=true; after: uncon=false, blood >= 5.99, bleeding 0; case3 (bandaged, AWAKE) canTreat=true and
the treatment clears the bandaged wounds (full heal); no Warning Message / script error naming
bacta or BACTAPROBE. usage: run_bacta25.py HARD_END(HH:MM)|plan       writes bacta25/verdict_bacta25.json"""
import glob, json, re, shutil, subprocess, sys, time
from pathlib import Path
HARD_END = sys.argv[1]
HERE = Path(r'D:/AuxUpdater/bacta25')
PROBE = HERE / 'probe' / 'BactaProbe.VR'
AUX = r'C:\Users\Miran\Downloads\Steam-aux-release-20261125-P26z25-bacta\@41st_Kaid_Aux_Release'
Z24_AUX = r'C:\Users\Miran\Downloads\Steam-aux-release-20261125-P26z24-qol-thirra11-menufix\@41st_Kaid_Aux_Release'
RB = r'D:/Codex/Mapmaking_Omnibus_Production/review/review_boot.py'
PY313 = r'C:/Users/Miran/AppData/Local/Programs/Python/Python313/python.exe'
PY310 = r'C:/Users/Miran/AppData/Local/Programs/Python/Python310/python.exe'
NOWIN = 0x08000000
sys.path.insert(0, r'D:/AuxUpdater/clickfix/menustall'); import relaunch_on_marker as rom
def log(*a):
    s = time.strftime('%H:%M:%S ') + ' '.join(str(x) for x in a); print(s, flush=True)
    with open(HERE / 'run.log', 'a', encoding='utf-8') as f: f.write(s + '\n')
mods = [m for m in Path(r'D:/AuxUpdater/qol24/modlist_71.txt').read_text(encoding='utf-8').strip().split(';') if m]
assert len(mods) == 71 and mods.count(Z24_AUX) == 1, 'modlist_71 does not hold the P26z24 Aux'
mods = [AUX if m == Z24_AUX else m for m in mods]
assert all(Path(m).is_dir() for m in mods) and Path(AUX, 'Addons', '41st_Medical.pbo').is_file()
ml = HERE / 'modlist_71_p26z25.txt'; ml.write_text(';'.join(mods), encoding='utf-8')
empty = Path(r'D:/AuxUpdater/qol24/@P26z24_TerrainInAux'); assert empty.is_dir() and not any((empty / 'addons').iterdir())
assert (PROBE / 'initPlayerLocal.sqf').is_file() and (PROBE / 'mission.sqm').is_file()
if HARD_END == 'plan': print('PLAN OK', len(mods), 'mods'); sys.exit()
assert time.strftime('%H:%M') < HARD_END, 'past hard end'
def servers():
    out = subprocess.run(['tasklist', '/FI', 'IMAGENAME eq arma3server_x64.exe', '/FO', 'CSV', '/NH'], capture_output=True, text=True, creationflags=NOWIN).stdout
    return [l for l in out.splitlines() if 'arma3server_x64' in l.lower()]
if rom.arma_clients() or servers(): sys.exit('REFUSED: Arma running %s %s' % (rom.arma_clients(), servers()))
NAME = 'P26z25Bacta'; t0 = time.time(); shots = HERE / 'winshot_bacta'
p = subprocess.Popen([PY313, RB, '--name', NAME, '--mission', str(PROBE), '--terrain-mod', str(empty), '--port', '4593', '--modlist', str(ml)],
                     stdout=open(HERE / 'boot.out', 'w'), stderr=subprocess.STDOUT, creationflags=NOWIN)
run = None
for _ in range(120):
    time.sleep(2)
    c = [q for q in Path(r'C:/ReviewSessions').glob(NAME + '-*') if q.stat().st_ctime >= t0 - 2 and (q / 'session.json').is_file()]
    if c: run = max(c, key=lambda q: q.stat().st_ctime); break
if not run: log('no run folder'); sys.exit(5)
ws = subprocess.Popen([PY310, r'D:/AuxUpdater/clickfix/winshot_after.py', str(run), str(shots), '--every', '15', '--after', '100', '--max', '900'],
                      stdout=open(HERE / 'winshot.out', 'w'), stderr=subprocess.STDOUT, creationflags=NOWIN, cwd=r'D:/AuxUpdater/clickfix')
boot = rom.boot_client(run, window=True, when_ready=True, retries=2, join_timeout=400, hard_end=HARD_END)
log('client boot:', boot['result'])
crpt = boot['attempts'][-1]['client_rpt'] if boot['attempts'] else None
done = False
if boot['exit'] == 0 and crpt:
    end = time.time() + 300
    while time.time() < end and time.strftime('%H:%M') < HARD_END:
        time.sleep(5)
        if 'BACTAPROBE done' in Path(crpt).read_text(encoding='utf-8', errors='replace'): done = True; time.sleep(5); break
log('probe done' if done else 'probe NOT done', crpt)
r = subprocess.run([PY313, RB, '--stop', '--run', str(run)], capture_output=True, text=True, creationflags=NOWIN); log('stop:', r.stdout.strip().replace('\n', ' | '))
for proc in (p, ws):
    try: proc.wait(timeout=60)
    except Exception: pass
lines = Path(crpt).read_text(encoding='utf-8', errors='replace').splitlines() if crpt else []
if crpt: (HERE / 'logs').mkdir(exist_ok=True); shutil.copy2(crpt, HERE / 'logs' / Path(crpt).name)
strip = lambda l: re.sub(r'^\s*\d+:\d+:\d+\s*', '', l).strip()
q = [strip(l) for l in lines if 'BACTAPROBE' in l]
def line(k): return next((l for l in q if l.startswith('BACTAPROBE ' + k)), '')
def num(l, k):
    m = re.search(k + r'=(-?[\d.]+)', l); return float(m.group(1)) if m else None
c1, c2, tr, af = line('case1'), line('case2'), line('treatment'), line('after')
c3, c3a = line('case3 '), line('case3after')
def bw(l):
    m = re.search(r'wounds (\d+) -> (\d+)', l); return (int(m.group(1)), int(m.group(2))) if m else None
bad = [strip(l) for l in lines if ('Warning Message' in l or 'Error' in l) and ('bacta' in l.lower() or 'BACTAPROBE' in l)][:10]
v = {'client_rpt': crpt, 'probe_done': done, 'client_boot': boot, 'bactaprobe': q, 'bad_lines': bad, 'winshots': str(shots),
     'case1_ok': 'bacta canTreat=false' in c1 and (num(c1, 'bleeding') or 0) > 0 and 'uncon=true' in c1,
     'case2_ok': 'bacta canTreat=true' in c2 and num(c2, 'bleeding') == 0 and 'uncon=true' in c2,
     'treatment_started': 'started=true' in tr,
     'full_heal': 'uncon=false' in af and (num(af, 'blood') or 0) >= 5.99 and num(af, 'bleeding') == 0 and bool(bw(af)) and bw(af)[0] > 0 and bw(af)[1] == 0,
     'case3_ok': 'bacta canTreat=true' in c3 and 'uncon=false' in c3 and num(c3, 'bleeding') == 0,
     'case3_heal': 'started=true' in c3a and bool(bw(c3a)) and bw(c3a)[0] > 0 and bw(c3a)[1] == 0 and 'uncon=false' in c3a,
     'warnings_after_start': sum('Warning Message' in l for l in lines[next((i for i, l in enumerate(lines) if 'Starting mission' in l), len(lines)):])}
v['PASS'] = bool(done and v['case1_ok'] and v['case2_ok'] and v['treatment_started'] and v['full_heal'] and v['case3_ok'] and v['case3_heal'] and not bad)
(HERE / 'verdict_bacta25.json').write_text(json.dumps(v, indent=1), encoding='utf-8')
log('VERDICT', 'PASS' if v['PASS'] else 'FAIL'); print('\n'.join(q))
