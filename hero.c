#include "hero.h"
#include "colis.h"

void init_hero(Hero* h,int x)
{
     if(x==1)
     {
        h->hero_right = IMG_Load("p1.png");
h->hero_left = IMG_Load("p2.png");
h->hero_runr=IMG_Load("p5.png");
h->hero_runl=IMG_Load("p6.png");
        h->hero_downr=IMG_Load("p7.png");
        h->hero_downl=IMG_Load("p8.png");
       



h->sens=0;
h->frame=0;
h->frame1=0;
h->position_hero.x = 30;
h->position_hero.y = 0;
h->status=0;
h->t=0;
    }
if(x==2)
    {

h->hero_right = IMG_Load("p10.png");
h->hero_left = IMG_Load("p20.png");
h->hero_runr=IMG_Load("p50.png");
h->hero_runl=IMG_Load("p60.png");
        h->hero_downr=IMG_Load("p70.png");
        h->hero_downl=IMG_Load("p80.png");
       

h->sens=0;
h->frame=0;
h->frame1=0;
h->position_hero.x = 100;
h->position_hero.y = 0;
h->status=0;
h->t=0;

    }
int i =0,j=0,m=0,l=0;
for (i = 0; i < 4; i++)
{
h->right[i].x = i*94.4 ;
h->right[i].y = 0;
h->right[i].w =94.4 ;
h->right[i].h = 235;
}


for (j = 0; j < 4; j++)
{
h->left[j].x = j*94.4;
h->left[j].y = 0;
h->left[j].w = 94.4;
h->left[j].h = 235;
}

for (m= 0; m< 5; m++)
{
h->runr[m].x = m*151.6;
h->runr[m].y = 0;
h->runr[m].w = 151.6 ;
h->runr[m].h = 235;
}
for (l= 0; l< 5; l++)
{
h->runl[l].x = l*151.6 ;
h->runl[l].y = 0;
h->runl[l].w = 151.6 ;
h->runl[l].h = 235;
}
}

	



void display_hero(Hero h,Hero h2,int nbj, SDL_Surface* screen)
{
      if(nbj<=2) 
      {
        if(h.sens==0 )
        {
		SDL_BlitSurface(h.hero_right, &h.right[h.frame], screen, &h.position_hero);
	}
	else if (h.sens==1)
        {
		SDL_BlitSurface(h.hero_left, &h.right[h.frame], screen, &h.position_hero);
	}
 
	else if (h.sens==3)
        {
		SDL_BlitSurface(h.hero_runr, &h.runr[h.frame1], screen, &h.position_hero);	
	}
	
	else if (h.sens==4)
        {
	SDL_BlitSurface(h.hero_runl, &h.runl[h.frame1], screen, &h.position_hero);
			
	}

	else if (h.sens==7)
        {
	SDL_BlitSurface(h.hero_downr, NULL, screen, &h.position_hero);	
	}
	else if (h.sens==8)
        {
	SDL_BlitSurface(h.hero_downl, NULL, screen, &h.position_hero);	
	}
     }
     if(nbj==2) 
      {
        if(h2.sens==0 )
        {
		SDL_BlitSurface(h2.hero_right, &h2.right[h2.frame], screen, &h2.position_hero);
	}
	else if (h2.sens==1)
        {
		SDL_BlitSurface(h2.hero_left, &h2.right[h2.frame], screen, &h2.position_hero);
	}
 
	else if (h2.sens==3)
        {
		SDL_BlitSurface(h2.hero_runr, &h2.runr[h2.frame1], screen, &h2.position_hero);	
	}
	
	else if (h2.sens==4)
        {
	SDL_BlitSurface(h2.hero_runl, &h2.runl[h2.frame1], screen, &h2.position_hero);
			
	}

	else if (h2.sens==7)
        {
	SDL_BlitSurface(h2.hero_downr, NULL, screen, &h2.position_hero);	
	}
	else if (h2.sens==8)
        {
	SDL_BlitSurface(h2.hero_downl, NULL, screen, &h2.position_hero);	
	}
     }
	
		SDL_Flip(screen);
}


void animateHero(Hero* h)
{ 


      if((h->sens==0 || h->sens==1  ))  
   {
      
	h->frame++;
	
	if ( h->frame > 4 )
	{
		h->frame = 0;
	}
  }
  if(h->sens==4 || h->sens==3)
{
h->frame1++;

	if ( h->frame1 > 5 )
	{
		h->frame1 = 0;
	}
} 

 

 	
}



void moveHero(Hero *H,int verif)
{
	     if(H->sens==0 && verif==1)
        	H->position_hero.x+=5;   
        else if(H->sens==1 && verif==1)
        	H->position_hero.x-=5; 
        else if (H->sens==3 && verif==1)
               H->position_hero.x+=20;
        else if (H->sens==4 && verif==1)
               H->position_hero.x-=20;
        else if (H->sens==7 && verif==1)
               H->position_hero.x+=15;    
        else if (H->sens==8 && verif==1)
               H->position_hero.x-=15;           
}

