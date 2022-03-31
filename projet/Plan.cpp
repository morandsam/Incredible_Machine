#include <iostream>
#include "Plan.h"
using namespace std;

Vecteur Plan::calcul_point_plus_proche(ObjetMobile const& obj2) const
{
    return (obj2.get_param() + ((point_origine-obj2.get_param())*normal)*normal);
}

double Plan::distance(ObjetMobile const& obj2) const
{
    double distance = (calcul_point_plus_proche(obj2)-obj2.get_param()).norme()-obj2.get_rayon();
    return distance;
}


ostream& Plan::affiche(ostream& sortie) const
{
    sortie<<get_point_origine()<<" # origine plan"<<endl;
    sortie<<get_normal()<<" # normale plan"<<endl<<endl;

    return sortie;
}

ostream& operator<<(ostream& sortie, Plan const& plan)
{
    return plan.affiche(sortie);
}