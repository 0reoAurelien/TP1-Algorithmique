#include "exercice1.h"
#include "utility.h"
#include "stdio.h"

void exercice1(){
    printf("Hello world\n");

    question1();
}

void question1(){
    
    int A[10] = {3, 1, 2, 3, 4, 9, 10, 5, 6, 7};

/*

Tant que les éléments sont croissant, append them to res

fin de monotonie :



*/



    int tree[] = {};
    int temp[] = {};

    for (int i = 0; i < sizeof(A); i++){
        empty_tab(temp, sizeof(temp));

    }

}


void question1_bis(){
    int MAX_N = 1;
    int n;                              // Nombre d'éléments dans la séquence
    int sequence[MAX_N];                // La séquence d'entrée
    int lis[MAX_N];                     // La plus longue sous-séquence croissante
    int lis_length;                     // Longueur de la LIS

    // Lire les données depuis le fichier INPMONOSEQ.TXT
    //read_input("INPMONOSEQ.TXT", sequence, &n);

    // Calculer la plus longue sous-séquence croissante
    //longest_increasing_subsequence(sequence, n, &lis_length, lis);

    for (int i = 0; i < lis_length; i++){
        printf("(%i): %i;\n", lis_length, lis[i]);
    }

    // Écrire les résultats dans le fichier OUTMONOSEQ.TXT
    write_output("OUTMONOSEQ.TXT", lis, lis_length);

}
