#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED



int settings(int l,SDL_Surface *screen2,SDL_Surface *main2[],int *done ,int *volume,SDL_Surface *screen,int *p,SDL_Surface *VOL[]);
int newgame(int l,SDL_Surface *screen2,SDL_Surface *newgamescreen);
int credit(int c,SDL_Surface *screen3,SDL_Surface *main);
void splashing(int *o,SDL_Surface *splashscreen,SDL_Surface *splash[]);
void anim(SDL_Surface *screen ,SDL_Surface *main1[]);
void anim2(SDL_Surface *screen2 ,SDL_Surface *main2[]);


#endif // FONCTION_H_INCLUDED

