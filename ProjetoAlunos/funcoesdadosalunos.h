/********************************************************************
================> funcoesdadosalunos.h
Cabeçalho das funcões implementadas no módulo funcoesdadosalunos.c,
que servem para adicionar dados para os alunos.
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesmatematicas.h"

//Função para impressão de dados
void saidastr(char *mensagem);

//#####ALUNO#####

//Função adição de nome de aluno
char *nomeAluno(char *mensagem);

//Verificação de sexo de aluno
char *sexoAluno(char *mensagem);

//Adição de data de nascimento para aluno
char *anoNascAluno(char *mensagem);

//Notas
float entradafloat(char *mensagem);

//Média final
void saidafloat(char *mensagem, float valor);

//Mensagem de aprovação ou reprovação
void imprime_aprovacao(char status);

//Verificação de aprovação ou reprovação
int checa_aprovacao(float m, float referencia);

//######CURSO#####

//Nome do curso
char *nomeCurso (char *mensagem);

//Código do curso
char *codigoCurso(char *mensagem);
