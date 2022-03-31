#pragma once
#include"Vecteur.h"
#include"Pendule.h"
#include"Balle.h"


using namespace std;

class Integrateur {

public:

    virtual void integre_balle_simple(Balle& balle) const =0;
    virtual void integre_pendule(Pendule& p) const =0;
    virtual void integre_balle(Balle& balle) const =0;

};