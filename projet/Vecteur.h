#pragma once
#include<vector>


class Vecteur{
public:

    void augmente(double new_dimension_value);

    void set_coord(unsigned int posi, double new_compo);
    
    void affiche() const;

    bool compare(Vecteur vec2, double precision) const;

    Vecteur oppose() const;

    Vecteur addition(Vecteur autre) const;
    
    Vecteur soustraction(Vecteur autre);

    Vecteur mult(double scalaire) const;

    double prod_scal(Vecteur autre) const;

    Vecteur prod_vect(Vecteur autre) const;

    double norme2() const;

    double norme() const;

    Vecteur unitaire() const;

private:
    std::vector<double> composantes;
};