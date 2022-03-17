#include <iostream>
#include "Balle.h"
#define _USE_MATH_DEFINES
#include <cmath>

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

void Balle::affiche() const
{
    cout<<"Masse : "<<masse<<endl<<"Masse volumique : "<<masse_volumique<<endl
    <<"Rayon : "<<rayon<<endl<<"Position : ";
    cout<<position<<"Vitesse : ";
    cout<<vitesse<<"Forces : ";
    cout<<force;
}
