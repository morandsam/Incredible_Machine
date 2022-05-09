#include "Integrateur.h"
#include "Integrateur_RK4.h"
#include "Balle.h"
#include "constantes.h"
#include<cmath>

using namespace std;


void Integrateur_RK4::integre(ObjetMobile& obj) const
{   
    // Formules directement tirée du complément mathématique du projet

    Vecteur p(obj.get_param());
    Vecteur p_point(obj.get_dev_temp_param());

    Vecteur k_1(p_point);
    Vecteur k_1_prime(obj.evolution());
    Vecteur k_2(k_1 + 0.5*dt*k_1_prime);
    Vecteur k_2_prime(obj.evolution(p + 0.5*dt*k_1, k_2));
    Vecteur k_3(p_point + 0.5*dt*k_2_prime);
    Vecteur k_3_prime(obj.evolution(p + 0.5*dt*k_2, k_3));
    Vecteur k_4(p_point + dt*k_3_prime);
    Vecteur k_4_prime(obj.evolution(p + dt*k_3, k_4));

    obj.set_param(p + (dt/6)*(k_1 + 2*k_2 + 2*k_3 + k_4));
    obj.set_dev_temp_param(p_point + (dt/6)*(k_1_prime + 2*k_2_prime + 2*k_3_prime + k_4_prime));


    // Actualisation nécessaire pour les pendules et les ressorts
    obj.calcul_posi_masse();
    obj.calcul_vitesse_masse();
}

void Integrateur_RK4::integre_balle_simple(Balle& balle) const
{   
    Vecteur f(0,g);

    // Formules directement tirée du complément mathématique du projet

    Vecteur p(balle.get_param());
    Vecteur p_point(balle.get_dev_temp_param());

    Vecteur k_1(p_point);
    Vecteur k_1_prime(f);
    Vecteur k_2(k_1 + 0.5*dt*k_1_prime);
    Vecteur k_2_prime(f);
    Vecteur k_3(p_point + 0.5*dt*k_2_prime);
    Vecteur k_3_prime(f);
    Vecteur k_4(p_point + dt*k_3_prime);
    Vecteur k_4_prime(f);

    balle.set_param(p + (dt/6)*(k_1 + 2*k_2 + 2*k_3 + k_4));
    balle.set_dev_temp_param(p_point + (dt/6)*(k_1_prime + 2*k_2_prime + 2*k_3_prime + k_4_prime));
}