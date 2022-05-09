#include <iostream>
#include "Balle.h"
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "Integrateur.h"
#include "Integrateur_EC.h"
#include "Integrateur_Newmark.h"
#include "Integrateur_E.h"
#include "Integrateur_Newmark.h"
#include "Integrateur_RK4.h"

using namespace std;

// Test de fonctionnement sur les classes Balle, Intégrateur et Intégrtauer d'Euler-Cromer

int main()
{
    Vecteur param(0,1);
    Vecteur dev_param(1,2);

    Balle balle(param,dev_param,Vecteur(0,0),Vecteur(0,0),0.127,0);

    Integrateur_EC int1(0.01);
    Integrateur_RK4 int2(0.01);
    Integrateur_Newmark int3(0.01,0.00005);

    for(size_t i(0);i<80;++i){
        int1.integre_balle_simple(balle);
        balle.affiche(cout,false);
    }

    return 0;
}