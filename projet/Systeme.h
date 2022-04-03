#pragma once
#include<vector>
#include<memory>
#include<ostream>
#include "Dessinable.h"
#include "ObjetMobile.h"
#include "Obstacles.h"
#include "Integrateur.h"

class Systeme : public Dessinable{

public:

    // Méthodes


    // ajoute un pointeur sur un objet à la collection objets
    void ajouter_objet_mob(ObjetMobile* nouveau);
    void ajouter_objet_stat(Obstacles* nouveau);

    // Méthode faisant évoluer le système par un intégrateur integr sur nbr_iterations itérations
    void evolue(Integrateur const& integr);

    virtual void dessine_sur(SupportADessin& support) override { support.dessine(*this); };

    std::ostream& affiche(std::ostream& sortie) const;

private:

    // Atrributs

    std::vector<std::unique_ptr<ObjetMobile>> obj_mob;
    std::vector<std::unique_ptr<Obstacles>> obj_stat;

};

// Opérateurs

std::ostream& operator<<(std::ostream& sortie, Systeme const& systeme);