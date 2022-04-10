#include <iostream>
#include "Balle.h"
#include "Vecteur.h"
#include "Integrateur_E.h"
#include "Integrateur_EC.h"
#include "ChampForces.h"
#include "constantes.h"


using namespace std;

// Test de fonctionnement sur les classes Balle, ChampForces, Intégrateur et Intégrateur d'Euler-Cromer

int main()
{
    ChampForces g_(0,0,g);

    Vecteur param(0,0,0);
    Vecteur dev_param(0,0.1,0.2);

    Balle balle(param,dev_param,Vecteur(0,0,0),Vecteur(0,0,0),0.100530964914873,0.2);

    g_.agit_sur(balle);

    Integrateur_EC int2(0.01);

    for(size_t i(1);i<5;++i){
        int2.integre(balle);
        cout<<balle.get_param()<<endl;
        cout<<balle.get_dev_temp_param()<<endl;
    }

    return 0;
}