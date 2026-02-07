#include "\nsm_Main\_include\macros.hpp"

params[
["_normal_text","EH RIP MEMEIFY ERROR",["string"]],
["_meme_text","EH RIP MEMEIFY ERROR",["wordsss"]],
["_chance_to_happen",0,[0]]
];

_chance=random 1;
_textToShow= _normal_text;

if(_chance<_chance_to_happen) then 
{
	_textToShow=_meme_text;
};
[_textToShow, ""] call ace_common_fnc_displayTextPicture;