// Bruna Caetano, Lucas Jost e Bruno Cantarelli - SI

#include "tree.h"

Courses *createTree() {
    return NULL;
}

void freeTree(Courses *tree) {
    if (tree != NULL) {
        freeTree(tree->left);
        freeTree(tree->right);
        freeList(tree->students);
        free(tree);
    }
}

void createCourse(Courses *tree) {
    Courses *new = (Courses *) malloc(sizeof(Courses));

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

    insertCourse(tree, new);
    printf("Curso criado com sucesso!\n");
    free(new);
}

void insertCourse(Courses *tree, Courses *course) {
    if (tree == NULL) {
        puts("Árvore vazia!");
        Courses *aux = (Courses *) malloc(sizeof(Courses));
        aux->code = course->code;
        strcpy(aux->name, course->name);
        strcpy(aux->center, course->center);
        aux->left = NULL;
        aux->right = NULL;
        *tree = *aux;
        free(aux);
    } else {
        printf("Código: %d\n", course->code);
        printf("Código árvore: %d\n", tree->code);
        if (course->code < tree->code){
            printf("ESQUERDA");
            insertCourse(tree->left, course);
        }
        else if (course->code > tree->code) {
            printf("DIREITA");
            insertCourse(tree->right, course);
        } else
            printf("Curso já cadastrado!\n");
    }
}

void deleteCourse(Courses **tree) {
    puts("Removendo curso...");
    int code;

    printf("Digite o código do curso a ser deletado: ");
    scanf("%d", &code);

    if (*tree == NULL)
        printf("Curso não encontrado!\n");
    else {
        if (code < (*tree)->code)
            deleteCourse(&(*tree)->left);
        else if (code > (*tree)->code)
            deleteCourse(&(*tree)->right);
        else {
            freeList((*tree)->students);
            Courses *aux = *tree;
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

void printTree2d(Courses *tree, int space) {
    if (tree != NULL) {
        space += 7;
        printTree2d(tree->right, space);
        printf("\n");

        for (int i = 10; i < space; i++)
            printf(" ");

        printf("%d\n", tree->code);
        printTree2d(tree->left, space);
    }
}
// TODO: simplificar essas funções
void printTree(Courses *tree) {
    puts("Printando cursos em forma de árvore...");
    printTree2d(tree, 0);
    printf("-----------------------------------------------\n");
}

void printSequential(Courses *tree) {
    puts("Printando cursos em ordem de código...");
    if (tree != NULL) {
        printSequential(tree->left);
        printf("Código: %d\n", tree->code);
        printf("Nome: %s\n", tree->name);
        printf("Centro: %s\n\n", tree->center);
        printSequential(tree->right);
    }
}

void insertStudentCourse(Courses **tree) {
    puts("Inserindo aluno em curso...");
    int code;

    printf("Digite o código do curso: ");
    scanf("%d", &code);

    if (*tree == NULL)
        printf("Curso não encontrado!\n");
    else {
        if (code < (*tree)->code)
            insertStudentCourse(&(*tree)->left);
        else if (code > (*tree)->code)
            insertStudentCourse(&(*tree)->right);
        else {
            int qntd;

            printf("Digite a quantidade de alunos a serem inseridos: ");
            scanf("%d", &qntd);

            for (int i = 0; i < qntd; i++)
                insertStudent(&(*tree)->students);
        }
    }
}

void deleteStudentCourse(Courses **tree) {
    puts("Removendo aluno de curso...");
    int code;

    printf("Digite o código do curso: ");
    scanf("%d", &code);

    if (*tree == NULL)
        printf("Curso não encontrado!\n");
    else {
        if (code < (*tree)->code)
            deleteStudentCourse(&(*tree)->left);
        else if (code > (*tree)->code)
            deleteStudentCourse(&(*tree)->right);
        else {
            deleteStudent(&(*tree)->students);
            if (lengthStudents((*tree)->students) == 0) {
                freeList((*tree)->students);
            }
        }
    }
}

void printStudentCourse(Courses **tree) {
    puts("Listando todos aluno de um curso...");
    int code;

    printf("Digite o código do curso: ");
    scanf("%d", &code);

    if (*tree == NULL)
        printf("Curso não encontrado!\n");
    else {
        if (code < (*tree)->code)
            printStudentCourse(&(*tree)->left);
        else if (code > (*tree)->code)
            printStudentCourse(&(*tree)->right);
        else {
            printf("Curso: %d - %s\n", (*tree)->code, (*tree)->name);
            printf("Alunos:\n");
            printStudents((*tree)->students);
        }
    }
}

void printAllStudents(Courses **tree) {
    puts("Listando todos os alunos...");
    if (*tree == NULL)
        printf("Não há cursos cadastrados!\n");
    else {
        printStudentCourse(&(*tree)->left);

        List *aux = (*tree)->students;
        while (aux->student != NULL) {
            printOneStudent(*aux->student);
            aux = aux->next;
        }
        printf("Código: %d\n", (*tree)->code);
        printf("Nome: %s\n", (*tree)->name);
        printf("Centro: %s\n\n", (*tree)->center);

        printStudentCourse(&(*tree)->right);
    }
}