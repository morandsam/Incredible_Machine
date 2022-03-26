#include"Integrateur.h"
#include"Integrateur_EC.h"
#include<cmath>

using namespace std;


void Integrateur_EC::integre_pendule(ObjetMobile& p,double f,double dt) const
{
    Vecteur p_ (p.get_param());
    Vecteur p_point (p.get_dev_temp_param());

    p.set_dev_temp_param(p.get_dev_temp_param()+dt*f);
    p.set_param(p.get_param()+ dt*p.get_dev_temp_param());
}