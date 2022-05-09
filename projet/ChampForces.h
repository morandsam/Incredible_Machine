#pragma once
#include"Vecteur.h"
#include"Objets.h"
#include <cmath>
#include<ostream>


class ChampForces: public Objets
{
public:
    
    //Constructeurs

    ChampForces(double x, double y, double z) :intensite(Vecteur(x,y,z)) {}

    ChampForces(Vecteur origine, Vecteur intensite_ = Vecteur(0,0,0)): Objets(origine), intensite(intensite_) {}


    //Méthodes

    // Ajoute une force df à un objet mobile
    virtual void agit_sur(ObjetMobile& obj) const;

    // Doit encore être définie
    double distance(ObjetMobile const&) const override;

    void ajoute_a(Systeme& sys) const;

    virtual void dessine_sur(SupportADessin& support) override { support.dessine(*this); };

    virtual std::ostream& affiche(std::ostream& sortie) const;
    
private:

    //Attributs
    
    Vecteur intensite;

};

// Opérateurs

std::ostream& operator<<(std::ostream& sortie, ChampForces const& champ_force);
