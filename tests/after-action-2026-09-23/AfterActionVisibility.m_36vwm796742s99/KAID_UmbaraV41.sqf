// ===== KAID Umbara V4.1 master block (Admin Panel -> Server Exec) =====
// Changes vs V4:
//   * flare helper light is tunable via missionNamespace vars and defaults to a dimmer setting
//   * infantry NVG block (Zeus camera unaffected; aircraft crew optional via KAID_Umbara_AllowAirNVG; officer/commander visors and officer rangefinders exempt via KAID_Umbara_NVGExemptClasses)
//   * ground-vehicle thermal block (aircraft keep TI)
//   * Zeus view (normal mode only): grade lifted + clarity boost, glare shield only while flares burn, optional local fog relief; Zeus NVG = V4 behaviour (NVG with a flare in view is a grey wash in any version: Zeus should use normal view while flares burn)
//   * fog altitude decay 0.017 (was 0.004): ~800 m air-to-air at 120 m AGL, ~1.2 km at 200 m AGL
//   * ambient birds/animals and bird/insect sound layers disabled
//   * distant battlefield audio: very rare (15-45 min apart), brief (5-9 s), intense two-sided exchanges 1.6-2.8 km from a player group,
//     heard identically by everyone in range (one world-space source), armed by Zeus or a 60 min timer; KAID_BattleAudio_* tunables
//   * long-op guard: time multiplier 0.1 (sun would rise ~02:30 otherwise), clock/fog/overcast/rain re-asserted every 60 s
//   * all loops carry Running flags so re-running the block replaces them cleanly
private _base = getTerrainHeightASL [worldSize / 2,worldSize / 2];
// Small debrief adjustment: target +5% fog-limited visibility, tunable to +10%.
// This scales density conservatively; exact perceived distance needs a client check.
private _visibility = (missionNamespace getVariable ["KAID_Umbara_VisibilityGain",1.05]) max 1 min 1.10;
private _ground = 0.65 / _visibility;
missionNamespace setVariable ["KAID_Umbara_VisibilityGain",_visibility,true];
private _decay = 0.017;   // V4 used 0.004. Verified in-engine: 0.017 gives ~800 m air-to-air visibility at 120 m AGL and ~1.2 km at 200 m AGL; ground fog unchanged

missionNamespace setVariable ["KAID_FogBase",_base + 40,true];
missionNamespace setVariable ["KAID_FogDecay",_decay,true];
missionNamespace setVariable ["KAID_FogGround",_ground,true];

0 setOvercast 1;
0 setRain 0;
0 setFog [_ground,_decay,_base + 40];
0 setLightnings 1;
setWind [3,4,true];

forceWeatherChange;

999999 setOvercast 1;
999999 setRain 0;
999999 setFog [_ground,_decay,_base + 40];
999999 setLightnings 1;

{
    [_x,[-1,-2]] call BIS_fnc_setCuratorVisionModes;
} forEach allCurators;

// ---- tunables (server-synced so Zeus can retune live from the debug console) ----
missionNamespace setVariable ["KAID_FlareLightIntensity",0,true];   // helper light OFF by default since op day (its ambient term drove auto-exposure down: "flares make it darker"); 2200 was the tested V4.1 value
missionNamespace setVariable ["KAID_FlareLightAmbient",[0.55,0.50,0.42],true];
missionNamespace setVariable ["KAID_FlareLightAttenuation",[0,0,0,0.003,180,320],true];
missionNamespace setVariable ["KAID_Umbara_AllowAirNVG",true,true];
missionNamespace setVariable ["KAID_Umbara_BlockGroundTI",true,true];
missionNamespace setVariable ["KAID_Umbara_IndoorLogic",true,true];     // clear halls + mute ambience bed while under a placed object's roof (Acclamator)
missionNamespace setVariable ["KAID_Umbara_IndoorFog",0.12,true];       // fog VALUE applied locally while under a roof (halls clear; haze still visible through the bridge windows). Fog is uniform below the fog base, so only the value helps here
missionNamespace setVariable ["KAID_Umbara_NoRoofPrefixes",["land_3as_umbara","egl_","jms_"],true];   // class prefixes that never count as a roof (canopy trees, Gliese plants); anything else with a class does (ship modules, buildings)
missionNamespace setVariable ["KAID_Umbara_NVGExemptClasses",["FST_Visor","FST_Visor_Woodland","FST_Marshal_Commander_Visor","FST_Antenna","JLTS_CloneNVGCC","JLTS_CloneNVGMC","JLTS_CloneNVGRange"],true];   // officer/commander visors and officer rangefinders keep NVG; matched on the worn item and its parent classes, so every skin variant counts
missionNamespace setVariable ["KAID_Umbara_ExemptBlockTI",true,true];    // exempt visors/rangefinders still lose their thermal mode (goggles switch off when TI is selected; NVG mode stays available)
missionNamespace setVariable ["KAID_Umbara_ZeusFogRelief",true,true];   // local fog thinning while the Zeus interface is open
missionNamespace setVariable ["KAID_Umbara_ZeusFog",0.10,true];   // Zeus-local fog while the interface is open (0.30 was judged still too thick)
missionNamespace setVariable ["KAID_Umbara_ZeusGlareShield",false,true];   // darken the Zeus view while flares burn (op-day feedback: far too dark; keep false)

