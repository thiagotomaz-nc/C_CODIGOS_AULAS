#include <stdio.h>

// retorna 1: valor1 > valor2
// retorna 0: valor1 == valor1
//  retorna -1: valor1 < valor2
//ATENÇÃO NÃO PODE TER 2 FUNÇÕES COM O MESMO NOME EM C;
float compara_valores(float valor1, float valor2);

int main(void)
{
    int numero;
    float n1, n2;

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

    /*printf("\n-> Digite segundo numero: ");
    scanf("%i", &numero)
    printf("O fatorial de %i eh: %i\n\n", numero, fatorial(numero) );
    */

    return 0;
}

//compara valor1 com o valor2
//A ordem interfere na comparação
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