#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_NUMEROS 10
#define NUM_MAX 50


int main(void){
    srand(time(NULL));

    int conjunto[N_NUMEROS];

    printf("* CONJUNTO * \n");
    for (int i = 0; i< N_NUMEROS;i++){
        conjunto[i] = rand() % (NUM_MAX + 1);
        printf("%i ", conjunto[i]);
    }

     /* IMPRIMIR */



    return 0;
}