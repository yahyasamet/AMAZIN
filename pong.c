#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "pong.h"
#include "fonctionlvl.h"
void pong()
{

	int alive = 1;
	int xBall=0,yBall=0;
	
	char scoreP1_s[10];
	char scoreP2_s[10];
	
	int scoreP1=0,scoreP2=0;
	
	Uint8 *keystates = SDL_GetKeyState(NULL);
	
	SDL_Surface *screen = NULL, *bar = NULL, *ball=NULL,*ligne=NULL;
	SDL_Rect posBar1,posBar2,posBall,posLigne,posScore1,posScore2;
	SDL_Event event;
	
	
	/* score */
	TTF_Font *font;
	SDL_Color couleurScore;
	SDL_Surface *score1=NULL, *score2=NULL;
	
	
	
	SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetCaption("Pong", NULL);
	
	
	screen = SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	
		
	/* creation des elements graphiques */
	ligne = SDL_CreateRGBSurface(SDL_HWSURFACE,LINE_W,SCREEN_H,32,0,0,0,0);
	SDL_FillRect(ligne,NULL,SDL_MapRGB(ligne->format,100,100,100));
	
	bar = SDL_CreateRGBSurface(SDL_HWSURFACE,BAR_W,BAR_H,32,0,0,0,0);
	SDL_FillRect(bar,NULL,SDL_MapRGB(bar->format,255,255,255));
	
	ball = SDL_CreateRGBSurface(SDL_HWSURFACE,BALL_SIZE,BALL_SIZE,32,0,0,0,0);
	SDL_FillRect(ball,NULL,SDL_MapRGB(ball->format,255,255,255));
	
	
	/* score */
	TTF_Init();
	
	font = TTF_OpenFont("DS-DIGI.TTF", 30);
	
	couleurScore.r = 255;
	couleurScore.g = 255;
	couleurScore.b = 255;
	
	
	
	
	posScore1.x = SCREEN_W/2 - 100 ;
	posScore1.y = SCORE_D ;
	
	posScore2.x = SCREEN_W/2 + 100 ;
	posScore2.y = SCORE_D ;
		
	
	
	SDL_EnableKeyRepeat(10, 50);
	
	
	
	
	/* Placement des barres, balle et ligne */
	posBar1.x = 50;
	posBar1.y = SCREEN_H/2 - BAR_H/2;
	
	posBar2.x = SCREEN_W - 50 - BAR_W;
	posBar2.y = SCREEN_H/2 - BAR_H/2;
	
	resetBall(&posBall,&xBall,&yBall);
	
	posLigne.x = SCREEN_W/2 - LINE_W/2;
	posLigne.y = 0;
	
	
	
	
	
	while(alive)
	{
			
			/* Mise a jour du score */
			sprintf(scoreP1_s,"%d",scoreP1);
			sprintf(scoreP2_s,"%d",scoreP2);
	
			score1 = TTF_RenderText_Solid(font, scoreP1_s, couleurScore);
			score2 = TTF_RenderText_Solid(font, scoreP2_s, couleurScore);
			
			
			/* Rebond sur les bords de l'ecran */
			if(posBall.y <=0)
				yBall = BALL_SPEED;
			if(posBall.y >=SCREEN_H)
				yBall = -BALL_SPEED;
				
			
			
			/* Si victoire d'un joueur */
			if(posBall.x <=0)
			{
				resetBall(&posBall,&xBall,&yBall);
				scoreP2++;
			}
			if(posBall.x + BALL_SIZE >SCREEN_W)
			{
				resetBall(&posBall,&xBall,&yBall);
				scoreP1++;
			}
			
			
			
			
			/* Collision avec la barre de gauche */
			
			if(posBall.x <= posBar1.x+BAR_W &&  posBall.x > posBar1.x)
			{
			
			if(posBall.y >= posBar1.y && posBall.y <= posBar1.y + BAR_H)
				xBall = BALL_SPEED;
			
			}
			
			/* Collision avec la barre de droite */
			if(posBall.x >= posBar2.x &&  posBall.x < posBar2.x + BAR_W/2)
			{
			
			if(posBall.y >= posBar2.y && posBall.y <= posBar2.y + BAR_H)
				xBall = -BALL_SPEED;
			
			}
			
			
			
	
			SDL_PollEvent(&event);
			
			switch(event.type)
			{
				case SDL_QUIT:
				alive = 0;
				break;
			}
			
			/* Gestion du clavier */
			SDL_PumpEvents();
			
			if(keystates[SDLK_ESCAPE])
				alive=0;
				
			if(keystates[SDLK_a])
				if(posBar1.y>=5)
				posBar1.y -=5;
				
			if(keystates[SDLK_s])
				if(posBar1.y<=SCREEN_H -BAR_H -5)
				posBar1.y +=5;
				
			if(keystates[SDLK_p])
				if(posBar2.y>=5)
				posBar2.y -=5;
				
			if(keystates[SDLK_l])
				if(posBar2.y<=SCREEN_H -BAR_H-5)
				posBar2.y +=5;
		
	
		
		
		posBall.x += xBall;
		posBall.y += yBall;
		
		
		posScore1.w = score1->w;
		posScore1.h = score1->h;
		
		posScore2.w = score2->w;
		posScore2.h = score2->h;
		
		
		
		/* Affichage des surfaces */
		SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
		
		SDL_BlitSurface(ligne,NULL,screen,&posLigne);
		
		SDL_BlitSurface(ball,NULL,screen,&posBall);
		SDL_BlitSurface(bar,NULL,screen,&posBar1);
		SDL_BlitSurface(bar,NULL,screen,&posBar2);
		
		SDL_BlitSurface(score1,NULL,screen,&posScore1);
		SDL_BlitSurface(score2,NULL,screen,&posScore2);
		
		
		SDL_Flip(screen);
		SDL_Delay(10);
		
	
	}
	
		
	
	
	
	SDL_FreeSurface(score1);
	SDL_FreeSurface(score2);
	SDL_FreeSurface(ligne);
	SDL_FreeSurface(ball);
	TTF_CloseFont(font);
	SDL_FreeSurface(screen);
	SDL_Quit();

}


	
/* Relance la balle */
void resetBall(SDL_Rect *position,int *x,int *y)
{
	position->x  = BALL_X;
	position->y = BALL_Y;
	*x=BALL_SPEED;
	*y=BALL_SPEED;
}
