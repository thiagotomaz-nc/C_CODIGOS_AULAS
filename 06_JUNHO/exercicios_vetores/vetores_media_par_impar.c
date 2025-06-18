/*
    crie um programa em c que gere aleatoriamente 20 numeros inteiros
    entre o 0 e 100. O programa deve calcular e exibir a média dos 
    valores PARES e a média dos valores IMPARES. Ao final, devem
    ser exibidos os números pares maiores que a média PAR e os números
    ímpares menores que a média IMPAR.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 6

int main(void){
    
    int vetor[N];

    int quant_pares = 0, quant_impares = 0, somatorio_par = 0, somatorio_impar = 0;
    double media_par, media_impar;

    srand(time(NULL));

    for (int i = 0; i<N;i++){
        vetor[i] = rand() % 101;
    }

    printf("\n");

    printf("Numeros do vetor -> ");
    for (int i = 0; i< N;i++){

        printf("%i -> %i: ", i+1, vetor[i]);

        if(vetor[i] % 2 == 0){
            quant_pares++;
            somatorio_par += vetor[i];
        }else{
            somatorio_impar += vetor[i];
            quant_impares++;
        }
    }

    media_par = (double) somatorio_par / quant_pares;
    media_impar = (double) somatorio_impar / quant_impares;

    printf("\n\n");
    printf("###############################################");
    printf("\n===MEDIA DOS PARES ==> %.2lf", media_par);
    printf("\n===MEDIA DOS IMPARES ==> %.2lf", media_impar);
    printf("\n\n");
    printf("*****************************************");
    printf("\n==> NUMEROS PARES MAIORES QUE A MEDIA DOS PARES ==> %.2lf: ", media_par);
    for(int j = 0; j< N;j++){
        if(vetor[j] % 2 == 0){
           if (vetor[j] > media_par) {
                printf("%i; ", vetor[j]);        
            }   
        }   
    }

    printf("\n==> NUMEROS IMPARES MEMORES QUE A MEDIA DOS IMPARES  ==> %.2lf: ", media_impar);
    for(int i = 0; i< N;i++){
        if(vetor[i] % 2 != 0){
            if (vetor[i] < media_impar) {
                printf("%i; ", i, vetor[i]);   
            }         
        }
    }

    printf("\n\n");

    return 0;


}