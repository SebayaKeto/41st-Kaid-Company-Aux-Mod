
_this addAction ['Hack Device', {[_this select 0, _this select 1, _this select 2] call FST_CivilRandomizers_fnc_hackingterminal;}, nil,6,true,true,"","true",3];
_this addAction ['Repair Device', {[_this select 0, _this select 1, _this select 2] call FST_CivilRandomizers_fnc_hackingterminal;}, nil,6,true,true,"","true",3];

_this setVariable ["FST_DeviceHacked",false,true];
_this setVariable ["FST_DeviceBroken",true,true];


[_this,['Hack Device', {[_this select 0, _this select 1, _this select 2] call FST_CivilRandomizers_fnc_hackingterminal;}, nil,6,true,true,"","true",3]] remoteExec ["addAction", 0, true];

[_this,['Repair Device', {[_this select 0, _this select 1, _this select 2] call FST_CivilRandomizers_fnc_hackingterminal;}, nil,6,true,true,"","true",3]] remoteExec ["addAction", 0, true];
_this setVariable ["FST_DeviceBroken",true,true];


/* #Xodyqy
$[
	1.063,
	["RepairGUI",[["(safeZoneX + (safeZoneW - ((safeZoneW / safeZoneH) min 1.2)) / 2)","(safeZoneY + (safeZoneH - (((safeZoneW / safeZoneH) min 1.2) / 1.2)) / 2)","((safeZoneW / safeZoneH) min 1.2)","(((safeZoneW / safeZoneH) min 1.2) / 1.2)"],"(((safeZoneW / safeZoneH) min 1.2) / 40)","((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25)","GUI_GRID_CENTER"],0,0,0],
	[-1000,"ButtonBackground",[2,"",["11.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X","3.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y","16 * GUI_GRID_CENTER_W","19.5 * GUI_GRID_CENTER_H"],[-1,-1,-1,-1],[0,0,0,0.8],[-1,-1,-1,-1],"","-1"],[]],
	[-1600,"FST_BtnDecorrupt",[2,"DECORRUPT DRIVES",["12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X","4 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y","14 * GUI_GRID_CENTER_W","1 * GUI_GRID_CENTER_H"],[1,1,1,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[-1601,"FST_BtnDefragment",[2,"DEFRAGMENT DRIVES",["12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X","5.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y","14 * GUI_GRID_CENTER_W","1 * GUI_GRID_CENTER_H"],[1,1,1,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[-1602,"FST_BtnDatalink",[2,"REPAIR DATALINK",["12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X","7 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y","14 * GUI_GRID_CENTER_W","1 * GUI_GRID_CENTER_H"],[1,1,1,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[-1603,"FST_BtnPSU",[2,"REPAIR PSU",["12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X","8.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y","14 * GUI_GRID_CENTER_W","1 * GUI_GRID_CENTER_H"],[1,1,1,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[-1604,"FST_BtnCPU",[2,"REPAIR CPU",["12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X","10 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y","14 * GUI_GRID_CENTER_W","1 * GUI_GRID_CENTER_H"],[1,1,1,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[-1605,"FST_BtnFuses",[2,"REPLACE FUSES",["12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X","11.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y","14 * GUI_GRID_CENTER_W","1 * GUI_GRID_CENTER_H"],[1,1,1,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[-1606,"FST_BtnCapacitors",[2,"REPLACE CAPACITORS",["12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X","13 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y","14 * GUI_GRID_CENTER_W","1 * GUI_GRID_CENTER_H"],[1,1,1,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[-1607,"FST_BtnRestart",[2,"RESTART DEVICE",["12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X","14.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y","14 * GUI_GRID_CENTER_W","1 * GUI_GRID_CENTER_H"],[1,1,1,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[-1608,"FST_BtnBypassCircuit",[2,"BYPASS SUSPECTED DAMAGED CIRCUITRY",["12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X","16 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y","14 * GUI_GRID_CENTER_W","1 * GUI_GRID_CENTER_H"],[1,1,1,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[-1609,"FST_BtnHotwire",[2,"HOTWIRE",["12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X","17.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y","14 * GUI_GRID_CENTER_W","1 * GUI_GRID_CENTER_H"],[1,1,1,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[-1610,"FST_BtnSmack",[2,"PERFORM PERCUSSIVE MAINTENANCE",["12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X","19 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y","14 * GUI_GRID_CENTER_W","1 * GUI_GRID_CENTER_H"],[1,1,1,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[-1611,"FST_BtnDeviceCancel",[2,"CANCEL",["12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X","21.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y","14 * GUI_GRID_CENTER_W","1 * GUI_GRID_CENTER_H"],[1,1,1,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[-1001,"DiagnosisBackground",[2,"",["2 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X","9 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y","9 * GUI_GRID_CENTER_W","6 * GUI_GRID_CENTER_H"],[-1,-1,-1,-1],[0.459,0,0,0.8],[-1,-1,-1,-1],"","-1"],[]],
	[-1002,"AttemptBackground",[2,"",["28 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X","9 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y","9 * GUI_GRID_CENTER_W","6 * GUI_GRID_CENTER_H"],[-1,-1,-1,-1],[0,0.459,0,0.8],[-1,-1,-1,-1],"","-1"],[]],
	[-1100,"DiagosisText",[2,"",["2.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X","9.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y","8 * GUI_GRID_CENTER_W","5 * GUI_GRID_CENTER_H"],[0,0,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[-1101,"AttemptText",[2,"",["28.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X","9.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y","8 * GUI_GRID_CENTER_W","5 * GUI_GRID_CENTER_H"],[0,0,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1003,"DiagnosisTextTitle",[2,"DIAGNOSTIC RESULT:",["2 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X","6.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y","9 * GUI_GRID_CENTER_W","2 * GUI_GRID_CENTER_H"],[-1,-1,-1,-1],[0,0,0,0.8],[-1,-1,-1,-1],"","-1"],[]],
	[1004,"RepairTextTitle",[2,"REPAIR RESULT:",["28 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X","6.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y","9 * GUI_GRID_CENTER_W","2 * GUI_GRID_CENTER_H"],[-1,-1,-1,-1],[0,0,0,0.8],[-1,-1,-1,-1],"","-1"],[]]
]
*/

