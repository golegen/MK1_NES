// NES MK1 v0.2
// Copyleft Mojon Twins 2013, 2015

// printer.h
// Draw map, print text, etcetera.


// fade out
void __fastcall__ fade_out (void) {
	for (fader = 4; fader > -1; fader --) {
		pal_bright (fader);
		delay (fade_delay);
	}	
}

// fade in
void __fastcall__ fade_in (void) {
	for (fader = 0; fader < 5; fader ++) {
		pal_bright (fader);
		delay (fade_delay);
	}	
}

// Clear update list
void __fastcall__ clear_update_list (void) {
	for (i = 0; i < UPDATE_LIST_SIZE * 3; i ++)
		update_list [i] = 0;	
}

void __fastcall__ cls (void) {
	vram_adr(0x2000);
	vram_fill(255,0x3c0);
	vram_adr (0x23c0);
	vram_fill(0xff,64);
}

const unsigned char bitmasks [] = {0xfc, 0xf3, 0xcf, 0x3f};
unsigned char attr_table [64];

void draw_tile (unsigned char x, unsigned char y, unsigned char tl) {
	rdc = (x >> 2) + ((y >> 2) << 3);
	rdb = ((x >> 1) & 1) + (((y >> 1) & 1) << 1);
	rda = attr_table [rdc];
	rda = (rda & bitmasks [rdb]) | (tileset_pals [tl] << (rdb << 1));
	attr_table [rdc] = rda;
	
	gp_tmap = tsmap + (tl << 2);
	gp_addr = ((y<<5) + x + 0x2000);
	vram_adr (gp_addr++);
	vram_put (*gp_tmap++);
	vram_put (*gp_tmap++);
	gp_addr+=31;
	vram_adr (gp_addr++);
	vram_put (*gp_tmap++);
	vram_put (*gp_tmap);	
}

void update_list_tile (unsigned char x, unsigned char y, unsigned char tl) {
	// Attribute
	rdc = (x >> 2) + ((y >> 2) << 3);
	rdb = ((x >> 1) & 1) + (((y >> 1) & 1) << 1);
	rda = attr_table [rdc];
	rda = (rda & bitmasks [rdb]) | (tileset_pals [tl] << (rdb << 1));
	attr_table [rdc] = rda;
	
	gp_addr = 0x23c0 + rdc;
	update_list [update_index++] = MSB(gp_addr);
	update_list [update_index++] = LSB(gp_addr);
	update_list [update_index++] = rda;
	
	// tiles
	//tl = (16 + tl) << 2;
	gp_tmap = tsmap + (tl << 2);
	gp_addr = ((y<<5) + x + 0x2000);
	update_list [update_index++] = MSB(gp_addr);
	update_list [update_index++] = LSB(gp_addr++);
	update_list [update_index++] = *gp_tmap++;
	update_list [update_index++] = MSB(gp_addr);
	update_list [update_index++] = LSB(gp_addr);
	update_list [update_index++] = *gp_tmap++;
	gp_addr += 31;
	update_list [update_index++] = MSB(gp_addr);
	update_list [update_index++] = LSB(gp_addr++);
	update_list [update_index++] = *gp_tmap++;
	update_list [update_index++] = MSB(gp_addr);
	update_list [update_index++] = LSB(gp_addr);
	update_list [update_index++] = *gp_tmap;
}

void p_t (unsigned char x, unsigned char y, unsigned char n) {
	gp_addr = (y << 5) + x + 0x2000;
	update_list [update_index++] = MSB (gp_addr);
	update_list [update_index++] = LSB (gp_addr++);
	update_list [update_index++] = (n / 10) + 16;
	update_list [update_index++] = MSB (gp_addr);
	update_list [update_index++] = LSB (gp_addr);
	update_list [update_index++] = (n % 10) + 16;
}

#ifdef DEBUG
unsigned char hexchar (unsigned char n) {
	return n < 10 ? 16 + n : 23 + n;
}

void p_th (unsigned char x, unsigned char y, unsigned char n) {
	gp_addr = (y << 5) + x + 0x2000;
	update_list [update_index++] = MSB (gp_addr);
	update_list [update_index++] = LSB (gp_addr++);
	update_list [update_index++] = hexchar (n >> 4);
	update_list [update_index++] = MSB (gp_addr);
	update_list [update_index++] = LSB (gp_addr);
	update_list [update_index++] = hexchar (n & 15);	
}
#endif

void __fastcall__ draw_scr (void) {
	// Clear attribute table
	//for (rdit = 0; rdit < 56; rdit ++) attr_table [rdit] = 0xff;
	
	// Draw current screen
	gp_gen = (unsigned char *) (c_map) + n_pant * 96; rdx = 0; rdy = TOP_ADJUST;
	
	for (rdit = 0; rdit < 192; rdit ++) {
		if ((rdit & 1) == 0) {
			rdt = gp_gen [rdit >> 1] >> 4;
		} else {
			rdt = gp_gen [rdit >> 1] & 15;
		}
		
		map_buff [rdit] = rdt;		
		map_attr [rdit] = tbehs [rdt];		
#ifdef BREAKABLE_WALLS
		brk_buff [rdit] = 1;
#endif
		if (rdt == 0 && (rand8 () & 7) == 1) rdt = 16;	// ALT BG

		draw_tile (rdx, rdy, rdt);
		
		rdx = (rdx + 2) & 31; if (!rdx) rdy +=2;
	}
	
	// Clear open locks
#ifndef DEACTIVATE_KEYS	
	for (gpit = 0; gpit < MAX_CERROJOS; gpit ++) {
		if (n_pant == lknp [gpit]) {
			if (!lkact [gpit]) {
				rdx = (lkxy [gpit] >> 4);
				rdy = (lkxy [gpit] & 15);
				draw_tile (rdx << 1, (rdy << 1) + TOP_ADJUST, 0);
				rdit = rdx + (rdy << 4);
				map_attr [rdit] = 0;
				map_buff [rdit] = 0;
			}
		}
	}	
#endif

#ifdef BREAKABLE_ANIM
	do_process_breakable = 0;
	for (gpit = 0; gpit < MAX_BREAKABLE; gpit ++) brkf [gpit] = 0;
#endif
}

void pr_str (unsigned char x, unsigned char y, unsigned char *s) {
	gp_addr = ((y<<5) + x + 0x2000);
	vram_adr (gp_addr);
	while (gpit = *s++) {
		if (gpit != '_') vram_put (gpit - 32); else vram_put (0);
	}
}

void __fastcall__ un_rle_screen (unsigned char *rle) {
	rdx = 0; rdy = 0; gpit = 0;
	while (gpit < 240) {
		rdt = (*rle ++);
		if (rdt & 128) {
			gpjt = rdt & 127;
			rdt = (*rle ++);
			while (0 < gpjt--) {
				draw_tile (rdx, rdy, rdt);
				rdx = (rdx + 2) & 31; if (!rdx) rdy += 2;
				gpit ++;
			}
		} else {
			draw_tile (rdx, rdy, rdt);
			rdx = (rdx + 2) & 31; if (!rdx) rdy +=2;
			gpit ++;
		}
	}
	// 64 attributes
	gpit = 64; vram_adr (0x23c0);
	while (0 < gpit--) vram_put (*rle ++);
}
