#pragma once

#include"Vecteur.h"
#include<ostream>

class Balle{
public:

    // Constructeurs

    Balle(double masse_volumique_, double rayon_)
    :vitesse(Vecteur(0,0,0)), position(Vecteur(0,0,0)), force(Vecteur(0,0,-9.81))
    {
        masse_volumique= masse_volumique_;
        rayon=rayon_;
        calcul_masse();
    }

    Balle(Vecteur const& position_, Vecteur const& vitesse_, Vecteur const& force_, double masse_volumique_, double rayon_)
    :vitesse(vitesse_), position(position_), force(force_)
    {
        masse_volumique= masse_volumique_;
        rayon=rayon_;
        calcul_masse();
    }


    //Méthodes
    
    void ajoute_force(Vecteur const& df);
    Vecteur get_position() const {return position;}
    Vecteur get_vitesse() const {return vitesse;}
    Vecteur get_force() const {return force;}
    void set_position(Vecteur const& position_);
    void set_vitesse(Vecteur const& vitesse_);
    void set_force(Vecteur const& force_);
    double get_rayon() const;
    void set_rayon(double r);
    double get_masse() const;
    void set_masse_volumique(double masse_volumique);
    void calcul_masse();
    void set_masse(double masse);
    void calcul_masse_volumique();
    std::ostream& affiche(std::ostream& sortie) const;

private:
   
    // Attributs

    double masse_volumique;
    double masse;
    double rayon;
    Vecteur vitesse;
    Vecteur position;
    Vecteur force;
    
    
};

// Opérateurs

//affichage sous la forme cout << balle
std::ostream& operator<<(std::ostream& sortie, Balle const& balle);