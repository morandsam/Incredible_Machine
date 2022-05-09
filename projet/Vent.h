#pragma once
#include "ChampForces.h"
#include<ostream>



class Vent: public ChampForces {

public:

    // Constructeurs

    Vent(Vecteur origine,Vecteur elong_,Vecteur elarg_,double profondeur_,double v_0_) : ChampForces(origine), elong(elong_), elarg(elarg_), direction(~(elong^elarg).oppose()), profondeur(profondeur_), v_0(v_0_) {}

    // Méthodes
    
    void agit_sur(ObjetMobile& obj) const override;

    bool est_dans_le_vent(ObjetMobile const& obj) const;

    //void ajoute_a(Systeme& sys) const override;

    Vecteur get_elong() const {return elong;};
    Vecteur get_elarg() const {return elarg;};
    double get_profondeur() const {return profondeur;};
    double get_v_0() const {return v_0;};   

    void ajoute_a(Systeme& sys) const;

    // Méthode tirée mot à mot (comme demandé) de la donnée du projet
    virtual void dessine_sur(SupportADessin& support) override { support.dessine(*this); };

    std::ostream& affiche(std::ostream& sortie) const override;

private:
    
    //Attributs

    Vecteur elong;
    Vecteur elarg;
    Vecteur direction;
    double profondeur;
    double v_0;

};

// Opérateurs

std::ostream& operator<<(std::ostream& sortie, Vent const& vent);