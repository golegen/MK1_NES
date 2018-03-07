// NES MK1 v1.0
// Copyleft Mojon Twins 2013, 2015, 2017, 2018

// ..\dev\assets\mscnes.h - script data and interpreter
// generated by mscMK1 1.0 by the Mojon Twins

const unsigned char script_pool_0 [] = {
/*            0     1     2     3     4     5     6     7     8     9     A     B     C     D     E     F */
/* 0000 */ 0x20, 0x00, 0x37, 0x00, 0x47, 0x00, 0x4f, 0x00, 0x58, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 
/* 0001 */ 0x68, 0x00, 0x00, 0x00, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* 0002 */ 0x0e, 0x10, 0x05, 0x06, 0xff, 0x20, 0x08, 0x06, 0x03, 0x51, 0xe9, 0x01, 0xff, 0x7f, 0xff, 0x06, 
/* 0003 */ 0xf0, 0xff, 0x86, 0xa2, 0x08, 0xff, 0xff, 0x06, 0x21, 0xe1, 0xff, 0xff, 0xf1, 0xff, 0x07, 0x61, 
/* 0004 */ 0x62, 0x08, 0xff, 0xed, 0x00, 0xff, 0xff, 0x06, 0xf0, 0xff, 0x86, 0x98, 0x85, 0xff, 0xff, 0x07, 
/* 0005 */ 0x61, 0x63, 0x85, 0xff, 0xed, 0x01, 0xff, 0xff, 0x06, 0xf0, 0xff, 0x86, 0x94, 0x81, 0xff, 0xff, 
/* 0006 */ 0x06, 0xf0, 0xff, 0x86, 0x5e, 0x82, 0xff, 0xff, 0x09, 0xf0, 0xff, 0x86, 0x31, 0x83, 0x86, 0x4d, 
/* 0007 */ 0x84, 0xff, 0xff, 0x15, 0xf0, 0xff, 0x01, 0x00, 0x00, 0x01, 0x01, 0x04, 0x01, 0x02, 0x05, 0x01, 
/* 0008 */ 0x03, 0x06, 0x01, 0x04, 0x07, 0x01, 0x05, 0x00, 0xff, 0xff
};

const unsigned char * const script_pool [] = {
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
    gp_gen = (unsigned char *) script_pool [level] + whichs + whichs;
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
                case 0x61: sc_terminado = (!just_interacted); break;
                case 0x62: sc_terminado = (script_arg != read_vbyte ()); break;
                case 0x63: sc_terminado = (script_arg != read_byte ()); break;
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
                    case 0xed: gp_gen = custom_texts [read_vbyte ()]; textbox_do (); break;
                    case 0x86: sc_x = read_byte (); sc_y = read_byte (); containers_add (); break;
                    case 0xf1: script_result = 1; return;
                    case 0xff: sc_terminado = 1; break;
                }
            }
        }
        script = next_script;
    }
}
