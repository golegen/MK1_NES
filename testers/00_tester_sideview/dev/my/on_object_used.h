// NES MK1 v2.0
// Copyleft Mojon Twins 2013, 2015, 2017, 2018

// Add here your code. An object has just been used.
// You may add checks and set variables and stuff.

// Player used object rda on hotspot rdb.

// Example:
// Object 5 is placed at screen 3, object 6 is placed at screen 4.

win_level = (
	ht [4] == 5 + 2*HS_USE_OFFS && 
	ht [5] == 6 + 2*HS_USE_OFFS
);

// 2*HS_USE_OFFS 'cause HS_FIX_ON_USE is on!
