
#include "exercice2.h"
#include "utility.h"
#include "stdio.h"
#define MAX_N 100

int checksum(int* A, int* removedIndexList, int indexListSize, int aSum, int k);
void recFind(int* A, int aSize, int* removedIndexList, int depth, int aSum, int k, int* bestRemovedIndexList, int* bestDepth);

void exercice2(){
    printf("Je suis l'exercice 2\n");
    question2_1();
}

void question2_1(){
    int k;
    int A[MAX_N];
    int aSize;
    
    // Lire les valeurs du tableau A depuis le fichier INPDIVSEQ.txt
    read_input_ex2("INPDIVSEQ.txt", A, &aSize, &k);

    //int aSize = sizeof(A) / sizeof(A[0]);

    // Initialisation
    int removedIndexList[aSize];
    int bestRemovedIndexList[aSize];
    int aSum = 0;
    int bestDepth = aSize;
    for (int i = 0; i < aSize; i++){
        removedIndexList[i] = -1;  // -1 pour indiquer que cet indice n'est pas encore utilisé
        bestRemovedIndexList[i] = -1;  // Initialiser avec -1
        aSum += A[i];
    }

    if (k == 0){ // cas d'une division par 0
        printf("Vous essayez de diviser par 0 : pas de résultat.\n");
        return;
    }

    if (aSize == 0){ // cas d'une liste A vide
        printf("Tableau vide.\n");
        return;
    }

    // Appel de la fonction récursive pour chercher le meilleur sous-ensemble
    recFind(A, aSize, removedIndexList, 0, aSum, k, bestRemovedIndexList, &bestDepth);

    // Construire et afficher le résultat
    int resSize = aSize - bestDepth; 
    int res[resSize];
    
    
    int removedIndex; // Variable pour vérifier si l'indice est un élément retiré ou non
    int count = 0; // Indice pour écrire les valeurs dans res
    /*
    for (int i = 0; i < aSize; i++){
        removedIndex = 0;
        for (int j = 0; j < bestDepth; j++){
            if (i == bestRemovedIndexList[j]){
                removedIndex = 1;
                break;
            }
        }
        if (!removedIndex){
            res[count] = A[i];
            printf("%d ", res[count]);
            count++;
        }
    }
    */

    // Écrire les résultats dans le fichier OUTDIVSEQ.txt
    write_output_ex2("OUTDIVSEQ.txt", A, aSize, bestRemovedIndexList, bestDepth, resSize);

    return;
}

int checksum(int* A, int* removedIndexList, int removedIndexListSize, int aSum, int k){
    for (int i = 0; i < removedIndexListSize; i++){
        aSum -= A[removedIndexList[i]];
    }
    return (aSum % k == 0);
}

void recFind(int* A, int aSize, int* removedIndexList, int depth, int aSum, int k, int* bestRemovedIndexList, int* bestDepth){
    if (depth > *bestDepth){
        return; // Ne pas continuer si on a déjà trouvé une meilleure solution
    }
    else if (checksum(A, removedIndexList, depth, aSum, k)){
        *bestDepth = depth;
        for (int i = 0; i < depth; i++){
            bestRemovedIndexList[i] = removedIndexList[i];
        }
    }
    else{
        for (int j = 0; j < aSize; j++){
            // Vérifier si l'indice a déjà été retiré
            int alreadyRemoved = 0;
            for (int i = 0; i < depth; i++) {
                if (removedIndexList[i] == j) {
                    alreadyRemoved = 1;
                    break;
                }
            }
            if (!alreadyRemoved){
                removedIndexList[depth] = j;  // Utiliser depth comme niveau actuel
                recFind(A, aSize, removedIndexList, depth + 1, aSum, k, bestRemovedIndexList, bestDepth);
            }
        }        
    }
}
