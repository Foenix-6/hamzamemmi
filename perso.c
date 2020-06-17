/**
 * @file perso.c 
 */
#include "perso.h"


int nb_image_par_ligne_spritesheet =11,
nb_ligne_spritesheet=4;

void initialiser_animation_perso(SDL_Rect *clip)
{

  //init width and height
for (int j=0; j<nb_image_par_ligne_spritesheet*nb_ligne_spritesheet;j++){
  clip[j].w = 100;
  clip[j].h = 100;
}


    //vers droite : ligne 1
    int i = 0;
    for (i = 0; i < nb_image_par_ligne_spritesheet; i++)
    {

        clip[i].x = clip[i].w * i;
        clip[i].y = 0;
    }

    //vers gauche : ligne 2
    i = 11;
    for (i = 11; i < (2 * nb_image_par_ligne_spritesheet); i++)
    {
        clip[i].x =(i-11)* clip[i].w;
        clip[i].y =  clip[0].y+clip[0].h;
    }
   //vers droite : ligne 3
    i = 22;
    for (i = 22; i < (3 * nb_image_par_ligne_spritesheet); i++)
    {
        clip[i].x =(i-22)* clip[i].w;
        clip[i].y =  300;
    }
   //vers gauche : ligne 4
    i = 33;
    for (i = 33; i < (4 * nb_image_par_ligne_spritesheet); i++)
    {
        clip[i].x =(i-33)* clip[i].w;
        clip[i].y = (clip[0].y+clip[0].h)*2;
    }

}
/**
* @brief To initialize the personnage p  .
* @param p the personnage
* @return Nothing
*/
void initialiser_perso(personnage *p){
  p->pos_perso.x=10;
  p->pos_perso.y=400;
  p->pos_perso.h=100;
  p->pos_perso.w=100;

  p->image_perso=IMG_Load("src/perso.png");
  p->vitesse_perso=3;
    p->vitesse_max_perso=15;

  p->stable=1;
  p->direction=0;
  p->jump=1; //1-> peut sauter | 0-> ne peut pas sauter

  p->comp_tab_animation_perso=30;
  initialiser_animation_perso(p->animation_perso);

  p->vie=3;
  p->score=000;

  p->acc=0;
  p->acceleration=0;

}
/**
* @brief To show the personnage p .
* @param screen the screen
* @param p the personnage
* @return Nothing
*/
void afficher_perso(personnage *p, SDL_Surface *screen){
  SDL_BlitSurface(p->image_perso,&p->animation_perso[p->comp_tab_animation_perso],screen,&p->pos_perso);
}
/**
* @brief for the movement of  the  personnage p (right)   .
* @param dt Unit32 
* @param p the personnage  
* @return Nothing
*/

void avancer_perso(personnage *p,Uint32 dt){
  acceleration(p,dt);
  p->direction=0;
  p->stable=0;
  if (p->pos_perso.x+p->pos_perso.w<800)
p->pos_perso.x+=p->vitesse_perso;
p->pos_perso_relative.x+=p->vitesse_perso;

animation_perso_mvt_droite(p);
}

/**
* @brief for the movement of  the  personnage p (left)   .
* @param dt Unit32 
* @param p the personnage  
* @return Nothing
*/
void reculer_perso(personnage *p,Uint32 dt){
  acceleration(p,dt);
  p->direction=1;
    p->stable=0;
p->pos_perso.x-=p->vitesse_perso;
p->pos_perso_relative.x-=p->vitesse_perso;

animation_perso_mvt_gauche(p);
}
/**
* @brief for the annimation of the personnage when he is (stable )    .
* @param p the personnage  
* @return Nothing
*/
void animation_perso_stable(personnage *p){

  p->comp_tab_animation_perso++;

  //regarder droite
if (!p->direction)
{
  if(p->comp_tab_animation_perso < 42 || p->comp_tab_animation_perso>42)
  p->comp_tab_animation_perso=42;
}

  //regarder gauche
if(p->direction){
  if(p->comp_tab_animation_perso < 25 || p->comp_tab_animation_perso>25)
  p->comp_tab_animation_perso=25;
}



}
/**
* @brief for annimation of the personnage when he moove to the right .   .
* @param p the personnage  
* @return Nothing
*/

void animation_perso_mvt_droite(personnage *p){
    p->comp_tab_animation_perso++;

  if(p->comp_tab_animation_perso < 0 || p->comp_tab_animation_perso>10)
  p->comp_tab_animation_perso=0;
}
/**
* @brief for annimation of the personnage when he moove to the right .   .
* @param p the personnage  
* @return Nothing
*/

void animation_perso_mvt_gauche(personnage *p){
  p->comp_tab_animation_perso++;

if(p->comp_tab_animation_perso < 12 || p->comp_tab_animation_perso>21)
p->comp_tab_animation_perso=11;
}
/**
* @brief for the acceleration of  the personnage .   .
* @param p the personnage  
* @param dt Unit32 
* @return Nothing
*/

void acceleration(personnage *p,Uint32 dt){
  if (p->acceleration%2==0) {
 p->acc=0;
    p->vitesse_perso=3;
   }
 if(p->acceleration%2==1)
 {
   if(p->vitesse_perso<p->vitesse_max_perso)
 {
 p->acc+=0.00003;
   p->vitesse_perso+=0.5*p->acc*dt*dt+p->vitesse_perso*dt/1000;
 }
 }
}
/**
* @brief for the jump of  the personnage .   .
* @param p the personnage  
* @return Nothing
*/
void jump_perso(personnage *p){
 if(p->jump){
  p->pos_perso_relative.y-=150;
  p->pos_perso.y-=150;
}
}




