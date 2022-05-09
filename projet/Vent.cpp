#include "Vent.h"
#include "ObjetMobile.h"
#include "Systeme.h"
#include<iostream>

using namespace std;


void Vent::agit_sur(ObjetMobile& obj) const
{
    // Formule tirées de l'appendice mathématique
    if(est_dans_le_vent(obj)){
        obj.ajoute_force(3.77*v_0*v_0*obj.get_rayon()*obj.get_rayon()*direction);
    } 
}

bool Vent::est_dans_le_vent(ObjetMobile const& obj) const
{
    // Condition tirée de l'appendice mathématique
    Vecteur temp(obj.get_position_masse() - position_origine);

    if(temp*direction>0 && temp*direction<profondeur && temp*(~elarg)>0 && temp*(~elarg)<elarg.norme() && temp*(~elong)>0 && temp*(~elong)<elong.norme()){
        return true;
    } else {
        return false;
    }
}




void Vent::ajoute_a(Systeme& sys) const
{
    sys.ajouter_champ_force(new Vent(*this));
}

ostream& Vent::affiche(ostream& sortie) const
{
    sortie<<"Un vent :"<<endl;
    sortie<<"Direction du vent : "<<direction<<endl;
    sortie<<"Profondeur du vent : "<<profondeur<<endl;
    sortie<<"Longeur : "<<elong<<endl;
    sortie<<"Largeur : "<<elarg<<endl;
    sortie<<"Vitesse du vent : "<<v_0<<endl<<endl;

    return sortie;
}

ostream& operator<<(ostream& sortie, Vent const& vent)
{
    return vent.affiche(sortie);
}