
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

if ( _depositcount != 0) then
{
private _totalcount = missionNamespace getVariable "FST_TotalIntel";
_totalcount = _totalcount + _depositcount;
missionNamespace setVariable ["FST_TotalIntel", _totalcount]; 
};

if ( _comms != 0) then
{
private _totalcomms = missionNamespace getVariable "FST_SusComm";
_totalcomms = _totalcomms + _comms;
missionNamespace setVariable ["FST_SusComm", _totalcomms]; 
};

if ( _hcomm != 0) then
{
private _totalhcomms = missionNamespace getVariable "FST_SusHComm";
_totalhcomms = _totalhcomms + _hcomm;
missionNamespace setVariable ["FST_SusHComm", _totalhcomms]; 
};

if ( _datacard != 0) then
{
private _totaldatacard = missionNamespace getVariable "FST_SusDatacard";
_totaldatacard = _totaldatacard + _datacard;
missionNamespace setVariable ["FST_SusDatacard", _totaldatacard]; 
};

if ( _datacrystal != 0) then
{
private _totaldatacrystal = missionNamespace getVariable "FST_SusDatacrystal";
_totaldatacrystal = _totaldatacrystal + _datacrystal;
missionNamespace setVariable ["FST_SusDatacrystal", _totaldatacrystal]; 
};

if ( _datapad != 0) then
{
private _totaldatapad = missionNamespace getVariable "FST_SusDatapad";
_totaldatapad = _totaldatapad + _datapad;
missionNamespace setVariable ["FST_SusDatapad", _totaldatapad]; 
};

if ( _sdatapad != 0) then
{
private _totalsdatapad = missionNamespace getVariable "FST_SusSDatapad";
_totalsdatapad = _totalsdatapad + _sdatapad;
missionNamespace setVariable ["FST_SusSDatapad", _totalsdatapad]; 
};

if ( _mdatapad != 0) then
{
private _totalmdatapad = missionNamespace getVariable "FST_SusMDatapad";
_totalmdatapad = _totalmdatapad + _mdatapad;
missionNamespace setVariable ["FST_SusMDatapad", _totalmdatapad]; 
};

if ( _rugdatapad != 0) then
{
private _totalrugdatapad = missionNamespace getVariable "FST_SusRugDatapad";
_totalrugdatapad = _totalrugdatapad + _rugdatapad;
missionNamespace setVariable ["FST_SusRugDatapad", _totalrugdatapad]; 
};

if ( _readdatapad != 0) then
{
private _totalreaddatapad = missionNamespace getVariable "FST_SusReadDatapad";
_totalreaddatapad = _totalreaddatapad + _readdatapad;
missionNamespace setVariable ["FST_SusReadDatapad", _totalreaddatapad]; 
};

if ( _projector != 0) then
{
private _totalprojector = missionNamespace getVariable "FST_SusProjector";
_totalprojector = _totalprojector + _projector;
missionNamespace setVariable ["FST_SusProjector", _totalprojector]; 
};

if ( _bounty != 0) then
{
private _totalbounty = missionNamespace getVariable "FST_SusBounty";
_totalbounty = _totalbounty + _bounty;
missionNamespace setVariable ["FST_SusBounty", _totalbounty]; 
};

if ( _tracking != 0) then
{
private _totaltracking = missionNamespace getVariable "FST_SusTracking";
_totaltracking = _totaltracking + _tracking;
missionNamespace setVariable ["FST_SusTracking", _totaltracking]; 
};

if ( _flimsi != 0) then
{
private _totalflimsi = missionNamespace getVariable "FST_SusFlimsi";
_totalflimsi = _totalflimsi + _flimsi;
missionNamespace setVariable ["FST_SusFlimsi", _totalflimsi]; 
};

if ( _ffolder != 0) then
{
private _totalffolder = missionNamespace getVariable "FST_SusFlimsiFolder";
_totalffolder = _totalffolder + _ffolder;
missionNamespace setVariable ["FST_SusFlimsiFolder", _totalffolder]; 
};

if ( _camtono != 0) then
{
private _totalcamtono = missionNamespace getVariable "FST_SusCamtono";
_totalcamtono = _totalcamtono + _camtono;
missionNamespace setVariable ["FST_SusCamtono", _totalcamtono]; 
};

if ( _thead != 0) then
{
private _totalthead = missionNamespace getVariable "FST_SusTHead";
_totalthead = _totalthead + _thead;
missionNamespace setVariable ["FST_SusTHead", _totalthead]; 
};

if ( _bxchip != 0) then
{
private _totalbxchip = missionNamespace getVariable "FST_SusBXChip";
_totalbxchip = _totalbxchip + _bxchip;
missionNamespace setVariable ["FST_SusBXChip", _totalbxchip]; 
};