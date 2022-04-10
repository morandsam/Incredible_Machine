#include"Systeme.h"
#include<iostream>
#include<ostream>
#include "constantes.h"
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
    
    // Permet de faire agir seulement Archimède sur la balle dans l'exercice P9

        //(*obj_mob[0]).set_force(Vecteur(0,0,0));
        //(*obj_mob[1]).set_force(Vecteur(0,0,0));
        //
        //(*champs_forces[0]).agit_sur(*obj_mob[0]);
        //
        //(*obj_mob[1]).set_force((*obj_mob[1]).get_masse() * g_vec);


    //(*this).affiche(cout,false);

    // Seconde boucle qui gère les chocs
    for(size_t j(0);j<obj_mob.size();++j){
        
        for (size_t i(j+1);i<obj_mob.size();++i){
            (*obj_mob[j]).agit_sur(*obj_mob[i]);            
        }

        for (size_t i(0);i<obj_stat.size();++i){
            (*obj_stat[i]).agit_sur(*obj_mob[j]);
        }
        
    }

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

