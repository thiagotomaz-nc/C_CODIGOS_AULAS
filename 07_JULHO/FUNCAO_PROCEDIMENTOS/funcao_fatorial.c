#include <stdio.h>

// retorna 1: valor1 > valor2
// retorna 0: valor1 == valor1
//  retorna -1: valor1 < valor2
// ATENÇÃO NÃO PODE TER 2 FUNÇÕES COM O MESMO NOME EM C;
float compara_valores(float, float);
int fatorial(int);

#define N_INDICE 10

// maior_valor(int * vetor); ponteiro apontando para o vetor
int maior_valor(int [], int);

int main(void)
{
    int numero;
    float n1, n2;
    int vetor[] = {10,32,5,6,11,1,20,3};

    printf("\n O maior numero do vetor eh %i", maior_valor(vetor,8));
    return 0;
    
    /*---------------------------------------*/

    printf("\n-> Digite um numero: ");
    scanf("%i", &numero);

    printf(" %i! = %i\n\n", numero, fatorial(numero));

    return 0;

    /*--------------------------------------------------------------*/

    printf("\n-> Digite 2 numeros: ");
    scanf("%f %f", &n1, &n2);

    int comparacao = compara_valores(n1, n2);
    switch (comparacao)
    {
    case 1:
        printf("%.2f > %.2f", n1, n2);
        break;
    case 0:
        printf("%.2f = %.2f", n1, n2);
        break;
    case -1:
        printf("%.2f < %.2f", n1, n2);
        break;
    default:
        break;
    }

    return 0;
}

int fatorial(int numero)
{
    int fatorial = 1;
    if (numero >= 0)
    {
        for (int i = 1; i <= numero; i++)
        {
            fatorial *= i;
        }

        return fatorial;
    }
    else
    {
        printf("ERRO: Não existe Fatorial de numeros negativos!!!");
        return -1;
    }
}

// compara valor1 com o valor2
// A ordem interfere na comparação
float compara_valores(float valor1, float valor2)
{
    int valor = 0;
    if (valor1 > valor2)
    {
        return 1;
    }
    else if (valor1 < valor2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

/*float compara_valores(float valor1,float valor2){
   return valor1 - valor2;
}*/

int maior_valor(int vetor[], int tamanho){
    int maior=vetor[0];

    for (int i =1; i<tamanho;i++){
        if (maior < vetor[i]) maior=vetor[i];
    }

    return maior;
}