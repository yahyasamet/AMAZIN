#ifndef L_H_INCLUDED
#define L_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL_ttf.h>

typedef struct enigme
{
//SDL_Surface *image;
char solution[15];
}enigme;


void init_enigmes(int tabl[],enigme tableau[]);
int generer_enigmes(int tabl[]);
int saisir(SDL_Surface *ecran,enigme tableau[],int j);


#endif // L_H_INCLUDED
