localNamespace setVariable ["stonewall_code", (localNamespace getVariable ["stonewall_code", ""]) + "if !(_opts isEqualType createHashMap) then { _opts = createHashMap; };
private _scope = _args param [0, _opts getOrDefault [""scope"", ""all""]];
if !(_scope in [""all"", ""areas""]) then { _scope = ""all""; };
private _owners = [];
if (_req > 2) then { _owners pushBackUnique _req; };
{
private _u = getAssignedCuratorUnit _x;
if (!isNull _u && {isPlayer _u} && {owner _u > 2}) then { _owners pushBackUnique (owner _u); };
} forEach allCurators;
private _reqInfo = format [""req=%1|reqAdmin=%2|reqRemote=%3"", _req, [-1, admin _req] select (_req > 2), isRemoteExecuted];
[_owners, _scope, _opts, _lockId, _reqInfo] spawn {
params [""_owners"", ""_scope"", ""_opts"", ""_lockId"", ""_reqInfo""];
private _margin = _opts getOrDefault [""margin"", 15];
private _zenAreas = _opts getOrDefault [""zenAreas"", missionNamespace getVariable [""FST_stonewall_zenAreas"", true]];
private _daidVars = [];
"];
