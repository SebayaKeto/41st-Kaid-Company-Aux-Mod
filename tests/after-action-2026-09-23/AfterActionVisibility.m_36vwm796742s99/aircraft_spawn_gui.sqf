private _rotaryList = [
    ["LAAT/i Mk1",                      "FST_laati_Turret"],
    ["LAAT/i Mk2",                      "FST_laati_mk2"],
    ["LAAT/i Mk2 (Lamps)",              "FST_laati_mk2Lights"],
    ["LAAT/c",                          "FST_LAATC"],
    ["LAAT/c Pole",                     "FST_LAATC_Pole"],
    ["LAAT/le",                         "FST_LAAT_LE"],
    ["LAAT/i Mk1 'Q-Ball'",             "FST_laati_Turret_Qball"],
    ["LAAT/i Mk2 'Q-Ball'",             "FST_laati_mk2_Qball"],
    ["LAAT/i Mk2 'Q-Ball' (Lamps)",     "FST_laati_mk2Lights_Qball"],
    ["LAAT/i Mk1 'Grim'",               "FST_laati_Turret_Grim"],
    ["LAAT/i Mk2 'Grim'",               "FST_laati_mk2_Grim"],
    ["LAAT/i Mk2 'Grim' (Lamps)",       "FST_laati_mk2Lights_Grim"],
    ["LAAT/i Mk1 'Sierra'",             "FST_laati_Turret_Sierra"],
    ["LAAT/i Mk2 'Sierra'",             "FST_laati_mk2_Sierra"],
    ["LAAT/i Mk2 'Sierra' (Lamp)",      "FST_laati_mk2Lights_Sierra"],
    ["LAAT/i Mk1 'Ouranos'",            "FST_laati_Turret_Ouranos"],
    ["LAAT/i Mk2 'Ouranos'",            "FST_laati_mk2_Ouranos"],
    ["LAAT/i Mk2 'Ouranos' (Lamps)",    "FST_laati_mk2Lights_Ouranos"],
    ["LAAT/i Mk1 'Cait'",               "FST_laati_Turret_Cait"],
    ["LAAT/i Mk2 'Cait'",               "FST_laati_mk2_Cait"],
    ["LAAT/i Mk2 'Cait' (Lamps)",       "FST_laati_mk2Lights_Cait"],
    ["LAAT/i Mk1 'Fire'",               "FST_laati_Turret_Fire"],
    ["LAAT/i Mk2 'Fire'",               "FST_laati_mk2_Fire"],
    ["LAAT/i Mk2 'Fire' (Lamps)",       "FST_laati_mk2Lights_Fire"],
    ["LAAT/i Mk1 'Talisman'",           "FST_laati_Turret_Talisman"],
    ["LAAT/i Mk2 'Talisman'",            "FST_laati_mk2_Talisman"],
    ["LAAT/i Mk2 'Talisman' (Lamps)",   "FST_laati_mk2Lights_Talisman"],
    ["LAAT/i Mk1 'Pole'",               "FST_laati_Turret_Pole"],
    ["LAAT/i Mk2 'Pole'",               "FST_laati_mk2_Pole"],
    ["LAAT/i Mk2 'Pole' (Lamps)",       "FST_laati_mk2Lights_Pole"],
    ["LAAT/i Mk1 'Red'",                "FST_laati_Turret_Red"],
    ["LAAT/i Mk2 'Red'",                "FST_laati_mk2_Red"],
    ["LAAT/i Mk2 'Red' (Lamps)",        "FST_laati_mk2Lights_Red"],
    ["LAAT/i Mk1 'Aether'",             "FST_laati_Turret_Aether"],
    ["LAAT/i Mk2 'Aether'",             "FST_laati_mk2_Aether"],
    ["LAAT/i Mk2 'Aether' (Lamps)",     "FST_laati_mk2Lights_Aether"]
];

private _fixedList = [
    ["ARC-170 Heavy Fighter",       "FST_Arc_170"],
    ["ARC_170 Pole",                "FST_ARC_170_Pole"],
    ["ARC_170 Rear",                "FST_Arc_170_Rear"],
    ["ARC_170 Pole Rear",           "FST_Arc_170_Pole_Rear"],
    ["Y-Wing Strategic Bomber",     "FST_Ywing_Bomber_Green"],
    ["Z-95 Headhunter",             "FST_Z95_Republic"],
    ["Z-95 Headhunter Q-Ball",      "FST_Z95_Qball"],
    ["Nu-Class Shuttle",            "FST_Nu_Shuttle"],
    ["Rho-Class Shuttle",           "FST_Rho_Shuttle"]
];

