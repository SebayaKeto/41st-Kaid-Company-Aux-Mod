from pathlib import Path
import shutil
from pbo_tools import pack
root=Path(__file__).resolve().parent.parent
src=root/'work/qualification/CandidateHybrid.VR'
dst=root/'work/qualification/CandidateArmorDiagnostic.VR'
dst.mkdir(exist_ok=True)
for name in ['mission.sqm','description.ext','cba_settings.sqf']:
    shutil.copy2(src/name,dst/name)
(dst/'init.sqf').write_text('if(isServer)then{[] execVM "run.sqf";};\n')
s=(src/'run.sqf').read_text()
s=s.replace('hybrid','diagnostic').replace('QUAL_HYBRID_ARMOR','QUAL_ARMOR_DIAGNOSTIC')
s=s.replace('{\n private _task=_x;', '{\n private _frozen=_x;\n {\n private _task=_x;')
s=s.replace('}forEach[0,90,180];','}forEach[0,180];')
s=s.replace('}forEach["","rush","hunt"];','}forEach["","rush"];\n}forEach[false,true];')
s=s.replace('private _tg=group driver _t;', 'if(_frozen)then{_t enableSimulationGlobal false};\n  private _targetStart=getPosATL _t;\n  private _tg=group driver _t;')
s=s.replace('_samples pushBack[abs', '_samples pushBack[abs')
s=s.replace('velocityModelSpace _v]','velocityModelSpace _v,getPosATL _v,getPosATL _t,([_v,"VIEW",_t] checkVisibility[eyePos gunner _v,aimPos _t]),assignedTarget gunner _v,canFire _v,currentCommand driver _v]')
s=s.replace('bearing %2",_task,_bearing','bearing %2 frozen %3",_task,_bearing,_frozen')
s=s.replace('[_label+" firing",', 'diag_log format["[QUAL_TARGET_PHYSICS] %1",[_label,_t distance2D _targetStart,getPosATL _t,velocity _t]];\n  [_label+" firing",')
(dst/'run.sqf').write_text(s)
pack(dst,root/'outputs/testing/server/mpmissions/CandidateArmorDiagnostic.VR.pbo')
cfg=root/'outputs/testing/server/server.cfg'
t=cfg.read_text();t=t.replace('class Missions {};','class Missions {class Qualification {template="CandidateArmorDiagnostic.VR";difficulty="Regular";};};')
cfg.write_text(t)
print('Original delivered AAT diagnostic packed: mobile/frozen targets, bearings, task modes, visibility and positions.')
