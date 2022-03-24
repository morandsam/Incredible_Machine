#pragma once
#include"ObjetMobile.h"
#include<cmath>
#include<ostream>

class Pendule : public ObjetMobile{


public:

    // Constructeurs

    Pendule(Vecteur const& position_, Vecteur const& vitesse_, Vecteur const& force_, Vecteur const& origine, double masse_volumique_, double rayon_, double longueur_, double frottement_)
    : ObjetMobile(position_,vitesse_,force_,origine,masse_volumique_,rayon_), longueur(longueur_),frottement(frottement_),direction(~(Vecteur(0,9.81,0))),
     position_masse(origine+Vecteur(0,0,longueur*cos(get_param().get_coord(0)))+longueur*sin(get_param().get_coord(0))*direction),
     vitesse_masse(longueur*(get_dev_temp_param().get_coord(0))*(cos(get_param().get_coord(0))*direction-Vecteur(0,0,sin(get_param().get_coord(0)))))
      {}

    // Méthodes

    double get_frottement() const {return frottement;};
    double get_longueur() const {return longueur;};
    Vecteur get_direction() const {return direction;};
    Vecteur get_position_masse() const {return position_masse;};
    Vecteur get_vitesse_masse() const {return vitesse_masse;};
    void evolution();
    void calcul_posi_masse();
    void calcul_vitesse_masse();

    std::ostream& affiche(std::ostream& sortie) const;

private:

    // Attributs

    double longueur;
    double frottement;
    Vecteur direction;
    Vecteur position_masse;   
    Vecteur vitesse_masse;

};


std::ostream& operator<<(std::ostream& sortie, Pendule const& pendule);