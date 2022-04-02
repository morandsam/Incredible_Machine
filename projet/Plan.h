#pragma once 
#include "Obstacles.h"
#include "Vecteur.h"
#include<ostream>

class Plan:public Obstacles
{
public:

    // Constructeurs

    Plan(Vecteur const& origine,Vecteur const& def_normal)
    :Obstacles(origine), normal(~def_normal) {}

    // Méthodes

    Vecteur get_position_origine() const {return position_origine;};
    Vecteur get_normal() const {return normal;};
    Vecteur calcul_point_plus_proche(ObjetMobile const& Obj2) const override;
    double distance(ObjetMobile const& obj2) const override;

    std::ostream& affiche(std::ostream& sortie) const;

protected:

    // Attributs
    
    Vecteur normal;
};

// Opérateurs

std::ostream& operator<<(std::ostream& sortie, Plan const& plan);