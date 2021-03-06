#include <iostream>
#include "Vecteur.h"
#include "Pendule.h"
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

    Vecteur position(0.4);
    Vecteur vitesse(0.0);
    Vecteur force(0,0,0);
    Vecteur origine(0,2,1);
    double longueur(0.2);
    double rayon(0);
    double masse(0.1);
    double frottement(0.005);

    ChampForces g_(0,0,g);

    Pendule p(position,vitesse,origine,masse,rayon,longueur,frottement);

    g_.agit_sur(p);

    Integrateur_EC int1(0.01);

    cout<<g_;
    cout<<p;

    for(size_t i(1);i<5;++i){
        int1.integre(p);
        cout<<p;
    }


    return 0;
}