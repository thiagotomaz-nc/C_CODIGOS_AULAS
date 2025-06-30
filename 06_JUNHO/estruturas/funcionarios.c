#include <stdio.h>
#include <math.h>

int main()
{
    int n_funcionarios;

    printf("\n -> digite o numero de funcionarios: ");
    scanf("%i", &n_funcionarios);

    if (n_funcionarios > 0)
    {
        int idade_funcionario[n_funcionarios];
        float salario_funcionario[n_funcionarios];
        int rg_funcionario[n_funcionarios];

        printf("\n ***** CADASTRO DE FUNCIONARIOS ***** ");

        for (int i = 0; i < n_funcionarios; i++)
        {
            printf("\n *** Digite o dados para o funcionario [%i] ***", i);
            printf("\n-> idade: ");
            scanf("%i", &idade_funcionario[i]);

            printf("->Salario: ");
            scanf("%f", &salario_funcionario[i]);

            printf("->RG: ");
            scanf("%i", &rg_funcionario[i]);

            printf("\n");
        }

        printf("\n ********* MEDIAS DOS FUNCIONARIOS ********* \n");

        int soma_idade = 0;
        float soma_salario = 0.0;

        for (int i = 0; i < n_funcionarios; i++)
        {
            soma_idade += idade_funcionario[i];
            soma_salario += salario_funcionario[i];
        }

        printf("\n -> Media das idades: %.0lf", round(soma_idade / n_funcionarios));
        printf("\n -> Media Salarial: R$ %.2f", soma_salario / n_funcionarios);
    }

    return 0;
}