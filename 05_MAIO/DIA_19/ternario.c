#include <stdio.h>

int main(void) {
    int num1, num2;

    printf(" -> Digite numero 1: ");
    scanf("%i",&num1);

    printf(" -> Digite numero 2: ");
    scanf("%i",&num2);

    if (num1 >= num2) {
        printf(" num1 >= num2");
    } else {
        printf(" num1 < num2");
    }

    printf("\n EXEMPLO OPERADOR TERNARIO\n");
    num1 >= num2 ? printf(" num1 >= num2") : printf(" num1 < num2");

    int resultado;

    resultado = num1 >= num2 ? num1 - num2 : num1 + num2;

    printf("\n\n RESULTADO: %i",resultado);

    return 0;
}