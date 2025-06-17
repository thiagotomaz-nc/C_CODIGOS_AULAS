#include <stdio.h>

int main(void){
    int numero, fatorial = 1;

    printf("\n-> informe um numero<int>: ");
    scanf("%i", &numero);

    if(numero >= 0){

         if(numero == 0){
            fatorial = 1;
         }else{
            int i = numero; 
            printf("\nCALCULANDO O FATORIAL DE %i", numero);
            printf("\n ");
            while (i >= 1){
                if (i!=1){
                    printf("%i * ", i);
                }else{
                    printf("%i", i);
                }
            
            fatorial  *=  i;
            i--;
          } 
         }
          
       
    }else{
        printf("\n_> Nao existe fatorial de numero negatico!");   
    }

    printf("\n ");
    printf("\n-> O fatorial de %i eh %i", numero, fatorial);
    printf("\n ");

    return 0;
}