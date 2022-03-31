#pragma once 
#include "Portion_plan.h"
#include "Obstacles.h"
#include <ostream>
#include "Vecteur.h"


class Brique: public Obstacles
{
public:
    Brique(Vecteur def_origine,double hauteur_, Vecteur Elong,Vecteur Elarg)
    :   hauteur(hauteur_), longueur(Elong), largeur(Elarg), normal(~((~longueur)^(~largeur))),
        point_origine(def_origine)
        {
            if((Elong*Elarg)!=0){
                largeur-= (largeur*(~longueur))*(~longueur);
                normal= ~(longueur^largeur);
            }

            largeur_=largeur.norme();
            longueur_=longueur.norme();      //peut etre modifier plus tard
        };


    double distance(const ObjetMobile& Obj2) const override;
    Vecteur calcul_point_plus_proche(ObjetMobile const& obj2) const override;
    Vecteur get_point_origine() const{return point_origine;};
    Vecteur get_longueur() const{return longueur;};
    Vecteur get_largeur() const{return largeur;};
    double get_hauteur() const{return hauteur;};

    std::ostream& affiche(std::ostream& sortie) const;

private:
    double hauteur;
    double longueur_;
    double largeur_;
    Vecteur longueur;
    Vecteur largeur;
    Vecteur normal;
    Vecteur point_origine;
};

std::ostream& operator<<(std::ostream& sortie, Brique const& brique);
