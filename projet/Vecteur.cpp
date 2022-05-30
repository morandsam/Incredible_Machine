#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include <string>
#include <ostream>
using namespace std;


void Vecteur::operator+=(Vecteur const& autre)
{
    Vecteur temp(addition(autre));
    composantes=temp.composantes;
}

void Vecteur::operator-=(Vecteur const& autre)
{
    Vecteur temp(soustraction(autre));
    composantes=temp.composantes;
}

void Vecteur::operator+=(double scal)
{
    for(size_t i(0);i<composantes.size();++i)
    {
        set_coord(i,composantes[i] + scal);
    }
}

void Vecteur::operator*=(double const& scalaire)
{
    Vecteur temp = mult(scalaire);
    composantes=temp.composantes;
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

ostream& Vecteur::affiche(ostream& sortie) const
{
    for(size_t i(0); i<composantes.size(); ++i){
        sortie<<composantes[i]<<" ";
    }
    //sortie<<endl;
    return sortie;
}


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
    Vecteur resultat(0);
    for(size_t i(0); i<composantes.size();++i){
        resultat.augmente(composantes[i]*-1);
    }
    return resultat;
}


Vecteur Vecteur::addition(Vecteur autre) const
{
    Vecteur resultat(0);

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


Vecteur Vecteur::soustraction(Vecteur autre) 
{
    Vecteur resultat(0);
    return addition(autre.oppose());
}


Vecteur Vecteur::mult(double scalaire) const 
{
    Vecteur resultat(0);
    for(size_t i(0);i<composantes.size();++i){
        resultat.augmente(scalaire*composantes[i]);
    }

    return resultat;
}


double Vecteur::prod_scal(Vecteur autre) const
{
    double result(0);

    if(composantes.size()!=autre.composantes.size()){
        Erreur erreur({0,"erreur de dimension dans un produit scalaire"});
        throw erreur;
    }

    for(size_t i(0);i<composantes.size();++i){
        result+= (composantes[i])*(autre.composantes[i]);
    }

    return result;
}


Vecteur Vecteur::prod_vect(Vecteur autre) const
{
    Vecteur resultat(0);
    if(composantes.size()!=3 or autre.composantes.size()!=3){
        Erreur erreur({0,"erreur de dimension dans un produit vectoriel"});
        throw erreur;
    }

    resultat.augmente(composantes[1]*autre.composantes[2]-composantes[2]*autre.composantes[1]);
    resultat.augmente(composantes[2]*autre.composantes[0]-composantes[0]*autre.composantes[2]);
    resultat.augmente(composantes[0]*autre.composantes[1]-composantes[1]*autre.composantes[0]);
    return resultat;
    
}

double Vecteur::norme2() const 
{
    double norme2(0.0);
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
    Vecteur resultat(0);
    double norme_(norme());
    for (size_t i(0);i<composantes.size(); i++){
        resultat.augmente(composantes[i]/norme_);
    }
        
    return resultat;
}


Vecteur operator+(Vecteur const& vec1, Vecteur const& vec2)
{
    Vecteur temp(0);
    temp+=vec1;
    temp+=vec2;
    return temp;
}

Vecteur operator+(Vecteur const& vec, double scal)
{
    Vecteur temp(vec);
    temp+=scal;

    return temp;
}

Vecteur operator+(double scal,Vecteur const& vec)
{
    Vecteur temp(vec);
    temp+=scal;

    return temp;
}

Vecteur operator-(Vecteur const& vec1, Vecteur const& vec2)
{
    Vecteur temp(0);
    temp+=vec1;
    temp-=vec2;
    return temp;
}

Vecteur operator*(double scalaire, Vecteur const& vec1)
{
    Vecteur temp(vec1.mult(scalaire));
    return temp;
}

Vecteur operator*(Vecteur const& vec1, double scalaire)
{
    Vecteur temp(vec1);
    temp*=scalaire;
    return temp;
}

double operator*(Vecteur const& vec1, Vecteur const& vec2)
{
    return vec1.prod_scal(vec2);
}

Vecteur operator^(Vecteur const& vec1, Vecteur const& vec2)
{
    return vec1.prod_vect(vec2);
}

Vecteur operator~(Vecteur const& vec1)
{
    return vec1.unitaire();
}

ostream& operator<<(ostream& sortie, Vecteur const& vec)
{
    return vec.affiche(sortie);
}

bool operator==(Vecteur const& vec1, Vecteur const& vec2)
{
    if (vec1.compare(vec2, 10e-7)){
        return true;
    } else {
        return false;
    }
}

bool operator!=(Vecteur const& vec1, Vecteur const& vec2)
{
    if (vec1==vec2){
        return false;
    } else {
        return true;
    }
}