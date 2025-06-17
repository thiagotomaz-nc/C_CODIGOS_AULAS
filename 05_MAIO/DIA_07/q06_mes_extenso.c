#include <stdio.h>

int main(void){
    int mes;

    printf("\n-> Digite o numero correspondente ao mes do ano (1-12)<int>:  ");
    scanf("%i", &mes);

    switch(mes){
        case 1:
        printf("\n-> %i -> JANEIRO! ", mes);
        break;
        case 2:
        printf("\n-> %i -> FEVEREIRO! ", mes);
        break;
        case 3:
        printf("\n-> %i -> MARCO! ", mes);
        break;
        case 4:
        printf("\n-> %i -> ABRIL! ", mes);
        break;
        case 5:
        printf("\n-> %i -> MAIOR! ", mes);
        break;
        case 6:
        printf("\n-> %i -> JUNHO! ", mes);
        break;
        case 7:
        printf("\n-> %i -> JULHO! ", mes);
        break;
        case 8:
        printf("\n-> %i -> AGOSTO! ", mes);
        break;
        case 9:
        printf("\n-> %i -> SETEMBRO! ", mes);
        break;
        case 10:
        printf("\n-> %i -> OUTUBRO! ", mes);
        break;
        case 11:
        printf("\n-> %i -> NOVEMBRO! ", mes);
        break;
        case 12:
        printf("\n-> %i -> DEZEMBRO! ", mes);
        break;

        default:
            printf("\n -> O numero %i esta fora do intervalo, tente novamente neste intervalo -> (1-12)", mes);
    }

    printf("\n ");

    return 0;
}