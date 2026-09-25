// A short-range visual check, never a terrain-object enumeration or wall reveal.
// Used only by the opt-in low-visibility mission aid.
params ["_observer","_target",["_range",125]];
if (isNull _observer || {isNull _target} || {!alive _observer} || {!alive _target} || {!local _observer}) exitWith {false};
if (_observer distance _target>_range || {captive _target}) exitWith {false};
private _bearing=abs ((((_observer getDir _target)-(getDir _observer)+540) mod 360)-180);
if (_bearing>70) exitWith {false};
([vehicle _observer,"VIEW",vehicle _target] checkVisibility [eyePos _observer,aimPos _target])>0.5
