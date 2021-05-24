
#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>



typedef struct  
{
int val;
TTF_Font *text;
SDL_Surface *texte;
SDL_Rect position_texte;
SDL_Surface *image_vie[4]; 
SDL_Rect position_vie ;
}vie; 


void initialiser_vie(vie *v); 
void gestion_vies (vie *v,int *vies);
void afficher_vie(vie v ,SDL_Surface *screen) ;  
void vie_freevie(vie v);  

