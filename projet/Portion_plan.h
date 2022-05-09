#pragma once 
#include"Plan.h"
#include<ostream>

class Portion_plan: public Plan
{
public: 

    // Constructeurs

    Portion_plan(Vecteur def_origine, Vecteur def_normal,double def_long,Vecteur Elong_,double def_larg)
    : Plan(def_origine, ~def_normal),longueur_(def_long),largeur_(def_larg),Elong(~Elong_),Elarg(Elong)
    {
        // Formule tirée de l'appendice mathématique qui permet de gérer le cas où les 2 vecteurs ne sont pas orthogonaux 
        if((def_normal*Elong_)!=0){
            Elong-= ~((Elong*normal)*normal);
        }
        Elarg= ~(normal^Elong);
    }

    // Méthodes
    
    double get_longueur_() const {return longueur_;};
    double get_largeur_() const {return largeur_;};
    Vecteur get_Elong() const {return Elong;};
    Vecteur get_Elarg() const {return Elarg;};

    // Nécessaires pour calcul_point_plus_proche
    double calcul_Xklong(Vecteur const& x2) const;
    double calcul_Xklarg(Vecteur const& x2) const;    
    double distance(ObjetMobile const& obj2) const;

    Vecteur calcul_point_plus_proche( ObjetMobile const& Obj2) const override;

    void ajoute_a(Systeme& sys) const;

    // Méthode tirée mot à mot (comme demandé) de la donnée du projet
    virtual void dessine_sur(SupportADessin& support) override { support.dessine(*this); };
    
    std::ostream& affiche(std::ostream& sortie) const override;

private:

    // Attributs
    
    double longueur_;
    double largeur_;
    Vecteur Elong;
    Vecteur Elarg;
};

// Opérateurs

std::ostream& operator<<(std::ostream& sortie, Portion_plan const& plan);