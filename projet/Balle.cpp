#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "Balle.h"
#include <ostream>

using namespace std;




//ostream& Balle::affiche(ostream& sortie) const
//{
//    sortie<<"Masse : "<<masse<<endl<<"Masse volumique : "<<masse_volumique<<endl
//    <<"Rayon : "<<rayon<<endl<<"Position : ";
//    sortie<<param<<"Vitesse : ";
//    sortie<<dev_temp_param<<"Forces : ";
//    sortie<<force<<endl;
//
//    return sortie;
//}


ostream& operator<<(ostream& sortie, Balle const& balle)
{
    return balle.affiche(sortie);
}