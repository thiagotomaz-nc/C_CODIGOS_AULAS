#include <stdio.h>

int main(void){

    int numeros[4] = {4,3,2,1};
   // int numeros = {4,3,2,1};

    printf("\n tamanho do inteiro<>: %i", sizeof(int));
    
    // %x imprime endereços;
    printf("\n Endereco do vetor: %x", numeros);
    // & quando eu quero acessar o enderecõ da variável
    

   for (int i = 0; i < sizeof(numeros)/sizeof(numeros[0]); i++){
        printf("\n Endereco do vetor[%i]: %x",i, &numeros[i]);
    }

    /*
        ao serem imprimidos ambos os prints exibem o mesmo endereço de memoria 
        O nome do vetor "numeros" guarda o endereço da primeira posição do vetor,
        ou seja, o endereço da posição "numeros[0]";

        Logo, o nome do vetor é um ponteiro;


        761ff9d0 = 761ff9d0

     */


    
    return 0;
}