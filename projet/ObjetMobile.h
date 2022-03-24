#pragma once
#include"Vecteur.h"
#include<ostream>

class ObjetMobile {

public:
    // Constructeurs

    ObjetMobile(int deg_lib):dev_temp_param(Vecteur(deg_lib)=Vecteur(3)), param(Vecteur(deg_lib)=Vecteur(3)), 
    force(Vecteur(deg_lib)=Vecteur(3)), position_reference(Vecteur(deg_lib)=Vecteur(3)) {}

    ObjetMobile(double masse_, double rayon_)
    :dev_temp_param(Vecteur(3)), param(Vecteur(3)), force(Vecteur(0,0,-9.81)), position_reference(Vecteur(3))
    {
        masse= masse_;
        rayon=rayon_;
        calcul_masse();
    }

    ObjetMobile(Vecteur const& position_, Vecteur const& vitesse_, Vecteur const& force_, Vecteur const& origine, double masse_, double rayon_)
    :dev_temp_param(vitesse_), param(position_), force(force_), position_reference(origine)
    {
        masse= masse_;
        rayon=rayon_;
        calcul_masse_volumique();
    }

    // Méthodes

    void evolution();
    Vecteur get_param() const {return param;};
    Vecteur get_dev_temp_param() const {return dev_temp_param;};
    void set_param(Vecteur const& param_) {param=param_;};
    void set_dev_temp_param(Vecteur const& dev_temp_param_) {dev_temp_param=dev_temp_param_;};
    Vecteur get_force() const {return force;}
    void set_force(Vecteur const& force_) {force=force_;};
    double get_rayon() const {return rayon;};
    double get_masse() const {return masse;};
    void set_rayon(double r) {rayon=r;};
    void set_masse_volumique(double masse_volumique);
    void set_masse(double masse);
    void calcul_masse();
    void calcul_masse_volumique();

    void ajoute_force(Vecteur const& df) {force+=df;};
   
    std::ostream& affiche(std::ostream& sortie) const;

protected:

    // Attributs

    double masse;
    double masse_volumique;
    double rayon;
    Vecteur dev_temp_param;
    Vecteur param;
    Vecteur force;
    Vecteur position_reference;


private:

    
};

// Opérateurs

std::ostream& operator<<(std::ostream& sortie, ObjetMobile const& objetmobile);