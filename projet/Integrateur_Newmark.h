#pragma once
#include"ObjetMobile.h"
#include"Integrateur.h"

class Integrateur_Newmark : public Integrateur {


public:

    // Constructeurs

    Integrateur_Newmark(double dt_, double epsilon_ = 0.00001): Integrateur(dt_), epsilon(epsilon_) 
    {
        if (epsilon<0){
            epsilon = 0.00001;
        }
    }

    // Méthodes

    void integre(ObjetMobile& obj) const override;

    // Cette méthode n'a plus d'utilité réelle mais a été uitlisée pour testIntegrateur1.cpp
    void integre_balle_simple(Balle& balle) const override;

private:
    double epsilon;

};