#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
// Bruna Caetano, Lucas Jost e Bruno Cantarelli - SI

#include "resources.h"

Node *createCourse(Node *tree) {
    int code;

    printf("Digite o código do curso: ");
    scanf("%d", &code);

    tree = insert(tree, code);
    printf("Curso criado com sucesso!\n");
    return tree;
}

Node *removeCourse(Node *tree) {
    int code;
    printf("Digite o código do curso: ");
    scanf("%d", &code);
    Node *course = search(tree, code);

    if (course == NULL) {
        printf("Curso não encontrado!\n");
        return tree;
    }

    tree = delete(tree, code);
    printf("Curso removido com sucesso!\n");
    free(course);
    return tree;
}

// TODO: ajustar aqui
Node *putStudentInCourse(Node *tree){
    int code;

    printf("Digite o código do curso: ");
    scanf("%d", &code);
    Node *root = search(tree, code);
    if (root == NULL) {
        printf("Curso não encontrado!\n");
        return tree;
    }

//    root->students =
            insertStudent(root->students);
    free(root);
    return tree;
}

// TODO: ajustar aqui
Node *removeStudentFromCourse(Node *tree){
    int code;

    printf("Digite o código do curso: ");
    scanf("%d", &code);
    Node *root = search(tree, code);
    if (root == NULL) {
        printf("Curso não encontrado!\n");
        return tree;
    }

    deleteStudent(root->students);
    free(root);
    return tree;
}

void printCourses(Node *tree) {
    printTree2d(tree, 0);
    printf("-----------------------------------------------\n");
    print(tree);
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

    printf("Curso: %d - %s\n", tree->code, tree->name);
    printf("Alunos:\n");
    printStudents(root->students);
    free(root);
}

void printStudentsOfAllCourses(Node *tree){
    if (tree == NULL) return;
    printStudentsOfAllCourses(tree->left);
    printf("%s\n%d - %s\n", tree->name, tree->code, tree->center);
    printStudents(tree->students);
    printStudentsOfAllCourses(tree->right);
}
#pragma clang diagnostic pop