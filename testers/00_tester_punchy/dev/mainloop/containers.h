// NES MK1 v1.0
// Copyleft Mojon Twins 2013, 2015, 2017, 2018

// Containers interaction

if (containers_index) {
	if (
		b_button
		#ifdef ENABLE_USE_ANIM
			&& use_ct == 0
		#endif
	) {
		rdx = prx + 4; rdy = pry + 8;

		gpit = containers_index; while (gpit --) {
			rda = containers_yx [gpit]; rdb = rda << 4; rdc = rda & 0xf0;
			if (
				collide_in (rdx, rdy, rdb, rdc)
				#ifndef PLAYER_TOP_DOWN
					/*&& ppossee*/
				#endif
			) {
				#ifdef ENABLE_USE_ANIM
					// Only if it is a genuine container				
					if (containers_f [gpit] & 0x80) {
						use_ct = 1; use_sub_ct = USE_ANIM_FRAMES_PER_STEP;
						use_type = USE_TYPE_CONTAINER;
					}
				#endif
				containers_interact_with = gpit;
				b_button = 0;
				break;
			}
			
		}
	}

	if (containers_interact_with != 0xff) {
		script_arg = containers_f [containers_interact_with];
		if (script_arg & 0x80) {
			#ifdef ENABLE_USE_ANIM
				if (use_ct == USE_ANIM_INTERACT_ON && use_sub_ct == USE_ANIM_FRAMES_PER_STEP)
			#endif
			{
				rda = script_arg & 0x7f;
				rdb = flags [rda];
				flags [rda] = flags [FLAG_INVENTORY];
				flags [FLAG_INVENTORY] = rdb;
				sfx_play (SFX_OBJECT, 1);

				// Object has been got. You may complete here. You are using scripting but just in case.
				#include "my/on_object_got.h"
			}
		}
		
		// Run script; script_arg is set, alwyas success
		just_interacted = 1;
		run_fire_script ();
		fire_script_success = 1;
		containers_interact_with = 0xff;
	}
}