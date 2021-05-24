#include "hero.h"
#include "vie.h"
#include "score.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string.h>
#include "background.h"
#include <time.h>
#include "faces.h"
#include "colis.h"
#include "minimap.h"
#include "timer.h"
#include "fonctionlvl.h"
#include "es.h"
#include "header.h"
#include "save.h"
int lvl1 (int nbj1,int nbj2,SDL_Surface *screen,int level)
{

	
	
	TTF_Init(); 
    	TTF_Font *police=NULL;
    
	SDL_Surface* times[4];
	times[0]=IMG_Load("t1.png");
	times[1]=IMG_Load("t3.png");
	times[2]=IMG_Load("t5.png");
	times[3]=IMG_Load("t7.png");
	
	SDL_Rect bg_pos;
	bg_pos.x=0;
	bg_pos.y=0;
	
	background bg; 
	initBckg (&bg,"lvl1.png");

	
	int i=0;
	SDL_Surface* pr;
	SDL_Surface* mask;

	SDL_Rect pr_pos;
	mask = IMG_Load("calque1bl.png");

	pr = IMG_Load("perdu.png");
	pr_pos.x=0;
	pr_pos.y=0;
	
	minimap mini;
	init_map(&mini);
	SDL_Color col={0,0,0};

	
	int colision=0,time=0,time2=0,t=0,c=1;
	clock_t debut,debut2;
	debut=clock();
	debut2=initminuteur (&police);
	

	int continuer = 1,dt=0,verification,nbj=0;
	SDL_Event event,event2;
        TTF_Init();
	Hero hero;
	Hero hero2;
	int valeur_score=0,vies=3;
	vie v;
	score s;
	
	initialiser_vie(&v);
	initialiser_score(valeur_score,&s);
	
	int numkeys;
       Uint8 * keys;
       int numkeys2;
       Uint8 * keys2;
       
       int pause=1;
       SDL_Surface* pausemenu;
	pausemenu=IMG_Load("pause menu.png");
	
	SDL_Surface* pausesymbole;
	pausesymbole=IMG_Load("pause.png");
	SDL_Rect pospause;
	pospause.x=98;
	pospause.y=73;
	int D;
       SDL_Rect posred;
        SDL_Color red={255,0,0};
	SDL_Color vert={0,255,0};
	SDL_Color bleu={0,0,255};
	SDL_Color bleuciel={0,255,255};
	SDL_Color rose={255,0,255};
	Ennemi e;
       
       int colenemi=0,enb=1;
	

	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL); //tenezel 3al left wala rigt to93ed temechy
	
 	init_hero(&hero,nbj1);
 	verification=0;
 	do
 	{
 	verification=checkbas(mask,hero.hero_right,hero.position_hero,red);
	hero.position_hero.y++;
        }while(verification==0);
        
        if(nbj2==2)
        {
        init_hero(&hero2,nbj2);
 	verification=0;
 	do
 	{
 	verification=checkbas(mask,hero2.hero_right,hero2.position_hero,red);
	hero2.position_hero.y++;
        }while(verification==0);
        }
        if (nbj2==2)
        nbj=2;
        else
        nbj=1;
        printf("%d",hero2.position_hero.y);
        initEnnemi(&e,hero);
	// GAME LOOP
	while(continuer) 
	{
	
	
	if (SDL_PollEvent(&event)) 
		{	
      switch (event.type) 
			{
				
				case SDL_KEYDOWN:
					switch( event.key.keysym.sym )
					{
					case SDLK_ESCAPE:
					save (valeur_score,vies,level);
					//load (valeur_score,vies,level);
					           continuer = 0;
				                 break;
					        case SDLK_v:
						gestion_vies(&v,&vies);
						break;
						case SDLK_p:
						update_score(&valeur_score);
						break;
					
					
					}
					break;
				case SDL_MOUSEBUTTONUP:
                	  if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=0 && event.motion.x<=198 && event.motion.y>=0 && event.motion.y<=173))
  	              {
  	            pause=0;
  	                    
  	              }
  	              break;
  	           
			       
			       		
				}
		}
	if(pause!=0)
	{
	time=audience (screen,t,debut,time);
	
	
    keys = SDL_GetKeyState(&numkeys);
    keys2 = SDL_GetKeyState(&numkeys2);
    
    SDL_PumpEvents();
       if(nbj<=2)
       {
        
        verification=checkbas(mask,hero.hero_right,hero.position_hero,red);        
      if(keys[SDLK_RIGHT] && !keys[SDLK_SPACE] && !keys[SDLK_DOWN] && (collision_parfaite_r(mask,hero.hero_right,hero.position_hero,col)==0))
        { 
        hero.sens=0;
	animateHero(&hero);
	moveHero(&hero,verification);
	scrollToRight(&bg);
	movemini(&mini,0);
        }
        if(keys[SDLK_LEFT] && !keys[SDLK_SPACE] && !keys[SDLK_DOWN] && (collision_parfaite_l(mask,hero.hero_left,hero.position_hero,col)==0))
        {
	hero.sens=1;
	animateHero(&hero);
	moveHero(&hero,verification);
	scrollToLeft(&bg);
	//scrollToLeft(&mask);
	movemini(&mini,1);
        }
        
        if(keys[SDLK_RIGHT] && keys[SDLK_LCTRL] && !keys[SDLK_SPACE] && (collision_parfaite_r(mask,hero.hero_right,hero.position_hero,col)==0))
        {
	hero.sens=3;
	animateHero(&hero);
	moveHero(&hero,verification);


	scrollToRight(&bg);
	//scrollToRight(&mask);
	movemini(&mini,0);
       }
       if(keys[SDLK_LEFT] && keys[SDLK_LCTRL] && !keys[SDLK_SPACE] && (collision_parfaite_l(mask,hero.hero_left,hero.position_hero,col)==0))
        {
	hero.sens=4;
	animateHero(&hero);
	moveHero(&hero,verification);

	scrollToLeft(&bg);
	//scrollToLeft(&mask);
	movemini(&mini,1);
       }
       if(keys[SDLK_RIGHT] && keys[SDLK_DOWN] && !keys[SDLK_SPACE] && (collision_parfaite_r(mask,hero.hero_right,hero.position_hero,col)==0))
        {
	hero.sens=7;
	moveHero(&hero,verification);


	scrollToRight(&bg);
	//crollToRight(&mask);
	movemini(&mini,0);
       }
       
       if(keys[SDLK_LEFT] && keys[SDLK_DOWN] && !keys[SDLK_SPACE]&& (collision_parfaite_l(mask,hero.hero_left,hero.position_hero,col)==0))
        {
	hero.sens=8;
	moveHero(&hero,verification);

	 scrollToLeft(&bg);
	//scrollToLeft(&mask);
	movemini(&mini,1);
       }
      
       
       if(keys[SDLK_SPACE])
       {
        hero.t=1;

      // scrollToRight(&mask);
        }
      //do
     // {
      if(hero.t==1)
        Sautej1(&hero,keys,verification);
     // verification=checkbas(mask,hero.hero_right,hero.position_hero,red); 
      //}while(verification==0);     
      if ((collision_parfaite_l(mask,hero.hero_left,hero.position_hero,col)==1)&&hero.t==1)
      {
      	hero.position_hero.x=hero.position_hero.x+10;
      	hero.position_hero.y=533;
      }
      if ((collision_parfaite_r(mask,hero.hero_left,hero.position_hero,col)==1)&&hero.t==1)
      {
      	hero.position_hero.x=hero.position_hero.x-10;
      	hero.position_hero.y=533;

      }
      
       
     
       
      
    }
     
    
       if(nbj==2)
       { 
               
      if(keys2[SDLK_d] && !keys2[SDLK_z] && !keys2[SDLK_s])
        { 
        
        hero2.sens=0;
	animateHero(&hero2);
	moveHero(&hero2,verification);
        }
        if(keys2[SDLK_q] && !keys2[SDLK_z] && !keys2[SDLK_s] )
        {
	hero2.sens=1;
	animateHero(&hero2);
	moveHero(&hero2,verification);
	
        }
        
        if(keys2[SDLK_d] && keys2[SDLK_f] && !keys2[SDLK_z])
        {
	hero2.sens=3;
	animateHero(&hero2);
	moveHero(&hero2,verification);
	
       }
       if(keys2[SDLK_q] && keys2[SDLK_f] && !keys2[SDLK_z])
        {
	hero2.sens=4;
	animateHero(&hero2);
	moveHero(&hero2,verification);
       }
       if(keys2[SDLK_d] && keys2[SDLK_s] && !keys2[SDLK_z])
        {
	hero2.sens=7;
	moveHero(&hero2,verification);
       }
       
       if(keys2[SDLK_q] && keys2[SDLK_s] && !keys2[SDLK_z])
        {
	hero2.sens=8;
	moveHero(&hero2,verification);
       }
       if(keys[SDLK_z])
        hero2.t=1;
       
      if(hero2.t==1)
       {
      Sautej2(&hero2,keys2);
       }
    
      
     }
     
     
     if (collision_parfaite_r(mask,hero.hero_right,hero.position_hero,rose)==1)
	{

		while(c==1)
		{
		c=faces(screen);
		if (c==2)
		gestion_vies(&v,&vies);
		}
							
	}
	
	 if (collision_parfaite_r(mask,hero.hero_right,hero.position_hero,col)==1)
	{
               level++;
		continuer=lvl2(nbj1,nbj2,screen,level);
		
							
	}
	
	if (checkhaut(mask,hero.hero_right,hero.position_hero,vert)==1)
	{
	gestion_vies(&v,&vies);
	} 
  
	colenemi=collision(&e,&hero);
	if(colenemi==1)
	{
	while(enb==1)
		{
		enb=enemidefi(screen);
		if (enb==2)
		gestion_vies(&v,&vies);
		}
	}
	

                if((time<30))
                {	
               SDL_BlitSurface(mask,NULL, screen, &bg_pos);
               //SDL_BlitSurface(mask,NULL, screen, &bg_pos);
   
		afficherBckg (screen,bg);

		  if(time>=0 && time<15)
	SDL_BlitSurface(times[0],NULL, screen, &bg_pos);
	else if(time>=15 && time<20)
		SDL_BlitSurface(times[1],NULL, screen, &bg_pos);
	else if(time>=20 && time<25)
		SDL_BlitSurface(times[2],NULL, screen, &bg_pos);
	else if(time>=25 && time<30)
		SDL_BlitSurface(times[3],NULL, screen, &bg_pos);
		SDL_BlitSurface(mini.map,NULL, screen, &mini.positionmap);
		SDL_BlitSurface(mini.minihero,NULL, screen, &mini.positionminihero);
	        
		time2=minuteur(debut2,screen,police,t);
		SDL_BlitSurface(pausesymbole,NULL, screen, &bg_pos);
		afficher_score(&s,screen,valeur_score);
		afficher_vie(v,screen);
		display_hero(hero,hero2,nbj,screen);
		if (enb!=0)
		{
		afficherEnnemi(e,screen);
               animerEnnemi(&e); 
              update(&e,&hero);
              }
		
 		}
		else
		{
		SDL_BlitSurface(pr,NULL, screen, &pr_pos);              
		SDL_Flip(screen);                  
		}                 
		
		
		
		
		
		
	}
	else if (pause==0)
  	              	{
  	              	SDL_BlitSurface(pausemenu,NULL, screen, &bg_pos);
  	              	if (SDL_PollEvent(&event2)) 
		{	
      switch (event2.type) 
			{
				
				
				case SDL_MOUSEBUTTONUP:
                	  if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=438 && event2.motion.x<=843 && event2.motion.y>=300 && event2.motion.y<=354))
  	              {
  	            pause=1;
  	                    
  	              }
  	              if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=438 && event2.motion.x<=843 && event2.motion.y>=300 && event2.motion.y<=354))
  	              {
  	            pause=1;      
  	              }
  	              if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=438 && event2.motion.x<=843 && event2.motion.y>=370 && event2.motion.y<=370+54))
  	              {
  	            //sauvegarder 
  	            save (valeur_score,vies,level);     
  	              }
  	              if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=438 && event2.motion.x<=843 && event2.motion.y>=491 && event2.motion.y<=491+54))
  	              {
  	            continuer=0;     
  	              }
  	              break;
  	           
			       
			       		
				}
		}
  	              	SDL_Flip(screen);
  	              	}   	
	}
	freeHero(&hero);
	freeHero(&hero2);

	free_score(s);
	vie_freevie(v);

	
	  
	
	return(0);
}
int lvl2 (int nbj1,int nbj2,SDL_Surface *screen,int level)
{


	
	TTF_Init(); 
    	TTF_Font *police=NULL;
    
	SDL_Surface* times[4];
	times[0]=IMG_Load("t1.png");
	times[1]=IMG_Load("t3.png");
	times[2]=IMG_Load("t5.png");
	times[3]=IMG_Load("t7.png");
	
	SDL_Rect bg_pos;
	bg_pos.x=0;
	bg_pos.y=0;
	
	background bg; 
	initBckg (&bg,"lvl2.png");

	
	int i=0;
	SDL_Surface* pr;
	SDL_Surface* mask;

	SDL_Rect pr_pos;
	mask = IMG_Load("calque2bl.png");

	pr = IMG_Load("perdu.png");
	pr_pos.x=0;
	pr_pos.y=0;
	
	minimap mini;
	init_map(&mini);
	SDL_Color col={0,0,0};

	
	int colision=0,time=0,time2=0,t=0,c=1;
	clock_t debut,debut2;
	debut=clock();
	debut2=initminuteur (&police);
	

	int continuer = 1,dt=0,verification,nbj=0;
	SDL_Event event,event2;
        TTF_Init();
	Hero hero;
	Hero hero2;
	int valeur_score=0,vies=3;
	vie v;
	score s;
	
	initialiser_vie(&v);
	initialiser_score(valeur_score,&s);
	update_score(&valeur_score);
	int numkeys;
       Uint8 * keys;
       int numkeys2;
       Uint8 * keys2;
       
       int pause=1;
       SDL_Surface* pausemenu;
	pausemenu=IMG_Load("pause menu.png");
	
	SDL_Surface* pausesymbole;
	pausesymbole=IMG_Load("pause.png");
	SDL_Rect pospause;
	pospause.x=98;
	pospause.y=73;
	
       SDL_Rect posred;
        SDL_Color red={255,0,0};
	SDL_Color vert={0,255,0};
	SDL_Color bleu={0,0,255};
	SDL_Color bleuciel={0,255,255};
	SDL_Color rose={255,0,255};
	
       
       int colenemi=0,enb=1;
	int tabl[30];
        enigme tableau[8];
        int j;
         int r=1;

init_enigmes(tabl,tableau);

	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL); //tenezel 3al left wala rigt to93ed temechy
	
 	init_hero(&hero,nbj1);
 	verification=0;
 	do
 	{
 	verification=checkbas(mask,hero.hero_right,hero.position_hero,red);
	hero.position_hero.y++;
        }while(verification==0);
        
        if(nbj2==2)
        {
        init_hero(&hero2,nbj2);
 	verification=0;
 	do
 	{
 	verification=checkbas(mask,hero2.hero_right,hero2.position_hero,red);
	hero2.position_hero.y++;
        }while(verification==0);
        }
        if (nbj2==2)
        nbj=2;
        else
        nbj=1;
        printf("%d",hero2.position_hero.y);

	// GAME LOOP
	while(continuer) 
	{
	
	
	if (SDL_PollEvent(&event)) 
		{	
      switch (event.type) 
			{
				
				case SDL_KEYDOWN:
					switch( event.key.keysym.sym )
					{
					case SDLK_ESCAPE:
					save (valeur_score,vies,level);
					//load (valeur_score,vies,level);
					           continuer = 0;
				                 break;
					        case SDLK_v:
						gestion_vies(&v,&vies);
						break;
						case SDLK_p:
						update_score(&valeur_score);
						break;
					
					}
					break;
				case SDL_MOUSEBUTTONUP:
                	  if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=0 && event.motion.x<=198 && event.motion.y>=0 && event.motion.y<=173))
  	              {
  	            pause=0;
  	                    
  	              }
  	              break;
  	           
			       
			       		
				}
		}
	if(pause!=0)
	{
	time=audience (screen,t,debut,time);
	
	
    keys = SDL_GetKeyState(&numkeys);
    keys2 = SDL_GetKeyState(&numkeys2);
    
    SDL_PumpEvents();
       if(nbj<=2)
       {
        
        verification=checkbas(mask,hero.hero_right,hero.position_hero,red);        
      if(keys[SDLK_RIGHT] && !keys[SDLK_SPACE] && !keys[SDLK_DOWN] && (collision_parfaite_r(mask,hero.hero_right,hero.position_hero,col)==0))
        { 
        hero.sens=0;
	animateHero(&hero);
	moveHero(&hero,verification);
	scrollToRight(&bg);
	movemini(&mini,0);
        }
        if(keys[SDLK_LEFT] && !keys[SDLK_SPACE] && !keys[SDLK_DOWN] && (collision_parfaite_l(mask,hero.hero_left,hero.position_hero,col)==0))
        {
	hero.sens=1;
	animateHero(&hero);
	moveHero(&hero,verification);
	scrollToLeft(&bg);
	//scrollToLeft(&mask);
	movemini(&mini,1);
        }
        
        if(keys[SDLK_RIGHT] && keys[SDLK_LCTRL] && !keys[SDLK_SPACE] && (collision_parfaite_r(mask,hero.hero_right,hero.position_hero,col)==0))
        {
	hero.sens=3;
	animateHero(&hero);
	moveHero(&hero,verification);


	scrollToRight(&bg);
	//scrollToRight(&mask);
	movemini(&mini,0);
       }
       if(keys[SDLK_LEFT] && keys[SDLK_LCTRL] && !keys[SDLK_SPACE] && (collision_parfaite_l(mask,hero.hero_left,hero.position_hero,col)==0))
        {
	hero.sens=4;
	animateHero(&hero);
	moveHero(&hero,verification);

	scrollToLeft(&bg);
	//scrollToLeft(&mask);
	movemini(&mini,1);
       }
       if(keys[SDLK_RIGHT] && keys[SDLK_DOWN] && !keys[SDLK_SPACE] && (collision_parfaite_r(mask,hero.hero_right,hero.position_hero,col)==0))
        {
	hero.sens=7;
	moveHero(&hero,verification);


	scrollToRight(&bg);
	//crollToRight(&mask);
	movemini(&mini,0);
       }
       
       if(keys[SDLK_LEFT] && keys[SDLK_DOWN] && !keys[SDLK_SPACE]&& (collision_parfaite_l(mask,hero.hero_left,hero.position_hero,col)==0))
        {
	hero.sens=8;
	moveHero(&hero,verification);

	 scrollToLeft(&bg);
	//scrollToLeft(&mask);
	movemini(&mini,1);
       }
      
       
       if(keys[SDLK_SPACE])
       {
        hero.t=1;

      // scrollToRight(&mask);
        }
      //do
     // {
      if(hero.t==1)
        Sautej1(&hero,keys,verification);
     // verification=checkbas(mask,hero.hero_right,hero.position_hero,red); 
      //}while(verification==0);     
      if ((collision_parfaite_l(mask,hero.hero_left,hero.position_hero,col)==1)&&hero.t==1)
      {
      	hero.position_hero.x=hero.position_hero.x+10;
      	hero.position_hero.y=533;
      }
      if ((collision_parfaite_r(mask,hero.hero_left,hero.position_hero,col)==1)&&hero.t==1)
      {
      	hero.position_hero.x=hero.position_hero.x-10;
      	hero.position_hero.y=533;

      }
      
       
     
       
      
    }
     
    
       if(nbj==2)
       { 
               
      if(keys2[SDLK_d] && !keys2[SDLK_z] && !keys2[SDLK_s])
        { 
        
        hero2.sens=0;
	animateHero(&hero2);
	moveHero(&hero2,verification);
        }
        if(keys2[SDLK_q] && !keys2[SDLK_z] && !keys2[SDLK_s] )
        {
	hero2.sens=1;
	animateHero(&hero2);
	moveHero(&hero2,verification);
	
        }
        
        if(keys2[SDLK_d] && keys2[SDLK_f] && !keys2[SDLK_z])
        {
	hero2.sens=3;
	animateHero(&hero2);
	moveHero(&hero2,verification);
	
       }
       if(keys2[SDLK_q] && keys2[SDLK_f] && !keys2[SDLK_z])
        {
	hero2.sens=4;
	animateHero(&hero2);
	moveHero(&hero2,verification);
       }
       if(keys2[SDLK_d] && keys2[SDLK_s] && !keys2[SDLK_z])
        {
	hero2.sens=7;
	moveHero(&hero2,verification);
       }
       
       if(keys2[SDLK_q] && keys2[SDLK_s] && !keys2[SDLK_z])
        {
	hero2.sens=8;
	moveHero(&hero2,verification);
       }
       if(keys[SDLK_z])
        hero2.t=1;
       
      if(hero2.t==1)
       {
      Sautej2(&hero2,keys2);
       }
    
      
     }
     
     
     if (collision_parfaite_r(mask,hero.hero_right,hero.position_hero,rose)==1)
	{
		while(r==1)
		{
		j=generer_enigmes(tabl);
                r=saisir(screen,tableau,j);
                if (r!=0)
                gestion_vies(&v,&vies);
                }
                						
	}
	
	if (collision_parfaite_r(mask,hero.hero_right,hero.position_hero,col)==1)
	{
                level++;
		continuer=lvl3(nbj1,nbj2,screen,level);
		
							
	}
	
	if (checkhaut(mask,hero.hero_right,hero.position_hero,vert)==1)
	{
	gestion_vies(&v,&vies);
	} 
  
	
	

                if((time<30))
                {	
               SDL_BlitSurface(mask,NULL, screen, &bg_pos);
               //SDL_BlitSurface(mask,NULL, screen, &bg_pos);
   
		afficherBckg (screen,bg);

		  if(time>=0 && time<15)
	SDL_BlitSurface(times[0],NULL, screen, &bg_pos);
	else if(time>=15 && time<20)
		SDL_BlitSurface(times[1],NULL, screen, &bg_pos);
	else if(time>=20 && time<25)
		SDL_BlitSurface(times[2],NULL, screen, &bg_pos);
	else if(time>=25 && time<30)
		SDL_BlitSurface(times[3],NULL, screen, &bg_pos);
		SDL_BlitSurface(mini.map,NULL, screen, &mini.positionmap);
		SDL_BlitSurface(mini.minihero,NULL, screen, &mini.positionminihero);
	       
		time2=minuteur(debut2,screen,police,t);
		SDL_BlitSurface(pausesymbole,NULL, screen, &bg_pos);
		afficher_score(&s,screen,valeur_score);
		afficher_vie(v,screen);
		display_hero(hero,hero2,nbj,screen);
		
		
 		}
		else
		{
		SDL_BlitSurface(pr,NULL, screen, &pr_pos);              
		SDL_Flip(screen);                  
		}                 
		
		
		
		
		
		
	}
	else if (pause==0)
  	              	{
  	              	SDL_BlitSurface(pausemenu,NULL, screen, &bg_pos);
  	              	if (SDL_PollEvent(&event2)) 
		{	
      switch (event2.type) 
			{
				
				
				case SDL_MOUSEBUTTONUP:
                	  if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=438 && event2.motion.x<=843 && event2.motion.y>=300 && event2.motion.y<=354))
  	              {
  	            pause=1;
  	                    
  	              }
  	              if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=438 && event2.motion.x<=843 && event2.motion.y>=300 && event2.motion.y<=354))
  	              {
  	            pause=1;      
  	              }
  	              if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=438 && event2.motion.x<=843 && event2.motion.y>=370 && event2.motion.y<=370+54))
  	              {
  	            //sauvegarder  
  	            save (valeur_score,vies,level);    
  	              }
  	              if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=438 && event2.motion.x<=843 && event2.motion.y>=491 && event2.motion.y<=491+54))
  	              {
  	            continuer=0;     
  	              }
  	              break;
  	           
			       
			       		
				}
		}
  	              	SDL_Flip(screen);
  	              	}   	
	}
	freeHero(&hero);
	freeHero(&hero2);

	free_score(s);
	vie_freevie(v);

	
	  
	
	return(0);
}

