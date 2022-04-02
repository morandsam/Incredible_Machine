#include <iostream>
#include"Ressort.h"
#include"ObjetMobile.h"

using namespace std;



Vecteur Ressort::evolution() const
{
    // Formule directement tirée de l'appendice mathématique du projet
    Vecteur f((force*direction -k*(get_param().get_coord(0)) - frottement*(get_dev_temp_param().get_coord(0)))/masse);
    return f;
}

void Ressort::calcul_posi_masse()
{
    // Formule directement tirée de l'appendice mathématique du projet
    position_masse= (position_origine + (get_param().get_coord(0))*direction);
}
    
    
void Ressort::calcul_vitesse_masse()
{
    // Formule directement tirée de l'appendice mathématique du projet
    vitesse_masse= ((get_dev_temp_param().get_coord(0))*direction);
}

ostream& Ressort::affiche(ostream& sortie) const
{
    sortie<<masse<<" # masse ressort"<<endl
    <<longueur_repos<<" # longueur au repos ressort"<<endl
    <<k<<" # raideur ressort"<<endl
    <<frottement<<" # frottement ressort"<<endl;
    sortie<<position_origine<<" # origine ressort"<<endl;
    sortie<<direction<<" # direction ressort"<<endl;
    sortie<<param<<" # x ressort"<<endl;
    sortie<<dev_temp_param<<" # x point ressort"<<endl;
    sortie<<position_masse<<" # position bout ressort"<<endl<<endl;

    return sortie;
}


void Ressort::affiche_gnuplot(double dt) const
{
    cout<<dt<<" ";
    cout<<dev_temp_param<<endl;

}


ostream& operator<<(ostream& sortie, Ressort const& ressort)
{
    return ressort.affiche(sortie);
}