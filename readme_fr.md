
# Push Swap

## Table des matières

  - [Introduction](#introduction)
  - [Fonctionnalités](#fonctionnalités)
  - [Structure des données](#structure-des-données)
  - [Algorithme](#algorithme)
  - [Liste des fonctions](#liste-des-fonctions)
  - [Bonus](#bonus)

## Introduction

**Push Swap** est un projet en C qui consiste à créer un programme permettant de trier une pile d'entiers en utilisant un nombre minimal d'opérations. Les opérations disponibles sont `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb` et `rrr`. L'objectif de ce projet est de développer un algorithme efficace pour trier, comprendre les opérations sur les piles et améliorer ses compétences en résolution de problèmes. L'algorithme de tri doit être aussi optimisé que possible, et aucun autre nombre d'opérations que celui nécessaire ne doit être utilisé.

En terminant **Push Swap**, vous apprendrez les structures de données de pile, l'importance de l'optimisation des algorithmes et vous acquerrez de l'expérience en résolution de problèmes et optimisation des performances.

## Fonctionnalités

- Implémente un algorithme de tri utilisant des opérations basées sur des piles.
- Fournit une solution optimisée pour trier les entiers.
- Inclut un ensemble d'opérations (`sa`, `sb`, `pa`, `pb`, etc.) pour manipuler les piles.

## Liste des fonctions

- `sa` - Échanger les deux premiers éléments de la pile A.
- `sb` - Échanger les deux premiers éléments de la pile B.
- `pa` - Pousser le premier élément de la pile B vers la pile A.
- `pb` - Pousser le premier élément de la pile A vers la pile B.
- `ra` - Faire pivoter la pile A (déplacer le premier élément vers le bas).
- `rb` - Faire pivoter la pile B (déplacer le premier élément vers le bas).
- `rr` - Faire pivoter les piles A et B.
- `rra` - Faire pivoter inversément la pile A (déplacer le dernier élément vers le haut).
- `rrb` - Faire pivoter inversément la pile B (déplacer le dernier élément vers le haut).
- `rrr` - Faire pivoter inversément les piles A et B.

## Structure des données
**Liste doublement chaînée**

Dans le projet **Push Swap**, une **liste doublement chaînée** est couramment utilisée pour représenter la pile. Une liste doublement chaînée est un type de structure de données où chaque élément (nœud) contient une référence (ou lien) à ses éléments suivant et précédent, ce qui la distingue d'une liste simplement chaînée qui ne pointe que vers l'élément suivant.

### Qu'est-ce qu'une liste doublement chaînée ?

Une **liste doublement chaînée** est une liste de nœuds, où chaque nœud contient trois composants clés :
1. **Données** : La valeur stockée dans le nœud.
2. **Next** : Une référence (ou pointeur) vers le nœud suivant dans la liste.
3. **Prev** : Une référence (ou pointeur) vers le nœud précédent dans la liste.

Cette structure permet une traversée dans les deux sens : avant et arrière.

### Comment fonctionne une liste doublement chaînée ?

1. **Structure d'un nœud** :
   Chaque nœud d'une liste doublement chaînée se compose des éléments suivants :
   - **Données** : La valeur de l'élément (par exemple, l'entier dans la pile **Push Swap**).
   - **Next** : Un pointeur/référence vers le nœud suivant dans la liste.
   - **Prev** : Un pointeur/référence vers le nœud précédent dans la liste.
   
   Voici une illustration simple d'un nœud dans une liste doublement chaînée :

   ```
   [Prev | Data | Next]
   ```

2. **Avantages d'une liste doublement chaînée** :
   - **Traversée bidirectionnelle** : Vous pouvez naviguer dans les deux sens de la liste, ce qui facilite la manipulation dans les deux directions lors des opérations comme `push`, `swap` et `rotate` dans le projet **Push Swap**.
   - **Insertions/Destructions efficaces** : L'insertion et la suppression de nœuds peuvent être effectuées efficacement en temps constant, surtout si le nœud est déjà connu (en utilisant les références `next` et `prev`).
   - **Opérations flexibles** : Vous pouvez facilement effectuer des opérations comme l'échange de deux éléments en manipulant les pointeurs `next` et `prev` sans avoir besoin de traverser toute la liste.

3. **Opérations sur la liste doublement chaînée** :

   - **Push** :
     Dans le projet **Push Swap**, une opération de push signifie transférer un élément d'une pile (liste chaînée) vers une autre. Lorsque un élément est poussé de la pile A vers la pile B ou inversement, cela se fait en ajustant les pointeurs `next` et `prev` des nœuds.
   
   - **Swap** :
     Une opération d'échange consiste à échanger les deux premiers éléments de la pile. Pour une liste doublement chaînée, cela se fait en ajustant les pointeurs `next` et `prev` des deux nœuds.

   - **Rotate** :
     Une opération de rotation déplace le premier élément de la pile vers le bas. Elle implique :
     - Mettre à jour le pointeur `next` du nœud supérieur actuel pour qu'il pointe vers le `NULL` (nouveau dernier).
     - Rendre le nœud supérieur actuel le dernier en ajustant le pointeur `prev` du nouveau dernier à `NULL`.

   - **Reverse Rotate** :
     La rotation inversée est l'opposée de la rotation. Elle consiste à déplacer le dernier élément de la pile vers le haut :
     - Le dernier nœud devient le nouveau premier.
     - Le pointeur `next` du nouveau dernier nœud pointe vers l'ancien premier.

4. **Gestion de la mémoire** :
   - Dans une liste doublement chaînée, la gestion correcte de la mémoire est cruciale. Lorsque des nœuds sont supprimés, la mémoire doit être libérée pour éviter les fuites de mémoire.

### Exemple de liste doublement chaînée dans Push Swap

Voici à quoi pourrait ressembler une simple liste doublement chaînée représentant une pile dans **Push Swap** :

```
[Prev | 10 | Next] ↔ [Prev | 20 | Next] ↔ [Prev | 30 | Next]
```

---

### Pourquoi utiliser une liste doublement chaînée dans **Push Swap** ?

Dans **Push Swap**, la pile de nombres doit être triée à l'aide de diverses opérations. La structure de liste doublement chaînée offre une manière flexible de mettre en œuvre ces opérations de manière efficace. Elle permet de :
- Une traversée facile et rapide dans les deux sens.
- Des opérations d'ajout, d'échange, de rotation et de rotation inversée efficaces.
- Une manipulation simplifiée de la pile lors de l'exécution de plusieurs opérations simultanément.

## Algorithme

1. **Pousser les deux premiers nombres** :
   - Commencez par pousser deux nombres de **STACK_A** vers **STACK_B** sans rien vérifier. Cela aide à configurer la pile initiale.

2. **Trouver le nombre le moins cher** :
   - Après le push initial, commencez à calculer le coût (nombre d'opérations) pour déplacer chaque nombre dans sa position correcte dans **STACK_B**.

3. **Pousser le nombre le moins cher** :
   - Continuez ce processus en sélectionnant toujours le nombre le moins cher.

4. **Gérer les trois derniers éléments** :
   - Une fois que vous atteignez les trois derniers éléments, le tri devient plus simple.

5. **Pousser de retour dans **STACK_A** :
   - Une fois triés dans **STACK_B**, commencez à les remettre dans **STACK_A**.

6. **Ajustement final** :
   - Assurez-vous que le plus petit nombre soit en haut de la pile **STACK_A**.

## Bonus

- Algorithme de tri optimisé utilisant des opérations sur les piles.
- Prend en charge les cas limites, tels que le tri de petites ou grandes tailles d'entrée.
- Fournit des opérations supplémentaires pour une manipulation efficace des piles.

---
