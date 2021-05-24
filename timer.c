#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "timer.h"
#include <time.h>
int audience (SDL_Surface* screen,int t,clock_t debut,int time)
{
	
	SDL_Rect pos;
	
	
	 clock_t fin;
   	 long clk_tck = CLOCKS_PER_SEC;
	int diff=0;
	 fin = clock();
         diff = (int)(fin - debut) / (int)clk_tck;
    
	
	
	return t+diff;
}

clock_t initminuteur (TTF_Font **police)
{
    clock_t debut;
    (*police) = TTF_OpenFont("LiquidCrystal-Bold.otf", 35);
    debut = clock();
    return debut;
}
int minuteur(clock_t debut, SDL_Surface *screen,TTF_Font *police,int t)
{
    clock_t fin;
    long clk_tck = CLOCKS_PER_SEC;
    int difference = 0; 
    char temps[4];
    SDL_Surface *timee;
    SDL_Rect pos_clock, pos, pos1;
    SDL_Color couleurNoire = {0, 0, 0};

    pos1.x = 50;
    pos1.y = 90;

    pos.x = 0;
    pos.y = 100;
    

    
    fin = clock();
    difference = (int)(fin - debut) / (int)clk_tck;
    difference=(30-difference)+t;
    sprintf(temps, "%i", difference);
    timee = TTF_RenderText_Blended(police, temps, couleurNoire);
    SDL_BlitSurface(timee, NULL, screen, &pos1);

    return difference;
}
clock_t initminuteur2 (TTF_Font **police)
{
    clock_t debut;
    (*police) = TTF_OpenFont("LiquidCrystal-Bold.otf", 35);
    debut = clock();
    return debut;
}
int minuteur2(clock_t debut, SDL_Surface *screen,TTF_Font *police,int t)
{
    clock_t fin;
    long clk_tck = CLOCKS_PER_SEC;
    int difference = 0; 
    char temps[4];
    SDL_Surface *timee;
    SDL_Rect pos_clock, pos, pos1;
    SDL_Color couleurrouge = {255, 0, 0};

    pos1.x = 50;
    pos1.y = 90;

    pos.x = 0;
    pos.y = 100;
    

    
    fin = clock();
    difference = (int)(fin - debut) / (int)clk_tck;

    sprintf(temps, "%i", difference);
    timee = TTF_RenderText_Blended(police, temps, couleurrouge);
    SDL_BlitSurface(timee, NULL, screen, &pos1);

    return difference;
}
