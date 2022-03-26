#pragma once
#include"ObjetMobile.h"
#include"Integrateur.h"
#include"Vecteur.h"


class Integrateur_EC : public Integrateur {


    public:
        void integre_pendule(ObjetMobile& p,double f,double dt) const;

};