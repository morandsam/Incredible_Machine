#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "Vecteur.h"
#include "Balle.h"
#include "ChampForces.h"


using namespace std;

void ChampForces::agit_sur(Balle& balle) const
{
    ChampForces g(0,0,-9.81);

    double rho(1.2);

    Vecteur df((balle.get_masse()-4*M_PI*rho*balle.get_rayon()*balle.get_rayon()*balle.get_rayon()/3)*g.intensite);

    balle.ajoute_force(df);

}
