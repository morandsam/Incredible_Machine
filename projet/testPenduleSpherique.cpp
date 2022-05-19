#include <iostream>
#include "Vecteur.h"
#include "PenduleSpherique.h"
#include "Integrateur.h"
#include "Integrateur_EC.h"
#include "Integrateur_E.h"
#include "Integrateur_Newmark.h"
#include "Integrateur_RK4.h"
#include "ChampForces.h"
#include "Balle.h"
#include "constantes.h"
using namespace std;

// Test de fonctionnement sur la classe Pendule

int main(){

    Vecteur position(0.4,0.4);
    Vecteur vitesse(1,1);
    Vecteur force(0,0,0);
    Vecteur origine(0,0,0);
    double longueur(1);
    double rayon(0);
    double masse(0.1);
    double frottement(0.005);

    ChampForces g_(0,0,g);

    PenduleSpherique p(position,vitesse,force,origine,masse,rayon,longueur,frottement);

    g_.agit_sur(p);

    Integrateur_EC int1(0.01);
    for(size_t i(1);i<400;++i){
        int1.integre(p);
        p.affiche(cout,false);
    }


    return 0;
}