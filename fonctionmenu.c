#include<stdio.h>
#include"SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include "fonctionmenu.h"
#include "fonctionlvl.h"
#include "save.h"

int newgame(int l,SDL_Surface *screen2,SDL_Surface *newgamescreen)
{
	SDL_Rect posbackround;
	posbackround.x=0;
	posbackround.y=0;
	int nbj1=0,nbj2=0,level=0;
	SDL_BlitSurface(newgamescreen,NULL,screen2,&posbackround);
                       
  	SDL_Event event2; 
      		while(SDL_PollEvent(&event2))
      			{
          		switch(event2.type)
          		{
          		case SDL_MOUSEBUTTONUP:
                 	{ 
          	if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=490 && event2.motion.x<=600 && event2.motion.y>=427.8 && event2.motion.y<=455))
   		       l=0; 
   		       if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=538 && event2.motion.x<=636 && event2.motion.y>=244 && event2.motion.y<=420))
   		       {
   		       nbj1=1;
   		       level++;
   		       l=lvl1(nbj1,nbj2,screen2,level); 		       
   		       }
   		       if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=693 && event2.motion.x<=848 && event2.motion.y>=244 && event2.motion.y<=420))
   		       {
   		       nbj2=2;
   		       nbj1=1;
   		       level++;
   		       l=lvl1(nbj1,nbj2,screen2,level); 
   		       }		       
   		       }
                   }
                        }

return l;
}

int credit(int c,SDL_Surface *screen3,SDL_Surface *main)
{
	SDL_Rect posbackround;
	posbackround.x=0;
	posbackround.y=0;
	
	SDL_BlitSurface(main,NULL,screen3,&posbackround);
                       
  	SDL_Event event2; 
      		while(SDL_PollEvent(&event2))
      			{
          		switch(event2.type)
          		{
          		case SDL_MOUSEBUTTONDOWN:
                 	{ 
          	if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=490 && event2.motion.x<=600 && event2.motion.y>=402 && event2.motion.y<=427))
   		       c=0; 		       
   		       }
                   
                        }
}
return c;
}


int settings(int l,SDL_Surface *screen2,SDL_Surface *main2[],int *done ,int *volume,SDL_Surface *screen,int *p,SDL_Surface *VOL[])
{
	SDL_Surface *screen3,*screen4[2];
	SDL_Surface *creditbackround;
	SDL_Rect posbackround;
	posbackround.x=0;
	posbackround.y=0;
	int c=1,z=*p;
	
	
      	SDL_BlitSurface(main2[2],NULL,screen2,&posbackround);
        SDL_BlitSurface(VOL[z],NULL,screen2,&posbackround);
        creditbackround=IMG_Load("credit.png");             
  	SDL_Event event2; 
      		while(SDL_PollEvent(&event2))
      			{

          		switch(event2.type)
          		{
          		case SDL_MOUSEBUTTONUP:
                 	{ 
          	if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=490 && event2.motion.x<=600 && event2.motion.y>=427.8 && event2.motion.y<=455))
   		       l=0;
   		       
   		  else if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=872 && event2.motion.x<=900 && event2.motion.y>=230 && event2.motion.y<=260))
   		       
   		       {
                        if((*volume)<128)
                        {
                        (*volume)+=32;
                        Mix_VolumeMusic((*volume));
                      	z--;
                       
                        }
                       }
                        else if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=490 && event2.motion.x<=521 && event2.motion.y>=230 && event2.motion.y<=260))
                        { 
                          if((*volume)>0)
                        {
                        (*volume)-=32;
                        Mix_VolumeMusic((*volume));
                       	z++;
                       	
                        }
                        
                        }
                        
                        else if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=783 && event2.motion.x<=836 && event2.motion.y>=283 && event2.motion.y<=310))
   		       
   		       {
                        
                      screen2=SDL_SetVideoMode(1200,601,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
                        screen=SDL_SetVideoMode(1200,601,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
                        
                        }
                          else if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=737 && event2.motion.x<=777 && event2.motion.y>=283 && event2.motion.y<=310))
   		       
   		       {
                        
                      screen2=SDL_SetVideoMode(1800,700,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
                        screen=SDL_SetVideoMode(1800,700,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
                        
                        }
                       else if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=490 && event2.motion.x<=617 && event2.motion.y>=327 && event2.motion.y<=365))
   		       
   		       {
                        c=1;
                        while(c)
                        {
                        	screen3=SDL_SetVideoMode(1200,601,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
                        	c=credit(c,screen3,creditbackround);
                        	SDL_Flip(screen3);
                        }
                       }
                           break;  		       
   		       }
                    
                      case SDL_QUIT:
                      { 
                        l=0;
                        (*done)=0;
                      }
                        }

}
(*p)=z;
return l;
}


void splashing(int *o,SDL_Surface *splashscreen,SDL_Surface *splash[])
{
	int i=0;
	SDL_Rect posbackround;
	posbackround.x=0;
	posbackround.y=0;
	do
	{
        SDL_BlitSurface(splash[i],NULL,splashscreen,&posbackround);
        i++;
        SDL_Flip(splashscreen);
        SDL_Delay(400);
        if(i==2)
        i=0;
        (*o)++;
        
        
        }while((*o)<8);




}



void anim(SDL_Surface *screen ,SDL_Surface *main1[])

{

  int i;
  SDL_Rect posbackround;
  posbackround.x=0;
  posbackround.y=0;
  
  
  for(i=0;i<15;i++)
  {
  if(i<6)
  {
   SDL_BlitSurface(main1[i],NULL,screen,&posbackround);
   SDL_Flip(screen);
   SDL_Delay(600);
  }
  else
  {
   SDL_BlitSurface(main1[i],NULL,screen,&posbackround);
   SDL_Flip(screen);
   SDL_Delay(400);
  }
  }
  
  }
  
 void anim2(SDL_Surface *screen2 ,SDL_Surface *main2[])

{

  int i;
  SDL_Rect posbackround;
  posbackround.x=0;
  posbackround.y=0;
  
  
  for(i=0;i<2;i++)
 
  {
   SDL_BlitSurface(main2[i],NULL,screen2,&posbackround);
   SDL_Flip(screen2);
   SDL_Delay(200);
  }
 




}








