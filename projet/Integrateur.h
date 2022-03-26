#pragma once
#include"Vecteur.h"
#include"Pendule.h"


using namespace std;

class Integrateur {

public:

    Vecteur integre_pendule(Pendule const& p, double dt) const;

};