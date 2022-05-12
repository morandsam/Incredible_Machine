#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include"Pendule.h"
#include"Systeme.h"
#include "constantes.h"

using namespace std;


Vecteur Pendule::evolution() const
{
    return evolution(param,dev_temp_param);
}

Vecteur Pendule::evolution(Vecteur const& param_ , Vecteur const& dev_temp_param_) const
{
    // Formule directement tirée de l'appendice mathématique du projet
    double p_ (param_.get_coord(0));
    double p_point (dev_temp_param_.get_coord(0));
    Vecteur f((
        cos(p_)*(get_force()*get_direction())
        -sin(p_)*(get_force()*(~g_vec))
        -get_frottement()*p_point/get_longueur())
        /(get_masse()*get_longueur()));
    return f;
}

void Pendule::actualise_vitesse_choc(Vecteur const& delta_v)
{
    // Formule NON-tirée du complément mathématique : elle permet de prendre que la composante de delta_v qui est tangente à la vitesse du bout du pendule
    Vecteur nouvelle_vitesse(get_vitesse_masse() + delta_v);
    set_dev_temp_param(Vecteur((nouvelle_vitesse*(~get_vitesse_masse()))*1.0/get_longueur()));
}

Vecteur Pendule::get_force_choc(bool avec_projection) 
{   
    if(avec_projection) return (force*(~get_vitesse_masse()))*(~get_vitesse_masse());
    else return force;
}

void Pendule::ajoute_force_choc(Vecteur const& df, bool avec_projection)
{
    force+=df;
    if(avec_projection) force = force*(~get_vitesse_masse())*(~get_vitesse_masse());
}

void Pendule::set_force(Vecteur const& force_) 
{
    force = Vecteur(0,0,0);
    ajoute_force(force_);
}

void Pendule::set_param(Vecteur const& param_)
{
    param=param_;
    calcul_posi_masse();
}

void Pendule::set_dev_temp_param(Vecteur const& dev_temp_param_) 
{
    dev_temp_param=dev_temp_param_;
    calcul_vitesse_masse();
}


void Pendule::calcul_posi_masse()
{   
    // Formule directement tirée de l'appendice mathématique du projet
    Vecteur p(position_origine);
    Vecteur temp1(longueur*(cos(param.get_coord(0))*(~g_vec)));
    Vecteur temp2(longueur*sin(param.get_coord(0))*direction);

    position_masse= (p+temp1+temp2);
}
    
    
void Pendule::calcul_vitesse_masse()
{
    // Formule directement tirée de l'appendice mathématique du projet
    Vecteur temp1(cos(param.get_coord(0))*direction);
    Vecteur temp2(sin(param.get_coord(0))*(~g_vec).oppose());
    vitesse_masse= longueur*(dev_temp_param.get_coord(0))*(temp1+temp2);
}

void Pendule::ajoute_a(Systeme& sys) const
{
    sys.ajouter_objet_mob(new Pendule(*this));
}

ostream& Pendule::affiche(ostream& sortie, bool complet) const
{
    if(complet){
        sortie<<"Un pendule :"<<endl;
        sortie<<masse<<" # masse pendule"<<endl
        <<longueur<<" # longueur pendule"<<endl
        <<frottement<<" # frottement pendule"<<endl;
        sortie<<position_origine<<" # origine pendule"<<endl;
        sortie<<direction<<" # direction pendule"<<endl;
        sortie<<param<<" # theta pendule"<<endl;
        sortie<<dev_temp_param<<" # theta point pendule"<<endl;
        sortie<<position_masse<<" # position bout pendule"<<endl;
        sortie<<vitesse_masse<<" # vitesse bout du pendule"<<endl;
        sortie<<evolution()<<" # f() pendule"<<endl;
        sortie<<force<<" # force sur pendule"<<endl<<endl;
    } else {
        sortie<<position_masse<<endl;
        //sortie<<dev_temp_param<<endl;
    }

    return sortie;
}

ostream& operator<<(ostream& sortie, Pendule const& pendule)
{
    return pendule.affiche(sortie);
}



//Vecteur Pendule::get_force_choc() const
//{
//    // Formule tirée directement de l'appendice mathématique qui donne la force totale subie par la masse au bout du pendule
//    double p_ (get_param().get_coord(0));
//    double p_point (get_dev_temp_param().get_coord(0));
//    double f_(evolution().get_coord(0));
//
//    Vecteur f(get_masse()*get_longueur()*(f_*(cos(p_)*direction - sin(p_)*(~g_vec))
//            - (p_point*p_point)*(sin(p_)*direction + cos(p_)*(~g_vec))));
//
//    return f;
//
//}