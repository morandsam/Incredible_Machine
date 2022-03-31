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
    
    Vecteur get_position() const {return get_param();}
    Vecteur get_vitesse() const {return get_dev_temp_param();}
    
    void set_position(Vecteur const& position_) {set_param(position_);};
    void set_vitesse(Vecteur const& vitesse_) {set_dev_temp_param(vitesse_);};
    double distance(const ObjetMobile& Obj2);
    
    //std::ostream& affiche(std::ostream& sortie) const;

private:
   
    // Attributs

    

};

// Opérateurs

//affichage sous la forme cout << balle
//std::ostream& operator<<(std::ostream& sortie, Balle const& balle);