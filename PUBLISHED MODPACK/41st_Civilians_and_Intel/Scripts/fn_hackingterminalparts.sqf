    
["FST_setGridRelations", {
    params ["_display","_difficulty"];

    if ( _difficulty == 0) then
    {
        (_display displayCtrl 1700) setVariable ["FST_ButtonRelations",[1701,1705,1706]];
        (_display displayCtrl 1701) setVariable ["FST_ButtonRelations",[1700,1702,1705,1706,1707]];
        (_display displayCtrl 1702) setVariable ["FST_ButtonRelations",[1701,1703,1706,1707,1708]];
        (_display displayCtrl 1703) setVariable ["FST_ButtonRelations",[1702,1704,1707,1708,1709]];
        (_display displayCtrl 1704) setVariable ["FST_ButtonRelations",[1703,1708,1709]];
        (_display displayCtrl 1705) setVariable ["FST_ButtonRelations",[1700,1701,1706,1710,1711]];
        (_display displayCtrl 1706) setVariable ["FST_ButtonRelations",[1700,1701,1702,1705,1707,1710,1711,1712]];
        (_display displayCtrl 1707) setVariable ["FST_ButtonRelations",[1701,1702,1703,1706,1708,1711,1712,1713]];
        (_display displayCtrl 1708) setVariable ["FST_ButtonRelations",[1702,1703,1704,1707,1709,1712,1713,1714]];
        (_display displayCtrl 1709) setVariable ["FST_ButtonRelations",[1703,1704,1708,1713,1714]];
        (_display displayCtrl 1710) setVariable ["FST_ButtonRelations",[1705,1706,1711,1715,1716]];
        (_display displayCtrl 1711) setVariable ["FST_ButtonRelations",[1705,1706,1707,1710,1712,1715,1716,1717]];
        (_display displayCtrl 1712) setVariable ["FST_ButtonRelations",[1706,1707,1708,1711,1713,1716,1717,1718]];
        (_display displayCtrl 1713) setVariable ["FST_ButtonRelations",[1707,1708,1709,1712,1714,1717,1718,1719]];
        (_display displayCtrl 1714) setVariable ["FST_ButtonRelations",[1708,1709,1713,1718,1719]];
        (_display displayCtrl 1715) setVariable ["FST_ButtonRelations",[1710,1711,1716,1720,1721]];
        (_display displayCtrl 1716) setVariable ["FST_ButtonRelations",[1710,1711,1712,1715,1717,1720,1721,1722]];
        (_display displayCtrl 1717) setVariable ["FST_ButtonRelations",[1711,1712,1713,1716,1718,1721,1722,1723]];
        (_display displayCtrl 1718) setVariable ["FST_ButtonRelations",[1712,1713,1714,1717,1719,1722,1723,1724]];
        (_display displayCtrl 1719) setVariable ["FST_ButtonRelations",[1713,1714,1718,1723,1724]];
        (_display displayCtrl 1720) setVariable ["FST_ButtonRelations",[1715,1716,1721]];
        (_display displayCtrl 1721) setVariable ["FST_ButtonRelations",[1715,1716,1717,1720,1722]];
        (_display displayCtrl 1722) setVariable ["FST_ButtonRelations",[1716,1717,1718,1721,1723]];
        (_display displayCtrl 1723) setVariable ["FST_ButtonRelations",[1717,1718,1719,1722,1724]];
        (_display displayCtrl 1724) setVariable ["FST_ButtonRelations",[1718,1719,1723]];
    };
    if ( _difficulty == 1) then
    {
        (_display displayCtrl 1700) setVariable ["FST_ButtonRelations",[1725,1726,1727,1732,1701,1734,1705,1706]];
        (_display displayCtrl 1701) setVariable ["FST_ButtonRelations",[1726,1727,1728,1700,1702,1705,1706,1707]];
        (_display displayCtrl 1702) setVariable ["FST_ButtonRelations",[1727,1728,1729,1701,1703,1706,1707,1708]];
        (_display displayCtrl 1703) setVariable ["FST_ButtonRelations",[1728,1729,1730,1702,1704,1707,1708,1709]];
        (_display displayCtrl 1704) setVariable ["FST_ButtonRelations",[1729,1730,1731,1703,1733,1708,1709,1735]];
        (_display displayCtrl 1705) setVariable ["FST_ButtonRelations",[1732,1700,1701,1734,1706,1736,1710,1711]];
        (_display displayCtrl 1706) setVariable ["FST_ButtonRelations",[1700,1701,1702,1705,1707,1710,1711,1712]];
        (_display displayCtrl 1707) setVariable ["FST_ButtonRelations",[1701,1702,1703,1706,1708,1711,1712,1713]];
        (_display displayCtrl 1708) setVariable ["FST_ButtonRelations",[1702,1703,1704,1707,1709,1712,1713,1714]];
        (_display displayCtrl 1709) setVariable ["FST_ButtonRelations",[1703,1704,1733,1708,1735,1713,1714,1737]];
        (_display displayCtrl 1710) setVariable ["FST_ButtonRelations",[1734,1705,1706,1736,1711,1738,1715,1716]];
        (_display displayCtrl 1711) setVariable ["FST_ButtonRelations",[1705,1706,1707,1710,1712,1715,1716,1717]];
        (_display displayCtrl 1712) setVariable ["FST_ButtonRelations",[1706,1707,1708,1711,1713,1716,1717,1718]];
        (_display displayCtrl 1713) setVariable ["FST_ButtonRelations",[1707,1708,1709,1712,1714,1717,1718,1719]];
        (_display displayCtrl 1714) setVariable ["FST_ButtonRelations",[1708,1709,1735,1713,1737,1718,1719,1739]];
        (_display displayCtrl 1715) setVariable ["FST_ButtonRelations",[1736,1710,1711,1738,1716,1740,1720,1721]];
        (_display displayCtrl 1716) setVariable ["FST_ButtonRelations",[1710,1711,1712,1715,1717,1720,1721,1722]];
        (_display displayCtrl 1717) setVariable ["FST_ButtonRelations",[1711,1712,1713,1716,1718,1721,1722,1723]];
        (_display displayCtrl 1718) setVariable ["FST_ButtonRelations",[1712,1713,1714,1717,1719,1722,1723,1724]];
        (_display displayCtrl 1719) setVariable ["FST_ButtonRelations",[1713,1714,1737,1718,1739,1723,1724,1741]];
        (_display displayCtrl 1720) setVariable ["FST_ButtonRelations",[1738,1715,1716,1740,1721,1742,1743,1744]];
        (_display displayCtrl 1721) setVariable ["FST_ButtonRelations",[1715,1716,1717,1720,1722,1743,1744,1745]];
        (_display displayCtrl 1722) setVariable ["FST_ButtonRelations",[1716,1717,1718,1721,1723,1744,1745,1746]];
        (_display displayCtrl 1723) setVariable ["FST_ButtonRelations",[1717,1718,1719,1722,1724,1745,1746,1747]];
        (_display displayCtrl 1724) setVariable ["FST_ButtonRelations",[1718,1719,1739,1723,1741,1746,1747,1748]];
        (_display displayCtrl 1725) setVariable ["FST_ButtonRelations",[1726,1732,1700]];
        (_display displayCtrl 1726) setVariable ["FST_ButtonRelations",[1725,1727,1732,1700,1701]];
        (_display displayCtrl 1727) setVariable ["FST_ButtonRelations",[1726,1728,1700,1701,1702]];
        (_display displayCtrl 1728) setVariable ["FST_ButtonRelations",[1727,1729,1701,1702,1703]];
        (_display displayCtrl 1729) setVariable ["FST_ButtonRelations",[1728,1730,1702,1703,1704]];
        (_display displayCtrl 1730) setVariable ["FST_ButtonRelations",[1729,1731,1703,1704,1733]];
        (_display displayCtrl 1731) setVariable ["FST_ButtonRelations",[1730,1704,1733]];
        (_display displayCtrl 1732) setVariable ["FST_ButtonRelations",[1725,1726,1700,1734,1705]];
        (_display displayCtrl 1733) setVariable ["FST_ButtonRelations",[1730,1731,1704,1709,1735]];
        (_display displayCtrl 1734) setVariable ["FST_ButtonRelations",[1732,1700,1705,1736,1710]];
        (_display displayCtrl 1735) setVariable ["FST_ButtonRelations",[1704,1733,1709,1714,1737]];
        (_display displayCtrl 1736) setVariable ["FST_ButtonRelations",[1734,1705,1710,1738,1715]];
        (_display displayCtrl 1737) setVariable ["FST_ButtonRelations",[1709,1735,1714,1719,1739]];
        (_display displayCtrl 1738) setVariable ["FST_ButtonRelations",[1736,1710,1715,1740,1720]];
        (_display displayCtrl 1739) setVariable ["FST_ButtonRelations",[1714,1737,1719,1724,1741]];
        (_display displayCtrl 1740) setVariable ["FST_ButtonRelations",[1738,1715,1720,1742,1743]];
        (_display displayCtrl 1741) setVariable ["FST_ButtonRelations",[1719,1739,1724,1747,1748]];
        (_display displayCtrl 1742) setVariable ["FST_ButtonRelations",[1740,1720,1743]];
        (_display displayCtrl 1743) setVariable ["FST_ButtonRelations",[1740,1720,1721,1742,1744]];
        (_display displayCtrl 1744) setVariable ["FST_ButtonRelations",[1720,1721,1722,1743,1745]];
        (_display displayCtrl 1745) setVariable ["FST_ButtonRelations",[1721,1722,1723,1744,1746]];
        (_display displayCtrl 1746) setVariable ["FST_ButtonRelations",[1722,1723,1724,1745,1747]];
        (_display displayCtrl 1747) setVariable ["FST_ButtonRelations",[1723,1724,1741,1746,1748]];
        (_display displayCtrl 1748) setVariable ["FST_ButtonRelations",[1724,1741,1747]];
    };
    if ( _difficulty == 2) then
    {
        (_display displayCtrl 1700) setVariable ["FST_ButtonRelations",[1725,1726,1727,1732,1701,1734,1705,1706]];
        (_display displayCtrl 1701) setVariable ["FST_ButtonRelations",[1726,1727,1728,1700,1702,1705,1706,1707]];
        (_display displayCtrl 1702) setVariable ["FST_ButtonRelations",[1727,1728,1729,1701,1703,1706,1707,1708]];
        (_display displayCtrl 1703) setVariable ["FST_ButtonRelations",[1728,1729,1730,1702,1704,1707,1708,1709]];
        (_display displayCtrl 1704) setVariable ["FST_ButtonRelations",[1729,1730,1731,1703,1733,1708,1709,1735]];
        (_display displayCtrl 1705) setVariable ["FST_ButtonRelations",[1732,1700,1701,1734,1706,1736,1710,1711]];
        (_display displayCtrl 1706) setVariable ["FST_ButtonRelations",[1700,1701,1702,1705,1707,1710,1711,1712]];
        (_display displayCtrl 1707) setVariable ["FST_ButtonRelations",[1701,1702,1703,1706,1708,1711,1712,1713]];
        (_display displayCtrl 1708) setVariable ["FST_ButtonRelations",[1702,1703,1704,1707,1709,1712,1713,1714]];
        (_display displayCtrl 1709) setVariable ["FST_ButtonRelations",[1703,1704,1733,1708,1735,1713,1714,1737]];
        (_display displayCtrl 1710) setVariable ["FST_ButtonRelations",[1734,1705,1706,1736,1711,1738,1715,1716]];
        (_display displayCtrl 1711) setVariable ["FST_ButtonRelations",[1705,1706,1707,1710,1712,1715,1716,1717]];
        (_display displayCtrl 1712) setVariable ["FST_ButtonRelations",[1706,1707,1708,1711,1713,1716,1717,1718]];
        (_display displayCtrl 1713) setVariable ["FST_ButtonRelations",[1707,1708,1709,1712,1714,1717,1718,1719]];
        (_display displayCtrl 1714) setVariable ["FST_ButtonRelations",[1708,1709,1735,1713,1737,1718,1719,1739]];
        (_display displayCtrl 1715) setVariable ["FST_ButtonRelations",[1736,1710,1711,1738,1716,1740,1720,1721]];
        (_display displayCtrl 1716) setVariable ["FST_ButtonRelations",[1710,1711,1712,1715,1717,1720,1721,1722]];
        (_display displayCtrl 1717) setVariable ["FST_ButtonRelations",[1711,1712,1713,1716,1718,1721,1722,1723]];
        (_display displayCtrl 1718) setVariable ["FST_ButtonRelations",[1712,1713,1714,1717,1719,1722,1723,1724]];
        (_display displayCtrl 1719) setVariable ["FST_ButtonRelations",[1713,1714,1737,1718,1739,1723,1724,1741]];
        (_display displayCtrl 1720) setVariable ["FST_ButtonRelations",[1738,1715,1716,1740,1721,1742,1743,1744]];
        (_display displayCtrl 1721) setVariable ["FST_ButtonRelations",[1715,1716,1717,1720,1722,1743,1744,1745]];
        (_display displayCtrl 1722) setVariable ["FST_ButtonRelations",[1716,1717,1718,1721,1723,1744,1745,1746]];
        (_display displayCtrl 1723) setVariable ["FST_ButtonRelations",[1717,1718,1719,1722,1724,1745,1746,1747]];
        (_display displayCtrl 1724) setVariable ["FST_ButtonRelations",[1718,1719,1739,1723,1741,1746,1747,1748]];
        (_display displayCtrl 1725) setVariable ["FST_ButtonRelations",[1749,1750,1751,1758,1726,1760,1732,1700]];
        (_display displayCtrl 1726) setVariable ["FST_ButtonRelations",[1750,1751,1752,1725,1727,1732,1700,1701]];
        (_display displayCtrl 1727) setVariable ["FST_ButtonRelations",[1751,1752,1753,1726,1728,1700,1701,1702]];
        (_display displayCtrl 1728) setVariable ["FST_ButtonRelations",[1752,1753,1754,1727,1729,1701,1702,1703]];
        (_display displayCtrl 1729) setVariable ["FST_ButtonRelations",[1753,1754,1755,1728,1730,1702,1703,1704]];
        (_display displayCtrl 1730) setVariable ["FST_ButtonRelations",[1754,1755,1756,1729,1731,1703,1704,1733]];
        (_display displayCtrl 1731) setVariable ["FST_ButtonRelations",[1755,1756,1757,1730,1759,1704,1733,1761]];
        (_display displayCtrl 1732) setVariable ["FST_ButtonRelations",[1758,1725,1726,1760,1700,1762,1734,1705]];
        (_display displayCtrl 1733) setVariable ["FST_ButtonRelations",[1730,1731,1759,1704,1761,1709,1735,1763]];
        (_display displayCtrl 1734) setVariable ["FST_ButtonRelations",[1760,1732,1700,1762,1705,1764,1736,1710]];
        (_display displayCtrl 1735) setVariable ["FST_ButtonRelations",[1704,1733,1761,1709,1763,1714,1737,1765]];
        (_display displayCtrl 1736) setVariable ["FST_ButtonRelations",[1762,1734,1705,1764,1710,1766,1738,1715]];
        (_display displayCtrl 1737) setVariable ["FST_ButtonRelations",[1709,1735,1763,1714,1765,1719,1739,1767]];
        (_display displayCtrl 1738) setVariable ["FST_ButtonRelations",[1764,1736,1710,1766,1715,1768,1740,1720]];
        (_display displayCtrl 1739) setVariable ["FST_ButtonRelations",[1714,1737,1765,1719,1767,1724,1741,1769]];
        (_display displayCtrl 1740) setVariable ["FST_ButtonRelations",[1766,1738,1715,1768,1720,1770,1742,1743]];
        (_display displayCtrl 1741) setVariable ["FST_ButtonRelations",[1719,1739,1767,1724,1769,1747,1748,1771]];
        (_display displayCtrl 1742) setVariable ["FST_ButtonRelations",[1768,1740,1720,1770,1743,1772,1773,1774]];
        (_display displayCtrl 1743) setVariable ["FST_ButtonRelations",[1740,1720,1721,1742,1744,1773,1774,1775]];
        (_display displayCtrl 1744) setVariable ["FST_ButtonRelations",[1720,1721,1722,1743,1745,1774,1775,1776]];
        (_display displayCtrl 1745) setVariable ["FST_ButtonRelations",[1721,1722,1723,1744,1746,1775,1776,1777]];
        (_display displayCtrl 1746) setVariable ["FST_ButtonRelations",[1722,1723,1724,1745,1747,1776,1777,1778]];
        (_display displayCtrl 1747) setVariable ["FST_ButtonRelations",[1723,1724,1741,1746,1748,1777,1778,1779]];
        (_display displayCtrl 1748) setVariable ["FST_ButtonRelations",[1724,1741,1769,1747,1771,1778,1779,1780]];
        (_display displayCtrl 1749) setVariable ["FST_ButtonRelations",[1750,1758,1725]];
        (_display displayCtrl 1750) setVariable ["FST_ButtonRelations",[1749,1751,1758,1725,1726]];
        (_display displayCtrl 1751) setVariable ["FST_ButtonRelations",[1750,1752,1725,1726,1727]];
        (_display displayCtrl 1752) setVariable ["FST_ButtonRelations",[1751,1753,1726,1727,1728]];
        (_display displayCtrl 1753) setVariable ["FST_ButtonRelations",[1752,1754,1727,1728,1729]];
        (_display displayCtrl 1754) setVariable ["FST_ButtonRelations",[1753,1755,1728,1729,1730]];
        (_display displayCtrl 1755) setVariable ["FST_ButtonRelations",[1754,1756,1729,1730,1731]];
        (_display displayCtrl 1756) setVariable ["FST_ButtonRelations",[1755,1757,1730,1731,1759]];
        (_display displayCtrl 1757) setVariable ["FST_ButtonRelations",[1756,1731,1759]];
        (_display displayCtrl 1758) setVariable ["FST_ButtonRelations",[1749,1750,1725,1760,1732]];
        (_display displayCtrl 1759) setVariable ["FST_ButtonRelations",[1756,1757,1731,1733,1761]];
        (_display displayCtrl 1760) setVariable ["FST_ButtonRelations",[1758,1725,1732,1762,1734]];
        (_display displayCtrl 1761) setVariable ["FST_ButtonRelations",[1731,1759,1733,1735,1763]];
        (_display displayCtrl 1762) setVariable ["FST_ButtonRelations",[1760,1732,1734,1764,1736]];
        (_display displayCtrl 1763) setVariable ["FST_ButtonRelations",[1733,1761,1735,1737,1765]];
        (_display displayCtrl 1764) setVariable ["FST_ButtonRelations",[1762,1734,1736,1766,1738]];
        (_display displayCtrl 1765) setVariable ["FST_ButtonRelations",[1735,1763,1737,1739,1767]];
        (_display displayCtrl 1766) setVariable ["FST_ButtonRelations",[1764,1736,1738,1768,1740]];
        (_display displayCtrl 1767) setVariable ["FST_ButtonRelations",[1737,1765,1739,1741,1769]];
        (_display displayCtrl 1768) setVariable ["FST_ButtonRelations",[1766,1738,1740,1770,1742]];
        (_display displayCtrl 1769) setVariable ["FST_ButtonRelations",[1739,1767,1741,1748,1771]];
        (_display displayCtrl 1770) setVariable ["FST_ButtonRelations",[1768,1740,1742,1772,1773]];
        (_display displayCtrl 1771) setVariable ["FST_ButtonRelations",[1741,1769,1748,1779,1780]];
        (_display displayCtrl 1772) setVariable ["FST_ButtonRelations",[1770,1742,1773]];
        (_display displayCtrl 1773) setVariable ["FST_ButtonRelations",[1770,1742,1743,1772,1774]];
        (_display displayCtrl 1774) setVariable ["FST_ButtonRelations",[1742,1743,1744,1773,1775]];
        (_display displayCtrl 1775) setVariable ["FST_ButtonRelations",[1743,1744,1745,1774,1776]];
        (_display displayCtrl 1776) setVariable ["FST_ButtonRelations",[1744,1745,1746,1775,1777]];
        (_display displayCtrl 1777) setVariable ["FST_ButtonRelations",[1745,1746,1747,1776,1778]];
        (_display displayCtrl 1778) setVariable ["FST_ButtonRelations",[1746,1747,1748,1777,1779]];
        (_display displayCtrl 1779) setVariable ["FST_ButtonRelations",[1747,1748,1771,1778,1780]];
        (_display displayCtrl 1780) setVariable ["FST_ButtonRelations",[1748,1771,1779]];
    };

}] call CBA_fnc_addEventHandler;

