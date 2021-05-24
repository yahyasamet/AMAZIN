#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL_ttf.h>
#include <string.h>

void init_enigmes(int tabl[],enigme tableau[])
{ 
int i;
char photo[20];


for(i=0;i<8;i++)
tabl[i]=0;

/*for(i=0;i<30;i++)
{
sprintf(photo,"enigme%d.png",i);
tableau[i]->image=IMG_Load(photo);
}*/

strcpy(tableau[0].solution,"deuxieme");
strcpy(tableau[1].solution,"2kilo");
strcpy(tableau[2].solution,"n");


}




int generer_enigmes(int tabl[])
{
int j;
srand(time(NULL));
do
{	
  j=rand()%3;
}
while (tabl[j]==1);
tabl[j]=1;
return j;
}




int saisir(SDL_Surface *ecran,enigme tableau[],int j)
{

	int tempsinit=SDL_GetTicks();
	int tempsactuel=SDL_GetTicks();
	int tempsrestant;
	SDL_Surface *fond=NULL;
	SDL_Surface *texte=NULL;
char stempsrestant[50];

	SDL_Rect positiont;
	positiont.x = 10;
positiont.y = 10;
	SDL_Surface *temps=NULL;
	TTF_Font *police =NULL;
	int continuer =1;
SDL_Rect position1;
	int i;
	char l;
	char chaine[10];
	sprintf(chaine,"enigmes%d.png",j);  
	fond=IMG_Load(chaine);
SDL_Rect posi;
posi.x=0;
posi.y=0;
SDL_BlitSurface(fond,NULL,ecran,&posi);
SDL_Flip(ecran);
	char mot[100]={0};
	SDL_Event event;
	SDL_Rect position;
position.x = 398;
position.y = 452;
	SDL_Color couleur={255,255,255};
	SDL_Color couleurn={0,0,0};
	int z=0;
	TTF_Init();

	police = TTF_OpenFont("angelina.ttf",35);
	while (continuer)
	{


//ICI
	tempsactuel=SDL_GetTicks();
	
	if(tempsactuel-tempsinit<20000)
	{
		//printf("%d\n",tempsrestant);
		tempsrestant=20000-tempsactuel;
		sprintf(stempsrestant,"%d",tempsrestant);
		temps = TTF_RenderText_Blended(police,stempsrestant,couleurn);
		SDL_BlitSurface(fond, NULL, ecran, &position1);
		SDL_BlitSurface(texte, NULL, ecran, &position);
		SDL_BlitSurface(temps, NULL, ecran, &positiont);
		SDL_Flip(ecran);



	SDL_WaitEvent(&event);
	switch(event.type)
	{


		case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{
				case SDLK_RETURN:
				continuer=0;
		break;

case SDLK_KP0:
l='0';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;


case SDLK_KP1:
l='1';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;


case SDLK_KP2:
l='2';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;

break;

case SDLK_KP3:
l='3';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;


case SDLK_KP4:
l='4';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;

break;

case SDLK_KP5:
l='5';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;

break;

case SDLK_KP6:
l='6';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;

break;

case SDLK_KP7:
l='7';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;

break;

case SDLK_KP8:
l='8';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_KP9:
l='9';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_a:
l='a';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);

SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_b:
l='b';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;

break;

case SDLK_c:
l='c';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_d:
l='d';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;

break;

case SDLK_e:
l='e';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_f:
l='f';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_g:
l='g';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;

break;

case SDLK_h:
l='h';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_i:
l='i';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_j:
l='j';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_k:
l='k';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_l:
l='l';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_m:
l='m';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_n:
l='n';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;

break;

case SDLK_o:
l='o';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_p:
l='p';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_q:
l='q';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_r:
l='r';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_s:
l='s';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_t:
l='t';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_u:
l='u';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_v:
l='v';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_w:
l='w';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_x:
l='x';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_y:
l='y';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_z:
l='z';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;

case SDLK_SPACE:
l=' ';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position1.x = 0;
position1.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position1);

SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
if (position.x>=328)
position.x=position.x-5;


break;
case SDLK_BACKSPACE:
z--;
mot[z]='\0';
texte = TTF_RenderText_Blended(police,mot,couleur);
//position.x = 0;
//position.y = 0;
if (position.x<=398)
position.x=position.x+5;

SDL_BlitSurface(fond, NULL, ecran, &position1);

//position.x = 328;
//position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
break;

}
}
}
else
{
break;
}
}

int r;
if (strcmp(mot,"stalwart")==0)
{r=0;
return r;
}
r=strcmp(mot,tableau[j].solution);

TTF_CloseFont(police);
TTF_Quit();
SDL_FreeSurface(texte);
SDL_FreeSurface(fond);
return r;
}




