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
    : Objets(3),dev_temp_param(Vecteur(3)), param(Vecteur(3)), force(Vecteur(0,0,0))
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

    // Destructeur
    
    virtual ~ObjetMobile() = default;


    // Méthodes

    // Méthodes virtuelles
    
    virtual Vecteur evolution(Vecteur const& param_ , Vecteur const& dev_temp_param_) const = 0;
    virtual Vecteur get_position_masse() const {return get_param();};
    virtual Vecteur get_vitesse_masse() const {return get_dev_temp_param();};
    virtual Vecteur get_force_choc(bool avec_projection) const;
    virtual void ajoute_force_choc(Vecteur const& df, bool avec_projection);
    virtual void calcul_posi_masse() {};
    virtual void calcul_vitesse_masse() {};
    
    
    Vecteur evolution() const;

    Vecteur get_param() const {return param;};
    Vecteur get_dev_temp_param() const {return dev_temp_param;};
    Vecteur get_force() const {return force;}
    double get_rayon() const {return rayon;};
    double get_masse() const {return masse;};
    double get_masse_volumique() const {return masse_volumique;};
    
    void set_param(Vecteur const& param_);
    virtual void set_dev_temp_param(Vecteur const& dev_temp_param_);
    void set_rayon(double r) {rayon=r;};
    void set_masse_volumique(double masse_volumique);
    void set_masse(double masse);
    void set_force(Vecteur const& force_) {force=force_;};
    void ajoute_force(Vecteur const& df) {force+=df;};
    
    void calcul_masse();
    void calcul_masse_volumique();


    // Gestion des chocs entre objets mobiles
    void agit_sur(ObjetMobile& obj2, bool infos_choc, bool avec_projection);

    // Méthode virtuelle utilisée dans agit_sur qui permet d'ajuster la vitesse résultante du choc en fonction de l'objet mobile considéré
    virtual void actualise_vitesse_choc(Vecteur const& delta_v) {set_dev_temp_param(get_dev_temp_param() + delta_v);};
    
    // Retourne la distance qui sépare deux objets mobiles bord à bord et non pas centre à centre
    double distance(ObjetMobile const& obj2) const;

    virtual std::ostream& affiche(std::ostream& sortie,bool complet = true) const = 0;
    
protected:

    // Attributs en protected car ObjetMobile est une "super" classe abstraite

    double masse;
    double masse_volumique;
    double rayon;
    Vecteur dev_temp_param;
    Vecteur param;
    Vecteur force;
    
};


