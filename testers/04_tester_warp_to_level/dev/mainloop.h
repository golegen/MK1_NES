// NES MK1 v1.0
// Copyleft Mojon Twins 2013, 2015, 2017, 2018

// Main loop & helpers

void game_init (void) {

	win_level = game_over = 0;

	// Assets setup. Selects tileset, map, palettes, etc.
	#include "mainloop/asset_setup.h"

	pal_bg (c_pal_bg);
	pal_spr (c_pal_fg);

	cls ();

	draw_game_frame ();
	//clean_gauge ();

	hotspots_load ();
	#ifndef DEACTIVATE_KEYS		
		// bolts_load
		memfill (lkact, 1, c_max_bolts);
	#endif		

	if (!warp_to_level)	{
		n_pant = SCR_INI;
		px = (4 + (PLAYER_INI_X << 4)) << FIXBITS;
		py = (PLAYER_INI_Y << 4) << FIXBITS;
	}
	player_to_pixels ();
	player_init ();
		
	#ifdef PERSISTENT_ENEMIES
		enems_persistent_load ();
	#endif		

	#ifdef PERSISTENT_DEATHS
		enems_persistent_deaths_load ();
	#endif

	#ifndef DEACTIVATE_OBJECTS
		pobjs = 0;
	#endif

	#ifdef HOTSPOT_TYPE_STAR
		pstars = 0;
	#endif

	#ifndef DEACTIVATE_KEYS	
		pkeys = 0;
	#endif

	#ifdef ENABLE_RESONATORS
		res_on = 0;
		res_disable = 0;
	#endif

	#ifdef ENABLE_USE_ANIM
		if (!warp_to_level) use_ct = 0;
	#endif

	#ifdef ENABLE_NO
		no_ct = 0;
	#endif	

	#ifdef ENABLE_PROPELLERS
		#ifdef PROPELLERS_ON_BY_DEFAULT
			propellers_on = 1;
		#else
			propellers_on = 0;
		#endif
	#endif

	#ifdef ENABLE_SPRINGS
		#ifdef SPRINGS_ON_BY_DEFAULT
			springs_on = 1;
		#else
			springs_on = 0;
		#endif
	#endif

	#ifdef ENABLE_TIMER
		#ifndef TIMER_RESET_ON_ENTER
			timer = TIMER_INITIAL;
			timer_frames = 50;
			timer_zero = 0;
			otimer = 0xff;
		#endif
		#ifdef TIMER_START_ON
			timer_on = 1;
		#else
			timer_on = 0;
		#endif
	#endif

	half_life = 0;
	frame_counter = 0;
	olife = oammo = oobjs = okeys = 0xff;
	okilled = 0xff;

	#include "my/extra_inits.h"

	#if defined (ENABLE_INTERACTIVES) && defined (INTERACTIVES_FROM_CODE)
		#include "my/interactives_setup.h"
	#endif
}