["FST_setUpMinefieldGame", {
    params ["_display","_difficulty"];

    private _gnode = 2;
    private _bnode = 2;

    if (_difficulty == 0) then
    {
        _display setVariable ["FST_GoodPoints", 2];
        _display setVariable ["FST_BadPoints", 2];
        private _up2xs = [1700,1701,1702,1703,1704];
        private _up1xs = [1705,1706,1707,1708,1709];
        private _cenxs = [1710,1711,1712,1713,1714];
        private _dn1xs = [1715,1716,1717,1718,1719];
        private _dn2xs = [1720,1721,1722,1723,1724];
        private _yarrays = [_up2xs,_up1xs,_cenxs,_dn1xs,_dn2xs];
        while { _gnode > 0 } do
        {
            private _goodbutton = (_yarrays select (floor (random 5))) select (floor (random 5));
            private _grelations = (_display displayCtrl _goodbutton) getvariable ["FST_ButtonRelations", [20,20,20]];
            private _gtotal = 0;
            private _badspot = false;
            {
                private _outerrelations = (_display displayCtrl _x) getvariable ["FST_ButtonRelations", [20,20,20]];
                private _outercheck = 0;
                {
                    if ((_display displayCtrl _x) getvariable ["FST_SetAsAccess", false]) then { _outercheck = _outercheck + 1;};
                    if ((_display displayCtrl _x) getvariable ["FST_SetAsMine", false]) then { _outercheck = _outercheck + 1;};
                } forEach _outerrelations;
                if (_outercheck >= 4 ) then {_badspot = true};
                if ((_display displayCtrl _x) getvariable ["FST_SetAsAccess", false]) then { _gtotal = _gtotal + 1;};
                if ((_display displayCtrl _x) getvariable ["FST_SetAsMine", false]) then { _gtotal = _gtotal + 1;};
            } forEach _grelations; 
            if ((_gtotal < 4) && (!_badspot) && !((_display displayCtrl _goodbutton) getvariable ["FST_SetAsAccess", false])) then
            {
                (_display displayCtrl _goodbutton) setVariable ["FST_SetAsAccess", true];
                _gnode = _gnode - 1;
            };
        };
        while { _bnode > 0 } do
        {
            private _badbutton = (_yarrays select (floor (random 5))) select (floor (random 5));
            private _brelations = (_display displayCtrl _badbutton) getvariable ["FST_ButtonRelations", [20,20,20]];
            private _btotal = 0;
            private _badspot = false;
            {
                private _outerrelations = (_display displayCtrl _x) getvariable ["FST_ButtonRelations", [20,20,20]];
                private _outercheck = 0;
                {
                    if ((_display displayCtrl _x) getvariable ["FST_SetAsAccess", false]) then { _outercheck = _outercheck + 1;};
                    if ((_display displayCtrl _x) getvariable ["FST_SetAsMine", false]) then { _outercheck = _outercheck + 1;};
                } forEach _outerrelations;
                if (_outercheck >= 4 ) then {_badspot = true};
                if ((_display displayCtrl _x) getvariable ["FST_SetAsAccess", false]) then { _btotal = _btotal + 1;};
                if ((_display displayCtrl _x) getvariable ["FST_SetAsMine", false]) then { _btotal = _btotal + 1;};
            } forEach _brelations; 
            if (_btotal < 4 && !((_display displayCtrl _badbutton) getvariable ["FST_SetAsAccess", false]) && (!_badspot) && !((_display displayCtrl _badbutton) getvariable ["FST_SetAsMine", false])) then
            {
                (_display displayCtrl _badbutton) setVariable ["FST_SetAsMine", true];
                _bnode = _bnode - 1;
            };
        };
        {
            {
                private _relations = (_display displayCtrl _x) getvariable ["FST_ButtonRelations", [20,20,20]];
                private _gn = 0;
                private _rn = 0;
                {
                    if ((_display displayCtrl _x) getvariable ["FST_SetAsAccess", false]) then { _gn = _gn + 1;};
                    if ((_display displayCtrl _x) getvariable ["FST_SetAsMine", false]) then { _rn = _rn + 1;};
                } forEach _relations;
                (_display displayCtrl _x) setvariable ["FST_HintTotal", [_gn,_rn]];
            } forEach _x;
        } forEach _yarrays;
    };
    if (_difficulty == 1) then
    {
        _gnode = 6;
        _bnode = 4;
        _display setVariable ["FST_GoodPoints", 6];
        _display setVariable ["FST_BadPoints", 4];
        (_display displayCtrl 1825) ctrlSetText "\41st_Civilians_and_Intel\Data\Green6.paa";
        (_display displayCtrl 1827) ctrlSetText "\41st_Civilians_and_Intel\Data\Red4.paa";
        private _up3xs = [1725,1726,1727,1728,1729,1730,1731];
        private _up2xs = [1732,1700,1701,1702,1703,1704,1733];
        private _up1xs = [1734,1705,1706,1707,1708,1709,1735];
        private _cenxs = [1736,1710,1711,1712,1713,1714,1737];
        private _dn1xs = [1738,1715,1716,1717,1718,1719,1739];
        private _dn2xs = [1740,1720,1721,1722,1723,1724,1741];
        private _dn3xs = [1742,1743,1744,1745,1746,1747,1748];
        private _yarrays = [_up3xs,_up2xs,_up1xs,_cenxs,_dn1xs,_dn2xs,_dn3xs];
        while { _gnode > 0 } do
        {
            private _goodbutton = (_yarrays select (floor (random 7))) select (floor (random 7));
            private _grelations = (_display displayCtrl _goodbutton) getvariable ["FST_ButtonRelations", [20,20,20]];
            private _gtotal = 0;
            private _badspot = false;
            {
                private _outerrelations = (_display displayCtrl _x) getvariable ["FST_ButtonRelations", [20,20,20]];
                private _outercheck = 0;
                {
                    if ((_display displayCtrl _x) getvariable ["FST_SetAsAccess", false]) then { _outercheck = _outercheck + 1;};
                    if ((_display displayCtrl _x) getvariable ["FST_SetAsMine", false]) then { _outercheck = _outercheck + 1;};
                } forEach _outerrelations;
                if (_outercheck >= 4 ) then {_badspot = true};
                if ((_display displayCtrl _x) getvariable ["FST_SetAsAccess", false]) then { _gtotal = _gtotal + 1;};
                if ((_display displayCtrl _x) getvariable ["FST_SetAsMine", false]) then { _gtotal = _gtotal + 1;};
            } forEach _grelations; 
            if ((_gtotal < 4) && (!_badspot) && !((_display displayCtrl _goodbutton) getvariable ["FST_SetAsAccess", false])) then
            {
                (_display displayCtrl _goodbutton) setVariable ["FST_SetAsAccess", true];
                _gnode = _gnode - 1;
            };
        };
        while { _bnode > 0 } do
        {
            private _badbutton = (_yarrays select (floor (random 7))) select (floor (random 7));
            private _brelations = (_display displayCtrl _badbutton) getvariable ["FST_ButtonRelations", [20,20,20]];
            private _btotal = 0;
            private _badspot = false;
            {
                private _outerrelations = (_display displayCtrl _x) getvariable ["FST_ButtonRelations", [20,20,20]];
                private _outercheck = 0;
                {
                    if ((_display displayCtrl _x) getvariable ["FST_SetAsAccess", false]) then { _outercheck = _outercheck + 1;};
                    if ((_display displayCtrl _x) getvariable ["FST_SetAsMine", false]) then { _outercheck = _outercheck + 1;};
                } forEach _outerrelations;
                if (_outercheck >= 4 ) then {_badspot = true};
                if ((_display displayCtrl _x) getvariable ["FST_SetAsAccess", false]) then { _btotal = _btotal + 1;};
                if ((_display displayCtrl _x) getvariable ["FST_SetAsMine", false]) then { _btotal = _btotal + 1;};
            } forEach _brelations; 
            if (_btotal < 4 && !((_display displayCtrl _badbutton) getvariable ["FST_SetAsAccess", false]) && (!_badspot) && !((_display displayCtrl _badbutton) getvariable ["FST_SetAsMine", false])) then
            {
                (_display displayCtrl _badbutton) setVariable ["FST_SetAsMine", true];
                _bnode = _bnode - 1;
            };
        };
        {
            {
                private _relations = (_display displayCtrl _x) getvariable ["FST_ButtonRelations", [20,20,20]];
                private _gn = 0;
                private _rn = 0;
                {
                    if ((_display displayCtrl _x) getvariable ["FST_SetAsAccess", false]) then { _gn = _gn + 1;};
                    if ((_display displayCtrl _x) getvariable ["FST_SetAsMine", false]) then { _rn = _rn + 1;};
                } forEach _relations;
                (_display displayCtrl _x) setvariable ["FST_HintTotal", [_gn,_rn]];
            } forEach _x;
        } forEach _yarrays;
    };
    if (_difficulty == 2) then
    {
        _gnode = 10;
        _bnode = 6;
        _display setVariable ["FST_GoodPoints", 10];
        _display setVariable ["FST_BadPoints", 6];
        (_display displayCtrl 1824) ctrlSetText "\41st_Civilians_and_Intel\Data\Green1.paa";
        (_display displayCtrl 1825) ctrlSetText "\41st_Civilians_and_Intel\Data\Green0.paa";
        (_display displayCtrl 1827) ctrlSetText "\41st_Civilians_and_Intel\Data\Red6.paa";
        private _up4xs = [1749,1750,1751,1752,1753,1754,1755,1756,1757];
        private _up3xs = [1758,1725,1726,1727,1728,1729,1730,1731,1759];
        private _up2xs = [1760,1732,1700,1701,1702,1703,1704,1733,1761];
        private _up1xs = [1762,1734,1705,1706,1707,1708,1709,1735,1763];
        private _cenxs = [1764,1736,1710,1711,1712,1713,1714,1737,1765];
        private _dn1xs = [1766,1738,1715,1716,1717,1718,1719,1739,1767];
        private _dn2xs = [1768,1740,1720,1721,1722,1723,1724,1741,1769];
        private _dn3xs = [1770,1742,1743,1744,1745,1746,1747,1748,1771];
        private _dn4xs = [1772,1773,1774,1775,1776,1777,1778,1779,1780];
        private _yarrays = [_up4xs,_up3xs,_up2xs,_up1xs,_cenxs,_dn1xs,_dn2xs,_dn3xs,_dn4xs];
        while { _gnode > 0 } do
        {
            private _goodbutton = (_yarrays select (floor (random 9))) select (floor (random 9));
            private _grelations = (_display displayCtrl _goodbutton) getvariable ["FST_ButtonRelations", [20,20,20]];
            private _gtotal = 0;
            private _badspot = false;
            {
                private _outerrelations = (_display displayCtrl _x) getvariable ["FST_ButtonRelations", [20,20,20]];
                private _outercheck = 0;
                {
                    if ((_display displayCtrl _x) getvariable ["FST_SetAsAccess", false]) then { _outercheck = _outercheck + 1;};
                    if ((_display displayCtrl _x) getvariable ["FST_SetAsMine", false]) then { _outercheck = _outercheck + 1;};
                } forEach _outerrelations;
                if (_outercheck >= 4 ) then {_badspot = true};
                if ((_display displayCtrl _x) getvariable ["FST_SetAsAccess", false]) then { _gtotal = _gtotal + 1;};
                if ((_display displayCtrl _x) getvariable ["FST_SetAsMine", false]) then { _gtotal = _gtotal + 1;};
            } forEach _grelations; 
            if ((_gtotal < 4) && (!_badspot) && !((_display displayCtrl _goodbutton) getvariable ["FST_SetAsAccess", false])) then
            {
                (_display displayCtrl _goodbutton) setVariable ["FST_SetAsAccess", true];
                _gnode = _gnode - 1;
            };
        };
        while { _bnode > 0 } do
        {
            private _badbutton = (_yarrays select (floor (random 9))) select (floor (random 9));
            private _brelations = (_display displayCtrl _badbutton) getvariable ["FST_ButtonRelations", [20,20,20]];
            private _btotal = 0;
            private _badspot = false;
            {
                private _outerrelations = (_display displayCtrl _x) getvariable ["FST_ButtonRelations", [20,20,20]];
                private _outercheck = 0;
                {
                    if ((_display displayCtrl _x) getvariable ["FST_SetAsAccess", false]) then { _outercheck = _outercheck + 1;};
                    if ((_display displayCtrl _x) getvariable ["FST_SetAsMine", false]) then { _outercheck = _outercheck + 1;};
                } forEach _outerrelations;
                if (_outercheck >= 4 ) then {_badspot = true};
                if ((_display displayCtrl _x) getvariable ["FST_SetAsAccess", false]) then { _btotal = _btotal + 1;};
                if ((_display displayCtrl _x) getvariable ["FST_SetAsMine", false]) then { _btotal = _btotal + 1;};
            } forEach _brelations; 
            if (_btotal < 4 && !((_display displayCtrl _badbutton) getvariable ["FST_SetAsAccess", false]) && (!_badspot) && !((_display displayCtrl _badbutton) getvariable ["FST_SetAsMine", false])) then
            {
                (_display displayCtrl _badbutton) setVariable ["FST_SetAsMine", true];
                _bnode = _bnode - 1;
            };
        };
        {
            {
                private _relations = (_display displayCtrl _x) getvariable ["FST_ButtonRelations", [20,20,20]];
                private _gn = 0;
                private _rn = 0;
                {
                    if ((_display displayCtrl _x) getvariable ["FST_SetAsAccess", false]) then { _gn = _gn + 1;};
                    if ((_display displayCtrl _x) getvariable ["FST_SetAsMine", false]) then { _rn = _rn + 1;};
                } forEach _relations;
                (_display displayCtrl _x) setvariable ["FST_HintTotal", [_gn,_rn]];
            } forEach _x;
        } forEach _yarrays;
    };
}] call CBA_fnc_addEventHandler;

