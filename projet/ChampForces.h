#pragma once

#include"Vecteur.h"
#include <cmath>


class ChampForces{
    public:
    
    //Constructeurs

    ChampForces(double x, double y, double z) :intensite(Vecteur(x,y,z)) {}

    //Méthodes

    void agit_sur(Balle& balle) const;

    
    private:

    //Attributs
    
    Vecteur intensite;

};
