if (!(is3DEN)) then {
    systemChat "Applying Immersive Voices!";
    diag_log "Applying Immersive Voices!";
} else {
    diag_log "Applying Immersive Voices! (in 3DEN)";
};

0 spawn {
    {
        // Current result is saved in variable _x
        _unit = _x;

        [_unit] spawn PHEN_fnc_IVP_AutoAssign;
        uiSleep 0.001;

    } forEach allUnits;
};

player addEventHandler ["CuratorGroupPlaced", {
	params ["_curator", "_group"];

    {
        _unit = _x;
        [_unit] spawn PHEN_fnc_IVP_AutoAssign;
        
    } forEach (units _group);

}];

player addEventHandler ["CuratorObjectPlaced", {
	params ["_curator", "_entity"];

    _unit = _entity;
    [_unit] spawn PHEN_fnc_IVP_AutoAssign;

}];