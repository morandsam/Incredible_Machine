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

    ChampForces g_(0,0,g);

    // Paramètres test exo P10
    Vecteur param__(0,1.36675,0.283821);
    Vecteur dev_param__(0,0.715449,0.0957368);

    Vecteur _param_(0,0.624,0.0465234);
    Vecteur _dev_param_(0,0.8,-2.59108);

    Vecteur param(0,0,0.3);
    Vecteur dev_param(0,0.8,2);

    Vecteur param_(0,1.46284,0.260128);
    Vecteur dev_param_(0,0.419218,0.13874);

    
    Balle balle(param,dev_param,Vecteur(0,0,0),Vecteur(0,0,0),0.00167784948285945,0.051111);
    //Balle balle2(param_,dev_param_,Vecteur(0,0,0),Vecteur(0,0,0),0.1,0.05);

    
    Pendule pendule(Vecteur(1.5),Vecteur(-0.5),Vecteur(0,0,0),Vecteur(0,1.4,0.45),0.1,0.05,0.2,0.005);
    //Pendule pend(Vecteur(0.319603599172218),Vecteur(0.441579572811062),Vecteur(0,0,0),Vecteur(0,1.148649741794006,1.209488037945800),0.1,0.05,1,0);
    
    Plan p(Vecteur(0,0,0),Vecteur(0,0,1));

    
    g_.ajoute_a(syst);
    balle.ajoute_a(syst);
    //balle2.ajoute_a(syst);
    pendule.ajoute_a(syst);
    //pend.ajoute_a(syst);
    p.ajoute_a(syst);
    
    Integrateur_EC int1(0.01);
    
    cout<<syst;

    for (size_t i(0);i<400;++i){
        syst.dessine_sur(ecran);
        syst.evolue(int1);
    }

    return 0;
}