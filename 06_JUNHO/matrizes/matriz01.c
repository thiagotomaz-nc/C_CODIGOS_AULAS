#include <stdio.h>

int main(void){
    int n_colunas, n_linhas;

    printf("-> Digite numero de linhas: ");
    scanf("%i", &n_linhas);

    printf("-> Digite numero de linhas: ");
    scanf("%i", &n_colunas);

    if(n_linhas > 0 && n_colunas > 0){

        int matriz [n_linhas][n_colunas];

        for (int i = 0; i < n_linhas; i++){
            for (int j = 0; j < n_colunas; j++){
                // matriz diagonal
                if(i == j){
                    matriz[i][j] = 1;
                }else{
                    matriz[i][j] = 0;
                }
               
                printf("%i ", matriz[i][j]);
            }
            printf("\n");
        }

    }

    return 0;

}