#include "Integrateur.h"
#include "Integrateur_Newmark.h"
#include "Balle.h"
#include "constantes.h"
#include <iostream>
#include<cmath>

using namespace std;


void Integrateur_Newmark::integre(ObjetMobile& obj) const
{   
    // Formules directement tirée du complément mathématique du projet

    Vecteur p(obj.get_param());
    Vecteur p_point(obj.get_dev_temp_param());

    Vecteur p_final(p);
    Vecteur p_point_final(p_point);
    Vecteur s(obj.evolution());
    Vecteur q(p_final);
    Vecteur r(obj.evolution(p_final,p_point_final));
    
    do{
        q-=q;
        q+=p_final;
        p_point_final-=p_point_final;
        p_point_final+= p_point + 0.5*dt*(r+s);
        p_final-=p_final;
        p_final += p + dt*p_point + (dt*dt/3)*(0.5*r + s);
    } while ((p_final - q).norme()>=epsilon);

    obj.set_param(p_final);
    obj.set_dev_temp_param(p_point_final);

    // Actualisation nécessaire pour les pendules et les ressorts
    obj.calcul_posi_masse();
    obj.calcul_vitesse_masse();
}

void Integrateur_Newmark::integre_balle_simple(Balle& balle) const
{   
    Vecteur f(0,g);

    // Formules directement tirée du complément mathématique du projet

    Vecteur p(balle.get_param());
    Vecteur p_point(balle.get_dev_temp_param());

    Vecteur p_final(p);
    Vecteur p_point_final(p_point);
    Vecteur s(f);
    Vecteur q(p_final);
    Vecteur r(f);
    
    do{
        q-=q;
        q+=p_final;
        p_point_final-=p_point_final;
        p_point_final+= p_point + 0.5*dt*(r+s);
        p_final-=p_final;
        p_final += p + dt*p_point + (dt*dt/3)*(0.5*r + s);
    } while ((p_final - q).norme()>=epsilon);

    balle.set_param(p_final);
    balle.set_dev_temp_param(p_point_final);

}