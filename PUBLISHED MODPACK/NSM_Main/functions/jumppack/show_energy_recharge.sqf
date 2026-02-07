#include "\nsm_Main\_include\macros.hpp"

params["_curr_energy","_new_energy","_total_energy"];
_old_ratio=_curr_energy/_total_energy;
_new_ratio=_new_energy/_total_energy;

_result=false;
_thres=0;
_threshold_list = [
	0.05,0.1,0.15,
	0.2,0.25,0.3,
	0.35,0.4,0.45,
	0.5,0.55,0.6,
	0.65,0.7,0.75,
	0.8,0.85,0.9,
	0.95,1
];
_thres_color="#FFFFFF";
_threshold_color_list = [
	"#FF0000","#FF1500","#FF2500",
	"#FF3500","#FF4500","#FF5500",
	"#FF6500","#FF7500","#FF8500",
	"#FF9500","#FFA500","#FFB500",
	"#fff200","#aaff00","#99ff00",
	"#88ff00","#55ff00","#33ff00",
	"#11ff00","#00FFFF"
];

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
} foreach _threshold_list;


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