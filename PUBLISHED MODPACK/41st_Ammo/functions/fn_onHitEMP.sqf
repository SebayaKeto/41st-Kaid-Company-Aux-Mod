#define COOLDOWN 2

params ["_target", "_shooter", "_ammo", "_pos"];

if ((getText(configFile >> "CfgAmmo" >> _ammo >> "simulation") != "shotBullet") &&
    ((_pos distance _target) > getNumber(configFile >> "CfgAmmo" >> _ammo >> "indirectHitRange"))) exitWith {};

if (_target getVariable ["FST_EMPCooldown", CBA_missionTime - 1] >= CBA_missionTime) exitWith {};

_target setVariable ["FST_EMPCooldown", CBA_missionTime + COOLDOWN, true];

private _droidekaClasses = ["FST_Droideka", "FST_Sniper_Deka"];
private _toFry = false;
private _isDroideka = false;
private _uniform = "";
private _isDroid = 0;

if (_target isKindOf "CAManBase") then {
	_uniform = uniform _target;
	_isDroid = getNumber(configFile >> "CfgWeapons" >> _uniform >> "JLTS_isDroid");
	private _affectedUniforms = ["JLTS_CloneArmorInfantryMC", "JLTS_CloneArmorReconMC"];
	private _protectedUniforms = ["JLTS_CloneArmorReconMedicMC"];

	if (
		(_isDroid == 1 || _uniform in _affectedUniforms) &&
		!(_uniform in _protectedUniforms)
	) then {
		if (alive _target) then { _toFry = true; };
	};
} else {
	if ((typeOf _target) in _droidekaClasses && {alive _target}) then {
		_toFry = true;
		_isDroideka = true;
	};
};

if (_toFry) then {
    [_target, _isDroideka] spawn {
        params ["_unit", "_isDroideka"];

        if (_isDroideka) then {
            _unit setHitPointDamage ["HitShield", 1];
            _unit animateSource ["ShieldLayer_BaseFront", 1, true];
            _unit setVariable ["ShieldStatus", 0, true];
        } else {           
            private _uniform = uniform _unit;
            private _soundClass = getText(configFile >> "CfgWeapons" >> _uniform >> "JLTS_deathSounds");
            private _sound = if (_soundClass != "") then {
                selectRandom getArray(configFile >> "CfgJLTSDeathSounds" >> _soundClass >> "emp")
            } else {
                selectRandom getArray(configFile >> "CfgJLTSDeathSounds" >> "DeathDroid" >> "emp")
            };
            playSound3D [_sound, _unit, false, getPosASL _unit, 2, 1, 0];
            _unit setDamage 1;
        };

        _unit setVariable ["FST_EMPCooldown", nil, true];
    };
};
