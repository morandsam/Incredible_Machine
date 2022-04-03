#pragma once
#include"Vecteur.h"
#include"Objets.h"
#include<ostream>

class ObjetMobile: public Objets {

public:

    // Constructeurs

    ObjetMobile(int deg_lib)
    : Objets(deg_lib), dev_temp_param(Vecteur(deg_lib)=Vecteur(3)), param(Vecteur(deg_lib)=Vecteur(3)), force(Vecteur(deg_lib)=Vecteur(3)) {}

    ObjetMobile(double masse_, double rayon_)
    : Objets(3),dev_temp_param(Vecteur(3)), param(Vecteur(3)), force(Vecteur(0,0,-9.81))
    {
        masse= masse_;
        rayon=rayon_;
        calcul_masse_volumique();
    }

    ObjetMobile(Vecteur const& position_, Vecteur const& vitesse_, Vecteur const& force_, Vecteur const& origine, double masse_, double rayon_)
    : Objets(origine), dev_temp_param(vitesse_), param(position_), force(force_)
    {
        masse= masse_;
        rayon=rayon_;
        calcul_masse_volumique();
    }


    // Méthodes

    // Méthodes virtuelles pour le polymorphisme qui sont toutes redéfinies dans les sous classes
    virtual Vecteur evolution() const = 0;
    virtual Vecteur get_position_masse() const = 0;
    virtual Vecteur get_vitesse_masse() const = 0;
    virtual void calcul_posi_masse() = 0;
    virtual void calcul_vitesse_masse() = 0;

    Vecteur get_param() const {return param;};
    Vecteur get_dev_temp_param() const {return dev_temp_param;};
    void set_param(Vecteur const& param_) {param=param_;};
    void set_dev_temp_param(Vecteur const& dev_temp_param_) {dev_temp_param=dev_temp_param_;};
    Vecteur get_force() const {return force;}
    void set_force(Vecteur const& force_) {force=force_;};
    double get_rayon() const {return rayon;};
    double get_masse() const {return masse;};
    double get_masse_volumique() const {return masse_volumique;};
    void set_rayon(double r) {rayon=r;};
    void set_masse_volumique(double masse_volumique);
    void set_masse(double masse);
    void calcul_masse();
    void calcul_masse_volumique();
    void ajoute_force(Vecteur const& df) {force+=df;};
    

    // Encore à définir
    void agit_sur(ObjetMobile&) const;
    
    // Retourne la distance qui sépare deux objets mobiles bord à bord et non pas centre à centre
    double distance(ObjetMobile const& obj2) const;

    virtual std::ostream& affiche(std::ostream& sortie) const = 0;

protected:

    // Attributs en protected car ObjetMobile est une "super" classe abstraite

    double masse;
    double masse_volumique;
    double rayon;
    Vecteur dev_temp_param;
    Vecteur param;
    Vecteur force;
    
};


