#include <stdio.h>

int main(void){
    int linhas_A, colunas_A, linhas_B, colunas_B;

    printf("-> Digite numero de linhas e colunas de A: ");
    scanf("%i %i", &linhas_A, &colunas_A);
    
    printf("-> Digite numero de linhas e colunas de B: ");
    scanf("%i %i", &linhas_B, &colunas_B);
   

    if(linhas_A > 0 && colunas_A > 0 && linhas_B > 0 && colunas_B > 0){
        if(linhas_A == linhas_B && colunas_A==colunas_B){
            //a adição matricial só é possivel com matrizes
            // de mesma dimensão
            int matrizA[linhas_A][colunas_A];
            int matrizB[linhas_B][colunas_B];

            //agora vou preencher a matriz A
            printf("\n ===========Preenchendo a matriz A ===========");
            for (int i = 0; i<linhas_A;i++){
                for (int j = 0; j<colunas_A; j++){
                    printf("\n -> Digite o valor para a matriz A[%i][%i]: ", i,j);
                    scanf("%i", &matrizA[i][j]);
                }
            }

            printf("\n ===========Preenchendo a matriz B ===========");
            for (int i = 0; i<linhas_A;i++){
                for (int j = 0; j<colunas_A; j++){
                    printf("\n -> Digite o valor para a matriz B[%i][%i]: ", i,j);
                    scanf("%i", &matrizB[i][j]);
                }
            }

            int soma_matriz[linhas_A][colunas_A];
            printf("\n =========== Somando as matrizes A + B ===========");
            for (int i = 0; i<linhas_A;i++){
                for (int j = 0; j<colunas_A; j++){
                    soma_matriz[i][j] = matrizA[i][j]+matrizB[i][j];
                    printf("\n -> %i + %i = %i ", matrizA[i][j],matrizB[i][j], soma_matriz[i][j]);
                   
                }
            }
            printf("\n =========== Matriz  soma (A + B) ===========\n");
            for (int i = 0; i<linhas_A;i++){
                for (int j = 0; j<colunas_A; j++){
                    printf("%i ",soma_matriz[i][j]);
                   
                }
                printf("\n");
            }
            
        }else{
            printf("ERROR, As matrizes devem ter a mesma dimensao!");
        }
    }else{
        printf("Error, nao existe matriz com o valor negativo ou igual a zero!");
    }

}