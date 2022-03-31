#include <iostream>
#include "Vecteur.h"
#include"Pendule.h"
#include "Integrateur.h"
#include "Integrateur_EC.h"
#include "ChampForces.h"
#include "Balle.h"
using namespace std;

int main(){


Vecteur position(0.4);
Vecteur vitesse(0.0);
Vecteur force(0,0,0);
Vecteur origine(0,2,1);
double longueur(0.2);
double rayon(0);
double masse(0.1);
double frottement(0.001);

ChampForces g(0,0,-9.81);

Pendule p(position,vitesse,force,origine,masse,rayon,longueur,frottement);

g.agit_sur(p);

Integrateur_EC int1(0.01);

for(size_t i(1);i<1000;++i){
    int1.integre_pendule(p);
    p.affiche_gnuplot(i);
}


return 0;
}