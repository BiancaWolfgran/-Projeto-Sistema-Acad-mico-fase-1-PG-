#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "funcoesmatematicas.h"
#include "funcoesdadosalunos.h"

#define QTD 1


//Struct criação de aluno
typedef struct aluno Aluno;
struct aluno
{
    char *nome, *cpf, *sexo;
    char *anoNasc;
    float notas[3], mediafinal;
    char status;  // 1 = aprovado  0 = reprovado
};

//Struct criação de curso
typedef struct curso Curso;
struct curso{

    char *nomeC;
    char *codigo;
    char *disciplina;
};

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
    // ====> ALUNO
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

    // ====> CURSOS
   /* int c = 0;
    Curso curso[c];
    char *qtdCurso = (char *) malloc((sizeof(char) * sizeof(qtdCurso)));;


    printf("\t\nDeseja adicionar curso? S/N: ");
    scanf("%c", qtdCurso);
    getchar();
    while(qtdCurso != 'N') {
        c++;
        printf("\n#Curso: %d\n", c);
        curso[i].nomeC = nomeCurso("\tDigite o nome do curso: ");
        curso[i].codigo = codigoCurso("\tDigite o código do curso: ");
        printf("\t\nDeseja adicionar curso? S/N.");
        system("cls");
    } */

    // ----------------------SAIDA DE DADOS ---------------------
    saidastr("\n-------------RELATÓRIO-------------------");
    system("color 8F");
    a = 0;
    for (i=0; i < QTD; i++)
    {
        a++;
        printf("\n#Aluno: %d\n", a);
        saidafloat("\n Média Final= ", alunos[i].mediafinal);
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
    saidastr("\n Maior média: ");
    saidastr(alunos[a].nome);
    saidafloat("\n---Média= ", alunos[a].mediafinal);
    saidastr("\n\n__________________________");

    system("pause");
}


int main() {

    inicializar();
    gerente();
    finalizar();
    return 0;

}
