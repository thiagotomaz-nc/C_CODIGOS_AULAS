#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NCJ1 10
#define NCJ2 20

int main (void){
    int conjunto_01[NCJ1];
    int conjunto_02[NCJ2];
    
    //definindo a semente do rand
    // a partir do horario do SO - Sistema Operacional;
    srand(time(NULL));

    //preenchendo o conjunto 01
    printf("\nCONJUNTO 01: \n");
    for (int i = 0; i< NCJ1;i++){
        // quando eu divido um numero inteiro por outro inteiro 
        // o resto da divisão vai de numero N a N -1;
        conjunto_01[i] = rand() % 21; // vai de 0 a 20;
        printf("%i ", conjunto_01[i]);
    }

    printf("\n ");

    //preenchendo o conjunto 02
     printf("\nCONJUNTO 02: \n");
    for (int i = 0; i< NCJ2;i++){
        // quando eu divido um numero inteiro por outro inteiro 
        // o resto da divisão vai de numero N a N -1;
        conjunto_02[i] = rand() % 21; // vai de 0 a 20;
        printf("%i ", conjunto_02[i]);
    }

    printf("\n ");

    //Apresentar os elementos comuns aos 2 conjuntos
    printf("\nUNIAO entre os conjuntos 01 e 02 \n" );
    for (int i = 0; i<NCJ1; i++){
        for(int j = 0; j<NCJ2; j++){    
            if(conjunto_01[i] == conjunto_02[j]){
                printf("%i ", conjunto_01[i]);
                break;
            }

        }

    }

    printf("\n ");

    return 0;
}