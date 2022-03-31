#include "Portion_plan.h"
#include<ostream>

using namespace std;



double Portion_plan:: calcul_Xklong(Vecteur const& x2) const
{
    double Xklong ((x2-point_origine)*Elong);
    return Xklong;
}

double Portion_plan:: calcul_Xklarg(Vecteur const& x2) const
{
    double Xklarg ((x2-point_origine)*Elarg);
    return Xklarg;
   
}

Vecteur Portion_plan::calcul_point_plus_proche(ObjetMobile const& obj2) const
{
    Vecteur x2(Plan::calcul_point_plus_proche(obj2));
    double Xkl (calcul_Xklarg(x2));
    double XkL (calcul_Xklong(x2));
     if(XkL>longueur){
        x2-= (XkL-longueur)*Elong;
    }else if(XkL<0){
        x2-= XkL*Elong;
    }
    if(Xkl>largeur){
        x2-= (Xkl-largeur)*Elarg;
    }else if(Xkl<0){
        x2-= Xkl*Elarg;
    };
    return x2;
}

double Portion_plan::distance(ObjetMobile const& obj2) const
{
     double distance = (calcul_point_plus_proche(obj2)-obj2.get_param()).norme()-obj2.get_rayon();
     return distance;
}

ostream& Portion_plan::affiche(ostream& sortie) const
{
    sortie<<get_point_origine()<<" # origine plan"<<endl;
    sortie<<get_normal()<<" # normale plan"<<endl;
    sortie<<get_longueur()<<" # longueur"<<endl;
    sortie<<get_largeur()<<" # largeur"<<endl<<endl;

    return sortie;
}

ostream& operator<<(ostream& sortie, Portion_plan const& plan)
{
    return plan.affiche(sortie);
}