#pragma once

#include"Vecteur.h"
#include"Objets.h"
#include <cmath>


class ChampForces: public Objets
{
    public:
    
    //Constructeurs

    ChampForces(double x, double y, double z) :intensite(Vecteur(x,y,z)) {}

    //Méthodes

    void agit_sur(ObjetMobile& obj) const override;
    double distance(ObjetMobile const&) const override;
    
    private:

    //Attributs
    
    Vecteur intensite;

};
