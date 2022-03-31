#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "Balle.h"
#include <ostream>

using namespace std;


Vecteur Balle::evolution() const
{
    double temp(1/get_masse());
    cout<<temp<<endl;
    Vecteur f(temp*get_force());
    cout<<get_force()<<endl;
    return f;
}

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