#pragma once
#include"ObjetMobile.h"
#include"Integrateur.h"
#include"Vecteur.h"


class Integrateur_E : public Integrateur {


public:
    Integrateur_E(double dt_): dt(dt_) {}


    void integre_pendule(Pendule& p) const;
    void integre_balle(Balle& balle) const;
    void integre_balle_simple(Balle& balle) const;


private:
    double dt;

};