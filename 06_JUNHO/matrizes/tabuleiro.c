#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//preencher 10 posições com posições 1 com aleatorias, 
//CUIDADO não gerar posição aleatoria no mesmo local;
//2 jogadores, acertar os numeros 1 criado aleatoriamente em cinco tentativas, após isso vem o jogador 2
//para o jogador 2 vai se criar um novo tabuleiro.

#define LINHAS 9
#define COLUNAS 9
#define UNS 10

int main(void){
    int tabuleiro[LINHAS][COLUNAS];
    int acertos_jogadores[2] = {0,0}, tentativas_jogadores[2] = {0,0};
    int modo_jogo, linha_tabuleiro, coluna_tabuleiro;
    char jogador01[]="jogador01";
    char jogador02[] = "jogador02";
    
    srand(time(NULL));
    
    printf("-> Gerando o tabuleiro \n");
    for (int i = 0; i < LINHAS; i++ ){
        for (int j = 0; j < COLUNAS;j++){
            tabuleiro[i][j] = 0;
        }

    }
    //Gerar os numeros 10  em posições aleatórias
    
    for (int i = 0; i <= LINHAS; i++ ){
        int linhas_1 = rand() % 10;
        int colunas_1 = rand() % 10;
        if (!tabuleiro[linhas_1][colunas_1] == 1){
            tabuleiro[linhas_1][colunas_1] = 1;
        } else{
            i--;
        }
    }
    printf("\n *** obrigado por esperar!!! ***");

    printf("\n");
    printf("\n =====================================");
    printf("\n OLA, BEM-VINDO AO DESCUBRA UNS.\n");
    printf("\n Modo de jogo disponiveis: ");
    printf("\n [ 1 ] -> Tabuleiros (um jogador de cada vez)");
    printf("\n [ 2 ] -> Jogadores Alternados");
    printf("\n Seleciona o modo de jogo: ");
    scanf("%i", &modo_jogo);
    printf("\n Modo 1 selecionado, o jogador 1 iniciara o jogo");
    printf("\n");
    printf("\n");
    printf("*** JOGADOR 1: No tabuleiro abaixo existe 10 numeros uns escondidos, encontre-os usando a linha e a coluna ***");
    printf("\n");
    printf("\n");
    printf("");
    printf("\n ========== TABULEIRO ========\n");
    printf("\n");
    for (int i = 0; i < LINHAS; i++ ){
        for (int j = 0; j < COLUNAS;j++){
            printf(" %c " , '*');
            //printf(" %i " , tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    do{
        
        printf("\nscore");
        printf("\nJOGADOR 1: %i acertos | %i tentativas", acertos_jogadores[0], tentativas_jogadores[0]);
        printf("\n");
        printf("-> Digite a linha do tabuleiro: ");
        scanf("%i", &linha_tabuleiro);
        printf("-> Digite a coluna do tabuleiro: ");
        scanf("%i", &coluna_tabuleiro); 

        if(tabuleiro[linha_tabuleiro][coluna_tabuleiro] == 1){
        printf("\n *** PARABENS VOCE ENCONTROU O NUMERO 1 ***, restam %i numeros 1 (uns) para serem encontrados\n", UNS - acertos_jogadores[0]);
            printf("\n ========== TABULEIRO ========\n");
            printf("\n");
            for (int i = 0; i < LINHAS; i++ ){
                for (int j = 0; j < COLUNAS;j++){
                    printf(" %c " , '*');
                    //printf(" %i " , tabuleiro[i][j]);
                }
        printf("\n");
    }
            acertos_jogadores[0]++;
        }else{
            printf("\n Error, tente novamente!!!");
        }
    
    }while(acertos_jogadores[0] = 10);

    /*do{
    printf("\n BEM-VINDO AO JOGO\n");
    printf("\n %s escolha uma posição do tabuleiro (linha, coluna)\n", jogador01);
    printf("\n");

    }while(tentativas < 5);
*/
    printf("\n");
    return 0;
}