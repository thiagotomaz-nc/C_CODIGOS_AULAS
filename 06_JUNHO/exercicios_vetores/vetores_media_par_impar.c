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

#define N 20

int main(void){
    
    int vetor[N];

    int quant_pares = 0, quant_impares = 0, somatorio_par = 0, somatorio_impar = 0;

    srand(time(NULL));

    for (int i = 0; i<N;i++){
        vetor[i] = rand() % 101;

        if(vetor[i] % 2 == 0){
            quant_pares++;
            somatorio += vetor[i];
        }else{
            somatorio_impar += vetor[i]
            quant_impares++;
        }

    }




    printf("\n");

    printf("VETOR -> ");
    for (int i = 0; i< N;i++){
        
        printf("%i ", vetor[i]);
    }

    return 0;
}