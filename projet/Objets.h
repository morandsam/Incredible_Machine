#pragma once 
class ObjetMobile;

class Objets
{  
    virtual void agit_sur(ObjetMobile&) const =0;
    virtual double distance(ObjetMobile const&) const =0;
};