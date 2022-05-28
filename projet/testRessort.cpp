#include <iostream>
#include "Vecteur.h"
#include"Ressort.h"
#include "Integrateur.h"
#include "Integrateur_EC.h"
#include "Integrateur_Newmark.h"
#include "Integrateur_RK4.h"
#include "ChampForces.h"
#include "constantes.h"
using namespace std;

// Test de fonctionnement sur la classe Ressort

int main(){


    Vecteur position(0.4);
    Vecteur vitesse(0.0);
    Vecteur origine(0,0,1);
    double longueur(1);
    double rayon(0);
    double masse(0.1);
    double frottement(0.01);
    double k_(1.38165);
    Vecteur direction_(0,0.707106781186547,-0.707106781186547);

    ChampForces g_(0,0,g);

    Ressort r (position,vitesse,origine,direction_,masse,rayon,longueur,frottement,k_);

    g_.agit_sur(r);

    Integrateur_EC int1(0.01);

    for(size_t i(1);i<6;++i){
        int1.integre(r);
        r.affiche(cout,true);
    }


    return 0;
}