private _battalionList = [
    ["ITT",                             "FST_ITT"],
    ["ITT (Logistics)",                 "FST_ITT_Logistic"],
    ["Resupply Pod",                    "FST_Supplies_Pod"],
    ["Logistics Pod",                   "FST_Logistics_Pod"],
    ["AV-7 Field Cannon Artillery",     "FST_AV7"],
    ["HAVw A6 Juggernaut",              "FST_Jug"],
    ["PR-10 'Puma' (Desert)",           "FST_PR10_APC_Desert"],
    ["PR-10 'Puma' (Desert) Turreted",  "FST_Technical_Twin_Laser_Desert"],
    ["PR-10 'Puma' (Midnight)",         "FST_PR10_APC_Midnight"],
    ["PR-10 'Puma' (Midnight) Turreted","FST_Technical_Twin_Laser_Midnight"],
    ["PR-10 'Puma' (Urban)",            "FST_PR10_APC_Urban"],
    ["PR-10 'Puma' (Urban) Turreted",   "FST_Technical_Twin_Laser_Urban"],
    ["PR-10 'Puma' (Woodland)",         "FST_PR10_APC_Woodland"],
    ["PR-10 'Puma' (Woodland) Turreted","FST_Technical_Twin_Laser_Woodland"]
];

private _co1List = [
    ["Republic Mortar",         "FST_Republic_Mortar"],
    ["E-Web Blaster Turret",    "FST_EWEB"]
];

private _co2List = [
    ["AT-TE",                           "FST_ATTE_Base"],
    ["AT-TE (Rancor)",                  "FST_ATTE_Rancor"],
    ["AT-TE (Klanka Killa)",            "FST_ATTE_Klanka"],
    ["AT-TE (Grenner)",                 "FST_ATTE_gwenn"],
    ["AT-AP",                           "FST_ATAP_Base"],
    ["TX-130 Recon Saber",              "FST_Recon_Saber"],
    ["TX-130 Saber",                    "FST_Saber"],
    ["TX-130 Saber (Rancor)",           "FST_Saber_Rancor"],
    ["TX-130 Super Saber",              "FST_SuperSaber"],
    ["TX-130 Super Saber (Rancor)",     "FST_SuperSaber_Rancor"],
    ["TX-130 Recon Saber (TheClawMachine)", "FST_Recon_Saber_TheClawMachine"],
    ["TX-130 Saber (TheClawMachine)",       "FST_Saber_TheClawMachine"],
    ["TX-130 Super Saber (TheClawMachine)", "FST_SuperSaber_TheClawMachine"],
    ["ISP Swamp Speeder",               "FST_ISP"],
    ["ISP Swamp Speeder (Transport)",   "FST_ISP_Transport"],
    ["PK-V5 'Dewback' IFV",             "FST_PKV5_UP_Sickle"],
    ["PK-V5 'Dianoga' MLRS",            "FST_PKV5_MLRS_Carrier"],
    ["PK-V5 'Gundark' Light Tank",      "FST_PKV5_UP_Stormer"],
    ["PK-V5 'Massif' SPG",              "FST_PKV5_UP_Sceptre"],
    ["PK-V5 'Veractyl' SPAA",           "FST_PKV5_UP_Shredder"]
];

private _padList = [
    ["Pad 1", "Pad1_Spawn_Location"],
    ["Pad 2", "Pad2_Spawn_Location"],
    ["Pad 3", "Pad3_Spawn_Location"],
    ["Pad 4", "Pad4_Spawn_Location"],
    ["Pad 5", "Pad5_Spawn_Location"],
    ["Pad 6", "Pad6_Spawn_Location"],
    ["Pad 7", "Pad7_Spawn_Location"],
    ["Pad 8", "Pad8_Spawn_Location"],
    ["Pad 9", "Pad9_Spawn_Location"],
    ["Pad 10", "Pad10_Spawn_Location"]
];

