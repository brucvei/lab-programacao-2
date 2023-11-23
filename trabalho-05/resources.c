// Bruna Caetano, Lucas Jost e Bruno Cantarelli - SI

#include "resources.h"

Node *createCourse(Node *tree) {
    int code;

    printf("Digite o código do curso: ");
    scanf("%d", &code);

    Node *course = search(tree, code);
    if (course != NULL) {
        printf("Curso já existe!\n");
        return tree;
    }

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

    tree = insertStudentInCourse(tree, code);
    return tree;
}

Node *deleteStudentFromCourse(Node *tree){
    int code;

    printf("Digite o código do curso: ");
    scanf("%d", &code);
    Node *root = search(tree, code);
    if (root == NULL) {
        printf("Curso não encontrado!\n");
        return tree;
    }

    tree = removeStudentInCourse(tree, code);
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

    printf("\n\n%s %d\n", root->name, root->code);
    printf("Alunos:\n");
    printStudents(root->students);
}

void printStudentsOfAllCourses(Node *tree){
    if (tree == NULL) return;
    printStudentsOfAllCourses(tree->left);
    printf("\n\n%s %d\n", tree->name, tree->code);
    printf("Alunos:");
    printStudents(tree->students);
    printStudentsOfAllCourses(tree->right);
}

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