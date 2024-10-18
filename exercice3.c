#include <stdio.h>
#include <stdlib.h>
#include "exercice3.h"

#define MAX 100

void makeSet(int n);
int find(int x);
void unionSets(int x, int y);
void addEdge(int u, int v);
void freeAdjList(int n);


typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX]; // Liste d'adjacence
// Structure pour l'Union-Find
int parent[MAX];



void exercice3() {
    printf("Je suis l'exercice 3\n");    
    question3_1();
    //question3_2();
}


void question3_1() {
    FILE *inFile = fopen("INPARBGRAPH.txt", "r");
    FILE *outFile = fopen("OUTARBGRAPH1.txt", "w");
    
    if (inFile == NULL || outFile == NULL) {
        printf("Erreur d'ouverture de fichier.\n");
        return;
    }

    int n;
    int m;
    fscanf(inFile, "%d %d", &n, &m);

    int adjMatrix[MAX][MAX] = {0}; // Matrice d'adjacence

    // Lecture des arêtes
    for (int i = 0; i < m; i++) {
        int u, v;
        fscanf(inFile, "%d %d", &u, &v);
        adjMatrix[u - 1][v - 1] = 1;
        adjMatrix[v - 1][u - 1] = 1; // Graphe non orienté
    }

    makeSet(n);

    // Parcours de la matrice pour trouver un arbre couvrant
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adjMatrix[i][j] == 1 && find(i) != find(j)) {
                fprintf(outFile, "%d %d\n", i + 1, j + 1); // Écrire les arêtes de l'arbre couvrant
                unionSets(i, j); // Union des ensembles
            }
        }
    }

    fclose(inFile);
    fclose(outFile);
}

void question3_2(){
    FILE *inFile = fopen("INPARBGRAPH.txt", "r");
    FILE *outFile = fopen("OUTARBGRAPH2.txt", "w");
    
    if (inFile == NULL || outFile == NULL) {
        printf("Erreur d'ouverture de fichier.\n");
        return;
    }

    int n;
    int m;
    fscanf(inFile, "%d %d", &n, &m);

    // Initialiser les listes d'adjacence à NULL
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }

    // Lecture des arêtes
    for (int i = 0; i < m; i++) {
        int u;
        int v;
        fscanf(inFile, "%d %d", &u, &v);
        addEdge(u - 1, v - 1); // Graphe non orienté
        addEdge(v - 1, u - 1);
    }

    makeSet(n);

    // Parcourir la liste d'adjacence
    for (int i = 0; i < n; i++) {
        Node* temp = adjList[i];
        while (temp != NULL) {
            int v = temp->vertex;
            if (find(i) != find(v)) {
                fprintf(outFile, "%d %d\n", i + 1, v + 1); // Écrire l'arête dans l'arbre couvrant
                unionSets(i, v);
            }
            temp = temp->next;
        }
    }

    // Libérer la mémoire allouée pour la liste d'adjacence
    freeAdjList(n);

    fclose(inFile);
    fclose(outFile);
}


void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootX] = rootY;
    }
}

void addEdge(int u, int v) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

void freeAdjList(int n) {
    for (int i = 0; i < n; i++) {
        Node* current = adjList[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}