private _categoryList = [
    ["Rotary Wing",      "GUI_RotaryList"],
    ["Fixed Wing",       "GUI_FixedList"],
    ["Battalion Assets", "GUI_BattalionList"],
    ["1st Company",      "GUI_Co1List"],
    ["2nd Company",      "GUI_Co2List"]
];

missionNamespace setVariable ["GUI_RotaryList",    _rotaryList];
missionNamespace setVariable ["GUI_FixedList",     _fixedList];
missionNamespace setVariable ["GUI_BattalionList", _battalionList];
missionNamespace setVariable ["GUI_Co1List",       _co1List];
missionNamespace setVariable ["GUI_Co2List",       _co2List];
missionNamespace setVariable ["GUI_PadList",       _padList];
missionNamespace setVariable ["GUI_CategoryList",  _categoryList];
uiNamespace setVariable ["GUI_SelectedClass", ""];
uiNamespace setVariable ["GUI_SelectedName",  ""];
uiNamespace setVariable ["GUI_ActiveListVar", "GUI_RotaryList"];

private _padCache = [];
{
    private _varName = _x select 1;
    private _padObj  = missionNamespace getVariable [_varName, objNull];
    if (isNull _padObj) then {
        { if (vehicleVarName _x == _varName) exitWith { _padObj = _x; }; } forEach allMissionObjects "Logic";
    };
    _padCache pushBack _padObj;
} forEach _padList;
missionNamespace setVariable ["GUI_PadCache", _padCache];

fnc_getSelectedPad = {
    private _display  = uiNamespace getVariable ["GUI_Display", displayNull];
    private _combo    = _display displayCtrl 9951;
    private _selIdx   = lbCurSel _combo;
    private _padCache = uiNamespace getVariable ["GUI_PadCache", []];
    if (_selIdx < 0 || _selIdx >= count _padCache) exitWith { objNull };
    _padCache select _selIdx
};

fnc_isPadClear = {
    params ["_pad", "_statusLbl"];
    private _preview = uiNamespace getVariable ["GUI_PreviewVehicle", objNull];
    private _nearVehicles = (getPosASL _pad) nearEntities [["LandVehicle", "Air", "Ship"], 10];
    _nearVehicles = _nearVehicles select { alive _x && _x != _preview };
    if (count _nearVehicles > 0) then {
        _statusLbl ctrlSetText format ["> DEPLOY REJECTED — %1 UNIT(S) OBSTRUCTING LANDING ZONE.", count _nearVehicles];
        _statusLbl ctrlSetTextColor [0.95, 0.30, 0.30, 1.0];
        _statusLbl ctrlCommit 0;
        false
    } else {
        true
    }
};

fnc_setStatus = {
    params ["_statusLbl", "_text", "_color"];
    _statusLbl ctrlSetText _text;
    _statusLbl ctrlSetTextColor _color;
    _statusLbl ctrlCommit 0;
};

fnc_removePreviewVehicle = {
    private _prev = uiNamespace getVariable ["GUI_PreviewVehicle", objNull];
    if (!isNull _prev) then {
        deleteVehicle _prev;
        uiNamespace setVariable ["GUI_PreviewVehicle", objNull];
    };
};

fnc_spawnPreviewVehicle = {
    if (!hasInterface) exitWith {};
    call fnc_removePreviewVehicle;
    private _className = uiNamespace getVariable ["GUI_SelectedClass", ""];
    if (_className == "") exitWith {};
    private _pad = call fnc_getSelectedPad;
    if (isNull _pad) exitWith {};

    private _pos     = getPosATL _pad;
    private _preview = _className createVehicleLocal _pos;
    _preview setDir (getDir _pad);
    _preview setPosATL _pos;
    _preview allowDamage false;
    _preview enableSimulation false;
    { deleteVehicle _x } forEach crew _preview;

    uiNamespace setVariable ["GUI_PreviewVehicle", _preview];
};

