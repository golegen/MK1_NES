// NES MK1 v2.0
// Copyleft Mojon Twins 2013, 2015, 2017, 2018

// Use this alongisde map_renderer_complex.h
// (#define MAP_RENDERER_COMPLEX)

// Reaching this point, map_buff has the decompressed map screen.
// You can write as many modifications as you like here:

#ifndef ACTIVATE_SCRIPTING
	if (n_pant == 0 && flags [5] == 6) {
		map_buff [0x68] = 3;
	}
#endif
