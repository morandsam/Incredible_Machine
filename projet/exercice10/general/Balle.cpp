#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "Balle.h"
#include <ostream>

using namespace std;



Vecteur Balle::evolution() const
{
    double temp(1/get_masse());
    Vecteur f(temp*get_force());
    return f;
}


void Balle::actualise_vitesse_choc(Vecteur const& delta_v)
{
    // Formule tirée de l'appendice mathématique du projet
    set_dev_temp_param(get_dev_temp_param() + delta_v);
}

void Balle::actualise_force_choc(Vecteur const& vecteur)
{
    set_force(force+vecteur);
}
ostream& Balle::affiche(ostream& sortie, bool complet) const
{
    if(complet){
        sortie<<"Une balle :"<<endl;
        sortie<<"Masse : "<<masse<<endl<<"Masse volumique : "<<masse_volumique<<endl
        <<"Rayon : "<<rayon<<endl<<"Position : ";
        sortie<<param<<endl<<"Vitesse : ";
        sortie<<dev_temp_param<<endl<<"Forces : ";
        sortie<<force<<endl<<endl;
    } else {
        sortie<<param<<endl;
        //sortie<<dev_temp_param<<endl;
        //sortie<<force<<endl<<endl;
    }

    return sortie;
}

ostream& operator<<(ostream& sortie, Balle const& balle)
{
    return balle.affiche(sortie);
}


