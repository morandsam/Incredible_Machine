#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include"Pendule.h"
#include"Integrateur.h"
#include"ObjetMobile.h"

using namespace std;

void Pendule::evolution()
{
    for (size_t i(0);i<1;++i)
    {
        Integrateur test;
        double dt(0.01);
        *this=test.integr_pendule_euler(*this,dt);
        calcul_posi_masse();
        calcul_vitesse_masse();
    }
    
}

void Pendule::calcul_posi_masse()
{
    Vecteur p(position_reference);
    Vecteur temp1(0,0,longueur*cos(param.get_coord(0)));
    Vecteur temp2(longueur*sin(param.get_coord(0))*direction);

    position_masse= (p+temp1+temp2);


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
    sortie<<"un pendule"<<endl<<masse<<" # masse pendule"<<endl
    <<longueur<<" # longueur pendule"<<endl
    <<frottement<<" # frottement pendule"<<endl;
    sortie<<position_reference<<" # origine pendule"<<endl;
    sortie<<direction<<" # direction pendule"<<endl;
    sortie<<param<<" # theta pendule"<<endl;
    sortie<<dev_temp_param<<" # theta point pendule"<<endl;
    sortie<<position_masse<<" # position bout pendule"<<endl;

    return sortie;

    cout<<endl<<longueur*sin(get_param().get_coord(0))*direction;
}


ostream& operator<<(ostream& sortie, Pendule const& pendule)
{
    return pendule.affiche(sortie);
}