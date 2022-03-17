#include <iostream>
#include "Balle.h"
#include "Vecteur.h"
using namespace std;

int main()
{

Vecteur posi(3,5.6,9);
Vecteur vitess(1,1,1);
Vecteur forc(3,5,7);

Balle balle(posi,vitess,forc,1,3);

balle.affiche();


return 0;
}