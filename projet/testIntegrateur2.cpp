#include <iostream>
#include "Balle.h"
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "Integrateur.h"
#include "Integrateur_E.h"
#include "Integrateur_EC.h"
#include "Integrateur_Newmark.h"
#include "Integrateur_RK4.h"
#include "ChampForces.h"
#include "constantes.h"

using namespace std;

int main()
{
    ChampForces g_(0,0,g);

    Vecteur param(0,0,0);
    Vecteur dev_param(0,0.1,0.2);

    Balle balle(param,dev_param,0.100530964914873,0.2);

    g_.agit_sur(balle);

    Integrateur_EC int2(0.01);

    cout<<g_;
    cout<<balle;
    
    for(size_t i(1);i<6;++i){
        int2.integre(balle);
        cout<<balle;
    }

    return 0;
}