#include <iostream>
#include <cmath>
#include "Vecteur.h"
using namespace std;

int main()
{

cout<<"Hello Sam !";

return 0;
}


void Vecteur::augmente(double new_dimension_value)
{
    composantes.push_back(new_dimension_value);   
}

void Vecteur::set_coord(unsigned int posi, double new_compo)
{
    if(posi<composantes.size()){
        composantes[posi]=new_compo;
    }
}

void Vecteur::affiche() const
{
    for(size_t i(0); i<composantes.size(); ++i){
        cout<<composantes[i]<<" ";
    }
    cout<<endl;
}

//ajout du paramètre precison afin de pouvoir décider à chaque comparaison quelle précision est souhaitée
bool Vecteur::compare(Vecteur vec2, double precision) const 
{
    if(composantes.size()==vec2.composantes.size()){
        for(size_t i(0); i<composantes.size(); ++i) {
            if (abs(composantes[i]-vec2.composantes[i])>precision){
                return false;
            }
        }
        return true;
    }
    return false;
}

Vecteur Vecteur::oppose() const 
{
    Vecteur resultat;
    for(size_t i(0); i<composantes.size();++i){
        resultat.augmente(composantes[i]*-1);
    }
    return resultat;
}

//Dans le cas où les 2 vecteurs n'ont pas la même dimension on a décidé de "simuler" les dimensions manquantes du plus petit vecteur par des 0
Vecteur Vecteur::addition(Vecteur autre) const
{
    Vecteur resultat;

    int j(0);

    if(composantes.size()<autre.composantes.size()){
        for(size_t i(0);i<composantes.size();++i){
            resultat.augmente(composantes[i]+autre.composantes[i]);
            ++j;
        }
        for(size_t i(j);i<autre.composantes.size();++i){
            resultat.augmente(autre.composantes[i]);
        }
    } else if(composantes.size()>autre.composantes.size()){
                for(size_t i(0);i<autre.composantes.size();++i){
                    resultat.augmente(composantes[i]+autre.composantes[i]);
                    ++j;
                }
                for(size_t i(j);i<composantes.size();++i){
                    resultat.augmente(composantes[i]);
                }
    } else {
        for(size_t i(0);i<composantes.size();++i){
            resultat.augmente(composantes[i]+autre.composantes[i]);
        }
    }

    return resultat;
}

// La soustraction est définie par l'addition de l'opposé, la même convention est appliquée qu'à l'addition concernant les vecteurs de taille différentes
Vecteur Vecteur::soustraction(Vecteur autre) 
{
    Vecteur resultat;
    return addition(autre.oppose());
}


Vecteur Vecteur::mult(double scalaire) const 
{
    Vecteur resultat;
    for(size_t i(0);i<composantes.size();++i){
        resultat.augmente(scalaire*composantes[i]);
    }

    return resultat;
}

// Il faudra encore définir une erreure en cas de 2 dimensions différentes
double Vecteur::prod_scal(Vecteur autre) const
{
    double result(0);
    if(composantes.size()==autre.composantes.size()){
        for(size_t i(0);i<composantes.size();++i){
            result+= (composantes[i])*(autre.composantes[i]);
        }
        return result;
    }
}

// Il faudra encore définir une erreure en cas de 2 dimensions non égales à 3
Vecteur Vecteur::prod_vect(Vecteur autre) const
{
    Vecteur resultat;
    if(composantes.size()==3 and autre.composantes.size()==3){

        resultat.augmente(composantes[1]*autre.composantes[2]-composantes[2]*autre.composantes[1]);
        resultat.augmente(composantes[2]*autre.composantes[0]-composantes[0]*autre.composantes[2]);
        resultat.augmente(composantes[0]*autre.composantes[1]-composantes[1]*autre.composantes[0]);

        return resultat;
    }
}

double Vecteur::norme2() const 
{
    double norme2;
    for(size_t i(0); i<composantes.size();++i){
        norme2+= composantes[i]*composantes[i];
    }
    return norme2;
}

double Vecteur::norme() const 
{
    return sqrt(norme2());
}

Vecteur Vecteur::unitaire() const 
{
    Vecteur resultat;
    double norme_(norme());
    for (size_t i(0);i<composantes.size(); i++){
        resultat.augmente(composantes[i]/norme_);
    }
        
    return resultat;
}