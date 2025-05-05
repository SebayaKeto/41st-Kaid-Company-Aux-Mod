/*
 * Author: Maldova
 *
 *
 * Arguments:
 * _object
 *
 * Example:
 * call FST_fnc_toggleShield;
 *
 * Return Value:
 * None
 *
 */

params ["_object"];

if (_object getVariable ['Shield_Hidden', false]) then 
{ 
	_object hideSelection 'Shield', false;  // Show
	_object setVariable ['Shield_Hidden', false]; 
}
else
{
	_object hideSelection 'Shield', true; // Hide
	_object setVariable ['Shield_Hidden', true];
};