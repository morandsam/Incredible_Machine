#pragma once
#include"Vecteur.h"
#include"Pendule.h"
#include"Balle.h"


using namespace std;

class Integrateur {

public:


    double integre_pendule(Pendule const& p) const;
    Vecteur integre_balle_simple() const;
    Vecteur integre_balle(Balle const& balle) const;


};