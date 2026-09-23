from pathlib import Path
import shutil
from pbo_tools import pack
root=Path(__file__).resolve().parent.parent
src=root/'work/qualification/CandidateHybrid.VR'
dst=root/'work/qualification/CandidateReleaseTrial.VR'
shutil.copytree(src,dst,dirs_exist_ok=True)
fn='fn_burnsArmorPulseEnd.sqf'
s=(root/'work/qualification/integrated/source/FST_HCSpawn'/fn).read_text()
s=s.replace('if (_driver!=leader _group) then {_driver doFollow leader _group};', '''private _mode=([_group,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet) param [0,""];
// Mission-only experiment: avoid reissuing follow inside a stationary tank.
if (_mode!="" && {_driver!=leader _group}) then {_driver doFollow leader _group};''')
(dst/fn).write_text(s)
p=dst/'init.sqf';p.write_text('FST_HCSpawn_fnc_burnsArmorPulseEnd=compile preprocessFileLineNumbers "'+fn+'";\n'+p.read_text())
p=dst/'run.sqf';s=p.read_text();a=s.index('private _deadline=');b=s.index('["hybrid preset applied"',a);s=s[:a]+s[b:]
s=s.replace('["hybrid preset four HCs",count(missionNamespace getVariable["FST_HC_Ids",[]])==4]call Q_check;', '["server-only release trial",isServer]call Q_check;')
s=s.replace('hybrid','release-trial').replace('QUAL_HYBRID_ARMOR','QUAL_RELEASE_TRIAL')
p.write_text(s)
pack(dst,root/'outputs/testing/server/mpmissions/CandidateReleaseTrial.VR.pbo')
cfg=(root/'outputs/testing/server/server.cfg').read_text().replace('CandidateArmorDiagnostic.VR','CandidateReleaseTrial.VR').replace('steamQueryPort=2443','steamQueryPort=2463')
(root/'outputs/testing/server/release-trial.cfg').write_text(cfg)
print('Mission-only pulse-release trial ready. Delivered addon unchanged.')
