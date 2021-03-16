#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "allMenus.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    menuInicial();
    salvarCursoArquivo(cadastraCurso);
    salvarAlunoArquivo(cadastraAluno);


    return 0;
}
