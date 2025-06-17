#include <stdio.h>
#include <string.h>

int main(void){

    char nome[30];
    char nome2[30];
    int numero;
    char aux;


    printf("\n-> Digite um numero: ");
    scanf("%i", &numero);

    

    scanf("%c", &aux);
    printf("\n=> Digite o seu nome1: ");
    scanf("%[^\n]", &nome);
    
    // fflush(stdin);

    scanf("%c", &aux);
    printf("\n=> Digite o seu nome2: ");
    // uma forma de atribuir uma cadeia de caracteres (string) a um vetor
    // porem ele finaliza o nome no primeiro espaço: Exemplo: jose Thiago,
    // lê apenas Jose, a barra de 
    //espaço é interpretado como o fim da string
    /* scanf("%s", &nome);*/

   // lendo usando um formatador
   //leia qualquer coisa até encontrar o /n(Enter)
   scanf("%[^\n]", &nome2);

    printf("O seu nome1 eh %s e o nome2 eh %s!", nome, nome2);

    
    
    int cmp = strcmp(nome,nome2);
    //utilizada para colocar nomes em ordem alfabetica;
    /*
        >0: nome1 > nome2
        ==0: nome1 == nome2
        <0: nome1 <  nome2 
    */

    printf("\n ");

    if (cmp > 0){
        printf("\n-> A ordem Alfabetica eh: 1:  %s e 2: %s!", nome2, nome);
    }else if(cmp < 0){
        printf("\n-> A ordem Alfabetica eh: 1:  %s e 2: %s!", nome, nome);
    }else{
        printf("\n-> String iguais!");
    }

    return 0;
}