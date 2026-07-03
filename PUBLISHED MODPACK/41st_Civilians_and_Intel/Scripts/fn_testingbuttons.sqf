
createDialog "FST_RepairDeviceDialog";
params ["_control"];
				private _repairData = _control getVariable "FST_RepairData";
				_repairData params ["_term", "_user", "_origin", "_error"];
				private _esctxt0 = "<t color='#990000'>You have been electrocuted by the device you were repairing</t>";
				hintSilent parseText _esctxt0;
				_term setVariable ["FST_DeviceInUse",false,true];
				_user setVariable ["FST_PlayerIsMeching",false,true];
				closeDialog 0;
				playSound3D ["a3\missions_f_epa\data\sounds\electricity_loop.wss", _term,false, getPosASL _term,5,1,20];
				[_user, 0.5, "LeftArm",  "plasma"] call ace_medical_fnc_addDamageToUnit;
				[_user, 0.5, "RightArm", "plasma"] call ace_medical_fnc_addDamageToUnit;
				[ _user, true, 3, true] call ace_medical_fnc_setUnconscious;
				_user addForce [ _user vectorModelToWorld [0,-200,700], _user selectionPosition "face"]; 
