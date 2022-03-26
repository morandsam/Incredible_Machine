#include <iostream>
#include "Balle.h"
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "Integrateur.h"
#include "Integrateur_EC.h"

using namespace std;

int main()
{
    Vecteur param(0,1);
    Vecteur dev_param(1,2);

    Balle balle(param,dev_param,Vecteur(0,0),Vecteur(0,0),0.127,0);

    Integrateur int1;
    Integrateur_EC int2(0.01);

    for(size_t i(0);i<4;++i){
        int2.integre_balle(balle,int1.integre_balle_simple());
        cout<<"Integration : "<<i<<endl;
        cout<<balle;
    }

    return 0;
}