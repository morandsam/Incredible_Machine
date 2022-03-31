#pragma once
#include "Objets.h"
#include "ObjetMobile.h"

class Obstacles: public Objets {
public:
    void agit_sur(ObjetMobile& obj2) const override;
    virtual Vecteur calcul_point_plus_proche(ObjetMobile const& Obj2) const =0;
};