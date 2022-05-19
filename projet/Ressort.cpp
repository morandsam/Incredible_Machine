#include <iostream>
#include"Ressort.h"
#include"Systeme.h"
#include"ObjetMobile.h"

using namespace std;



Vecteur Ressort::evolution(Vecteur const& param_ , Vecteur const& dev_temp_param_) const
{
    // Formule directement tirée de l'appendice mathématique du projet
    Vecteur f((force*direction -k*(param_.get_coord(0)) - frottement*(dev_temp_param_.get_coord(0)))/masse);
    return f;
}

void Ressort::actualise_vitesse_choc(Vecteur const& delta_v)
{
    // Formule NON-tirée du complément mathématique : elle permet de prendre que la composante de delta_v qui est tangente à la vitesse de la masse au bout du ressort
    set_dev_temp_param(get_dev_temp_param() + (delta_v*direction)*direction);
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

void Ressort::ajoute_a(Systeme& sys) const
{
    sys.ajouter_objet_mob(new Ressort(*this));
}

ostream& Ressort::affiche(ostream& sortie, bool complet) const
{
    if(complet){
        sortie<<"Un ressort :"<<endl;
        sortie<<masse<<" # masse ressort"<<endl
        <<longueur_repos<<" # longueur au repos ressort"<<endl
        <<k<<" # raideur ressort"<<endl
        <<frottement<<" # frottement ressort"<<endl;
        sortie<<position_origine<<" # origine ressort"<<endl;
        sortie<<direction<<" # direction ressort"<<endl;
        sortie<<param<<" # x ressort"<<endl;
        sortie<<dev_temp_param<<" # x point ressort"<<endl;
        sortie<<position_masse<<" # position bout ressort"<<endl<<endl;
    } else {
        sortie<<param<<endl;
        sortie<<dev_temp_param<<endl;
    }

    return sortie;
}

ostream& operator<<(ostream& sortie, Ressort const& ressort)
{
    return ressort.affiche(sortie);
}
