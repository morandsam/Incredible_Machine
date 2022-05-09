#include "Portion_plan.h"
#include "Systeme.h"
#include<ostream>

using namespace std;



double Portion_plan:: calcul_Xklong(Vecteur const& x2) const
{
    double Xklong ((x2-position_origine)*Elong);
    return Xklong;
}

double Portion_plan:: calcul_Xklarg(Vecteur const& x2) const
{
    double Xklarg ((x2-position_origine)*Elarg);
    return Xklarg;
}

Vecteur Portion_plan::calcul_point_plus_proche(ObjetMobile const& obj2) const
{
    // Formule tirée de l'appendice mathématique
    Vecteur x2(Plan::calcul_point_plus_proche(obj2));
    double Xkl (calcul_Xklarg(x2));
    double XkL (calcul_Xklong(x2));
     if(XkL>longueur_){
        x2-= (XkL-longueur_)*Elong;
    }else if(XkL<0){
        x2-= XkL*Elong;
    }
    if(Xkl>largeur_){
        x2-= (Xkl-largeur_)*Elarg;
    }else if(Xkl<0){
        x2-= Xkl*Elarg;
    };
    return x2;
}

double Portion_plan::distance(ObjetMobile const& obj2) const
{
    // Formule tirée de l'appendice mathématique
     double distance = (calcul_point_plus_proche(obj2)-obj2.get_position_masse()).norme()-obj2.get_rayon();
     return distance;
}

void Portion_plan::ajoute_a(Systeme& sys) const
{
    sys.ajouter_objet_stat(new Portion_plan(*this));
}

ostream& Portion_plan::affiche(ostream& sortie) const
{
    sortie<<"Une portion de plan :"<<endl;
    sortie<<get_position_origine()<<" # origine plan"<<endl;
    sortie<<get_normal()<<" # normale plan"<<endl;
    sortie<<get_longueur_()<<" # longueur"<<endl;
    sortie<<get_largeur_()<<" # largeur"<<endl<<endl;

    return sortie;
}

ostream& operator<<(ostream& sortie, Portion_plan const& plan)
{
    return plan.affiche(sortie);
}