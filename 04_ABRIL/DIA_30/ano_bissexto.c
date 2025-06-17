include <stdio.h>

int main(void) {
    int ano;

    printf(" -> Digite um ano: ");
    scanf("%i",&ano);

    if (ano < 0) {
        printf(" ERRO: nao existe ano negativo!");
    } else {
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano %  400 == 0)) {
            printf(" Ano eh bissexto!");
        } else {
            printf(" Ano NAO bissexto!");
        }
    }

    return 0;
}