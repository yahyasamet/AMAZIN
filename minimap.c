#include "minimap.h"
#include <SDL/SDL.h>
void init_map(minimap* m)
{
	m->map=IMG_Load("minimap.png");
	m->minihero=IMG_Load("persomini.png");
	m->positionmap.x=475;
	m->positionmap.y=50;
	m->positionminihero.x=475;
	m->positionminihero.y=75;
	
}


void movemini(minimap *m, int sens)
{

	if(sens==0)
        	m->positionminihero.x+=1;   
	if(sens==1)
        	m->positionminihero.x-=1; 


}
