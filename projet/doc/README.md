---------------------------------------------------------------
README (Samuel Morand & Yann Turin) :

1.Nous avons fait l'entièreté du projet demandé à l'exception du moteur graphique (QT).

Nous avons ajouté un ressort (extension), ainsi qu'un pendule sphérique et tous les intégrateurs proposés. Nous avons aussi créé un PDF nommé arbre héritage qui montre les héritages de chaque classe (la flèche pointe vers la classe qui hérite de la classe de départ). Nous avons aussi ajouté des captures d'écrans de nos plots, ainsi que leurs fichiers de données rattachés pour que notre projet ait un "minimum" de rendu visuel.

2.Nous avons décidé de ne pas faire le moteur graphique, mais comme dit au point 1. Nous voulions quand même avoir un rendu visuel donc nous avons "ploté" nos résultats sur gnuplot.

3.Nous avons passé environ 7h en moyenne par personne par semaine.

Pour bien comprendre notre projet il est préférable d'avoir regardé notre PDF arbre héritage au préalable.

---------------------------------------------------------------

Les classes Objets, Objetmobile, Obstacles n'ont pas besoin d'explications pour leur fonctionement puisqu’elles seront dans le constructeur des classes
suivantes : Balle, Pendule, PenduleSpherique, Ressort, Plan, PortionPlan, Brique, Vent, Ventilateur et ChampForces.

Pour les classes héritant d'ObjetMobile le constructeur a besoin (dans l'ordre) :

- La classe Balle :
. La position de la balle, (Vecteur 2D-3D)
. La vitesse de la balle, (Vecteur 2D-3D)
. De sa masse, (double)
. De son rayon, (double)
. La somme des forces sur la balle (par défaut (0,0,0)),
. L’origine (valeur par défaut (0,0,0) inutilisé pour la balle mais le constructeur d'objet mobile le demande, c'est un choix de conception)

- La classe Ressort :
. La position du ressort, (Vecteur 1D)
. La vitesse, (Vecteur 1D)
. L’origine, (Vecteur 3D)
. La direction du ressort, (Vecteur 3D)
. La masse de la balle au bout du ressort, (double)
. Le rayon, (double)
. La longueur au repos, (double)
. Le frottement, (double)
. La constante k du ressort, (double)
. La somme des forces sur la balle (valeur par défaut (0,0,0))

- Les classes Pendule et PenduleSpherique :
. L'angle de départ, (Vecteur 1D resp. Vecteur 2D)
. La vitesse, (Vecteur 1D resp. Vecteur 2D)
. L’origine, (Vecteur 3D)
. La masse de la balle au bout du pendule, (double)
. Le rayon de la balle au bout du pendule, (double)
. La longueur de la "tige", (double)
. Le frottement, (double)
. La somme des forces sur la balle (valeur par défaut (0,0,0))

------------------------------------------------------------------

Pour les classes héritant d'obstacles le constructeur a besoin de (dans l'ordre) :

- La classe Plan :
. De l'origine (Vecteur 3D)
. Et de la normal au plan (Vecteur 3D)

- La classe Portion_plan :
. De l'origine (Vecteur 3D)
. De la normal (Vecteur 3D)
. Du double de la longueur
. Du vecteur 3D direction de la longueur
. Du double de la largeur

- La classe Brique :
. De l'origine (Vecteur 3D)
. De la hauteur (double)
. Du vecteur 3D de la direction de la longueur ayant la norme = longueur
. Du vecteur 3D de la direction de la largueur ayant la norme = largueur

------------------------------------------------------------------

