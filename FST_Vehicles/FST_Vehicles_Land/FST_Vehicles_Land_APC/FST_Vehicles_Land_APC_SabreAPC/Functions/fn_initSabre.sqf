params ["_vehicle"];
if (isNull _vehicle) exitWith {};
private _first=false;
isNil {
    if !(_vehicle getVariable ["FST_raiderInitLocal",false]) then {
        _vehicle setVariable ["FST_raiderInitLocal",true];
        _vehicle addEventHandler ["Local",{_this call FST_Raider_fnc_startSabreOwner}];
        _first=true;
    };
};
if (_first && {local _vehicle} && {alive _vehicle}) then {
    _vehicle setVehicleAmmo 1;
    _vehicle forceSpeed -1;
};
if (local _vehicle) then {[_vehicle] call FST_Raider_fnc_startSabreOwner};
if (!_first || {!hasInterface} || {!alive _vehicle}) exitWith {};
// Cosmetic sources remain local. One pair and one HUD startup per vehicle/client.
[_vehicle] spawn {
    params ["_v"];
    private _lights=[];
    {
        private _l="#lightpoint" createVehicleLocal [0,0,0];
        _l setLightColor [1,0.08,0.08];_l setLightAmbient [0.35,0.03,0.03];
        _l setLightIntensity 2.5;_l setLightUseFlare false;
        _l setLightAttenuation [0,0,0,1,18,30];
        _l lightAttachObject [_v,_v selectionPosition [_x,"Memory"]];
        _lights pushBack _l;
    } forEach ["Emissive_01","Emissive_02"];
    waitUntil {uiSleep 1;!alive _v};
    {deleteVehicle _x} forEach _lights;
};
[_vehicle] execVM "\FST\FST_Vehicles\FST_Vehicles_Land\FST_Vehicles_Land_APC\FST_Vehicles_Land_APC_SabreAPC\Functions\fn_showSabreArmorStatus.sqf";
