
#include "utility.h"
#include "stdio.h"
#include "stdlib.h"

// Lecture des données depuis un fichier
void read_input(const char* filename, int* sequence, int* n) {
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

// Écriture des résultats dans un fichier
void write_output(const char* filename, int* lis, int lis_length) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%d\n", lis_length);  // Écrire la longueur de la LIS
    for (int i = 0; i < lis_length; i++) {
        if (i > 0) fprintf(file, " ");
        fprintf(file, "%d", lis[i]);  // Écrire chaque élément de la LIS
    }
    fprintf(file, "\n");

    fclose(file);
}

void empty_tab(int *tab, int sizeOfTab)
{
    for (int i = 0; i < sizeOfTab; i++){
        //popen(tab);
    }
}
