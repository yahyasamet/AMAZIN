#ifndef fonction_H_INCLUDED
#define fonction_H_INCLUDED
typedef struct
{
	int nx;
	int ny;
}pos;

void initface (SDL_Surface* tab1[],SDL_Surface* tab2[],pos tab[]);
int faces(SDL_Surface* screen);
void init (SDL_Surface* backround,SDL_Surface* perso,SDL_Surface* tabenemi[]);
int enemidefi(SDL_Surface* screen);
int aleapos();
SDL_Rect positiongrille(int pos);
#endif 
