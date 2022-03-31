#include"Integrateur.h"
#include"Integrateur_E.h"
#include<cmath>
#include<iostream>

using namespace std;


void Integrateur_E::integre_pendule(Pendule& p) const
{
    p.set_param(p.get_param()+ dt*p.get_dev_temp_param());
    p.set_dev_temp_param(p.get_dev_temp_param()+dt*p.evolution());
    p.calcul_posi_masse();
    p.calcul_vitesse_masse();
}

void Integrateur_E::integre_balle(Balle& balle) const
{   
    balle.set_param(balle.get_param()+ dt*balle.get_dev_temp_param());
    balle.set_dev_temp_param(balle.get_dev_temp_param()+dt*balle.evolution());
}

void Integrateur_E::integre_balle_simple(Balle& balle) const
{   
    
    Vecteur f(0,-9.81);

    balle.set_param(balle.get_param()+ dt*balle.get_dev_temp_param());
    balle.set_dev_temp_param(balle.get_dev_temp_param()+dt*f);
    
}