- La classe ChampForces, deux constructeurs ( il est recommandé de n'utiliser que le premier ) :

1 :
. L'intensité sur x en double
. L’intensité sur y en double
. L’intensité sur z en double

2 :
. L’origine (Vecteur 3D)
. Le vecteur intensité (Vecteur 3D)


- La classe Vent :
. Origine (Vecteur 3D)
. Vecteur de la direction de la longueur (Vecteur 3D)
. Vecteur de la direction de la largeur (Vecteur 3D)
. De la profondeur (double)
. De la vitesse du vent (double)

------------------------------------------------------------------

- La classe Ventilateur :
. Origine (Vecteur 3D)
. Vecteur de la direction de la longueur (Vecteur 3D)
. Vecteur de la direction de la largeur (Vecteur 3D)
. De la hauteur de la brique (double)
. De la profondeur (double)
. De la vitesse du vent (double)

-----------------------------------------------------------------

- La classe Vecteur comporte 6 constructeurs:

1 :
  La dimension (remplit de 0 (vecteur nul)) en int
2 :
  La valeur (vecteur 1D) en double
3 :
  la valeur première composantes en double
  La valeur deuxième composantes en double
4 :
  La valeur de la première composantes en double
  La valeur de la deuxième composantes en double
  La valeur de la troisème composantes en double

5 :
  Un vector<double> (prend sa dimension et ses valeurs)

6 :  le constructeur de copie

----------------------------------------------------------------

Il n'est pas nécesaire de comprendre comment les intégrateurs fonctionnent pour pouvoir utiliser la simulation. Sachez qu'il existe 4 types d'integrateurs différents dans notre projet à votre disposition : Integrateur_E, Integrateur_EC, Integrateur_RK4 et Integrateur_Newmark, les 2 derniers sont les plus exactes. Afin de pouvoir en déclarer un il suffit de choisir son type et de lui donner un pas de temps (secondes) en double :

// Integrateur_EC nom(0.01);

---------------------------------------------------------------

La classe Systeme est la classe qui contient tous les objets que vous voulez utiliser pour la simulation et qui, grâce à la méthode évolution, les fait évoluer et interagir entre eux en cas de chocs. Nous avons ajouté deux booléens comme paramètres pour le constructeur de cette classe :

à l'aide du premier booléen:

-"true" : donne les infos précises pendant un choc
-"false" : ne donne rien

à l'aide du deuxième booléen:

-"true" : projette les forces lors d'un choc (pour tous les objets mobiles sauf la balle)
-"false" : ne projette pas les forces

Pour créer un système il vous faut donc lui donner les paramètres qui lui sont nécessaires au fonctionnement, comme ceci :

// Systeme syst(false,true); 

Pour ajouter des Objets à notre système il faut d'abord créer l'objet, prenons un pendule nommé pendu, puis écrire :

// pendu.ajoute_a(syst); 

Finalement, pour faire évoluer un système il choisir un intégrateur et lui appliquer la méthode evolue() de Systeme :

// Integrateur_RK4 integr(0.01);
// 
// for(size_t i(0);i<100;++i){
//     sys.evolue(integr);
// }

----------------------------------------------------------------

La classe TextViewer ne prend aucun argument et permet, à l'aide de la fontion dessine_sur de Systeme (prenant un Textviewer en argument), d'afficher toutes les positions des masses des objets de la simulation. Donc par exemple si vous déclarez un Systeme sys(false,false) et qu'ensuite vous le mettez dans une boucle d'évolution avec sys.dessine_sur(ecran) (TexViewer ecran), alors les données affichées lors de l'exécution seront prêtes à être plottées.

Pour créer un TextViewer il suffit de lui donner un nom sans arguments :

TextViewer nom;

----------------------------------------------------------------

Pour afficher les données de la simulation il existe deux possibilités :

1 : Simplement mettre un cout<<systeme dans la boucle d évolution :

// Integrateur_RK4 integr(0.01);
// 
// for(size_t i(0);i<100;++i){
//     cout<<sys;
//     sys.evolue(integr);
// }

Cette méthode affichera absolument tous les détails sur toutes les composantes du système à chaque pas de temps.

2 : Utiliser un TextViewer :

// Integrateur_RK4 integr(0.01);
//
// TextViewer ecran;
// 
// for(size_t i(0);i<100;++i){
//     sys.dessine_sur(ecran);
//     sys.evolue(integr);
// }

Cette méthode affichera seulement la position de la masse de chaque objet mobile du système. Ces données sont donc très pratiques pour être plottées.
Cet affichage se fait de manière alternée (par exemple: la première ligne de donnée sera le pendule, la deuxième la balle, la troisième le pendule, etc..)

Pour mettre toutes ces données dans un fichier il suffit d'entrer ce type de commande :

// bac_a_sable.exe > donnes.txt

Et ensuite de plot dans gnuplot grâce à la commande :

// splot "donnes.txt" (3D)
// plot "donnes.txt" (2D)

---------------------------------------------------------------

Pour compiler le projet en entier utilisez tous simplement la commande make (sous Linux) dans le répertoire du fichier.
Pour compiler spécifiquement un programme (la liste est dans le makefile au début) vous pouvez entrez la commande :

// make bac_a_sable_ (nom du programme suivi d'un _)

