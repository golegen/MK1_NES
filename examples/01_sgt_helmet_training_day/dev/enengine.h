// NES MK1 v0.1
// Copyleft Mojon Twins 2013

// enengine.h
// Enemies Engine & stuff

void __fastcall__ enems_load (void) {
	// Loads enems from n_pant
	gp_gen = (unsigned char *) (c_enems) + n_pant * 21;
	for (gpit = 0; gpit < 3; gpit ++) {
		en_x1 [gpit] = *gp_gen ++;
		en_y1 [gpit] = *gp_gen ++;
		en_x2 [gpit] = *gp_gen ++;
		en_y2 [gpit] = *gp_gen ++;
		en_mx [gpit] = (*gp_gen ++) - 8;
		en_my [gpit] = (*gp_gen ++) - 8;
		en_t [gpit] = *gp_gen ++;
		
		en_x [gpit] = en_x1 [gpit];
		en_y [gpit] = en_y1 [gpit];
		
		en_life [gpit] = ENEMS_LIFE_GAUGE;
		en_status [gpit] = 0;
		
#ifdef ENABLE_PURSUERS		
		if (en_t [gpit] == 7) {
			en_s [gpit] = TYPE_7_FIXED_SPRITE - 1;
			en_alive [gpit] = 0;
			en_ct [gpit] = DEATH_COUNT_EXPRESSION;
		} else 
#endif		
		{
			en_s [gpit] = en_t [gpit] - 1;
			if (en_mx [gpit] == 1 || en_my [gpit] == 1) {
				en_status [gpit] = 1; 
			} else {
				en_status [gpit] = 0;
				en_mx [gpit] >>= 1;
				en_my [gpit] >>= 1;
			}
		}
		
		en_touched [gpit] = 0;		
	}
}
/*
void __fastcall__ enems_sprites (void) {
	// Creates sprites for enems.
	for (gpit = 0; gpit < 3; gpit ++) {
		if (!en_t [gpit]) {
			oam_meta_spr (0, 240, gpit << 4, spr_empty);
		}
	}
}
*/
void __fastcall__ enems_move (void) {
	// Updates sprites
	touched = 0;
	for (gpit = 0; gpit < 3; gpit ++) {
		if (en_touched [gpit]) {
			
			en_cttouched [gpit] --;
			if (!en_cttouched [gpit]) {
				en_touched [gpit] = 0;
			} else {
				oam_meta_spr (en_x [gpit], en_y [gpit] + SPRITE_ADJUST, gpit << 4, spr_explosion);
				continue;
			}
		}
		
		if (en_t [gpit]) {

			if (en_mx [gpit] != 0) {
				en_fr = ((en_x [gpit]) >> 4) & 1;
			} else {
				en_fr = ((en_y [gpit]) >> 4) & 1;
			}

			switch (en_t [gpit]) {
				case 1:
				case 2:
				case 3:
				case 4:
					if (!en_status [gpit] || half_life) {
#ifdef WALLS_STOP_ENEMIES
						// Collision. Acts as "everything is a wall". Refine if needed for future games!
						
						en_colly = 0;
						if (en_my [gpit] != 0) {
							etx1 = en_x [gpit] >> 4;
							etx2 = (en_x [gpit] + 15) >> 4;
							if (en_my [gpit] < 0) {
								ety1 = (en_y [gpit] - 1) >> 4;	
							} else if (en_my [gpit] > 0) {
								ety1 = (en_y [gpit] + 16) >> 4;
							}						
							if (attr (etx1, ety1) || attr (etx2, ety1)) {
								en_colly = 1;
							}				
						}
						
						en_collx = 0;
						if (en_mx [gpit] != 0) {
							ety1 = en_y [gpit] >> 4;
							ety2 = (en_y [gpit] + 15) >> 4;
							if (en_mx [gpit] < 0) {
								etx1 = (en_x [gpit] - 1) >> 4;
							} else if (en_mx [gpit] > 0) {
								etx1 = (en_x [gpit] + 16) >> 4;
							}
							if (attr (etx1, ety1) || attr (etx1, ety2)) {
								en_collx = 1;
							}
						}
#endif
						
						en_x [gpit] += en_mx [gpit];
						en_y [gpit] += en_my [gpit];
#ifdef WALLS_STOP_ENEMIES
						if (en_x [gpit] == en_x1 [gpit] || en_x [gpit] == en_x2 [gpit] || en_collx) en_mx [gpit] = -en_mx [gpit];
						if (en_y [gpit] == en_y1 [gpit] || en_y [gpit] == en_y2 [gpit] || en_colly) en_my [gpit] = -en_my [gpit];
#else
						if (en_x [gpit] == en_x1 [gpit] || en_x [gpit] == en_x2 [gpit]) en_mx [gpit] = -en_mx [gpit];
						if (en_y [gpit] == en_y1 [gpit] || en_y [gpit] == en_y2 [gpit]) en_my [gpit] = -en_my [gpit];						
#endif						
					}
					oam_meta_spr (en_x [gpit], en_y [gpit] + SPRITE_ADJUST, gpit << 4, spr_enems [(en_s [gpit] << 1) + en_fr]);
					break;
				case 7:					
					switch (en_alive [gpit]) {
						case 0:
							// IDLE
							if (en_ct [gpit]) {
								en_ct [gpit] --;
								en_y [gpit] = 240;
								oam_meta_spr (0, 240, gpit << 4, spr_empty);
							} else {
								en_alive [gpit] = 1;
								en_x [gpit] = en_x1 [gpit];
								en_y [gpit] = en_y1 [gpit];
								en_rawv [gpit] = 1 << (rand8 () % 5);
								if (en_rawv [gpit] > 4) en_rawv [gpit] = 1;
								if (en_rawv [gpit] == 1) en_status [gpit] = 1; else en_rawv [gpit] >>= 1;
								en_ct [gpit] = 50 + (rand8 () & 31);
								oam_meta_spr (en_x [gpit], en_y [gpit] + SPRITE_ADJUST, gpit << 4, spr_explosion);
							}
							break;
						case 1:
							// Appearing
							if (en_ct [gpit]) {
								en_ct [gpit] --;
							} else {
								en_alive [gpit] = 2;
							}
							break;
						case 2:
							// Pursuing
							if (pstate == EST_NORMAL && (!en_status [gpit] || half_life)) {
								en_mx [gpit] = add_sign (((prx >> 2) << 2) - en_x [gpit], en_rawv [gpit]);
								en_my [gpit] = add_sign (((pry >> 2) << 2) - en_y [gpit], en_rawv [gpit]);

								en_y [gpit] += en_my [gpit];
#ifdef WALLS_STOP_ENEMIES
								// Collision detection
#ifdef BOUNDING_BOX_8_BOTTOM
								etx1 = (en_x [gpit] + 4) >> 4;
								etx2 = (en_x [gpit] + 11) >> 4;
#else
								etx1 = en_x [gpit] >> 4;
								etx2 = (en_x [gpit] + 15) >> 4;
#endif								
								if (en_my [gpit] < 0) {
#ifdef BOUNDING_BOX_8_BOTTOM
									ety1 = (en_y [gpit] + 8) >> 4;
#else																		
									ety1 = en_y [gpit] >> 4;
#endif									
									if (attr (etx1, ety1) || attr (etx2, ety1)) 
#ifdef BOUNDING_BOX_8_BOTTOM
										en_y [gpit] = ((ety1 + 1) << 4) - 8;
#else									
										en_y [gpit] = (ety1 + 1) << 4;
#endif										
								} else if (en_my [gpit] > 0) {
									ety1 = (en_y [gpit] + 15) >> 4;
									if (attr (etx1, ety1) || attr (etx2, ety1))
										en_y [gpit] = (ety1 - 1) << 4;
								}
#endif							
								en_x [gpit] += en_mx [gpit];
#ifdef WALLS_STOP_ENEMIES
								// Collision detection
#ifdef BOUNDING_BOX_8_BOTTOM
								ety1 = (en_y [gpit] + 8) >> 4;
								ety2 = (en_y [gpit] + 15) >> 4;
#else								
								ety1 = en_y [gpit] >> 4;
								ety2 = (en_y [gpit] + 15) >> 4;
#endif								
								if (en_mx [gpit] < 0) {
#ifdef BOUNDING_BOX_8_BOTTOM									
									etx1 = (en_x [gpit] + 4) >> 4;
#else
									etx1 = en_x [gpit] >> 4;
#endif									
									if (attr (etx1, ety1) || attr (etx1, ety2))
#ifdef BOUNDING_BOX_8_BOTTOM
										en_x [gpit] = ((etx1 + 1) << 4) - 4;
#else									
										en_x [gpit] = (etx1 + 1) << 4;	
#endif										
								} else if (en_mx [gpit] > 0) {
#ifdef BOUNDING_BOX_8_BOTTOM
									etx1 = (en_x [gpit] + 11) >> 4;
#else									
									etx1 = (en_x [gpit] + 15) >> 4;
#endif									
									if (attr (etx1, ety1) || attr (etx1, ety2))
#ifdef BOUNDING_BOX_8_BOTTOM
										en_x [gpit] = ((etx1 - 1) << 4) + 4;
#else									
										en_x [gpit] = (etx1 - 1) << 4;
#endif										
								}
#endif
	
							}
							oam_meta_spr (en_x [gpit], en_y [gpit] + SPRITE_ADJUST, gpit << 4, spr_enems [(en_s [gpit] << 1) + en_fr]);
							break;
					}					
					break;
			}

			// Collide <-> player
			if (!touched && pstate == EST_NORMAL && collide (prx, pry, en_x [gpit], en_y [gpit])) {
				if (en_t [gpit] != 7 || en_alive [gpit] == 2) {
					touched = 1;
					kill_player ();
				}
			}
		} else {
			oam_meta_spr (0, 240, gpit << 4, spr_empty);
		}
	}	
}
