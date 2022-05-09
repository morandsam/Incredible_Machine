#include "Ventilateur.h"
#include "Systeme.h"
using namespace std;


void Ventilateur::ajoute_a(Systeme& sys) const
{
    brique.ajoute_a(sys);
    vent.ajoute_a(sys);
}

ostream& Ventilateur::affiche(ostream& sortie) const
{
    sortie<<"Un ventilateur compose de :"<<endl;
    sortie<<brique;
    sortie<<vent;

    return sortie;
}

ostream& operator<<(ostream& sortie, Ventilateur const& ventilateur)
{
    return ventilateur.affiche(sortie);
}

