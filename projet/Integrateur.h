#pragma once
#include"Vecteur.h"
#include"ObjetMobile.h"
#include"Balle.h"


using namespace std;

class Integrateur {

public:

    // Constructeurs
    
    Integrateur(double dt_): dt(dt_) {}

    // Métodes virtuelles qui sont redéfinies dans les sous classes d'Integrateur  --> polymorphisme
    virtual void integre(ObjetMobile& obj) const = 0;
    virtual void integre_balle_simple(Balle& balle) const = 0;

protected:

    // Attributs

    double dt;    
};