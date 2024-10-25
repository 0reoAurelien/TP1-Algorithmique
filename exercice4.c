
#include <stdio.h>
#include <stdlib.h>
#include "exercice4.h"
#include "utility.h"


void exercice4()
{
    printf("Je suis l'exercice 4\n");
    question4_1();
    question4_2();
}


void dfs_matrix(int v, int n, int adjMatrix[MAX][MAX], int visited[MAX], int component[MAX], int* componentSize);
void dfs_list(int v, Node* adjList[MAX], int visited[MAX], int component[MAX], int* componentSize);


void question4_1() { // Utilisation de la matrice d'adjacence
    int n, m;
    int adjMatrix[MAX][MAX] = {0}; // Matrice d'adjacence
    read_input_adjacency_matrix("INPCONGRAPH.txt", adjMatrix, &n, &m);

    int visited[MAX] = {0};
    int components[MAX][MAX];  // Stocke les sommets par composante
    int componentSizes[MAX] = {0}; // Taille de chaque composante
    int k = 0; // Nombre de composantes

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int component[MAX] = {0};
            int componentSize = 0;
            dfs_matrix(i, n, adjMatrix, visited, component, &componentSize);
            
            for (int j = 0; j < componentSize; j++) {
                components[k][j] = component[j];
            }
            componentSizes[k] = componentSize;
            k++;
        }
    }

    write_output_ex4("OUTCONGRAPH1.txt", components, componentSizes, k);
}


void question4_2() { // Utilisation de la liste d'adjacence
    int n, m;
    Node* adjList[MAX] = {NULL}; // Liste d'adjacence
    read_input_adjacency_list("INPCONGRAPH.txt", adjList, &n, &m);

    int visited[MAX] = {0};
    int components[MAX][MAX];  // Stocke les sommets par composante
    int componentSizes[MAX] = {0}; // Taille de chaque composante
    int k = 0; // Nombre de composantes

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int component[MAX] = {0};
            int componentSize = 0;
            dfs_list(i, adjList, visited, component, &componentSize);
            
            for (int j = 0; j < componentSize; j++) {
                components[k][j] = component[j];
            }
            componentSizes[k] = componentSize;
            k++;
        }
    }

    write_output_ex4("OUTCONGRAPH2.txt", components, componentSizes, k);
    freeAdjList(adjList, n);
}


void dfs_matrix(int v, int n, int adjMatrix[MAX][MAX], int visited[MAX], int component[MAX], int* componentSize) {
    visited[v] = 1;
    component[(*componentSize)++] = v + 1; // Stocke le sommet dans la composante
    for (int i = 0; i < n; i++) {
        if (adjMatrix[v][i] == 1 && !visited[i]) {
            dfs_matrix(i, n, adjMatrix, visited, component, componentSize);
        }
    }
}


void dfs_list(int v, Node* adjList[MAX], int visited[MAX], int component[MAX], int* componentSize) {
    visited[v] = 1;
    component[(*componentSize)++] = v + 1; // Ajoute le sommet à la composante
    
    Node* temp = adjList[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            dfs_list(temp->vertex, adjList, visited, component, componentSize);
        }
        temp = temp->next;
    }
}