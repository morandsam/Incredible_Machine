#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include"Pendule.h"
#include"Systeme.h"
#include "constantes.h"

using namespace std;



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
        sortie<<param<<" # angle pendule"<<endl;
        sortie<<dev_temp_param<<" # angle point pendule"<<endl;
        sortie<<position_masse<<" # position bout pendule"<<endl;
        sortie<<vitesse_masse<<" # vitesse bout du pendule"<<endl;
        sortie<<ObjetMobile::evolution()<<" # f() pendule"<<endl;
        sortie<<force<<" # force sur pendule"<<endl<<endl;
    } else {
        sortie<<position_masse<<endl;
        //sortie<<param<<" "<<dev_temp_param<<endl;
        //sortie<<dev_temp_param<<endl;
    }

    return sortie;
}

ostream& operator<<(ostream& sortie, Pendule const& pendule)
{
    return pendule.affiche(sortie);
}
