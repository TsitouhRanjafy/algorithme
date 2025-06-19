# Validation de Mot

Ce projet implémente un algorithme qui valide un mot selon des règles spécifiques.

## Description
L'algorithme prend en entrée une chaîne de caractères et retourne :
- `1` si la chaîne respecte toutes les contraintes
- `0` si elle enfreint au moins une contrainte

## Contraintes
Le mot doit respecter les règles suivantes :
1. Il doit contenir uniquement les lettres `m` et `a`.
2. Sa longueur maximale est de **49 caractères**.
3. Il doit commencer par la lettre **'m'**.
4. Il ne doit pas y avoir de répétition immédiate d'une même lettre (ex: `mamaa` est invalide).
5. La longueur minimale du mot est **4** caractères (`"mama"`).

## Exemple

input:`'mamamamamam'`   
output: **1**

input: `mamamaa`   
output: **0**