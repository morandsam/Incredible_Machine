#include"Integrateur.h"
#include"Integrateur_E.h"
#include<cmath>
#include<iostream>

using namespace std;


void Integrateur_E::integre_pendule(ObjetMobile& p,double f) const
{
    Vecteur p_ (p.get_param());
    Vecteur p_point (p.get_dev_temp_param());

    p.set_param(p.get_param()+ dt*p.get_dev_temp_param());
    p.set_dev_temp_param(p.get_dev_temp_param()+dt*f);
    
}

void Integrateur_E::integre_balle(ObjetMobile& p,Vecteur const& f) const
{   
    Vecteur p_ (p.get_param());
    Vecteur p_point (p.get_dev_temp_param());

    p.set_param(p.get_param()+ dt*p.get_dev_temp_param());
    p.set_dev_temp_param(p.get_dev_temp_param()+dt*f);

    
    
}