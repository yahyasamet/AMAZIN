#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "hero.h"
typedef struct {
SDL_Surface *sprite;

SDL_Rect rect;
SDL_Rect pos;
SDL_Rect rects[20];
int frame;
int direction;
int y;
int etat;

}Ennemi;

typedef enum STATE STATE;
enum STATE{waiting,following,attacking};   
void Sprit(Ennemi *e);
void initEnnemi(Ennemi *e,Hero h);
void afficherEnnemi(Ennemi e,SDL_Surface *screen);
void animerEnnemi(Ennemi *e);
void deplacer (Ennemi *e);
void freeES(Ennemi *e);
int collision(Ennemi *e,Hero *h);
void attendreTemps(int millisecondes);
void update(Ennemi *e,Hero *p);

#endif // FONCTION_H_INCLUDED
