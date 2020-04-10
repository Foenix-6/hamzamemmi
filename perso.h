#define FONCTION_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <utilitaire.h>




typedef struct
{	
 SDL_Surface *perso;
 SDL_Rect posperso;
 SDL_Rect anime_perso[16];
 int frameNumber, frameTimer;
 int vie,score;
 texte textevie;
 texte textscore;


}perso;

void initialiserperso(perso *p);
void initialiservie(texte *textevie ,int *vie);
void initialiserscore(texte *textescore,int score);
void initialisertemps(texte *temps);
void miseajourvie(texte *textevie, int *vie);
void miseajourcore(texte *textescore,int *score);
void miseajourtemps(texte *temps);
void affichervie(texte textevie,int vie);
void afficherscore(texte textescore,int score);
void affichertemps(texte temps);
void afficherperso(perso p);
void deplacerperso(posperso *pp);
void animerperso(perso *p);

#endif
