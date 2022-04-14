#pragma once

class SupportADessin;

class Dessinable {

public:

    // Méthodes virtuelles

    virtual void dessine_sur(SupportADessin&) = 0;

};