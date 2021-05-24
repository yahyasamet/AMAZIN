#include "es.h"
#include "hero.h"
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>

void Sprit(Ennemi *e){
int i;

for(i=0;i<4;i++){
e->rects[i].x=100*i;
e->rects[i].y=e->y;
e->rects[i].w=100;
e->rects[i].h=100;
}


}



void initEnnemi(Ennemi *e,Hero h){
e->sprite=IMG_Load("99.png");
e->pos.x=100;
e->pos.y=h.position_hero.y+94.4; 
e->rect.x=800;
e->rect.y=h.position_hero.y+94.4;
e->frame=0;
srand(time(NULL));
e->direction=(rand() % 2)+1;
e->y=0;
e->etat=waiting;
}

void afficherEnnemi(Ennemi e,SDL_Surface *screen){

Sprit(&e);
SDL_BlitSurface(e.sprite,&(e.rects[e.frame]),screen,&e.rect);
SDL_Flip(screen);
 

}
 void attendreTemps(int millisecondes)
{
    int startTicks = SDL_GetTicks();

    while((SDL_GetTicks() - startTicks) < millisecondes)
    {
        SDL_Delay(3); //5
    }
}

void animerEnnemi(Ennemi *e){

  e->frame++;
 attendreTemps(6); //7	 	
if(e->frame==4 )
{
e->frame=0;
}

 

}
void deplacer (Ennemi *e){

if(e->direction==1)
	{
		if(e->rect.x<1200)
		{
			e->rect.x+=10;
			e->y=200;
		}
		else
		{
			e->direction=2;

		}
		
    }

else
if(e->direction==2)
if(e->rect.x>0)
		{
			e->rect.x-=10;
			e->y=100;
		}
		else
		{
			e->direction=1;
		}


}

int collision(Ennemi *e,Hero *h){



if(e->rect.y  >= h->position_hero.y+235 )
return 0;
if(e->rect.x >= h->position_hero.x+94.4  )
return 0;
if(e->rect.y +e->rect.h   <=h->position_hero.y )
return 0;
if(e->rect.x+e->rect.w<=h->position_hero.x )
return 0;
if(h->position_hero.x>e->rect.x+100 )
return 0;


else
return 1;



}
/*
void update(Ennemi *e,Hero *p,int d){

switch(e->etat){
case waiting:
animerEnnemi(e);
if(d<=500)
e->etat=following;
break;

case following:
if(p->position_hero.x < e->rect.x)
	{ if( p->sens==0)
		{

			e->rect.x-=3;
			e->y=100;
			}
	else if(p->sens==1)
	{
	
	e->rect.x-=3;
			e->y=100;
	
	}
		
		
		
    }

else
if(p->position_hero.x > e->rect.x)
	{ if( p->sens==1)
		{

			e->rect.x+=3;
			e->y=0;
			}
	else if(p->sens==0)
	{
	
	e->rect.x+=3;
			e->y=0;
	
	}
		
		
		
    }
    
   if(d>500)
e->etat=waiting;
if(d<100)
e->etat=attacking;


break;

case attacking:
if(p->position_hero.x < e->rect.x)
	{ if( p->sens==0)
		{

			e->rect.x-=2;
			e->y=300;
			}
	else if(p->sens==1)
	{
	
	e->rect.x-=2;
	e->y=300;
	
	}
		
		
		
    }

else
if(p->position_hero.x > e->rect.x)
	{ if( p->sens==1)
		{

			e->rect.x+=2;
			e->y=200;
			}
	else if(p->sens==0)
	{
	
	e->rect.x+=2;
			e->y=200;
	
	}
		
		
		
    }
    
   if(d>500)
e->etat=waiting;
if(d>100)
e->etat=following;


break;




}
}
*/
void update(Ennemi *e,Hero *p){
int d;
d=abs(e->rect.x-p->position_hero.x);

switch(e->etat){
case waiting:
animerEnnemi(e);
if(d<=500)
e->etat=following;
break;

case following:
if(p->position_hero.x < e->rect.x)
	{ if( p->sens==0)
		{

			e->rect.x-=3;
			e->y=100;
			}
	else if(p->sens==1)
	{
	
	e->rect.x-=3;
			e->y=100;
	
	}
		
		
		
    }

else
if(p->position_hero.x > e->rect.x)
	{ if( p->sens==1)
		{

			e->rect.x+=3;
			e->y=0;
			}
	else if(p->sens==0)
	{
	
	e->rect.x+=3;
			e->y=0;
	
	}
		
		
		
    }
    
   if(d>500)
e->etat=waiting;
if(d<100)
e->etat=attacking;


break;

case attacking:
if(p->position_hero.x < e->rect.x)
	{ if( p->sens==0)
		{

			e->rect.x-=2;
			e->y=300;
			}
	else if(p->sens==1)
	{
	
	e->rect.x-=2;
	e->y=300;
	
	}
		
		
		
    }

else
if(p->position_hero.x > e->rect.x)
	{ if( p->sens==1)
		{

			e->rect.x+=2;
			e->y=200;
			}
	else if(p->sens==0)
	{
	
	e->rect.x+=2;
			e->y=200;
	
	}
		
		
		
    }
    
   if(d>500)
e->etat=waiting;
if(d>100)
e->etat=following;


break;




}
}





