["FST_applyIdentity", {
    params ["_person", "_face", "_speaker"];
    _person setFace _face;
    _person setSpeaker _speaker;
}] call CBA_fnc_addEventHandler;

["FST_applyName", {
    params ["_person", "_name"];
    _person setName _name;
}] call CBA_fnc_addEventHandler;