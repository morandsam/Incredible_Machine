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

    //Méthodes

    // Ajoute une force df à un objet mobile
    void agit_sur(ObjetMobile& obj) const;

    // Doit encore être définie
    double distance(ObjetMobile const&) const override;

    // Les 2 méthodes suivantes sont là pour que champforces ne soit pas une classe abstraite
    // A MODIFIER
    std::ostream& affiche(std::ostream& sortie) const {return sortie;};
    virtual void dessine_sur(SupportADessin& support) override { support.dessine(*this); };
    
    private:

    //Attributs
    
    Vecteur intensite;

};
