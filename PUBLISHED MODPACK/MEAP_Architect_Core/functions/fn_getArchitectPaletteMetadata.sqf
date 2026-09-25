params [["_className", "", [""]]];

private _config = configFile >> "CfgVehicles" >> _className;
private _category = getText (_config >> "MEAP_SW_buildCategory");
if (_category isEqualTo "") then
{
    _category = if (_className find "MEAP_SW_Props" == 0) then {"Props"} else
    {
        if (_className find "MEAP_SW_Structures" == 0) then {"Structures"} else {"Vanilla"}
    };
};

private _subcategoryId = getText (_config >> "MEAP_SW_buildSubcategory");
private _subcategoryLabel = _subcategoryId;
if (_subcategoryId isEqualTo "") then
{
    _subcategoryId = getText (_config >> "editorSubcategory");
    _subcategoryLabel = getText (configFile >> "CfgEditorSubcategories" >> _subcategoryId >> "displayName");
};
if (_subcategoryId isEqualTo "") then
{
    _subcategoryId = getText (_config >> "vehicleClass");
};
if (_subcategoryId isEqualTo "") then
{
    _subcategoryId = "Other";
};
if (_subcategoryLabel isEqualTo "") then
{
    _subcategoryLabel = _subcategoryId;
};

[_category, _subcategoryId, _subcategoryLabel]