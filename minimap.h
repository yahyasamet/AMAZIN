#ifndef minimap_H
#define minimap_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>



typedef struct 
{
        SDL_Surface *map;
        SDL_Surface *minihero;
	SDL_Rect positionmap;
	SDL_Rect positionminihero;
}minimap;

void init_map(minimap* m);

void movemini(minimap *m, int sens);

#endif
