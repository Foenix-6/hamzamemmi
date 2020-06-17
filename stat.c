/**
 * @file stat.c 
 */
#include "stat.h"
/**
* @brief To initialize the vie_perso v  .
* @param v the vie_perso
* @return Nothing
*/
void init_vie(vie_perso* v){
    v->police_vie=TTF_OpenFont("src/font.ttf",30);

    v->texte_vie=NULL;

        v->pos_texte_vie.x=150;
        v->pos_texte_vie.y=10;

}
/**
* @brief To initialize the init_score s  .
* @param s the init_score
* @return Nothing
*/
void init_score(score_perso* s){
    s->police_score=TTF_OpenFont("src/font.ttf",30);

    s->texte_score=NULL;

    s->pos_texte_score.x=350;
    s->pos_texte_score.y=10;

}
/**
* @brief To show the score_perso  s.
* @param screen the screen
* @param  s the score_perso
* @param  p the personnage
* @return Nothing
*/

void afficher_score(personnage* p,SDL_Surface* screen,score_perso* s)
{SDL_Color couleur_score={255,255,255};
char char_score[50];
  sprintf(char_score,"score : %04d",p->score);

  s->texte_score=TTF_RenderText_Solid(s->police_score,char_score,couleur_score);
  SDL_BlitSurface(s->texte_score,NULL,screen,&s->pos_texte_score);

}
/**
* @brief To show the vie_perso  v.
* @param screen the screen
* @param  s the score_perso
* @param  p the personnage
* @return Nothing
*/

void afficher_vie(personnage* p,SDL_Surface* screen,vie_perso* v)
{SDL_Color couleur_vie={255,255,255};
  char char_vie[50];
  sprintf(char_vie,"vie x%02d",p->vie);

  v->texte_vie=TTF_RenderText_Solid(v->police_vie,char_vie,couleur_vie);
  SDL_BlitSurface(v->texte_vie,NULL,screen,&v->pos_texte_vie);
}
/**
* @brief To show the vie_perso  v.
* @param screen the screen
* @param  s the score_perso
* @param  v the vie_perso
* @param  p the personnage
* @return Nothing
*/
void afficher_vie_score(personnage *p, SDL_Surface *screen, score_perso *s, vie_perso *v){
afficher_vie(p,screen,v);
afficher_score(p,screen,s);
}




