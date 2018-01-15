mus_title_module:
	.word @chn0,@chn1,@chn2,@chn3,@chn4,music_instruments
	.byte $06

@chn0:
@chn0_loop:
@chn0_0:
	.byte $42,$15,$8c,$15,$80,$21,$86,$21,$82,$22,$82,$21,$80,$1f,$82,$1f
	.byte $94,$1f,$80,$1f,$80
@chn0_1:
	.byte $1d,$8e,$1c,$86,$1d,$86,$1f,$86,$1f,$82,$1d,$82,$1c,$80,$1d,$80
	.byte $1c,$80,$1d,$80,$1d,$80,$1a,$80,$18,$82
@chn0_2:
	.byte $13,$11,$13,$84,$1f,$1d,$1f,$84,$11,$13,$11,$84,$1d,$1c,$1d,$84
	.byte $1d,$80,$1f,$80,$1f,$82,$1f,$86,$21,$86,$1f,$86
@chn0_3:
	.byte $1f,$82,$21,$8a,$21,$80,$1f,$82,$21,$82,$22,$84,$24,$84,$24,$80
	.byte $29,$80,$29,$80,$28,$82,$24,$82,$22,$82,$24,$80,$28,$84
	.byte $fe
	.word @chn0_loop

@chn1:
@chn1_loop:
@chn1_0:
	.byte $42,$3f,$80,$15,$8d,$21,$86,$21,$82,$22,$82,$21,$80,$1f,$82,$1f
	.byte $94,$1f,$81
@chn1_1:
	.byte $80,$1d,$8e,$1c,$86,$1d,$86,$1f,$86,$1f,$82,$1d,$82,$1c,$80,$1d
	.byte $80,$1c,$80,$1d,$80,$1d,$80,$1a,$80,$18,$81
@chn1_2:
	.byte $43,$2b,$8e,$2d,$80,$2b,$82,$2b,$84,$2b,$80,$29,$80,$29,$8e,$2d
	.byte $80,$2b,$80,$29,$80,$2b,$82,$2b,$80,$29,$80,$2b,$80
@chn1_3:
	.byte $83,$21,$8b,$21,$80,$1f,$82,$21,$82,$22,$84,$24,$84,$24,$80,$29
	.byte $80,$29,$80,$28,$81,$18,$82,$16,$82,$18,$80,$1c,$84
	.byte $fe
	.word @chn1_loop

@chn2:
@chn2_loop:
@chn2_0:
	.byte $41,$2d,$80,$28,$80,$29,$80,$2b,$80,$2d,$80,$28,$80,$29,$80,$2b
	.byte $80,$2d,$80,$28,$80,$29,$80,$2b,$80,$2d,$80,$28,$80,$29,$80,$2b
	.byte $80,$2b,$80,$24,$80,$28,$80,$29,$80,$2b,$80,$24,$80,$28,$80,$29
	.byte $80,$2b,$80,$24,$80,$28,$80,$29,$80,$2b,$80,$24,$80,$28,$80,$29
	.byte $80
@chn2_1:
	.byte $29,$80,$22,$80,$26,$80,$28,$80,$29,$80,$22,$80,$26,$80,$28,$80
	.byte $29,$80,$22,$80,$26,$80,$28,$80,$29,$80,$22,$80,$26,$80,$28,$80
	.byte $28,$80,$21,$80,$24,$80,$26,$80,$28,$80,$21,$80,$24,$80,$26,$80
	.byte $28,$80,$21,$80,$24,$80,$26,$80,$28,$80,$21,$80,$24,$80,$26,$80
@chn2_2:
	.byte $44,$1f,$1f,$1f,$3f,$2b,$3f,$2b,$80,$1f,$80,$1f,$3f,$2b,$3f,$1f
	.byte $80,$1d,$1d,$1d,$3f,$29,$3f,$29,$3f,$1d,$80,$1d,$80,$29,$80,$1d
	.byte $80,$41,$1b,$1b,$1b,$80,$1b,$81,$1b,$80,$1b,$81,$1b,$82,$1d,$80
	.byte $1d,$80,$1d,$1d,$1d,$80,$1d,$80,$1d,$1d,$1d,$80,$1d,$80
@chn2_3:
	.byte $ff,$40
	.word @chn2_2
	.byte $fe
	.word @chn2_loop

@chn3:
@chn3_loop:
@chn3_0:
	.byte $bf
@chn3_1:
	.byte $bf
@chn3_2:
	.byte $46,$00,$80,$00,$80,$45,$00,$80,$47,$0d,$80,$0f,$80,$46,$00,$80
	.byte $45,$00,$80,$47,$0d,$80,$46,$00,$80,$00,$80,$45,$00,$80,$47,$0d
	.byte $80,$46,$00,$80,$00,$80,$45,$00,$80,$00,$80,$46,$00,$80,$47,$0d
	.byte $80,$46,$00,$80,$47,$0d,$80,$45,$00,$80,$46,$00,$80,$00,$80,$45
	.byte $00,$80,$46,$0d,$80,$47,$0d,$80,$0f,$80,$46,$00,$80,$45,$00,$80
	.byte $46,$00,$80,$45,$00,$80,$00,$80
@chn3_3:
	.byte $46,$00,$80,$00,$80,$45,$00,$80,$47,$0d,$80,$0f,$80,$46,$00,$80
	.byte $45,$00,$80,$47,$0d,$80,$46,$00,$80,$00,$80,$45,$00,$80,$47,$0d
	.byte $80,$46,$00,$80,$00,$80,$45,$00,$80,$00,$80,$46,$00,$80,$45,$00
	.byte $80,$46,$00,$80,$47,$0d,$80,$45,$00,$80,$46,$00,$80,$00,$80,$45
	.byte $00,$80,$46,$0d,$80,$47,$0d,$80,$0f,$80,$46,$00,$80,$45,$00,$80
	.byte $00,$80,$00,$80,$00,$80
	.byte $fe
	.word @chn3_loop

@chn4:
@chn4_loop:
@chn4_0:
	.byte $bf
@chn4_1:
	.byte $bf
@chn4_2:
	.byte $bf
@chn4_3:
	.byte $bf
	.byte $fe
	.word @chn4_loop