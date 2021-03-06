#pragma once 
#include "Portion_plan.h"
#include "Obstacles.h"
#include "Objets.h"
#include <ostream>
#include "Vecteur.h"


class Brique: public Obstacles
{
public:

    // Constructeurs

    Brique(Vecteur def_origine,double hauteur_,Vecteur Elong,Vecteur Elarg)
    : Obstacles(def_origine), hauteur(hauteur_),longueur_(Elong.norme()),largeur_(Elarg.norme()),longueur(Elong),largeur(Elarg),normal(~((~longueur)^(~largeur)))
        {
            // Formule tirée de l'appendice mathématique qui permet de gérer le cas où les 2 vecteurs ne sont pas orthogonaux 
            if((Elong*Elarg)!=0){
                largeur-= (largeur*(~longueur))*(~longueur);
                normal= ~(longueur^largeur);
            }
        }

    //Méthodes

    // Retourne la distance la plus courte à un objet mobile
    double distance(const ObjetMobile& Obj2) const override;

    // Retourne le point le plus proche de l'objet mobile qui se trouve sur la brique
    Vecteur calcul_point_plus_proche(ObjetMobile const& obj2) const override;

    Vecteur get_position_origine() const{return position_origine;};
    Vecteur get_longueur() const{return longueur;};
    Vecteur get_largeur() const{return largeur;};
    Vecteur get_normal() const{return normal;};
    double get_longueur_() const{return longueur_;};
    double get_largeur_() const{return largeur_;}
    double get_hauteur() const{return hauteur;};

    // Retroune les différentes faces de la brique
    Portion_plan get_f1() const;
    Portion_plan get_f2() const;
    Portion_plan get_f3() const;
    Portion_plan get_f4() const;
    Portion_plan get_f5() const;
    Portion_plan get_f6() const;

    void ajoute_a(Systeme& sys) const;

    // Méthode tirée mot à mot (comme demandé) de la donnée du projet
    virtual void dessine_sur(SupportADessin& support) override { support.dessine(*this); };

    std::ostream& affiche(std::ostream& sortie) const override;

private:

    // Attributs
    
    double hauteur;
    double longueur_;
    double largeur_;
    Vecteur longueur;
    Vecteur largeur;
    Vecteur normal;
};

// Opérateurs

std::ostream& operator<<(std::ostream& sortie, Brique const& brique);
