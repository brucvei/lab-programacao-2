// Bruna Caetano, Lucas Jost e Bruno Cantarelli - SI

#include "tree.h"

Tree *createTree() {
    return NULL;
}

void freeTree(Tree *tree) {
    if (tree != NULL) {
        freeTree(tree->left);
        freeTree(tree->right);
        freeList(tree->course.students);
        free(tree);
    }
}

void insertCourse(Tree **tree) {
    puts("Inserindo curso...");
    int code;
    char name[50], center[50];
    Tree *aux = NULL;

    printf("Digite o código do curso: ");
    scanf("%d", &code);
    printf("Digite o nome do curso: ");
    getchar();
    scanf("%[^\n]", name);
    printf("Digite o centro do curso: ");
    getchar();
    scanf("%[^\n]", center);


    if (*tree == NULL) {
        aux = (Tree *) malloc(sizeof(Tree));
        Course *new = (Course *) malloc(sizeof(Course));
        new->code = code;
        strcpy(new->name, name);
        strcpy(new->center, center);
        new->students = createList();
        aux->course = *new;
        aux->left = NULL;
        aux->right = NULL;
        *tree = aux;
    } else {
        if (code < (*tree)->course.code)
            insertCourse(&(*tree)->left);
        else if (code > (*tree)->course.code)
            insertCourse(&(*tree)->right);
        else
            printf("Curso já cadastrado!\n");
    }
}

void deleteCourse(Tree **tree) {
    puts("Removendo curso...");
    int code;

    printf("Digite o código do curso a ser deletado: ");
    scanf("%d", &code);

    if (*tree == NULL)
        printf("Curso não encontrado!\n");
    else {
        if (code < (*tree)->course.code)
            deleteCourse(&(*tree)->left);
        else if (code > (*tree)->course.code)
            deleteCourse(&(*tree)->right);
        else {
            freeList((*tree)->course.students);
            Tree *aux = *tree;
            // ajusta os ponteiros da árvore
            if ((*tree)->left == NULL && (*tree)->right == NULL) { // caso seja uma folha
                *tree = NULL;
            } else if ((*tree)->left == NULL) { // caso tenha apenas um filho direito
                *tree = (*tree)->right;
            } else if ((*tree)->right == NULL) { // caso tenha apenas um filho esquerdo
                *tree = (*tree)->left;
            } else { // caso tenha dois filhos ou mais
                aux = (*tree)->left;
                while (aux->right != NULL) {
                    aux = aux->right;
                }
                aux->right = (*tree)->right;
                aux = *tree;
                *tree = (*tree)->left;
            }
            free(aux);
            printf("Curso removido com sucesso!\n");
        }
    }
}

void printTree2d(Tree *tree, int space) {
    if (tree != NULL) {
        space += 7;
        printTree2d(tree->right, space);
        printf("\n");

        for (int i = 10; i < space; i++)
            printf(" ");

        printf("%d\n", tree->course.code);
        printTree2d(tree->left, space);
    }
}
// TODO: simplificar essas funções
void printTree(Tree *tree) {
    puts("Printando cursos em forma de árvore...");
    printTree2d(tree, 0);
    printf("-----------------------------------------------\n");
}

void printSequential(Tree *tree) {
    puts("Printando cursos em ordem de código...");
    if (tree != NULL) {
        printSequential(tree->left);
        printf("Código: %d\n", tree->course.code);
        printf("Nome: %s\n", tree->course.name);
        printf("Centro: %s\n\n", tree->course.center);
        printSequential(tree->right);
    }
}

void insertStudentCourse(Tree **tree) {
    puts("Inserindo aluno em curso...");
    int code;

    printf("Digite o código do curso: ");
    scanf("%d", &code);

    if (*tree == NULL)
        printf("Curso não encontrado!\n");
    else {
        if (code < (*tree)->course.code)
            insertStudentCourse(&(*tree)->left);
        else if (code > (*tree)->course.code)
            insertStudentCourse(&(*tree)->right);
        else {
            int qntd;

            printf("Digite a quantidade de alunos a serem inseridos: ");
            scanf("%d", &qntd);

            for (int i = 0; i < qntd; i++)
                insertStudent(&(*tree)->course.students);
        }
    }
}

void deleteStudentCourse(Tree **tree) {
    puts("Removendo aluno de curso...");
    int code;

    printf("Digite o código do curso: ");
    scanf("%d", &code);

    if (*tree == NULL)
        printf("Curso não encontrado!\n");
    else {
        if (code < (*tree)->course.code)
            deleteStudentCourse(&(*tree)->left);
        else if (code > (*tree)->course.code)
            deleteStudentCourse(&(*tree)->right);
        else {
            deleteStudent(&(*tree)->course.students);
            if (lengthStudents((*tree)->course.students) == 0) {
                freeList((*tree)->course.students);
            }
        }
    }
}

void printStudentCourse(Tree **tree) {
    puts("Listando todos aluno de um curso...");
    int code;

    printf("Digite o código do curso: ");
    scanf("%d", &code);

    if (*tree == NULL)
        printf("Curso não encontrado!\n");
    else {
        if (code < (*tree)->course.code)
            printStudentCourse(&(*tree)->left);
        else if (code > (*tree)->course.code)
            printStudentCourse(&(*tree)->right);
        else {
            printf("Curso: %d - %s\n", (*tree)->course.code, (*tree)->course.name);
            printf("Alunos:\n");
            printStudents((*tree)->course.students);
        }
    }
}

void printAllStudents(Tree **tree) {
    puts("Listando todos os alunos...");
    if (*tree == NULL)
        printf("Não há cursos cadastrados!\n");
    else {
        printStudentCourse(&(*tree)->left);

        List *aux = (*tree)->course.students;
        while (aux->student != NULL) {
            printOneStudent(*aux->student);
            aux = aux->next;
        }
        printf("Código: %d\n", (*tree)->course.code);
        printf("Nome: %s\n", (*tree)->course.name);
        printf("Centro: %s\n\n", (*tree)->course.center);

        printStudentCourse(&(*tree)->right);
    }
}