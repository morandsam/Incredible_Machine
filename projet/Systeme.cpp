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

void Systeme::evolue(Integrateur const& integr)
{
    for(size_t j(0);j<obj_mob.size();++j){
        
        for (size_t i(0);i<j;++i){
            (*obj_mob[j]).agit_sur(*obj_mob[i]);
        }
        for (size_t i(j+1);i<obj_mob.size();++i){
            (*obj_mob[j]).agit_sur(*obj_mob[i]);            
        }

        // Obstacles agissent sur les objets mobiles
        for (size_t i(0);i<obj_stat.size();++i){
            (*obj_stat[i]).agit_sur(*obj_mob[j]);
        }

        integr.integre(*obj_mob[j]);
    } 
}

std::ostream& Systeme::affiche(std::ostream& sortie) const
{
    for(size_t i(0);i<obj_mob.size();++i){
        obj_mob[i]->affiche(sortie);
    }

    for(size_t i(0);i<obj_stat.size();++i){
        obj_stat[i]->affiche(sortie);
    }

    return sortie;
}

ostream& operator<<(ostream& sortie, Systeme const& systeme)
{
    return systeme.affiche(sortie);
}

