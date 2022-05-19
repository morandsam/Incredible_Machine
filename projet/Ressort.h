#pragma once
#include"ObjetMobile.h"
#include<cmath>
#include<ostream>


class Ressort : public ObjetMobile{


public:

    // Constructeurs

    Ressort(Vecteur const& position_, Vecteur const& vitesse_, Vecteur const& force_, Vecteur const& origine, Vecteur const& direction_, double masse_, double rayon_, double longueur_repos_, double frottement_,double k_)
    : ObjetMobile(position_,vitesse_,force_,origine,masse_,rayon_),longueur_repos(longueur_repos_),frottement(frottement_), k(k_), direction(~direction_),
    position_masse(origine+ (get_param().get_coord(0))*direction),
    vitesse_masse((get_dev_temp_param().get_coord(0))*direction)
    {}

    // Méthodes

    double get_frottement() const {return frottement;};
    double get_longueur_repos() const {return longueur_repos;};
    Vecteur get_direction() const {return direction;};
    Vecteur get_position_masse() const {return position_masse;};
    Vecteur get_vitesse_masse() const {return vitesse_masse;};
    
    void calcul_posi_masse() override;
    void calcul_vitesse_masse() override;
   
    // Retourne la fonction f (propre à l'évolution d'un ressort) qui est utilisée par l'intégrateur
    Vecteur evolution(Vecteur const& param_ , Vecteur const& dev_temp_param_) const override;

    void actualise_vitesse_choc(Vecteur const& delta_v) override;

    void ajoute_a(Systeme& sys) const;

    // Méthode tirée mot à mot (comme demandé) de la donnée du projet
    virtual void dessine_sur(SupportADessin& support) override { support.dessine(*this); };

    std::ostream& affiche(std::ostream& sortie, bool complet = true) const override;

private:

    // Attributs

    double longueur_repos;
    double frottement;
    double k;
    Vecteur direction;
    Vecteur position_masse;   
    Vecteur vitesse_masse;

};

// Opérateurs

std::ostream& operator<<(std::ostream& sortie, Ressort const& ressort);