fnc_populateVehicleList = {
    private _display    = uiNamespace getVariable ["GUI_Display", displayNull];
    private _listbox    = _display displayCtrl 9910;
    private _searchBox  = _display displayCtrl 9985;
    private _query      = toLower (ctrlText _searchBox);
    private _activeVar  = uiNamespace getVariable ["GUI_ActiveListVar", "GUI_RotaryList"];
    private _fullList   = missionNamespace getVariable [_activeVar, []];

    lbClear _listbox;
    private _idx = 0;
    {
        if (_query == "" || { (toLower (_x select 0)) find _query >= 0 }) then {
            _listbox lbAdd (_x select 0);
            _listbox lbSetValue [_idx, _forEachIndex];
            _idx = _idx + 1;
        };
    } forEach _fullList;
};

fnc_updateCategory = {
    private _display     = uiNamespace getVariable ["GUI_Display", displayNull];
    private _catCombo    = _display displayCtrl 9982;
    private _selIdx      = lbCurSel _catCombo;
    private _catList     = missionNamespace getVariable ["GUI_CategoryList", []];
    if (_selIdx < 0 || _selIdx >= count _catList) exitWith {};
    private _entry       = _catList select _selIdx;
    uiNamespace setVariable ["GUI_ActiveListVar", _entry select 1];
    call fnc_removePreviewVehicle;
    private _searchBox   = _display displayCtrl 9985;
    _searchBox ctrlSetText "";
    call fnc_populateVehicleList;
};

fnc_updateSelection = {
    private _display     = uiNamespace getVariable ["GUI_Display", displayNull];
    private _listbox     = _display displayCtrl 9910;
    private _selIdx      = lbCurSel _listbox;
    if (_selIdx < 0) exitWith {};
    private _origIdx     = _listbox lbValue _selIdx;
    private _activeVar   = uiNamespace getVariable ["GUI_ActiveListVar", "GUI_RotaryList"];
    private _list        = missionNamespace getVariable [_activeVar, []];
    private _entry       = _list select _origIdx;
    uiNamespace setVariable ["GUI_SelectedClass", _entry select 1];
    uiNamespace setVariable ["GUI_SelectedName",  _entry select 0];
    private _selectedLbl = _display displayCtrl 9856;
    _selectedLbl ctrlSetText format ["> %1", _entry select 0];
    _selectedLbl ctrlSetTextColor [0.25, 0.95, 0.35, 1.0];
    _selectedLbl ctrlCommit 0;
    call fnc_spawnPreviewVehicle;
};

fnc_spawnVehicle = {
    private _display     = uiNamespace getVariable ["GUI_Display", displayNull];
    private _statusLbl   = _display displayCtrl 9856;
    private _className   = uiNamespace getVariable ["GUI_SelectedClass", ""];
    private _displayName = uiNamespace getVariable ["GUI_SelectedName",  ""];

    if (_className == "") exitWith {
        [_statusLbl, "> ERROR: NO UNIT SELECTED.", [0.95, 0.30, 0.30, 1.0]] call fnc_setStatus;
    };

    private _pad = call fnc_getSelectedPad;

    if (isNull _pad) exitWith {
        private _combo   = _display displayCtrl 9951;
        private _selIdx  = lbCurSel _combo;
        private _padList = uiNamespace getVariable ["GUI_PadList", []];
        private _varName = if (_selIdx >= 0) then { (_padList select _selIdx) select 1 } else { "unknown" };
        [_statusLbl, format ["> ERROR: PAD OBJECT '%1' NOT FOUND.", _varName], [0.95, 0.30, 0.30, 1.0]] call fnc_setStatus;
    };

    if !([_pad, _statusLbl] call fnc_isPadClear) exitWith {};

    private _pos     = getPosATL _pad;
    private _dir     = getDir _pad;

    private _combo   = _display displayCtrl 9951;
    private _selIdx  = lbCurSel _combo;
    private _padList = uiNamespace getVariable ["GUI_PadList", []];
    private _varName = (_padList select _selIdx) select 1;
    private _padName = _combo lbText _selIdx;

    call fnc_removePreviewVehicle;
    [_className, _pos, _dir, format ["GUI_PadVehicle_%1", _varName]] remoteExec ["fnc_serverSpawnVehicle", 2];
    [_statusLbl, format ["> DEPLOYED: %1 ON %2.", _displayName, _padName], [0.20, 0.90, 0.30, 1.0]] call fnc_setStatus;
};

aircraft_deploy = { call fnc_spawnVehicle; };