void Saute(Hero *h,float impulsion)
{
     h->vy = -impulsion;
    h->status = 1;

}
void ControleSol(Hero *h,int verif)
{
if (verif==1)
    {
        h->position_hero.y++;
        if (h->vy>0)
            h->vy = 0.0f;
        h->status = 0;
    }
}
void Gravite(Hero *h,float factgravite,float factsautmaintenu,Uint8* keys)
{

    if (h->status == 1 && keys[SDLK_SPACE])
        factgravite/=factsautmaintenu;
    h->vy += factgravite;
    
   
    
}
void Evolue(Hero *h,Uint8* keys,int verif)
{

    float lateralspeed = 0.75f;
    float airlateralspeedfacteur = 0.75f; 
    float maxhspeed = 4.5f;
    float adherance = 2.25f;
    float impulsion = 9.0f;
    float factgravite = 0.75f;
    float factsautmaintenu = 4.5f;


// controle lateral

if (h->status == 0)
{
h->vx=0;
h->vy=0;
h->t=0;
}
    if (h->status == 1) // (*2)
        lateralspeed*= airlateralspeedfacteur;
         
    if (keys[SDLK_LEFT]) // (*1)
        h->vx-=lateralspeed;
    if (keys[SDLK_RIGHT])
        h->vx+=lateralspeed;
   if (h->status == 0 && !keys[SDLK_LEFT] && !keys[SDLK_RIGHT]) // (*3)
         h->vx/=adherance; 
        
// limite vitesse
    if (h->vx>maxhspeed) // (*4)
        h->vx = maxhspeed;
    if (h->vx<-maxhspeed)
        h->vx = -maxhspeed; 
// saut
    if (keys[SDLK_SPACE] && h->status == 0)
    
        Saute(h,impulsion);
    Gravite(h,factgravite,factsautmaintenu,keys);
    ControleSol(h,verif);
    
// application du vecteur à la position.
    h->position_hero.x +=h->vx;
    h->position_hero.y +=h->vy;
  
   

}

void Sautej1(Hero *h,Uint8* keys,int verif)
{

  // Uint32 timer,elapsed;

  // timer = SDL_GetTicks();
            Evolue(&(*h),keys,verif);
    //        elapsed =SDL_GetTicks()-timer;
    //        if (elapsed<5)
    //        SDL_Delay(5-elapsed);
   

}


void Gravite2(Hero *h,float factgravite,float factsautmaintenu,Uint8* keys)
{
    if (h->status == 1 && keys[SDLK_z])
        factgravite/=factsautmaintenu;
    h->vy += factgravite;
    
}
void Evolue2(Hero *h,Uint8* keys)
{

    float lateralspeed = 0.75f;
    float airlateralspeedfacteur = 0.75f; 
    float maxhspeed = 4.5f;
    float adherance = 2.25f;
    float impulsion = 9.0f;
    float factgravite = 0.75f;
    float factsautmaintenu = 4.5f;
    
if (h->status == 0)
{
h->vx=0;
h->vy=0;
h->t=0;
}
    
    
// controle lateral
    if (h->status == 1) // (*2)
        lateralspeed*= airlateralspeedfacteur;
         
    if (keys[SDLK_q]) // (*1)
        h->vx-=lateralspeed;
    if (keys[SDLK_d])
        h->vx+=lateralspeed;
   if (h->status == 0 && !keys[SDLK_q] && !keys[SDLK_d]) // (*3)
        h->vx/=adherance; 
        
// limite vitesse
    if (h->vx>maxhspeed) // (*4)
        h->vx = maxhspeed;
    if (h->vx<-maxhspeed)
        h->vx = -maxhspeed; 
// saut
    if (keys[SDLK_z] && h->status == 0)
    
        Saute(h,impulsion);
    Gravite2(h,factgravite,factsautmaintenu,keys);
    //ControleSol(h);
    
// application du vecteur à la position.
    h->position_hero.x +=h->vx;
    h->position_hero.y +=h->vy;
    
   

}
void Sautej2(Hero *h,Uint8* keys)
{

  // Uint32 timer,elapsed;

  // timer = SDL_GetTicks();
            Evolue2(&(*h),keys);
    //        elapsed =SDL_GetTicks()-timer;
    //        if (elapsed<5)
    //        SDL_Delay(5-elapsed);
   

}








void freeHero(Hero *H)
{
	SDL_FreeSurface(H->hero_right);
	SDL_FreeSurface(H->hero_left);
	SDL_FreeSurface(H->hero_runr);
	SDL_FreeSurface(H->hero_runl);
	SDL_FreeSurface(H->hero_downr);
	SDL_FreeSurface(H->hero_downl);
	
}