////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by LCDR A. Rakha (Tooka), v1.063, #Xodyqy)
////////////////////////////////////////////////////////

class ButtonBackground: RscText
{
	idc = 1000;
	x = 11.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
	y = 3.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
	w = 16 * GUI_GRID_CENTER_W;
	h = 19.5 * GUI_GRID_CENTER_H;
	colorBackground[] = {0,0,0,0.8};
};
class FST_BtnDecorrupt: RscButton
{
	idc = 1600;
	text = "DECORRUPT DRIVES"; //--- ToDo: Localize;
	x = 12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
	y = 4 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
	w = 14 * GUI_GRID_CENTER_W;
	h = 1 * GUI_GRID_CENTER_H;
	colorText[] = {1,1,1,1};
};
class FST_BtnDefragment: RscButton
{
	idc = 1601;
	text = "DEFRAGMENT DRIVES"; //--- ToDo: Localize;
	x = 12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
	y = 5.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
	w = 14 * GUI_GRID_CENTER_W;
	h = 1 * GUI_GRID_CENTER_H;
	colorText[] = {1,1,1,1};
};
class FST_BtnDatalink: RscButton
{
	idc = 1602;
	text = "REPAIR DATALINK"; //--- ToDo: Localize;
	x = 12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
	y = 7 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
	w = 14 * GUI_GRID_CENTER_W;
	h = 1 * GUI_GRID_CENTER_H;
	colorText[] = {1,1,1,1};
};
class FST_BtnPSU: RscButton
{
	idc = 1603;
	text = "REPAIR PSU"; //--- ToDo: Localize;
	x = 12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
	y = 8.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
	w = 14 * GUI_GRID_CENTER_W;
	h = 1 * GUI_GRID_CENTER_H;
	colorText[] = {1,1,1,1};
};
class FST_BtnCPU: RscButton
{
	idc = 1604;
	text = "REPAIR CPU"; //--- ToDo: Localize;
	x = 12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
	y = 10 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
	w = 14 * GUI_GRID_CENTER_W;
	h = 1 * GUI_GRID_CENTER_H;
	colorText[] = {1,1,1,1};
};
class FST_BtnFuses: RscButton
{
	idc = 1605;
	text = "REPLACE FUSES"; //--- ToDo: Localize;
	x = 12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
	y = 11.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
	w = 14 * GUI_GRID_CENTER_W;
	h = 1 * GUI_GRID_CENTER_H;
	colorText[] = {1,1,1,1};
};
class FST_BtnCapacitors: RscButton
{
	idc = 1606;
	text = "REPLACE CAPACITORS"; //--- ToDo: Localize;
	x = 12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
	y = 13 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
	w = 14 * GUI_GRID_CENTER_W;
	h = 1 * GUI_GRID_CENTER_H;
	colorText[] = {1,1,1,1};
};
class FST_BtnRestart: RscButton
{
	idc = 1607;
	text = "RESTART DEVICE"; //--- ToDo: Localize;
	x = 12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
	y = 14.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
	w = 14 * GUI_GRID_CENTER_W;
	h = 1 * GUI_GRID_CENTER_H;
	colorText[] = {1,1,1,1};
};
class FST_BtnBypassCircuit: RscButton
{
	idc = 1608;
	text = "BYPASS SUSPECTED DAMAGED CIRCUITRY"; //--- ToDo: Localize;
	x = 12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
	y = 16 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
	w = 14 * GUI_GRID_CENTER_W;
	h = 1 * GUI_GRID_CENTER_H;
	colorText[] = {1,1,1,1};
};
class FST_BtnHotwire: RscButton
{
	idc = 1609;
	text = "HOTWIRE"; //--- ToDo: Localize;
	x = 12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
	y = 17.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
	w = 14 * GUI_GRID_CENTER_W;
	h = 1 * GUI_GRID_CENTER_H;
	colorText[] = {1,1,1,1};
};
class FST_BtnSmack: RscButton
{
	idc = 1610;
	text = "PERFORM PERCUSSIVE MAINTENANCE"; //--- ToDo: Localize;
	x = 12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
	y = 19 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
	w = 14 * GUI_GRID_CENTER_W;
	h = 1 * GUI_GRID_CENTER_H;
	colorText[] = {1,1,1,1};
};
class FST_BtnDeviceCancel: RscButton
{
	idc = 1611;
	text = "CANCEL"; //--- ToDo: Localize;
	x = 12.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
	y = 21.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
	w = 14 * GUI_GRID_CENTER_W;
	h = 1 * GUI_GRID_CENTER_H;
	colorText[] = {1,1,1,1};
};
class DiagnosisBackground: RscText
{
	idc = 1001;
	x = 2 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
	y = 9 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
	w = 9 * GUI_GRID_CENTER_W;
	h = 6 * GUI_GRID_CENTER_H;
	colorBackground[] = {0.459,0,0,0.8};
};
class AttemptBackground: RscText
{
	idc = 1002;
	x = 28 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
	y = 9 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
	w = 9 * GUI_GRID_CENTER_W;
	h = 6 * GUI_GRID_CENTER_H;
	colorBackground[] = {0,0.459,0,0.8};
};
class DiagosisText: RscStructuredText
{
	idc = 1100;
	x = 2.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
	y = 9.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
	w = 8 * GUI_GRID_CENTER_W;
	h = 5 * GUI_GRID_CENTER_H;
	colorText[] = {0,0,0,1};
};
class AttemptText: RscStructuredText
{
	idc = 1101;
	x = 28.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
	y = 9.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
	w = 8 * GUI_GRID_CENTER_W;
	h = 5 * GUI_GRID_CENTER_H;
	colorText[] = {0,0,0,1};
};
class DiagnosisTextTitle: RscText
{
	idc = 1003;
	text = "DIAGNOSTIC RESULT:"; //--- ToDo: Localize;
	x = 2 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
	y = 6.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
	w = 9 * GUI_GRID_CENTER_W;
	h = 2 * GUI_GRID_CENTER_H;
	colorBackground[] = {0,0,0,0.8};
};
class RepairTextTitle: RscText
{
	idc = 1004;
	text = "REPAIR RESULT:"; //--- ToDo: Localize;
	x = 28 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
	y = 6.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
	w = 9 * GUI_GRID_CENTER_W;
	h = 2 * GUI_GRID_CENTER_H;
	colorBackground[] = {0,0,0,0.8};
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////



				0		"You have no clue what is wrong with it.",
				1		"The device is throwing error codes at you.",
				2		"The device is extremely sluggish.",
				3		"It only shows the BIOS screen.",
				4		"The device refuses to connect to anything.",
				5		"The lights and displays are flickering on and off and the device fails to stay on repeatedly.",
				6		"The device is frozen. Not the cold kind of frozen, the ""It's not doing anything."" kind of frozen.",
				7		"You smell burning electronics from inside it.",
				8		"Several parts appear blackened inside.",
				9		"There is a blaster hole in it.",
				10		"It will not turn on.",
				11		"One of the parts inside is radiating intense heat."

