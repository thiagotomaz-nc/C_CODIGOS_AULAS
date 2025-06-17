#include <stdio.h>

int main(){
    double num1, num2;
    char operador;

    printf("-> digite o primeiro numero: ");
    scanf("%lf", &num1);

    printf("-> Digite o segundo numero: ");
    scanf("%lf", &num2);

   //fflush(stdin);
    scanf("%c",  &operador);
    printf("\n-> Digite a operacao desejada [+ , - , / , * ]: ");
    scanf("%c",  &operador);

    switch(operador){
        case '+':
            printf("\n-> A soma de %lf + %lf = %.2lf", num1, num2, num1 + num2);
            break;
        case '-':
            printf("\n-> A subtracao de %lf - %lf = %.2lf", num1, num2, num1 - num2);
            break;
        case '/':
            if (num2 != 0){
                printf("\n-> A divisao de %lf / %lf = %.2lf", num1, num2, num1 / num2);
            }else{
                printf("\n-> Não existe divisão por 0");
            }
            break;
        case '*':
            printf("\n-> A multiplicacao de %lf * %lf = %.2lf", num1, num2, num1 * num2);
            break;
        default:
            printf("\n*ERROR, Operador invalido");

    }
    printf("\n ");

    return 0;
}