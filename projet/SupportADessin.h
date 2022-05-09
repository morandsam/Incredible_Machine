#pragma once
class Systeme;
class Balle;
class Pendule;
class Ressort;
class Plan;
class Portion_plan;
class Brique;
class ChampForces;
class Ventilateur;
class Vent;

class SupportADessin {

public:

    // Méthodes virtuelles

    virtual ~SupportADessin() = default;
    virtual void dessine(Systeme const&) = 0;
    virtual void dessine(Balle const&) = 0;
    virtual void dessine(Pendule const&) = 0;
    virtual void dessine(Ressort const&) = 0;
    virtual void dessine(Plan const&) = 0;
    virtual void dessine(Portion_plan const&) = 0;
    virtual void dessine(Brique const&) = 0;
    virtual void dessine(ChampForces const&) = 0;
    virtual void dessine(Vent const&) = 0;
    virtual void dessine(Ventilateur const&) = 0;

};