aircraft_garage = {
    private _display   = uiNamespace getVariable ["GUI_Display", displayNull];
    private _statusLbl = _display displayCtrl 9856;
    private _combo     = _display displayCtrl 9951;
    private _selIdx    = lbCurSel _combo;
    private _padList   = uiNamespace getVariable ["GUI_PadList", []];

    if (_selIdx < 0 || _selIdx >= count _padList) exitWith {
        [_statusLbl, "> ERROR: NO TARGET PAD SELECTED.", [0.95, 0.80, 0.15, 1.0]] call fnc_setStatus;
    };

    private _varName = (_padList select _selIdx) select 1;
    private _padName = _combo lbText _selIdx;
    private _pad     = (uiNamespace getVariable ["GUI_PadCache", []]) select _selIdx;

    if (isNull _pad) exitWith {
        [_statusLbl, format ["> ERROR: PAD OBJECT '%1' NOT FOUND.", _varName], [0.95, 0.30, 0.30, 1.0]] call fnc_setStatus;
    };

    private _preview      = uiNamespace getVariable ["GUI_PreviewVehicle", objNull];
    private _nearVehicles = (getPosASL _pad) nearEntities [["LandVehicle", "Air", "Ship"], 10];
    _nearVehicles = _nearVehicles select { alive _x && _x != _preview };

    if (count _nearVehicles == 0) exitWith {
        [_statusLbl, format ["> NO UNITS DETECTED WITHIN 10M OF %1.", _padName], [0.95, 0.80, 0.15, 1.0]] call fnc_setStatus;
    };

    private _stored      = 0;
    private _crewBlocked = 0;

    {
        if (count crew _x > 0) then {
            _crewBlocked = _crewBlocked + 1;
        } else {
            private _storeKey = format ["GUI_PadVehicle_%1", _varName];
            private _tracked  = missionNamespace getVariable [_storeKey, objNull];
            if (!isNull _tracked && { _tracked == _x }) then {
                missionNamespace setVariable [_storeKey, objNull];
            };
            _x remoteExec ["deleteVehicle", 2];
            _stored = _stored + 1;
        };
    } forEach _nearVehicles;

    if (_stored > 0 && _crewBlocked == 0) then {
        [_statusLbl, format ["> %1 UNIT(S) RECALLED FROM %2.", _stored, _padName], [0.20, 0.90, 0.30, 1.0]] call fnc_setStatus;
    };
    if (_stored > 0 && _crewBlocked > 0) then {
        [_statusLbl, format ["> %1 RECALLED. %2 SKIPPED — CREW STILL ABOARD.", _stored, _crewBlocked], [0.95, 0.75, 0.15, 1.0]] call fnc_setStatus;
    };
    if (_stored == 0 && _crewBlocked > 0) then {
        [_statusLbl, "> RECALL DENIED — EVACUATE ALL CREW FIRST.", [0.95, 0.55, 0.10, 1.0]] call fnc_setStatus;
    };
};

fnc_destroyPadCamera = {
    call fnc_removePreviewVehicle;
    private _cam = uiNamespace getVariable ["GUI_PadCam", objNull];
    if (!isNull _cam) then {
        _cam cameraEffect ["TERMINATE", "BACK"];
        camDestroy _cam;
        uiNamespace setVariable ["GUI_PadCam", objNull];
    };
    private _script = uiNamespace getVariable ["GUI_PadCamScript", scriptNull];
    if (!isNull _script) then {
        terminate _script;
        uiNamespace setVariable ["GUI_PadCamScript", scriptNull];
    };
    private _light = uiNamespace getVariable ["GUI_PreviewLight", objNull];
    if (!isNull _light) then {
        deleteVehicle _light;
        uiNamespace setVariable ["GUI_PreviewLight", objNull];
    };
    private _display = uiNamespace getVariable ["GUI_Display", displayNull];
    if (!isNull _display) then {
        (_display displayCtrl 9811) ctrlSetText "NO PAD SELECTED";
        (_display displayCtrl 9812) ctrlSetText "FEED OFFLINE";
        (_display displayCtrl 9812) ctrlSetTextColor [0.55, 0.30, 0.30, 1.0];
    };
};

