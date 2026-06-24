["FST_depositCredits", {
    params ["_credits"];
    private _total = missionNamespace getVariable ["FST_CollectedDeposit", 0];
    _total = _total + _credits;
    missionNamespace setVariable ["FST_CollectedDeposit", _total, true];
}] call CBA_fnc_addEventHandler;

["FST_depositIntel", {
    params ["_intel", "_comms", "_hcomm", "_datacard", "_datacrystal", "_datapad", "_sdatapad", "_mdatapad", "_rugdatapad", "_readdatapad", "_projector", "_bounty", "_tracking", "_flimsi", "_ffolder", "_camtono", "_thead", "_bxchip", "_hackdata"];

if ( _intel != 0) then
{
private _totalintel = missionNamespace getVariable "FST_TotalIntel";
_totalintel = _totalintel + _intel;
missionNamespace setVariable ["FST_TotalIntel", _totalintel, true]; 
};

if ( _comms != 0) then
{
private _totalcomms = missionNamespace getVariable "FST_SusComm";
_totalcomms = _totalcomms + _comms;
missionNamespace setVariable ["FST_SusComm", _totalcomms, true]; 
};

if ( _hcomm != 0) then
{
private _totalhcomms = missionNamespace getVariable "FST_SusHComm";
_totalhcomms = _totalhcomms + _hcomm;
missionNamespace setVariable ["FST_SusHComm", _totalhcomms, true]; 
};

if ( _datacard != 0) then
{
private _totaldatacard = missionNamespace getVariable "FST_SusDatacard";
_totaldatacard = _totaldatacard + _datacard;
missionNamespace setVariable ["FST_SusDatacard", _totaldatacard, true]; 
};

if ( _datacrystal != 0) then
{
private _totaldatacrystal = missionNamespace getVariable "FST_SusDatacrystal";
_totaldatacrystal = _totaldatacrystal + _datacrystal;
missionNamespace setVariable ["FST_SusDatacrystal", _totaldatacrystal, true]; 
};

if ( _datapad != 0) then
{
private _totaldatapad = missionNamespace getVariable "FST_SusDatapad";
_totaldatapad = _totaldatapad + _datapad;
missionNamespace setVariable ["FST_SusDatapad", _totaldatapad, true]; 
};

if ( _sdatapad != 0) then
{
private _totalsdatapad = missionNamespace getVariable "FST_SusSDatapad";
_totalsdatapad = _totalsdatapad + _sdatapad;
missionNamespace setVariable ["FST_SusSDatapad", _totalsdatapad, true]; 
};

if ( _mdatapad != 0) then
{
private _totalmdatapad = missionNamespace getVariable "FST_SusMDatapad";
_totalmdatapad = _totalmdatapad + _mdatapad;
missionNamespace setVariable ["FST_SusMDatapad", _totalmdatapad, true]; 
};

if ( _rugdatapad != 0) then
{
private _totalrugdatapad = missionNamespace getVariable "FST_SusRugDatapad";
_totalrugdatapad = _totalrugdatapad + _rugdatapad;
missionNamespace setVariable ["FST_SusRugDatapad", _totalrugdatapad, true]; 
};

if ( _readdatapad != 0) then
{
private _totalreaddatapad = missionNamespace getVariable "FST_SusReadDatapad";
_totalreaddatapad = _totalreaddatapad + _readdatapad;
missionNamespace setVariable ["FST_SusReadDatapad", _totalreaddatapad, true]; 
};

if ( _projector != 0) then
{
private _totalprojector = missionNamespace getVariable "FST_SusProjector";
_totalprojector = _totalprojector + _projector;
missionNamespace setVariable ["FST_SusProjector", _totalprojector, true]; 
};

if ( _bounty != 0) then
{
private _totalbounty = missionNamespace getVariable "FST_SusBounty";
_totalbounty = _totalbounty + _bounty;
missionNamespace setVariable ["FST_SusBounty", _totalbounty, true]; 
};

if ( _tracking != 0) then
{
private _totaltracking = missionNamespace getVariable "FST_SusTracking";
_totaltracking = _totaltracking + _tracking;
missionNamespace setVariable ["FST_SusTracking", _totaltracking, true]; 
};

if ( _flimsi != 0) then
{
private _totalflimsi = missionNamespace getVariable "FST_SusFlimsi";
_totalflimsi = _totalflimsi + _flimsi;
missionNamespace setVariable ["FST_SusFlimsi", _totalflimsi, true]; 
};

if ( _ffolder != 0) then
{
private _totalffolder = missionNamespace getVariable "FST_SusFlimsiFolder";
_totalffolder = _totalffolder + _ffolder;
missionNamespace setVariable ["FST_SusFlimsiFolder", _totalffolder, true]; 
};

if ( _camtono != 0) then
{
private _totalcamtono = missionNamespace getVariable "FST_SusCamtono";
_totalcamtono = _totalcamtono + _camtono;
missionNamespace setVariable ["FST_SusCamtono", _totalcamtono, true]; 
};

if ( _thead != 0) then
{
private _totalthead = missionNamespace getVariable "FST_SusTHead";
_totalthead = _totalthead + _thead;
missionNamespace setVariable ["FST_SusTHead", _totalthead, true]; 
};

if ( _bxchip != 0) then
{
private _totalbxchip = missionNamespace getVariable "FST_SusBXChip";
_totalbxchip = _totalbxchip + _bxchip;
missionNamespace setVariable ["FST_SusBXChip", _totalbxchip, true]; 
};

if ( _hackdata != 0) then
{
private _totalhackdata = missionNamespace getVariable "FST_HackDatacard";
_totalhackdata = _totalhackdata + _hackdata;
missionNamespace setVariable ["FST_HackDatacard", _totalhackdata, true]; 
};

}] call CBA_fnc_addEventHandler;
