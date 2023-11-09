// Bruna Caetano, Lucas Jost e Bruno Cantarelli - SI

#include "tree.h"

//Node *createTree() {
//    return NULL;
//}

void freeTree(Node *tree) {
    puts("freeTree");
    if (tree != NULL) {
        freeList(tree->course->students);
        freeTree(tree->left);
        freeTree(tree->right);
        free(tree);
    }
}

Node *newNode(int code, char* name, char* center) {
    puts("newNode");
    Node *temp;
    temp = malloc(sizeof(Node));
    temp->course->code = code;
    strcpy(temp->course->name, name);
    strcpy(temp->course->center, center);
    temp->left = NULL;
    temp->right = NULL;
    temp->course->students = createList();
    printf("%d\n%s\n%s\n", temp->course->code, temp->course->name, temp->course->center);
    return temp;
}

Node *search(Node *root, int x) {
    puts("search");
    if (root == NULL || root->course->code == x) return root;
    else if (x > root->course->code) return search(root->right, x);
    else return search(root ->left, x);
}

Node *insert(Node *root, int code, char* name, char* center) {
    puts("insert");
    printf("%d\t%s\t%s\t", code, name, center);
    if (root == NULL) return newNode(code, name, center);
    else if (code > root->course->code) root->right = insert(root->right, code, name, center);
    else root->left = insert(root->left, code, name, center);
    return root;
}

Node *minimum(Node *root) {
    puts("minimum");
    if (root == NULL) return NULL;
    else if (root->left != NULL) return minimum(root->left);
    return root;
}

Node *delete(Node *root, int x) {
    puts("delete");
    if (root == NULL) return NULL;
    if (x > root->course->code) root->right = delete(root->right, x);
    else if (x < root->course->code) root->left = delete(root->left, x);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL || root->right == NULL) {
            Node *temp;
            if (root->left == NULL) temp = root->right;
            else temp = root->left;
            free(root);
            return temp;
        } else {
            Node *temp = minimum(root->right);
            root->course = temp->course;
            root->right = delete(root->right, temp->course->code);
        }
    }
    return root;
}

void print(Node *root) {
    puts("print");
    if (root != NULL) {
        print(root->left);
        printf("-%d ", root->course->code);
        print(root->right);
    }
}

