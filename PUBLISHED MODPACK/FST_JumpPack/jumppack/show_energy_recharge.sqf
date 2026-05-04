

params["_curr_energy","_new_energy","_total_energy"];
if (_total_energy <= 0) exitWith {};

private _old_ratio = _curr_energy / _total_energy;
private _new_ratio = _new_energy / _total_energy;

private _result = false;
private _thres = 0;
private _threshold_list = [.125,.25,.375,.5,.625,.75,.875,1];
private _thres_color = "#FFFFFF";
private _threshold_color_list = ["#FF0000","#FF4500","#FF8500","#FFA500","#fff200","#aaff00","#55ff00","#00FFFF"];

if(count _threshold_color_list != count _threshold_list) then 
{
	[
		format[
			"Energy: <t color='%5'>%1</t>/%2" +"<br />"+ "Percent: <t color='%5'>%3%4</t>",
			_new_energy,
			_total_energy,
			'X',
			"%",
			'#FF0000'
		], 
		""
	] call ace_common_fnc_displayTextPicture;
};

{
	if(_old_ratio<_x && _new_ratio>=_x) then {
			_result=true;
			_thres=_x;
			_thres_color= _threshold_color_list select _forEachIndex;
	};
}foreach _threshold_list;


if(!_result) exitwith {};

[
	format[
		"Energy: <t color='%5'>%1</t>/%2" +"<br />"+ "Percent: <t color='%5'>%3%4</t>",
		_new_energy,
		_total_energy,
		_thres*100,
		"%",
		_thres_color
	],
	""
] call ace_common_fnc_displayTextPicture;