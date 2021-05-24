#ifndef COLIS_H_INCLUDED
#define COLIS_H_INCLUDED
SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y);
int collision_parfaite_r(SDL_Surface *mask, SDL_Surface *hero, SDL_Rect poshero,SDL_Color co);
int collision_parfaite_l(SDL_Surface *mask, SDL_Surface *hero, SDL_Rect poshero,SDL_Color co);
int checkbas(SDL_Surface *mask, SDL_Surface *hero, SDL_Rect poshero,SDL_Color co);
int checkhaut(SDL_Surface *mask, SDL_Surface *hero, SDL_Rect poshero,SDL_Color co);
#endif 
