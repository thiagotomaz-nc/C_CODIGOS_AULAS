#include <stdio.h>

int main(void) {
    int idade;

    printf("\n-> Digite a sua idade<int>: ");
    scanf("%i", &idade);

    
   
    switch (idade){
        case 5 ... 7:
            printf("\n-> Categoria infantil A");
        break;
        case 8 ... 10:
           printf("\n-> Categoria infantil B");
        break;
        case 11 ... 13:
            printf("\n-> Categoria Juvenil A");
        break;
        case 14 ... 17:
            printf("\n-> Categoria Juvenil");
        break;
        default:
            if (!(idade <= 5))
                printf("\n-> Categoria Senior");
            else   
                printf("\n->ERROR, nao existe categoria para sua idade!");
  
    }
    
    printf("\n ");

    return 0;

}