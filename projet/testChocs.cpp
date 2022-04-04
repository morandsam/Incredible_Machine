#include <iostream>
#include "Balle.h"
#include "Pendule.h"
#include "Ressort.h"
#include "Vecteur.h"
#include "Integrateur_E.h"
#include "Integrateur_EC.h"
#include "ChampForces.h"
#include "TextViewer.h"
#include "Systeme.h"
#include "Plan.h"



using namespace std;

// Test fonctionnement des chocs entre Objets

int main() {
    
    Systeme syst;

    TextViewer ecran;

    ChampForces g(0,0,-9.81);

    Vecteur param(0,0.0624,0.2465234);
    Vecteur dev_param(0,0.8,-2.59108);

    //Vecteur param_(0,1.46284,0.260128);
    //Vecteur dev_param_(0,0.419218,0.13874);

    Balle balle(param,dev_param,Vecteur(0,0,0),Vecteur(0,0,0),0.00167784948285945,0.051111);

    g.agit_sur(balle);

    Plan p(Vecteur(0,0,0),Vecteur(0,0,1));

    //Balle balle2(param_,dev_param_,Vecteur(0,0,0),Vecteur(0,0,0),0.1,0.05);
//
    //g.agit_sur(balle2);

    syst.ajouter_objet_mob(new Balle(balle));
    //syst.ajouter_objet_mob(new Balle(balle2));
    syst.ajouter_objet_stat(new Plan(p));
    


    Integrateur_EC int1(0.01);

    for (size_t i(0);i<200;++i){
        syst.dessine_sur(ecran);
        syst.evolue(int1);
    }


    return 0;
}