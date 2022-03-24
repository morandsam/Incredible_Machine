#pragma once
#include"ObjetMobile.h"
#include<cmath>
#include<ostream>

class Pendule : public ObjetMobile{


public:

    // Constructeurs

    Pendule(Vecteur const& position_, Vecteur const& vitesse_, Vecteur const& force_, Vecteur const& origine, double masse_volumique_, double rayon_, double longueur_, double frottement_)
    : ObjetMobile(position_,vitesse_,force_,origine,masse_volumique_,rayon_), longueur(longueur_),frottement(frottement_), position_masse(origine+Vecteur(0,longueur*sin(get_param().get_coord(0)),longueur*cos(get_param().get_coord(0)))),
      {}

    // Méthodes

    double get_frottement() const {return frottement;};
    double get_longueur() const {return longueur;};
    Vecteur get_direction() const {return direction;};
    void evolution();
    Vecteur calcul_posi_masse();
    Vecteur calcul_vitesse_masse();

private:

    // Attributs

    double longueur;
    double frottement;
    Vecteur direction;
    Vecteur position_masse;   // à définir dans constructeurs
    Vecteur vitesse_masse;



};