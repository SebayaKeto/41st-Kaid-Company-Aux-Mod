localNamespace setVariable ["stonewall_code", (localNamespace getVariable ["stonewall_code", ""]) + "private _sid = format [""%1%2%3T%4%5%6-%7"", _d#0, _d#1, _d#2, _d#3, _d#4, _d#5, floor random 10000];
private _pre = ""STONEWALL|"" + _sid + ""|"";
private _toCallers = [];
private _emit = {
params [""_line"", ""_share""];
diag_log text (_pre + _line);
if (_share) then { _toCallers pushBack (_pre + _line); };
};
[format [""H|v=1.2.4|world=%1|mission=%2|briefing=%3|time=%4|serverTime=%5|scope=%6|margin=%7|players=%8|addon=%9|%10"",
worldName, missionName, briefingName call _clean, time toFixed 1, serverTime toFixed 1, _scope, _margin,
count allPlayers, [0, 1] select _cba, _reqInfo], true] call _emit;
private _areas = [];
{
private _m = _x;
private _nameL = toLower _m;
private _text = markerText _m;
private _kind = """";
if (_nameL find ""stonewall_keep"" == 0) then { _kind = ""stonewall""; };
if (_kind == """" && {_zenAreas} && {_nameL find ""zen_area_markers_"" == 0}) then { _kind = ""zen""; };
"];
