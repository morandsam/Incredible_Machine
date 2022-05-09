#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "Balle.h"
#include"Systeme.h"
#include <ostream>

using namespace std;



Vecteur Balle::evolution() const
{
    double temp(1/get_masse());
    Vecteur f(temp*get_force());
    return f;
}


void Balle::ajoute_a(Systeme& sys) const
{
    sys.ajouter_objet_mob(new Balle(*this));
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


