#include "cadastros.h"
#define MAX_DISCIPLINAS 4

struct Disciplina{
    char *nome[30];
};

struct Curso{
    int codigo;
    char nome[30];
    struct Disciplina disciplinas[MAX_DISCIPLINAS];
};

struct Aluno{
    char cpf[12];
    char nome[60];
    char sexo;
    char dataNasc[11];
    int codigoCurso;
    float notas[4];
};

struct Curso *cursos;
struct Disciplina *disciplina;
struct Aluno *alunos;
static int contadorCursos = 0;
static int qtdAlunos = 0;

//******CURSOS******

void cadastraCurso() {

    int qtd;

    printf("Quantos cursos deseja cadastrar? ");
    scanf("%d", &qtd);

    cursos = (struct Curso*)malloc(qtd * sizeof(struct Curso));
    disciplina = (struct Disciplina*)malloc(sizeof(struct Disciplina));

	for(contadorCursos = 0; contadorCursos < qtd; contadorCursos++){
        printf("Digite o código do curso: ");
        scanf("%d", &cursos[contadorCursos].codigo);
        getchar();
        printf("Digite o nome do curso: ");
        scanf("%31[^\n]", cursos[contadorCursos].nome);
        getchar();
        for(int j = 0; j < MAX_DISCIPLINAS; j ++){
            printf("Digite o nome da disciplina %d do curso: ", j+1);
            scanf("%30[^\n]", disciplina[j].nome);
            getchar();
        }
	}
	menuCursos();

}

void salvarCursoArquivo(struct Curso *lista) {
    FILE* fp;

    fp = fopen("sistemaAcademico.txt", "a");
    if(fp == NULL){
        fprintf(stderr, "Erro, não foi possível abrir o arquivo\n");
        return 1;
    }

    for(int i = 0; i < qtdAlunos; i++){
        fprintf(fp, "Código: %d \n", cursos[i].codigo);
        fprintf(fp, "Nome: %s \n", cursos[i].nome);
        for(int j = 0; j < MAX_DISCIPLINAS; j++){
            fprintf(fp, "Disciplina %d: %s \n", j+1, disciplina[j].nome);
        }
    }

    fclose(fp);
}

int buscaPosicaoCurso(int codigo) {

    int posicaoCurso = 0;

    if(contadorCursos > 0){
        for(int i = 0; i < contadorCursos; i++){
			if(cursos[i].codigo == codigo){
				break;
			}
			posicaoCurso++;
		}
	}

    return posicaoCurso;
}

void alteraCurso() {

    int codigo;
    printf("Digite o código do curso que deseja editar: ");
    scanf("%d", &codigo);
    getchar();

    int indiceCurso = buscaPosicaoCurso(codigo);

    printf("Digite o novo nome para o curso: ");
    scanf("%30[^\n]", cursos[indiceCurso].nome);
    getchar();
    for(int i = 0; i < MAX_DISCIPLINAS; i++){
        printf("Digite o nome da disciplina %d do curso: ", i+1);
            scanf("%30[^\n]", disciplina[i].nome);
            getchar();
    }

    menuCursos();

}

void consultaCursos(){
    printf("entrou\n");
    for(int i = 0; i < contadorCursos; i++){
        printf("------------------------------\n");
        printf("Código: %d \n", cursos[i].codigo);
        printf("Nome: %s \n", cursos[i].nome);
        for(int j = 0; j < MAX_DISCIPLINAS; j++){
            printf("Disciplina %d: %s \n", j+1, disciplina[j].nome);
        }
    }
    menuCursos();
}

//*******ALUNOS******

void cadastraAluno() {

    int cpfEValido;
    int qtd;

    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &qtd);
    getchar();

    alunos = (struct Aluno*)malloc(qtd * sizeof(struct Aluno));

    for(qtdAlunos = 0; qtdAlunos < qtd; qtdAlunos++){
        printf("Digite o nome do aluno(a): ");
        scanf("%65[^\n]", alunos[qtdAlunos].nome);

        printf("Digite o CPF do aluno: ");
        scanf("%s", alunos[qtdAlunos].cpf);
        getchar();
        cpfEValido =1;
        //validarcpf(alunos[qtdAlunos].cpf);
        while(cpfEValido == 0){
            printf("CPF inválido. Digite novamente: ");
            scanf("%s", alunos[qtdAlunos].cpf);
            cpfEValido = validarcpf(alunos[qtdAlunos].cpf);
        }
        fflush(stdin);


        printf("Digite o sexo do(a) aluno(a), F  para feminino, M para masculino: ");
        scanf("%c", &alunos[qtdAlunos].sexo);
        getchar();

        while(alunos[qtdAlunos].sexo != 'M' && alunos[qtdAlunos].sexo != 'F'){
            printf("\tSexo inválido!\n");
            printf("Digite o sexo do(a) aluno(a), F  para feminino, M para masculino: ");
            scanf("%c", &alunos[qtdAlunos].sexo);
            getchar();
        }

         printf("Digite a data de nascimento do(a) aluno(a): ");
         scanf("%30[^\n]", alunos[qtdAlunos].dataNasc);

         printf("Digite o código do curso: ");
         scanf("%d", &alunos[qtdAlunos].codigoCurso);

         for(int i = 0; i < 4; i ++){
            printf("Digite a nota da disciplina %d: ", i+1);
            scanf("%f", &alunos[qtdAlunos].notas[i]);
            getchar();
         }

        printf("-------------------------------------------------\n");
    }

     menuAlunos();
}

