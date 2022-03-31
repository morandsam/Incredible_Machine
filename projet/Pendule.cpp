#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include"Pendule.h"
#include"Integrateur.h"
#include"ObjetMobile.h"
#include"Integrateur_EC.h"

using namespace std;

//void Pendule::evolution()
//{
//    Integrateur_EC int1(0.01);
//    double t(0);
//    for (size_t i(0);i<1000;++i)
//    {
//        int1.integre_pendule(*this);
//        calcul_posi_masse();
//        calcul_vitesse_masse();
//        
//        t+=0.01;
//        affiche_gnuplot(i);
//    }
//}

Vecteur Pendule::evolution() const
{
    Vecteur p_ (get_param());
    Vecteur p_point (get_dev_temp_param());
    Vecteur f((cos(p_.get_coord(0))*(get_force()*get_direction())+sin(p_.get_coord(0))*(get_force().get_coord(2))-get_frottement()*p_point.get_coord(0)/get_longueur())/(get_masse()*get_longueur()));
    return f;
}

void Pendule::calcul_posi_masse()
{
    Vecteur p(position_reference);
    Vecteur temp1(0,0,longueur*cos(param.get_coord(0)));
    Vecteur temp2(longueur*sin(param.get_coord(0))*direction);

    position_masse= (p-temp1+temp2);


    //à compléter

}
    
    
void Pendule::calcul_vitesse_masse()
{
    Vecteur temp1(cos(param.get_coord(0))*direction);
    Vecteur temp2(0,0,sin(param.get_coord(0)));
    vitesse_masse= longueur*(dev_temp_param.get_coord(0))*(temp1-temp2);
}



ostream& Pendule::affiche(ostream& sortie) const
{
    sortie<<masse<<" # masse pendule"<<endl
    <<longueur<<" # longueur pendule"<<endl
    <<frottement<<" # frottement pendule"<<endl;
    sortie<<position_reference<<" # origine pendule"<<endl;
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