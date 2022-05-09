#include <iostream>
#include "Balle.h"
#include "Vecteur.h"
#include "Integrateur_E.h"
#include "Integrateur_EC.h"
#include "Integrateur_Newmark.h"
#include "Integrateur_RK4.h"
#include "ChampForces.h"
#include "TextViewer.h"
#include "Systeme.h"
#include "constantes.h"


using namespace std;

// Test fonctionnement classe Systeme et classe TextViewer

int main() {

    Systeme syst;

    TextViewer ecran;

    ChampForces g_(0,0,g);

    Vecteur param(0,0,0);
    Vecteur dev_param(0,0.1,0.2);

    Balle balle(param,dev_param,Vecteur(0,0,0),Vecteur(0,0,0),0.100530964914873,0.2);

    g_.agit_sur(balle);


    syst.ajouter_objet_mob(new Balle(balle));


    Integrateur_EC int1(0.01);

    for (size_t i(0);i<3;++i){
        syst.dessine_sur(ecran);
        syst.evolue(int1);
    }

    return 0;
}