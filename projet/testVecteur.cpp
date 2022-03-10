#include <iostream>
#include "Vecteur.h"
using namespace std;

int main()
{
Vecteur vec1;
Vecteur vec2;

vec1.augmente(1);
vec1.augmente(4.4);
vec1.augmente(3.5);

vec2.augmente(2);
vec2.augmente(2);
vec2.augmente(2);

try{
    Vecteur vec3(vec1.prod_vect(vec2));
    vec3.affiche();
}
catch(Erreur erreur) {
    cerr<<erreur.message<<endl;
}


return 0;
}