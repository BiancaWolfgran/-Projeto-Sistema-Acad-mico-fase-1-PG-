/************************************************************************
                                CADASTROS.H
    Cabe�alho com todas as fun��es de cadastro de alunos e cursos
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "funcoesmatematicas.h"

//CURSOS

void cadastraCurso();

int buscaPosicaoCurso(int codigo);

void alteraCurso();

void consultaCursos();


//ALUNOS

void cadastraAluno();

int buscaPosicaoAluno(int cpf);

void editaAluno();

void listarAlunos();

//CONSULTAS

void nomeAluno();
//consulta de aluno por nome;

void cpfAluno();
//consulta de aluno por cpf.

void disciplinaCurso();
//consulta de disciplinas por curso.

//RELAT�RIOS

void listaDeAlunos();

void alunosAprovados();

void alunosReprovados();
