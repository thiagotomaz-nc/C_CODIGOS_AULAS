#include <stdio.h>

#define N_MAX_ALUNOS 100

struct Aluno
{
 
    int matricula;
    char nome[100];
    float media_final;
};

int main(void)
{
    int n_alunos;

    printf("\n -> Digite a quantidade de alunos: ");
    scanf("%i", &n_alunos);

    if (n_alunos > 0 && n_alunos < N_MAX_ALUNOS)
    {
        struct Aluno alunos[n_alunos];

        printf("\n ***** CADASTRO DE ALUNOS *****\n");
        for (int i = 0; i < n_alunos; i++)
        {
            
            fflush(stdin);
            printf("\n----> Aluno %i ---- ", i + 1);
            scanf("%s", &alunos[i].nome);
            printf("\n----> Matricula %i ---- ", i + 1);
            scanf("%i", &alunos[i].matricula);
            printf("\n----> Media %i ---- ", i + 1);
            scanf("%f", &alunos[i].media_final);
        }

        printf("\n***** DADOS DO ALUNO *****\n");
        for (int i = 0; i < n_alunos; i++)
        {

            printf("\n----> MATRICULA %i ---- ", alunos[i].matricula);
            printf("\n----> Nome: %s ---- ", alunos[i].nome);
            printf("\n----> Media: %.1f ", alunos[i].media_final);
            printf("\n----> Status: %s", (alunos[i].media_final >= 6) ? "Aprovado" : "Reprovado");

            printf("\n\n------------------------------------------------------\n ");
        }
    }

    return 0;
}