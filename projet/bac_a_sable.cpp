#include <iostream>
#include "Balle.h"
#include "Pendule.h"
#include "PenduleSpherique.h"
#include "Ressort.h"
#include "Vecteur.h"
#include "Integrateur_E.h"
#include "Integrateur_EC.h"
#include "Integrateur_Newmark.h"
#include "Integrateur_RK4.h"
#include "ChampForces.h"
#include "TextViewer.h"
#include "Systeme.h"
#include "Plan.h"
#include "Portion_plan.h"
#include "Brique.h"
#include "Ventilateur.h"



using namespace std;

int main() {

    Systeme syst(false,true);

    TextViewer ecran;

    ChampForces g_(0,0,g);

    Vecteur param(0,0,0.3);
    Vecteur dev_param(0,0.8,2);

    Balle balle(param,dev_param,0.00167784948285945,0.051111);

    Pendule pendule(Vecteur(1.5),Vecteur(-0.5),Vecteur(0,1.4,0.45),0.1,0.05,0.2,0.005);

    Plan p(Vecteur(0,0,0),Vecteur(0,0,1));
    
    g_.ajoute_a(syst);
    balle.ajoute_a(syst);
    pendule.ajoute_a(syst);
    p.ajoute_a(syst);

    Integrateur_EC int1(0.01);
    Integrateur_RK4 int2(0.01);
    
    cout<<syst;

    for (size_t i(0);i<300;++i){
        syst.dessine_sur(ecran);
        syst.evolue(int2);
    }

    return 0;
}