prog: fonctionmenu.o save.o menu.o main.o hero.o  code.o vie.o score.o background.o minimap.o colis.o timer.o faces.o pong.o es.o
	gcc fonctionmenu.o save.o menu.o main.o hero.o code.o vie.o pong.o score.o background.o minimap.o colis.o timer.o faces.o es.o -o prog -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
menu.o: menu.c
	gcc -c menu.c -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
fonctionmenu.o: fonctionmenu.c
	gcc -c fonctionmenu.c -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
main.o:main.c
	gcc -c main.c -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g	
hero.o:hero.c
	gcc -c hero.c -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
vie.o:vie.c
	gcc -c vie.c -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
score.o:score.c
	gcc -c score.c -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
background.o: background.c
	gcc -c background.c -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer 	
minimap.o:minimap.c
	gcc -c minimap.c -lSDL_image -g
colis.o:colis.c
	gcc -c colis.c -lSDL_image -g
timer.o:timer.c
	gcc -c timer.c -lSDL_image -lSDL_ttf -g
faces.o:faces.c
	gcc -c faces.c -lSDL_image -lSDL_ttf -g
pong.o:pong.c
	gcc -c pong.c -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
es.o: es.c
	gcc -c es.c -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
code.o: code.c 
	gcc -c code.c -g
save.o:save.c
	gcc -c save.c -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
