#include <iostream>
#include "Balle.h"
#include "Vecteur.h"
#include "Integrateur_EC.h"
#include "Integrateur_E.h"
#include "Integrateur_Newmark.h"
#include "Integrateur_RK4.h"
#include "ChampForces.h"
#include "TextViewer.h"
#include "Systeme.h"
#include "Ventilateur.h"
#include "constantes.h"

using namespace std;

int main() {

    Systeme sys;

    TextViewer affichage;
    Integrateur_EC inte (0.01);

    Balle balle(Vecteur(5,0.5,1.5),Vecteur(0,0,0),Vecteur(0,0,0),Vecteur(0,0,0),2.5,0.25);
    
    //Ventilateur ventilateur(Vecteur(3,1,0),Vecteur(0,-3,0),Vecteur(-3,0,0),1,10,100);

    Ventilateur ventilo(Vecteur(0,0,0),Vecteur(0,0,1),Vecteur(0,1,0),1,10,100);

    Plan p(Vecteur(0,0,-1),Vecteur(0,0,1));
    
    ChampForces g_(0,0,g);


    
    balle.ajoute_a(sys);
    ventilo.ajoute_a(sys);
    p.ajoute_a(sys);
    g_.ajoute_a(sys);

    cout<<sys;

    for(size_t i(0);i<150;++i){
        affichage.dessine(sys);
        sys.evolue(inte);
    }


    return 0;
}