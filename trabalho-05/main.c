// Bruna Caetano, Lucas Jost e Bruno Cantarelli - SI

#include "resources.h"

int main(){
    Node *tree = NULL;
    int opcao;

    do {
        printMenu();
        scanf("%d", &opcao);

        switch (opcao) {
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

    return 0;
}