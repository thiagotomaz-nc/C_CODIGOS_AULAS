#include <stdio.h>
#include <string.h>

#define N_MAX_ALUNOS 100

struct Aluno
{

    int matricula;
    char nome[50];
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
            printf("\n\n------------------------------------------------------\n ");
        }

        printf("\n***** DADOS DO ALUNO *****\n");

        for (int i = 0; i < n_alunos; i++)
        {                                              // percorrer todos os indices do vetor
            for (int j = i + 1; j < n_alunos - 1; j++) // percorrer os elementos dos vetores seguinte
            {
                if (alunos[i].media_final < alunos[j].media_final)
                {
                    int aux_media = alunos[i].media_final;
                    int aux_matricula = alunos[i].matricula;
                    char aux_nome[50];
                    // primeiro e o destino, e o segundo e a origem
                    strcpy(aux_nome, alunos[i].nome); // para funcionar os a string inicial e a de destino devem ter obrigatoriamente o mesmo tamanho;

                    alunos[i].matricula = alunos[j].matricula;
                    alunos[i].media_final = alunos[j].media_final;
                    strcpy(alunos[j].nome, alunos[i].nome);

                    alunos[j].matricula = aux_matricula;
                    alunos[j].media_final = aux_media;
                    strcpy(alunos[j].nome, aux_nome);
                }
            }
        }

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