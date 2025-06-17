#include <stdio.h>

int main(void) {
    int num1, num2, num3;

    printf("\n-> Digite o numero 1<int>: ");
    scanf("%i", &num1);

    printf("\n-> Digite o numero 2<int>: ");
    scanf("%i", &num2);

    printf("\n-> Digite o numero 3<int>: ");
    scanf("%i", &num3);

    int maior, menor, mediano;

    
    if(num1 > num2 && num1 > num3){
      maior = num1;
      if (num2 > num3){
        mediano = num2;
        menor = num3;
      }else{
        mediano = num3;
        menor = num2;
      }
    }else if (num2 > num1 && num2 > num3){
      maior = num2;
      if (num1 > num3){
        mediano = num1;
        menor = num3;
      }else{
        mediano = num3;
        menor = num1;
      }
    }else{
        maior = num3;
      if (num1 > num2){
        mediano = num1;
        menor = num2;
      }else{
        mediano = num2;
        menor = num1;
      }
    }

    printf("\n -> Numeros em ordem decrescente: %i, %i, %i", maior, mediano, menor);
    printf("\n ");
    
    

    return 0;
}