#include "exercice5.h"
#include <stdio.h>
#include <stdbool.h>
#include "utility.h"


int minDistance(int dist[], bool sptSet[], int n);
void dijkstra(int adjMatrix[MAX][MAX], int n, int start, int end, int* shortestDistance, int path[MAX], int* pathSize);


void exercice5() {
    printf("Je suis l'exercice 5\n");
    question5_1();
}

void question5_1() {
    int adjMatrix[MAX][MAX];
    int n;
    int m;
    int start;
    int end;
    int shortestDistance;
    int path[MAX];
    int pathSize;

    // Lecture
    read_input_adjacency_matrix_ex5("INPDIJGRAPH.txt", adjMatrix, &n, &m, &start, &end);

    // Calcul du plus court chemin
    dijkstra(adjMatrix, n, start, end, &shortestDistance, path, &pathSize);

    // Écriture des résultats
    write_output_ex5("OUTDIJGRAPH.txt", shortestDistance, path, pathSize);
}


// Trouve le sommet avec la distance minimale dans le tableau dist
int minDistance(int dist[], bool sptSet[], int n) {
    int min = MAX, min_index;
    for (int v = 0; v < n; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

// Algorithme de Dijkstra pour la matrice
void dijkstra(int adjMatrix[MAX][MAX], int n, int start, int end, int* shortestDistance, int path[MAX], int* pathSize) {
    int dist[MAX], parent[MAX];
    bool sptSet[MAX];

    // Initialiser les distances et sptSet
    for (int i = 0; i < n; i++) {
        dist[i] = MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }
    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);
        sptSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && adjMatrix[u][v] && dist[u] != MAX && dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }

    *shortestDistance = dist[end];

    // Reconstruction du chemin
    *pathSize = 0;
    for (int v = end; v != -1; v = parent[v])
        path[(*pathSize)++] = v;

    // Inverser le chemin
    for (int i = 0; i < *pathSize / 2; i++) {
        int temp = path[i];
        path[i] = path[*pathSize - 1 - i];
        path[*pathSize - 1 - i] = temp;
    }
}
