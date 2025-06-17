#include <stdio.h>

int main(void){
    int contador = 10;
    int somatorio =0;

    while(contador<=16){
        if(contador % 2 == 0 ){
            somatorio += contador;
        
        }

        contador++;
    }

    printf("\n-> Somatorio:   %i!", somatorio);

    printf("\n ");
    return 0;
}