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

    Vecteur get_position() const {return get_param();};
    Vecteur get_vitesse() const {return get_dev_temp_param();};
    Vecteur get_position_masse() const {return get_position();};
    Vecteur get_vitesse_masse() const {return get_vitesse();};

    // Les 2 méthodes suivantes n'ont pas d'utilité en soi mais sont présentes afin de pouvoir faire du polymorphisme au niveau des objets mobiles
    void calcul_posi_masse() {};
    void calcul_vitesse_masse() {};
    
    void set_position(Vecteur const& position_) {set_param(position_);};
    void set_vitesse(Vecteur const& vitesse_) {set_dev_temp_param(vitesse_);};

    // Retourne la fonction f (propre à l'évolution d'une balle) qui est utilisée par l'intégrateur
    Vecteur evolution() const;

    void actualise_vitesse_choc(Vecteur const& delta_v) override;

    void actualise_force_choc(Vecteur const& vecteur) override;

    Vecteur get_force_choc() const override {return get_force();};

    // Méthode tirée mot à mot (comme demandé) de la donnée du projet
    virtual void dessine_sur(SupportADessin& support) override { support.dessine(*this); };
    
    virtual std::ostream& affiche(std::ostream& sortie, bool complet = true) const override;

};

std::ostream& operator<<(std::ostream& sortie, Balle const& balle);