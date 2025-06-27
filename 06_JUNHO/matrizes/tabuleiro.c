/* ATIVIDADE EXTRA DE IMPLEMENTAÇÃO
THIAGO TOMAZ DE ARAUJO - 20251134040031
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LINHAS 10
#define COLUNAS 10
#define QUANT_UNS 10 // -> Essa constante vai servir apenas para controlar a quantidade de uns a serem gerados
#define ACERTO_UNS_ALTERNADOS 5
#define TRUE 1
#define QUANT_JOGADORES 2

int main(void)
{
    char tabuleiro_exibicao[LINHAS][COLUNAS], nova_partida;
    int tabuleiro_controler[LINHAS][COLUNAS];
    int acertos_jogadores[QUANT_JOGADORES] = {0, 0}, tentativas_jogadores[QUANT_JOGADORES] = {0, 0}, id_jogador = 0;
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

        srand(time(NULL));

        for (int i = 0; i < LINHAS; i++)
        {
            for (int j = 0; j < COLUNAS; j++)
            {
                tabuleiro_controler[i][j] = 0;
                tabuleiro_exibicao[i][j] = '0';
            }
        }

        // TAREFAS DE CADA OPCAO DO MENU
        switch (modo_jogo)
        {
        case 0:
            printf("\n -> Voce saiu do jogo, ate mais");
            menu_liberado++;
            break;
        case 1:
            // Gerar/distribuir aleatoriamente os numeros 10 uns em posições aleatórias
            for (int i = 0; i < QUANT_UNS; i++)
            {
                int linhas_1 = rand() % LINHAS;
                int colunas_1 = rand() % COLUNAS;
                if (tabuleiro_controler[linhas_1][colunas_1] == 0)
                {
                    tabuleiro_controler[linhas_1][colunas_1] = 1;
                }
                else
                {
                    i--;
                }
            }
            printf("\n/////////////////////////////////////////////////////////////////////////");
            printf("\n>>> Modo Dois Jogadores (Sequencial) selecionado <<< \n");
            printf("\n-------------------------------------------------------------------------");

            printf("\n\n========== TABULEIRO ========\n");

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
                printf("__________________________________________________________________");
                printf("\n-> [Jogador %i] eh a sua vez | RESUMO: %i acertos <-> %i tentativas", id_jogador + 1, acertos_jogadores[id_jogador], tentativas_jogadores[id_jogador]);
                printf("\nFACA SUA JOGADA\n");

                printf("\n-> Digite a linha do tabuleiro: ");
                scanf("%i", &linha_tabuleiro);
                printf("-> Digite a coluna do tabuleiro: ");
                scanf("%i", &coluna_tabuleiro);

                // verificar se a linha e a posicao ja foi chamada se sim informar que ja foi chamada
                if (tabuleiro_exibicao[linha_tabuleiro][coluna_tabuleiro] == 'X' || tabuleiro_exibicao[linha_tabuleiro][coluna_tabuleiro] == '1')
                {
                    printf("\n################################################################");
                    printf("\nTENCAO JOGADOR [ %i ], A LINHA L [ %i ] E A COLUNA C [ %i ] JA FOI ESCOLHIDA , tente novamente!!!", id_jogador + 1, linha_tabuleiro, coluna_tabuleiro);
                    printf("\n################################################################\n");
                    continue;
                }
                else if (linha_tabuleiro < 0 || linha_tabuleiro >= LINHAS)
                {
                    printf("\n################################################################");
                    printf("\nATENCAO JOGADOR [ %i ], O(s) VALOR(es) ACEITOS(s) para a LINHA [ L ] E DE 0 A %i, tente novamente!!!", id_jogador + 1, LINHAS - 1);
                    printf("\n################################################################\n");
                    continue;
                }
                else if (coluna_tabuleiro < 0 || coluna_tabuleiro >= COLUNAS)
                {
                    printf("\n################################################################");
                    printf("\nATENCAO JOGADOR [ %i ], O(s) VALOR(es) ACEITOS(s) para a COLUNA [ C ] E DE 0 A %i, tente novamente!!!", id_jogador + 1, COLUNAS - 1);
                    printf("\n################################################################\n");
                    continue;
                }
                else
                {
                    if (tabuleiro_controler[linha_tabuleiro][coluna_tabuleiro] == 1)
                    {
                        acertos_jogadores[id_jogador]++;
                        tentativas_jogadores[id_jogador]++;
                        tabuleiro_exibicao[linha_tabuleiro][coluna_tabuleiro] = '1';
                        printf("\n********************************************************************");
                        printf("\n********************************************************************");
                        printf("\n *** JOGADOR [ %i ], PARABENS VOCE ENCONTROU O NUMERO 1 ***,\nrestam %i numeros 1 (uns) para serem encontrados", id_jogador + 1, QUANT_UNS - acertos_jogadores[id_jogador]);
                        printf("\n-----------------------------------------------------");
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
                        tentativas_jogadores[id_jogador]++;
                        tabuleiro_exibicao[linha_tabuleiro][coluna_tabuleiro] = 'X';
                        printf("\n################################################################");
                        printf("\n JOGADOR [ %i ] NAO EXISTE 1 NESSA POSICAO  L [ %i ] <--> C [ %i ]  , tente novamente!!!", id_jogador + 1, linha_tabuleiro, coluna_tabuleiro);
                        printf("\n-----------------------------------------------------");

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
                    } // fim do senão, caso o jogador não encontre o 1.

                    /*
                    -> verificar a quantidade de acertos é 10
                    */
                    if ((acertos_jogadores[id_jogador] == QUANT_UNS) && (id_jogador == 0))
                    {

                        printf("\n********************************************************************");
                        printf("\n********************************************************************");
                        printf("\n********************************************************************");
                        printf("\n *** PARABENS jogador %i voce encontrou todos os numeros 1 (uns)  ***", id_jogador + 1);
                        printf("\n-> RESUMO: %i acertos <-> %i tentativas", acertos_jogadores[id_jogador], tentativas_jogadores[id_jogador]);
                        printf("\n\nO JOGADOR %i ENCERROU A SUA VEZ\n\n", id_jogador + 1);
                        printf("\n------------------------------------------------------------------------------------------\n");
                        id_jogador++;
                        printf("\n-> Agora eh a vez do [Jogador %i] ", id_jogador + 1);
                        printf("\n-> Gerando novo tabuleiro\n");
                        printf("\nFACA SUA JOGADA\n");

                        // Gerando/povoando os valores dos tabuleiros
                        for (int i = 0; i < LINHAS; i++)
                        {
                            for (int j = 0; j < COLUNAS; j++)
                            {
                                tabuleiro_controler[i][j] = 0;
                                tabuleiro_exibicao[i][j] = '0';
                            }
                        }

                        // Gerar/distribuir aleatoriamente os numeros 10 uns em posições aleatórias
                        for (int i = 0; i < QUANT_UNS; i++)
                        {
                            int linhas_1 = rand() % LINHAS;
                            int colunas_1 = rand() % COLUNAS;
                            if (tabuleiro_controler[linhas_1][colunas_1] == 0)
                            {
                                tabuleiro_controler[linhas_1][colunas_1] = 1;
                            }
                            else
                            {
                                i--;
                            }
                        }
                        // exibindo o tabuleiro
                        printf("========== TABULEIRO ========\n");

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
                    } // FIM DO JOGADOR 1 PARA O JOGADOR 2
                    // SITUAÇÃO EM QUE O JOGADOR 2 VENCE
                    else if (id_jogador == 1 && tentativas_jogadores[id_jogador] <= tentativas_jogadores[id_jogador - 1])
                    {
                        if (acertos_jogadores[id_jogador] == QUANT_UNS && tentativas_jogadores[id_jogador] == tentativas_jogadores[id_jogador - 1])
                        {
                            printf("\n********************************************************************");
                            printf("\n********************************************************************");
                            printf("\n********************************************************************");
                            printf("\n *** O jogador %i EMPATOU com o jogador %i ***", id_jogador, id_jogador + 1);
                            printf("\n-> TOTAL:\n%i acertos <-> %i tentativas", acertos_jogadores[id_jogador], tentativas_jogadores[id_jogador]);
                            printf("\n____________________________________________________________________\n");
                            printf("\n *** O jogador %i FICOU SEGUNDO LUGAR  ***", id_jogador);
                            printf("\n-> TOTAL:\n%i acertos <-> %i tentativas", acertos_jogadores[id_jogador - 1], tentativas_jogadores[id_jogador - 1]);
                            printf("\n-----------------------------------------------------\n");
                            fflush(stdin);
                            printf("\n-> O que deseja fazer agora?\n[ 1 ] -> JOGAR OUTRA PARTIDA\n[ 2 ] - MENU INICIAL\n[ aperte qualquer  tecla ] -> ENCERRAR  ");
                            scanf("%c", &nova_partida);

                            if (nova_partida == '1')
                            {

                                for (int i = 0; i < 2; i++)
                                {
                                    acertos_jogadores[i] = 0;
                                    tentativas_jogadores[i] = 0;
                                    id_jogador = 0;
                                }

                                srand(time(NULL));

                                for (int i = 0; i < LINHAS; i++)
                                {
                                    for (int j = 0; j < COLUNAS; j++)
                                    {
                                        tabuleiro_controler[i][j] = 0;
                                        tabuleiro_exibicao[i][j] = '0';
                                    }
                                }

                                // Gerar/distribuir aleatoriamente os numeros 10 uns em posições aleatórias
                                for (int i = 0; i < QUANT_UNS; i++)
                                {
                                    int linhas_1 = rand() % LINHAS;
                                    int colunas_1 = rand() % COLUNAS;
                                    if (tabuleiro_controler[linhas_1][colunas_1] == 0)
                                    {
                                        tabuleiro_controler[linhas_1][colunas_1] = 1;
                                    }
                                    else
                                    {
                                        i--;
                                    }
                                }
                                printf("========== TABULEIRO ========\n");

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
                                // refazer as tabelas e zerar os valores utilizados
                            }
                            else if (nova_partida == '2')
                            {
                                for (int i = 0; i < 2; i++)
                                {
                                    acertos_jogadores[i] = 0;
                                    tentativas_jogadores[i] = 0;
                                    id_jogador = 0;
                                }
                                break;
                            }
                            else
                            {
                                menu_liberado++;
                                break;
                            }
                        }
                        else if (acertos_jogadores[id_jogador] == QUANT_UNS && tentativas_jogadores[id_jogador] != tentativas_jogadores[id_jogador - 1])
                        {
                            printf("\n********************************************************************");
                            printf("\n********************************************************************");
                            printf("\n********************************************************************");
                            printf("\n *** O jogador %i EH O CAMPEAO ***", id_jogador + 1);
                            printf("\n-> TOTAL:\n%i acertos <-> %i tentativas", acertos_jogadores[id_jogador], tentativas_jogadores[id_jogador]);
                            printf("\n____________________________________________________________________\n");
                            printf("\n *** O jogador %i FICOU SEGUNDO LUGAR  ***", id_jogador);
                            printf("\n-> TOTAL:\n%i acertos <-> %i tentativas", acertos_jogadores[id_jogador - 1], tentativas_jogadores[id_jogador - 1]);
                            printf("\n-----------------------------------------------------\n");
                            fflush(stdin);
                            printf("\n-> O que deseja fazer agora?\n[ 1 ] -> JOGAR OUTRA PARTIDA\n[ 2 ] - MENU INICIAL\n[ aperte qualquer  tecla ] -> ENCERRAR  ");
                            scanf("%c", &nova_partida);

                            if (nova_partida == '1')
                            {

                                for (int i = 0; i < 2; i++)
                                {
                                    acertos_jogadores[i] = 0;
                                    tentativas_jogadores[i] = 0;
                                    id_jogador = 0;
                                }

                                srand(time(NULL));

                                for (int i = 0; i < LINHAS; i++)
                                {
                                    for (int j = 0; j < COLUNAS; j++)
                                    {
                                        tabuleiro_controler[i][j] = 0;
                                        tabuleiro_exibicao[i][j] = '0';
                                    }
                                }

                                // Gerar/distribuir aleatoriamente os numeros 10 uns em posições aleatórias
                                for (int i = 0; i < QUANT_UNS; i++)
                                {
                                    int linhas_1 = rand() % LINHAS;
                                    int colunas_1 = rand() % COLUNAS;
                                    if (tabuleiro_controler[linhas_1][colunas_1] == 0)
                                    {
                                        tabuleiro_controler[linhas_1][colunas_1] = 1;
                                    }
                                    else
                                    {
                                        i--;
                                    }
                                }
                                printf("========== TABULEIRO ========\n");

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
                                // refazer as tabelas e zerar os valores utilizados
                            }
                            else if (nova_partida == '2')
                            {
                                for (int i = 0; i < 2; i++)
                                {
                                    acertos_jogadores[i] = 0;
                                    tentativas_jogadores[i] = 0;
                                    id_jogador = 0;
                                }
                                break;
                            }
                            else
                            {
                                menu_liberado++;
                                break;
                            }
                        }
                    } // jogador 1 venceu
                    else if (id_jogador == 1 && tentativas_jogadores[id_jogador] > tentativas_jogadores[id_jogador - 1])
                    {
                        printf("\n********************************************************************");
                        printf("\n********************************************************************");
                        printf("\n********************************************************************");
                        printf("\n *** O jogador %i excedeu a quantidade de tentativas do jogador %i ***", id_jogador + 1, id_jogador);
                        printf("\n********************************************************************");
                        printf("\n *** O jogador %i EH O CAMPEAO ***", id_jogador);
                        printf("\n-> TOTAL:\n%i acertos <-> %i tentativas", acertos_jogadores[id_jogador - 1], tentativas_jogadores[id_jogador - 1]);
                        printf("\n____________________________________________________________________\n");
                        printf("\n *** O jogador %i FICOU SEGUNDO LUGAR  ***", id_jogador + 1);
                        printf("\n-> TOTAL:\n%i acertos <-> %i tentativas", acertos_jogadores[id_jogador], tentativas_jogadores[id_jogador]);
                        printf("\n-----------------------------------------------------\n");
                        fflush(stdin);
                        printf("\n-> O que deseja fazer agora?\n[ 1 ] -> JOGAR OUTRA PARTIDA\n[ 2 ] - MENU INICIAL\n[ aperte qualquer  tecla ] -> ENCERRAR  ");
                        scanf("%c", &nova_partida);

                        if (nova_partida == '1')
                        {
                            for (int i = 0; i < 2; i++)
                            {
                                acertos_jogadores[i] = 0;
                                tentativas_jogadores[i] = 0;
                                id_jogador = 0;
                            }

                            srand(time(NULL));

                            for (int i = 0; i < LINHAS; i++)
                            {
                                for (int j = 0; j < COLUNAS; j++)
                                {
                                    tabuleiro_controler[i][j] = 0;
                                    tabuleiro_exibicao[i][j] = '0';
                                }
                            }

                            // Gerar/distribuir aleatoriamente os numeros 10 uns em posições aleatórias
                            for (int i = 0; i < QUANT_UNS; i++)
                            {
                                int linhas_1 = rand() % LINHAS;
                                int colunas_1 = rand() % COLUNAS;
                                if (tabuleiro_controler[linhas_1][colunas_1] == 0)
                                {
                                    tabuleiro_controler[linhas_1][colunas_1] = 1;
                                }
                                else
                                {
                                    i--;
                                }
                            }
                            printf("========== TABULEIRO ========\n");

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
                            // refazer as tabelas e zerar os valores utilizados
                        }
                        else if (nova_partida == '2')
                        {
                            for (int i = 0; i < 2; i++)
                            {
                                acertos_jogadores[i] = 0;
                                tentativas_jogadores[i] = 0;
                                id_jogador = 0;
                            }
                            break;
                        }
                        else
                        {
                            menu_liberado++;
                            break;
                        }
                    }
                }
            } // fim do while
            break;
            // INICIANDO O CASE 2, MODO ALTERNADO
        case 2:
            for (int i = 0; i < QUANT_UNS; i++)
            {
                int linhas_1 = rand() % LINHAS;
                int colunas_1 = rand() % COLUNAS;
                if (tabuleiro_controler[linhas_1][colunas_1] == 0)
                {
                    tabuleiro_controler[linhas_1][colunas_1] = 1;
                }
                else
                {
                    i--;
                }
            }
            printf("\n/////////////////////////////////////////////////////////////////////////");
            printf("\n>>> Modo Dois Jogadores (Alternado) selecionado <<< ");
            printf("\n*************************************************************************");

            printf("\n\n========== TABULEIRO ========\n");

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
            printf("\nINICIANCO O JOGO\n");
            while (TRUE)
            {
                printf("-------------------------------------------------------------------------");
                printf("\n-> [JOGADOR %i] EH A SUA VEZ", id_jogador + 1);
                printf("\nFACA SUA JOGADA\n");

                printf("\n-> Digite a linha do tabuleiro: ");
                scanf("%i", &linha_tabuleiro);
                printf("-> Digite a coluna do tabuleiro: ");
                scanf("%i", &coluna_tabuleiro);

                // verificar se a linha e a posicao ja foi chamada se sim informar que ja foi chamada
                if (tabuleiro_exibicao[linha_tabuleiro][coluna_tabuleiro] == 'X' || tabuleiro_exibicao[linha_tabuleiro][coluna_tabuleiro] == '1')
                {
                    printf("\n################################################################");
                    printf("\nATENCAO JOGADOR [ %i ], A LINHA L [ %i ] E A COLUNA C [ %i ] JA FOI ESCOLHIDA , tente novamente!!!", id_jogador + 1, coluna_tabuleiro);
                    printf("\n################################################################\n");
                    continue;
                }
                else if (linha_tabuleiro < 0 || linha_tabuleiro >= LINHAS)
                {
                    printf("\n################################################################");
                    printf("\nATENCAO JOGADOR [ %i ], O(s) VALOR(es) ACEITOS(s) para a LINHA [ L ] E DE 0 A %i, tente novamente!!!", id_jogador + 1, LINHAS - 1);
                    printf("\n################################################################\n");
                    continue;
                }
                else if (coluna_tabuleiro < 0 || coluna_tabuleiro >= COLUNAS)
                {
                    printf("\n################################################################");
                    printf("\nATENCAO JOGADOR [ %i ], O(s) VALOR(es) ACEITOS(s) para a COLUNA [ C ] E DE 0 A %i, tente novamente!!!", id_jogador + 1, COLUNAS - 1);
                    printf("\n################################################################\n");
                    continue;
                }
                else
                {
                    if (tabuleiro_controler[linha_tabuleiro][coluna_tabuleiro] == 1)
                    {
                        acertos_jogadores[id_jogador]++;
                        tabuleiro_exibicao[linha_tabuleiro][coluna_tabuleiro] = '1';
                        printf("\n********************************************************************");
                        printf("\n********************************************************************");
                        printf("\n *** JOGADOR [%i], PARABENS  VOCE ENCONTROU O NUMERO 1 ***,\nrestam %i numeros 1 (uns) para serem encontrados", id_jogador + 1, ACERTO_UNS_ALTERNADOS - acertos_jogadores[id_jogador]);
                        printf("\n\nPONTUACAO: ");
                        if (id_jogador == 0)
                        {
                            printf("JOGADOR (%i): %i ACERTO(S) X JOGADOR (%i): %i ACERTOS", id_jogador + 1, acertos_jogadores[id_jogador], id_jogador + 2, acertos_jogadores[id_jogador + 1]);
                        }
                        else
                        {
                            printf("JOGADOR (%i): %i ACERTOS X JOGADOR (%i): %i ACERTOS", id_jogador - 1, acertos_jogadores[id_jogador - 1], id_jogador + 1, acertos_jogadores[id_jogador]);
                        }
                        printf("\n\n//////////////////////////////////////////////////////////////////////////////");

                        printf("\nPROXIMA JOGADA!!!");
                        printf("\n-----------------------------------------------------");
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
                        tabuleiro_exibicao[linha_tabuleiro][coluna_tabuleiro] = 'X';
                        printf("\n################################################################");
                        printf("\nJOGADOR (%i) O NUMERO 1 NAO SE ENCONTRA NA POSICAO  L (%i) <--> C (%i)", id_jogador + 1, linha_tabuleiro, coluna_tabuleiro);
                        printf("\n\nPONTUACAO: ");
                        if (id_jogador == 0)
                        {
                            printf("JOGADOR (%i): %i ACERTO(S) X JOGADOR (%i): %i ACERTOS", id_jogador + 1, acertos_jogadores[id_jogador], id_jogador + 2, acertos_jogadores[id_jogador + 1]);
                        }
                        else
                        {
                            printf("JOGADOR (%i): %i ACERTOS X JOGADOR (%i): %i ACERTOS", id_jogador - 1, acertos_jogadores[id_jogador - 1], id_jogador + 1, acertos_jogadores[id_jogador]);
                        }
                        printf("\n\n//////////////////////////////////////////////////////////////////////////////");
                        printf("\nPROXIMA JOGADA!!!");
                        printf("\n-----------------------------------------------------");

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

                } // fim da conferencia de acerto e error.

                // CALCULAR O VENCEDOR
                // VENCEDOR É QUEM ENCONTRAR METADE DOS 1 MAS 1;
                if (acertos_jogadores[id_jogador] == ACERTO_UNS_ALTERNADOS)
                {
                    printf("\n********************************************************************");
                    printf("\n********************************************************************");
                    printf("\n********************************************************************");
                    printf("\n *** JOGADOR %i CAMPEAO ***", id_jogador + 1);
                    printf("\n *** PARABENS JOGADOR %i VOCE ENCONTROU  %i NUMEROS 1 (UNS) ESCONDIDOS NO TABULEIRO ANTES DO OUTRO JOGADOR  ***", id_jogador + 1, ACERTO_UNS_ALTERNADOS);
                    printf("\n-> RESUMO DO JOGO:");
                    printf("\n\nPONTUACAO: ");
                    if (id_jogador == 0)
                    {
                        printf("JOGADOR (%i): %i ACERTO(S) X JOGADOR (%i): %i ACERTOS", id_jogador + 1, acertos_jogadores[id_jogador], id_jogador + 2, acertos_jogadores[id_jogador + 1]);
                    }
                    else
                    {
                        printf("JOGADOR (%i): %i ACERTOS X JOGADOR (%i): %i ACERTOS", id_jogador - 1, acertos_jogadores[id_jogador - 1], id_jogador + 1, acertos_jogadores[id_jogador]);
                    }
                    printf("\n------------------------------------------------------------------------------------------\n");
                    fflush(stdin);
                    printf("\n-> O que deseja fazer agora?\n[ 1 ] -> JOGAR OUTRA PARTIDA MODO ALTERNADO\n[ 2 ] - MENU INICIAL\n[ aperte qualquer  tecla ] -> ENCERRAR  ");
                    scanf("%c", &nova_partida);
                    printf("\n//////////////////////////////////////////////////////////////////////////////\n\n");

                    if (nova_partida == '1')
                    {
                        for (int i = 0; i < 2; i++)
                        {
                            acertos_jogadores[i] = 0;
                        }
                        id_jogador = 0;
                        srand(time(NULL));

                        for (int i = 0; i < LINHAS; i++)
                        {
                            for (int j = 0; j < COLUNAS; j++)
                            {
                                tabuleiro_controler[i][j] = 0;
                                tabuleiro_exibicao[i][j] = '0';
                            }
                        }

                        // Gerar/distribuir aleatoriamente os numeros 10 uns em posições aleatórias
                        for (int i = 0; i < QUANT_UNS; i++)
                        {
                            int linhas_1 = rand() % LINHAS;
                            int colunas_1 = rand() % COLUNAS;
                            if (tabuleiro_controler[linhas_1][colunas_1] == 0)
                            {
                                tabuleiro_controler[linhas_1][colunas_1] = 1;
                            }
                            else
                            {
                                i--;
                            }
                        }
                        printf("========== TABULEIRO ========\n");

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
                    else if (nova_partida == '2')
                    {
                        for (int i = 0; i < 2; i++)
                        {
                            acertos_jogadores[i] = 0;
                        }
                        id_jogador = 0;
                        break;
                    }
                    else
                    {
                        menu_liberado++;
                        break;
                    }
                }

                // ALTERNAR ENTRE O JOGADOR 1 E 2;
                if (id_jogador == 0)
                {
                    id_jogador++;
                    continue;
                }
                else
                {
                    id_jogador--;
                    continue;
                }
                // menu_liberado++;
            }
            break;
        case 3:
            fflush(stdin);
            printf("\n");
            printf("\n =====================================");
            printf("\n INSTRUCOES SOBRE O JOGO DESCUBRA UNS");
            printf("\n =====================================");
            printf("\n//////////////////////////////////////////////////////////////////");
            printf("\n");
            printf("\n >>> O jogo No tabuleiro abaixo existe 10 numeros 1 (uns) escondidos em posicoes aleatorias,\nencontre-os usando a posicao da linha e da coluna, ao acertar a posicao do numero 1 ele sera mostrado no tabuleiro,\ncaso voce erre sera mostrado a letra 'X' na posição no tabuleiro  para indicar o onde o jogador errou");
            printf("\n---------------------------------------------------------");
            printf("\n");
            printf("\n ### Modo Dois Jogadores (Sequencial) ###");
            printf("\n -> O Jogador 1 joga ate encontrar todos os 10 numeros 1(uns) escondidos, Em seguida, o Jogador 2 joga com o mesmo objetivo/desafio. O jogador que encontrar todos os 10 numeros 1 (uns) com menos tentativas vence, ou seja, se o Jogador 2 exceder as tentativas do Jogador 1, perde automaticamente");
            printf("\n---------------------------------------------------------");
            printf("\n");
            printf("\n ### Modo Dois Jogadores (Alternado) ###");
            printf("\n -> No modo de jogo de jogadores alternados, o jogo se inicia com o preenchimento do tabuleiro e logo em seguida, os jogadores 1 e 2, alternadamente, terão a oportunidade de descobrir os números unss até que um dos jogadores encontre cinco números uns e o jogo seja encerrado. Vencerá o jogo aquele jogador que descobrir cinco números uns primeiros. Deve-se considerar que a posição de um número descoberto por um jogador não poderá também ser considerada descoberta pelo outro jogador. Ou seja, uma vez que a posição de um número um é descoberta por um determinado jogador, esta posição deixará de ser acessível para as tentativas do outro jogador.");
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

    // Levando em consideração que os valores que irão sair do do_while serão apenas o 1 ou 2.

    printf("\n-----------------------------------------------------");
    printf("\nOBRIGADO POR JOGAR, VOLTE SEMPRE!!!\n\n");
    printf("\n");
    return 0;
}