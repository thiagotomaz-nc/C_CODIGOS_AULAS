/*
    crie um programa em linguagem c que cria um vetor inteiro de 10 elementos sem repetição,
    cujos os numeros são gerados aleatoriamente entre 0 e 20;
    
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

int main (void){
   
    srand(time(NULL)); // semente do rand;
    int vetor[N];
    int numeros_inseridos = 0;
    int numero ;    
    int existe_numero = 0; // o zero corresponde a falso
    

    printf("\nNumeros gerados -> ");
    do {
        numero = rand() % 21;
        existe_numero = 0;
        printf("%i ", numero);
        for (int i = 0; i<N;i++){
            if (numero == vetor[i]){
                existe_numero = 1; // numero ja existe no vetor -> corresponde ao existe.
                break;
            }

        }

        if (!existe_numero){
            vetor[numeros_inseridos] = numero;
             numeros_inseridos++;
        }else{

        }

    }while(numeros_inseridos < N);

    printf("\n");

    printf("VETOR -> ");
    for (int i = 0; i< N;i++){
        
        printf("%i ", vetor[i]);
    }

    
    printf("\n ");

    return 0;
}