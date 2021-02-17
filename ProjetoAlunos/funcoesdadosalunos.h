/********************************************************************
================> funcoesdadosalunos.h
Cabe�alho das func�es implementadas no m�dulo funcoesdadosalunos.c,
que servem para adicionar dados para os alunos.
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesmatematicas.h"

//Fun��o para impress�o de dados
void saidastr(char *mensagem);

//#####ALUNO#####

//Fun��o adi��o de nome de aluno
char *nomeAluno(char *mensagem);

//Verifica��o de sexo de aluno
char *sexoAluno(char *mensagem);

//Adi��o de data de nascimento para aluno
char *anoNascAluno(char *mensagem);

//Notas
float entradafloat(char *mensagem);

//M�dia final
void saidafloat(char *mensagem, float valor);

//Mensagem de aprova��o ou reprova��o
void imprime_aprovacao(char status);

//Verifica��o de aprova��o ou reprova��o
int checa_aprovacao(float m, float referencia);

//######CURSO#####

//Nome do curso
char *nomeCurso (char *mensagem);

//C�digo do curso
char *codigoCurso(char *mensagem);
