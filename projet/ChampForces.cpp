#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "ChampForces.h"


using namespace std;

void ChampForces::agit_sur(ObjetMobile& obj) const
{
    // rho_air = 1.2 mais peut être modifié
    double rho(1.2);

    // Formule directement tirée de l'appendice mathématique du projet
    Vecteur df((obj.get_masse()-4*M_PI*rho*obj.get_rayon()*obj.get_rayon()*obj.get_rayon()/3)*intensite);
    
    obj.ajoute_force(df);

}

double ChampForces::distance(ObjetMobile const&) const
{

    // defintion temporaire
    return 2.0;
}


ostream& ChampForces::affiche(ostream& sortie) const
{
    sortie<<"Un champ de force :"<<endl;
    sortie<<intensite<<" # intensite"<<endl<<endl;

    return sortie;
}

ostream& operator<<(ostream& sortie, ChampForces const& champ_force)
{
    return champ_force.affiche(sortie);
}