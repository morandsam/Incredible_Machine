#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "Balle.h"
#include <ostream>

using namespace std;


void Balle::ajoute_force(Vecteur const& df)
{
    force+=df;
    
}

double Balle::get_rayon() const
{
    return rayon;
}
   
double Balle::get_masse() const
{
    return masse;
}

void Balle::calcul_masse()
{
    masse = masse_volumique*4*M_PI*rayon*rayon*rayon/3;
}

void Balle::set_masse_volumique(double massevolumique)
{
    masse_volumique=massevolumique;
    calcul_masse();
}

void Balle::set_position(Vecteur const& position_)
{
    position=position_;
}

void Balle::set_vitesse(Vecteur const& vitesse_)
{
    vitesse=vitesse_;
}

void Balle::set_force(Vecteur const& force_)
{
    force=force_;
}

void Balle::set_rayon(double r)
{
    rayon=r;
}

ostream& Balle::affiche(ostream& sortie) const
{
    sortie<<"Masse : "<<masse<<endl<<"Masse volumique : "<<masse_volumique<<endl
    <<"Rayon : "<<rayon<<endl<<"Position : ";
    sortie<<position<<"Vitesse : ";
    sortie<<vitesse<<"Forces : ";
    sortie<<force<<endl;

    return sortie;
}


ostream& operator<<(ostream& sortie, Balle const& balle)
{
    return balle.affiche(sortie);
}