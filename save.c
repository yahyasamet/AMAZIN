#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "save.h"

/*-----Fonction de sauvegarde de la partie-----*/

void save (int valeur_score,int vies,int level)
 { 
    FILE* saveF = NULL;
    saveF = fopen("sauvegarde.txt","w+"); // Ouverture en écriture du fichier sauvegarde.txt

        if(saveF != NULL)
{   // Ecriture dans le fichier des positions du joueur et score


 fprintf(saveF,"%d %d %d\n",level,valeur_score,vies); //etat=0 perdu etat=1 gagne
              
		

        }

    fclose(saveF); // Fermeture du fichier
}


/*------ Fonction de chargement de la partie--------*/


void load (int valeur_score,int vies,int level )
{ 

    FILE* saveF = NULL;
    saveF = fopen("sauvegarde.txt","r"); // Ouverture du fichier sauvegarde en lecture

    if(saveF != NULL) 
	{ 
	
	    fscanf(saveF,"%d %d %d",&level,&valeur_score,&vies);
	    
}

    fclose(saveF); // Fermeture du fichier
}
