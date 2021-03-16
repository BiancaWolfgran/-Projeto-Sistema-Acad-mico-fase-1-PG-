#include "allMenus.h"

void menuInicial() {

    int opcao;

    puts("\tSISTEMA ACADÊMICO:");
    puts("#######################################################################");
    puts("1 - Cadastrar curso;");
    puts("2 - Cadastrar aluno;");
    puts("3 - Consultas (alunos/cursos);");
    puts("4 - Relatórios;");
    puts("5 - Sair;");
    printf("\t\nDigite a opção desejada: ");
    scanf("%d", &opcao);
    getchar();

    switch(opcao){
    case 1:
        system("cls");
        menuCursos();
        break;
    case 2:
        system("cls");
        menuAlunos();
        break;
    case 3:
        system("cls");
        menuConsultas();
        break;
    case 4:
        system("cls");
        menuRelatorios();
        break;
    case 5:
        printf("\nAté mais!\n");
        Sleep(5);
        exit(0);
    default:
        system("cls");
        printf("\tERRO, OPÇÃO INVÁLIDA!  TENTE NOVAMENTE\n\n");
        menuInicial();
        break;
    }
}

void menuCursos() {

    int codigo;

    puts("###############");
    puts("\t\tCURSO");
    puts("###############");
    puts("1 - Cadastrar novo curso.");
    puts("2 - Alterar dados de curso.");
    puts("3 - Consulta de cursos.");
    puts("4 - Voltar.");
    printf("\t\nDigite a opção desejada: ");
    scanf("%d", &codigo);
    getchar();

    switch(codigo){
    case 1:
        system("cls");
        cadastraCurso();
        break;
    case 2:
        system("cls");
        alteraCurso();
        break;
    case 3:
        system("cls");
        consultaCursos();
        break;
    case 4:
        system("cls");
        menuInicial();
        break;
    default:
        printf("\tERRO, OPÇÃO INVÁLIDA!!!");
        Sleep(5);
        menuCursos();
        break;
    }
}


void menuAlunos() {

    int opcao;
    puts("######################");
    puts("\t\t\nALUNO");
    puts("######################");
    puts("1 - Cadastrar novo aluno.");
    puts("2 - Alterar dados de aluno.");
    puts("3 - Lista alunos cadastrados.");
    puts("4 - Voltar.");
    printf("\t\nDigite a opção desejada: ");
    scanf("%d", &opcao);
    getchar();

   switch(opcao){
    case 1:
        system("cls");
        cadastraAluno();
        break;
    case 2:
        system("cls");
        editaAluno();
        break;
    case 3:
        system("cls");
        listarAlunos();
        break;
    case 4:
        system("cls");
        menuInicial();
        break;
    default:
        system("cls");
        printf("\tERRO, OPÇÃO INVÁLIDA!!!");
        menuAlunos();
        break;
    }
}

void menuConsultas() {

    int codigo;
    puts("####################");
    puts("\t\tCONSULTAS");
    puts("####################");
    puts("1 - Consultar aluno por nome.");
    puts("2 - Consultar aluno por CPF.");
    puts("3 - Consultar disciplinas por curso");
    puts("4 - Voltar.");
    printf("\tDigite a opção desejada: ");
    scanf("%d", &codigo);
    getchar();

    switch(codigo){
    case 1:
        system("cls");
        nomeAluno();
        break;
   case 2:
        system("cls");
        cpfAluno();
        break;
   case 3:
        system("cls");
        disciplinaCurso();
        break;
    case 4:
        system("cls");
        menuInicial();
        break;
    default:
        system("cls");
        printf("\tERRO, OPÇÃO INVÁLIDA!!!");
        menuConsultas();
        break;
    }
}

void menuRelatorios() {

    int opcao;
    puts("#####################");
    puts("\t\tRELATÓRIOS");
    puts("#####################");
    puts("1 - Lista de alunos.");
    puts("2 - Lista de alunos aprovados.");
    puts("3 - Lista de alunos reprovados.");
    puts("4 - Voltar.");
    printf("\tDigite a opção desejada: ");
    scanf("%d", &opcao);
    getchar();

    switch(opcao){
    case 1:
        system("cls");
        listaDeAlunos();
        break;
    case 2:
        system("cls");
        alunosAprovados();
        break;
    case 3:
        system("cls");
        alunosReprovados();
        break;
    case 4:
        system("cls");
        menuInicial();
        break;
    default:
        system("cls");
        printf("\tERRO, OPÇÃO INVÁLIDA!!!");
        menuRelatorios();
        break;
    }
}
