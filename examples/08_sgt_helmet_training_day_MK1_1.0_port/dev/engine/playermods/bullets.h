// NES MK1 v0.7
// Copyleft Mojon Twins 2013, 2015, 2016

void fire_bullet (void) {
	#ifdef MAX_AMMO
		if (!pammo) return;
		pammo --;
	#endif
	// Creates a new bullet (if possible);
	for (gpit = 0; gpit < MAX_BULLETS; gpit ++) {
		if (bst [gpit] == 0) {
			bst [gpit] = 1;

			#ifdef PLAYER_MOGGY_STYLE
				switch (pfacing) {
					case CELL_FACING_LEFT:
						bx [gpit] = prx - 4;
						bmx [gpit] = -PLAYER_BULLET_SPEED;
						by [gpit] = pry + PLAYER_BULLET_Y_OFFSET;
						bmy [gpit] = 0;
						break;	
					case CELL_FACING_RIGHT:
						bx [gpit] = prx + 12;
						bmx [gpit] = PLAYER_BULLET_SPEED;
						by [gpit] = pry + PLAYER_BULLET_Y_OFFSET;
						bmy [gpit] = 0;
						break;
					case CELL_FACING_DOWN:
						bx [gpit] = prx + PLAYER_BULLET_X_OFFSET;
						by [gpit] = pry + 12;
						bmy [gpit] = PLAYER_BULLET_SPEED;
						bmx [gpit] = 0;
						break;
					case CELL_FACING_UP:
						bx [gpit] = prx + 8 - PLAYER_BULLET_X_OFFSET;
						by [gpit] = pry - 4;
						bmy [gpit] = -PLAYER_BULLET_SPEED;
						bmx [gpit] = 0;
						break;
				}
			#else
				by [gpit] = pry + PLAYER_BULLET_Y_OFFSET;
				
				if (pfacing) {
					// Left
					bx [gpit] = prx - 4;
					bmx [gpit] = -PLAYER_BULLET_SPEED;
				} else {
					// Right
					bx [gpit] = prx + 12;
					bmx [gpit] = PLAYER_BULLET_SPEED;
				}
			#endif		
			
			// sound
			sfx_play (5, 0);
			// done
			break;
		}
	}
}

void bullets_move (void) {
	for (gpit = 0; gpit < MAX_BULLETS; gpit ++) {
		if (bst [gpit]) {
			if (bmx [gpit]) {
				bx [gpit] += bmx [gpit];

				if (
					bx [gpit] < PLAYER_BULLET_SPEED ||
					bx [gpit] > 255 - PLAYER_BULLET_SPEED
				) bst [gpit] = 0; 
			
			}

			#ifdef PLAYER_MOGGY_STYLE		
				if (bmy [gpit]) {
					by [gpit] += bmy [gpit];
					if (
						by [gpit] < PLAYER_BULLET_SPEED ||
						by [gpit] > 191 - PLAYER_BULLET_SPEED
					) bst [gpit] = 0; 
				}
			#endif
			
			cx1 = (bx [gpit] + 3) >> 4; 
			cy1 = (by [gpit] + 3) >> 4;
			cm_two_points ();

			#ifdef BREAKABLE_WALLS
				if (at1 & 16) break_wall (cx1, cy1);
			#endif			
			
			if (at1 & 8) {
				bst [gpit] = 0;
				sfx_play (6, 2);
			}
			
			// Collide with enemies?			
			for (gpjt = 0; gpjt < 3; gpjt ++) {
				#ifdef FIRE_MIN_KILLABLE
					if (en_t [gpjt] >= FIRE_MIN_KILLABLE)
				#else
					if (en_t [gpjt])
				#endif
				{
					#ifdef ENABLE_PURSUERS
						if (en_t [gpjt] != 7 || en_alive [gpjt] == 2)
					#endif
					
					if (collide_in (bx [gpit] + 3, by [gpit] + 3, en_x [gpjt], en_y [gpjt])) {
						
						en_cttouched [gpjt] = 8;
						bst [gpit] = 0;
						sfx_play (6, 2);
						en_life [gpjt] --;						

						if (en_life [gpjt] == 0) {	

							#ifdef ENABLE_PURSUERS
								if (en_t [gpjt] == 7) {
									en_alive [gpjt] = 0;
									en_ct [gpjt] = DEATH_COUNT_EXPRESSION;
									en_life [gpjt] = ENEMIES_LIFE_GAUGE;
								} else
							#endif
							en_t [gpjt] = 0;		

							pkilled ++;												
						}
						break;
					}
				}	
			}
						
			oam_index = oam_spr (bx [gpit], SPRITE_ADJUST + by [gpit], oam_index, BULLET_PALETTE, BULLET_PATTERN);
		}
	}
}
