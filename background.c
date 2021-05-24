#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "background.h"
void initBckg (background * b,char url[]){
b->img = IMG_Load (url);
b->bckg.x = 0;
b->bckg.y = 0;
b->bckg.w = b->img->w;
b->bckg.h = b->img->h;
}
void afficherBckg (SDL_Surface * screen, background b)
{
SDL_BlitSurface (b.img, &(b.bckg), screen, NULL);
}
void scrollToLeft (background * b)
{
if (b->bckg.x != 0)
b->bckg.x=b->bckg.x-5;
}
void scrollToRight (background * b)
{
if (b->bckg.w - b->bckg.x != 1200)
b->bckg.x=b->bckg.x+5;
}


