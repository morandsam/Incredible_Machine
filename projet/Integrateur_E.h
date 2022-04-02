#pragma once
#include"ObjetMobile.h"
#include"Integrateur.h"

class Integrateur_E : public Integrateur {


public:

    // Constructeurs

    Integrateur_E(double dt_): Integrateur(dt_) {}

    // Méthodes

    void integre(ObjetMobile& obj) const;

    // Cette méthode n'a plus d'utilité réelle mais a été utilisée pour testIntegrateur1.cpp
    void integre_balle_simple(Balle& balle) const;

};