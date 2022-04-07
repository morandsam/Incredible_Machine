#include"Systeme.h"
#include<iostream>
#include<ostream>
using namespace std;


void Systeme::ajouter_objet_mob(ObjetMobile* nouveau)
{
    if(nouveau != nullptr) {
        obj_mob.push_back(unique_ptr<ObjetMobile>(nouveau));
    }
}

void Systeme::ajouter_objet_stat(Obstacles* nouveau)
{
    if(nouveau != nullptr) {
        obj_stat.push_back(unique_ptr<Obstacles>(nouveau));
    }
}

void Systeme::ajouter_champ_force(ChampForces* nouveau)
{
    if(nouveau != nullptr) {
        champs_forces.push_back(unique_ptr<ChampForces>(nouveau));
    }
}

void Systeme::evolue(Integrateur const& integr)
{
    // Première boucle qui (ré)initialise les forces subies par les objets mobiles
    for(size_t j(0);j<obj_mob.size();++j){

        (*obj_mob[j]).set_force(Vecteur(0,0,0));

        for(size_t i(0);i<champs_forces.size();++i){
            (*champs_forces[i]).agit_sur(*obj_mob[j]);
        }
    }

    // Seconde boucle qui gère les chocs
    for(size_t j(0);j<obj_mob.size();++j){
        
        for (size_t i(j+1);i<obj_mob.size();++i){
            (*obj_mob[j]).agit_sur(*obj_mob[i]);            
        }

        for (size_t i(0);i<obj_stat.size();++i){
            (*obj_stat[i]).agit_sur(*obj_mob[j]);
        }
        
    }

    //(*this).affiche(cout,false);


    // Troisème boucle qui intègre d'un pas de temps tous les objets mobiles
    for(size_t j(0);j<obj_mob.size();++j){

        integr.integre(*obj_mob[j]);
    }
}


std::ostream& Systeme::affiche(std::ostream& sortie, bool complet) const
{
    if(complet){
        for(size_t i(0);i<obj_mob.size();++i){
            obj_mob[i]->affiche(sortie);
        }

        for(size_t i(0);i<obj_stat.size();++i){
            obj_stat[i]->affiche(sortie);
        }

        for(size_t i(0);i<champs_forces.size();++i){
            champs_forces[i]->affiche(sortie);
        }
    } else {
        for(size_t i(0);i<obj_mob.size();++i){
            obj_mob[i]->affiche(sortie,false);
        }
    }

    return sortie;
}

ostream& operator<<(ostream& sortie, Systeme const& systeme)
{
    return systeme.affiche(sortie);
}

