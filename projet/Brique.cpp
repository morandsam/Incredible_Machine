#include <iostream>
#include "Brique.h"
#include "Portion_plan.h"
using namespace std;

 double Brique::distance(ObjetMobile const& obj2) const{
     
     Portion_plan f1(point_origine,normal,longueur_,~longueur,largeur_);
     Portion_plan f2(point_origine,(~largeur).oppose(),hauteur,normal.oppose(),longueur_);
     Portion_plan f3(point_origine,(~longueur).oppose(),largeur_,~largeur,hauteur);
     Portion_plan f4(point_origine + longueur_*(~longueur),~longueur,hauteur,normal.oppose(),largeur_);
     Portion_plan f5(point_origine + largeur_*(~largeur),~largeur,longueur_,~longueur,hauteur);
     Portion_plan f6(point_origine - hauteur*normal,normal.oppose(),largeur_,~largeur,longueur_);

     vector<double> distance(6,0);

     distance[0]= (f1.distance(obj2));
     distance[1]= (f2.distance(obj2));
     distance[2]= (f3.distance(obj2));
     distance[3]= (f4.distance(obj2));
     distance[4]= (f5.distance(obj2));
     distance[5]= (f6.distance(obj2));
     
     double distance_min(distance[0]);
     for(int i(0);i<5;++i){
         if(distance[i]>distance[i+1]){
             distance_min = distance[i+1];
         } 
    }

    Vecteur v(distance);

    return distance_min;
 }

 Vecteur Brique::calcul_point_plus_proche(ObjetMobile const& obj2) const{
     
     Portion_plan f1(point_origine,normal,longueur_,~longueur,largeur_);
     Portion_plan f2(point_origine,(~largeur).oppose(),hauteur,normal.oppose(),longueur_);
     Portion_plan f3(point_origine,(~longueur).oppose(),largeur_,~largeur,hauteur);
     Portion_plan f4(point_origine + longueur_*(~longueur),~longueur,hauteur,normal.oppose(),largeur_);
     Portion_plan f5(point_origine + largeur_*(~largeur),~largeur,longueur_,~longueur,hauteur);
     Portion_plan f6(point_origine - hauteur*normal,normal.oppose(),largeur_,~largeur,longueur_);


     vector<Vecteur> point(6,0);
     vector<double> distance(6,0);
     distance[0]= (f1.distance(obj2));
     distance[1]= (f2.distance(obj2));
     distance[2]= (f3.distance(obj2));
     distance[3]= (f4.distance(obj2));
     distance[4]= (f5.distance(obj2));
     distance[5]= (f6.distance(obj2));

     point[0]= (f1.calcul_point_plus_proche(obj2));
     point[1]= (f2.calcul_point_plus_proche(obj2));
     point[2]= (f3.calcul_point_plus_proche(obj2));
     point[3]= (f4.calcul_point_plus_proche(obj2));
     point[4]= (f5.calcul_point_plus_proche(obj2));
     point[5]= (f6.calcul_point_plus_proche(obj2));
     
     Vecteur p_p_proche(point[0]);
     for(int i(0);i<5;++i){
         if(distance[i]>distance[i+1]){
             p_p_proche = point[i+1];
         }
     }
     return p_p_proche;
 }

 ostream& Brique::affiche(ostream& sortie) const
 {
     sortie<<get_point_origine()<<" # origine brique"<<endl;
     sortie<<get_longueur()<<" # longueur"<<endl;
     sortie<<get_largeur()<<" # largeur"<<endl;
     sortie<<get_hauteur()<<" # hauteur"<<endl<<endl;

     return sortie;
 }

 ostream& operator<<(std::ostream& sortie, Brique const& brique)
 {
     return brique.affiche(sortie);
 }