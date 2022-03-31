#pragma once 
#include"Plan.h"
#include<ostream>

class Portion_plan: public Plan
{
public: 
    Portion_plan(Vecteur def_origine, Vecteur def_normal,double def_long,Vecteur Elong_,double def_larg)
    : Plan(def_origine, ~def_normal),longueur(def_long),largeur(def_larg),Elong(~Elong_),Elarg(Elong)
    {
        if((def_normal*Elong_)!=0){
            Elong-= ~((Elong*normal)*normal);
        }
        Elarg= ~(normal^Elong);
    }

    double calcul_Xklong(Vecteur const& x2) const;
    double calcul_Xklarg(Vecteur const& x2) const;
    
    double get_longueur() const {return longueur;};
    double get_largeur() const {return largeur;};
    Vecteur get_Elong() const {return Elong;};
    Vecteur get_Elarg() const {return Elarg;};
    
    double distance(ObjetMobile const& obj2) const;
    Vecteur calcul_point_plus_proche( ObjetMobile const& Obj2) const override;
    
    std::ostream& affiche(std::ostream& sortie) const;

private:
    double longueur;
    double largeur;
    Vecteur Elong;
    Vecteur Elarg;
};

std::ostream& operator<<(std::ostream& sortie, Portion_plan const& plan);