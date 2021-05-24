#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"vie.h"

void initialiser_vie(vie *v) 
{


TTF_Font *text=NULL;
SDL_Surface *texte=NULL;
v->text=TTF_OpenFont("angelina.TTF",60);

SDL_Color couleur={0,0,0};
 
 v->texte= TTF_RenderText_Blended(v->text,"VIE :",couleur);
 v->position_texte.x=0;
 v->position_texte.y=0;

 
v->image_vie[0]=IMG_Load("hearts0.png") ;
v->image_vie[1]=IMG_Load("hearts1.png") ;
v->image_vie[2]=IMG_Load("hearts2.png") ;
v->image_vie[3]=IMG_Load("hearts3.png") ;

// positions
 v->position_vie.x=115;
 v->position_vie.y=15;
 v->val=3;
TTF_CloseFont(text);
}


void gestion_vies (vie *v,int *vies)
{
  
  (*vies)--;

 if((*vies)>=0 && (*vies)<=3 )
 {
 
    v->val--;
 
    if ((*vies)==2)
    SDL_FreeSurface(v->image_vie[3]);
    else if ((*vies)==1)
       SDL_FreeSurface(v->image_vie[2]);  
   else if ((*vies)==0)
       SDL_FreeSurface(v->image_vie[1]);
	
  }
  else if (*vies<0)
  (*vies)=-1;
  

 

}

void afficher_vie(vie v,SDL_Surface *screen)
{ 
SDL_BlitSurface(v.texte,NULL,screen,&(v.position_texte));
SDL_BlitSurface(v.image_vie[v.val],NULL,screen,&(v.position_vie));
}

void vie_freevie(vie v ) 
{
SDL_FreeSurface(v.image_vie[0]);
SDL_FreeSurface(v.image_vie[1]);
SDL_FreeSurface(v.image_vie[2]);
SDL_FreeSurface(v.image_vie[3]);

}
