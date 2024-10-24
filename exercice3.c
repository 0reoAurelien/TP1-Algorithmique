#include <stdio.h>
#include <stdlib.h>
#include "exercice3.h"
#include "utility.h"


void exercice3() {
    printf("Je suis l'exercice 3\n");    
    question3_1();
    question3_2();
}


void question3_1() { // Avec la matrice d'adjacence


    int n;
    int m;

    int adjMatrix[MAX][MAX] = {0}; // Matrice d'adjacence

    read_input_adjacency_matrix("INPARBGRAPH.txt", adjMatrix, &n, &m);

    // Structure pour l'Union-Find
    int parent[MAX];
    makeSet(n, parent);

    int res[MAX];
    int resSize = 0;

    // Parcours de la matrice pour trouver un arbre couvrant
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adjMatrix[i][j] == 1 && find(i, parent) != find(j, parent)) {
                // Ajout dans "res" des arêtes de l'arbre couvrant
                res[resSize++] = i+1;
                res[resSize++] = j+1;
                unionSets(i, j, parent); // Union des ensembles
            }
        }
    }
    write_output_ex3("OUTARBGRAPH1.txt", res, resSize);
}

void question3_2(){ // Avec la liste d'adjacence

    Node* adjList[MAX]; // Liste d'adjacence

    int n;
    int m;

    read_input_adjacency_matrix("INPARBGRAPH.txt", adjList, &n, &m);

    // Structure pour l'Union-Find
    int parent[MAX];
    makeSet(n, parent);

    int res[MAX];
    int resSize = 0;

    // Parcourir la liste d'adjacence
    for (int i = 0; i < n; i++) {
        Node* temp = adjList[i];
        while (temp != NULL) {
            int v = temp->vertex;
            if (find(i, parent) != find(v, parent)) {
                // Ajout dans "res" des arêtes de l'arbre couvrant
                res[resSize++] = i+1;
                res[resSize++] = v+1;
                unionSets(i, v, parent); // Union des ensembles
            }
            temp = temp->next;
        }
    }

    write_output_ex3("OUTARBGRAPH2.txt", res, resSize);

    // Libérer la mémoire allouée pour la liste d'adjacence
    freeAdjList(adjList, n);
}