[[],{
0 setRain 0;
skipTime 1;
skipTime -1;
}] remoteExec ["BIS_fnc_call",-2];

// ---- long-op guard (server): hold the clock and the weather for the whole op ----
// The map's latitude (60 N, July) means the sun rises ~02:30 game time; a 6 h op would run into daylight.
// Time multiplier 0.1 => 6 real hours = 36 game minutes. Re-asserted every 60 s against Zeus modules / skipTime.
// Zeus: to move the op clock on purpose, set KAID_Umbara_LockTime false, setDate, then set it true again (re-anchors).
missionNamespace setVariable ["KAID_Umbara_LockTime",true,true];
missionNamespace setVariable ["KAID_Umbara_TimeMult",0.1,true];
missionNamespace setVariable ["KAID_Umbara_SetTime",[0,30],true];   // op time of day [hour,minute] applied when the block runs; [] = keep current
missionNamespace setVariable ["KAID_WeatherGuardRunning",false];

if (isServer) then {
    private _t = missionNamespace getVariable ["KAID_Umbara_SetTime",[0,30]];
    if (count _t == 2) then {
        setDate [date select 0, date select 1, date select 2, _t select 0, _t select 1];
        diag_log format ["KAID_Guard: op time set to %1", date];
    };
    setTimeMultiplier (missionNamespace getVariable ["KAID_Umbara_TimeMult",0.1]);
    [] spawn {
        uiSleep 2;
        missionNamespace setVariable ["KAID_WeatherGuardRunning",true];
        private _anchor = date;
        private _wasLocked = true;
        diag_log format ["KAID_Guard: started, anchor date %1, timeMultiplier %2", _anchor, timeMultiplier];
        while { missionNamespace getVariable ["KAID_WeatherGuardRunning",false] } do {
            uiSleep 60;
            private _locked = missionNamespace getVariable ["KAID_Umbara_LockTime",true];
            if (_locked && {!_wasLocked}) then { _anchor = date; diag_log format ["KAID_Guard: re-anchored to %1", _anchor]; };
            _wasLocked = _locked;
            if (_locked) then {
                private _m = missionNamespace getVariable ["KAID_Umbara_TimeMult",0.1];
                if (abs (timeMultiplier - _m) > 0.01) then { setTimeMultiplier _m; diag_log format ["KAID_Guard: timeMultiplier reset to %1", _m]; };
                private _dh = abs (dayTime - ((_anchor select 3) + (_anchor select 4) / 60));
                _dh = _dh min (24 - _dh);
                if (_dh > 1.5) then { setDate _anchor; diag_log format ["KAID_Guard: clock drifted %1 h, reset to %2", _dh toFixed 2, _anchor]; };
            };
            private _fp = fogParams;
            private _decay = missionNamespace getVariable ["KAID_FogDecay",0.017];
            private _fogBase = missionNamespace getVariable ["KAID_FogBase",0];
            private _ground = missionNamespace getVariable ["KAID_FogGround",0.619047619];
            if (abs ((_fp select 0) - _ground) > 0.03 || {abs ((_fp select 1) - _decay) > 0.001} || {abs ((_fp select 2) - _fogBase) > 1}) then {
                10 setFog [_ground,_decay,_fogBase]; 999999 setFog [_ground,_decay,_fogBase];
                diag_log format ["KAID_Guard: fog was %1, restored", _fp];
            };
            if (overcast < 0.9) then { 10 setOvercast 1; 999999 setOvercast 1; diag_log "KAID_Guard: overcast restored"; };
            if (rain > 0.05) then { 0 setRain 0; 999999 setRain 0; diag_log "KAID_Guard: rain cleared"; };
        };
    };
};

