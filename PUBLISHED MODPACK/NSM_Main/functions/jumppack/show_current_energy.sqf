#include "\nsm_Main\_include\macros.hpp"

params["_curr_energy","_total_energy"];

if(_total_energy<=0) exitWith {};
if(_curr_energy<0) exitWith {};

_energy_ratio=_curr_energy/_total_energy;

_thres_color="#800080";

[
	format[
		"Energy Left: <t color='%5'>%1</t>/%2" +"<br />"+ "Percent: <t color='%5'>%3%4</t>",
		_curr_energy,_total_energy,
		_energy_ratio*100,
		"%",
		_thres_color
	], 
	""
] call ace_common_fnc_displayTextPicture;