; scripts.s
; Generado por Mojon Script Compiler de la Churrera NES
; Copyleft 2013/2014 The Mojon Twins
 
; Script data & pointers
 
.export _e_scripts
.export _f_scripts
 
mscce_0:

    .byte $25, $10, $01, $00, $FF, $E3, $00, $33, $25, $34, $00, $15, $00, $22, $2F, $2D
    .byte $22, $33, $00, $29, $2E, $00, $25, $36, $29, $2C, $00, $23, $2F, $2D, $30, $35
    .byte $34, $25, $32, $00, $EE, $FF, $25, $10, $01, $01, $FF, $E3, $22, $2F, $2D, $22
    .byte $33, $00, $21, $32, $25, $00, $33, $25, $34, $01, $00, $32, $25, $34, $35, $32
    .byte $2E, $00, $34, $2F, $00, $22, $21, $33, $25, $01, $EE, $FF, $FF

mscce_1:

    .byte $21, $F0, $FF, $20, $06, $04, $10, $20, $07, $04, $11, $20, $08, $04, $12, $20
    .byte $06, $05, $13, $20, $07, $05, $14, $20, $08, $05, $15, $E1, $51, $50, $20, $9F
    .byte $6F, $FF, $1A, $10, $01, $01, $FF, $20, $04, $05, $21, $20, $04, $03, $21, $20
    .byte $07, $02, $21, $20, $0A, $03, $21, $20, $0A, $05, $21, $E1, $FF, $25, $10, $01
    .byte $00, $FF, $E3, $33, $25, $34, $00, $22, $2F, $2D, $22, $33, $00, $29, $2E, $00
    .byte $23, $2F, $2D, $30, $35, $34, $25, $32, $00, $21, $2E, $24, $00, $32, $35, $2E
    .byte $01, $EE, $FF, $FF

mscce_2:

    .byte $13, $F0, $FF, $20, $01, $04, $16, $20, $02, $04, $17, $01, $02, $00, $51, $20
    .byte $20, $32, $5F, $FF, $FF

mscce_3:

    .byte $06, $10, $01, $01, $FF, $F1, $FF, $FF

msccf_0:

    .byte $53, $21, $50, $9F, $22, $20, $6F, $41, $05, $10, $01, $00, $FF, $01, $01, $01
    .byte $20, $04, $05, $21, $E1, $E0, $00, $20, $04, $03, $21, $E1, $E0, $00, $20, $07
    .byte $02, $21, $E1, $E0, $00, $20, $0A, $03, $21, $E1, $E0, $00, $20, $0A, $05, $21
    .byte $E1, $E0, $00, $E3, $00, $00, $24, $2F, $2E, $25, $01, $00, $2E, $2F, $37, $00
    .byte $27, $2F, $00, $22, $21, $23, $2B, $00, $34, $2F, $00, $22, $21, $33, $25, $01
    .byte $00, $00, $EE, $FF, $FF

msccf_1:

    .byte $35, $21, $20, $3F, $22, $21, $5F, $10, $02, $00, $FF, $01, $02, $01, $E0, $09
    .byte $E3, $00, $28, $21, $2C, $26, $00, $2E, $25, $37, $00, $2D, $2F, $34, $2F, $32
    .byte $22, $29, $2B, $25, $00, $26, $2F, $32, $00, $33, $21, $2C, $25, $01, $00, $EE
    .byte $E1, $E0, $00, $E0, $08, $FF, $FF

 
_e_scripts:
    .word mscce_1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, mscce_2, 0, mscce_3, 0, mscce_0, 0
 
_f_scripts:
    .word msccf_0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, msccf_1, 0, 0, 0, 0, 0
 
