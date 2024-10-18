#include "exercice1.h"
#include "utility.h"
#include "stdio.h"
#define MAX_N 100

void exercice1(){
    printf("Je suis l'exercice 1\n");
    question1_1();
}

void question1_1() {
    int A[MAX_N];
    int aSize;

    // Lire les valeurs du tableau A depuis le fichier INPMONOSEQ.txt
    read_input_ex1("INPMONOSEQ.txt", A, &aSize);

    //int aSize = sizeof(A) / sizeof(A[0]);

    if (aSize == 0) {  // Cas d'une liste vide
        printf("Liste vide.\n");
        return;
    }

    // Tableau dp où dp[i] sera la longueur de la plus longue sous-séquence croissante jusqu'à l'élément i
    int dp[aSize];
    int previous[aSize];  // Pour stocker les indices précédents afin de reconstruire la séquence
    int maxLength = 1;  // La longueur de la plus longue sous-séquence
    int maxIndex = 0;  // Index de fin de la plus longue sous-séquence croissante

    // Initialisation : chaque élément est une sous-séquence croissante de longueur 1
    for (int i = 0; i < aSize; i++) {
        dp[i] = 1;
        previous[i] = -1;  // Aucun élément précédent au début
    }

    // Parcourir la liste pour remplir le tableau dp
    for (int i = 1; i < aSize; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                previous[i] = j;  // Stocker l'index précédent
            }
        }
        // Mettre à jour la longueur maximale et l'index correspondant
        if (dp[i] > maxLength) {
            maxLength = dp[i];
            maxIndex = i;
        }
    }

    // Reconstruction de la plus longue sous-séquence croissante
    int lis[maxLength];
    int k = maxLength - 1;
    int currentIndex = maxIndex;

    while (currentIndex != -1) {
        lis[k] = A[currentIndex];
        k--;
        currentIndex = previous[currentIndex];
    }

    // Écrire les résultats dans le fichier OUTMONOSEQ.TXT
    write_output_ex1("OUTMONOSEQ.txt", lis, maxLength);
}

