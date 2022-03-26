#pragma once
#include"ObjetMobile.h"
#include"Integrateur.h"
#include"Vecteur.h"


class Integrateur_EC : public Integrateur {


    public:
        void integre_pendule(ObjetMobile& p,Vecteur const& f,double dt) const;

};