// Point-in-area test (rectangle/ellipse, honors rotation)
// [px, py, cx0, cy0, a, b, angle, isRect] -> BOOL

params ["_px", "_py", "_cx0", "_cy0", "_a", "_b", "_angle", "_isRect"];

private _dx = _px - _cx0;
private _dy = _py - _cy0;
private _ca = cos(-_angle);
private _sa = sin(-_angle);
private _rx = (_dx * _ca) - (_dy * _sa);
private _ry = (_dx * _sa) + (_dy * _ca);

if (_isRect) then {
	(abs _rx <= _a) && (abs _ry <= _b)
} else {
	(((_rx / _a) * (_rx / _a)) + ((_ry / _b) * (_ry / _b))) <= 1
}
