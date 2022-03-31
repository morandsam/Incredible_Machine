#include<iostream>
#include"Balle.h"
#include"Brique.h"
#include"Plan.h"
#include"ChampForces.h"
#include"Vecteur.h"

using namespace std;

int main(){
ChampForces g(0,0,-9.81);
Balle balle(Vecteur(0.2,-0.4,1.3),Vecteur(0,0,0),Vecteur(0,0,0),Vecteur(0,0,0),0.100530964914873,0.2);

g.agit_sur(balle);

Brique brique(Vecteur(0,0,0.5),0.5,Vecteur(0,-0.6,0),Vecteur(0.8,0,0));

Plan plan(Vecteur(0,0,0),Vecteur(0,0,1));

cout<<balle<<endl;
cout<<plan<<endl;
cout<<brique<<endl;


cout<<plan.calcul_point_plus_proche(balle)<<endl;
cout<<plan.distance(balle)<<endl;
cout<<brique.calcul_point_plus_proche(balle)<<endl;
cout<<brique.distance(balle);

return 0;    
}