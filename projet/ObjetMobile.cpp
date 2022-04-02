#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "ObjetMobile.h"
#include <ostream>

using namespace std;



void ObjetMobile::calcul_masse()
{
    // le volume correspond à celui d'une sphère
    masse = masse_volumique*4*M_PI*rayon*rayon*rayon/3;
}

void ObjetMobile::calcul_masse_volumique()
{
    // le volume correspond à celui d'une sphère
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

void ObjetMobile::agit_sur(ObjetMobile&) const
{   
    // Encore à définir
    cout<<" ";
}
    
double ObjetMobile::distance(ObjetMobile const& obj2) const
{
    Vecteur c1_c2 = get_position_masse() - obj2.get_position_masse();
    double distance(0); 
    distance = c1_c2.norme()-get_rayon()-obj2.get_rayon();
    return distance;
}


ostream& ObjetMobile::affiche(ostream& sortie) const
{
    sortie<<"Masse : "<<masse<<endl<<"Masse volumique : "<<masse_volumique<<endl
    <<"Rayon : "<<rayon<<endl<<"Position : ";
    sortie<<param<<endl<<"Vitesse : ";
    sortie<<dev_temp_param<<endl<<"Forces : ";
    sortie<<force<<endl<<endl;

    return sortie;
}

ostream& operator<<(ostream& sortie, ObjetMobile const& objetmobile)
{
    return objetmobile.affiche(sortie);
}

