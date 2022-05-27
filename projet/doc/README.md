README (Samuel Morand & Yann Turin):

1. Nous avons fait l'entiéreté du projet demandé à l'exception du moteur graphique (QT).
Nous avons, ajouter un ressort (extension), ainsi qu'un Pendule sphérique et tout les intégrateur demandé. Nous avons aussi crée un PDF nommé arbre_heritage qui montre les heritage de chaque classe ( la flèche pointe vers une classe qui hérite de la classe de départ). Nous avons aussi ajouter des captures d'écrans de nos plots pour que notre projet ait un rendu visuel.

2. Nous avons décidé de ne pas faire le moteur graphique, mais comme dit au point 1. Nous voulions quand même avoir un rendu visuel donc nous avons "ploté" nos résultats sur Gnuplot.

3. Nous avons passé environ 5h en moyenne par personne par semaine. 

Pour bien comprendre notre Projet il est préférable d'avoir regardé notre PDF arbre heritage ainsi que le fichier text Conception.

Les classes Vecteurs, integrateurs quelconques ne sont pas très importante quant à la compréhension de l'utilisation du programme, mais essentiel quant a son focntionnement. Se sont les Classes de calculs.

SupportADessin et Textviewer sont des classes "d'appuis" pour afficher les données du programme ou pour Gnuplot. 

La Classe systeme est la classe qui gère les chocs ainsi que les données qui seront affiché lorsque le programme sera lancé, Nous avons ajouté un booléen comme paramètre poour l'affichage des données nous/vous permettant d'afficher un grand nombre de donnée sur l'objet à l'aide d'un "true" et de ne voir que l'essentiel grâce au "false".

Les Classes Objets, Objetmobiles, Obstacles n'ont pas besoin d'explication pour leur fonctionnement pusique elles seront dans le constructeurs des Classes suivantes: Balle, pendule, penduleSpherique, ressort, plan, portion_plan, brique, vent, ventilateur et ChampForces.

Pour les classes héritant d'ObjetMobile le constructeur a besoin (dans l'ordre):

-La classe Balle :
    . La position de la balle,
    . la vitesse de la balle,
    . la somme des force sur la balle,
    . l'origine(valeur par defaut (0,0,0)inutilisé pour la balle mais le constructeur d'objet mobile demandé, c'est un choix de conception),
    . de sa masse,
    . et de son rayon 

- le ressort:
    . La position du ressort,
    . la vitesse,
    . la somme des force sur la balle,
    . l'origine,  
    . la direction du ressort,
    . la masse de la balle au bout du ressort,
    . le rayon,
    . la longueur au repos,
    . le frottement,
    . la constante k du ressort

- le pendule et penduleSpherique:
    . l'angle de départ,
    . la vitesse,
    . la somme des force sur la balle,
    . l'origine,
    . la masse de la balle au bout du pendule,
    . le rayon de la balle au bout du pendule,
    . la longueur de la "corde",
    . le frottement

------------------------------------------------------------------

Pour les Classes héritant d'obstacles le constructeur a besoin de (dans l'ordre):

- le Plan :
    . de l'origine
    . et de la normal au plan

- la classe Portion_plan:
    . de l'origine
    . de la normal
    . du double de la longeur
    . du vecteur direction de la longueur
    . du double de la largeur

- la Classe Brique :
    . de l'origine
    . de la hauteur
    . du vecteur de la direction de la longueur ayant la norme= longueur
    . du vecteur de la direction de la largueur ayant la norme = largueur

------------------------------------------------------------------

- pour a classe ChampForces, il y a deux constructeurs:
1:  
    . l'intensité sur x
    . l'intensité sur y
    . l'intensité sur z

2:
    . l'origine
    . le vecteur intensité

- pour la classe Vent héritant de ChampForces:
    . origine
    . vecteur unitaire de la direction de la longueur 
    . vecteur unitaire de la direction de la largeur
    . de la profondeur
    .??????????

------------------------------------------------------------------

-La Classe Ventilateur heritant d'objet (choix de conception):
    . origine
    . vecteur unitaire de la direction de la longueur 
    . vecteur unitaire de la direction de la largeur
    . de la hauteur de la brique
    . de la profondeur
    .?????????? v_0






Pour crée un systeme il vous faut lui donner les paramètres qui lui sont nécessaire au focntionnement, comme ceci :

Systeme syst(false,true);

    TextViewer ecran; ?????????

Pour ajouter des Objets à notre systeme il faut d'abord crée l'objet, prenons un pendule nommé Pendu, puis  noté :

Pendu.ajoute_a(syst) // ajoute un pendule au systeme//

Pour faire démarrer la simulation il faut choisir l'integrateur en lui donnant un dt comme paramètre, prenons l'exemple d'un integrateur nommeé integre1, et le nombre d'iteration que vous voulez calculer (ici 300):

    for (size_t i(0);i<300;++i){
        syst.dessine_sur(ecran);
        syst.evolue(integre1);
    }



