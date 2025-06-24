#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//preencher 10 posições com posições 1 com aleatorias, 
//CUIDADO não gerar posição aleatoria no mesmo local;
//2 jogadores, acertar os numeros 1 criado aleatoriamente em cinco tentativas, após isso vem o jogador 2
//para o jogador 2 vai se criar um novo tabuleiro.

#define linhas 9
#define colunas 9

int main(void){
    int tabuleiro[linhas][colunas];
    int acerto = 0, tentativas = 0;
    char jogador01[]="jogador01";
    char jogador02[] = "jogador02";
    
    

    for (int i = 0; i < linhas; i++ ){
        for (int j = 0; j < colunas;j++){
            tabuleiro[i][j] = 0;
        }

    }

    printf("\n ========== ESCOLHA UMA POSICAO NO TABULEIRO ========\n");
    printf("\n");
    for (int i = 0; i < linhas; i++ ){
        for (int j = 0; j < colunas;j++){
            // printf(" %c " , '*');
            printf(" %i " , tabuleiro[i][j]);
        }
        printf("\n");
    }

    do{
    printf("\n BEM-VINDO AO JOGO\n");
     printf("\n %s escolha uma posição do tabuleiro (linha, coluna)\n", jogador01);
    printf("\n");

    }while(tentativas < 5);

    printf("\n");
    return 0;
}