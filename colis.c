#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include "colis.h"



SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y)
{
    SDL_Color color;
    Uint32 col = 0;
    //Determine position
    char *pPosition = (char *)pSurface->pixels;
    pPosition += (pSurface->pitch * y); 
    pPosition += (pSurface->format->BytesPerPixel * x);
    memcpy(&col, pPosition, pSurface->format->BytesPerPixel);
    //convertir color
    SDL_GetRGB(col, pSurface->format, &color.r, &color.g, &color.b);
    return (color);
}

int collision_parfaite_r(SDL_Surface *mask, SDL_Surface *hero, SDL_Rect poshero,SDL_Color co)
{
    SDL_Color col;
    SDL_Rect pos[8];
    int collision = 0;
    int i,w,h;
    col.r = 0;
    col.g = 0; 
    col.b = 0;
   

    w = 94.4; 
    h = 235;

   
    
    pos[3].x = poshero.x + w / 2; 
 
    pos[3].y = poshero.y; /*top_milieu*/
    pos[4].x = poshero.x + w / 2;
    pos[4].y = poshero.y +h; /*bottom_milieu*/
    pos[5].x = poshero.x + w;
    pos[5].y = poshero.y; /*droite_sup*/
    pos[6].x = poshero.x + w;
    pos[6].y = poshero.y + h / 2; /*droite*/
    pos[7].x = poshero.x + w;
    pos[7].y = poshero.y + h; /*droite_inf*/

    for (i = 3; (i < 8) && (collision == 0); i++)
    {
        col = GetPixel(mask, pos[i].x, pos[i].y);
        
        if ((col.r ==co.r) && (col.g == co.g) && (col.b == co.b))
            collision = 1;
        
    }
    return (collision);
}

int collision_parfaite_l(SDL_Surface *mask, SDL_Surface *hero, SDL_Rect poshero,SDL_Color co)
{
    SDL_Color col;
    SDL_Rect pos[8];
    int collision = 0;
    int i,w,h;
    col.r = 0;
    col.g = 0; 
    col.b = 0;
   

    w = 94.4; 
    h = 235;

   
    pos[0].x = poshero.x;
    pos[0].y = poshero.y; /*gauche_sup*/
    pos[1].x = poshero.x;
    pos[1].y = poshero.y + h / 2; /*gauche*/
    pos[2].x = poshero.x;
    pos[2].y = poshero.y + h; /*gauche_inf*/
    pos[3].x = poshero.x + w / 2; 
    pos[3].y = poshero.y; /*top_milieu*/
    
    pos[4].x = poshero.x + w / 2;
    pos[4].y = poshero.y +h; /*bottom_milieu*/
    

    for (i = 0; (i < 5) && (collision == 0); i++)
    {
        col = GetPixel(mask, pos[i].x, pos[i].y);
        
        if ((col.r ==co.r) && (col.g == co.g) && (col.b == co.b))
            collision = 1;
        
    }
    return (collision);
}
int checkbas(SDL_Surface *mask, SDL_Surface *hero, SDL_Rect poshero,SDL_Color co)
{
    SDL_Color col;
    SDL_Rect pos[8];
    int collision = 0;
    int i,w,h;
    col.r = 0;
    col.g = 0; 
    col.b = 0;
   

    w = 94.4; 
    h = 235;

   
    pos[0].x = poshero.x + w;
    pos[0].y = poshero.y + h; /*droite_inf*/
    
    
    pos[1].x = poshero.x;
    pos[1].y = poshero.y + h; /*gauche_inf*/
    
   
    
    pos[2].x = poshero.x + w / 2;
    pos[2].y = poshero.y +h; /*bottom_milieu*/
    
    for (i = 0; (i < 3) && (collision == 0); i++)
    {
        col = GetPixel(mask, pos[i].x, pos[i].y);
        
        if ((col.r ==co.r) && (col.g == co.g) && (col.b == co.b))
            collision = 1;
        
    }
    return (collision);
}
int checkhaut(SDL_Surface *mask, SDL_Surface *hero, SDL_Rect poshero,SDL_Color co)
{
    SDL_Color col;
    SDL_Rect pos[8];
    int collision = 0;
    int i,w,h;
    col.r = 0;
    col.g = 0; 
    col.b = 0;
   

    w = 94.4; 
    h = 235;

   
    pos[0].x = poshero.x;
    pos[0].y = poshero.y; /*sup_inf*/
    
    
    pos[1].x = poshero.x+w/2;
    pos[1].y = poshero.y; /*milieu sup*/
    
   
    
    pos[2].x = poshero.x + w ;
    pos[2].y = poshero.y; /*droite sup*/
    
    for (i = 0; (i < 3) && (collision == 0); i++)
    {
        col = GetPixel(mask, pos[i].x, pos[i].y);
        
        if ((col.r ==co.r) && (col.g == co.g) && (col.b == co.b))
            collision = 1;
        
    }
    return (collision);
}
