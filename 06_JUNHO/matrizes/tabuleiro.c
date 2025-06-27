#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LINHAS 3
#define COLUNAS 3
#define QUANT_UNS 4 // -> Essa constante vai servir apenas para controlar a quantidade de uns a serem gerados
#define TRUE 1

int main(void)
{
    char tabuleiro_exibicao[LINHAS][COLUNAS], nova_partida;
    int tabuleiro_controler[LINHAS][COLUNAS];
    int acertos_jogadores[2] = {0, 0}, tentativas_jogadores[2] = {0, 0}, id_jogador = 0;
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
        // TAREFAS DE CADA OPCAO DO MENU
        switch (modo_jogo)
        {
        case 0:
            printf("\n -> Voce saiu do jogo, ate mais");
            menu_liberado++;
            break;
        case 1:
            printf("\n********************************************");
            printf("\n>>> Modo Dois Jogadores (Sequencial) selecionado <<< \n");
            printf("\n---------------------------------------------------------------");

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
                printf("\n-> Eh a vez do [Jogador 1] | RESUMO: %i acertos <-> %i tentativas", acertos_jogadores[id_jogador], tentativas_jogadores[id_jogador]);
                printf("\nFACA SUA JOGADA\n");

                printf("\n-> Digite a linha do tabuleiro: ");
                scanf("%i", &linha_tabuleiro);
                printf("-> Digite a coluna do tabuleiro: ");
                scanf("%i", &coluna_tabuleiro);

                // verificar se a linha e a posicao ja foi chamada se sim informar que ja foi chamada
                if (tabuleiro_exibicao[linha_tabuleiro][coluna_tabuleiro] == 'X' || tabuleiro_exibicao[linha_tabuleiro][coluna_tabuleiro] == '1')
                {
                    printf("\n################################################################");
                    printf("\nA LINHA L [ %i ] E A COLUNA C [ %i ] JA FOI ESCOLHIDA , tente novamente!!!", linha_tabuleiro, coluna_tabuleiro);
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
                        printf("\n *** PARABENS VOCE ENCONTROU O NUMERO 1 ***,\nrestam %i numeros 1 (uns) para serem encontrados", QUANT_UNS - acertos_jogadores[id_jogador]);
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
                        printf("\nNAO EXISTE 1 NESSA POSICAO  L [ %i ] <--> C [ %i ]  , tente novamente!!!", linha_tabuleiro, coluna_tabuleiro);
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
                    //SITUAÇÃO EM QUE O JOGADOR 2 VENCE
                    else if (id_jogador == 1 && tentativas_jogadores[id_jogador] <= tentativas_jogadores[id_jogador - 1])
                    {
                        if (acertos_jogadores[id_jogador] == QUANT_UNS && tentativas_jogadores[id_jogador] == tentativas_jogadores[id_jogador - 1] )
                        {
                            printf("\n********************************************************************");
                            printf("\n********************************************************************");
                            printf("\n********************************************************************");
                            printf("\n *** O jogador %i EMPATOU com o jogador %i ***", id_jogador, id_jogador+1);
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
                        }else  if (acertos_jogadores[id_jogador] == QUANT_UNS && tentativas_jogadores[id_jogador] != tentativas_jogadores[id_jogador - 1] )
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
                    }//jogador 1 venceu
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
        case 2:
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

    // Levando em consideração que os valores que irão sair do do_while serão apenas o 1 ou 2.

    printf("\n-----------------------------------------------------");
    printf("\nOBRIGADO POR JOGAR, VOLTE SEMPRE!!!\n\n");
    printf("\n");
    return 0;
}