#include <stdio.h>

int main(void){
    int dia;

    printf("\n-> Digite um dia da semana (1/7): ");
    scanf("%i",&dia);

    switch(dia){
        // logica de intervalo
        // case 2 ... 6: 

        case 1: 
            printf("-> O valor %i eh referente ao Domingo!", dia);
            break;
            //sai do codigo, caso ele não esteja no case, ele ignora os cases posteriores e executa os códigos dentro desses cases até finalizar ou encontrar outro break;
        case 2:
            printf("-> O valor %i eh referente ah Segunda-feira!", dia);
            break;
        case 3:
            printf("-> O valor %i eh referente ah Terca-feira!", dia);
            break;
        case 4:
            printf("-> O valor %i eh referente ah Quarta-feira!", dia);
            break;
        case 5:
            printf("-> O valor %i eh referente ah Quinta-feira!", dia);
            break;
        case 6:
            printf("-> O valor %i eh referente ah Sexta-feira!", dia);
            break;
        case 7:
            printf("-> O valor %i eh referente ao Sabado!", dia);
            break;
        default: 
            printf("\n#ERROR:  o valor %i digitado nao eh um dia invalido!",dia);
    }

    printf("\n ");

    return 0;
}