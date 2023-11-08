// Bruna Caetano, Lucas Jost e Bruno Cantarelli - SI

#include "tree.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"
int menu(Courses **tree){
    int opcao;
    puts("\nEscolha uma opção:");
    puts("1 - Inserir um curso.");
    puts("2 - Remover um curso.");
    puts("3 - Listar cursos.");
    puts("4 - Inserir alunos em um curso.");
    puts("5 - Remover um aluno de um curso.");
    puts("6 - Listar alunos de um curso.");
    puts("7 - Listar todos os alunos e seus cursos.");
    printf("0 - Terminar programa.\n -> ");
    scanf("%d", &opcao);
    switch (opcao) { // NOLINT(*-multiway-paths-covered)
        case 1:
            createCourse(*tree);
            return 1;
        case 2:
            deleteCourse(tree);
            return 1;
        case 3:
//            printTree(*tree);
            printSequential(*tree);
            return 1;
        case 4:
            insertStudentCourse(tree);
            return 1;
        case 5:
            deleteStudentCourse(tree);
            return 1;
        case 6:
            printStudentCourse(tree);
            return 1;
        case 7:
            printAllStudents(tree);
            return 1;
        case 0:
            return 0;
    }
};
#pragma clang diagnostic pop

int main(){
    Courses *tree = createTree();

    while (menu(&tree) != 0);

    freeTree(tree);

    return 0;
}