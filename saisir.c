#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL_ttf.h>

int saisir(SDL_Surface *ecran,enigme tableau[],int j)
{
SDL_Surface *fond=NULL;
SDL_Surface *texte=NULL;
TTF_Font *police =NULL;
int continuer =1;
int i,j;
char l;
char chaine[10];
sprintf(chaine,"enigme%d.png",j);
fond=IMG_Load(chaine);

char mot[100]={0};
SDL_Event event;
SDL_Rect position;
SDL_Color couleur={255,255,255};
int z=0;

TTF_Init();
police = TTF_OpenFont("angelina.ttf",24);
while (continuer)
{
 

SDL_WaitEvent(&event);
switch(event.type)
{ case SDL_KEYDOWN:
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
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;


case SDLK_KP1:
l='1';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;


case SDLK_KP2:
l='2';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_KP3:
l='3';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;


case SDLK_KP4:
l='4';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
,int i
break;

case SDLK_KP5:
l='5';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_KP6:
l='6';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_KP7:
l='7';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_KP8:
l='8';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_KP9:
l='9';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_a:
l='a';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_b:
l='b';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_c:
l='c';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_d:
l='d';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);
break;

case SDLK_e:
l='e';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_f:
l='f';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_g:
l='g';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_h:
l='h';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_i:
l='i';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_j:
l='j';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_k:
l='k';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_l:
l='l';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_m:
l='m';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_n:
l='n';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_o:
l='o';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_p:
l='p';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_q:
l='q';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_r:
l='r';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_s:
l='s';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_t:
l='t';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_u:
l='u';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_v:
l='v';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_w:
l='w';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_x:
l='x';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_y:
l='y';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;

case SDLK_z:
l='z';
mot[z]=l;
z++;
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;
SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;
case SDLK_BACKSPACE:
z--;
mot[z]='\0';
texte = TTF_RenderText_Blended(police,mot,couleur);
position.x = 0;
position.y = 0;

SDL_BlitSurface(fond, NULL, ecran, &position);

position.x = 328;
position.y = 452;
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_Flip(ecran);

break;
}
}
}
int r;
r=strcmp(mot,tableau[j].solution);
TTF_CloseFont(police);
TTF_Quit();
SDL_FreeSurface(texte);
return r;
}


