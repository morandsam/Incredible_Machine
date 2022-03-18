#pragma once

#include <vector>
#include <string>
#include <ostream>


//structure de gestion d'erreurs
//code=0 est une erreur de dimension
//la structure sera potentiellement agrandie
struct Erreur{
    int code;
    std::string message;
};

class Vecteur{
public:

    //Constructeurs

    Vecteur(int dimension) : composantes(dimension,0) {}


    Vecteur(double coord_1, double coord_2, double coord_3)
    {
        composantes.push_back(coord_1);
        composantes.push_back(coord_2);
        composantes.push_back(coord_3);
    }

    Vecteur(std::vector<double> compo)
    : composantes(compo)
    {}

    Vecteur(Vecteur const& autre)
    {
        composantes=autre.composantes;
    }

    //Méthodes

    void operator+=(Vecteur const& autre);

    void operator-=(Vecteur const& autre);

    void operator*=(double const& scalaire);

    void augmente(double new_dimension_value);

    void set_coord(unsigned int posi, double new_compo);
    
    std::ostream& affiche(std::ostream& sortie) const;
   
    //ajout du paramètre precison afin de pouvoir décider à chaque comparaison quelle précision est souhaitée
    bool compare(Vecteur vec2, double precision) const;

    Vecteur oppose() const;
   
    //Dans le cas où les 2 vecteurs n'ont pas la même dimension on a décidé de "simuler" les dimensions manquantes du plus petit vecteur par des 0
    Vecteur addition(Vecteur autre) const;
    
    // La soustraction est définie par l'addition de l'opposé, la même convention est appliquée qu'à l'addition concernant les vecteurs de taille différentes
    Vecteur soustraction(Vecteur autre);

    Vecteur mult(double scalaire) const;
    
    //En cas de mauvaise(s) dimension(s) une erreur de dimension est lancée
    double prod_scal(Vecteur autre) const;
    
    //En cas de mauvaise(s) dimension(s) une erreur de dimension est lancée
    Vecteur prod_vect(Vecteur autre) const;

    double norme2() const;

    double norme() const;

    Vecteur unitaire() const;

private:

    // Attributs
    
    std::vector<double> composantes;
};


// Opérateurs

//addition
Vecteur operator+(Vecteur const& vec1, Vecteur const& vec2);

//soustraction
Vecteur operator-(Vecteur const& vec1, Vecteur const& vec2);

//multiplication par un scalaire droite
Vecteur operator*(Vecteur const& vec1, double scalaire);

//multiplication par un scalaire gauche
Vecteur operator*(double scalaire, Vecteur const& vec1);

//produit scalaire
double operator*(Vecteur const& vec1, Vecteur const& vec2);

//produit vectoriel
Vecteur operator^(Vecteur const& vec1, Vecteur const& vec2);

//vecteur unitaire
Vecteur operator~(Vecteur const& vec1);

//affichage sous la forme cout << vec
std::ostream& operator<<(std::ostream& sortie, Vecteur const& vec);

//compare
bool operator==(Vecteur const& vec1, Vecteur const& vec2);

//compare si différent
bool operator!=(Vecteur const& vec1, Vecteur const& vec2);
