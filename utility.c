
#include "utility.h"
#include "stdio.h"
#include "stdlib.h"


// Lecture des données depuis un fichier (exercice 1)
void read_input_ex1(const char* filename, int* sequence, int* n) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d", n);  // Lire le nombre d'éléments
    for (int i = 0; i < *n; i++) {
        fscanf(file, "%d", &sequence[i]);  // Lire chaque élément de la séquence
    }

    fclose(file);
}


// Lecture des données depuis un fichier (exercice 2)
void read_input_ex2(const char* filename, int* sequence, int* n, int* k) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d", n);  // Lire le nombre d'éléments
    fscanf(file, "%d", k);  // Lire le paramètre k
    for (int i = 0; i < *n; i++) {
        fscanf(file, "%d", &sequence[i]);  // Lire chaque élément de la séquence
    }

    fclose(file);
}


// Lecture des données depuis un fichier (exercice 2) pour une matricce d'adjacence
void read_input_adjacency_matrix(const char* filename, int adjMatrix[MAX][MAX], int* n, int* m) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d %d", n, m);

    // Lecture des arêtes
    for (int i = 0; i < *m; i++) {
        int u, v;
        fscanf(file, "%d %d", &u, &v);
        adjMatrix[u - 1][v - 1] = 1;
        adjMatrix[v - 1][u - 1] = 1; // Graphe non orienté
    }

    fclose(file);
}


// Lecture des données depuis un fichier (exercice 2) pour une liste d'adjacence
void read_input_adjacency_list(const char* filename, Node *adjList[MAX], int* n, int* m) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d %d", n, m);

    // Initialiser les listes d'adjacence à NULL
    for (int i = 0; i < *n; i++) {
        adjList[i] = NULL;
    }

    // Lecture des arêtes
    for (int i = 0; i < *m; i++) {
        int u, v;
        fscanf(file, "%d %d", &u, &v);

        // Ajustement des indices pour démarrer à 0
        u -= 1;
        v -= 1;

        // Ajouter `v` dans la liste d'adjacence de `u`
        addEdgeToList(u, v, &adjList[u]);

        // Ajouter `u` dans la liste d'adjacence de `v` (graphe non orienté)
        addEdgeToList(v, u, &adjList[v]);
    }

    fclose(file);
}


// Lecture des données depuis un fichier (exercice 2) pour une matricce d'adjacence
void read_input_adjacency_matrix_ex5(const char* filename, int adjMatrix[MAX][MAX], int* n, int* m, int* start, int* end) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d %d %d %d", n, m, start, end);
    (*start)--;  // Ajuster les indices pour démarrer à 0
    (*end)--;

    // Initialiser la matrice avec des valeurs infinies
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            adjMatrix[i][j] = (i == j) ? 0 : MAX;
        }
    }

    // Lecture des arêtes et poids
    for (int i = 0; i < *m; i++) {
        int u, v, weight;
        fscanf(file, "%d %d %d", &u, &v, &weight);
        adjMatrix[u - 1][v - 1] = weight;
        adjMatrix[v - 1][u - 1] = weight;  // Graphe non orienté
    }

    fclose(file);
}


// Écriture des résultats dans un fichier (exercice 1)
void write_output_ex1(const char* filename, int* lis, int lis_length, int* indexTable) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%d\n", lis_length);  // Écrire la longueur de la LIS
    for (int i = 0; i < lis_length; i++) {
        if (i > 0) fprintf(file, "\n");
        fprintf(file, "a[%d] = %d", indexTable[i], lis[i]);  // Écrire chaque élément de la LIS
    }
    fprintf(file, "\n");

    fclose(file);
}


// Écriture des résultats dans un fichier (exercice 2)
void write_output_ex2(const char* filename, int* A, int aSize, int* bestRemovedIndexList, int bestDepth, int resSize) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%d\n", resSize);  // Écrire la longueur de la séquence

    // Affichages des éléments retenus et calcul de la somme de ces éléments
    int sum = 0;
    int removedIndex; // Variable pour vérifier si l'indice est un élément retiré ou non
    for (int i = 0; i < aSize; i++){
        removedIndex = 0;
        for (int j = 0; j < bestDepth; j++){
            if (i == bestRemovedIndexList[j]){
                removedIndex = 1;
                break;
            }
        }
        if (!removedIndex){
            sum += A[i];
            if (i > 0) fprintf(file, "\n");
            fprintf(file, "a[%d] = %d", i, A[i]);  // Écrire chaque élément de la LIS
        }
    }

    fprintf(file, "\n");
    // Afficher la somme des éléments
    fprintf(file, "Sum = %d\n", sum);
    fclose(file);
}


void write_output_ex3(const char *filename, int *res, int resSize)
{
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier %s\n", filename);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < resSize/2; i++)
        fprintf(file, "%d %d\n", res[2*i], res[2*i+1]); // Écrire les arêtes de l'arbre couvrant
    fclose(file);
}


void write_output_ex4(const char* filename, int components[MAX][MAX], int componentSizes[MAX], int k)
{
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Erreur d'ouverture du fichier");
        exit(1);
    }
    fprintf(file, "%d\n", k); // Nombre de composantes
    for (int i = 0; i < k; i++) {
        fprintf(file, "Composante connexe %d:\n", i + 1);
        for (int j = 0; j < componentSizes[i]; j++) {
            fprintf(file, "%d ", components[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}


// Écriture du résultat dans le fichier
void write_output_ex5(const char* filename, int distance, int path[], int pathSize) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%d\n", distance);  // Écrire la distance
    for (int i = 0; i < pathSize; i++) {
        fprintf(file, "%d", path[i] + 1);  // Revenir aux indices de départ
        if (i < pathSize - 1) fprintf(file, " -> ");
    }
    fprintf(file, "\n");

    fclose(file);
}


void addEdgeToList(int u, int v, Node** adjListPosition) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = *adjListPosition;
    *adjListPosition = newNode;
}


void freeAdjList(Node** adjList, int n) {
    for (int i = 0; i < n; i++) {
        Node* current = adjList[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}


int find(int x, int* parent) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}


void unionSets(int x, int y, int* parent) {
    int rootX = find(x, parent);
    int rootY = find(y, parent);
    if (rootX != rootY) {
        parent[rootX] = rootY;
    }
}


void makeSet(int n, int* parent) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

