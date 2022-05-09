#pragma once
#include"ObjetMobile.h"
#include"Integrateur.h"

class Integrateur_RK4 : public Integrateur {


public:

    // Constructeurs

    Integrateur_RK4(double dt_): Integrateur(dt_) {}

    // Méthodes

    void integre(ObjetMobile& obj) const override;

    // Cette méthode n'a plus d'utilité réelle mais a été uitlisée pour testIntegrateur1.cpp
    void integre_balle_simple(Balle& balle) const override;


};