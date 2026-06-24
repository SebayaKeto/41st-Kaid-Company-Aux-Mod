
params ["_target", "_player"];

if !(missionNamespace getVariable ["FST_IntelInitialized", false]) then 
{
    missionNamespace setVariable ["FST_IntelInitialized", true, true];
    missionNamespace setVariable ["FST_TotalIntel", 0, true];
    missionNamespace setVariable ["FST_SusComm", 0, true];
    missionNamespace setVariable ["FST_SusHComm", 0, true];
    missionNamespace setVariable ["FST_SusDatacard", 0, true];
    missionNamespace setVariable ["FST_SusDatacrystal", 0, true];
    missionNamespace setVariable ["FST_SusDatapad", 0, true];
    missionNamespace setVariable ["FST_SusSDatapad", 0, true];
    missionNamespace setVariable ["FST_SusMDatapad", 0, true];
    missionNamespace setVariable ["FST_SusRugDatapad", 0, true];
    missionNamespace setVariable ["FST_SusReadDatapad", 0, true];
    missionNamespace setVariable ["FST_SusProjector", 0, true];
    missionNamespace setVariable ["FST_SusBounty", 0, true];
    missionNamespace setVariable ["FST_SusTracking", 0, true];
    missionNamespace setVariable ["FST_SusFlimsi", 0, true];
    missionNamespace setVariable ["FST_SusFlimsiFolder", 0, true];
    missionNamespace setVariable ["FST_SusCamtono", 0, true];
    missionNamespace setVariable ["FST_SusTHead", 0, true];
    missionNamespace setVariable ["FST_SusBXChip", 0, true];
    missionNamespace setVariable ["FST_HackDatacard", 0, true];
};

private _depositcount = 0;
private _comms = 0;
private _hcomm = 0;
private _datacard = 0;
private _datacrystal = 0;
private _datapad = 0;
private _sdatapad = 0;
private _mdatapad = 0;
private _rugdatapad = 0;
private _readdatapad = 0;
private _projector = 0;
private _bounty = 0;
private _tracking = 0;
private _flimsi = 0;
private _ffolder = 0;
private _camtono = 0;
private _thead = 0;
private _bxchip = 0;
private _hackdata = 0;

while {"FST_FlatComm_Abnormal" in items _player} do 
{
    _player removeItem "FST_FlatComm_Abnormal";
    _depositcount = _depositcount + 1;
    _comms = _comms + 1;
};

while {"FST_HandComm_Abnormal" in items _player} do 
{
    _player removeItem "FST_HandComm_Abnormal";
    _depositcount = _depositcount + 1;
    _comms = _comms + 1;
};

while {"FST_HoloComm_Abnormal" in items _player} do 
{
    _player removeItem "FST_HoloComm_Abnormal";
    _depositcount = _depositcount + 1;
    _hcomm = _hcomm + 1;
};

while {"FST_CivDatacard_Abnormal" in items _player} do 
{
    _player removeItem "FST_CivDatacard_Abnormal";
    _depositcount = _depositcount + 1;
    _datacard = _datacard + 1;
};

while {"FST_CivDataCrystal_Abnormal" in items _player} do 
{
    _player removeItem "FST_CivDataCrystal_Abnormal";
    _depositcount = _depositcount + 1;
    _datacrystal = _datacrystal + 1;
};

while {"FST_CivData_Abnormal" in items _player} do 
{
    _player removeItem "FST_CivData_Abnormal";
    _depositcount = _depositcount + 1;
    _datapad = _datapad + 1;
};

while {"FST_StylusData_Abnormal" in items _player} do 
{
    _player removeItem "FST_StylusData_Abnormal";
    _depositcount = _depositcount + 1;
    _sdatapad = _sdatapad + 1;
};

while {"FST_CivMiniData_Abnormal" in items _player} do 
{
    _player removeItem "FST_CivMiniData_Abnormal";
    _depositcount = _depositcount + 1;
    _mdatapad = _mdatapad + 1;
};

while {"FST_SpaceData_Abnormal" in items _player} do 
{
    _player removeItem "FST_SpaceData_Abnormal";
    _depositcount = _depositcount + 1;
    _rugdatapad = _rugdatapad + 1;
};

while {"FST_ReadData_Abnormal" in items _player} do 
{
    _player removeItem "FST_ReadData_Abnormal";
    _depositcount = _depositcount + 1;
    _readdatapad = _readdatapad + 1;
};

while {"FST_CivHoloprojector_Abnormal" in items _player} do 
{
    _player removeItem "FST_CivHoloprojector_Abnormal";
    _depositcount = _depositcount + 1;
    _projector = _projector + 1;
};

while {"FST_BountyDisk_Abnormal" in items _player} do 
{
    _player removeItem "FST_BountyDisk_Abnormal";
    _depositcount = _depositcount + 1;
    _bounty = _bounty + 1;
};

while {"FST_TrackingFob_Abnormal" in items _player} do 
{
    _player removeItem "FST_TrackingFob_Abnormal";
    _depositcount = _depositcount + 1;
    _tracking = _tracking + 1;
};

while {"FST_CivFlimsi_Abnormal" in items _player} do 
{
    _player removeItem "FST_CivFlimsi_Abnormal";
    _depositcount = _depositcount + 1;
    _flimsi = _flimsi + 1;
};

while {"FST_CivFlimsiFile_Abnormal" in items _player} do 
{
    _player removeItem "FST_CivFlimsiFile_Abnormal";
    _depositcount = _depositcount + 1;
    _ffolder = _ffolder + 1;
};

while {"FST_Camtono_Suspicious" in items _player} do 
{
    _player removeItem "FST_Camtono_Suspicious";
    _depositcount = _depositcount + 1;
    _camtono = _camtono + 1;
};

while {"FST_TSeriesHead" in items _player} do 
{
    _player removeItem "FST_TSeriesHead";
    _depositcount = _depositcount + 1;
    _thead = _thead + 1;
};

while {"FST_BXChip" in items _player} do 
{
    _player removeItem "FST_BXChip";
    _depositcount = _depositcount + 1;
    _bxchip = _bxchip + 1;
};

while {"FST_HackDatacard_Abnormal" in items _player} do 
{
    _player removeItem "FST_HackDatacard_Abnormal";
    _depositcount = _depositcount + 1;
    _hackdata = _hackdata + 1;
};

private _text = "";

if ( _depositcount != 0 ) then 
{
    _text = "<t color='#7ebd00'>You have stored your usable intel!</t>";
    hintSilent parseText _text;
    ["FST_depositIntel", [_depositcount, _comms, _hcomm, _datacard, _datacrystal, _datapad, _sdatapad, _mdatapad, _rugdatapad, _readdatapad, _projector, _bounty, _tracking, _flimsi, _ffolder, _camtono, _thead, _bxchip, _hackdata]] call CBA_fnc_serverEvent;
};

if ( _depositcount == 0 ) then 
{
    _text = "<t color='#990000'>You do not have anything usable to store.</t>";
    hintSilent parseText _text;
};