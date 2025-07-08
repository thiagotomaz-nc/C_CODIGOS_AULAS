#include <stdio.h>

// retorna 1: valor1 > valor2
// retorna 0: valor1 == valor1
//  retorna -1: valor1 < valor2
// ATENÇÃO NÃO PODE TER 2 FUNÇÕES COM O MESMO NOME EM C;
float compara_valores(float, float);
int fatorial(int);

#define N_INDICE 10

// maior_valor(int * vetor); ponteiro apontando para o vetor
int maior_valor(int[], int);

int main(void)
{
    int vetor[] = {10, 32, 5, 6, 11, 1, 20, 3};

    printf("\n O maior numero do vetor eh %i", maior_valor(vetor, 8));
    printf("\nBYTES: %i", sizeof(vetor) / sizeof(int));
    /* TOTAL DE BYTES DO VETOR DIVIDIDO PELOS BYTES OCUPADOS POR UM INTEIRO (4)*/
    return 0;
}

int maior_valor(int vetor[], int tamanho)
{
    int maior = vetor[0];

    for (int i = 1; i < tamanho; i++)
    {
        if (maior < vetor[i])
            maior = vetor[i];
    }

    return maior;
}