int lvl3 (int nbj1,int nbj2,SDL_Surface *screen,int level)
{

	
	
	TTF_Init(); 
    	TTF_Font *police=NULL;
    
	SDL_Surface* times[4];
	times[0]=IMG_Load("t1.png");
	times[1]=IMG_Load("t3.png");
	times[2]=IMG_Load("t5.png");
	times[3]=IMG_Load("t7.png");
	
	SDL_Rect bg_pos;
	bg_pos.x=0;
	bg_pos.y=0;
	
	background bg; 
	initBckg (&bg,"LVL3.png");

	
	int i=0;
	SDL_Surface* pr;
	SDL_Surface* mask;

	SDL_Rect pr_pos;
	mask = IMG_Load("calque3.png");

	pr = IMG_Load("perdu.png");
	pr_pos.x=0;
	pr_pos.y=0;
	
	minimap mini;
	init_map(&mini);
	SDL_Color col={0,0,0};

	
	int colision=0,time=0,time2=0,t=0,c=1;
	clock_t debut,debut2;
	debut=clock();
	debut2=initminuteur (&police);
	

	int continuer = 1,dt=0,verification,nbj=0;
	SDL_Event event,event2;
        TTF_Init();
	Hero hero;
	Hero hero2;
	int valeur_score=0,vies=3;
	vie v;
	score s;
	
	initialiser_vie(&v);
	initialiser_score(valeur_score,&s);
	update_score(&valeur_score);
	update_score(&valeur_score);
	int numkeys;
       Uint8 * keys;
       int numkeys2;
       Uint8 * keys2;
       
       int pause=1;
       SDL_Surface* pausemenu;
	pausemenu=IMG_Load("pause menu.png");
	
	SDL_Surface* pausesymbole;
	pausesymbole=IMG_Load("pause.png");
	SDL_Rect pospause;
	pospause.x=98;
	pospause.y=73;
	
       SDL_Rect posred;
        SDL_Color red={255,0,0};
	SDL_Color vert={0,255,0};
	SDL_Color bleu={0,0,255};
	SDL_Color bleuciel={0,255,255};
	SDL_Color rose={255,0,255};
	
       
       int colenemi=0,enb=1;
	

	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL); //tenezel 3al left wala rigt to93ed temechy
	
 	init_hero(&hero,nbj1);
 	verification=0;
 	do
 	{
 	verification=checkbas(mask,hero.hero_right,hero.position_hero,red);
	hero.position_hero.y++;
        }while(verification==0);
        
        if(nbj2==2)
        {
        init_hero(&hero2,nbj2);
 	verification=0;
 	do
 	{
 	verification=checkbas(mask,hero2.hero_right,hero2.position_hero,red);
	hero2.position_hero.y++;
        }while(verification==0);
        }
        if (nbj2==2)
        nbj=2;
        else
        nbj=1;
        printf("%d",hero2.position_hero.y);

	// GAME LOOP
	while(continuer) 
	{
	
	
	if (SDL_PollEvent(&event)) 
		{	
      switch (event.type) 
			{
				
				case SDL_KEYDOWN:
					switch( event.key.keysym.sym )
					{
					case SDLK_ESCAPE:
					save (valeur_score,vies,level);
					//load (valeur_score,vies,level);
					           continuer = 0;
				                 break;
					        case SDLK_v:
						gestion_vies(&v,&vies);
						break;
						case SDLK_p:
						update_score(&valeur_score);
						break;
					
					
					}
					break;
				case SDL_MOUSEBUTTONUP:
                	  if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>=0 && event.motion.x<=198 && event.motion.y>=0 && event.motion.y<=173))
  	              {
  	            pause=0;
  	                    
  	              }
  	              break;
  	           
			       
			       		
				}
		}
	if(pause!=0)
	{
	time=audience (screen,t,debut,time);
	
	
    keys = SDL_GetKeyState(&numkeys);
    keys2 = SDL_GetKeyState(&numkeys2);
    
    SDL_PumpEvents();
       if(nbj<=2)
       {
        
        verification=checkbas(mask,hero.hero_right,hero.position_hero,red);        
      if(keys[SDLK_RIGHT] && !keys[SDLK_SPACE] && !keys[SDLK_DOWN] && (collision_parfaite_r(mask,hero.hero_right,hero.position_hero,col)==0))
        { 
        hero.sens=0;
	animateHero(&hero);
	moveHero(&hero,verification);
	scrollToRight(&bg);
	movemini(&mini,0);
        }
        if(keys[SDLK_LEFT] && !keys[SDLK_SPACE] && !keys[SDLK_DOWN] && (collision_parfaite_l(mask,hero.hero_left,hero.position_hero,col)==0))
        {
	hero.sens=1;
	animateHero(&hero);
	moveHero(&hero,verification);
	scrollToLeft(&bg);
	//scrollToLeft(&mask);
	movemini(&mini,1);
        }
        
        if(keys[SDLK_RIGHT] && keys[SDLK_LCTRL] && !keys[SDLK_SPACE] && (collision_parfaite_r(mask,hero.hero_right,hero.position_hero,col)==0))
        {
	hero.sens=3;
	animateHero(&hero);
	moveHero(&hero,verification);


	scrollToRight(&bg);
	//scrollToRight(&mask);
	movemini(&mini,0);
       }
       if(keys[SDLK_LEFT] && keys[SDLK_LCTRL] && !keys[SDLK_SPACE] && (collision_parfaite_l(mask,hero.hero_left,hero.position_hero,col)==0))
        {
	hero.sens=4;
	animateHero(&hero);
	moveHero(&hero,verification);

	scrollToLeft(&bg);
	//scrollToLeft(&mask);
	movemini(&mini,1);
       }
       if(keys[SDLK_RIGHT] && keys[SDLK_DOWN] && !keys[SDLK_SPACE] && (collision_parfaite_r(mask,hero.hero_right,hero.position_hero,col)==0))
        {
	hero.sens=7;
	moveHero(&hero,verification);


	scrollToRight(&bg);
	//crollToRight(&mask);
	movemini(&mini,0);
       }
       
       if(keys[SDLK_LEFT] && keys[SDLK_DOWN] && !keys[SDLK_SPACE]&& (collision_parfaite_l(mask,hero.hero_left,hero.position_hero,col)==0))
        {
	hero.sens=8;
	moveHero(&hero,verification);

	 scrollToLeft(&bg);
	//scrollToLeft(&mask);
	movemini(&mini,1);
       }
      
       
       if(keys[SDLK_SPACE])
       {
        hero.t=1;

      // scrollToRight(&mask);
        }
      //do
     // {
      if(hero.t==1)
        Sautej1(&hero,keys,verification);
     // verification=checkbas(mask,hero.hero_right,hero.position_hero,red); 
      //}while(verification==0);     
      if ((collision_parfaite_l(mask,hero.hero_left,hero.position_hero,col)==1)&&hero.t==1)
      {
      	hero.position_hero.x=hero.position_hero.x+10;
      	hero.position_hero.y=533;
      }
      if ((collision_parfaite_r(mask,hero.hero_left,hero.position_hero,col)==1)&&hero.t==1)
      {
      	hero.position_hero.x=hero.position_hero.x-10;
      	hero.position_hero.y=533;

      }
      
       
     
       
      
    }
     
    
       if(nbj==2)
       { 
               
      if(keys2[SDLK_d] && !keys2[SDLK_z] && !keys2[SDLK_s])
        { 
        
        hero2.sens=0;
	animateHero(&hero2);
	moveHero(&hero2,verification);
        }
        if(keys2[SDLK_q] && !keys2[SDLK_z] && !keys2[SDLK_s] )
        {
	hero2.sens=1;
	animateHero(&hero2);
	moveHero(&hero2,verification);
	
        }
        
        if(keys2[SDLK_d] && keys2[SDLK_f] && !keys2[SDLK_z])
        {
	hero2.sens=3;
	animateHero(&hero2);
	moveHero(&hero2,verification);
	
       }
       if(keys2[SDLK_q] && keys2[SDLK_f] && !keys2[SDLK_z])
        {
	hero2.sens=4;
	animateHero(&hero2);
	moveHero(&hero2,verification);
       }
       if(keys2[SDLK_d] && keys2[SDLK_s] && !keys2[SDLK_z])
        {
	hero2.sens=7;
	moveHero(&hero2,verification);
       }
       
       if(keys2[SDLK_q] && keys2[SDLK_s] && !keys2[SDLK_z])
        {
	hero2.sens=8;
	moveHero(&hero2,verification);
       }
       if(keys[SDLK_z])
        hero2.t=1;
       
      if(hero2.t==1)
       {
      Sautej2(&hero2,keys2);
       }
    
      
     }
     
     
     if (collision_parfaite_r(mask,hero.hero_right,hero.position_hero,rose)==1)
	{

		while(c==1)
		{
		c=faces(screen);
		if (c==2)
		gestion_vies(&v,&vies);
		}
							
	}
	
	if (collision_parfaite_r(mask,hero.hero_right,hero.position_hero,col)==1)
	{

		continuer=lvl3(nbj1,nbj2,screen,level);
		
							
	}
	
	if (checkhaut(mask,hero.hero_right,hero.position_hero,vert)==1)
	{
	gestion_vies(&v,&vies);
	} 
  
	
	

                if((time<30))
                {	
               SDL_BlitSurface(mask,NULL, screen, &bg_pos);
               //SDL_BlitSurface(mask,NULL, screen, &bg_pos);
   
		afficherBckg (screen,bg);

		  if(time>=0 && time<15)
	SDL_BlitSurface(times[0],NULL, screen, &bg_pos);
	else if(time>=15 && time<20)
		SDL_BlitSurface(times[1],NULL, screen, &bg_pos);
	else if(time>=20 && time<25)
		SDL_BlitSurface(times[2],NULL, screen, &bg_pos);
	else if(time>=25 && time<30)
		SDL_BlitSurface(times[3],NULL, screen, &bg_pos);
		SDL_BlitSurface(mini.map,NULL, screen, &mini.positionmap);
		SDL_BlitSurface(mini.minihero,NULL, screen, &mini.positionminihero);
	       
		time2=minuteur(debut2,screen,police,t);
		SDL_BlitSurface(pausesymbole,NULL, screen, &bg_pos);
		afficher_score(&s,screen,valeur_score);
		afficher_vie(v,screen);
		display_hero(hero,hero2,nbj,screen);
		
		
 		}
		else
		{
		SDL_BlitSurface(pr,NULL, screen, &pr_pos);              
		SDL_Flip(screen);                  
		}
		
		
		
		
		
	}
	else if (pause==0)
  	              	{
  	              	SDL_BlitSurface(pausemenu,NULL, screen, &bg_pos);
  	              	if (SDL_PollEvent(&event2)) 
		{	
      switch (event2.type) 
			{
				
				
				case SDL_MOUSEBUTTONUP:
                	  if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=438 && event2.motion.x<=843 && event2.motion.y>=300 && event2.motion.y<=354))
  	              {
  	            pause=1;
  	                    
  	              }
  	              if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=438 && event2.motion.x<=843 && event2.motion.y>=300 && event2.motion.y<=354))
  	              {
  	            pause=1;      
  	              }
  	              if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=438 && event2.motion.x<=843 && event2.motion.y>=370 && event2.motion.y<=370+54))
  	              {
  	            //sauvegarder
  	            save (valeur_score,vies,level);      
  	              }
  	              if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=438 && event2.motion.x<=843 && event2.motion.y>=491 && event2.motion.y<=491+54))
  	              {
  	            continuer=0;     
  	              }
  	              break;
  	           
			       
			       		
				}
		}
  	              	SDL_Flip(screen);
  	              	}   	
	}
	freeHero(&hero);
	freeHero(&hero2);

	free_score(s);
	vie_freevie(v);

	
	  
	
	return(0);
}



