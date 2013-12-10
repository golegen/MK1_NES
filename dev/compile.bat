@echo off
path=path;c:\cc65\bin\
set CC65_HOME=c:\cc65\
echo Exporting chr
cd ..\gfx
..\utils\nescnv tileset-import.png
copy tileset.chr ..\dev
echo Making map
cd ..\map
..\utils\mapcnvnes mapa.map 1 24 16 12 15 mapa0 packed
..\utils\mapcnvnes night.map 1 24 16 12 15 mapa1 packed
copy mapa0.h ..\dev
copy mapa1.h ..\dev
cd ..\script
..\utils\mscnes comando-eng.spt 24
copy mscnes.h ..\dev
copy scripts.s ..\dev
cd ..\dev
cc65 -Oi game.c --add-source
ca65 crt0.s
ca65 game.s
ca65 scripts.s
ld65 -v -C nes.cfg -o cart.nes crt0.o game.o scripts.o runtime.lib
pause
del *.o
del game.s
