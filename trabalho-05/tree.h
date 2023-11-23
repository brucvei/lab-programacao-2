// Bruna Caetano, Lucas Jost e Bruno Cantarelli - SI

#ifndef TRABALHO_05_TREE_H
#define TRABALHO_05_TREE_H

#include "list.h"

/* Arvore de cursos:
 * code     -> código do curso
 * name     -> nome do curso
 * center   -> centro da universidade
 * students -> lista de alunos
 * left     -> ponteiro para o filho esquerdo
 * right    -> ponteiro para o filho direito
*/

typedef struct node {
    int code;
    char name[50];
    char center[50];
    List *students;
    struct node *left;
    struct node *right;
} Node;

// Encontra o menor valor da arvore
Node *minimum(Node *root);

// Libera o espaço alocado para a arvore
void freeTree(Node *tree);

// Cria um novo nó
Node *newNode(int code);

// Insere um nó na arvore
Node *insert(Node *root, int code);

// Procura um nó na arvore pelo seu código
Node *search(Node *tree, int x);

// Deleta um nó da arvore:
/* caso o nó não tenha filhos ele só remove o nó;
 * caso o nó possua só um filho, ele remove e ajusta os ponteiros;
 * caso o nó possui dois filhos, ele vai substituindo o valor com o filho da direita até a folha.*/
Node *delete(Node *tree, int code);

// Insere um aluno na lista de alunos de um curso
Node *insertStudentInCourse(Node *root, int code);

// Remove um aluno da lista de alunos de um curso
Node *removeStudentInCourse(Node *root, int code);

// Printa a arvore em formato de arvore
void printTree2d(Node *tree, int space);

// Printa a arvore em formato de lista
void print(Node *tree);

#endif //TRABALHO_05_TREE_H