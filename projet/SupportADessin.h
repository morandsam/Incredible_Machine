#pragma once
#include "Balle.h"
#include "Pendule.h"
#include "Systeme.h"


class SupportADessin {

public:
    virtual ~SupportADessin() = default;

    virtual void dessine(Systeme const&) = 0;
    virtual void dessine(Balle const&) = 0;
    virtual void dessine(Pendule const&) = 0;
    
};