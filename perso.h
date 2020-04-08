#define FONCTION_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>




typedef struct
{	
 SDL_Surface *perso;
 SDL_Rect posperso;
 SDL_Rect anime_perso[16];
 int frameNumber, frameTimer;
 int vie,score;

}perso;

void initialiserperso(perso *p);
void initialiservie(vie *v);
void initialiserscore(score *s);
void initialisertemps(temps *t);
void modificationvie(vie *v, int c);
void modificationscore(score *s);
void modificationtemps(temps *t);
void affichervie(vie v);
void afficherscore(score s);
void affichertemps(temps t);
void afficherperso(perso p);
void deplacerperso(posperso *pp);
void animerperso(perso *p);

#endif
