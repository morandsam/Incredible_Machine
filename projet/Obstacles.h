#pragma once
#include "Objets.h"
#include "ObjetMobile.h"

class Obstacles: public Objets {

public:

    // Constructeurs

    Obstacles(Vecteur origine): Objets(origine) {}

    
    // A redéfinir
    void agit_sur(ObjetMobile& obj2) const override;

    // Méthode virtuelle redéfinie dans les sous classes --> polymorphisme
    virtual Vecteur calcul_point_plus_proche(ObjetMobile const& Obj2) const = 0;
};