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

ostream& Balle::affiche(ostream& sortie) const
{
    sortie<<"Masse : "<<masse<<endl<<"Masse volumique : "<<masse_volumique<<endl
    <<"Rayon : "<<rayon<<endl<<"Position : ";
    sortie<<param<<endl<<"Vitesse : ";
    sortie<<dev_temp_param<<endl<<"Forces : ";
    sortie<<force<<endl<<endl;

    sortie<<param<<endl;

    return sortie;
}

ostream& operator<<(ostream& sortie, Balle const& balle)
{
    return balle.affiche(sortie);
}