// ---- distant battlefield audio (server only; playSound3D from the server is heard by every client, positionally) ----
missionNamespace setVariable ["KAID_BattleAudioRunning",false];
missionNamespace setVariable ["KAID_BattleAudio_MinDist",1600,true];   // source distance from a random player (m)
missionNamespace setVariable ["KAID_BattleAudio_MaxDist",2800,true];
missionNamespace setVariable ["KAID_BattleAudio_Range",4500,true];     // audible range of each shot (m)
missionNamespace setVariable ["KAID_BattleAudio_Pitch",0.85,true];     // < 1 = duller, further-sounding
missionNamespace setVariable ["KAID_BattleAudio_MinGap",900,true];    // seconds of silence between exchanges (15 min)
missionNamespace setVariable ["KAID_BattleAudio_MaxGap",2700,true];   // (45 min)
missionNamespace setVariable ["KAID_BattleAudio_GroupRadius",1500,true];   // players within this distance count as one group
missionNamespace setVariable ["KAID_BattleAudio_MinLen",5,true];    // engagement length in seconds
missionNamespace setVariable ["KAID_BattleAudio_MaxLen",9,true];
missionNamespace setVariable ["KAID_BattleAudio_Volume",1.2,true];
// Shots stay silent until EITHER a Zeus arms them from Server Exec:
//     missionNamespace setVariable ["KAID_BattleAudio_Armed",true,true];
// OR the fallback timer expires (seconds after this block ran; 0 = manual only).
// Stop for good:  missionNamespace setVariable ["KAID_BattleAudioRunning",false,true];
missionNamespace setVariable ["KAID_BattleAudio_Armed",false,true];
missionNamespace setVariable ["KAID_BattleAudio_ArmAfter",3600,true];   // 60 min fallback

