#include <iostream>
#include "Plan.h"
using namespace std;

Vecteur Plan::calcul_point_plus_proche(ObjetMobile const& obj2) const
{
    // Formule directement tirée de l'appendice mathématique
    return (obj2.get_position_masse() + ((position_origine-obj2.get_position_masse())*normal)*normal);
}

double Plan::distance(ObjetMobile const& obj2) const
{
    // Formule directement tirée de l'appendice mathématique
    double distance = (calcul_point_plus_proche(obj2)-obj2.get_position_masse()).norme()-obj2.get_rayon();
    return distance;
}


ostream& Plan::affiche(ostream& sortie) const
{
    sortie<<"Un plan :"<<endl;
    sortie<<get_position_origine()<<" # origine plan"<<endl;
    sortie<<get_normal()<<" # normale plan"<<endl<<endl;

    return sortie;
}

ostream& operator<<(ostream& sortie, Plan const& plan)
{
    return plan.affiche(sortie);
}