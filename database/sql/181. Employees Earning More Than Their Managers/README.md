# 181. Employees Earning More Than Their Managers

**Difficulté :** Facile

---

## Table : Employee

| Column Name | Type |
| :--- | :--- |
| id | int |
| name | varchar |
| salary | int |
| managerId | int |

`id` est la clé primaire (colonne avec des valeurs uniques) pour cette table. Chaque ligne de cette table indique l'ID d'un employé, son nom, son salaire et l'ID de son responsable (`managerId`).

---

## Instruction

Écrivez une solution pour trouver les **employés qui gagnent plus que leurs responsables**.

Retournez la table de résultats dans n'importe quel ordre.

---

### Exemple 1:

**Input (Table Employee) :**

| id | name | salary | managerId |
| :---: | :---: | :---: | :---: |
| 1 | Joe | 70000 | 3 |
| 2 | Henry | 80000 | 4 |
| 3 | Sam | 60000 | Null |
| 4 | Max | 90000 | Null |

**Output :**

| Employee |
| :---: |
| Joe |

**Explication :** Joe est le seul employé qui gagne plus que son responsable.