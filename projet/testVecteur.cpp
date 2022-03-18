#include <iostream>
#include "Vecteur.h"
using namespace std;

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



return 0;
}