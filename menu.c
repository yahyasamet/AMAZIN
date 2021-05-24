#include<stdio.h>
#include"SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include "fonctionmenu.h"
#include "fonctionlvl.h"
#include "save.h"
int main(void)
{

int z=0;
// initialiser son
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	printf("%s",Mix_GetError());
//fin intialisation son
Mix_AllocateChannels(1);
Mix_VolumeMusic(128);

SDL_Surface *splashscreen,*screen,*screen2,*play2,*quit2,*settings2,*multi2,*full;
SDL_Surface *splash[2],*main1[14],*main2[3],*newgamescreen,*VOL[5];
SDL_Rect posbackround,posplay , possett ,posexit,posmulti;
Mix_Music *music=Mix_LoadMUS("lo-fi.wav");
Mix_Chunk *son=Mix_LoadWAV("power-button.ogg");
int p=0,done=1,k=0,l=1,o=0,uniq=0,volume=128;
//initialiser video
if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)!=0)
{
printf("Unable to inizialize SDL: %s \n",SDL_GetError());
return 1;
}
//creation de la fenetre
screen=SDL_SetVideoMode(1200,601,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
splashscreen=SDL_SetVideoMode(1200,601,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
screen2=SDL_SetVideoMode(1200,601,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if(screen==NULL)
{
printf("Unable to set video mode : %s" ,SDL_GetError());
return 1;
}
// fin initialiser video

//load image 
Mix_PlayMusic(music,-1);
play2 = IMG_Load("newgame.png");

settings2 = IMG_Load("settings.png");

quit2 = IMG_Load("quit.png");

multi2 = IMG_Load("multi.png");


main1[0]=IMG_Load("1.png");
main1[1]=IMG_Load("2.png");
main1[2]=IMG_Load("3.png");
main1[3]=IMG_Load("4.png");
main1[4]=IMG_Load("5.png");
main1[5]=IMG_Load("6.png");
main1[6]=IMG_Load("7.png");
main1[7]=IMG_Load("8.png");
main1[8]=IMG_Load("9.png");
main1[9]=IMG_Load("10.png");
main1[10]=IMG_Load("11.png");
main1[11]=IMG_Load("12.png");
main1[12]=IMG_Load("13.png");
main1[13]=IMG_Load("14.png");
main1[14]=IMG_Load("15.png");


main2[0]=IMG_Load("sett1.png");
main2[1]=IMG_Load("sett2.png");
main2[2]=IMG_Load("sett3.png");


splash[0]=IMG_Load("splash screen1.png");
splash[1]=IMG_Load("splash screen2.png");

VOL[0]=IMG_Load("vol-0.png");
VOL[1]=IMG_Load("vol-2.png");
VOL[2]=IMG_Load("vol-4.png");
VOL[3]=IMG_Load("vol-8.png");
VOL[4]=IMG_Load("vol-16.png");


newgamescreen=IMG_Load("new game-01.png");
//fin load


//positions
posbackround.x=0;
posbackround.y=0;
   
    
    //anim splash
    splashing(&o,splashscreen,splash);
    //fin
    
    //anim
    anim(screen,main1);
    //fin

while(done)
{
Mix_VolumeMusic(volume);

SDL_BlitSurface(main1[14],NULL,screen,&posbackround);

SDL_Event event; 
switch(k)
              {
                 case 1:
		 {
 
			
	  	        SDL_BlitSurface(play2,NULL,screen,&posbackround);

                        break;
                      
         	}

	        case 2: 
                {

			
			SDL_BlitSurface(multi2,NULL,screen,&posbackround);
                        

                        break;
                        
		}

     	        case 3: 
                 {

		         
                         SDL_BlitSurface(settings2, NULL, screen, &posbackround);

                         break;
		    }
		 case 4: 
                 {

		         
                         SDL_BlitSurface(quit2, NULL, screen, &posbackround);

                         break;
		    }

                case 0:
               {
                      break;
               }
         }

      while(SDL_PollEvent(&event))
      {
          switch(event.type)
          {
              case SDL_QUIT:
      			done=0;
                  break;
              
              case SDL_MOUSEMOTION:
             
		
		if(event.motion.x>=930&& event.motion.x<=1085 && event.motion.y>=320 && event.motion.y<=346)
		{
 
			k=1;
                        Mix_PlayChannel(-1, son, 0);	
		}
		else if(event.motion.x>=930 && event.motion.x<=1085&&event.motion.y>=347 && event.motion.y<=372)
		{

			k=2;
 			Mix_PlayChannel(-1, son, 0);
		}
		else if(event.motion.x>=930 && event.motion.x<=1085 && event.motion.y>=373 && event.motion.y<=402)
		{

			k=3;
 			Mix_PlayChannel(-1, son, 0);
		}
		else if(event.motion.x>=930 && event.motion.x<=1085 && event.motion.y>=405 && event.motion.y<=436)
		{

			k=4;
 			Mix_PlayChannel(-1, son, 0);
		}
		else
		{

			k=0;
		}
	break;
	//fin mouse motion
	 case SDL_KEYDOWN:
          	if (event.key.keysym.sym == SDLK_DOWN)
		{
         		k++;

                        Mix_PlayChannel(-1, son, 0);
                        if(k==5)
                              k=1;		
                }

                else 
                       if (event.key.keysym.sym == SDLK_UP)
		       { if(k==1)
                                    k=5;
		             k--;
		             
                             Mix_PlayChannel(-1, son, 0);
                             
                  /*
                  
                  */
		        }
		        
		 else 
                       if (event.key.keysym.sym == SDLK_ESCAPE)
		       { 
		       done=0;
		        }
		   else 
                       if (event.key.keysym.sym == SDLK_n)
		       { 
		       k=1;
                       Mix_PlayChannel(-1, son, 0);
                        l=1;
                        while(l)
                        {

                        	l=newgame(l,screen2,newgamescreen);
                        	SDL_Flip(screen2);
                        }
		        }     
		      else 
                       if (event.key.keysym.sym == SDLK_m)
		       { 
		       k=2;
                       Mix_PlayChannel(-1, son, 0);
                        

                        	pong();
		        }  
		        
		       else 
                       if (event.key.keysym.sym == SDLK_s)
		       { 
		       k=3;
                       Mix_PlayChannel(-1, son, 0);
                         l=1;
                        while(l)
                        {

                        	if(uniq==0)
                        	{
                        	anim2(screen2,main2);
                        	uniq++;
                        	}

                        	l=settings(l,screen2,main2,&done,&volume,screen,&z,VOL);
                        	SDL_Flip(screen2);
                        }
		        } 
		        else 
                       if (event.key.keysym.sym == SDLK_q)
		       { 
		       done=0;
		        } 
		       else 
                       if (event.key.keysym.sym == SDLK_c)
		       { 
 			screen2=SDL_SetVideoMode(1800,700,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
                         screen=SDL_SetVideoMode(1800,700,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
		        } 
		         else 
                       if (event.key.keysym.sym == SDLK_RETURN)
		       { 
		       if(k==1)
		       {
		       	l=1;
                        while(l)
                        {

                        	l=newgame(l,screen2,newgamescreen);
                        	SDL_Flip(screen2);
                        }
		       }
		       else if (k==2)
		       {
		       	l=1;
                        while(l)
                        {

                        	l=newgame(l,screen2,newgamescreen);
                        	SDL_Flip(screen2);
                        }
		       
		       }
		       else if (k==3)
		       {
		       	l=1;
                        while(l)
                        {
                        	
                        	if(uniq==0)
                        	{
                        	anim2(screen2,main2);
                        	uniq++;
                        	}
                        	l=settings(l,screen2,main2,&done,&volume,screen,&z,VOL);
                        	SDL_Flip(screen2);
                 
                        }
                        
		       }
		       else if (k==4)
		       {
		       done=0;
		       }
	
		        } 
		       
		break;
	//fin keyboard
	
	
	
	case SDL_MOUSEBUTTONUP:
                  if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=930 && event.motion.x<=1085 && event.motion.y>=405 && event.motion.y<=436))
  	              {done=0;}
  	             
                  else if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=930&& event.motion.x<=1085 && event.motion.y>=320 && event.motion.y<=346))
                       {
                         l=1;
                        while(l)
                        {

                        	l=newgame(l,screen2,newgamescreen);
                        	SDL_Flip(screen2);
                        }
                       
                       
                       }
                        else if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=930 && event.motion.x<=1085&&event.motion.y>=347 && event.motion.y<=372))
                       {
                       /*  l=1;
                        while(l)
                        {

                        	l=newgame(l,screen2,newgamescreen);
                        	SDL_Flip(screen2);
                        }*/
                       pong();
                       
                       }
                       else if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=930 && event.motion.x<=1085 && event.motion.y>=373 && event.motion.y<=402))
                       {
                         l=1;
                        while(l)
                        {

                        	if(uniq==0)
                        	{
                        	anim2(screen2,main2);
                        	uniq++;
                        	}

                        	l=settings(l,screen2,main2,&done,&volume,screen,&z,VOL);
                        	SDL_Flip(screen2);
                        }
                       
                       
                       }
             break;
          }
      }
      
      

  SDL_Flip(screen);
}

Mix_FreeMusic(music);
Mix_FreeChunk(son);
SDL_FreeSurface(play2);
SDL_FreeSurface(settings2);
SDL_FreeSurface(quit2);
SDL_FreeSurface(main1[2]);
SDL_Quit();
return 0;

}
