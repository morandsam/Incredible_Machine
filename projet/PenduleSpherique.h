#pragma once 
#include <cmath>
#include <ostream>
#include "ObjetMobile.h"
#include "Pendule.h"

class PenduleSpherique : public Pendule 
{
public:

    // Constructeurs

    PenduleSpherique(Vecteur const& position_, Vecteur const& vitesse_, Vecteur const& force_, Vecteur const& origine, double masse_, double rayon_, double longueur_, double frottement_)
    :  Pendule( position_, vitesse_,  force_,  origine, masse_, rayon_, longueur_, frottement_)
    {
        calcul_posi_masse();
        calcul_vitesse_masse();
    }

    // Méthodes

    Vecteur evolution(Vecteur const& param_ , Vecteur const& dev_temp_param_) const override;
    
    // Permet de déterminer si l'on s'approche d'une divison par zero dans evolution
    bool est_vertical() const;

    // Permet de mettre phi_point = 0 lorsqu'on est très proche de 0 avec theta 
    void set_dev_temp_param(Vecteur const& vec) override;
    
    void calcul_posi_masse() override;
    void calcul_vitesse_masse() override;

    void ajoute_a(Systeme&) const;

    // Méthode tirée mot à mot (comme demandé) de la donnée du projet
    virtual void dessine_sur(SupportADessin& support) override { support.dessine(*this); };
};