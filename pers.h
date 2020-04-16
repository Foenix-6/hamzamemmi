#ifndef PERS_H_INCLUDED
#define PERS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <time.h>





struct personnage
{
    SDL_Surface *bas;
    SDL_Surface *haut;
    SDL_Surface *gauche[8];
    SDL_Surface *droite[8];
    SDL_Surface *depart;
    int left,right;

    SDL_Rect position_joueur;
	int score;
	
};typedef struct personnage pers;


struct vie
{
  int nbr;
  SDL_Rect position;
  SDL_Surface *image;
};
typedef struct vie vie;


struct temps
{
TTF_Font *police;
int tempsActuel;
int tempsPrecedent;
int compteur ;
SDL_Surface *texte;
SDL_Rect position;
};

typedef struct temps temps ;



struct score
{
TTF_Font *police;
int tempsActuel;
int tempsPrecedent;
int compteur ;
SDL_Surface *texte;
SDL_Rect position;
};

typedef struct score score ;




void init_temps(temps *t);
void affich_temps(temps t,SDL_Surface *ecran);
void intialiser_score(score *s);
void afficher_score(score s,SDL_Surface *ecran);
void initialiser_vie(vie *v,pers *p);
void afficher_vie(pers p,vie v,SDL_Surface *ecran);
pers boujer(int d, pers p);
void initialiserperso(pers *p);
void afficherperso(pers *p,int d,SDL_Surface *ecran);
void liberer_surface(pers *p);



#endif
