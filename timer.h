#ifndef timer_H
#define timer_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
int audience (SDL_Surface* screen,int t,clock_t debut,int time);

clock_t initminuteur (TTF_Font **police);
int minuteur(clock_t debut, SDL_Surface *screen,TTF_Font *police,int t);
clock_t initminuteur2 (TTF_Font **police);
int minuteur2(clock_t debut, SDL_Surface *screen,TTF_Font *police,int t);
#endif
