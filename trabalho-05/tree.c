// Bruna Caetano, Lucas Jost e Bruno Cantarelli - SI

#include "tree.h"

Node *newNode(int code) {
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

  Node *temp = (Node *)malloc(sizeof(Node));
  if (temp == NULL) {
    printf("Erro ao alocar memória!\n");
    exit(1);
  }

  temp->code = code;
  strcpy(temp->name, name);
  strcpy(temp->center, center);
  temp->left = NULL;
  temp->right = NULL;
  temp->students = createList();
  return temp;
}

Node *insert(Node *root, int code) {
  if (root == NULL)
    return newNode(code);
  else if (code > root->code)
    root->right = insert(root->right, code);
  else
    root->left = insert(root->left, code);
  return root;
}

Node *delete(Node *tree, int code) {
  if (tree == NULL)
    return NULL;
  if (code > tree->code)
    tree->right = delete (tree->right, code);
  else if (code < tree->code)
    tree->left = delete (tree->left, code);
  else {
    if (tree->left == NULL && tree->right == NULL) {
      free(tree);
      return NULL;
    } else if (tree->left == NULL || tree->right == NULL) {
      Node *temp;
      if (tree->left == NULL)
        temp = tree->right;
      else
        temp = tree->left;
      free(tree);
      return temp;
    } else {
      Node *temp = minimum(tree->right);
      tree->code = temp->code;
      strcpy(tree->name, temp->name);
      strcpy(tree->center, temp->center);
      tree->students = temp->students;
      tree->right = delete (tree->right, temp->code);
    }
  }
  return tree;
}

Node *search(Node *tree, int x) {
  if (tree == NULL || tree->code == x)
    return tree;
  else if (x > tree->code)
    return search(tree->right, x);
  else
    return search(tree->left, x);
}

Node *insertStudentInCourse(Node *root, int code) {
  if (code == root->code)
    root->students = insertStudent(root->students);
  else if (code > root->code)
    root->right = insertStudentInCourse(root->right, code);
  else
    root->left = insertStudentInCourse(root->left, code);
  return root;
}

Node *removeStudentInCourse(Node *root, int code) {
  if (code == root->code)
    root->students = deleteStudent(root->students);
  else if (code > root->code)
    root->right = removeStudentInCourse(root->right, code);
  else
    root->left = removeStudentInCourse(root->left, code);
  return root;
}

void print(Node *tree) {
  if (tree != NULL) {
    print(tree->left);
    printf("%s \n%s \t%d \n\n", tree->name, tree->center, tree->code);
    print(tree->right);
  }
}

Node *minimum(Node *root) {
  if (root == NULL)
    return NULL;
  else if (root->left != NULL)
    return minimum(root->left);
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
