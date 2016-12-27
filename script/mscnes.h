// script data and interpreter
// generated by msc3nes by the mojon twins

unsigned char sc_x, sc_y, sc_n, sc_c;
unsigned char *next_script;
unsigned char *script;
unsigned char script_result, sc_terminado, sc_continuar;

const unsigned char script_pool [] = {
/*            0     1     2     3     4     5     6     7     8     9     A     B     C     D     E     F */
/* 0000 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* 0001 */ 0x84, 0x00, 0x00, 0x00, 0x8d, 0x00, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* 0002 */ 0x00, 0x00, 0x00, 0x00, 0xe4, 0x00, 0xfa, 0x00, 0x9d, 0x01, 0xa5, 0x01, 0x00, 0x00, 0x00, 0x00, 
/* 0003 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb8, 0x01, 0xc4, 0x01, 0xf3, 0x01, 0xfb, 0x01, 
/* 0004 */ 0x39, 0x02, 0x3e, 0x02, 0x9a, 0x02, 0xa2, 0x02, 0x00, 0x00, 0x00, 0x00, 0x5a, 0x03, 0x66, 0x03, 
/* 0005 */ 0x00, 0x00, 0x00, 0x00, 0x7e, 0x03, 0xab, 0x03, 0x7c, 0x04, 0xa9, 0x04, 0x00, 0x00, 0x00, 0x00, 
/* 0006 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* 0007 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7a, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
/* 0008 */ 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0xff, 0x86, 0x01, 0x02, 0x09, 0xff, 0xff, 0x0c, 0xf0, 0xff, 
/* 0009 */ 0x01, 0x0f, 0x02, 0x01, 0x0e, 0x04, 0x01, 0x0d, 0x03, 0xff, 0xff, 0x17, 0x20, 0x05, 0x09, 0xff, 
/* 000A */ 0x20, 0x05, 0x8f, 0x0d, 0x20, 0x05, 0x8f, 0x00, 0x20, 0x09, 0x8d, 0x0d, 0x20, 0x09, 0x8d, 0x00, 
/* 000B */ 0xe0, 0x06, 0xff, 0x17, 0x20, 0x07, 0x09, 0xff, 0x20, 0x07, 0x8e, 0x0d, 0x20, 0x07, 0x8e, 0x00, 
/* 000C */ 0x20, 0x09, 0x8d, 0x0d, 0x20, 0x09, 0x8d, 0x00, 0xe0, 0x06, 0xff, 0x17, 0x20, 0x09, 0x09, 0xff, 
/* 000D */ 0x20, 0x05, 0x8f, 0x0d, 0x20, 0x05, 0x8f, 0x00, 0x20, 0x07, 0x8e, 0x0d, 0x20, 0x07, 0x8e, 0x00, 
/* 000E */ 0xe0, 0x06, 0xff, 0xff, 0x14, 0xf0, 0xff, 0x01, 0x0f, 0x00, 0x01, 0x0e, 0x00, 0x01, 0x0d, 0x00, 
/* 000F */ 0x01, 0x0c, 0x00, 0x51, 0x81, 0x31, 0x9f, 0x6f, 0xff, 0xff, 0x2f, 0x20, 0x0c, 0x06, 0xff, 0xeb, 
/* 0010 */ 0xe3, 0x33, 0x29, 0x27, 0x2e, 0x00, 0x33, 0x21, 0x39, 0x33, 0xee, 0xe3, 0x00, 0x33, 0x34, 0x29, 
/* 0011 */ 0x23, 0x2b, 0x00, 0x34, 0x2f, 0x00, 0x34, 0x28, 0x25, 0xee, 0xe3, 0x00, 0x28, 0x25, 0x21, 0x32, 
/* 0012 */ 0x34, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0xee, 0xec, 0xff, 0x14, 0x20, 0x0d, 0x0a, 0x10, 0x0f, 
/* 0013 */ 0x00, 0xff, 0x01, 0x0f, 0x01, 0xf4, 0x15, 0x00, 0x16, 0x00, 0xff, 0xe0, 0x06, 0xf2, 0xff, 0x17, 
/* 0014 */ 0x21, 0x81, 0x9f, 0x10, 0x0e, 0x00, 0xff, 0x01, 0x0e, 0x01, 0x20, 0x09, 0x06, 0x0b, 0xe0, 0x06, 
/* 0015 */ 0x51, 0x51, 0x31, 0x6f, 0x6f, 0xf2, 0xff, 0x1e, 0x21, 0x51, 0x6f, 0x22, 0x31, 0x5f, 0x10, 0x0d, 
/* 0016 */ 0x00, 0xff, 0x01, 0x0d, 0x01, 0xf4, 0x64, 0x0a, 0x65, 0x0a, 0x66, 0x0a, 0xff, 0xe0, 0x06, 0x51, 
/* 0017 */ 0x21, 0x31, 0x3f, 0x6f, 0xf2, 0xff, 0x15, 0x21, 0x51, 0x6f, 0x10, 0x0d, 0x00, 0xff, 0x01, 0x0d, 
/* 0018 */ 0x01, 0xf4, 0xff, 0xe0, 0x05, 0x51, 0x21, 0x31, 0x3f, 0x6f, 0xf2, 0xff, 0x0f, 0x10, 0x0c, 0x00, 
/* 0019 */ 0xff, 0x01, 0x0c, 0x01, 0x20, 0x03, 0x06, 0x0b, 0xe0, 0x06, 0xf2, 0xff, 0xff, 0x06, 0xf0, 0xff, 
/* 001A */ 0x01, 0x0f, 0x00, 0xff, 0xff, 0x11, 0x20, 0x0a, 0x02, 0x10, 0x0f, 0x00, 0xff, 0xf4, 0x12, 0x00, 
/* 001B */ 0x13, 0x00, 0xff, 0xe0, 0x06, 0xf2, 0xff, 0xff, 0x0a, 0xf0, 0xff, 0x86, 0x06, 0x0d, 0x06, 0x01, 
/* 001C */ 0x0f, 0x00, 0xff, 0xff, 0x16, 0x20, 0x04, 0x02, 0x10, 0x0f, 0x00, 0xff, 0xf4, 0x64, 0x0e, 0x65, 
/* 001D */ 0x0d, 0x42, 0x31, 0xff, 0x01, 0x0f, 0x01, 0xe0, 0x06, 0xf2, 0xff, 0x16, 0x20, 0x04, 0x02, 0x10, 
/* 001E */ 0x0f, 0x01, 0xff, 0xf4, 0x64, 0x00, 0x65, 0x00, 0x42, 0x30, 0xff, 0x01, 0x0f, 0x00, 0xe0, 0x06, 
/* 001F */ 0xf2, 0xff, 0xff, 0x06, 0xf0, 0xff, 0x01, 0x0f, 0x00, 0xff, 0xff, 0x1e, 0x20, 0x08, 0x0a, 0x10, 
/* 0020 */ 0x0f, 0x00, 0xff, 0xf4, 0xc2, 0x07, 0xc3, 0x08, 0xc4, 0x07, 0xc5, 0x08, 0xc6, 0x07, 0xc7, 0x00, 
/* 0021 */ 0x8a, 0x31, 0xff, 0x01, 0x0f, 0x01, 0xe0, 0x06, 0xf2, 0xff, 0x1d, 0x20, 0x08, 0x0a, 0x10, 0x0f, 
/* 0022 */ 0x01, 0xff, 0xf4, 0xc2, 0x08, 0xc3, 0x07, 0xc4, 0x08, 0xc5, 0x07, 0xc6, 0x08, 0xc7, 0x07, 0x8a, 
/* 0023 */ 0x30, 0xff, 0x01, 0x0f, 0x00, 0xe0, 0x06, 0xff, 0xff, 0x03, 0xf0, 0xff, 0xff, 0xff, 0x15, 0x20, 
/* 0024 */ 0x09, 0x02, 0x10, 0x0f, 0x00, 0xff, 0xf4, 0x92, 0x31, 0x30, 0x00, 0x40, 0x00, 0x50, 0x00, 0xff, 
/* 0025 */ 0xe0, 0x06, 0xf2, 0xff, 0x44, 0x20, 0x03, 0x0a, 0x10, 0x0e, 0x00, 0xff, 0xf4, 0x3a, 0x31, 0x5a, 
/* 0026 */ 0x00, 0x6a, 0x00, 0x7a, 0x00, 0x8a, 0x00, 0x9a, 0x00, 0xaa, 0x00, 0xba, 0x00, 0xff, 0xe0, 0x06, 
/* 0027 */ 0xe5, 0x19, 0xf4, 0x59, 0x0a, 0x5a, 0x0a, 0xff, 0xe0, 0x06, 0xe5, 0x0a, 0xf4, 0x79, 0x0a, 0x7a, 
/* 0028 */ 0x0a, 0xff, 0xe0, 0x06, 0xe5, 0x0a, 0xf4, 0x99, 0x0a, 0x9a, 0x0a, 0xff, 0xe0, 0x06, 0xe5, 0x0a, 
/* 0029 */ 0xf4, 0x26, 0x00, 0x27, 0x00, 0xff, 0xe0, 0x06, 0xff, 0xff, 0x06, 0xf0, 0xff, 0x01, 0x0f, 0x00, 
/* 002A */ 0xff, 0xff, 0x37, 0x20, 0x01, 0x0a, 0x10, 0x0f, 0x01, 0xff, 0xeb, 0xe3, 0x29, 0x00, 0x28, 0x21, 
/* 002B */ 0x36, 0x25, 0x00, 0x21, 0x2c, 0x32, 0x25, 0x21, 0x24, 0x39, 0xee, 0xe3, 0x21, 0x23, 0x34, 0x29, 
/* 002C */ 0x36, 0x21, 0x34, 0x25, 0x24, 0x00, 0x34, 0x28, 0x29, 0x33, 0xee, 0xe3, 0x34, 0x32, 0x21, 0x30, 
/* 002D */ 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0xee, 0xec, 0xf2, 0xff, 0x26, 0x20, 0x01, 0x0a, 0x10, 0x00, 
/* 002E */ 0x07, 0xff, 0xf4, 0x15, 0x00, 0x25, 0x00, 0x35, 0x00, 0x45, 0x00, 0x55, 0x00, 0x65, 0x00, 0x75, 
/* 002F */ 0x00, 0x85, 0x00, 0x95, 0x00, 0xa5, 0x00, 0xb5, 0x00, 0xff, 0x01, 0x0f, 0x01, 0xe0, 0x06, 0xf2, 
/* 0030 */ 0xff, 0x57, 0x20, 0x01, 0x0a, 0xff, 0xeb, 0xe3, 0x34, 0x28, 0x29, 0x33, 0x00, 0x21, 0x23, 0x34, 
/* 0031 */ 0x29, 0x36, 0x21, 0x34, 0x25, 0x33, 0xee, 0xe3, 0x33, 0x2f, 0x2d, 0x25, 0x34, 0x28, 0x29, 0x2e, 
/* 0032 */ 0x27, 0x0f, 0x00, 0x22, 0x35, 0x34, 0xee, 0xe3, 0x29, 0x00, 0x2e, 0x25, 0x25, 0x24, 0x00, 0x21, 
/* 0033 */ 0x00, 0x2c, 0x25, 0x36, 0x25, 0x32, 0xee, 0xe3, 0x34, 0x2f, 0x00, 0x26, 0x29, 0x34, 0x00, 0x29, 
/* 0034 */ 0x2e, 0x00, 0x34, 0x28, 0x29, 0x33, 0xee, 0xe3, 0x28, 0x2f, 0x2c, 0x25, 0x00, 0x0e, 0x00, 0x0e, 
/* 0035 */ 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0xee, 0xec, 0xff, 0xff, 0x0a, 0xf0, 0xff, 0x86, 0x05, 0x0d, 
/* 0036 */ 0x03, 0x01, 0x0f, 0x00, 0xff, 0xff, 0x16, 0x10, 0x0f, 0x00, 0xff, 0x01, 0x0f, 0x01, 0xf4, 0x86, 
/* 0037 */ 0x00, 0x96, 0x00, 0x87, 0x07, 0x97, 0x15, 0x1a, 0x31, 0xff, 0xe0, 0x06, 0xff, 0xff, 0x0f, 0xf0, 
/* 0038 */ 0xff, 0x01, 0x0f, 0x00, 0x01, 0x0e, 0x00, 0x01, 0x0d, 0x00, 0x01, 0x0c, 0x00, 0xff, 0x0d, 0x21, 
/* 0039 */ 0x00, 0x1f, 0xff, 0x51, 0x21, 0x11, 0x3f, 0x5f, 0x01, 0x0b, 0x00, 0xff, 0x0d, 0x21, 0xd1, 0xff, 
/* 003A */ 0xff, 0x51, 0xa1, 0x11, 0xbf, 0x5f, 0x01, 0x0b, 0x01, 0xff, 0xff, 0x19, 0x10, 0x0b, 0x00, 0x21, 
/* 003B */ 0x21, 0x3f, 0x10, 0x0f, 0x00, 0xff, 0x01, 0x0f, 0x01, 0x51, 0x51, 0x11, 0x6f, 0x5f, 0x20, 0x03, 
/* 003C */ 0x05, 0x0b, 0xe0, 0x06, 0xff, 0x19, 0x10, 0x0b, 0x00, 0x21, 0x51, 0x6f, 0x10, 0x0e, 0x00, 0xff, 
/* 003D */ 0x01, 0x0e, 0x01, 0x51, 0x71, 0x11, 0x8f, 0x5f, 0x20, 0x06, 0x05, 0x0b, 0xe0, 0x06, 0xff, 0x19, 
/* 003E */ 0x10, 0x0b, 0x00, 0x21, 0x71, 0x8f, 0x10, 0x0d, 0x00, 0xff, 0x01, 0x0d, 0x01, 0x51, 0xa1, 0x11, 
/* 003F */ 0xbf, 0x5f, 0x20, 0x08, 0x05, 0x0b, 0xe0, 0x06, 0xff, 0x19, 0x10, 0x0b, 0x00, 0x21, 0xa1, 0xbf, 
/* 0040 */ 0x10, 0x0c, 0x00, 0xff, 0x01, 0x0c, 0x01, 0x51, 0xf1, 0xf1, 0xfe, 0xbf, 0x20, 0x0b, 0x05, 0x0b, 
/* 0041 */ 0xe0, 0x06, 0xff, 0x19, 0x10, 0x0b, 0x01, 0x21, 0xa1, 0xbf, 0x10, 0x0c, 0x00, 0xff, 0x01, 0x0c, 
/* 0042 */ 0x01, 0x51, 0x71, 0x11, 0x8f, 0x5f, 0x20, 0x0b, 0x05, 0x0b, 0xe0, 0x06, 0xff, 0x19, 0x10, 0x0b, 
/* 0043 */ 0x01, 0x21, 0x71, 0x8f, 0x10, 0x0d, 0x00, 0xff, 0x01, 0x0d, 0x01, 0x51, 0x51, 0x11, 0x6f, 0x5f, 
/* 0044 */ 0x20, 0x08, 0x05, 0x0b, 0xe0, 0x06, 0xff, 0x19, 0x10, 0x0b, 0x01, 0x21, 0x51, 0x6f, 0x10, 0x0e, 
/* 0045 */ 0x00, 0xff, 0x01, 0x0e, 0x01, 0x51, 0x21, 0x11, 0x3f, 0x5f, 0x20, 0x06, 0x05, 0x0b, 0xe0, 0x06, 
/* 0046 */ 0xff, 0x19, 0x10, 0x0b, 0x01, 0x21, 0x21, 0x3f, 0x10, 0x0f, 0x00, 0xff, 0x01, 0x0f, 0x01, 0x51, 
/* 0047 */ 0xf1, 0xf1, 0xfe, 0xbf, 0x20, 0x03, 0x05, 0x0b, 0xe0, 0x06, 0xff, 0xff, 0x0f, 0xf0, 0xff, 0x01, 
/* 0048 */ 0x0f, 0x00, 0x01, 0x0e, 0x00, 0x01, 0x0d, 0x00, 0x01, 0x0c, 0x00, 0xff, 0x0d, 0x21, 0x00, 0x1f, 
/* 0049 */ 0xff, 0x51, 0x21, 0x11, 0x3f, 0x5f, 0x01, 0x0b, 0x00, 0xff, 0x0d, 0x21, 0xd1, 0xff, 0xff, 0x51, 
/* 004A */ 0xb1, 0x11, 0xcf, 0x5f, 0x01, 0x0b, 0x01, 0xff, 0xff, 0x19, 0x10, 0x0b, 0x00, 0x21, 0x21, 0x3f, 
/* 004B */ 0x10, 0x0f, 0x00, 0xff, 0x01, 0x0f, 0x01, 0x51, 0x51, 0x11, 0x6f, 0x5f, 0x20, 0x03, 0x05, 0x0b, 
/* 004C */ 0xe0, 0x06, 0xff, 0x19, 0x10, 0x0b, 0x00, 0x21, 0x51, 0x6f, 0x10, 0x0e, 0x00, 0xff, 0x01, 0x0e, 
/* 004D */ 0x01, 0x51, 0x81, 0x11, 0x9f, 0x5f, 0x20, 0x06, 0x05, 0x0b, 0xe0, 0x06, 0xff, 0x19, 0x10, 0x0b, 
/* 004E */ 0x00, 0x21, 0x81, 0x9f, 0x10, 0x0d, 0x00, 0xff, 0x01, 0x0d, 0x01, 0x51, 0xb1, 0x11, 0xcf, 0x5f, 
/* 004F */ 0x20, 0x09, 0x05, 0x0b, 0xe0, 0x06, 0xff, 0x19, 0x10, 0x0b, 0x00, 0x21, 0xb1, 0xcf, 0x10, 0x0c, 
/* 0050 */ 0x00, 0xff, 0x01, 0x0c, 0x01, 0x51, 0xf1, 0xf1, 0xfe, 0xbf, 0x20, 0x0c, 0x05, 0x0b, 0xe0, 0x06, 
/* 0051 */ 0xff, 0x19, 0x10, 0x0b, 0x01, 0x21, 0xb1, 0xcf, 0x10, 0x0c, 0x00, 0xff, 0x01, 0x0c, 0x01, 0x51, 
/* 0052 */ 0x81, 0x11, 0x9f, 0x5f, 0x20, 0x0c, 0x05, 0x0b, 0xe0, 0x06, 0xff, 0x19, 0x10, 0x0b, 0x01, 0x21, 
/* 0053 */ 0x81, 0x9f, 0x10, 0x0d, 0x00, 0xff, 0x01, 0x0d, 0x01, 0x51, 0x51, 0x11, 0x6f, 0x5f, 0x20, 0x09, 
/* 0054 */ 0x05, 0x0b, 0xe0, 0x06, 0xff, 0x19, 0x10, 0x0b, 0x01, 0x21, 0x51, 0x6f, 0x10, 0x0e, 0x00, 0xff, 
/* 0055 */ 0x01, 0x0e, 0x01, 0x51, 0x21, 0x11, 0x3f, 0x5f, 0x20, 0x06, 0x05, 0x0b, 0xe0, 0x06, 0xff, 0x19, 
/* 0056 */ 0x10, 0x0b, 0x01, 0x21, 0x21, 0x3f, 0x10, 0x0f, 0x00, 0xff, 0x01, 0x0f, 0x01, 0x51, 0xf1, 0xf1, 
/* 0057 */ 0xfe, 0xbf, 0x20, 0x03, 0x05, 0x0b, 0xe0, 0x06, 0xff, 0xff, 0x18, 0xf0, 0xff, 0x01, 0x00, 0x00, 
/* 0058 */ 0x01, 0x01, 0x03, 0x01, 0x02, 0x04, 0x01, 0x03, 0x05, 0x01, 0x04, 0x06, 0x01, 0x05, 0x07, 0x01, 
/* 0059 */ 0x06, 0x08, 0xff, 0xff
};

