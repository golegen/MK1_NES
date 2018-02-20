// NES MK1 v1.0
// Copyleft Mojon Twins 2013, 2015, 2017, 2018

// LUTs

#ifdef ENABLE_MONOCOCOS
	const unsigned char monococo_state_times [] = {
		MONOCOCO_BASE_TIME_HIDDEN, MONOCOCO_BASE_TIME_APPEARING, MONOCOCO_BASE_TIME_ONBOARD, MONOCOCO_BASE_TIME_APPEARING
	};
#endif

#ifdef ENABLE_STEADY_SHOOTERS
	// left, up, right, down
	const unsigned char coco_dx [] = { -COCO_V, 0, COCO_V, 0 };
	const unsigned char coco_dy [] = { 0, -COCO_V, 0, COCO_V };
#endif
