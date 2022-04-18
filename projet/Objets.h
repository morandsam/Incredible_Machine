#pragma once 
#include "Vecteur.h"
#include "Dessinable.h"
#include "SupportADessin.h"

// Ceci a été ajouté afin d'éviter une dépendance cyclique lorsqu'on compile le projet
class ObjetMobile;


class Objets : public Dessinable
{ 
public: 

    // Constructeurs

    Objets(Vecteur position_origine_): position_origine(position_origine_) {}
    Objets(): position_origine(Vecteur(0,0,0)) {}
    Objets(int deg_lib): position_origine(Vecteur (deg_lib) = Vecteur(3,0)) {}

    // Destructeur
    
    virtual ~Objets() = default;

    // Méthodes virtuelles qui sont redéfines dans les sous classes  --> polymorphisme 
    virtual double distance(ObjetMobile const&) const = 0;

protected:
    Vecteur position_origine;
};