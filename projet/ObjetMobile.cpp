#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "ObjetMobile.h"
#include <ostream>

using namespace std;

Vecteur ObjetMobile::evolution() const
{
    return evolution(param,dev_temp_param);
}

void ObjetMobile::calcul_masse()
{
    // le volume correspond à celui d'une sphère
    masse = masse_volumique*4*M_PI*rayon*rayon*rayon/3;
}

void ObjetMobile::calcul_masse_volumique()
{
    // le volume correspond à celui d'une sphère
    masse_volumique = masse/(4*M_PI*rayon*rayon*rayon/3);
}

void ObjetMobile::set_masse_volumique(double massevolumique)
{
    masse_volumique=massevolumique;
    calcul_masse();
}

void ObjetMobile::set_masse(double newmasse)
{
    masse=newmasse;
    calcul_masse_volumique();
}

void ObjetMobile::agit_sur(ObjetMobile& obj2, bool infos_choc)
{   
    // Formules tirées de l'appendice mathématique lié au projet
    double alpha(0.8);
    double mu (0.01);
    if (distance(obj2)<=0){

        if(infos_choc){
            cout<<endl<<"CHOC : "<<endl<<endl<<"Avant choc : "<<endl<<endl;
            this->affiche(cout,true);
            obj2.affiche(cout,true);
        }
        
        Vecteur n(~(get_position_masse()-obj2.get_position_masse()));
        double lambda((1+alpha)*(obj2.get_masse())/(get_masse() + obj2.get_masse()));
        double f_n_1(get_force_choc()*n);
        double f_n_2(obj2.get_force_choc()*n);
        if(f_n_1<0){
            ajoute_force_choc((f_n_1*n).oppose());
            obj2.ajoute_force_choc(f_n_1*n);
        }

        if(f_n_2>0){
            ajoute_force_choc(f_n_2*n);
            obj2.ajoute_force_choc((f_n_2*n).oppose());
        }

        double v_star((obj2.get_vitesse_masse()-get_vitesse_masse())*n);
        Vecteur v_c(get_vitesse_masse() - obj2.get_vitesse_masse() + v_star*n);
        Vecteur delta_v(0,0,0);
        if(7*mu*(1+alpha)*v_star>=2*v_c.norme()){
            delta_v=Vecteur(lambda*v_star*n - ((2*obj2.get_masse())/(7*(get_masse()+obj2.get_masse())))*v_c);
        } else {
            delta_v=Vecteur(lambda*v_star*(n-mu*(~v_c)));
        }

        actualise_vitesse_choc(delta_v);
        obj2.actualise_vitesse_choc(((get_masse()/obj2.get_masse())*delta_v).oppose());

        if(infos_choc){
            cout<<"n : "<<n<<endl<<"lambda : "<<lambda<<endl<<"f_n_1 : "<<f_n_1<<endl<<"f_n_2 : "<<f_n_2<<endl<<"v_star : "<<v_star<<endl;
            cout<<"v_c : "<<v_c<<endl<<7*mu*(1+alpha)*v_star<<endl<<2*v_c.norme()<<endl;
            cout<<"delta_v : "<<delta_v<<endl<<endl;
            cout<<"Apres choc : "<<endl<<endl;
            this->affiche(cout,true);
            obj2.affiche(cout,true);
        }
    }
}
    
double ObjetMobile::distance(ObjetMobile const& obj2) const
{
    Vecteur c1_c2 = get_position_masse() - obj2.get_position_masse();
    double distance(0); 
    distance = c1_c2.norme()-get_rayon()-obj2.get_rayon();
    return distance;
}