//
//void createCourse(Node *tree) {
//    Node *new = (Node *) malloc(sizeof(Node));
//
//    printf("Digite o código do curso: ");
//    scanf("%d", &new->code);
//    fflush(stdin);
//    printf("Digite o nome do curso: ");
//    getchar();
//    scanf("%[^\n]", new->name);
//    fflush(stdin);
//    printf("Digite o centro do curso: ");
//    getchar();
//    scanf("%[^\n]", new->center);
//    fflush(stdin);
//
//    new->students = createList();
//
//    insertCourse(tree, new);
//    printf("Curso criado com sucesso!\n");
//    free(new);
//}
//
//void insertCourse(Node *tree, Node *course) {
//    if (tree == NULL) {
//        puts("Árvore vazia!");
//        Node *aux = (Node *) malloc(sizeof(Node));
//        aux->code = course->code;
//        strcpy(aux->name, course->name);
//        strcpy(aux->center, course->center);
//        aux->left = NULL;
//        aux->right = NULL;
//        *tree = *aux;
//        free(aux);
//    } else {
//        printf("Código: %d\n", course->code);
//        printf("Código árvore: %d\n", tree->code);
//        if (course->code < tree->code){
//            printf("ESQUERDA");
//            insertCourse(tree->left, course);
//        }
//        else if (course->code > tree->code) {
//            printf("DIREITA");
//            insertCourse(tree->right, course);
//        } else
//            printf("Curso já cadastrado!\n");
//    }
//}
//
//void deleteCourse(Node **tree) {
//    puts("Removendo curso...");
//    int code;
//
//    printf("Digite o código do curso a ser deletado: ");
//    scanf("%d", &code);
//
//    if (*tree == NULL)
//        printf("Curso não encontrado!\n");
//    else {
//        if (code < (*tree)->code)
//            deleteCourse(&(*tree)->left);
//        else if (code > (*tree)->code)
//            deleteCourse(&(*tree)->right);
//        else {
//            freeList((*tree)->students);
//            Node *aux = *tree;
//            // ajusta os ponteiros da árvore
//            if ((*tree)->left == NULL && (*tree)->right == NULL) { // caso seja uma folha
//                *tree = NULL;
//            } else if ((*tree)->left == NULL) { // caso tenha apenas um filho direito
//                *tree = (*tree)->right;
//            } else if ((*tree)->right == NULL) { // caso tenha apenas um filho esquerdo
//                *tree = (*tree)->left;
//            } else { // caso tenha dois filhos ou mais
//                aux = (*tree)->left;
//                while (aux->right != NULL) {
//                    aux = aux->right;
//                }
//                aux->right = (*tree)->right;
//                aux = *tree;
//                *tree = (*tree)->left;
//            }
//            free(aux);
//            printf("Curso removido com sucesso!\n");
//        }
//    }
//}
//
void printTree2d(Node *tree, int space) {
    puts("printTree2d");
    if (tree != NULL) {
        space += 7;
        printTree2d(tree->right, space);
        printf("\n");

        for (int i = 10; i < space; i++)
            printf(" ");

        printf("%d\n", tree->course->code);
        printTree2d(tree->left, space);
    }
}
//// TODO: simplificar essas funções
//void printTree(Node *tree) {
//    puts("Printando cursos em forma de árvore...");
//    printTree2d(tree, 0);
//    printf("-----------------------------------------------\n");
//}
//
//void printSequential(Node *tree) {
//    puts("Printando cursos em ordem de código...");
//    if (tree != NULL) {
//        printSequential(tree->left);
//        printf("Código: %d\n", tree->code);
//        printf("Nome: %s\n", tree->name);
//        printf("Centro: %s\n\n", tree->center);
//        printSequential(tree->right);
//    }
//}
//
//void insertStudentCourse(Node **tree) {
//    puts("Inserindo aluno em curso...");
//    int code;
//
//    printf("Digite o código do curso: ");
//    scanf("%d", &code);
//
//    if (*tree == NULL)
//        printf("Curso não encontrado!\n");
//    else {
//        if (code < (*tree)->code)
//            insertStudentCourse(&(*tree)->left);
//        else if (code > (*tree)->code)
//            insertStudentCourse(&(*tree)->right);
//        else {
//            int qntd;
//
//            printf("Digite a quantidade de alunos a serem inseridos: ");
//            scanf("%d", &qntd);
//
//            for (int i = 0; i < qntd; i++)
//                insertStudent(&(*tree)->students);
//        }
//    }
//}
//
//void deleteStudentCourse(Node **tree) {
//    puts("Removendo aluno de curso...");
//    int code;
//
//    printf("Digite o código do curso: ");
//    scanf("%d", &code);
//
//    if (*tree == NULL)
//        printf("Curso não encontrado!\n");
//    else {
//        if (code < (*tree)->code)
//            deleteStudentCourse(&(*tree)->left);
//        else if (code > (*tree)->code)
//            deleteStudentCourse(&(*tree)->right);
//        else {
//            deleteStudent(&(*tree)->students);
//            if (lengthStudents((*tree)->students) == 0) {
//                freeList((*tree)->students);
//            }
//        }
//    }
//}
//
//void printStudentCourse(Node **tree) {
//    puts("Listando todos aluno de um curso...");
//    int code;
//
//    printf("Digite o código do curso: ");
//    scanf("%d", &code);
//
//    if (*tree == NULL)
//        printf("Curso não encontrado!\n");
//    else {
//        if (code < (*tree)->code)
//            printStudentCourse(&(*tree)->left);
//        else if (code > (*tree)->code)
//            printStudentCourse(&(*tree)->right);
//        else {
//            printf("Curso: %d - %s\n", (*tree)->code, (*tree)->name);
//            printf("Alunos:\n");
//            printStudents((*tree)->students);
//        }
//    }
//}
//
//void printAllStudents(Node **tree) {
//    puts("Listando todos os alunos...");
//    if (*tree == NULL)
//        printf("Não há cursos cadastrados!\n");
//    else {
//        printStudentCourse(&(*tree)->left);
//
//        List *aux = (*tree)->students;
//        while (aux->student != NULL) {
//            printOneStudent(*aux->student);
//            aux = aux->next;
//        }
//        printf("Código: %d\n", (*tree)->code);
//        printf("Nome: %s\n", (*tree)->name);
//        printf("Centro: %s\n\n", (*tree)->center);
//
//        printStudentCourse(&(*tree)->right);
//    }
//}