#pragma once
#include"ObjetMobile.h"
#include"Integrateur.h"
#include"Vecteur.h"
#include"Balle.h"
#include"Pendule.h"


class Integrateur_EC : public Integrateur {


public:

    Integrateur_EC(double dt_): dt(dt_) {}

    void integre_pendule(Pendule& p) const;
    void integre_balle(Balle& balle) const;
    void integre_balle_simple(Balle& balle) const;


private:
    double dt;

};