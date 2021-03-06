#pragma once
#include "Objets.h"
#include "ObjetMobile.h"
#include<ostream>

class Obstacles: public Objets {

public:

    // Constructeurs

    Obstacles(Vecteur origine): Objets(origine) {}

    // Destructeur
    
    virtual ~Obstacles() = default;

    
    // Gestion choc entre obstacles et objets mobiles
    void agit_sur(ObjetMobile& obj2, bool infos_choc, bool avec_projection) const;

    // Méthode virtuelle redéfinie dans les sous classes --> polymorphisme
    virtual Vecteur calcul_point_plus_proche(ObjetMobile const& Obj2) const = 0;
    virtual std::ostream& affiche(std::ostream& sortie) const = 0;
};