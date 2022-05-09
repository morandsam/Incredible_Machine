#pragma once
#include "Vent.h"
#include "Brique.h"
#include "Vecteur.h"
#include<ostream>


class Ventilateur : public Objets {

public: 

    // Constructeurs

    Ventilateur(Vecteur origine, Vecteur elong_, Vecteur elarg_, double hauteur_brique, double profondeur, double v_0)
    : Objets(origine), vent(origine,elong_,elarg_,profondeur,v_0), brique(origine,hauteur_brique,elong_,elarg_) {}

    // Méthodes

    void ajoute_a(Systeme& sys) const;

    double distance(ObjetMobile const& obj) const override {return brique.distance(obj);};

    // Méthode tirée mot à mot (comme demandé) de la donnée du projet
    virtual void dessine_sur(SupportADessin& support) override { support.dessine(*this); };

    std::ostream& affiche(std::ostream& sortie) const;

private:

    // Attributs

    Vent vent;
    Brique brique;
    
};

// Opérateurs

std::ostream& operator<<(std::ostream& sortie, Ventilateur const& ventilateur);
