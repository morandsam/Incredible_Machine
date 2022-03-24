#include <iostream>
#include "Vecteur.h"
#include"Pendule.h"
#include"ObjetMobile.h"
#include "Integrateur.h"
using namespace std;

int main(){




Vecteur position(0.4);
Vecteur vitesse(0.0);
Vecteur force(0,0,-9.81);
Vecteur origine(0,2,1);
double longueur(0.2);
double rayon(0.01);
double massev(200);
double frottement(0.05);




Pendule p(position,vitesse,force,origine,massev,rayon,longueur,frottement);



//p.evolution();




return 0;
}