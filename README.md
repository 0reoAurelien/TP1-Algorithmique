# TP Algorithmique :  
TRIAS Nathan, POINSEL Aurélien

> **Question 1 :**  
>> La question 1 est dans *exercice1.c* lié au header *exercice1.h*. Le plus gros problème rencontré ici est le cas où le premier chiffre de la liste était plus grand que la suite. Le changement de structure du code nous a permis de contourner ce problème. Ce changement a été le passage à une programmation dynamique, ce qui a stabilisé le code.

> **Question 2 :**  
>> Sur cette question, nous n'avons pas eu de problème particulier. Le code s’est exécuté comme attendu dès les premiers tests. Les résultats étaient corrects et le code est resté stable et simple.

> **Question 3 :**  
>> Cette question portait sur l'exploration des composantes connexes d'un graphe avec une matrice et une liste d’adjacence. Nous avons utilisé un parcours en profondeur (DFS), qui s'est révélé efficace pour cette tâche. La principale difficulté a été la gestion précise des indices dans la liste d’adjacence, ce qui a pris quelques ajustements. 

>> Une fois ces détails réglés, le code a pu détecter et stocker les composantes connexes sans problème. Quelques erreurs de segmentation sont apparues lors des premiers essais en raison d'allocations incorrectes, mais ces erreurs ont été corrigées en vérifiant chaque allocation et libération de mémoire.

> **Question 4 :**  
>> Pour cette question, nous devions structurer et afficher les différentes composantes connexes d'un graphe dans le fichier de sortie. Cela nous a demandé un ajustement du code précédent pour bien organiser l'affichage des résultats.

>> Une difficulté a été d'optimiser le format d’écriture dans le fichier de sortie, en particulier pour les indices des composantes. Après avoir révisé la façon de structurer la sortie, les résultats étaient affichés de manière claire et précise.

> **Question 5 :**  
>> La première partie de la question 5 portait sur l'utilisation de la matrice d'adjacence pour calculer le plus court chemin dans un graphe pondéré. Nous avons implémenté l'algorithme de Dijkstra en utilisant cette structure, qui est efficace mais gourmande en mémoire pour les grands graphes.

>> L’algorithme a été capable de trouver les chemins les plus courts comme attendu. La gestion de la priorité des sommets dans la matrice n’a pas posé de difficulté majeure, mais la mise en place du format de sortie (pour afficher le chemin et la distance) a demandé quelques ajustements.

> **Conclusion générale :**  
>> Ce TP nous a permis d'explorer plusieurs structures de données et algorithmes classiques, comme les matrices et les listes d'adjacence, ainsi que l'algorithme de Dijkstra. À chaque question, nous avons été confrontés à des défis différents, notamment en gestion de mémoire et en optimisation des structures de données. 

>> Nous avons pu stabiliser et finaliser la majorité des fonctions après plusieurs tests. Le code est opérationnel pour tous les cas testés, et les résultats sont conformes aux attentes. Nous avons simplement manqué de temps pour aborder les différentes structures de données dans l'exercice 5, o`u nous avons donc dû nous limiter aux matrices d'adjacence.
