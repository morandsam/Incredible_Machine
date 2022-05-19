#define _USE_MATH_DEFINES
#include "PenduleSpherique.h"
#include <cmath>
#include <iostream>
#include "constantes.h"
#include <float.h>
#include <iostream>

using namespace std;




Vecteur PenduleSpherique::evolution(Vecteur const& param_ , Vecteur const& dev_temp_param_) const
{
    // Formule directement tirée de l'appendice mathématique du projet
    //Vecteur U_Rho(sin(param.get_coord(0))*cos(param.get_coord(1))*direction 
    //              +((sin(param.get_coord(0))*sin(param.get_coord(1))*direction)^(~g_vec))
    //              + cos(param.get_coord(0))*(~g_vec));
//
    //Vecteur U_Theta(cos(param.get_coord(0))*cos(param.get_coord(1))*direction
    //                + ((cos(param.get_coord(0))*sin(param.get_coord(1))*direction)^(~g_vec))
    //                + sin(param.get_coord(0))*(~g_vec).oppose());
//
    //Vecteur U_Phi(((cos(param.get_coord(1))*direction)^(~g_vec))
     //               -sin(param.get_coord(1))*direction);

    double temp;
    if(param.get_coord(0) == 0){
        temp = 0;
        cout<<"bite"<<endl;
    } else {
        temp = (-2.0/tan(param.get_coord(0)));
    }

    
    Vecteur p_point_point(sin(param.get_coord(0))*(cos(param.get_coord(0))*pow(dev_temp_param.get_coord(1),2)+(g/longueur)),
                    temp*dev_temp_param.get_coord(0)*dev_temp_param.get_coord(1));
    
    //Vecteur f((masse*longueur)*(( -pow(dev_temp_param.get_coord(0),2) - pow(dev_temp_param.get_coord(1),2)*pow(sin(param.get_coord(0)),2))*U_Rho 
    //                             +(p_point_point.get_coord(0)- pow(dev_temp_param.get_coord(1),2)*sin(param.get_coord(0))*cos(param.get_coord(0)))*U_Theta
    //                             +(p_point_point.get_coord(1)*sin(param.get_coord(0)) - 2*dev_temp_param.get_coord(0)*dev_temp_param.get_coord(1)*cos(param.get_coord(0)))*U_Phi));
    
    return p_point_point;
}


void PenduleSpherique::ajoute_a(Systeme& syst) const
{   
} 

void PenduleSpherique::calcul_posi_masse()
{
    Vecteur p(position_origine);
    Vecteur temp1(longueur*cos(param.get_coord(0))*(~g_vec));
    Vecteur temp2(longueur*sin(param.get_coord(0))*cos(param.get_coord(1))*direction);
    Vecteur temp3((longueur* sin(param.get_coord(0))*sin(param.get_coord(1))*direction)^(~g_vec));

    position_masse = (p+temp1+temp2+temp3);
}

void PenduleSpherique::calcul_vitesse_masse()
{ 
    Vecteur temp1(dev_temp_param.get_coord(0)*sin(param.get_coord(0))*((~g_vec).oppose()));
    Vecteur temp2(direction*(dev_temp_param.get_coord(0)*cos(param.get_coord(0))*cos(param.get_coord(1)) - (dev_temp_param.get_coord(1)*sin(param.get_coord(0))*sin(param.get_coord(1)))));
    Vecteur temp3((direction*(dev_temp_param.get_coord(0)*cos(param.get_coord(0))*sin(param.get_coord(1)) + (dev_temp_param.get_coord(1)*sin(param.get_coord(0))*cos(param.get_coord(1)))))^(~g_vec));

    vitesse_masse = (longueur*(temp2+temp3+temp1));
}