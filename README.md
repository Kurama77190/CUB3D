<div align="center">
  <img height="150" src="https://github.com/Kurama77190/CUB3D/blob/main/img/makefile.PNG?raw=true"  />
</div>

# Cub3D

Cub3D est un projet de l'école **42**, inspiré par le jeu classique **Wolfenstein 3D**. L'objectif est de construire un moteur graphique en utilisant des techniques de **raycasting** pour simuler un rendu 3D à partir d'un environnement 2D. Ce projet est une excellente introduction à la création de moteurs de jeux et à la gestion de bibliothèques graphiques.

---

## Table des matières

1. [À propos du projet](#à-propos-du-projet)
2. [Ce que le projet nous apprend](#ce-que-le-projet-nous-apprend)
3. [Comment fonctionne le projet](#comment-fonctionne-le-projet)
4. [Installation](#installation)
5. [Utilisation](#utilisation)
6. [Gameplay](#gameplay)
7. [Prérequis](#prérequis)
8. [Licence](#licence)

---

## À propos du projet

Cub3D est une simulation de moteur 3D utilisant une carte 2D. Le joueur peut se déplacer dans un labyrinthe, regarder autour de lui et explorer les environnements générés. Le projet est codé en **C** en utilisant la bibliothèque graphique **MiniLibX**.

L'objectif principal est de comprendre et d'implémenter les bases des moteurs de jeux, notamment :
- Le **raycasting** pour créer une perspective 3D.
- L'affichage des textures sur les murs.
- La gestion des événements utilisateur (clavier et souris).
- La lecture et le parsing d'une carte personnalisée.

---

## Ce que le projet nous apprend

Cub3D nous apprend plusieurs concepts essentiels en développement logiciel et création de jeux vidéo :

1. **Mathématiques appliquées :**
   - Trigonométrie pour calculer les angles et les intersections de rayons.
   - Manipulation des vecteurs pour gérer les directions.

2. **Programmation graphique :**
   - Utilisation de la bibliothèque graphique **MiniLibX** pour dessiner des pixels, des images et gérer les fenêtres.
   - Chargement et affichage de textures à l'aide de fichiers `.xpm`.

3. **Optimisation :**
   - Réduction des calculs inutiles pour améliorer les performances.
   - Organisation du code pour un rendu fluide.

4. **Parsing :**
   - Lecture et validation de fichiers `.cub` contenant les configurations de la carte et des textures.

5. **Gestion des événements :**
   - Capturer les entrées clavier et souris pour interagir avec le jeu.

6. **Robustesse :**
   - Gestion des erreurs (ex. : fichiers manquants, carte incorrecte).
   - Nettoyage et libération correcte des ressources allouées.

---

## Comment fonctionne le projet

### 1. **Raycasting**

Le raycasting est au cœur du moteur 3D :
- Chaque **rayon** est lancé depuis la position du joueur selon son angle de vue.
- Lorsqu'un rayon intersecte un mur, la distance est calculée pour déterminer la hauteur du mur à dessiner.
- Les textures sont ensuite appliquées sur les murs en fonction de la position du point d'intersection.

### 2. **Carte et Parsing**

La carte est représentée comme une matrice 2D de caractères :
- **`1`** : Mur
- **`0`** : Sol
- **`N`, `S`, `E`, `W`** : Position et orientation initiales du joueur.
- Les fichiers `.cub` contiennent également les chemins vers les textures et les couleurs du plafond et du sol.

### 3. **Textures et affichage**

Les textures sont chargées depuis des fichiers `.xpm` et appliquées sur les murs en fonction de l'orientation (nord, sud, est, ouest).

### 4. **Gestion des événements**

Le projet capture les touches suivantes :
- **W, A, S, D** : Déplacement du joueur.
- **← / →** : Rotation de la vue.
- **ESC** : Quitter le jeu.

---

## Gameplay

<div align="center">
  <img height="550" src="https://github.com/Kurama77190/CUB3D/blob/main/img/cub3d.gif?raw=true"  />
</div>

<div align="center">
  <img height="550" src="https://github.com/Kurama77190/CUB3D/blob/main/img/labyrinthe.gif?raw=true"  />
</div>

---

## Prérequis

Pour exécuter Cub3D, vous devez avoir :
- **Linux** ou **WSL** avec un serveur X (VcXsrv, Xming, ou MobaXterm sauf dans le cas de WSL 2).
- **Make** et **GCC** installés :
  ```bash
  sudo apt update
  sudo apt install build-essential libx11-dev libxext-dev libbsd-dev libxpm-dev

## 📝 Licence

Ce projet est sous licence [MIT](https://opensource.org/licenses/MIT).

