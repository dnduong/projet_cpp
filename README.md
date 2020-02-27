DUONG Duc Nguyen 21604573 & DARDOURI Inès 21504397

Conception et implémentation d'un petit jeu utilisant le langage C++.

Game creator:
Les fichiers permettant de créer des plateaux de jeu sont les suivants:
- creator.cpp
- element.hpp
- diams.hpp
- teupor.hpp
- reumu.hpp
- geurchar.hpp
- mobile.hpp
- commun.hpp
- oueurj.hpp
- streumon.hpp
L’utilisateur choisit d’abord le nombre de niveaux qu’il veut puis la taille du plateau de jeu
(largeur au moins 10, longueur au moins 5), le nombre de teupors, de diams, de reumus et
de geurchars (au moins 1 par type d’élément et doit laisser au moins 6 cases libres dans le
plateau). Il choisit également le nombre de streumons.
Une fois le jeu créé, le fichier contenant toutes les informations nécessaires au jeu est
disponible et prêt à être lu pour pouvoir lancer une partie.
Game player:
Les fichiers permettant de jouer sur les plateaux créés par le Game creator sont les
suivants:
- diams.hpp
- teupor.hpp
- reumu.hpp
- geurchar.hpp
- commun.hpp
- oueurj.hpp
- streumon.hpp
- main.cpp
On lance le jeu avec le premier plateau disponible dans le fichier créé par le game creator.
Le joueur commence la partie avec 3 vies et se situe aléatoirement dans le plateau, et il en
perd une à chaque fois qu’il se fait capturer par un streumon.
Le joueur symbolisé par "@" peut se déplacer sur le plateau dans toutes les directions à raison d’une case à la
fois, en utilisant les touches du clavier comme suit :
- a : pour aller à la case en haut à gauche
- z : pour aller à la case en haut
- e : pour aller à la case en haut à droite
- q : pour aller à la case à gauche
- s : pour aller à la case en bas
- d : pour aller à la case à droite
- w : pour aller à la case en bas à gauche
- c : pour aller à la case en bas à droite
Le joueur a également la possibilité de manger des geurchars symbolisés par "*" situés un peu partout sur le
plateau et les diams symbolisés par "$" pour ovrir les portes symbolisées par "-" si celle-ci est fermée et par "+" si celle-ci est ouverte.
Capturer un geurchar lui procure une possibilité de téléport aléatoire sur le plateau activable
grâce à la touche “g” du clavier.
A chaque fois que le joueur utilise cette option, et tant qu’il dispose de geurchars , il se
téléporte sur une case aléatoire du plateau.
A chaque déplacement du joueur, le streumon symbolisé par "#" va également se déplacer sur le plateau de
manière aléatoire, dans l’espoir d’attraper le joueur.
Dans le cas où un streumon avance sur une même case qu’il y a déjà un autre streumon, il y
a :
- une chance sur trois que les streumons se reproduisent et créent un nouveau
streumon qui sera placé de manière aléatoire sur le plateau,
- une chance sur trois qu’un streumon mange l’autre et cette interaction crée un
nouvel artefact sur le plateau à la place où se trouve le streumon mangé.
- une chance sur trois qu’il ne se passe rien de particulier
A chaque fois que le joueur se fait manger par un streumon, il perd une vie et continue de
jouer jusqu’à l’épuisement de la totalité de ses vies.
A chaque fois que le joueur mange un diams, une teupor s’ouvre.
Le joueur doit sortir par une teupor ouverte afin de passer au plateau de jeu suivant.
Le joueur gagne lorsqu’il arrive à sortir via une porte ouverte du plateau de jeu du dernier
niveau, et il perd lorsqu’il n’a plus de vies.
