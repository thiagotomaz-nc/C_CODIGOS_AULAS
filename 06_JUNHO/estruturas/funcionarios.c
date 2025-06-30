#include <stdio.h>
#include <math.h>

//definido pelo usuario
typedef struct Funcionario
{
    int idade;
    float salario;
    int rg;
};


int main()
{
    int n_funcionarios;

    printf("\n -> digite o numero de funcionarios: ");
    scanf("%i", &n_funcionarios);

    if (n_funcionarios > 0)
    {
        struct Funcionario funcionarios[n_funcionarios];

        printf("\n ***** CADASTRO DE FUNCIONARIOS ***** ");

        for (int i = 0; i < n_funcionarios; i++)
        {
            printf("\n *** Digite o dados para o funcionario [%i] ***", i);
            printf("\n-> idade: ");
            scanf("%i", &funcionarios[i].idade);

            printf("->Salario: ");
            scanf("%f", &funcionarios[i].salario);

            printf("->RG: ");
            scanf("%i", &funcionarios[i].rg);

            printf("\n");
        }

        printf("\n ********* MEDIAS DOS FUNCIONARIOS ********* ");

        int soma_idade = 0;
        float soma_salario = 0.0;

        for (int i = 0; i < n_funcionarios; i++)
        {
            soma_idade += funcionarios[i].idade;
            soma_salario += funcionarios[i].salario;
        }

        printf("\n -> Media das idades: %.0lf", round(soma_idade / n_funcionarios));
        printf("\n -> Media Salarial: R$ %.2f", soma_salario / n_funcionarios);
    }

    printf("\n");

    return 0;
}