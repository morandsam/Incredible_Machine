#include"Integrateur.h"
#include"Vecteur.h"
#include<cmath>

using namespace std;

Pendule Integrateur::integr_pendule_euler(Pendule p, double dt) const
{
    Vecteur p_ (p.get_param());
    Vecteur p_point (p.get_dev_temp_param());

    p.set_dev_temp_param(p.get_dev_temp_param()+dt*(cos(p_.get_coord(0))*(p.get_force()*p.get_direction()-sin(p_.get_coord(0))*(p.get_force().get_coord(2)-p.get_frottement()*p_point.get_coord(0)/p.get_longueur())))/(p.get_masse()-p.get_longueur()));
    p.set_param(p.get_param()+ dt*p.get_dev_temp_param());

    return p;

}

