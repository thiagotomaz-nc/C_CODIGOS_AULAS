#include <stdio.h>

int main(void) {
    int a, b;

    printf("\n-> Digite o numero 1<int>: ");
    scanf("%i", &a);

    printf("-> Digite o numero 2<int>: ");
    scanf("%i", &b);

    
    if(a > b ){
        int aux = a;
        a = b;
        b =  aux;
    }
    
    printf("\n -> Numeros em ordem crescente: %i, %i",a, b);

    printf("\n ");
    
    

    return 0;
}