#include "Obstacles.h"
#include "iostream"

using namespace std;


void Obstacles::agit_sur(ObjetMobile& obj2) const
{
    // Formules tirées de l'appendice mathématique lié au projet
    double alpha(0.8);
    double mu (0.01);
    if (distance(obj2)<=0){

        
        Vecteur n(~(obj2.get_position_masse()-calcul_point_plus_proche(obj2)));
        double f_n_1(obj2.get_force()*n);

        if(f_n_1<0){
           obj2.set_force(obj2.get_force() - f_n_1*n);
        }

        double v_star((obj2.get_vitesse_masse().oppose())*n);
        Vecteur v_c(obj2.get_vitesse_masse() + v_star*n);
        Vecteur delta_v(0,0,0);
        if(7*mu*(1+alpha)*v_star>=2*v_c.norme()){
            delta_v=Vecteur((1+alpha)*v_star*n -(2/7)*v_c);
        } else {
            delta_v=Vecteur((1+alpha)*v_star*(n-mu*(~v_c)));
        }

        obj2.actualise_vitesse_choc(delta_v);

        //cout<<"CHOC : "<<endl<<endl;
        //obj2.affiche(cout,true)<<endl<<endl;
        //cout<<n<<endl<<f_n_1<<endl<<v_star<<endl;
        //cout<<v_c<<endl<<7*mu*(1+alpha)*v_star<<endl;
        //cout<<delta_v<<endl;
    }
}

