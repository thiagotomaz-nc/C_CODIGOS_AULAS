#include <stdio.h>

struct Aluno
{
    int matricula, idade;
    char nome[50];
    double nota1, nota2;
};

typedef struct Aluno Aluno;

struct Aluno alunos[10];

void Cadastrar_alunos(int num_alunos, Aluno * alunos);
void imprimir_relatorios_alunos(int num_alunos, Aluno * alunos);
double calcular_media(int matricula, Aluno * alunos);

int main(void)
{

    // matrícula, nome, idade, nota1 e nota2.
    char nome_aluno;
    double nota1, nota2;
    int matricula, idade, menu, numero_alunos;

    printf("\n-> Informe a quantidade de alunos: ");
    scanf("%i", &numero_alunos);
    
    scanf("%c", &nome_aluno);
    Aluno alunos[numero_alunos];

    // o nome de um vetor já é um ponteiro por natureza
    // por isso não necessita de colocar um &.
    Cadastrar_alunos(numero_alunos, alunos);
    imprimir_relatorios_alunos(numero_alunos, alunos);
    
    printf("\n Media: %lf", calcular_media(1, alunos));

    return 0;
}

void Cadastrar_alunos(int num_alunos, Aluno *alunos)
{
    char auxiliar;

    printf("\n            CADASTRO DE ALUNO");
    printf("\n -----------------------------------------");
    for (int i = 0; i < num_alunos; i++)
    {

        // equivale a *(aluno+i)
        alunos[i].matricula = i + 1;
        printf("\n - Matricula: %i", alunos[i].matricula);

        // fflush(stdin);
        fflush(stdin);
        printf("\n -> Nome: ");
        fgets(alunos[i].nome, 50, stdin);

        printf("-> idade: ");
        scanf("%i", &alunos[i].idade);

        printf(" -> nota 1: ");
        scanf("%lf", &alunos[i].nota1);

        printf("-> nota 2: ");
        scanf("%lf", &alunos[i].nota2);

        scanf("%c", &auxiliar);
    }
}

void imprimir_relatorios_alunos(int num_alunos, Aluno * alunos){

     printf("\n            RELATORIO DE ALUNOS");
    printf("\n -----------------------------------------");
    for (int i = 0; i < num_alunos; i++)
    {
        printf("\n * Matricula: %i",alunos[i].matricula);
        printf("\n * Nome: %s",alunos[i].nome);
        printf(" * Idade: %i",alunos[i].idade);
        printf("\n * Nota 01: %lf",alunos[i].nota1);
        printf("\n * Nota 02: %lf",alunos[i].nota2);
        printf("\n\n");
    }
    
}

double calcular_media(int matricula, Aluno * alunos){
    return (alunos[matricula-1].nota1 + alunos[matricula-1].nota1) /2;
}