#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "funcoesmatematicas.h"

#define QTD 1

typedef struct aluno Aluno;
struct aluno
{
    char *nome, *cpf, *sexo;
    char *anoNasc;
    float notas[3], mediafinal;
    char status;  // 1 = aprovado  0 = reprovado
};


//____________________variaveis globais

// ***** melhor n�o ter***
//______________________________________


//_______Headers________________________
void saidastr(char *mensagem);
void saidafloat(char *mensagem, float valor);
char *nomeAluno(char *mensagem);
char *sexoAluno(char *mensagem);
char *anoNascAluno(char *mensagem);
float entradafloat(char *mensagem);
void imprime_aprovacao(char status);
int checa_aprovacao(float m, float referencia);
//______________________________________


//Resultados
void saidastr(char *mensagem)
{
    printf("%s", mensagem);
}

//M�dia final
void saidafloat(char *mensagem, float valor)
{
    printf("%s%.2f", mensagem, valor);
}

//Nome aluno
char *nomeAluno(char *mensagem)
{
    char *nome = (char *) malloc((sizeof(char) * sizeof(nome)));
    printf("%s", mensagem);
    scanf(" %60[^\n]",nome);
    getchar();
    return nome;
}

//verifica��o de g�nero
char *sexoAluno(char *mensagem)
{
    char *sexo = (char *) malloc((sizeof(char) * sizeof(sexo)));
    char masculino = 'M';
    char feminino = 'F';

     printf("%s", mensagem);
     scanf("%c", sexo);
     getchar();

     while(*sexo != 'M' && *sexo != 'F'){
        printf("\tSexo inv�lido!\n");
        printf("%s", mensagem);
        scanf("%c", sexo);
        getchar();
     }

    return sexo;
}

char *anoNascAluno(char *mensagem){

    char *ano = (char *) malloc((sizeof(char) * sizeof(ano)));

    printf("%s", mensagem);
    scanf("%15[^\n]", ano);
    getchar();

    return ano;
}

//Notas
float entradafloat(char *mensagem)
{
    float n;
    printf("%s", mensagem);
    scanf("%f", &n);
    return n;
}

// referencia = valor para aprovacao   *********
void imprime_aprovacao(char status)
{
    if (status)
    {
        saidastr("\n => status = APROVADO\n\n\n");
    }
    else
    {
        saidastr("\n => status = REPROVADO\n\n\n");
    }
}

int checa_aprovacao(float m, float referencia)
{
    if (m >= referencia)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void finalizar()
{
    system("cls");
    system("color 2E");
    saidastr("\n\n #################### FIM ####################\n\n");
}

void inicializar()
{
    setlocale(LC_ALL, "Portuguese");
    system("cls"); // system("clear"); linux
    system("color 1F");
    saidastr("#################### Notas Alunos ####################\n\n\n");
}


void gerente()
{
    Aluno alunos[QTD];
    int a = 0, i;
    // ----------------------ENTRADA DE DADOS ---------------------
    for (i=0; i < QTD; i++)
    {
        a++;
        printf("#Aluno: %d\n", a);
        alunos[i].nome = nomeAluno("\tDigite nome aluno(a): ");
        alunos[i].sexo = sexoAluno("\n\tDigite sexo aluno(a), M para masculino, F para feminino: ");
        alunos[i].anoNasc = anoNascAluno("\n\tDigite ano de nascimento: ");
        alunos[i].notas[0] = entradafloat("\n\tDigite nota 1: ");
        alunos[i].notas[1] = entradafloat("\tDigite nota 2: ");
        alunos[i].notas[2] = entradafloat("\tDigite nota 3: ");
        alunos[i].mediafinal = mediaa(alunos[i].notas, 3);
        alunos[i].status = checa_aprovacao(alunos[i].mediafinal, 6);
        system("cls");
    }
    // ----------------------SAIDA DE DADOS ---------------------
    saidastr("\n-------------RELAT�RIO-------------------");
    system("color 8F");
    a = 0;
    for (i=0; i < QTD; i++)
    {
        a++;
        printf("\n#Aluno: %d\n", a);
        saidafloat("\n M�dia Final= ", alunos[i].mediafinal);
        saidastr("\n  ALUNO: ");
        saidastr(alunos[i].nome);
        saidastr("\n  SEXO: ");
        saidastr(alunos[i].sexo);
        saidastr("\n  DATA DE NASCIMENTO: ");
        saidastr(alunos[i].anoNasc);
        imprime_aprovacao(alunos[i].status);
        system("pause");
    }
    float maiormedia = 0;
    for (i=0; i < QTD; i++)
    {
        if (alunos[i].mediafinal > maiormedia)
        {
            maiormedia = alunos[i].mediafinal;
            a = i;
        }
    }
    saidastr("\n\n__________________________");
    saidastr("\n Maior m�dia: ");
    saidastr(alunos[a].nome);
    saidafloat("\n---M�dia= ", alunos[a].mediafinal);
    saidastr("\n\n__________________________");

    system("pause");
}

int main()
{
    inicializar();
    gerente();
    finalizar();
    return 0;
}

