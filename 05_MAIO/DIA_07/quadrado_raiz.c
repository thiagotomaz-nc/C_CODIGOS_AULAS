#include <stdio.h>
#include <math.h>

int main(void){
    int num1, num2;

    printf("\n-> Digite o numero 1<int>: ");
    scanf("%i", &num1);

    printf("\n-> Digite o numero 2<int>: ");
    scanf("%i", &num2);

    if (num1 > num2){
        printf("\n O maior numero eh %i e o menor eh %i ",num1, num2);
        printf("\n O quadrado  numero %i(menor) eh %lf", num2, pow(num2,2));
         if (num2<0){
            printf("\n #ERRO nao existe raiz quadrada de numero negativo!");

        }else{
            printf("\n -> A raiz quadrada de %i eh %.2lf", num2,  sqrt(num2));

        }
    }else{
        printf("\n O maior numero eh %i e o menor eh %i ",num2, num1);
        printf("\n O quadrado de %i eh %lf", num1, pow(num1,2));
        if (num1<0){
            printf("\n #ERRO nao existe raiz quadrada de numero negativo!");

        }else{
            printf("\n -> A raiz quadrada de %i eh %.2lf", num1,  sqrt(num1));

        }

    }

    printf("\n ");

    return 0;
}