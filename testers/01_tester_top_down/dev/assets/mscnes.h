// NES MK1 v2.0
// Copyleft Mojon Twins 2013, 2015, 2017, 2018

// ..\dev\assets\mscnes.h - Script pools and scripts interpreter
// generated by mscMK1 1.1 by the Mojon Twins

const unsigned char script_pool_0 [] = {
/*            0     1     2     3     4     5     6     7     8     9     A     B     C     D     E     F */
/* 0000 */ 0x6c, 0x00, 0xbd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* 0001 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* 0002 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* 0003 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* 0004 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* 0005 */ 0x00, 0x00, 0x00, 0x00, 0x13, 0x01, 0x28, 0x01, 0x00, 0x00, 0x00, 0x00, 0x60, 0x01, 0x00, 0x00, 
/* 0006 */ 0x68, 0x01, 0x70, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0xf0, 0xff, 0xf4, 
/* 0007 */ 0x64, 0x10, 0x74, 0x11, 0x84, 0x12, 0x65, 0x13, 0x75, 0x14, 0x85, 0x15, 0xff, 0x51, 0x00, 0x01, 
/* 0008 */ 0xff, 0x8f, 0xff, 0x11, 0x10, 0x01, 0x01, 0xff, 0xf4, 0x45, 0x18, 0x43, 0x18, 0x72, 0x18, 0xa3, 
/* 0009 */ 0x18, 0xa5, 0x18, 0xff, 0xff, 0x26, 0x10, 0x01, 0x00, 0xff, 0xe3, 0x1e, 0x53, 0x45, 0x54, 0x20, 
/* 000A */ 0x42, 0x4f, 0x4d, 0x42, 0x53, 0x20, 0x49, 0x4e, 0x20, 0x43, 0x4f, 0x4d, 0x50, 0x55, 0x54, 0x45, 
/* 000B */ 0x52, 0x20, 0x41, 0x4e, 0x44, 0x20, 0x52, 0x55, 0x4e, 0x21, 0x00, 0xff, 0xff, 0x54, 0x21, 0x50, 
/* 000C */ 0x9f, 0x22, 0x20, 0x6f, 0x41, 0x05, 0x10, 0x01, 0x00, 0xff, 0x01, 0x01, 0x01, 0x20, 0x04, 0x05, 
/* 000D */ 0x18, 0xe1, 0xe0, 0x00, 0x20, 0x04, 0x03, 0x18, 0xe1, 0xe0, 0x00, 0x20, 0x07, 0x02, 0x18, 0xe1, 
/* 000E */ 0xe0, 0x00, 0x20, 0x0a, 0x03, 0x18, 0xe1, 0xe0, 0x00, 0x20, 0x0a, 0x05, 0x18, 0xe1, 0xe0, 0x00, 
/* 000F */ 0xe3, 0x1e, 0x20, 0x20, 0x44, 0x4f, 0x4e, 0x45, 0x21, 0x20, 0x4e, 0x4f, 0x57, 0x20, 0x47, 0x4f, 
/* 0010 */ 0x20, 0x42, 0x41, 0x43, 0x4b, 0x20, 0x54, 0x4f, 0x20, 0x42, 0x41, 0x53, 0x45, 0x21, 0x20, 0x20, 
/* 0011 */ 0x00, 0xff, 0xff, 0x13, 0xf0, 0xff, 0x20, 0x01, 0x04, 0x16, 0x20, 0x02, 0x04, 0x17, 0x01, 0x02, 
/* 0012 */ 0x00, 0x51, 0x20, 0x20, 0x32, 0x5f, 0xff, 0xff, 0x36, 0x21, 0x20, 0x3f, 0x22, 0x21, 0x5f, 0x10, 
/* 0013 */ 0x02, 0x00, 0xff, 0x01, 0x02, 0x01, 0xe0, 0x09, 0xe3, 0x1e, 0x20, 0x48, 0x41, 0x4c, 0x46, 0x20, 
/* 0014 */ 0x4e, 0x45, 0x57, 0x20, 0x4d, 0x4f, 0x54, 0x4f, 0x52, 0x42, 0x49, 0x4b, 0x45, 0x20, 0x46, 0x4f, 
/* 0015 */ 0x52, 0x20, 0x53, 0x41, 0x4c, 0x45, 0x21, 0x20, 0x00, 0xe1, 0xe0, 0x00, 0xe0, 0x08, 0xff, 0xff, 
/* 0016 */ 0x06, 0x10, 0x01, 0x01, 0xff, 0xf1, 0xff, 0xff, 0x06, 0xf0, 0xff, 0x01, 0x01, 0x00, 0xff, 0xff, 
/* 0017 */ 0x26, 0x10, 0x01, 0x00, 0xff, 0xe3, 0x1e, 0x20, 0x53, 0x45, 0x54, 0x20, 0x35, 0x20, 0x42, 0x4f, 
/* 0018 */ 0x4d, 0x42, 0x53, 0x20, 0x49, 0x4e, 0x20, 0x45, 0x56, 0x49, 0x4c, 0x20, 0x43, 0x4f, 0x4d, 0x50, 
/* 0019 */ 0x55, 0x54, 0x45, 0x52, 0x20, 0x00, 0xff, 0x26, 0x10, 0x01, 0x01, 0xff, 0xe3, 0x1e, 0x42, 0x4f, 
/* 001A */ 0x4d, 0x42, 0x53, 0x20, 0x41, 0x52, 0x45, 0x20, 0x53, 0x45, 0x54, 0x21, 0x20, 0x52, 0x45, 0x54, 
/* 001B */ 0x55, 0x52, 0x4e, 0x20, 0x54, 0x4f, 0x20, 0x42, 0x41, 0x53, 0x45, 0x21, 0x00, 0xff, 0xff
};

