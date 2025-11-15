params ["_object", "_maxCharge", "_chargeRate", "_dischargeRate", "_canDischarge"];

// --- 1. READ ATTRIBUTES AND SET INITIAL STATE ---
private _powerEnabled       = [_object, "MEC_PowerSystem", 0] call BIS_fnc_getParamValue;
private _isSupplier         = [_object, "MEC_PowerSystem_IsSupplier", 0] call BIS_fnc_getParamValue;
private _isConsumer         = [_object, "MEC_PowerSystem_IsConsumer", 0] call BIS_fnc_getParamValue;
private _supplierRadius     = [_object, "MEC_PowerSystem_SupplierRadius", 50] call BIS_fnc_getParamValue;
private _supplierRate       = [_object, "MEC_PowerSystem_SupplierRate", 200] call BIS_fnc_getParamValue;
private _powerType          = [_object, "MEC_PowerSystem_Type", "Battery"] call BIS_fnc_getParamValue;
private _supplierType       = [_object, "MEC_PowerSystem_SupplierType", "FusionCell"] call BIS_fnc_getParamValue;
private _initialCharge      = [_object, "MEC_PowerSystem_InitialCharge", 10000] call BIS_fnc_getParamValue;


// --- 2. SET CORE STATE VARIABLES ---
_object setVariable [format ["%1_Power_Enabled", MEC_TAG_POWERSYSTEM], _powerEnabled, true];
_object setVariable [format ["%1_Charge_Current", MEC_TAG_POWERSYSTEM], _initialCharge, true];
_object setVariable [format ["%1_Charge_Max", MEC_TAG_POWERSYSTEM], _maxCharge, true];
_object setVariable [format ["%1_Charge_Rate", MEC_TAG_POWERSYSTEM], _chargeRate, true];
_object setVariable [format ["%1_Discharge_Rate", MEC_TAG_POWERSYSTEM], _dischargeRate, true];
_object setVariable [format ["%1_Can_Discharge", MEC_TAG_POWERSYSTEM], _canDischarge, true];
_object setVariable [format ["%1_Power_Type", MEC_TAG_POWERSYSTEM], _powerType, true];
_object setVariable [format ["%1_Is_Powered", MEC_TAG_POWERSYSTEM], false, true];

// --- 3. SET SUPPLIER/CONSUMER SPECIFIC VARIABLES ---
if (_isSupplier == 1) then {
    _object setVariable [format ["%1_Is_Supplier", MEC_TAG_POWERSYSTEM], true, true];
    _object setVariable [format ["%1_Supplier_Radius", MEC_TAG_POWERSYSTEM], _supplierRadius, true];
    _object setVariable [format ["%1_Supplier_Rate", MEC_TAG_POWERSYSTEM], _supplierRate, true];
    _object setVariable [format ["%1_Supplier_Type", MEC_TAG_POWERSYSTEM], _supplierType, true];
} else {
    _object setVariable [format ["%1_Is_Supplier", MEC_TAG_POWERSYSTEM], false, true];
};

_object;
