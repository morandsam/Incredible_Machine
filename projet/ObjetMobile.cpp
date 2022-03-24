#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "ObjetMobile.h"
#include <ostream>

using namespace std;


void ObjetMobile::evolution()
{
    

}


void ObjetMobile::calcul_masse()
{
    masse = masse_volumique*4*M_PI*rayon*rayon*rayon/3;
}

void ObjetMobile::calcul_masse_volumique()
{
    masse_volumique = masse/(4*M_PI*rayon*rayon*rayon/3);
}

void ObjetMobile::set_masse_volumique(double massevolumique)
{
    masse_volumique=massevolumique;
    calcul_masse();
}

void ObjetMobile::set_masse(double newmasse)
{
    masse=newmasse;
    calcul_masse_volumique();
}


ostream& ObjetMobile::affiche(ostream& sortie) const
{
    sortie<<"Masse : "<<masse<<endl<<"Masse volumique : "<<masse_volumique<<endl
    <<"Rayon : "<<rayon<<endl<<"Position : ";
    sortie<<param<<"Vitesse : ";
    sortie<<dev_temp_param<<"Forces : ";
    sortie<<force<<endl;

    return sortie;
}

ostream& operator<<(ostream& sortie, ObjetMobile const& objetmobile)
{
    return objetmobile.affiche(sortie);
}