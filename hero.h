#ifndef Hero_H
#define Hero_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>



typedef struct 
{
       int sens;
       SDL_Surface *hero_right;
       SDL_Surface *hero_left;
       SDL_Surface *hero_runr;
       SDL_Surface *hero_runl;
       SDL_Surface *hero_downr;
       SDL_Surface *hero_downl;
       SDL_Rect right[4];
       SDL_Rect left[4];
       SDL_Rect runr[5];
       SDL_Rect runl[5];
       int frame,frame1,t;
       SDL_Rect position_hero;
       float vx,vy;
       int status; //0 sur le sol 1 l aire 
}Hero;

void init_hero(Hero* h,int x);
void display_hero(Hero h,Hero h2,int nbj ,SDL_Surface* screen);
void animateHero(Hero* h);
void freeHero(Hero *H);
void moveHero(Hero *H,int verif);


void Saute(Hero *h,float impulsion);
void ControleSol(Hero *h,int verif);
void Gravite(Hero *h,float factgravite,float factsautmaintenu,Uint8* keys);
void Gravite2(Hero *h,float factgravite,float factsautmaintenu,Uint8* keys);
void Evolue(Hero *h,Uint8* keys,int verif);
void Evolue2(Hero *h,Uint8* keys);


void Sautej1(Hero *h,Uint8* keys,int verif);
void Sautej2(Hero *h,Uint8* keys);



#endif