void salvarAlunoArquivo(struct Aluno *lista) {
    FILE* fp;

    fp = fopen("sistemaAcademico.txt", "a");
    if(fp == NULL){
        fprintf(stderr, "Erro, não foi possível abrir o arquivo\n");
        return 1;
    }

    for(int i = 0; i < qtdAlunos; i++){
        fprintf(fp, "CPF: %s \n", alunos[i].cpf);
        fprintf(fp, "Nome: %s \n", alunos[i].nome);
        fprintf(fp, "Sexo: %c \n", alunos[i].sexo);
        fprintf(fp, "Data de nascimento: %s \n", alunos[i].dataNasc);
        fprintf(fp, "Código do curso atual: %d \n", alunos[i].codigoCurso);
        fprintf(fp, "Nota da disciplina 1: %.2f\n", alunos[i].notas[0]);
        fprintf(fp, "Nota da disciplina 2: %.2f\n", alunos[i].notas[1]);
        fprintf(fp, "Nota da disciplina 3: %.2f\n", alunos[i].notas[2]);
        fprintf(fp, "Nota da disciplina 4: %.2f\n", alunos[i].notas[3]);
    }

    fclose(fp);
}

int buscaPosicaoAluno(int cpf) {

    int posicaoAluno = 0;

    if(qtdAlunos > 0){
        for(int i = 0; i < qtdAlunos; i++){
			if(alunos[i].cpf == cpf){
				break;
			}
			posicaoAluno++;
		}
	}
}

void editaAluno() {

    int cpf;
    printf("Digite o CPF do aluno que deseja editar: ");
    scanf("%d", &cpf);
    getchar();

    int indiceAluno = buscaPosicaoAluno(cpf);

    printf("Digite o nome do aluno(a): ");
    scanf("%65[^\n]", alunos[qtdAlunos].nome);
    getchar();

    printf("Digite o sexo do(a) aluno(a), F  para feminino, M para masculino: ");
    scanf("%c", &alunos[qtdAlunos].sexo);

    while(alunos[qtdAlunos].sexo != 'M' && alunos[qtdAlunos].sexo != 'F'){
        printf("\tSexo inválido!\n");
        printf("Digite o sexo do(a) aluno(a), F  para feminino, M para masculino: ");
        scanf("%c", &alunos[qtdAlunos].sexo);
        getchar();
     }

     printf("Digite a data de nascimento do(a) aluno(a): ");
     scanf("%30[^\n]", alunos[qtdAlunos].dataNasc);

     printf("Digite o código do curso: ");
     scanf("%d", &alunos[qtdAlunos].codigoCurso);

     for(int i = 0; i < 4; i++){
        printf("Digite a nota da disciplina %d: ", i+1);
        scanf("%f", &alunos[qtdAlunos].notas);
        getchar();
     }

    menuAlunos();
}

void listarAlunos(){

    for(int i = 0; i < qtdAlunos; i++){
        printf("---------------------------------------------------\n");
        printf("CPF: %s \n", alunos[i].cpf);
        printf("Nome: %s \n", alunos[i].nome);
        printf("Sexo: %c \n", alunos[i].sexo);
        printf("Data de nascimento: %s \n", alunos[i].dataNasc);
        printf("Código do curso atual: %d \n", alunos[i].codigoCurso);
        printf("Nota da disciplina 1: %.2f\n", alunos[i].notas[0]);
        printf("Nota da disciplina 2: %.2f\n", alunos[i].notas[1]);
        printf("Nota da disciplina 3: %.2f\n", alunos[i].notas[2]);
        printf("Nota da disciplina 4: %.2f\n", alunos[i].notas[3]);
    }
    menuAlunos();
}

//****************CONSULTAS***************************8

void nomeAluno() {

    char nome[60];
    int op;

    do{
       printf("Digite o nome do aluno para busca: ");
       scanf("%60[^\n]", nome);
       for(int i = 0; i < qtdAlunos; i++){
            if(strstr(alunos[i].nome, nome) != NULL){
                printf("CPF: %s \n", alunos[i].cpf);
                printf("Nome: %s \n", alunos[i].nome);
                printf("Sexo: %c \n", alunos[i].sexo);
                printf("Data de nascimento: %s \n", alunos[i].dataNasc);
                printf("Código do curso atual: %d \n", alunos[i].codigoCurso);
                printf("Nota da disciplina 1: %.2f\n", alunos[i].notas[0]);
                printf("Nota da disciplina 2: %.2f\n", alunos[i].notas[1]);
                printf("Nota da disciplina 3: %.2f\n", alunos[i].notas[2]);
                printf("Nota da disciplina 4: %.2f\n", alunos[i].notas[3]);
            }
       }
       printf("Digite 0 para sair ou 1 para nova pesquisa: ");
       scanf("%d", &op);
       getchar();
    }while(op != 0);

    menuConsultas();
}

