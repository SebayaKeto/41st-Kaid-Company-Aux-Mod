// Authoritative only for locally controlled task fields. Other inputs stay public.
params ["_space","_args"];
private _key=if (_args isEqualType []) then {_args select 0} else {_args};
private _cache=if (_space isEqualType grpNull && {local _space}) then {_space getVariable ["BURNS_ownerTaskState",createHashMap]} else {createHashMap};
private _row=_cache getOrDefault [_key,[]];
if (count _row>0) exitWith {
    if (_row select 0) then {_row select 1} else {
        if (_args isEqualType [] && {count _args>1}) then {_args select 1} else {nil}
    }
};
_space getVariable _args
