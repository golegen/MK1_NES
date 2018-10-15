// NES MK1 v2.0
// Copyleft Mojon Twins 2013, 2015, 2017, 2018

// Add here your code. An interactive has just been interacted.
// You may add checks and set variables and stuff.

// rdc contains which interactive 'f' has been interacted.
// if rdc&128    -> container.
// if !(rdc&128) -> sprite face.

#ifndef ACTIVATE_SCRIPTING
	if (rdc == 8) {
		gp_gen = custom_text0; textbox_do (); 
	}

	if (rdc == (0x80 | 5)) {
		if (flags [5] == 0)
			gp_gen = custom_text2;
		else
			gp_gen = custom_text1; 
		textbox_do (); 
	}
#endif
	