const unsigned char * const script_pool [] = {
    script_pool_0, 
    script_pool_0
};

#ifdef CLEAR_FLAGS
void msc_clear_flags (void) {
    memfill (flags, 0, MAX_FLAGS);
}
#endif

unsigned char read_byte (void) {
    return *script ++;
}

unsigned char read_vbyte (void) {
    sc_c = *script ++;
    if (sc_c & 128) return flags [sc_c & 127];
    return sc_c;
}

void readxy (void) {
    sc_x = read_vbyte ();
    sc_y = read_vbyte ();
}

void run_script (unsigned char whichs) {
    // read address offset from index
    gp_gen = (unsigned char *) script_pool [level] + (whichs << 1);
    rda = *gp_gen ++; rdb = *gp_gen;
    script_result = 0;
    if (!(rda | rdb)) return;
    script = (unsigned char *) script_pool [level] + rda + (rdb << 8);

    while ((sc_c = read_byte ()) != 0xff) {
        next_script = script + sc_c;
        sc_terminado = sc_continuar = 0;
        while (!sc_terminado) {
            switch (read_byte ()) {
                case 0x10: readxy (); sc_terminado = (flags [sc_x] != sc_y); break;
                case 0x21: sc_terminado = (!(prx >= read_byte () && prx <= read_byte ())); break;
                case 0x22: sc_terminado = (!(pry >= read_byte () && pry <= read_byte ())); break;
                case 0x41: sc_terminado = (pobjs != read_vbyte ()); break;
                case 0xf0: break;
                case 0xff: sc_terminado = sc_continuar = 1; break;
            }
        }

        if (sc_continuar) {
            fire_script_success = 1;
            sc_terminado = 0;
            while (!sc_terminado) {
                switch (read_byte ()) {
                    case 0x01: readxy (); flags [sc_x] = sc_y; break;
                    case 0x20: readxy (); _x = sc_x; _y = sc_y; _t = read_vbyte (); map_set (); break;
                    case 0x51: f_zone_ac = 1; fzx1 = read_byte (); fzy1 = read_byte (); fzx2 = read_byte (); fzy2 = read_byte (); break;
                    case 0xe1: ppu_waitnmi (); clear_update_list (); break;
                    case 0xe3: _x = LINE_OF_TEXT_X; _y = LINE_OF_TEXT; gp_gen = script; sc_n = read_byte (); script += (sc_n + 1); pr_ul_str (); break;
                    case 0xf4: while (0xff != (sc_x = read_byte ())) { _x = sc_x >> 4; _y = sc_x & 15; _t = read_byte (); map_set (); ppu_waitnmi (); clear_update_list (); } break;
                    case 0xe0: sfx_play (read_vbyte (), 1); break;
                    case 0xf1: script_result = 1; return;
                    case 0xff: sc_terminado = 1; break;
                }
            }
        }
        script = next_script;
    }
}
