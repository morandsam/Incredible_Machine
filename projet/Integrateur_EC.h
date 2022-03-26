#pragma once
#include"ObjetMobile.h"
#include"Integrateur.h"
#include"Vecteur.h"


class Integrateur_EC : public Integrateur {


public:
    Integrateur_EC(double dt_): dt(dt_) {}


    void integre_pendule(ObjetMobile& p,double f) const;
    void integre_balle(ObjetMobile& p,Vecteur const& f) const;


private:
    double dt;


};