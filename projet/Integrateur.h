#pragma once
#include"Vecteur.h"
#include"Pendule.h"
#include<ostream>

using namespace std;

class Integrateur {

public:

    Pendule integr_pendule_euler(Pendule p, double dt) const;

};