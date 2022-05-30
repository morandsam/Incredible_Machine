#include <iostream>
#include "Balle.h"
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "ChampForces.h"
#include "constantes.h"
using namespace std;

// Test de fonctionnement sur la classe Balle

int main()
{
    Vecteur posi(1,2,3);
    Vecteur vitess(0,0.1,0.2);
    
    Vecteur posi2(-1,1.2,1.3);
    Vecteur vit2(0,0.1,0);

    Balle balle1(posi,vitess,0.100530964914873,0.2);
    Balle balle2(posi2,vit2,0.00460766922526503,0.1);

    ChampForces g_(0,0,g);

    g_.agit_sur(balle1);
    g_.agit_sur(balle2);

    cout<<g_;
    cout<<balle1;
    cout<<balle2;

    return 0;
}