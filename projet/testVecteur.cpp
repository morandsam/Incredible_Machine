#include <iostream>
#include "Vecteur.h"
using namespace std;

// Test de fonctionnement sur la classe Vecteur

int main()
{
    Vecteur vec1(0);
    Vecteur vec2(0);

    vec1.augmente(1);
    vec1.augmente(4.4);
    vec1.augmente(3.5);

    vec2.augmente(1);
    vec2.augmente(4.4);
    vec2.augmente(0);

    vec1*=2;

    Vecteur vec3(vec1);

    cout<<vec3;

    vec3-=vec3;

    cout<<vec3;

    cout<<(2*vec1)<<"   "<<(vec1*2)<<endl;
    return 0;
}