if (isServer) then {
    [] spawn {
        uiSleep 1;
        missionNamespace setVariable ["KAID_BattleAudioRunning",true];

        private _armT0 = time;
        waitUntil {
            uiSleep 2;
            private _after = missionNamespace getVariable ["KAID_BattleAudio_ArmAfter",3600];
            (missionNamespace getVariable ["KAID_BattleAudio_Armed",false])
            || {_after > 0 && {time - _armT0 >= _after}}
            || {!(missionNamespace getVariable ["KAID_BattleAudioRunning",false])}
        };
        if !(missionNamespace getVariable ["KAID_BattleAudioRunning",false]) exitWith {};
        missionNamespace setVariable ["KAID_BattleAudio_Armed",true,true];
        diag_log format ["KAID_BattleAudio: armed at t=%1 (%2 s after block)", round time, round (time - _armT0)];

        // the 41st's own weapon fire sounds (same files the DC-15 / Z-6 / DC-17 / droid E-5 configs use); only files that exist are kept
        private _rep = [
            "\41st_Weapons\DC-15AS\Data\dc15av2 2-177.ogg",
            "\41st_Weapons\DC-15AS\Data\dc15av2 2-177 (1).ogg",
            "\41st_Weapons\DC-15AS\Data\dc15av2 2-177 (2).ogg",
            "\41st_Weapons\DC-15AS\Data\15sv2 2-177.ogg",
            "\41st_Weapons\DC-15AS\Data\15sv2 2-177 (2).ogg",
            "\41st_Weapons\DC-15AS\Data\15sv2 2-177 (3).ogg",
            "\41st_Weapons\DC-15AS\Data\dc15cv1 2-177.ogg",
            "\41st_Weapons\DC-15AS\Data\dc15cv1 2-177 (2).ogg",
            "\41st_weapons\Z6\Data\z6 -3-965 (1).ogg",
            "\41st_weapons\Z6\Data\z6 -3-965 (3).ogg",
            "\41st_Weapons\DC17\Data\dc17v2 2-117.ogg"
        ] select { fileExists _x };
        private _cis = [
            "\41st_Weapons\CIS\Data\E5c 1-008.ogg",
            "\41st_Weapons\CIS\Data\SW02_Weapons_Blasters_E5_Laser_Close_VAR_04 0 0 0.wav"
        ] select { fileExists _x };
        diag_log format ["KAID_BattleAudio: %1 republic / %2 cis sound files available", count _rep, count _cis];
        if (_rep isEqualTo [] && {_cis isEqualTo []}) exitWith { diag_log "KAID_BattleAudio: no sound files found, disabled"; };
        if (_rep isEqualTo []) then { _rep = _cis; };
        if (_cis isEqualTo []) then { _cis = _rep; };

        // one side firing flat out until _until: bursts of 4-10 shots at 0.07-0.16 s, short gaps between bursts
        private _sideFire = {
            params ["_files","_posASL","_vol","_until"];
            while { time < _until } do {
                for "_i" from 1 to (4 + floor random 7) do {
                    if (time >= _until) exitWith {};
                    private _pitch = missionNamespace getVariable ["KAID_BattleAudio_Pitch",0.85];
                    playSound3D [selectRandom _files, objNull, false, _posASL, _vol, _pitch - 0.04 + random 0.08, missionNamespace getVariable ["KAID_BattleAudio_Range",4500]];
                    uiSleep (0.07 + random 0.09);
                };
                uiSleep (0.15 + random 0.45);
            };
        };

        // one sound source in world space is heard identically by everyone in range, so an exchange is
        // automatically "synced" for a group. Players are clustered by proximity; the cluster that has gone
        // longest without hearing one gets the next exchange, placed on its far side away from other clusters.
        private _events = [];   // [time, positionASL] of past exchanges
        private _clusterRadius = missionNamespace getVariable ["KAID_BattleAudio_GroupRadius",1500];

        while { missionNamespace getVariable ["KAID_BattleAudioRunning",false] } do {
            uiSleep ((missionNamespace getVariable ["KAID_BattleAudio_MinGap",900]) + random ((missionNamespace getVariable ["KAID_BattleAudio_MaxGap",2700]) - (missionNamespace getVariable ["KAID_BattleAudio_MinGap",900])));
            if !(missionNamespace getVariable ["KAID_BattleAudioRunning",false]) exitWith {};

            private _players = allPlayers select { alive _x };
            if !(_players isEqualTo []) then {
                // greedy proximity clustering -> list of centroids with member counts
                private _clusters = [];
                {
                    private _p = getPosATL _x;
                    private _idx = _clusters findIf { (_x select 0) distance2D _p < _clusterRadius };
                    if (_idx < 0) then {
                        _clusters pushBack [_p, 1];
                    } else {
                        private _c = _clusters select _idx;
                        private _n = (_c select 1) + 1;
                        private _cen = ((_c select 0) vectorMultiply ((_n - 1) / _n)) vectorAdd (_p vectorMultiply (1 / _n));
                        _clusters set [_idx, [_cen, _n]];
                    };
                } forEach _players;

                // pick the cluster with the longest silence (no exchange within audible range of it)
                private _range = missionNamespace getVariable ["KAID_BattleAudio_Range",4500];
                private _best = _clusters select 0;
                private _bestSilence = -1;
                {
                    private _cen = _x select 0;
                    private _last = -1e9;
                    { if (((_x select 1) distance2D _cen) < _range && {(_x select 0) > _last}) then { _last = _x select 0; }; } forEach _events;
                    private _silence = time - _last;
                    if (_silence > _bestSilence) then { _bestSilence = _silence; _best = _x; };
                } forEach _clusters;
                private _anchor = _best select 0;

                // source 1.6-2.8 km out; try 8 bearings and keep the one furthest from every other cluster
                private _dist = (missionNamespace getVariable ["KAID_BattleAudio_MinDist",1600]) + random ((missionNamespace getVariable ["KAID_BattleAudio_MaxDist",2800]) - (missionNamespace getVariable ["KAID_BattleAudio_MinDist",1600]));
                private _bearing = random 360;
                private _bestClear = -1;
                for "_k" from 0 to 7 do {
                    private _b = (random 360);
                    private _cand = _anchor vectorAdd [_dist * sin _b, _dist * cos _b, 0];
                    private _clear = 1e9;
                    { if !((_x select 0) isEqualTo _anchor) then { _clear = _clear min ((_x select 0) distance2D _cand); }; } forEach _clusters;
                    if (_clear > _bestClear) then { _bestClear = _clear; _bearing = _b; };
                };
                private _srcASL = ATLToASL (_anchor vectorAdd [_dist * sin _bearing, _dist * cos _bearing, 3 + random 10]);
                _events pushBack [time, _srcASL];
                diag_log format ["KAID_BattleAudio: exchange for cluster of %1 at %2 (of %3 clusters, silence %4 s), source %5 m bearing %6, clear of others %7 m",
                    _best select 1, (_anchor apply {round _x}), count _clusters, round _bestSilence, round _dist, round _bearing, if (_bestClear > 1e8) then {"n/a"} else {round _bestClear}];
                private _replyASL = _srcASL vectorAdd [60 + random 90, -40 + random 80, 0];
                private _vol = missionNamespace getVariable ["KAID_BattleAudio_Volume",2.5];
                private _len = (missionNamespace getVariable ["KAID_BattleAudio_MinLen",5]) + random ((missionNamespace getVariable ["KAID_BattleAudio_MaxLen",9]) - (missionNamespace getVariable ["KAID_BattleAudio_MinLen",5]));
                private _until = time + _len;

                // both sides fire at once: one opens, the other joins within a second; it all stops together
                if (random 1 < 0.5) then {
                    [_rep, _srcASL, _vol, _until] spawn _sideFire;
                    uiSleep (0.3 + random 0.7);
                    [_cis, _replyASL, _vol, _until] spawn _sideFire;
                } else {
                    [_cis, _srcASL, _vol, _until] spawn _sideFire;
                    uiSleep (0.3 + random 0.7);
                    [_rep, _replyASL, _vol, _until] spawn _sideFire;
                };
                waitUntil { uiSleep 0.5; time >= _until };
                // occasional single straggler after the exchange dies
                if (random 1 < 0.4) then {
                    uiSleep (0.8 + random 1.5);
                    playSound3D [selectRandom (_rep + _cis), objNull, false, _srcASL, _vol, missionNamespace getVariable ["KAID_BattleAudio_Pitch",0.85], missionNamespace getVariable ["KAID_BattleAudio_Range",4500]];
                };
            };
        };
    };
};

