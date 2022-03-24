#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "ChampForces.h"


using namespace std;

void ChampForces::agit_sur(ObjetMobile& obj) const
{
    ChampForces g(0,0,-9.81);

    double rho(1.2);

    Vecteur df((obj.get_masse()-4*M_PI*rho*obj.get_rayon()*obj.get_rayon()*obj.get_rayon()/3)*g.intensite);

    obj.ajoute_force(df);

}