void prepare_scr (void) {
	if (!ft) fade_out (); else ft = 0;

	ppu_off ();

	#ifdef ENABLE_PROPELLERS
		// Clear propellers
		prp_idx = 0;
	#endif

	#ifdef PERSISTENT_ENEMIES
		// Preserve enems
		enems_persistent_update ();
	#endif

	enems_load ();
	hotspots_create ();	

	#ifdef ENABLE_COCOS
		cocos_init ();
	#endif	

	#if defined (ACTIVATE_SCRIPTING) && defined (ENABLE_FIRE_ZONE)
		f_zone_ac = 0;
		fzx1 = fzx2 = fzy1 = fzy2 = 240;
	#endif

	#ifdef ENABLE_SHINES
		shine_active_ct = 0;
		max_shines = 0;
	#endif

	#ifdef ENABLE_TILE_CHAC_CHAC
		chac_chacs_queue_write = chac_chacs_queue_read = 0;
		max_chac_chacs = 0;
	#endif

		draw_scr ();

	#if defined (ENABLE_BREAKABLE) && defined (BREAKABLE_ANIM)
		do_process_breakable = 0;
		gpit = BREAKABLE_MAX; while (gpit --) brkf [gpit] = 0;
	#endif

	#ifdef LINE_OF_TEXT
		_x = LINE_OF_TEXT_X; _y = LINE_OF_TEXT;
		pr_str ("                              ");
	#endif

	#if defined (DIE_AND_RESPAWN) && (defined (PLAYER_SWIMS) || defined (PLAYER_TOP_DOWN))
		player_register_safe_spot ();
	#endif

	#ifdef PLAYER_CAN_FIRE
		for (gpit = 0; gpit < MAX_BULLETS; gpit ++) {
			b_slots [gpit] = gpit; bst [gpit] = 0;
		}
		b_slots_i = MAX_BULLETS;
	#endif

	#ifdef ENABLE_INTERACTIVES
		#ifdef INTERACTIVES_FROM_CODE
			interactives_create ();
		#else
			interactives_index = 0;
		#endif

		interactives_interact_with = 0xff;
	#endif
	
	// Reenable sprites and tiles now we are finished.
	#ifdef CNROM
		bankswitch (l_chr_rom_bank [level]);
	#endif

	ppu_on_all ();

	#ifdef ACTIVATE_SCRIPTING
		#if defined (ENABLE_PUSHED_SCRIPT)
			just_pushed = 0;
		#endif
		#if defined (ENABLE_INTERACTIVES)
			just_interacted = 0;
		#endif
		// Entering any script
		run_script (2 * MAP_SIZE + 1);
		// This room script
		run_script (n_pant << 1);
	#endif

	#include "my/on_entering_screen.h"

	gpit = 3; while (gpit --) en_spr_id [gpit] = en_s [gpit];
	
	oam_index = 4;
	prx = px >> FIXBITS; pry = py >> FIXBITS;
	#if defined (PLAYER_PUNCHES) || defined (PLAYER_KICKS)
		phitteract = 0;
	#endif	

	player_move ();
	player_render ();
	enems_move ();
	if (hrt) hotspots_paint ();
	
	#ifdef ENABLE_INTERACTIVES	
		interactives_paint ();
	#endif

	#ifdef ENABLE_TIMER
		#ifdef TIMER_RESET_ON_ENTER
			timer = TIMER_INITIAL;
			timer_frames = 50;
			timer_zero = 0;
			otimer = 0xff;
		#endif
	#endif

	oam_hide_rest (oam_index);
	hud_update ();
	ppu_waitnmi ();
	clear_update_list ();
	oam_index = 4;
	fade_in ();
}

