#include "exercice1.h"
#include <stdio.h>
#include <stdlib.h>


#define MAXN 5000

// Fonction pour lire les données depuis un fichier
void read_input_file(const char *filename, int *n, int arr[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier d'entrée.\n");
        exit(1);
    }
   
    // Lire le nombre d'éléments
    fscanf(file, "%d", n);
   
    // Lire les éléments de la séquence
    for (int i = 0; i < *n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
   
    fclose(file);
}

// Fonction pour écrire les résultats dans un fichier
void write_output_file(const char *filename, int lis_length, int lis_sequence[], int lis_indices[]) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier de sortie.\n");
        exit(1);
    }
   
    // Écrire la longueur de la plus longue sous-séquence croissante
    fprintf(file, "%d\n", lis_length);
   
    // Écrire chaque élément de la sous-séquence avec son indice
    for (int i = 0; i < lis_length; i++) {
        fprintf(file, "a[%d] = %d\n", lis_indices[i] + 1, lis_sequence[i]); // Indices 1-based
    }
   
    fclose(file);
}

// Fonction pour trouver la plus longue sous-séquence croissante
void lis(int n, int arr[], int *lis_length, int lis_sequence[], int lis_indices[]) {
    int dp[MAXN], prev[MAXN];
   
    // Initialisation
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        prev[i] = -1;
    }
   
    // Remplissage du tableau dp
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }
   
    // Trouver la longueur maximale de la sous-séquence croissante
    *lis_length = 0;
    int lis_index = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > *lis_length) {
            *lis_length = dp[i];
            lis_index = i;
        }
    }
   
    // Reconstruire la sous-séquence croissante
    int current_index = lis_index;
    int index = *lis_length - 1;
   
    while (current_index != -1) {
        lis_sequence[index] = arr[current_index];
        lis_indices[index] = current_index;
        index--;
        current_index = prev[current_index];
    }
}

int main() {
    int n;
    int arr[MAXN];
   
    // Lire les données du fichier d'entrée
    read_input_file("INPMONOSEQ.txt", &n, arr);
   
    int lis_length;
    int lis_sequence[MAXN], lis_indices[MAXN];
   
    // Trouver la plus longue sous-séquence croissante
    lis(n, arr, &lis_length, lis_sequence, lis_indices);
   
    // Écrire les résultats dans le fichier de sortie
    write_output_file("OUTMONOSEQ.TXT", lis_length, lis_sequence, lis_indices);
   
    return 0;
}
