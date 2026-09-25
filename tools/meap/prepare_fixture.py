"""Prepare an ISOLATED server mission; sender simulation is never a shipped addon."""
from pathlib import Path
from pbo_tools import pack

repo = Path(__file__).resolve().parents[2]
fixture = repo / 'tests/MEAPEngineering.VR'
source = repo / 'PUBLISHED MODPACK/MEAP_Architect_Core/functions'
for label, function in [('open', 'requestArchitectMode'), ('action', 'architectServerAction'), ('close', 'closeArchitectMode')]:
    text = (source / ('fn_' + function + '.sqf')).read_text()
    text = text.replace('remoteExecutedOwner', '_qaSender')
    if label == 'close':
        text = text.replace('isRemoteExecuted', 'true')
    if label == 'open':
        text = text.replace('MEAP_fnc_closeArchitectMode', 'Q_fnc_simclose')
    (fixture / ('sim_' + label + '.sqf')).write_text('// TEST ONLY: simulated remote execution context.\n' + text)
pack(fixture, fixture.with_suffix('.VR.pbo'))
print('Built isolated MEAPEngineering.VR.pbo. Never load this mission on public Main/Training.')
