README (Samuel Morand & Yann Turin) :
 
1. Nous avons fait l'entièreté du projet demandé à l'exception du moteur graphique (QT).
Nous avons ajouté un ressort (extension), ainsi qu'un pendule sphérique et tous les intégrateurs proposés. Nous avons aussi créé un PDF nommé arbre héritage qui montre les héritages de chaque classe (la flèche pointe vers la classe qui hérite de la classe de départ). Nous avons aussi ajouté des captures d'écrans de nos plots, ainsi que leurs fichiers de données rattachés pour que notre projet ait un rendu visuel.

2. Nous avons décidé de ne pas faire le moteur graphique, mais comme dit au point 1. Nous voulions quand même avoir un rendu visuel donc nous avons "ploté" nos résultats sur Gnuplot.

3. Nous avons passé environ 7h en moyenne par personne par semaine. 

Pour bien comprendre notre Projet il est préférable d'avoir regardé notre PDF arbre héritage au préalable.

Les classes Vecteurs, intégrateurs quelconques ne sont pas très importante quant à la compréhension de l'utilisation du programme, mais essentiel quant a son fonctionnement. Ce sont les classes de calculs.

SupportADessin et TextViewer sont des classes "d'appuis" pour afficher les données du programme ou pour Gnuplot. 

La classe système est la classe qui contient tout les objets que nous avons ajouté pour notre simulation et, grâce à la méthode évolution, les fait évoluer et intéragir entre eux en cas de chocs. Nous avons ajouté un booléen comme paramètre pour l'affichage des données nous/vous permettant d'afficher un grand nombre de donnée sur l'objet à l'aide d'un "true" et de ne voir que l'essentiel grâce au "false". Pour ce qui est de la méthode "affiche" de la classe système elle a toujours un "false" ce qui indique seulement la position des différentes masses. Par contre les données s'affiche en alterné, il ne faut donc pas relier les traits sur Gnuplot (par exemple: la première ligne de donnée sera le pendule, la deuxième la balle, la troisième le pendule, etc..).

Les classes Objets, Objetmobile, Obstacle n'ont pas besoin d'explication pour leur fonctionnement puisqu’elles seront dans le constructeur des Classes suivantes : Balle, Pendule, PenduleSpherique, Ressort, Plan, PortionPlan, Brique, Vent, Ventilateur et ChampForces.

Pour les classes héritant d'ObjetMobile le constructeur a besoin (dans l'ordre) :

-La classe Balle :
    . La position de la balle, (Vecteur 2D-3D)
    . La vitesse de la balle, (Vecteur 2D-3D)
    . De sa masse, (double)
    . De son rayon, (double)
    . La somme des forces sur la balle (par défaut (0,0,0)),
    . L’origine (valeur par défaut (0,0,0) inutilisé pour la balle mais le constructeur d'objet mobile le demande, c'est un choix de conception)
    

- le ressort :
    . La position du ressort, (Vecteur 1D)
    . La vitesse, (Vecteur 1D)
    . L’origine,  (Vecteur 3D)
    . La direction du ressort, (Vecteur 3D)
    . La masse de la balle au bout du ressort, (double)
    . Le rayon, (double)
    . La longueur au repos, (double)
    . Le frottement, (double)
    . La constante k du ressort, (double)
    . La somme des forces sur la balle (valeur par défaut (0,0,0))

- le pendule et pendule sphérique :
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

- le Plan :
    . De l'origine (Vecteur 3D)
    . Et de la normal au plan (Vecteur 3D)

- la classe Portion plan :
    . De l'origine (Vecteur 3D)
    . De la normal (Vecteur 3D)
    . Du double de la longueur
    . Du vecteur 3D direction de la longueur 
    . Du double de la largeur

- la classe Brique :
    . De l'origine (Vecteur 3D)
    . De la hauteur (double)
    . Du vecteur 3D de la direction de la longueur ayant la norme = longueur
    . Du vecteur 3D de la direction de la largueur ayant la norme = largueur

------------------------------------------------------------------

- pour la classe ChampForces, il y a deux constructeurs :
1 :  
    . l'intensité sur x en double
    . L’intensité sur y en double
    . L’intensité sur z en double

2 :
    . L’origine 
    . Le vecteur intensité 

    Ce deuxième constructeur a seulement une utilité pour la classe Vent qui est utilisée dans la classe Ventilateur

- pour la classe Vent héritant de ChampForces:
    . Origine (Vecteur 3D)
    . Vecteur de la direction de la longueur (Vecteur 3D)
    . Vecteur de la direction de la largeur (Vecteur 3D)
    . De la profondeur (double)
    . De la vitesse du vent (double)

------------------------------------------------------------------

-La Classe Ventilateur héritant d'Objets (choix de conception) :
    . Origine (Vecteur 3D)
    . Vecteur de la direction de la longueur (Vecteur 3D)
    . Vecteur de la direction de la largeur (Vecteur 3D)
    . De la hauteur de la brique (double)
    . De la profondeur (double)
    . De la vitesse du vent (double)


Si vous voulez une force en 2D nulle sur un objet mobile il faudra l'expliciter , car elle est en 3D nulle si l'on n'explicite rien

Pour créer un système il vous faut lui donner les paramètres qui lui sont nécessaire au fonctionnement, comme ceci :

{
    Systeme syst(false,true);
    TextViewer ecran;
}

Pour ajouter des Objets à notre système il faut d'abord créer l'objet, prenons un pendule nommé pendu, puis écrire :

    pendu.ajoute_a(syst) // ajoute un pendule au système//

Pour faire démarrer la simulation il faut choisir l'intégrateur en lui donnant un dt comme paramètre comme ceci:
{
    Integrateur_EC integre1(0.01);
}


Prenons l'exemple d'un intégrateur nommée integre1, et le nombre d'itérations que vous voulez calculer (ici 300):

    for (size_t i(0);i<300;++i){
        syst.dessine_sur(ecran);
        syst.evolue(integre1);
    }


A faire --> 

expliquer à quoi correspondent PRECISEMENT les arguments d'un système et expliquer leur implication  le premier bool donne les infos pendants un choc , le deuxième bool projette les forces lors d'un choc

donner les détails sur Vecteur et surouts sur ses constructeurs

expliquer comment afficher toutes les infos à chaque pas de temps -->  syst.affiche(cout,true) et enlever le syst.dessine_sur(ecran)

epxliciter la classe TexViewer et surtout pour le système !!



            