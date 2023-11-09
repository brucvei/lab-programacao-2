// Bruna Caetano, Lucas Jost e Bruno Cantarelli - SI

#include "resources.h"

void createCourse(Node *tree) {
    Course *new = (Course *) malloc(sizeof(Course));

    printf("Digite o código do curso: ");
    scanf("%d", &new->code);
    fflush(stdin);
    printf("Digite o nome do curso: ");
    getchar();
    scanf("%[^\n]", new->name);
    fflush(stdin);
    printf("Digite o centro do curso: ");
    getchar();
    scanf("%[^\n]", new->center);
    fflush(stdin);

    new->students = createList();

    insert(tree, new);
    printf("Curso criado com sucesso!\n");
    free(new);
}

void removeCourse(Node *tree) {
    int code;
    printf("Digite o código do curso: ");
    scanf("%d", &code);
//    Node *course = search(tree, code);
//
//    if (course == NULL) {
//        printf("Curso não encontrado!\n");
//        return;
//    }
//
    delete(tree, code);
    printf("Curso removido com sucesso!\n");
}

void printCourses(Node *tree) {
    printTree2d(tree, 0);
    printf("-----------------------------------------------\n");
    print(tree);
}

void putStudentInCourse(Node *tree){
    int code;

    printf("Digite o código do curso: ");
    scanf("%d", &code);
    Node *root = search(tree, code);
    if (root == NULL) {
        printf("Curso não encontrado!\n");
        return;
    }

    insertStudent(root->course->students);
    free(root);
}

void removeStudentFromCourse(Node *tree){
    int code;

    printf("Digite o código do curso: ");
    scanf("%d", &code);
    Node *root = search(tree, code);
    if (root == NULL) {
        printf("Curso não encontrado!\n");
        return;
    }

    deleteStudent(root->course->students);
    free(root);
}

void printStudentOfCourse(Node *tree){
    int code;

    printf("Digite o código do curso: ");
    scanf("%d", &code);
    Node *root = search(tree, code);
    if (root == NULL) {
        printf("Curso não encontrado!\n");
        return;
    }

    printf("Curso: %d - %s\n", tree->course->code, tree->course->name);
    printf("Alunos:\n");
    printStudents(root->course->students);
    free(root);
}

void printStudentsOfAllCourses(Node *tree){

}