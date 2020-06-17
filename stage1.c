/**
 * @file stage1.c 
 */
#include "stage1.h"

int stage_1(SDL_Surface *screen){
  int passed=1;//return 1 -> win | 0 -> lose

    TTF_Init();

    //determiner fps
    Uint32 t_dep,t_fin,dt=1;
    int fps=30;

//declaration background
background bg;
initialiser_back(&bg);

//declaration personnage
personnage p;
initialiser_perso(&p);

//declaration vie et score
vie_perso val_vie;
init_vie(&val_vie);
score_perso val_score;
init_score(&val_score);

SDL_EnableKeyRepeat(200,0);

  int running=1;
SDL_Event event;


  while (running){
t_dep=SDL_GetTicks();

p.stable=1;
if(SDL_PollEvent(&event)){

switch (event.type) {

  case SDL_QUIT:
running=0;
  break;


  case SDL_KEYDOWN:
  switch (event.key.keysym.sym) {

//right button
    case SDLK_RIGHT:
avancer_perso(&p,dt);
    break;

    case SDLK_UP:

jump_perso(&p);
    break;
//left button
    case SDLK_LEFT:
reculer_perso(&p,dt);
    break;

    //acceleration button
        case SDLK_a:
p.acceleration++;
        break;
  }
  break;

  case SDL_KEYUP:
  switch (event.key.keysym.sym) {

//right button
    case SDLK_RIGHT:
p.vitesse_perso=3;
    break;
//left button
    case SDLK_LEFT:
p.vitesse_perso=3;
    break;
  }
  break;

}//fin switch

}//fin pollevent


//animation perso
if(p.stable)
animation_perso_stable(&p);

printf("%d\t%f\n",p.acceleration,p.vitesse_perso );


gravity(&p,bg);


//affichage
afficher_back(&bg,screen);

afficher_perso(&p,screen);
afficher_vie_score(&p,screen,&val_score,&val_vie);


SDL_Flip(screen);

//determiner fps
t_fin=SDL_GetTicks();
dt=t_fin-t_dep;
if (1000/fps>dt) SDL_Delay (1000/fps-dt);

  }//fin while
    TTF_Quit();

  return passed;
}
