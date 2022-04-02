#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include"Pendule.h"

using namespace std;



Vecteur Pendule::evolution() const
{
    // Formule directement tirée de l'appendice mathématique du projet
    Vecteur p_ (get_param());
    Vecteur p_point (get_dev_temp_param());
    Vecteur f((cos(p_.get_coord(0))*(get_force()*get_direction())-sin(p_.get_coord(0))*(get_force().get_coord(2))-get_frottement()*p_point.get_coord(0)/get_longueur())/(get_masse()*get_longueur()));
    return f;
}

void Pendule::calcul_posi_masse()
{
    // Formule directement tirée de l'appendice mathématique du projet
    Vecteur p(position_origine);
    Vecteur temp1(0,0,longueur*cos(param.get_coord(0)));
    Vecteur temp2(longueur*sin(param.get_coord(0))*direction);

    position_masse= (p+temp1+temp2);
}
    
    
void Pendule::calcul_vitesse_masse()
{
    // Formule directement tirée de l'appendice mathématique du projet
    Vecteur temp1(cos(param.get_coord(0))*direction);
    Vecteur temp2(0,0,sin(param.get_coord(0)));
    vitesse_masse= longueur*(dev_temp_param.get_coord(0))*(temp1-temp2);
}



ostream& Pendule::affiche(ostream& sortie) const
{
    sortie<<masse<<" # masse pendule"<<endl
    <<longueur<<" # longueur pendule"<<endl
    <<frottement<<" # frottement pendule"<<endl;
    sortie<<position_origine<<" # origine pendule"<<endl;
    sortie<<direction<<" # direction pendule"<<endl;
    sortie<<param<<" # theta pendule"<<endl;
    sortie<<dev_temp_param<<" # theta point pendule"<<endl;
    sortie<<position_masse<<" # position bout pendule"<<endl<<endl;

    return sortie;
}


void Pendule::affiche_gnuplot(double dt) const
{
    cout<<dt<<" ";
    cout<<param<<endl;
}


ostream& operator<<(ostream& sortie, Pendule const& pendule)
{
    return pendule.affiche(sortie);
}