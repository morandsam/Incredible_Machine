#pragma once
#include "SupportADessin.h"


class TextViewer : public SupportADessin {

public:

    // Méthodes 
    
    void dessine(Systeme const& systeme) override;
    void dessine(Balle const& balle) override;
    void dessine(Pendule const& pendule) override;
    void dessine(Ressort const& ressort) override;
    void dessine(Plan const& plan) override;
    void dessine(Portion_plan const& portion_plan) override;
    void dessine(Brique const& brique) override;
    void dessine(ChampForces const& champforces) override;
    void dessine(Ventilateur const& ventilateur) override;
    void dessine(Vent const& vent) override;
};