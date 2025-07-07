#include <stdio.h>

/*deve ser declarada antes de ser usada/chamada, por isso ela foi chamada ante do main, a não ser que eu crie o prototipo dele*/
/*prototipo da função somarNumeros*/
// mão preciso colocar o nome dos parametros na função
float somarNumeros(float, float);
void exibir_resultado_soma(float, float);

int main(void)
{

    float num1, num2;

    printf("\n-> Digite o primeiro numero: ");
    scanf("%f", &num1);

    printf("-> Digite o segundo numero: ");
    scanf("%f", &num2);

    exibir_resultado_soma(num1, num2);

    return 0;
}

float somarNumeros(float num1, float num2)
{
    return num1 + num2;
}

void exibir_resultado_soma(float n1, float n2)
{
    printf("\nO valor da soma: %.2f + %.2f = %.2f\n\n", n1, n2,somarNumeros(n1,n2));
}