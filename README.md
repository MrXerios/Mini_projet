# Applications diverses
Application développée avec TouchGFX pour carte 32F746GDISCOVERY.

## Implantation du projet sur une carte 

Pour mettre le projet sur une carte : 

- ouvrir le fichier Mini.touchgfx avec TouchGFx,
- générer le code,
- remplacer les dossiers Mini\TouchGFX\assets et Mini\TouchGFX\gui parmi les dossiers fournis sur github,
- implanter de code dans la carte.

Le dossier Mini\TouchGFX\assets n'est pas nécessaire théoriquement puisque ce projet ne contient que des images fournies par STM, et non pas des images autres.

## Description des applications

### Calculatrice RPM (Reverse Polish Notation)

Calcultarice utilisant les notations RPM. Cette calculatrice affiche les quatre éléments de la pile.

Bouton :
- **0 - 9** : ajout d'un chiffre au premier élément de la pile.
- **\+ \- \x \%** : Opérateurs. Effectue l'opération spécifiée entre les deux premiers éléments de la pile.
- **AC** : Efface le premier élément de la pile
- **Ent** : Ajoute 0 à la pile et décale les éléments déjà dans la pile.
- **XY** : échange les deux permiers éléments de la pile
- **Sup** : Retire le dernier chiffre du premier élément de la pile
- **(x)** : retour à l'écran de sélection des applications

Tout les boutons ne sont pas accessibles sur l'écran initial. Il est possible d'accéder à l'écran secondaire en faisant glisser le doigt sur l'écran vers le bas.

### Timer

Timer configurable entre 0 et 99:59 minutes. Quitter l'écran réinitialise le timer.

### Pong

Jeu Pong. Le jeu démarre lorsque l'utilisateur appuie sur le bouton 'play' au dessus de l'affichage du score.

Le jeu dispose d'un comptage du score. Celui-ci est incrémenté à chaque fois que la balle rebondie sur la raquette. La vitesse de la balle est doublée lorsque le score atteint 10, puis 50. Le meilleur score depuis que la carte a été allumée est enregistré.
