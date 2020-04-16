#include "pers.h"



void intialiser_score(score *s)
{

	SDL_Color couleurNoire = {0, 0, 0};
  	SDL_Color  couleurBlanche = {255, 255, 255};

	char  temps[20] = "";
   
	s->police = NULL; 
	s->compteur =0; 
        s->position.x = 0;
        s->position.y = 0;
	s->tempsActuel = 0;
	s->tempsPrecedent = 0;
	s->police = TTF_OpenFont("Maximum Impact.ttf", 60);
        s->texte = TTF_RenderText_Shaded(s->police, temps, couleurNoire,couleurBlanche); /* On écrit la chaine temps dans la SDL_Surface */

}


void afficher_score(score s,SDL_Surface *ecran)
{
	SDL_BlitSurface(s.texte, NULL, ecran, &s.position);
}




void init_tempst(temps *t)
{
	SDL_Color couleurNoire = {0, 0, 0};
  	SDL_Color  couleurBlanche = {255, 255, 255};
	char  temps[20] = "";
   	t->police = NULL;
      	t->tempsActuel = 0;
 	t->tempsPrecedent = 0;
 	t->compteur =0;
  	t->police = TTF_OpenFont("Maximum Impact.ttf", 60); 
        t->position.x = 900;
        t->position.y = 0;
        t->texte = TTF_RenderText_Shaded(t->police, temps, couleurNoire,couleurBlanche); // On écrit la chaine temps dans la SDL_Surface 

}





void affich_temps(temps t,SDL_Surface *ecran)
{
	SDL_BlitSurface(t.texte, NULL, ecran, &t.position);

}







void initialiser_vie(vie *v,pers *p)
{
   v->image=IMG_Load("coeur.png");
   v->nbr=4;
   v->position.x=p->position_joueur.x;
   v->position.y=p->position_joueur.y;
}









void  afficher_vie(pers p,vie v,SDL_Surface *ecran)
{
  int i;
  SDL_Rect position;
  
  for(i=0;i<v.nbr;i++)
  {
    position.x=p.position_joueur.x+(v.image->w*i)-10;
    position.y=p.position_joueur.y-30;
    SDL_BlitSurface(v.image,NULL,ecran,&position);
  }
}





void initialiserperso(pers *p)
{

    p->gauche[1] = IMG_Load("1g.png");
    p->gauche[2] = IMG_Load("2g.png");
    p->gauche[3] = IMG_Load("3g.png");
    p->gauche[4] = IMG_Load("4g.png");
    p->gauche[5] = IMG_Load("5g.png");
    p->gauche[6] = IMG_Load("6g.png");
    p->gauche[7] = IMG_Load("7g.png");
    p->gauche[8] = IMG_Load("8g.png");

    p->droite[1] = IMG_Load("1d.png");
    p->droite[2] = IMG_Load("2d.png");
    p->droite[3] = IMG_Load("3d.png");
    p->droite[4] = IMG_Load("4d.png");
    p->droite[5] = IMG_Load("5d.png");
    p->droite[6] = IMG_Load("6d.png");
    p->droite[7] = IMG_Load("7d.png");
    p->droite[8] = IMG_Load("8d.png");

    p->depart=IMG_Load("1d.png");
    p->bas= IMG_Load("1d.png");
    p->haut= IMG_Load("1d.png");

    p->left=0;
    p->right=0;
    p->score=0;

    p->position_joueur.x=65;
    p->position_joueur.y=350;
}






void afficherperso(pers *p,int d,SDL_Surface *ecran)
{
if(d==6)
{
	SDL_BlitSurface(p->droite[p->right],NULL, ecran,&p->position_joueur);
        p->left=0;
}

else if (d==4)
{
	SDL_BlitSurface(p->gauche[p->left],NULL, ecran,&p->position_joueur);
	p->right=0;
}
else if (d==8)
{
	SDL_BlitSurface(p->haut,NULL, ecran,&p->position_joueur);
        p->right=0;
        p->left=0;
}
else if (d==2)
{	
	SDL_BlitSurface(p->bas,NULL, ecran,&p->position_joueur);
	p->right=0;
        p->left=0;
}








pers boujer(int d, pers p)
{
if(d==6)
	{p.right++;
  	p.position_joueur.x+=10;}

else if(d==4)
	{p.left++;
	p.position_joueur.x-=10;}

else if(d==8)
	{p.position_joueur.y-=10;}

else if(d==2)
	{p.position_joueur.y+=10;}

if(p.right==8)
    {p.right=1;}

if (p.left==8)
    {p.left=1;}



return p;
