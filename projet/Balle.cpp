#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "Balle.h"
#include <ostream>

using namespace std;



Vecteur Balle::evolution() const
{
    double temp(1/get_masse());
    Vecteur f(temp*get_force());
    return f;
}

ostream& operator<<(ostream& sortie, Balle const& balle)
{
    return balle.affiche(sortie);
}

