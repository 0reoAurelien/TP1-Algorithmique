
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

// Écriture des résultats dans un fichier (exercice 1)
void write_output_ex1(const char* filename, int* lis, int lis_length) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%d\n", lis_length);  // Écrire la longueur de la LIS
    for (int i = 0; i < lis_length; i++) {
        if (i > 0) fprintf(file, "\n");
        fprintf(file, "res[%d] = %d", i, lis[i]);  // Écrire chaque élément de la LIS
    }
    fprintf(file, "\n");

    fclose(file);
}


// Écriture des résultats dans un fichier (exercice 2)
void write_output_ex2(const char* filename, int* lis, int lis_length) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%d\n", lis_length);  // Écrire la longueur de la LIS
    for (int i = 0; i < lis_length; i++) {
        if (i > 0) fprintf(file, "\n");
        fprintf(file, "res[%d] = %d", i, lis[i]);  // Écrire chaque élément de la LIS
    }
    fprintf(file, "\n");
    // Calculer et afficher la somme des éléments
    int sum = 0;
    for (int i = 0; i < lis_length; i++){
        sum += lis[i];
    }
    fprintf(file, "Sum = %d", sum);
    fclose(file);
}


void print_tab(int *tab, int sizeOfTab){
    for (int i = 0; i < sizeOfTab; i++){
        printf("element %i : %i", i, *(++tab));
    }
}


void empty_tab(int *tab, int sizeOfTab)
{
    for (int i = 0; i < sizeOfTab; i++){
        //popen(tab);
    }
}
