#pragma once
#include"ObjetMobile.h"
#include"Vecteur.h"
#include<ostream>

class Balle : public ObjetMobile{
public:

    // Constructeurs

    Balle(Vecteur const& position_, Vecteur const& vitesse_, Vecteur const& force_, Vecteur const& origine, double masse_, double rayon_)
    : ObjetMobile(position_,vitesse_,force_,origine,masse_,rayon_) {}

    //Méthodes

    // Retourne la fonction f (propre à l'évolution d'une balle) qui est utilisée par l'intégrateur
    Vecteur evolution(Vecteur const& param_ , Vecteur const& dev_temp_param_) const override;

    Vecteur get_force_choc(bool avec_projection) const override {return force;};
    void ajoute_force_choc(Vecteur const& df, bool avec_projection) override {force+=df;};
    

    void ajoute_a(Systeme& sys) const;

    // Méthode tirée mot à mot (comme demandé) de la donnée du projet
    virtual void dessine_sur(SupportADessin& support) override { support.dessine(*this); };
    
    virtual std::ostream& affiche(std::ostream& sortie, bool complet = true) const override;

};

std::ostream& operator<<(std::ostream& sortie, Balle const& balle);