[[],{

// This JIP payload owns player graphics, audio and view controls only.
// Headless clients receive world weather from the server and have no renderer.
if (!hasInterface) exitWith {};

missionNamespace setVariable ["KAID_ZeusFlareEyeRunning",false];
missionNamespace setVariable ["KAID_ZeusFlareEyeV2Running",false];

private _oldEyeEH = missionNamespace getVariable ["KAID_ZeusFlareEyeEH",-1];

if (_oldEyeEH != -1) then {
    removeMissionEventHandler ["ProjectileCreated",_oldEyeEH];
    missionNamespace setVariable ["KAID_ZeusFlareEyeEH",-1];
};

private _oldCC = missionNamespace getVariable ["KAID_Umbara_CC",-1];

if (_oldCC != -1) then {
    ppEffectDestroy _oldCC;
};

private _cc = ppEffectCreate ["ColorCorrections",1501];

_cc ppEffectEnable true;

_cc ppEffectAdjust [
    0.76,
    1.04,
    -0.02,
    [0.03,0.03,0.09,0.24],
    [0.52,0.58,1.08,0.72],
    [0.25,0.42,0.30,0]
];

_cc ppEffectCommit 5;

missionNamespace setVariable ["KAID_Umbara_CC",_cc];

setApertureNew [-1];

private _oldFlareEH = missionNamespace getVariable ["KAID_FlareTerrainEH",-1];

if (_oldFlareEH != -1) then {
    removeMissionEventHandler ["ProjectileCreated",_oldFlareEH];
};

private _flareEH = addMissionEventHandler ["ProjectileCreated",{
    params ["_p"];

    private _cfg = configFile >> "CfgAmmo" >> typeOf _p;

    if (toLower (getText (_cfg >> "simulation")) != "shotilluminating") exitWith {};

    [_p] spawn {
        params ["_p"];

        uiSleep 0.05;

        if (isNull _p) exitWith {};

        missionNamespace setVariable ["KAID_LiveFlares",(missionNamespace getVariable ["KAID_LiveFlares",0]) + 1];

        [_p] spawn {
            params ["_p"];
            waitUntil {uiSleep 0.5; isNull _p};
            missionNamespace setVariable ["KAID_LiveFlares",((missionNamespace getVariable ["KAID_LiveFlares",0]) - 1) max 0];
        };

        private _intensity = missionNamespace getVariable ["KAID_FlareLightIntensity",2200];
        if (_intensity <= 0) exitWith {};

        private _l = "#lightpoint" createVehicleLocal (getPosATL _p);

        _l setLightColor [1,0.92,0.78];
        _l setLightAmbient (missionNamespace getVariable ["KAID_FlareLightAmbient",[0.55,0.50,0.42]]);
        _l setLightIntensity _intensity;
        _l setLightAttenuation (missionNamespace getVariable ["KAID_FlareLightAttenuation",[0,0,0,0.003,180,320]]);

        _l lightAttachObject [_p,[0,0,0]];

        waitUntil {
            uiSleep 0.25;
            isNull _p
        };

        deleteVehicle _l;
    };
}];

missionNamespace setVariable ["KAID_FlareTerrainEH",_flareEH];

missionNamespace setVariable ["KAID_ZeusBlueNVGRunning",false];
missionNamespace setVariable ["KAID_ZeusBlueNVGV2Running",false];

[] spawn {

    uiSleep 0.25;

    missionNamespace setVariable ["KAID_ZeusBlueNVGV2Running",true];

    private _fx = ppEffectCreate ["ColorCorrections",16736];

    _fx ppEffectForceInNVG true;
    _fx ppEffectEnable false;

    private _effect = [];

    if !(isNil "PDT_ENVG_fnc_getNvgEffect") then {
        _effect = call PDT_ENVG_fnc_getNvgEffect;
    };

    if (_effect isEqualTo []) then {
        _effect = [
            1,
            1,
            0,
            [0,0,0,0],
            [0.627,0.882,0.918,0],
            [1,1,1,0]
        ];
    };

    _fx ppEffectAdjust _effect;
    _fx ppEffectCommit 0;

    while {
        missionNamespace getVariable ["KAID_ZeusBlueNVGV2Running",false]
    } do {

        private _cur = getAssignedCuratorLogic player;
        private _useBlue = false;

        if (!isNull curatorCamera && {!isNull _cur}) then {

            private _modes = _cur call BIS_fnc_curatorVisionModes;
            private _index = _cur getVariable ["BIS_fnc_curatorVisionModes_current",0];

            if (_index >= 0 && {_index < count _modes}) then {
                _useBlue = ((_modes select _index) == -2);
            };
        };

        _fx ppEffectEnable _useBlue;

        uiSleep 0.05;
    };

    ppEffectDestroy _fx;
};

missionNamespace setVariable ["KAID_ZeusGlareShieldRunning",false];
missionNamespace setVariable ["KAID_ZeusViewRunning",false];

{
    private _old = missionNamespace getVariable [_x,-1];
    if (_old != -1) then { ppEffectDestroy _old; };
    missionNamespace setVariable [_x,-1];
} forEach ["KAID_ZeusGlareShieldFX","KAID_ZeusClarityFX"];

// ---- Zeus view: while the curator interface is open the Umbara grade is lifted for that client,
//      a mild clarity boost is applied, the glare shield engages only while flares burn,
//      and (optionally) the local fog is thinned. Everything is restored when Zeus closes. ----
[] spawn {

    uiSleep 0.5;

    missionNamespace setVariable ["KAID_ZeusViewRunning",true];

    private _glare = ppEffectCreate ["ColorCorrections",16740];
    // glare shield (darker view while flares burn) is OFF by default since the op-day report that it made the Zeus view much darker;
    // with KAID_Umbara_ZeusGlareShield false the effect is identical to the clarity boost, so the Zeus view is the same with or without flares
    if (missionNamespace getVariable ["KAID_Umbara_ZeusGlareShield",false]) then {
        _glare ppEffectAdjust [0.68,0.88,0.02,[0,0,0,0],[1,1,1,1],[0.299,0.587,0.114,0]];
    } else {
        _glare ppEffectAdjust [1.18,1.03,0.02,[0,0,0,0],[1,1,1,1],[0.299,0.587,0.114,0]];
    };
    _glare ppEffectCommit 0;
    _glare ppEffectEnable false;

    private _clarity = ppEffectCreate ["ColorCorrections",16741];
    _clarity ppEffectAdjust [1.18,1.03,0.02,[0,0,0,0],[1,1,1,1],[0.299,0.587,0.114,0]];
    _clarity ppEffectCommit 0;
    _clarity ppEffectEnable false;

    missionNamespace setVariable ["KAID_ZeusGlareShieldFX",_glare];
    missionNamespace setVariable ["KAID_ZeusClarityFX",_clarity];

    private _inZeus = false;
    private _gradeLifted = false;
    private _lastFogApply = -10;

    while {
        missionNamespace getVariable ["KAID_ZeusViewRunning",false]
    } do {

        private _cur = getAssignedCuratorLogic player;
        private _zeusOpen = !isNull curatorCamera && {!isNull _cur};
        private _normal = false;

        if (_zeusOpen) then {
            if !((_cur call BIS_fnc_curatorVisionModes) isEqualTo [-1,-2]) then {
                [_cur,[-1,-2]] call BIS_fnc_setCuratorVisionModes;
            };
            private _modes = _cur call BIS_fnc_curatorVisionModes;
            private _index = _cur getVariable ["BIS_fnc_curatorVisionModes_current",0];
            if (_index >= 0 && {_index < count _modes}) then {
                _normal = ((_modes select _index) == -1);
            };
        };

        private _cc = missionNamespace getVariable ["KAID_Umbara_CC",-1];
        private _fogBase = missionNamespace getVariable ["KAID_FogBase",0];
        private _fogDecay = missionNamespace getVariable ["KAID_FogDecay",0.017];

        // local fog relief only in Zeus NORMAL view (thin fog + flares white-out the NVG view)
        private _wantRelief = _zeusOpen && {_normal};
        if (_wantRelief && {!_inZeus}) then {
            _inZeus = true;
            if (missionNamespace getVariable ["KAID_Umbara_ZeusFogRelief",true]) then {
                2 setFog [missionNamespace getVariable ["KAID_Umbara_ZeusFog",0.10],_fogDecay,_fogBase];
            };
        };
        if (!_wantRelief && {_inZeus}) then {
            _inZeus = false;
            if (missionNamespace getVariable ["KAID_Umbara_ZeusFogRelief",true]) then {
                2 setFog [missionNamespace getVariable ["KAID_FogGround",0.619047619],_fogDecay,_fogBase];
            };
        };

        if (_inZeus && {missionNamespace getVariable ["KAID_Umbara_ZeusFogRelief",true]} && {time - _lastFogApply > 0.5}) then {
            _lastFogApply = time;
            0 setFog [missionNamespace getVariable ["KAID_Umbara_ZeusFog",0.10],_fogDecay,_fogBase];
        };

        // the Umbara grade is lifted only in Zeus NORMAL view; Zeus NVG keeps it (prevents flare white-out)
        private _liftGrade = _zeusOpen && {_normal};
        if (_liftGrade && {!_gradeLifted}) then {
            _gradeLifted = true;
            if (_cc != -1) then { _cc ppEffectEnable false; };
        };
        if (!_liftGrade && {_gradeLifted}) then {
            _gradeLifted = false;
            if (_cc != -1) then { _cc ppEffectEnable true; };
        };

        private _flares = missionNamespace getVariable ["KAID_LiveFlares",0];

        _glare ppEffectEnable (_zeusOpen && {_normal} && {_flares > 0});
        _clarity ppEffectEnable (_zeusOpen && {_normal} && {_flares == 0});

        uiSleep 0.1;
    };

    ppEffectDestroy _glare;
    ppEffectDestroy _clarity;
    missionNamespace setVariable ["KAID_ZeusGlareShieldFX",-1];
    missionNamespace setVariable ["KAID_ZeusClarityFX",-1];
    private _cc = missionNamespace getVariable ["KAID_Umbara_CC",-1];
    if (_cc != -1) then { _cc ppEffectEnable true; };
};

if !(missionNamespace getVariable ["KAID_PilotViewRunning",false]) then {

    missionNamespace setVariable ["KAID_PilotViewRunning",true];

    [] spawn {

        private _boosted = false;
        private _oldView = viewDistance;
        private _oldObj = getObjectViewDistance;

        while {
            missionNamespace getVariable ["KAID_PilotViewRunning",false]
        } do {

            private _veh = vehicle player;

            private _isPilot =
                (_veh isKindOf "Air") &&
                {driver _veh isEqualTo player};

            if (_isPilot && {!_boosted}) then {

                _oldView = viewDistance;
                _oldObj = getObjectViewDistance;

                setViewDistance 6000;
                setObjectViewDistance [3000,300];

                _boosted = true;
            };

            if (!_isPilot && {_boosted}) then {

                setViewDistance _oldView;
                setObjectViewDistance _oldObj;

                _boosted = false;
            };

            uiSleep 1;
        };

        if (_boosted) then {
            setViewDistance _oldView;
            setObjectViewDistance _oldObj;
        };
    };
};

// ---- ambience: kill ambient birds/animals and the bird/insect sound layers (weather sounds are unaffected) ----
enableEnvironment [false,false];

// ---- ambience bed: plays the mission's CfgSounds "KAID_UmbaraBed" on a loop if the mission ships it ----
missionNamespace setVariable ["KAID_AmbienceRunning",false];

if (isClass (missionConfigFile >> "CfgSounds" >> "KAID_UmbaraBed")) then {
    [] spawn {
        uiSleep 0.5;
        missionNamespace setVariable ["KAID_AmbienceRunning",true];
        private _len = getNumber (missionConfigFile >> "CfgSounds" >> "KAID_UmbaraBed" >> "KAID_length");
        if (_len <= 0) then { _len = 90; };
        while { missionNamespace getVariable ["KAID_AmbienceRunning",false] } do {
            // played on the speech channel so the indoor logic can fade it with fadeSpeech without touching effects or music
            playSound ["KAID_UmbaraBed",true];
            uiSleep (_len - 0.5);
        };
    };
};

// ---- indoors (Acclamator etc.): a placed object's roof overhead => thin the fog locally (KAID_Umbara_IndoorFog) so the
//      halls are clear, and fade the ambience bed out. Restored with a 2 s blend when the roof is gone ----
missionNamespace setVariable ["KAID_IndoorRunning",false];

[] spawn {

    uiSleep 1;

    missionNamespace setVariable ["KAID_IndoorRunning",true];

    private _indoor = false;
    private _lastApply = -10;

    while {
        missionNamespace getVariable ["KAID_IndoorRunning",false]
    } do {

        private _enabled = missionNamespace getVariable ["KAID_Umbara_IndoorLogic",true];
        private _now = false;

        if (_enabled && {alive player} && {isNull curatorCamera}) then {
            private _eye = eyePos player;
            private _hits = lineIntersectsSurfaces [_eye,_eye vectorAdd [0,0,80],player,objNull,true,1,"GEOM","NONE"];
            if !(_hits isEqualTo []) then {
                private _obj = (_hits select 0) select 2;
                // a placed object with a class counts as a roof (ship modules, buildings) UNLESS its class starts with a
                // plant prefix: the Umbara canopy (land_3as_umbara_*) and the Gliese vegetation (egl_*) are terrain objects with classes too
                if (!isNull _obj && {typeOf _obj != ""}) then {
                    private _t = toLower typeOf _obj;
                    private _plant = (missionNamespace getVariable ["KAID_Umbara_NoRoofPrefixes",[]]) findIf { (_t find (toLower _x)) == 0 };
                    _now = _plant < 0;
                };
            };
        };

        if (_now && {!_indoor}) then {
            _indoor = true;
            1 fadeSpeech 0;
        };
        if (!_now && {_indoor}) then {
            _indoor = false;
            1 fadeSpeech 1;
            2 setFog [missionNamespace getVariable ["KAID_FogGround",0.619047619],missionNamespace getVariable ["KAID_FogDecay",0.017],missionNamespace getVariable ["KAID_FogBase",0]];
        };
        if (_indoor && {time - _lastApply > 0.5}) then {
            _lastApply = time;
            0 setFog [missionNamespace getVariable ["KAID_Umbara_IndoorFog",0.12],missionNamespace getVariable ["KAID_FogDecay",0.017],missionNamespace getVariable ["KAID_FogBase",0]];
        };
        missionNamespace setVariable ["KAID_Indoor",_indoor];

        uiSleep 1;
    };

    1 fadeSpeech 1;
};

// ---- infantry NVG block: goggles are unassigned (kept in inventory) unless the player is aircraft crew ----
missionNamespace setVariable ["KAID_NVGBlockRunning",false];

[] spawn {

    uiSleep 0.5;

    missionNamespace setVariable ["KAID_NVGBlockRunning",true];

    private _lastHint = -60;

    while {
        missionNamespace getVariable ["KAID_NVGBlockRunning",false]
    } do {

        private _allowed =
            (missionNamespace getVariable ["KAID_Umbara_AllowAirNVG",true]) &&
            {(vehicle player) isKindOf "Air"} &&
            {(vehicle player) != player};

        if (!_allowed && {alive player}) then {

            private _nvg = hmd player;

            // exemption: the worn item or any of its parent classes is on the exempt list
            private _exempt = false;
            if (_nvg != "") then {
                private _list = (missionNamespace getVariable ["KAID_Umbara_NVGExemptClasses",[]]) apply { toLower _x };
                private _cfg = configFile >> "CfgWeapons" >> _nvg;
                while { isClass _cfg && {!_exempt} } do {
                    if ((toLower configName _cfg) in _list) then { _exempt = true; };
                    _cfg = inheritsFrom _cfg;
                };
            };

            if (_exempt) then {
                // exempt goggles keep NVG; thermal mode (vision 2) is switched off if enabled
                if ((missionNamespace getVariable ["KAID_Umbara_ExemptBlockTI",true]) && {currentVisionMode player == 2}) then {
                    player action ["NVGogglesOff",player];
                    if (time - _lastHint > 20) then {
                        hintSilent "Umbara's atmosphere defeats thermal imaging. Visor thermal mode is off.";
                        _lastHint = time;
                    };
                };
            } else {

                if (currentVisionMode player == 1) then {
                    player action ["NVGogglesOff",player];
                };

                if (_nvg != "" && {currentVisionMode player != 1}) then {

                    player unassignItem _nvg;

                    if (time - _lastHint > 20) then {
                        hintSilent "Umbara's atmosphere scatters NVG light. Goggles are stowed.";
                        _lastHint = time;
                    };
                };
            };
        };

        uiSleep 1;
    };
};

// ---- ground-vehicle thermal block (aircraft keep TI) ----
missionNamespace setVariable ["KAID_TIBlockRunning",false];

[] spawn {

    uiSleep 0.5;

    missionNamespace setVariable ["KAID_TIBlockRunning",true];

    while {
        missionNamespace getVariable ["KAID_TIBlockRunning",false]
    } do {

        if (missionNamespace getVariable ["KAID_Umbara_BlockGroundTI",true]) then {
            {
                if (!(_x isKindOf "Air") && {!(_x getVariable ["KAID_TIBlocked",false])}) then {
                    _x disableTIEquipment true;
                    _x setVariable ["KAID_TIBlocked",true];
                };
            } forEach vehicles;
        };

        uiSleep 5;
    };
};

}] remoteExec ["BIS_fnc_call",[0,-2] select isDedicated,"KAID_UmbaraV4"];
