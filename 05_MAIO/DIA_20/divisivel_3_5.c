#include <stdio.h>

int main(void){
    int contador = 1;

    while(contador<=100){
        if(contador % 3 == 0 && contador%5 ==0){
            printf("\n-> O numero %i eh divisivel por 3 e por 5!", contador);
        
        }

        contador++;
    }
    printf("\n ");
    return 0;
}