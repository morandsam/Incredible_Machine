#define _USE_MATH_DEFINES
#include "PenduleSpherique.h"
#include "Systeme.h"
#include <cmath>
#include <iostream>
#include "constantes.h"
#include <float.h>
#include <iostream>

using namespace std;


bool PenduleSpherique::est_vertical() const
{
    if(abs(abs(param.get_coord(0)) - round(abs(param.get_coord(0)/M_PI)*M_PI))<0.000000001){
        return true;
    } else {
        return false;
    }
}

void PenduleSpherique::set_dev_temp_param(Vecteur const& vec)
{
    if(est_vertical()){
        dev_temp_param = Vecteur(vec.get_coord(0),0);
    } else {
        dev_temp_param = vec;
    }   
}

Vecteur PenduleSpherique::evolution(Vecteur const& param_ , Vecteur const& dev_temp_param_) const
{

    // Lorsque theta tend vers un multiple de pi on le met = 0 pour éviter une divison par zéro
    double temp;
    if(est_vertical()){
        temp = 0.0;
    } else {
        temp = (-2.0*cos(param_.get_coord(0))/sin(param_.get_coord(0)));
    }

    // Formule tirée de l'appendice mathématique
    Vecteur p_point_point(sin(param_.get_coord(0))*(cos(param_.get_coord(0))*pow(dev_temp_param_.get_coord(1),2)+(g/longueur)), temp*dev_temp_param_.get_coord(0)*dev_temp_param_.get_coord(1));
    
    return p_point_point;
}


void PenduleSpherique::ajoute_a(Systeme& syst) const
{  
    syst.ajouter_objet_mob(new PenduleSpherique(*this));
} 

void PenduleSpherique::calcul_posi_masse()
{
    // Formule tirée de l'appendice mathématique
    Vecteur temp1(longueur*cos(param.get_coord(0))*(~g_vec));
    Vecteur temp2(longueur*sin(param.get_coord(0))*cos(param.get_coord(1))*direction);
    Vecteur temp3((longueur*sin(param.get_coord(0))*sin(param.get_coord(1))*direction)^(~g_vec));
    position_masse = Vecteur(position_origine+temp1+temp2+temp3);
}

void PenduleSpherique::calcul_vitesse_masse()
{ 
    // Formule tirée de l'appendice mathématique
    Vecteur temp1(dev_temp_param.get_coord(0)*sin(param.get_coord(0))*((~g_vec).oppose()));
    Vecteur temp2(direction*(dev_temp_param.get_coord(0)*cos(param.get_coord(0))*cos(param.get_coord(1)) - (dev_temp_param.get_coord(1)*sin(param.get_coord(0))*sin(param.get_coord(1)))));
    Vecteur temp3((direction*(dev_temp_param.get_coord(0)*cos(param.get_coord(0))*sin(param.get_coord(1)) + (dev_temp_param.get_coord(1)*sin(param.get_coord(0))*cos(param.get_coord(1)))))^(~g_vec));
    vitesse_masse = (longueur*(temp2+temp3+temp1));
}