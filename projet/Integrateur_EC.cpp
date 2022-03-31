#include"Integrateur.h"
#include"Integrateur_EC.h"
#include"Balle.h"
#include"Pendule.h"

#include<cmath>

using namespace std;


void Integrateur_EC::integre_pendule(Pendule& p) const
{
    p.set_dev_temp_param(p.get_dev_temp_param()+dt*(p.evolution()));
    p.set_param(p.get_param()+ dt*p.get_dev_temp_param());
    p.calcul_posi_masse();
    p.calcul_vitesse_masse();
}

void Integrateur_EC::integre_balle(Balle& balle) const
{   
    balle.set_dev_temp_param(balle.get_dev_temp_param()+dt*balle.evolution());
    balle.set_param(balle.get_param()+ dt*balle.get_dev_temp_param());
}

void Integrateur_EC::integre_balle_simple(Balle& balle) const
{   
    Vecteur f(0,-9.81);

    balle.set_dev_temp_param(balle.get_dev_temp_param()+dt*f);
    balle.set_param(balle.get_param()+ dt*balle.get_dev_temp_param());
}