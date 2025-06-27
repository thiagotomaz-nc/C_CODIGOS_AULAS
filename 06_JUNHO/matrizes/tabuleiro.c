#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LINHAS 10
#define COLUNAS 10
#define TRUE 1
#define UNS 10

int main(void)
{
    char tabuleiro_exibicao[LINHAS][COLUNAS];
    int tabuleiro_controler[LINHAS][COLUNAS];
    int acertos_jogadores[2] = {0, 0}, tentativas_jogadores[2] = {0, 0}, jogador = 1;
    int modo_jogo, menu_liberado = 0, linha_tabuleiro, coluna_tabuleiro;
    char detalhes_jogo;

    // MENU do jogo

    do
    {
        printf("\n =====================================");
        printf("\n OLA, BEM-VINDO AO DESCUBRA UNS");
        printf("\n =====================================");
        printf("\n");
        printf("\n *********** MENU ************");
        printf("\n--------------------------------------------------");
        printf("\n [ 1 ] -> Modo Dois Jogadores (Sequencial)");
        printf("\n [ 2 ] -> Modo Dois Jogadores (Alternado)");
        printf("\n [ 3 ] -> Instrucoes");
        printf("\n [ 0 ] -> Sair do jogo");
        printf("\n--------------------------------------------------");
        printf("\n Seleciona o modo de jogo: ");
        scanf("%i", &modo_jogo);

        // TAREFAS DE CADA OPCAO DO MENU
        switch (modo_jogo)
        {
        case 0:
            printf("\n -> Voce saiu do jogo, ate mais");
            return 0;
            break;
        case 1 ... 2:
            menu_liberado++;
            break;
        case 3:
            fflush(stdin);
            printf("\n");
            printf("\n//////////////////////////////////////////////////////////////////");
            printf("\n");
            printf("\n >>> No tabuleiro abaixo existe 10 numeros uns escondidos,\nencontre-os usando a posicao da linha e da coluna, ao acertar a posicao do numero 1 ele sera mostrado,\ncaso erre um x sera colocado na posicao para indicar o erro do jogador");
            printf("\n---------------------------------------------------------");
            printf("\n");
            printf("\n ### Modo Dois Jogadores (Sequencial) ###");
            printf("\n -> O Jogador 1 joga ate encontrar todos os 1 escondidos, Em seguida, o Jogador 2 joga com o mesmo desafio. O jogador que encontrar todos os 1s com menos tentativas vence, Se o Jogador 2 exceder as tentativas do Jogador 1, perde automaticamente");
            printf("\n---------------------------------------------------------");
            printf("\n");
            printf("\n ### Modo Dois Jogadores (Alternado) ###");
            printf("\n -> Os Jogadores se revezam a cada jogada: Jogador 1, depois Jogador 2, e assim por diante. A tabela e compartilhada, com isso, o jogo termina quando todos os 10 números 1 (uns) forem encontrados, logo, Vence o jogo quem conseguir encontrar mais números 1 ao final do jogo. Se a quantidade for a mesma, o jogo termina em empate.");
            printf("\n---------------------------------------------------------");
            printf("\n-> Digite qualquer tecla para sair: ");
            scanf("%c", &detalhes_jogo);
            printf("\n");
            break;
        default:
            printf("\n");
            printf("\n/////////////////////////////////////////////");
            printf("\n-> atencao, OPCAO INVALIDA, selecione uma opcao listada no menu");
            printf("\n");
            break;
        }
    } while (menu_liberado == 0);

    srand(time(NULL));

    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            tabuleiro_controler[i][j] = 0;
            tabuleiro_exibicao[i][j] = '0';
        }
    }

    // Gerar os numeros 10  em posições aleatórias
    for (int i = 0; i < LINHAS; i++)
    {
        int linhas_1 = rand() % 11;
        int colunas_1 = rand() % 11;
        if (tabuleiro_controler[linhas_1][colunas_1] == 0)
        {
            tabuleiro_controler[linhas_1][colunas_1] = 1;
        }
        else
        {
            i--;
        }
    }

    // Levando em consideração que os valores que irão sair do do_while serão apenas o 1 ou 2.

    if (modo_jogo == 1)
    {
        printf("\n********************************************");
        printf("\n\n >>> Modo Dois Jogadores (Sequencial)  selecionado\n");
        printf("\n__________________________________________________________________\n");
        printf("\n-> Eh a vez do [Jogador 1] | RESUMO: %i acertos <-> %i tentativas", acertos_jogadores[0], tentativas_jogadores[0]);
        printf("\nFACA SUA JOGADA\n\n");

        printf("\n ========== TABULEIRO ========\n");

        for (int i = 0; i < LINHAS; i++)
        {
            if (i == 0)
            {
                printf("  C  0 1 2 3 4 5 6 7 8 9\n");
                printf("L    | | | | | | | | | |\n");
            }
            for (int j = 0; j <= COLUNAS; j++)
            {
                if (j == 0)
                {
                    printf("%i -> ", i);
                }
                else
                {
                    printf("%c ", tabuleiro_exibicao[i][j - 1]);
                }
            }
            printf("\n");
        }

        while (TRUE)
        {
            if (jogador==1){
                
            }else{
                
            }
            printf("\n-> Digite a linha do tabuleiro: ");
            scanf("%i", &linha_tabuleiro);
            printf("-> Digite a coluna do tabuleiro: ");
            scanf("%i", &coluna_tabuleiro);

            if (tabuleiro_controler[linha_tabuleiro][coluna_tabuleiro] == 1)
            {
                acertos_jogadores[0]++;
                tentativas_jogadores[0]++;
                tabuleiro_exibicao[linha_tabuleiro][coluna_tabuleiro] = '1';
                printf("\n__________________________________________________________________\n");
                printf("\n-> Eh a vez do [Jogador 1] | RESUMO: %i acertos <-> %i tentativas", acertos_jogadores[0], tentativas_jogadores[0]);
                printf("\nFACA SUA JOGADA\n\n");
                printf("\n********************************************************************");
                printf("\n *** PARABENS VOCE ENCONTROU O NUMERO 1 ***,\nrestam %i numeros 1 (uns) para serem encontrados\n", LINHAS - acertos_jogadores[0]);
                printf("\n-----------------------------------------------------\n");
                printf("\n ========== TABULEIRO ========\n");

                for (int i = 0; i < LINHAS; i++)
                {
                    if (i == 0)
                    {
                        printf("  C  0 1 2 3 4 5 6 7 8 9\n");
                        printf("L    | | | | | | | | | |\n");
                    }
                    for (int j = 0; j <= COLUNAS; j++)
                    {
                        if (j == 0)
                        {
                            printf("%i -> ", i);
                        }
                        else
                        {
                            printf("%c ", tabuleiro_exibicao[i][j - 1]);
                        }
                    }
                    printf("\n");
                }
            }
            else
            {
                tentativas_jogadores[0]++;
                tabuleiro_exibicao[linha_tabuleiro][coluna_tabuleiro] = 'X';
                printf("\n################################################################");
                printf("\nNAO EXISTE 1 NESSA POSICAO  L [ %i ] <--> C [ %i ]  , tente novamente!!!", linha_tabuleiro, coluna_tabuleiro);
                printf("\n__________________________________________________________________\n");
                printf("\n-> Eh a vez do [Jogador 1] | RESUMO: %i acertos <-> %i tentativas", acertos_jogadores[0], tentativas_jogadores[0]);
                printf("\nFACA SUA JOGADA\n\n");

                printf("\n ========== TABULEIRO ========\n");

                for (int i = 0; i < LINHAS; i++)
                {
                    if (i == 0)
                    {
                        printf("  C  0 1 2 3 4 5 6 7 8 9\n");
                        printf("L    | | | | | | | | | |\n");
                    }
                    for (int j = 0; j <= COLUNAS; j++)
                    {
                        if (j == 0)
                        {
                            printf("%i -> ", i);
                        }
                        else
                        {
                            printf("%c ", tabuleiro_exibicao[i][j - 1]);
                        }
                    }

                    printf("\n");
                }

                continue;
            }
        }
    }
    else
    {
    }

    printf("\n");
    return 0;
}