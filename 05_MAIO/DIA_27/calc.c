#include <stdio.h>

int main(void){
    char op, aux;
    float num1, num2;
    int continuar;

    do{
       
        
        printf("\n------------------------");
        printf("\n###CALCULADORA EM C ###");
        printf("\n------------------------");
        printf("\n +: adicao");
        printf("\n -: subtração");
        printf("\n *: multiplicacao");
        printf("\n /: divisao");
        printf("\n------------------------");
        printf("\n -> Digite a operacao desejada: ");
        scanf("%c", &op);

        if(op=='+' || op=='-' || op=='*' || op=='/'){
            //operador e valido =  realizar a operação
            printf("\n -> Digite o numero 1: " ) ;
            scanf("%f", &num1);

            printf("\n -> Digite o numero 2: " ) ;
            scanf("%f", &num2);
            switch(op){
                case '+': 
                printf("\n-> %f + %f = %.2f", num1, num2, num1 + num2);
                break;
                case '-':
                printf("\n-> %f + %f = %.2f", num1, num2, num1 - num2);
                break;
                case '*':
                printf("\n-> %f + %f = %.2f", num1, num2, num1 * num2);
                break;
                case '/':
                if(num2!=0){
                    printf("\n-> %f + %f = %.2f", num1, num2, num1 / num2);
                }else{
                    printf("\n[ERROR] -> Nao existe divisao por zero!");
                }
                break;
            }
        }else{
            printf("\n[ERROR] -> Operador invalido!");
        }

       
        printf("\n ");
        printf("\n *********************************");   
        printf("\n -> deseja continuar (digite qualquer numero)? ");
        scanf("%i",&continuar);
        scanf("%c", &aux);
       }while(continuar != 0);

        printf("\n -> Saindo da calculadora... ");   


    return 0;
}