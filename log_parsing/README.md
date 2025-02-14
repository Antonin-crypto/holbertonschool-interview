# Log File Processor

Ce script lit les lignes d'un fichier de log au format suivant :

Il calcule la taille totale des fichiers et le nombre de lignes pour chaque code de statut (200, 301, 400, 401, 403, 404, 405, 500). Les statistiques sont affichées toutes les 10 lignes et lors d'une interruption par CTRL + C.

## Prérequis

- Python 3.x

## Exécution

1. Rendre le script exécutable :
2. Exécuter le script avec un fichier de log ou via `stdin` :
   ou entrer manuellement des lignes.

## Exemple

L'exécution après 10 lignes pourrait ressembler à ceci :
