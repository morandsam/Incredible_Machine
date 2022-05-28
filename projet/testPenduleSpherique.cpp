#include <iostream>
#define _USE_MATH_DEFINES
#include "Vecteur.h"
#include "PenduleSpherique.h"
#include "Integrateur.h"
#include "Integrateur_EC.h"
#include "Integrateur_E.h"
#include "Integrateur_Newmark.h"
#include "Integrateur_RK4.h"
#include "ChampForces.h"
#include "Balle.h"
#include <cmath>
#include "constantes.h"
using namespace std;

// Test de fonctionnement sur la classe PenduleSpherique

int main(){

    Vecteur position(M_PI_2,0);
    Vecteur vitesse(0,0.5);
    Vecteur origine(0,0,2);
    double longueur(2);
    double rayon(0);
    double masse(0.1);
    double frottement(0.005);

    ChampForces g_(0,0,g);

    PenduleSpherique p(position,vitesse,origine,masse,rayon,longueur,frottement);

    g_.agit_sur(p);

    Integrateur_RK4 int1(0.01);

    for(size_t i(1);i<20000;++i){
        int1.integre(p);
        p.affiche(cout,false);
    }

    return 0;
}
