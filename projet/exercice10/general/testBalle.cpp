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
    Vecteur vitess(1,1,1);
    Vecteur forc(0,0,0);

    Vecteur posi2(2,3,4);
    Vecteur vit2(1,2,3);
    Vecteur fr(0,0,0);

    Vecteur origine(3);

    Balle balle1(posi,vitess,forc,origine,0.100530964914873,0.2);
    Balle balle2(posi2,vit2,fr,origine,30,4);

    ChampForces g_(0,0,g);

    g_.agit_sur(balle1);

    cout<<balle1;

    return 0;
}