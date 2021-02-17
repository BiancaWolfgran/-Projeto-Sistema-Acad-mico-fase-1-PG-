#include "funcoesdadosalunos.h"

//Resultados
void saidastr(char *mensagem)
{
    printf("%s", mensagem);
}


/******PARTE ALUNO******/

char *nomeAluno(char *mensagem)
{
    char *nome = (char *) malloc((sizeof(char) * sizeof(nome)));
    printf("%s", mensagem);
    scanf(" %60[^\n]",nome);
    getchar();
    return nome;
}

//verificação de gênero
char *sexoAluno(char *mensagem)
{
    char *sexo = (char *) malloc((sizeof(char) * sizeof(sexo)));

    printf("%s", mensagem);
    scanf("%c", sexo);
    getchar();

    while(*sexo != 'M' && *sexo != 'F'){
        printf("\tSexo inválido!\n");
        printf("%s", mensagem);
        scanf("%c", sexo);
        getchar();
     }

    return sexo;
}

char *anoNascAluno(char *mensagem){

    char *ano = (char *) malloc((sizeof(char) * sizeof(ano)));

    printf("%s", mensagem);
    scanf("%11[^\n]", ano);
    getchar();

    return ano;
}

float entradafloat(char *mensagem)
{
    float n;
    printf("%s", mensagem);
    scanf("%f", &n);
    return n;
}

void saidafloat(char *mensagem, float valor)
{
    printf("%s%.2f", mensagem, valor);
}

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

/***********PARTE CURSO************/

char *nomeCurso (char *mensagem) {
    char *nomeC = (char *) malloc((sizeof(char) * sizeof(nomeC)));
    printf("%s", mensagem);
    scanf(" %50[^\n]", nomeC);
    getchar();
    return nomeC;
}

char *codigoCurso (char *mensagem) {
    char *codigo = (char *) malloc((sizeof(char) * sizeof(codigo)));
    printf("%s", mensagem);
    scanf(" %6[^\n]", codigo);
    getchar();
    return codigo;
}



