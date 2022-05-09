#include <iostream>
#include"Ressort.h"
#include"Systeme.h"
#include"ObjetMobile.h"

using namespace std;



Vecteur Ressort::evolution() const
{
    // Formule directement tirée de l'appendice mathématique du projet
    Vecteur f((force*direction -k*(get_param().get_coord(0)) - frottement*(get_dev_temp_param().get_coord(0)))/masse);
    return f;
}

void Ressort::actualise_vitesse_choc(Vecteur const& delta_v)
{
    // Formule NON-tirée du complément mathématique : elle permet de prendre que la composante de delta_v qui est tangente à la vitesse de la masse au bout du ressort
    set_dev_temp_param(get_dev_temp_param() + (delta_v*direction)*direction);
}

Vecteur Ressort::get_force_choc() 
{
    return force*(~get_vitesse_masse())*(~get_vitesse_masse());
}

void Ressort::ajoute_force_choc(Vecteur const& df)
{
    force+=df;

    force = force*(~get_vitesse_masse())*(~get_vitesse_masse());
}

void Ressort::set_force(Vecteur const& force_) 
{
    force = Vecteur(0,0,0);
    ajoute_force(force_);
}

void Ressort::set_param(Vecteur const& param_)
{
    param=param_;
    calcul_posi_masse();
}

void Ressort::set_dev_temp_param(Vecteur const& dev_temp_param_) 
{
    dev_temp_param=dev_temp_param_;
    calcul_vitesse_masse();
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


//Vecteur Ressort::get_force_choc() const 
//{
//    // Formule NON-tirée de l'appendice mathématique qui donne la force subie par la masse le long de la direction du ressort
//    double p_(param.get_coord(0));
//    double p_point_(dev_temp_param.get_coord(0));
//    Vecteur f((get_force()*direction - k*p_ - frottement*p_point_)*direction);
//    return f;
//}