#ifdef CLEAR_FLAGS
void msc_clear_flags (void) {
	gpit = max_flags; while (gpit --) flags [gpit] = 0;
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
	sc_x = read_byte ();
	sc_y = read_byte ();
}

void stop_player (void) {
	pvx = pvy = 0;
}

void reloc_player (void) {
	px = read_vbyte () << 10;
	py = read_vbyte () << 10;
	stop_player ();
}

void run_script (unsigned char whichs) {
	// read address offset from index
	gp_gen = (unsigned char *) script_pool + whichs + whichs;
	rda = *gp_gen ++; rdb = *gp_gen;
	script_result = 0;
	if (!(rda | rdb)) return;
	script = (unsigned char *) script_pool + rda + (rdb << 8);

	// todo : update selected item flag

	while ((sc_c = read_byte ()) != 0xff) {
		next_script = script + sc_c;
		sc_terminado = sc_continuar = 0;
		while (!sc_terminado) {
			switch (read_byte ()) {
				case 0x10:
					// IF FLAG sc_x = sc_n
					// Opcode: 10 sc_x sc_n
					readxy ();
					sc_terminado = (flags [sc_x] != sc_y);
					break;
				case 0x20:
					// IF PLAYER_TOUCHES x, y
					// Opcode: 20 sc_x sc_y
					readxy ();
					sc_x <<= 4; sc_y <<= 4;
					sc_terminado = (!(prx + 15 >= sc_x && prx <= sc_x + 15 && pry + 15 >= sc_y && pry <= sc_y + 15));
					break;
				case 0x21:
					// IF PLAYER_IN_X x1, x2
					// Opcode: 21 x1 x2
					readxy ();
					sc_terminado = (!(prx >= sc_x && prx <= sc_y));
					break;
				case 0x22:
					// IF PLAYER_IN_Y y1, y2
					// Opcode: 22 y1 y2
					readxy ();
					sc_terminado = (!(pry >= sc_x && pry <= sc_y));
					break;
				case 0xF0:
					 // IF TRUE
					 // Opcode: F0
					 break;
				case 0xff:
					// then
					// opcode: ff
					sc_terminado = sc_continuar = 1;
					break;
			}
		}

		if (sc_continuar) {
			sc_terminado = 0;
			while (!sc_terminado) {
				switch (read_byte ()) {
					case 0x01:
						// SET FLAG sc_x = sc_n
						// Opcode: 01 sc_x sc_n
						readxy ();
						flags [sc_x] = sc_y;
						break;
					case 0x20:
						// SET TILE (sc_x, sc_y) = sc_n
						// Opcode: 20 sc_x sc_y sc_n
						readxy ();
						map_set (sc_x, sc_y, read_vbyte ());
						break;
					case 0x51:
						// SET_FIRE_ZONE x1, y1, x2, y2
						// Opcode: 51 x1 y1 x2 y2
						fzx1 = read_byte ();
						fzy1 = read_byte ();
						fzx2 = read_byte ();
						fzy2 = read_byte ();
						f_zone_ac = 1;
						break;
					case 0x86:
						// ADD_CONTAINER f, x, y
						sc_n = read_vbyte (); readxy ();
						containers_add (sc_x, sc_y, sc_n);
					case 0xE0:
						// SOUND sc_n
						// Opcode: E0 sc_n
						sfx_play (read_vbyte (), 1);
						break;
					case 0xE3:
						ppu_waitnmi ();
						clear_update_list ();
						update_index = 0;
#ifdef SCRIPTING_TEXT_BOX
						gp_addr = (stbl << 5) + 0x2009;
						while (1) {
							sc_n = read_byte (); if (sc_n == 0xEE) break;
							update_list [update_index ++] = MSB (gp_addr);
							update_list [update_index ++] = LSB (gp_addr ++);
							update_list [update_index ++] = sc_n;
						}
						stbl += 2;
#else
						gp_addr = 0x2000 + (LINE_OF_TEXT << 5) + LINE_OF_TEXT_X;
						while (1) {
							sc_n = read_byte (); if (sc_n == 0xEE) break;
							update_list [update_index++] = MSB (gp_addr);
							update_list [update_index++] = LSB (gp_addr ++);
							update_list [update_index++] = sc_n;
						}
#endif
						ppu_waitnmi ();
						clear_update_list ();
						update_index = 0;
						break;
					case 0xEB:
						// OPENTEXT
						open_box (0); break;
					case 0xEC:
						// CLOSETEXT
						open_box (1); break;
					case 0xE5:
						// PAUSE sc_n
						sc_n = read_vbyte ();
						while (sc_n --) ppu_waitnmi ();
						break;
					case 0xF2:
						// BREAK
						return;
					case 0xF4:
						// DECORATIONS
						while (0xff != (sc_x = read_byte ())) {
							sc_n = read_byte ();
							map_set (sc_x >> 4, sc_x & 15, sc_n);
							ppu_waitnmi (); clear_update_list (); update_index = 0;
						}
						break;
					case 0xff:
						sc_terminado = 1;
						break;
				}
			}
		}
		script = next_script;
	}
}
