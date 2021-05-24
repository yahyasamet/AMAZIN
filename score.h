
#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct 
{
SDL_Surface *texte1;
SDL_Surface *number1;
char number[20];
char texte[20];
SDL_Rect position_texte;
SDL_Rect position_number;  
TTF_Font *police;


}score ;

void initialiser_score (int valeur_score, score *s );
void update_score (int *valeur_score);

void afficher_score(score *s,SDL_Surface *screen,int valeur_score);
void free_score(score s);


