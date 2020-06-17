/**
 * @file main.c 
 */
#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "stage1.h"

int main()
{

SDL_Init(SDL_INIT_VIDEO);

//creation fenetre principale
SDL_Surface *screen=NULL;
screen=SDL_SetVideoMode(900,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

int success=0;

success=stage_1(screen); //si retour 0 => stage 1 failed || si retour 1 => stage 1 passsed
if(success) printf("vous avez gagné\n");
else printf("vous avez perdu\n");

/*
if (sucess==1){// if (success)
success=0;
success=enigme(screen);
}
*/

SDL_Quit();


}
