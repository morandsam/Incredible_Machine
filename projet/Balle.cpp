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

double Balle::distance(const ObjetMobile& Obj2)
    {
        Vecteur vecteur_c1_c2 = get_param().soustraction(Obj2.get_param());
        double distance; 
        distance= vecteur_c1_c2.norme()-get_rayon()-Obj2.get_rayon();
        return distance;
    };