void game_loop (void) {
	#ifdef MULTI_LEVEL
		music_play (l_music [level]);
	#else
		music_play (MUSIC_INGAME);
	#endif

	clear_update_list ();
	set_vram_update (UPDATE_LIST_SIZE, update_list);

	on_pant = 99; ft = 1; fade_delay = 1;

	// MAIN LOOP

	pal_bright (0);
	ppu_on_all ();
	
	#ifdef ACTIVATE_SCRIPTING
		#ifdef CLEAR_FLAGS
			msc_clear_flags ();
		#endif
		
		// Entering game script
		run_script (2 * MAP_SIZE);
	#endif

	warp_to_level = 0; oam_index = 0; ticker = 50;
	
	while (1) {

		// Finish him

		if (pkill) player_kill ();
		if (game_over) break;			

		// Flick the screen

		flick_override = 0;
		#include "my/custom_flickscreen.h"
		#include "mainloop/flickscreen.h"
		
		// Change screen ?

		if (on_pant != n_pant && !warp_to_level) {
			prepare_scr ();
			on_pant = n_pant;
		}

		// Relocate player if spawned on a broken tile

		#if defined (ENABLE_BREAKABLE)
		if (pmayneedrelocation) {
			pmayneedrelocation = 0;
			gpit = 16;
			while (gpit --) {
				cx1 = prx >> 4; cx2 = (prx + 7) >> 4;
				cy1 = cy2 = (pry + 15) >> 4;
				cm_two_points ();
				if ((at1 & 8) == 0 && (at2 & 8) == 0) break;
				prx += 16;	// Try next cell
			}
			px = prx << FIXBITS;
		}
		#endif

		// Update hud

		#ifdef ACTIVATE_SCRIPTING
			if (n_pant != 0xfe && on_pant != 0xfe) 
		#endif
			hud_update ();

		// Shake the screen ? 

		#ifdef ENABLE_SHAKER
			#include "mainloop/shaker.h"
		#endif

		// Finish frame and wait for NMI

		oam_hide_rest (oam_index);
		ppu_waitnmi ();
		clear_update_list ();
		oam_index = 4;

		// Poll pads

		pad_read ();
		a_button = (pad_this_frame & PAD_A);
		b_button = (pad_this_frame & PAD_B);

		// Update actors if not paused...

		if (paused == 0) {

			// Count frames		
			if (ticker) -- ticker; else ticker = 50;
			half_life ^= 1;
			++ frame_counter;

			// Timer

			#ifdef ENABLE_TIMER
				#include "mainloop/timer.h"
			#endif

			// Extra checks

			#include "my/extra_checks.h"

			// Win level condition

			if (
			#if defined (WIN_LEVEL_CUSTOM)
				win_level
			#elif defined (ACTIVATE_SCRIPTING)
				script_result == 1
			#elif defined (PLAYER_MAX_OBJECTS)
				pobjs == PLAYER_MAX_OBJECTS
			#elif defined (SCR_END)
				(
					n_pant == SCR_END && 
					((prx + 8) >> 4) == PLAYER_END_X &&
					((pry + 8) >> 4) == PLAYER_END_Y
				) 
			#endif
			) {
				music_stop ();
				delay (50);
				break;
			}

			// Warp to level

			if (warp_to_level) {
				music_stop (); break;
			}

			// Update propellers

			#ifdef ENABLE_PROPELLERS
				if (propellers_on) propellers_do ();
			#endif

			// Detect interactions

			#ifdef ENABLE_INTERACTIVES
				#include "mainloop/interactives.h"
			#endif		

			// Update / collide hotspots

			#include "mainloop/hotspots.h"

			// Update player

			if (!warp_to_level) {
				player_move ();
				player_render ();
			}

			// Automatic scripting calls (USE_ANIM & fire zone)

			#ifdef ACTIVATE_SCRIPTING
				#include "mainloop/scripting.h"
			#endif

			// Update bullets

			#ifdef PLAYER_CAN_FIRE
				bullets_move ();
			#endif

			// Update cocos

			#ifdef ENABLE_COCOS
				cocos_do ();
			#endif

			// Update enemies
		
			enems_move ();

			// Do resonators

			#ifdef ENABLE_RESONATORS
				#include "mainloop/resonators.h"
			#endif

			// Paint hotspots

			if (hrt) hotspots_paint ();

			// Paint interactives

			#ifdef ENABLE_INTERACTIVES
				interactives_paint ();
			#endif

			// Do breakable tiles

			#if defined (ENABLE_BREAKABLE) && defined (BREAKABLE_ANIM)
				if (do_process_breakable) breakable_do_anim ();
			#endif

			// Update shines

			#ifdef ENABLE_SHINES
				shines_do ();
			#endif

			// Update no

			#ifdef ENABLE_NO
				#include "mainloop/no.h"
			#endif

			// Update chac-chacs

			#ifdef ENABLE_TILE_CHAC_CHAC
				chac_chacs_do ();
			#endif
		}

		// Cheat to skip level

		#include "mainloop/cheat.h"

		// Pause

		#include "mainloop/pause.h"
	}

	fade_delay = 4;
	music_stop ();
	fade_out ();
	set_vram_update (0, 0);
	ppu_off ();
	oam_clear ();
}
