#include <iostream>
#include "Vecteur.h"
using namespace std;

// Test de fonctionnement sur la classe Vecteur

int main()
{
    Vecteur vec1(1.0,2.0,-0.1);
    Vecteur vec2(2.6,3.5,4.1);
    Vecteur vec3(3);

    vec3=vec1;

    cout<<vec1<<endl;
    cout<<vec2<<endl;

    if(vec1==vec2){
        cout<<"1"<<endl;
    } else{
        cout<<"0"<<endl;
    }

    cout<<vec3;

    return 0;
}