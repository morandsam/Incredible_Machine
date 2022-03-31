#pragma once 
#include "Obstacles.h"
#include "Vecteur.h"
#include<ostream>

class Plan:public Obstacles
{
public:

    Plan(Vecteur const& origine,Vecteur const& def_normal)
    :point_origine(origine), normal(~def_normal) {}

    Vecteur get_point_origine() const {return point_origine;};
    Vecteur get_normal() const {return normal;};
    
    Vecteur calcul_point_plus_proche(ObjetMobile const& Obj2) const override;
    double distance(ObjetMobile const& obj2) const override;

    std::ostream& affiche(std::ostream& sortie) const;

protected:
    Vecteur point_origine;
    Vecteur normal;
};

std::ostream& operator<<(std::ostream& sortie, Plan const& plan);