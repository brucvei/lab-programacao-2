// Bruna Caetano, Lucas Jost e Bruno Cantarelli - SI

#include "resources.h"
//
//#pragma clang diagnostic push
//#pragma clang diagnostic ignored "-Wreturn-type"
//int menu(Node *tree){
//    int opcao;
//    puts("\nEscolha uma opção:");
//    puts("1 - Inserir um curso.");
//    puts("2 - Remover um curso.");
//    puts("3 - Listar cursos.");
//    puts("4 - Inserir alunos em um curso.");
//    puts("5 - Remover um aluno de um curso.");
//    puts("6 - Listar alunos de um curso.");
//    puts("7 - Listar todos os alunos e seus cursos.");
//    printf("0 - Terminar programa.\n -> ");
//    scanf("%d", &opcao);
//    switch (opcao) { // NOLINT(*-multiway-paths-covered)
//        case 1:
//            tree = createCourse(tree);
//            break;
////            return 1;
//        case 2:
//            removeCourse(tree);
//            return 1;
//        case 3:
//            printCourses(tree);
//            return 1;
//        case 4:
//            putStudentInCourse(tree);
//            return 1;
//        case 5:
//            deleteStudentFromCourse(tree);
//            return 1;
//        case 6:
//            printStudentOfCourse(tree);
//            return 1;
//        case 7:
//            printStudentsOfAllCourses(tree);
//            return 1;
//        case 0:
//            return 0;
//    }
//};
//#pragma clang diagnostic pop

void printMenu(){
    puts("\nEscolha uma opção:");
    puts("1 - Inserir um curso.");
    puts("2 - Remover um curso.");
    puts("3 - Listar cursos.");
    puts("4 - Inserir alunos em um curso.");
    puts("5 - Remover um aluno de um curso.");
    puts("6 - Listar alunos de um curso.");
    puts("7 - Listar todos os alunos e seus cursos.");
    printf("0 - Terminar programa.\n -> ");
}

int main(){
    Node *tree = NULL;
    int opcao;

    do {
        printMenu();
        scanf("%d", &opcao);

        switch (opcao) { // NOLINT(*-multiway-paths-covered)
            case 1:
                tree = createCourse(tree);
                break;
            case 2:
                tree = removeCourse(tree);
                break;
            case 3:
                printCourses(tree);
                break;
            case 4:
                tree = putStudentInCourse(tree);
                break;
            case 5:
                tree = deleteStudentFromCourse(tree);
                break;
            case 6:
                printStudentOfCourse(tree);
                break;
            case 7:
                printStudentsOfAllCourses(tree);
                break;
            case 0:
                puts("Terminando programa...");
                break;
        }
    } while (opcao != 0);

//    freeTree(tree);

    return 0;
}
// https://www.scaler.com/topics/binary-search-tree-program-in-c/