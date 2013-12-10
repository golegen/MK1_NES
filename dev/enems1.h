// x1, y1, x2, y2, mx, my, t
const unsigned char enemies_ROM [] = {
	0, 0, 0, 0, 8, 8, 0,
	0, 0, 0, 0, 8, 8, 0,
	0, 0, 0, 0, 8, 8, 0,
	80, 80, 64, 80, 8, 8, 7,
	144, 80, 128, 80, 8, 8, 7,
	32, 48, 48, 48, 8, 8, 7,
	112, 32, 112, 48, 8, 8, 7,
	160, 96, 160, 80, 8, 8, 7,
	112, 160, 96, 160, 8, 8, 7,
	64, 128, 80, 128, 8, 8, 7,
	112, 48, 112, 32, 8, 8, 7,
	208, 160, 208, 144, 8, 8, 7,
	224, 16, 224, 32, 8, 8, 7,
	16, 64, 32, 64, 8, 8, 7,
	176, 112, 176, 96, 8, 8, 7,
	128, 112, 144, 112, 8, 8, 7,
	144, 64, 144, 48, 8, 8, 7,
	32, 96, 32, 80, 8, 8, 7,
	32, 16, 32, 32, 8, 8, 7,
	176, 64, 176, 80, 8, 8, 7,
	80, 128, 96, 128, 8, 8, 7,
	160, 80, 160, 64, 8, 8, 7,
	32, 80, 32, 64, 8, 8, 7,
	192, 144, 176, 144, 8, 8, 7,
	112, 144, 96, 144, 8, 8, 7,
	144, 48, 128, 48, 8, 8, 7,
	16, 80, 16, 64, 8, 8, 7,
	112, 64, 128, 64, 8, 8, 7,
	32, 96, 48, 96, 8, 8, 7,
	224, 80, 208, 80, 8, 8, 7,
	32, 48, 48, 48, 8, 8, 7,
	144, 80, 144, 64, 8, 8, 7,
	176, 48, 176, 32, 8, 8, 7,
	16, 112, 16, 128, 8, 8, 7,
	144, 64, 160, 64, 8, 8, 7,
	112, 32, 112, 48, 8, 8, 7,
	16, 80, 32, 80, 8, 8, 7,
	160, 80, 176, 80, 8, 8, 7,
	96, 64, 96, 48, 8, 8, 7,
	96, 64, 96, 48, 8, 8, 7,
	224, 96, 208, 96, 8, 8, 7,
	128, 64, 128, 80, 8, 8, 7,
	128, 80, 112, 48, 7, 7, 7,
	144, 48, 112, 48, 4, 8, 1,
	112, 128, 144, 128, 12, 8, 1,
	112, 128, 112, 112, 8, 8, 7,
	128, 16, 128, 80, 8, 12, 2,
	208, 80, 208, 16, 8, 4, 2,
	80, 96, 80, 80, 8, 8, 7,
	208, 80, 208, 96, 8, 8, 7,
	144, 80, 160, 80, 8, 8, 7,
	64, 48, 80, 48, 8, 8, 7,
	192, 112, 192, 96, 8, 8, 7,
	160, 112, 144, 112, 8, 8, 7,
	80, 96, 96, 96, 8, 8, 7,
	176, 96, 176, 80, 8, 8, 7,
	128, 160, 112, 160, 8, 8, 7,
	160, 16, 160, 48, 8, 12, 2,
	96, 48, 96, 16, 8, 4, 2,
	16, 32, 16, 48, 8, 8, 7,
	32, 128, 32, 112, 8, 8, 7,
	160, 16, 176, 160, 12, 12, 3,
	224, 16, 208, 144, 4, 12, 3,
	96, 48, 80, 48, 8, 8, 7,
	160, 48, 176, 48, 8, 8, 7,
	128, 80, 128, 96, 8, 8, 7,
	16, 64, 48, 64, 12, 8, 1,
	224, 64, 192, 64, 4, 8, 1,
	112, 96, 112, 80, 8, 8, 7,
	192, 64, 192, 48, 8, 8, 7,
	48, 96, 48, 80, 8, 8, 7,
	64, 48, 176, 48, 16, 8, 1
};

// xy, tipo
const unsigned char hotspots_ROM [] = {
	0, 0,
	115, 4,
	0, 0,
	217, 2,
	209, 2,
	150, 1,
	17, 4,
	231, 4,
	201, 1,
	37, 1,
	69, 2,
	69, 2,
	101, 2,
	179, 2,
	26, 2,
	55, 1,
	148, 4,
	58, 4,
	58, 1,
	49, 4,
	72, 2,
	177, 2,
	133, 4,
	0, 0
};