["FST_initializeMinefieldButton", {
    params ["_term", "_user", "_clicked", "_total"];

		_clicked setVariable ["FST_HackingData", [_term, _user, _clicked, _total]];
        _clicked ctrlAddEventHandler 
		[
			"ButtonClick",
			{
				params ["_control"];
				private _hackingdata = _control getVariable "FST_HackingData";
				_hackingdata params ["_term", "_user", "_clicked", "_total"];
				if ((_clicked getVariable ["FST_RevealedButton", false]) or (_term getVariable ["FST_DeviceAccessed", false]) or (_term getVariable ["FST_DeviceLocked", false]) or (_term getVariable ["FST_DeviceBroken", false])) exitWith {};
                if (_clicked getVariable ["FST_SetAsMine", false]) then
                {
                    _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\BadTriangle.paa";
                    if ((_term getVariable ["FST_AttemptsLeft",0]) > 0) exitWith
                    {
                        _term setVariable ["FST_AttemptsLeft", ((_term getVariable ["FST_AttemptsLeft",0]) - 1), true];
                        _term setVariable ["FST_DeviceInUse",false,true]; 
                        _user setVariable ["FST_PlayerIsHacking",false,true];
		            	playSound3D ["a3\missions_f_bootcamp\data\sounds\vr_shutdown.wss", _term,false, getPosASL _term,5,1,20];
                        hintSilent parseText "<t color='#990000'>The target device detected the hacking attempt and kicked you out<br/> You may try again</t>";
                        ["FST_showTargets", []] call CBA_fnc_localEvent;
                        ((findDisplay 6970) displayCtrl 6001) ctrlShow true;
                        [
                            {
                                closeDialog 0;
                            },
                            [],
                            5
                        ] call CBA_fnc_waitAndExecute;
                    };
                    if (_term getVariable ["FST_DeviceRepaired", false]) then
                    {
                        _term setVariable ["FST_DeviceLocked", true, true];
                        _term setVariable ["FST_DeviceInUse",false,true]; 
                        _user setVariable ["FST_PlayerIsHacking",false,true];
		            	playSound3D ["a3\missions_f_bootcamp\data\sounds\vr_shutdown.wss", _term,false, getPosASL _term,5,1,20];
                        hintSilent parseText "<t color='#990000'>The target device detected the hacking attempt and has locked down<br/> This is now beyond what you can break into in the field</t>";
                        ["FST_showTargets", []] call CBA_fnc_localEvent;
                        ((findDisplay 6970) displayCtrl 6001) ctrlShow true;
                        [
                            {
                                closeDialog 0;
                            },
                            [],
                            5
                        ] call CBA_fnc_waitAndExecute;
                    };
                    if !(_term getVariable ["FST_DeviceRepaired", false]) then
                    {
                        _term setVariable ["FST_DeviceBroken", true, true];
                        _term setVariable ["FST_DeviceInUse",false,true]; 
                        _user setVariable ["FST_PlayerIsHacking",false,true];
		            	playSound3D ["a3\missions_f_bootcamp\data\sounds\vr_shutdown.wss", _term,false, getPosASL _term,5,1,20];
                        hintSilent parseText "<t color='#990000'>You failed the hack and damaged the target device in the proccess<br/>It will require repairs to try again</t>";
                        ["FST_showTargets", []] call CBA_fnc_localEvent;
                        ((findDisplay 6970) displayCtrl 6001) ctrlShow true;
                        [
                            {
                                closeDialog 0;
                            },
                            [],
                            5
                        ] call CBA_fnc_waitAndExecute;
                    };
                };
                if (_clicked getVariable ["FST_SetAsAccess", false]) then
                {
                    _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\GoodDiamond.paa";
                    private _runtotal = ((findDisplay 6970) getVariable ["FST_TotalAccessFound",0]) + 1;
                    if (_runtotal == _total) then
                    {
                        _term setVariable ["FST_DeviceAccessed", true, true];
                        _term setVariable ["FST_DiffPassed", _total, true];
                        ((findDisplay 6970) displayCtrl 1825) ctrlSetText "\41st_Civilians_and_Intel\Data\Green0.paa";
                        ["FST_showTargets", []] call CBA_fnc_localEvent;
                        ((findDisplay 6970) displayCtrl 6001) ctrlShow true;
                        [
                            {
                                closeDialog 0;
                            },
                            [],
                            5
                        ] call CBA_fnc_waitAndExecute;
                    }
                    else
                    {
                        playSoundUI [(selectRandom ["3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick1.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick2.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick3.ogg"]),4,1,true];
                        (findDisplay 6970) setVariable ["FST_TotalAccessFound", _runtotal];
                        ((findDisplay 6970) displayCtrl 1824) ctrlSetText "\41st_Civilians_and_Intel\Data\Green0.paa";
                        (findDisplay 6970) setVariable ["FST_GoodPoints", (((findDisplay 6970) getVariable ["FST_GoodPoints",0]) - 1)];
                        ((findDisplay 6970) displayCtrl 1825) ctrlSetText (["\41st_Civilians_and_Intel\Data\Green0.paa","\41st_Civilians_and_Intel\Data\Green1.paa","\41st_Civilians_and_Intel\Data\Green2.paa","\41st_Civilians_and_Intel\Data\Green3.paa","\41st_Civilians_and_Intel\Data\Green4.paa","\41st_Civilians_and_Intel\Data\Green5.paa","\41st_Civilians_and_Intel\Data\Green6.paa","\41st_Civilians_and_Intel\Data\Green7.paa","\41st_Civilians_and_Intel\Data\Green8.paa","\41st_Civilians_and_Intel\Data\Green9.paa"] select ((findDisplay 6970) getVariable ["FST_GoodPoints",0]));
			        	_clicked setVariable ["FST_RevealedButton", true];
                    };
                };
                if ((_clicked getVariable ["FST_SetAsAccess", false]) or (_clicked getVariable ["FST_SetAsMine", false])) exitWith {};
                playSoundUI [(selectRandom ["3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick1.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick2.ogg","3as\3AS_Weapons\Roleplay\sounds\RepublicDatapad\Clicks\DatapadClick3.ogg"]),4,1,true];
				_clicked setVariable ["FST_RevealedButton", true];
				private _hint = _clicked getVariable ["FST_HintTotal", [0,0]];
                if ((_hint select 0) == 4) then {_clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_4_0.paa";};
                if ((_hint select 1) == 4) then {_clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_0_4.paa";};
                if ((_hint select 0) == 0) then
                {
                    if ((_hint select 1) == 0) then
                    {
                        _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_0_0.paa";
                        ["FST_revealButtons", [_clicked]] call CBA_fnc_localEvent;
                    };
                    if ((_hint select 1) == 1) then
                    {
                        _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_0_1.paa";
                    };
                    if ((_hint select 1) == 2) then
                    { 
                        _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_0_2.paa";
                    };
                    if ((_hint select 1) == 3) then
                    {
                        _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_0_3.paa";
                    };
                };
                if ((_hint select 0) == 1) then
                {
                    if ((_hint select 1) == 0) then
                    {
                        _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_1_0.paa";
                    };
                    if ((_hint select 1) == 1) then
                    {
                        _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_1_1.paa";
                    };
                    if ((_hint select 1) == 2) then
                    { 
                        _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_1_2.paa";
                    };
                    if ((_hint select 1) == 3) then
                    {
                        _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_1_3.paa";
                    };
                };
                if ((_hint select 0) == 2) then
                {
                    if ((_hint select 1) == 0) then
                    {
                        _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_2_0.paa";
                    };
                    if ((_hint select 1) == 1) then
                    {
                        _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_2_1.paa";
                    };
                    if ((_hint select 1) == 2) then
                    { 
                        _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_2_2.paa";
                    };
                };
                if ((_hint select 0) == 3) then
                {
                    if ((_hint select 1) == 0) then
                    {
                        _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_3_0.paa";
                    };
                    if ((_hint select 1) == 1) then
                    {
                        _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_3_1.paa";
                    };
                };
			}
		];
}] call CBA_fnc_addEventHandler;

["FST_showTargets", {

    private _display = findDisplay 6970;
    {
        if ( _x getvariable ["FST_SetAsAccess", false]) then { _x ctrlSetText "\41st_Civilians_and_Intel\Data\GoodDiamond.paa";};
        if ( _x getvariable ["FST_SetAsMine", false]) then { _x ctrlSetText "\41st_Civilians_and_Intel\Data\BadTriangle.paa";};
    } forEach 
    [
        _display displayCtrl 1700,
        _display displayCtrl 1701,
        _display displayCtrl 1702,
        _display displayCtrl 1703,
        _display displayCtrl 1704,
        _display displayCtrl 1705,
        _display displayCtrl 1706,
        _display displayCtrl 1707,
        _display displayCtrl 1708,
        _display displayCtrl 1709,
        _display displayCtrl 1710,
        _display displayCtrl 1711,
        _display displayCtrl 1712,
        _display displayCtrl 1713,
        _display displayCtrl 1714,
        _display displayCtrl 1715,
        _display displayCtrl 1716,
        _display displayCtrl 1717,
        _display displayCtrl 1718,
        _display displayCtrl 1719,
        _display displayCtrl 1720,
        _display displayCtrl 1721,
        _display displayCtrl 1722,
        _display displayCtrl 1723,
        _display displayCtrl 1724,
        _display displayCtrl 1725,
        _display displayCtrl 1726,
        _display displayCtrl 1727,
        _display displayCtrl 1728,
        _display displayCtrl 1729,
        _display displayCtrl 1730,
        _display displayCtrl 1731,
        _display displayCtrl 1732,
        _display displayCtrl 1733,
        _display displayCtrl 1734,
        _display displayCtrl 1735,
        _display displayCtrl 1736,
        _display displayCtrl 1737,
        _display displayCtrl 1738,
        _display displayCtrl 1739,
        _display displayCtrl 1740,
        _display displayCtrl 1741,
        _display displayCtrl 1742,
        _display displayCtrl 1743,
        _display displayCtrl 1744,
        _display displayCtrl 1745,
        _display displayCtrl 1746,
        _display displayCtrl 1747,
        _display displayCtrl 1748,
        _display displayCtrl 1749,
        _display displayCtrl 1750,
        _display displayCtrl 1751,
        _display displayCtrl 1752,
        _display displayCtrl 1753,
        _display displayCtrl 1754,
        _display displayCtrl 1755,
        _display displayCtrl 1756,
        _display displayCtrl 1757,
        _display displayCtrl 1758,
        _display displayCtrl 1759,
        _display displayCtrl 1760,
        _display displayCtrl 1761,
        _display displayCtrl 1762,
        _display displayCtrl 1763,
        _display displayCtrl 1764,
        _display displayCtrl 1765,
        _display displayCtrl 1766,
        _display displayCtrl 1767,
        _display displayCtrl 1768,
        _display displayCtrl 1769,
        _display displayCtrl 1770,
        _display displayCtrl 1771,
        _display displayCtrl 1772,
        _display displayCtrl 1773,
        _display displayCtrl 1774,
        _display displayCtrl 1775,
        _display displayCtrl 1776,
        _display displayCtrl 1777,
        _display displayCtrl 1778,
        _display displayCtrl 1779,
        _display displayCtrl 1780
    ];

}] call CBA_fnc_addEventHandler;

["FST_revealButtons", {
    params ["_button"];
    private _display = findDisplay 6970;
    {
        if !((_display displayCtrl _x) getvariable ["FST_RevealedButton", false]) then
        {
            private _clicked = _display displayCtrl _x;
            _clicked setVariable ["FST_RevealedButton", true];
            private _hint = _clicked getVariable ["FST_HintTotal", [0,0]];
            if ((_hint select 0) == 4) then {_clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_4_0.paa";};
            if ((_hint select 1) == 4) then {_clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_0_4.paa";};
            if ((_hint select 0) == 0) then
            {
                if ((_hint select 1) == 0) then
                {
                    _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_0_0.paa";
                    ["FST_revealButtons", [_clicked]] call CBA_fnc_localEvent;
                };
                if ((_hint select 1) == 1) then
                {
                    _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_0_1.paa";
                };
                if ((_hint select 1) == 2) then
                { 
                    _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_0_2.paa";
                };
                if ((_hint select 1) == 3) then
                {
                    _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_0_3.paa";
                };
            };
            if ((_hint select 0) == 1) then
            {
                if ((_hint select 1) == 0) then
                {
                    _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_1_0.paa";
                };
                if ((_hint select 1) == 1) then
                {
                    _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_1_1.paa";
                };
                if ((_hint select 1) == 2) then
                { 
                    _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_1_2.paa";
                };
                if ((_hint select 1) == 3) then
                {
                    _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_1_3.paa";
                };
            };
            if ((_hint select 0) == 2) then
            {
                if ((_hint select 1) == 0) then
                {
                    _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_2_0.paa";
                };
                if ((_hint select 1) == 1) then
                {
                    _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_2_1.paa";
                };
                if ((_hint select 1) == 2) then
                { 
                    _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_2_2.paa";
                };
            };
            if ((_hint select 0) == 3) then
            {
                if ((_hint select 1) == 0) then
                {
                    _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_3_0.paa";
                };
                if ((_hint select 1) == 1) then
                {
                    _clicked ctrlSetText "\41st_Civilians_and_Intel\Data\HackResult_3_1.paa";
                };
            };
        };
    } forEach (_button getvariable ["FST_ButtonRelations", [20,20,20]]);
    

}] call CBA_fnc_addEventHandler;


["FST_resetHackRepairButtons", {
    params ["_term", "_display", "_source", "_attempttext"];

    private _pressed = ["FST_1600Pressed","FST_1601Pressed","FST_1602Pressed","FST_1603Pressed","FST_1604Pressed","FST_1605Pressed","FST_1606Pressed","FST_1607Pressed","FST_1608Pressed","FST_1609Pressed","FST_1610Pressed"];
    _term setVariable [ _pressed select ( _source - 1600), true, true];
    private _count = 1600;
    for "_count" from 1600 to 1610 do
    {
        if !(_term getVariable [( _pressed select (_count - 1600)), false]) then {(_display displayCtrl _count) ctrlEnable true;};
    };
	(_display displayCtrl 1611) ctrlEnable true;
    (_display displayCtrl 1613) ctrlSetStructuredText parsetext _attempttext;
	_term setVariable ["FST_LastAttempt", _attempttext,true];
	(_display displayCtrl _source) ctrlSetTextColor [0.4,0.4,0.4,1];
	(_display displayCtrl _source) ctrlSetTooltip "You have already performed this repair";

}] call CBA_fnc_addEventHandler;

["FST_winHackRepair", {
    params ["_term", "_user", "_origin"];

    _term setVariable ["FST_DeviceBroken",false,true]; 
    _term setVariable ["FST_DeviceRepaired",true,true];
    _term setVariable ["FST_DeviceInUse",false,true]; 
    _user setVariable ["FST_PlayerIsMeching",false,true];
    hintSilent parseText "<t color='#0074cc'>Device operational<br/>You may attempt to hack again</t>";
    closeDialog 0;

}] call CBA_fnc_addEventHandler;

["FST_loseHackRepair", {
    params ["_term", "_user", "_text"];
    
    hintSilent parseText _text;
    _term setVariable ["FST_DeviceFullBroken",true,true];
    _term setVariable ["FST_DeviceInUse",false,true];
    _user setVariable ["FST_PlayerIsMeching",false,true];
    closeDialog 0;

}] call CBA_fnc_addEventHandler;
