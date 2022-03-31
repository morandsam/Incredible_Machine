#pragma once
#include "SupportADessin.h"

class Dessinable {

public:

    virtual void dessine_sur(SupportADessin&) const = 0;

};