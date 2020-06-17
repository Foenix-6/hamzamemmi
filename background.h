#ifndef background_H_INCLUDED
#define background_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "perso.h"
/**
* @struct the background
* @brief struct for the background
*/
typedef struct{
  SDL_Surface *image_back;/*!< Surface. */
  SDL_Rect pos_back;/*!< Rectangle*/
  int gravity;
}background;

void initialiser_back(background *bg);
void afficher_back(background *bg, SDL_Surface *screen);
void gravity(personnage *p, background bg);

#endif