fnc_updatePadCamera = {
    call fnc_destroyPadCamera;

    private _display  = uiNamespace getVariable ["GUI_Display", displayNull];
    private _combo    = _display displayCtrl 9951;
    private _selIdx   = lbCurSel _combo;
    private _padList  = uiNamespace getVariable ["GUI_PadList", []];
    private _padCache = uiNamespace getVariable ["GUI_PadCache", []];

    if (_selIdx < 0 || _selIdx >= count _padCache) exitWith {};
    private _pad = _padCache select _selIdx;
    if (isNull _pad) exitWith {};

    private _padName = (_padList select _selIdx) select 0;
    private _padPos  = getPosASL _pad;

    private _light = "#lightpoint" createVehicleLocal [(_padPos select 0), (_padPos select 1), (_padPos select 2) + 8];
    _light setLightBrightness 8;
    _light setLightDaylight true;
    _light setLightColor [1.0, 1.0, 1.0];
    _light setLightAmbient [0.1, 0.1, 0.1];
    uiNamespace setVariable ["GUI_PreviewLight", _light];

    private _cam = "camera" camCreate _padPos;
    _cam camSetFOV 0.7;
    _cam camSetTarget _padPos;
    _cam cameraEffect ["INTERNAL", "BACK", "PadCamRT"];
    _cam camCommit 0;

    uiNamespace setVariable ["GUI_PadCam", _cam];

    (_display displayCtrl 9811) ctrlSetText format ["// %1", toUpper _padName];
    (_display displayCtrl 9812) ctrlSetText "FEED ACTIVE";
    (_display displayCtrl 9812) ctrlSetTextColor [0.20, 0.90, 0.30, 1.0];

    private _script = [_cam, _padPos] spawn {
        params ["_cam", "_padPos"];
        private _angle = 0;
        _cam camSetTarget _padPos;
        while {!isNull _cam && {!isNull (findDisplay 9900)}} do {
            _angle = (_angle + 0.63) % 360;
            private _x = (_padPos select 0) + (20 * sin _angle);
            private _y = (_padPos select 1) + (20 * cos _angle);
            private _z = (_padPos select 2) + 15;
            _cam setPosASL [_x, _y, _z];
            _cam camCommit 0;
            sleep 0.07;
        };
    };

    uiNamespace setVariable ["GUI_PadCamScript", _script];
    call fnc_spawnPreviewVehicle;
};

createDialog "AircraftSpawnGUI";
uiSleep 0.1;

private _display    = findDisplay 9900;
private _padCombo   = _display displayCtrl 9951;
private _catCombo   = _display displayCtrl 9982;
private _listbox    = _display displayCtrl 9910;
private _searchBox  = _display displayCtrl 9985;

private _padCache = missionNamespace getVariable ["GUI_PadCache", []];
uiNamespace setVariable ["GUI_Display",  _display];
uiNamespace setVariable ["GUI_PadList",  _padList];
uiNamespace setVariable ["GUI_PadCache", _padCache];
{
    private _label = (_padList select _forEachIndex) select 0;
    if (isNull _x) then { _label = format ["%1  [NOT PLACED]", _label]; };
    _padCombo lbAdd _label;
    _padCombo lbSetValue [_forEachIndex, _forEachIndex];
} forEach _padCache;

{
    _catCombo lbAdd (_x select 0);
    _catCombo lbSetValue [_forEachIndex, _forEachIndex];
} forEach _categoryList;

private _playerPos  = getPosATL player;
private _closestIdx = 0;
private _closestDst = 1e10;
{
    if (!isNull _x) then {
        private _dst = _playerPos distance2D (getPosATL _x);
        if (_dst < _closestDst) then {
            _closestDst = _dst;
            _closestIdx = _forEachIndex;
        };
    };
} forEach _padCache;
_padCombo lbSetCurSel _closestIdx;
_catCombo  lbSetCurSel 0;

call fnc_populateVehicleList;

_padCombo  ctrlAddEventHandler ["LBSelChanged", { call fnc_updatePadCamera; }];
_catCombo  ctrlAddEventHandler ["LBSelChanged", { call fnc_updateCategory; }];
_listbox   ctrlAddEventHandler ["LBSelChanged", { call fnc_updateSelection; }];
_searchBox ctrlAddEventHandler ["KeyUp",        { call fnc_populateVehicleList; }];

_display displayAddEventHandler ["Unload", { call fnc_destroyPadCamera; }];

call fnc_updatePadCamera;