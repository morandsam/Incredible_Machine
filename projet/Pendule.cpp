#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include"Pendule.h"
#include"Integrateur.h"
#include"ObjetMobile.h"

using namespace std;

void Pendule::evolution()
{
    for (size_t i(0);i<1;++i)
    {
        Integrateur test;
        double dt(0.01);
        *this=test.integr_pendule_euler(*this,dt);

    }
    
}

Vecteur Pendule::calcul_posi_masse()
{
    Vecteur p(position_reference);
    Vecteur temp1(0,0,longueur*cos(param.get_coord(0)));

    //à compléter

}
    
    
Vecteur Pendule::calcul_vitesse_masse()
{

}