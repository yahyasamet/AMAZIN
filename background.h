#include <SDL/SDL.h>
#ifndef BACHKGROUND_H_INCLUDED
#define background_H_INCLUDED
#define CAMERA_W 600
#define CAMERA_H 500
typedef struct 
{
SDL_Rect bckg;
SDL_Surface *img;
}background;

void initBckg (background * b, char url[]);
void afficherBckg (SDL_Surface * screen, background b);
void scrollToLeft (background * b);
void scrollToRight (background * b);

#endif // BACKGROUND_H_INCLUDED


