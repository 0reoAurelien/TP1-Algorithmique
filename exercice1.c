#include "exercice1.h"
#include "utility.h"
#include "stdio.h"

void exercice1(){
    printf("Hello world\n");

    question1();
}

void question1(){
    
    int A[13] = {1, 2, 3, 4, 9, 10, 5, 6, 7, 3, 82, 1024, 12};
    int res[13] = {}; //res est la liste qui sera retournée en sortie


    if (sizeof(A)==0){ //cas d'une liste A vide
        //return res;
        return;
    }

    res[0] = A[0]; //ajouter le premier élément dans res 

    if (sizeof(A)==1){ //cas d'une liste A avec un seul élément
        //return res;
        return;
    }

    //cas d'une liste A d'au moins 2 éléments

    int runningIndex = 1;
    int element = A[0];
    int nextElement = A[1];

    int resIndex = 0;

    int lowerValue; // contiendra la valeur haute à comparer lors du parcours de la branche de droite
    int higherValue; // contiendra la valeur basse à comparer lors du parcours de la branche de gauche
    int leftLength; // contiendra la longueur de la branche de gauche
    int rightLength; // contiendra la longueur de la branche de droite


    while (runningIndex < 13-1){ 
        element = res[resIndex]; // element est le dernier élément ajouté dans res
        nextElement = A[runningIndex]; // nextElement est le prochain élément de la liste A susceptible d'être ajouté

        if (element < nextElement){ //tant que c'est croissant, on ajoute nextElement à la liste res
            resIndex++;
            res[resIndex] = nextElement;
            runningIndex++;            
        }
        else { //si on arrive à la fin d'une chaine de croissance, on regarde à gauche et à droite quelle chaine de croissance est plus longue
            higherValue = element;
            lowerValue = nextElement;

            leftLength = 0;
            while((element > lowerValue)&&(runningIndex != -1)){
                leftLength++;
                resIndex--;
                element = res[resIndex];
            }
            resIndex += leftLength;


            rightLength = 0;
            while((element < higherValue)&&(runningIndex != 0)){
                rightLength++;
                runningIndex++;
                element = A[runningIndex];
            }
            runningIndex -= rightLength;     

            if (leftLength < rightLength){
                resIndex -= leftLength;
                res[resIndex] = nextElement;
            }

            runningIndex++;
        }
    }

    //return res;
    return;
}


/*

Tant que les éléments sont croissant, append them to res

fin de monotonie :
enregistrer le maximum atteint précédemment

récupérer le minimum associable au premier élément suivant la rupture de monotonie

déterminer la longueur de la chaîne de gauche

construire la chaine de droite

calculer la longueur de la chaine de droite

conserver la chaine la plus longue et passer à l'élément

*/




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
