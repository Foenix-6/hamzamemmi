#ifndef stat_H_INCLUDED
#define stat_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "string.h"
#include "perso.h"
/**
* @struct the vie_perso 
* @brief struct for the vie_perso
*/
typedef struct
{
  //creation police/font du texte
  TTF_Font *police_vie;
  //creation couleur du texte

  //creation texte vie
  SDL_Surface *texte_vie;
  SDL_Rect pos_texte_vie;

} vie_perso;
/**
* @struct the score_perso
* @brief struct for the score_perso
*/

typedef struct
{
  //creation police/font du texte
  TTF_Font *police_score;
  //creation couleur du texte

  //creation texte score
  SDL_Surface *texte_score;
  SDL_Rect pos_texte_score;

} score_perso;

void init_vie(vie_perso* v);
void init_score(score_perso *s);

void afficher_score(personnage *p, SDL_Surface *screen, score_perso *s);
void afficher_vie(personnage *p, SDL_Surface *screen, vie_perso *v);
void afficher_vie_score(personnage *p, SDL_Surface *screen, score_perso *s, vie_perso *v);







#endif
