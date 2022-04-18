#pragma once

class SupportADessin;

class Dessinable {

public:

    // Destructeur
    
    virtual ~Dessinable() = default;

    // Méthodes virtuelles

    virtual void dessine_sur(SupportADessin&) = 0;

};