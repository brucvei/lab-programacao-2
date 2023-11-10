// Bruna Caetano, Lucas Jost e Bruno Cantarelli - SI

#include "tree.h"

Node *newNode(int code) {
    puts("newNode");
    char name[50], center[50];

    fflush(stdin);
    printf("Digite o nome do curso: ");
    getchar();
    scanf("%[^\n]", name);

    fflush(stdin);

    printf("Digite o centro do curso: ");
    getchar();
    scanf("%[^\n]", center);
    fflush(stdin);

    puts("Criando curso...");
    Node *temp = (Node *) malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    temp->code = code;
    strcpy(temp->name, name);
    strcpy(temp->center, center);
    temp->left = NULL;
    temp->right = NULL;
    temp->students = NULL;
//    printf("%d\n%s\n%s\n", temp->code, temp->name, temp->center);
    return temp;
}

Node *insert(Node *root, int code) {
    puts("insert");
    if (root == NULL) return newNode(code);
    else if (code > root->code) root->right = insert(root->right, code);
    else root->left = insert(root->left, code);
    return root;
}

Node *delete(Node *root, int x) {
    puts("delete");
    if (root == NULL) return NULL;
    if (x > root->code) root->right = delete(root->right, x);
    else if (x < root->code) root->left = delete(root->left, x);
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
//            root->course = temp->course;
            root->right = delete(root->right, temp->code);
        }
    }
    return root;
}

Node *search(Node *root, int x) {
    puts("search");
    if (root == NULL || root->code == x) return root;
    else if (x > root->code) return search(root->right, x);
    else return search(root ->left, x);
}

void print(Node *root) {
    if (root != NULL) {
        print(root->left);
        printf("%s \n%s \t%d \n\n", root->name, root->center, root->code);
        print(root->right);
    }
}

Node *minimum(Node *root) {
    puts("minimum");
    if (root == NULL) return NULL;
    else if (root->left != NULL) return minimum(root->left);
    return root;
}

void printTree2d(Node *tree, int space) {
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

void freeTree(Node *tree) {
    if (tree != NULL) {
        freeList(tree->students);
        freeTree(tree->left);
        freeTree(tree->right);
        free(tree);
    }
}
