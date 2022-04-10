#include "Integrateur.h"
#include "Integrateur_E.h"
#include<cmath>
#include<iostream>
#include "constantes.h"

using namespace std;


void Integrateur_E::integre(ObjetMobile& obj) const
{
    // Formules directement tirée du complément mathématique du projet
    obj.set_param(obj.get_param()+ dt*obj.get_dev_temp_param());
    obj.set_dev_temp_param(obj.get_dev_temp_param()+dt*obj.evolution());

    // Actualisation nécessaire pour les pendules et les ressorts
    obj.calcul_posi_masse();
    obj.calcul_vitesse_masse();
}


void Integrateur_E::integre_balle_simple(Balle& balle) const
{   
    Vecteur f(0,g);

    // Formules directement tirée du complément mathématique du projet
    balle.set_param(balle.get_param()+ dt*balle.get_dev_temp_param());
    balle.set_dev_temp_param(balle.get_dev_temp_param()+dt*f);   
}