void cpfAluno() {

    char cpf[15];
    int op;

    do{
       printf("Digite o CPF do aluno para busca: ");
       scanf("%15[^\n]", cpf);
       for(int i = 0; i < qtdAlunos; i++){
            if(strstr(alunos[i].cpf, cpf) != NULL){
                printf("CPF: %s \n", alunos[i].cpf);
                printf("Nome: %s \n", alunos[i].nome);
                printf("Sexo: %c \n", alunos[i].sexo);
                printf("Data de nascimento: %s \n", alunos[i].dataNasc);
                printf("Código do curso atual: %d \n", alunos[i].codigoCurso);
                printf("Nota da disciplina 1: %.2f\n", alunos[i].notas[0]);
                printf("Nota da disciplina 2: %.2f\n", alunos[i].notas[1]);
                printf("Nota da disciplina 3: %.2f\n", alunos[i].notas[2]);
                printf("Nota da disciplina 4: %.2f\n", alunos[i].notas[3]);
            }
       }
       printf("Digite 0 para sair ou 1 para nova pesquisa: ");
       scanf("%d", &op);
       getchar();
    }while(op != 0);

    menuConsultas();
}

void disciplinaCurso() {

    char nomeCurso[30];
    int op;

    do{
       printf("Digite o nome do curso para visualização de disciplinas: ");
       scanf("%15[^\n]", nomeCurso);
       for(int i = 0; i < contadorCursos; i++){
            if(strstr(cursos[i].nome, nomeCurso) != NULL){
                for(int j = 0; j < MAX_DISCIPLINAS; j++){
                    printf("Disciplina %d: %s \n", j+1, disciplina[j].nome);
        }
            }
       }
       printf("Digite 0 para sair ou 1 para nova pesquisa: ");
       scanf("%d", &op);
       getchar();
    }while(op != 0);

    menuConsultas();
}

//**************RELATÓRIOS**********************

void listaDeAlunos() {
    for(int i = 0; i < qtdAlunos; i++){
        printf("---------------------------------------------------\n");
        printf("CPF: %s \n", alunos[i].cpf);
        printf("Nome: %s \n", alunos[i].nome);
        printf("Sexo: %c \n", alunos[i].sexo);
        printf("Data de nascimento: %s \n", alunos[i].dataNasc);
        printf("Código do curso atual: %d \n", alunos[i].codigoCurso);
        printf("Nota da disciplina 1: %.2f\n", alunos[i].notas[0]);
        printf("Nota da disciplina 2: %.2f\n", alunos[i].notas[1]);
        printf("Nota da disciplina 3: %.2f\n", alunos[i].notas[2]);
        printf("Nota da disciplina 4: %.2f\n", alunos[i].notas[3]);
    }
    menuRelatorios();
}

void alunosAprovados() {
    float media = 0;

    for(int i = 0; i < qtdAlunos; i++){
        media = alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2] + alunos[i].notas[3];
        media = media / 4;

        if(media >= 6){
            printf("---------------------------------------------------\n");
            printf("CPF: %s \n", alunos[i].cpf);
            printf("Nome: %s \n", alunos[i].nome);
            printf("Sexo: %c \n", alunos[i].sexo);
            printf("Data de nascimento: %s \n", alunos[i].dataNasc);
            printf("Código do curso atual: %d \n", alunos[i].codigoCurso);
            printf("Nota da disciplina 1: %.2f\n", alunos[i].notas[0]);
            printf("Nota da disciplina 2: %.2f\n", alunos[i].notas[1]);
            printf("Nota da disciplina 3: %.2f\n", alunos[i].notas[2]);
            printf("Nota da disciplina 4: %.2f\n", alunos[i].notas[3]);
            printf("Média: %.2f\n", media);
        }
    }
    menuRelatorios();
}

void alunosReprovados() {
    float media = 0;

    for(int i = 0; i < qtdAlunos; i++){
        media = alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2] + alunos[i].notas[3];
        media = media / 4;

        if(media <= 6){
            printf("---------------------------------------------------\n");
            printf("CPF: %s \n", alunos[i].cpf);
            printf("Nome: %s \n", alunos[i].nome);
            printf("Sexo: %c \n", alunos[i].sexo);
            printf("Data de nascimento: %s \n", alunos[i].dataNasc);
            printf("Código do curso atual: %d \n", alunos[i].codigoCurso);
            printf("Nota da disciplina 1: %.2f\n", alunos[i].notas[0]);
            printf("Nota da disciplina 2: %.2f\n", alunos[i].notas[1]);
            printf("Nota da disciplina 3: %.2f\n", alunos[i].notas[2]);
            printf("Nota da disciplina 4: %.2f\n", alunos[i].notas[3]);
            printf("Média: %.2f\n", media);
        }
    }
    menuRelatorios();
}
