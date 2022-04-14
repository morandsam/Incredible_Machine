#pragma once
#include"ObjetMobile.h"
#include<cmath>
#include<ostream>
#include "constantes.h"

class Pendule : public ObjetMobile{


public:

    // Constructeurs

    Pendule(Vecteur const& position_, Vecteur const& vitesse_, Vecteur const& force_, Vecteur const& origine, double masse_, double rayon_, double longueur_, double frottement_)
    : ObjetMobile(position_,vitesse_,force_,origine,masse_,rayon_), longueur(longueur_),frottement(frottement_),direction(~(Vecteur(0,9.81,0))),
     position_masse(origine+ longueur*(cos(param.get_coord(0))*(~g_vec)) + longueur*sin(param.get_coord(0))*direction),
     vitesse_masse(longueur*(get_dev_temp_param().get_coord(0))*(cos(get_param().get_coord(0))*direction + sin(param.get_coord(0))*(~g_vec).oppose()))
    {}

    // Méthodes

    double get_frottement() const {return frottement;};
    double get_longueur() const {return longueur;};
    Vecteur get_direction() const {return direction;};
    Vecteur get_position_masse() const {return position_masse;};
    Vecteur get_vitesse_masse() const {return vitesse_masse;};
    

    // Retourne la fonction f (propre à l'évolution d'un pendule) qui est utilisée par l'intégrateur
    Vecteur evolution() const;

    void actualise_vitesse_choc(Vecteur const& delta_v) override;

    void actualise_force_choc(Vecteur const& vecteur) override;

    Vecteur get_force_choc() const override;

    // Permet d'actualiser la position et la vitesse de la masse en fonction de param et dev_temp_param
    void calcul_posi_masse();
    void calcul_vitesse_masse();


    // Méthode tirée mot à mot (comme demandé) de la donnée du projet
    virtual void dessine_sur(SupportADessin& support) override { support.dessine(*this); };
    
    std::ostream& affiche(std::ostream& sortie,bool complet = true) const override;

private:

    // Attributs

    double longueur;
    double frottement;
    Vecteur direction;
    Vecteur position_masse;   
    Vecteur vitesse_masse;

};

// Opérateurs

std::ostream& operator<<(std::ostream& sortie, Pendule const& pendule);