#include <iostream>
#include "Balle.h"
#include "Vecteur.h"
#include "ChampForces.h"
using namespace std;

int main()
{

Vecteur posi(3,5.6,9);
Vecteur vitess(1,1,1);
Vecteur forc(3,5,7);

Vecteur posi2(2,3,4);
Vecteur vit2(1,2,3);
Vecteur fr(0,0,0);

Balle balle(posi,vitess,forc,10,3);
Balle balle2(posi2,vit2,fr,30,4);

ChampForces g(0,0,-9.81);

g.agit_sur(balle);

g.agit_sur(balle2);

cout<<(balle.get_force())<<endl;
cout<<balle;

cout<<balle2;


return 0;
}