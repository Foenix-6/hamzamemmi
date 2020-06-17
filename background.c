/**
 * @file background.c 
 */
#include "background.h"



/**
* @brief To initialize the backdround bg  .
* @param bg the background
* @return Nothing
*/
void initialiser_back(background *bg){
  bg->image_back=IMG_Load("src/back.png");
  bg->pos_back.x=0;
  bg->pos_back.y=0;
  bg->pos_back.w=1000; //largeur back
  bg->pos_back.h=600; // hauteur back

  bg->gravity=3;
}
/**
* @brief To show the backdround bg  .
* @param screen the screen
* @param bg backdround bg 
* @return Nothing
*/
void afficher_back(background *bg, SDL_Surface *screen){
SDL_BlitSurface(bg->image_back,NULL,screen,&bg->pos_back);
}
/**
* @brief for the gravity   .
* @param bg the background
* @param p the personnage  
* @return Nothing
*/

void gravity(personnage *p, background bg){

if(p->pos_perso.y<410){//if not touching the groud
p->pos_perso.y+=bg.gravity;
p->pos_perso_relative.y+=bg.gravity;
p->jump=0;
}
//if touching the ground
else p->jump=1;

}
