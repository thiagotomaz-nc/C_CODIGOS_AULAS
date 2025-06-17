#include <stdio.h>

int main(void) {
    int idade;

    printf("\n-> Digite a sua idade<int>: ");
    scanf("%i", &idade);

    if(idade< 18){
        printf("\n-> Voce eh menor de idade!");

    } else if(idade>=18 && idade<=65){
        printf("\n-> maior de idade");
    }else{
        printf("\n-> maior de 65 anos");
    }

    return 0;

}