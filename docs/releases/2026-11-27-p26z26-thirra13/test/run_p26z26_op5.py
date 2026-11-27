r"""P26z26 op 5 load test (27 Nov): server Ember_Op5_b13r6 + 1 client, Aux = the staged P26z26 folder. PASS = in mission, 0 warning boxes, 0 script errors after start.
P26z25 Bacta engine test (Aux Updater, 25 Nov 2026). ONLY on the Omnibus BOX OK.
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
HERE = Path(r'D:/AuxUpdater/p26z26')
PROBE = Path(r'C:/IslandsA/thirra_ops56/build/Ember_Op5_b13r6.fst_ember_caldera')
AUX = r'C:\Users\Miran\Downloads\Steam-aux-release-20261127-P26z26-thirra13\@41st_Kaid_Aux_Release'
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
assert all(Path(m).is_dir() for m in mods) and Path(AUX, 'Addons', 'fst_ember_caldera.pbo').is_file()
ml = HERE / 'modlist_71_p26z26.txt'; ml.write_text(';'.join(mods), encoding='utf-8')
empty = Path(r'D:/AuxUpdater/qol24/@P26z24_TerrainInAux'); assert empty.is_dir() and not any((empty / 'addons').iterdir())
assert (PROBE / 'mission.sqm').is_file()
if HARD_END == 'plan': print('PLAN OK', len(mods), 'mods'); sys.exit()
assert time.strftime('%H:%M') < HARD_END, 'past hard end'
def servers():
    out = subprocess.run(['tasklist', '/FI', 'IMAGENAME eq arma3server_x64.exe', '/FO', 'CSV', '/NH'], capture_output=True, text=True, creationflags=NOWIN).stdout
    return [l for l in out.splitlines() if 'arma3server_x64' in l.lower()]
if rom.arma_clients() or servers(): sys.exit('REFUSED: Arma running %s %s' % (rom.arma_clients(), servers()))
NAME = 'P26z26Op5'; t0 = time.time(); shots = HERE / 'winshot_op5'
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
        if 'Starting mission' in Path(crpt).read_text(encoding='utf-8', errors='replace'): done = True; log('in mission; 120 s soak'); time.sleep(120); break
log('probe done' if done else 'probe NOT done', crpt)
r = subprocess.run([PY313, RB, '--stop', '--run', str(run)], capture_output=True, text=True, creationflags=NOWIN); log('stop:', r.stdout.strip().replace('\n', ' | '))
for proc in (p, ws):
    try: proc.wait(timeout=60)
    except Exception: pass
lines = Path(crpt).read_text(encoding='utf-8', errors='replace').splitlines() if crpt else []
if crpt: (HERE / 'logs').mkdir(exist_ok=True); shutil.copy2(crpt, HERE / 'logs' / Path(crpt).name)
strip = lambda l: re.sub(r'^\s*\d+:\d+:\d+\s*', '', l).strip()
st = next((i for i, l in enumerate(lines) if 'Starting mission' in l), len(lines))
after = lines[st:]
v = {'client_rpt': crpt, 'in_mission': done, 'client_boot': boot, 'winshots': str(shots), 'rpt_lines': len(lines),
     'error_lines': sum('error' in l.lower() for l in lines),
     'script_errors_after_start': sum('Error in expression' in l for l in after),
     'warning_boxes': sum('Warning Message' in l for l in lines),
     'aux_error_lines': [strip(l) for l in lines if 'error' in l.lower() and any(k in l.lower() for k in ('fst_', '41st', 'kaid', 'ember_caldera'))][:15]}
v['PASS'] = bool(done and v['warning_boxes'] == 0 and v['script_errors_after_start'] == 0)
(HERE / 'verdict_p26z26_op5.json').write_text(json.dumps(v, indent=1), encoding='utf-8')
log('VERDICT', 'PASS' if v['PASS'] else 'FAIL', {k: v[k] for k in ('rpt_lines', 'error_lines', 'script_errors_after_start', 'warning_boxes')})
