README (Samuel Morand & Yann Turin) :
 >

1. Nous avons fait l'entièreté du projet demandé à l'exception du moteur graphique (QT).
Nous avons, ajouter un ressort (extension), ainsi qu'un Pendule sphérique et tous les intégrateurs demandés. Nous avons aussi créé un PDF nommé arbre héritage qui montre les héritages de chaque classe (la flèche pointe vers une classe qui hérite de la classe de départ). Nous avons aussi ajouté des captures d'écrans de nos plots pour que notre projet ait un rendu visuel.

2. Nous avons décidé de ne pas faire le moteur graphique, mais comme dit au point 1. Nous voulions quand même avoir un rendu visuel donc nous avons "ploté" nos résultats sur Gnuplot.

3. Nous avons passé environ 5h en moyenne par personne par semaine. 

Pour bien comprendre notre Projet il est préférable d'avoir regardé notre PDF arbre héritage au préalable.

Les classes Vecteurs, intégrateurs quelconques ne sont pas très importante quant à la compréhension de l'utilisation du programme, mais essentiel quant a son fonctionnement. Ce sont les Classes de calculs.

SupportADessin et Textviewer sont des classes "d'appuis" pour afficher les données du programme ou pour Gnuplot. 

La Classe système est la classe qui contient tout les objets que nous avons ajouté pour notre simulation et, grâce à la méthode évolution, les fait évoluer et intéragir entre eux en cas de chocs. Nous avons ajouté un booléen comme paramètre pour l'affichage des données nous/vous permettant d'afficher un grand nombre de donnée sur l'objet à l'aide d'un "true" et de ne voir que l'essentiel grâce au "false". Pour se qui est de la méthode "affiche" de la classe systeme elle a toujours un "false" ce qui indique seulement la position des différentes masses. Par contre les données s'affiche en alterné, il ne faut donc pas relier les traits sur Gnuplot (par exemple: la première ligne de donnée seras le pendule, la deuxième la balle, la troisième le pendule, etc..).

Les Classes Objets, Objetmobiles, Obstacles n'ont pas besoin d'explication pour leur fonctionnement puisqu’elles seront dans le constructeur des Classes suivantes : Balle, pendule, penduleSpherique, ressort, plan, portion_plan, brique, vent, ventilateur et ChampForces.

Pour les classes héritant d'ObjetMobile le constructeur a besoin (dans l'ordre) :

-La classe Balle :
    . La position de la balle,
    . La vitesse de la balle,
    . De sa masse,
    . De son rayon, 
    . La somme des forces sur la balle (par défaut (0,0,0)),
    . L’origine (valeur par défaut (0,0,0) inutilisé pour la balle mais le constructeur d'objet mobile demandé, c'est un choix de conception)
    

- le ressort :
    . La position du ressort,
    . La vitesse,
    . L’origine,  
    . La direction du ressort,
    . La masse de la balle au bout du ressort,
    . Le rayon,
    . La longueur au repos,
    . Le frottement,
    . La constante k du ressort,
    . La somme des forces sur la balle

- le pendule et pendule Sphérique :
    . L'angle de départ,
    . La vitesse,
    . L’origine,
    . La masse de la balle au bout du pendule,
    . Le rayon de la balle au bout du pendule,
    . La longueur de la "corde",
    . Le frottement,
    . La somme des forces sur la balle (par défaut (0,0,0))

------------------------------------------------------------------

Pour les Classes héritant d'obstacles le constructeur a besoin de (dans l'ordre) :

- le Plan :
    . De l'origine
    . Et de la normal au plan

- la classe Portion plan :
    . De l'origine
    . De la normal
    . Du double de la longueur
    . Du vecteur direction de la longueur
    . Du double de la largeur

- la Classe Brique :
    . De l'origine
    . De la hauteur
    . Du vecteur de la direction de la longueur ayant la norme = longueur
    . Du vecteur de la direction de la largueur ayant la norme = largueur

------------------------------------------------------------------

- pour a classé ChampForces, il y a deux constructeurs :
1 :  
    . l'intensité sur x
    . L’intensité sur y
    . L’intensité sur z

2 :
    . L’origine
    . Le vecteur intensité

- pour la classe Vent héritant de ChampForces:
    . Origine
    . Vecteur unitaire de la direction de la longueur 
    . Vecteur unitaire de la direction de la largeur
    . De la profondeur
    . De la vitesse du vent 

------------------------------------------------------------------

-La Classe Ventilateur héritant d'objet (choix de conception) :
    . Origine
    . Vecteur unitaire de la direction de la longueur 
    . Vecteur unitaire de la direction de la largeur
    . De la hauteur de la brique
    . De la profondeur
    . De la vitesse du vent


Si vous voulez une force en 2D il faudrat l'expliciter, car elle est en 3D si l'on n'explicite rien

Pour crée un système il vous faut lui donner les paramètres qui lui sont nécessaire au fonctionnement, comme ceci :

Systeme syst(false,true);

    TextViewer ecran;

Pour ajouter des Objets à notre système il faut d'abord crée l'objet, prenons un pendule nommé Pendu, puis noté :

Pendu.ajoute_a(syst) // ajoute un pendule au système//

Pour faire démarrer la simulation il faut choisir l'intégrateur en lui donnant un dt comme paramètre comme ceci:

Integrateur_EC integre1(0.01);


Prenons l'exemple d'un intégrateur nommée integre1, et le nombre d'itération que vous voulez calculer (ici 300):

    for (size_t i(0);i<300;++i){
        syst.dessine_sur(ecran);
        syst.evolue(integre1);
    }
