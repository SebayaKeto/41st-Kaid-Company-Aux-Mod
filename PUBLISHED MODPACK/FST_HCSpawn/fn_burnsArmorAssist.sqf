params ["_group","_contacts"];
if !(missionNamespace getVariable ["BURNS_ArmorAssistEnabled",true]) exitWith {};
private _v=vehicle leader _group;
if (!(_v isKindOf "FST_AAT") || {!local _v} || {!alive _v} || {!canFire _v}) exitWith {};
if ((units _group findIf {alive _x && {vehicle _x!=_v}})>=0) exitWith {};
private _driver=driver _v;
private _gunner=gunner _v;
if (isNull _gunner || {!local _gunner} || {!alive _gunner} || {_gunner getVariable ["BURNS_exempt",false]}) exitWith {};
// Inherited on-foot role writes must not disable a newly boarded crew's AI.
private _target=objNull;
private _best=1e12;
{
    _x params ["_pos","_type","_side","_cost","_object"];
    if (isNull _object || {!alive _object} || {captive _object} || {isObjectHidden _object} || {_side in [civilian,sideUnknown,sideLogic]} || {(side _group) getFriend _side>=0.6}) then {continue};
    private _platform=vehicle _object;
    if (_platform isKindOf "Air" || {[_object] call FST_HCSpawn_fnc_burnsIsDown}) then {continue};
    private _d=_v distance2D _pos;
    if (_d<_best) then {_target=_platform;_best=_d};
} forEach _contacts;
if (isNull _target) exitWith {};
private _point=aimPos _target;
if (([_v,"VIEW",_target] checkVisibility [eyePos _gunner,_point])<=0.5) exitWith {};
if (_gunner checkAIFeature "TARGET" && {_gunner checkAIFeature "AUTOTARGET"} && {_gunner checkAIFeature "FIREWEAPON"}) then {
    if (assignedTarget _gunner!=_target) then {_gunner doTarget _target};
    _gunner doFire _target;
};
// Give a bounded obstacle detour to native driving without competing hull turns.
if (count (_v getVariable ["BURNS_driveDetour",[]])>0) exitWith {};
if (isNull _driver || {!alive _driver} || {!local _driver} || {!canMove _v} || {!(_driver checkAIFeature "PATH")} || {effectiveCommander _v==_driver}) exitWith {};
private _mode=([_group,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet) param [0,""];
if !(_mode in ["","rush","hunt","assault"]) exitWith {};
private _wp=currentWaypoint _group;
private _wpPos=waypointPosition [_group,_wp];
// Unassigned armor must still obey an explicit native travel waypoint.
if (_mode=="" && {_wp<count waypoints _group} && {_v distance2D _wpPos>25}) exitWith {};
private _angle=(((_v getDir _target)-getDir _v+540) mod 360)-180;
private _turn=_v getVariable ["BURNS_turnProgress",[getDir _v,getPosATL _v,0]];
private _turned=abs (((getDir _v-(_turn select 0)+540) mod 360)-180);
if (_turned>12 || {_v distance2D (_turn select 1)>4} || {abs _angle<40}) then {_turn=[getDir _v,getPosATL _v,0]};
if ((_turn select 2)>=3) exitWith {
    _v setVariable ["BURNS_turnProgress",[getDir _v,getPosATL _v,0]];
    _v setVariable ["BURNS_armorTurnNext",time+8];
    if (_wp<count waypoints _group) then {_group setCurrentWaypoint [_group,_wp]};
    if (_driver!=leader _group) then {_driver doFollow leader _group};
};
_v setVariable ["BURNS_turnProgress",_turn];
if (abs _angle<55 || {time<(_v getVariable ["BURNS_armorTurnNext",-1])}) exitWith {};
if (count (_v getVariable ["BURNS_armorPulse",[]])>0) exitWith {};
if (abs speed _v>12) exitWith {
    // Brake a rear-first approach before trying to pivot at speed. Forward
    // travel and front-facing reverse withdrawals are left to native driving.
    if ((velocityModelSpace _v select 1)<-1 && {abs _angle>90}) then {
        _v sendSimpleCommand "STOPTURNING";
        _v sendSimpleCommand "STOP";
        _v setVariable ["BURNS_armorTurnNext",time+2];
    };
};
// A short physical turn, never setDir/teleport/velocity manipulation. Every
// pulse gets its own unconditional latch release through CBA's scheduled queue.
_turn set [2,(_turn select 2)+1];
_v setVariable ["BURNS_turnProgress",_turn];
private _serial=(_v getVariable ["BURNS_armorSerial",0])+1;
_v setVariable ["BURNS_armorSerial",_serial];
private _token=format ["%1:%2:%3",clientOwner,diag_tickTime,_serial];
_v setVariable ["BURNS_armorTurnNext",time+2];
private _revision=[_group,["BURNS_movementRevision",0]] call FST_HCSpawn_fnc_burnsStateGet;
_v setVariable ["BURNS_armorPulse",[_token,_group,_driver,_wp,_wpPos,_revision,clientOwner,time+1],true];
_v sendSimpleCommand "STOPTURNING";
doStop _driver;
_v sendSimpleCommand "STOP";
_v sendSimpleCommand (if (_angle<0) then {"LEFT"} else {"RIGHT"});
BURNS_ArmorTurnPulses=(missionNamespace getVariable ["BURNS_ArmorTurnPulses",0])+1;
[FST_HCSpawn_fnc_burnsArmorPulseEnd,[_v,_token],linearConversion [55,180,abs _angle,0.3,0.7,true]] call CBA_fnc_waitAndExecute;
