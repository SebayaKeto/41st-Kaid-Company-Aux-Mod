Q_fnc_umbLocal={
params["_mode","_args"];
if(_mode=="NATIVE")exitWith{
 private _before=allGroups;
 [east,["FST_UmbaranInf_SL","FST_UmbaranInf_Standard","FST_UmbaranInf_Medic","FST_UmbaranInf_EOD"],[5000,4000,0],"assault",50,[],true,clientOwner,0]call FST_HCSpawn_fnc_createGroupLocal;
 sleep 2;
 private _new=(allGroups-_before)select{local _x && {count units _x>0} && {typeOf leader _x=="FST_UmbaranInf_SL"}};
 private _g=_new param[0,grpNull];Q_nativeGroup=_g;publicVariable "Q_nativeGroup";
 [_g,"assault",[5200,4000,0],40]call FST_HCSpawn_fnc_setCombatTask;
 _g setVariable["Q_HCResult",[local _g,clientOwner,groupOwner _g,units _g findIf{primaryWeapon _x=="" || {(_x skill "general")<0.79} || {([_x]call FST_HCSpawn_fnc_burnsRole)!="human"}}<0],true];
};
_args params["_g",["_goal",[]]];
[_g]call FST_HCSpawn_fnc_burnsApplyRole;private _ok=[_g,"assault",_goal,40]call FST_HCSpawn_fnc_setCombatTask;
_g setVariable["Q_HCResult",[local _g,_ok,units _g findIf{([_x]call FST_HCSpawn_fnc_burnsRole)!="human"}<0,clientOwner,groupOwner _g,count units _g],true];
};if(isServer)then{[]execVM "run.sqf";};
