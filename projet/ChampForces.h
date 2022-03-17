#pragma once

#include <vector>
#include <ostream>
#include <math.h>
#include <cmath>


class ChampForces{
    public:
    void agit_sur(class Balle balle()){
        int Force(0);
        Force= (balle.getmasse()-4*M_PI*1.2*(pow(balle.getrayon(),3)/3))*9.81; 
        balle.getForce;// pas fini car il faut voir comment balle est fait
    };
    private:
    std::vector<double> intensite(3,0);// intensité sur x,y,z reste a voir la suite du programme

};
