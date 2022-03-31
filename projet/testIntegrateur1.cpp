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

    Integrateur_EC int2(0.01);

    for(size_t i(0);i<1000;++i){
        int2.integre_balle_simple(balle);
        //cout<<"Integration : "<<i<<endl;
        cout<<balle.get_param()<<endl;
    }

    return 0;
}