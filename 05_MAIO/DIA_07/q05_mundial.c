#include <stdio.h>

int main(void) {
    int idade;

    printf("\n-> Digite a sua idade<int>: ");
    scanf("%i", &idade);

    
   
    if (idade >=5 && idade <=7){
        printf("\n-> Categoria infantil A");

    }else if(idade >=8 && idade <=10){
        printf("\n-> Categoria infantil B");

    }else if(idade >=11 && idade <=13){
        printf("\n-> Categoria Juvenil A");

    }
    else if(idade >=14 && idade <=17){
        printf("\n-> Categoria Juvenil");

    }else if(idade >=18){
        printf("\n-> Categoria Senior");

    }else{
        printf("\n->ERROR, nao existe categoria para sua idade!");
    }
    
    printf("\n ");

    return 0;

}