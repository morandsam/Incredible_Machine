#include"Integrateur.h"
#include"Vecteur.h"
#include<cmath>
#include<iostream>


using namespace std;

double Integrateur::integre_pendule(Pendule const& p, double dt) const
{
    Vecteur p_ (p.get_param());
    Vecteur p_point (p.get_dev_temp_param());
    double f((cos(p_.get_coord(0))*(p.get_force()*p.get_direction())+sin(p_.get_coord(0))*((p.get_force().get_coord(2))-p.get_frottement()*p_point.get_coord(0)/p.get_longueur()))/(p.get_masse()*p.get_longueur()));  
    cout<<f<<endl;
    return f;
}

