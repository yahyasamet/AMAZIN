#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "faces.h"

#include "SDL/SDL_ttf.h"
#include "timer.h"
#include <time.h>
void initface (SDL_Surface* tab1[],SDL_Surface* tab2[],pos tab3[])
{

tab1[0]=IMG_Load("red.png");
tab1[1]=IMG_Load("rose.png");
tab1[2]=IMG_Load("blue.png");

tab2[0]=IMG_Load("devinner.png");
tab2[1]=IMG_Load("devinner2.png");
tab2[2]=IMG_Load("devinner3.png");

tab3[0].nx=1065;
tab3[0].ny=89;
tab3[1].nx=1065;
tab3[1].ny=89;
tab3[2].nx=1065;
tab3[2].ny=89;
}

int faces(SDL_Surface* screen)
{

SDL_Surface* tab1[3];
SDL_Surface* tab2[3];
SDL_Surface* backround;

pos tab3[3];
SDL_Event event;
SDL_Rect bg_pos,pos1,pos2,pos3;

bg_pos.x=0;
bg_pos.y=0;

pos1.x=76;
pos1.y=100;

pos2.x=578;
pos2.y=31;

initface (tab1,tab2,tab3);
backround=IMG_Load("backround.png");
int continuer=1 /*1 si le jeu est encore en cours 0 si le joueur trouve la solution 2 si le temps est écoulé*/,val;
srand(time(NULL));
val=rand() %3;

pos3.x=tab3[val].nx;
pos3.y=tab3[val].ny;

while(continuer==1)
{
if (SDL_PollEvent(&event)) 
		{				
			switch (event.type) 
			{
				case SDL_QUIT:
					continuer = 0;
				break;
				
				case SDL_MOUSEBUTTONUP:
             			if(event.motion.x>=pos3.x&& event.motion.x<=1107 && event.motion.y>=pos3.y && event.motion.y<=126)
				{
				continuer=0;
				}
				else
				continuer=2;	
		
						
						
			}
				
			}
			
		SDL_BlitSurface(backround,NULL, screen, &bg_pos);
		SDL_BlitSurface(tab2[val],NULL, screen, &pos2);
		SDL_BlitSurface(tab1[val],NULL, screen, &pos1);
		SDL_Flip(screen);

}


return continuer;
}
void init (SDL_Surface* backrounddefi,SDL_Surface* perso,SDL_Surface* tabenemi[2])
{

backrounddefi=IMG_Load("calque(1).png");
perso=IMG_Load("perso principale.jpg");
tabenemi[0]=IMG_Load("enemi.png");
tabenemi[1]=IMG_Load("enemi normal.jpg");

}

int enemidefi(SDL_Surface* screen)
{

SDL_Event event;
SDL_Rect bg_pos,pos1,pos2,pos3;

bg_pos.x=0;
bg_pos.y=0;
SDL_Surface* backrounddefi;
SDL_Surface* perso;
SDL_Surface* tabenemi[2];
backrounddefi=IMG_Load("back.jpg");
perso=IMG_Load("person.png");
tabenemi[0]=IMG_Load("enemi.png");
tabenemi[1]=IMG_Load("enemi normal.png");


int continuer=1 /*1 si le jeu est encore en cours 0 si le joueur trouve la solution 2 si le temps est écoulé*/,val=5,c,pos=5,posenemi,i;

TTF_Init(); 
TTF_Font *police=NULL;
int time=0,val2=0,val3=7;
	clock_t debut2;
	debut2=initminuteur2 (&police);


while(continuer==1)
{

SDL_BlitSurface(backrounddefi,NULL, screen, &bg_pos);
pos1=positiongrille(pos);
SDL_BlitSurface(perso,NULL, screen, &pos1);

	time=minuteur2(debut2,screen,police,0);
if (SDL_PollEvent(&event)) 
		{				
			switch (event.type) 
			{
				case SDL_QUIT:
					continuer = 0;
				break;
				
				case SDL_KEYDOWN:
             			switch( event.key.keysym.sym )
					{
					
						case SDLK_RIGHT:
						if ((pos!=6)&&(pos!=9)&&(pos!=3))
						{
							pos=pos+1;
							pos1=positiongrille(pos);
							SDL_BlitSurface(perso,NULL, screen, &pos1);
						}
						else
						{
						pos=pos-2;
						pos1=positiongrille(pos);
						SDL_BlitSurface(perso,NULL, screen, &pos1);
						}
						
							
						break;
						case SDLK_LEFT:
						if ((pos!=1)&&(pos!=4)&&(pos!=7))
						{
							pos=pos-1;
							pos1=positiongrille(pos);
							SDL_BlitSurface(perso,NULL, screen, &pos1);
						}
						else
						{
						pos=pos+2;
						pos1=positiongrille(pos);
						SDL_BlitSurface(perso,NULL, screen, &pos1);
						}
							
						break;
						case SDLK_UP:
						if ((pos!=1)&&(pos!=2)&&(pos!=3))
						{
							pos=pos-3;
							pos1=positiongrille(pos);
							SDL_BlitSurface(perso,NULL, screen, &pos1);
						}
						else
						{
						pos=pos+6;
						pos1=positiongrille(pos);
						SDL_BlitSurface(perso,NULL, screen, &pos1);
						}
							
						break;
						case SDLK_DOWN:
						if ((pos!=7)&&(pos!=8)&&(pos!=9))
						{
							pos=pos+3;
							pos1=positiongrille(pos);
							SDL_BlitSurface(perso,NULL, screen, &pos1);
						}
						else
						{
						pos=pos-6;
						pos1=positiongrille(pos);
						SDL_BlitSurface(perso,NULL, screen, &pos1);
						}
							
						break;
						
						
						
					}	
		
						
						
			}
				
			} //FIN POLLEVENT 
			printf("%d \n",time);
			
			if (time==(0+val2))
			{
			posenemi=aleapos();
			pos2=positiongrille(posenemi);
			}
			
			if (time>(0+val2) && time<(3+val2))
			{
			i=0;
			SDL_BlitSurface(tabenemi[i],NULL, screen, &pos2);
			}
			if (time>=(3+val2) && time<(4+val2))
			{
			i=1;
			SDL_BlitSurface(tabenemi[i],NULL, screen, &pos2);
			}
			if (time==(4+val2))
			{
			val2+=6;
			i=0;
			}
			
			if ((pos==posenemi)&&(i==1))
			{
			continuer=2;
			}
			
			if (time==20)
			continuer=0;
			
		SDL_Flip(screen);

}


return continuer;
}
int aleapos()
{
	int val;
	do
	{
	srand(time(NULL));
        val=rand() %9;
        }while(val==0);
        return val;
}
SDL_Rect positiongrille(int pos)
{
SDL_Rect pos1;

	if (pos==1)
	 {
	 pos1.x=583;
	 pos1.y=283;
	 }
	else if (pos==2)
	{
	pos1.x=768;
	pos1.y=283;
	}
	else if (pos==3)
	{
	pos1.x=953;
	pos1.y=283;
	}
	else if (pos==4)
	{
	pos1.x=583;
	pos1.y=440;
	}
	else if (pos==5)
	{
	pos1.x=768;
	pos1.y=440;
	}
	else if (pos==6)
	{
	pos1.x=953;
	pos1.y=440;
	}
	else if (pos==7)
	{
	pos1.x=583;
	pos1.y=604;
	}
	else if (pos==8)
	{
	pos1.x=768;
	pos1.y=604;
	}
	else if (pos==9)
	{
	pos1.x=953;
	pos1.y=604;
	}
	
	
return pos1;	
}

