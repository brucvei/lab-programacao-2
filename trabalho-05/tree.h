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

typedef struct course {
    int code;
    char *name;
    char *center;
    List *students;
} Course;

typedef struct node {
    Course *course;
    struct node *left;
    struct node *right;
} Node;

Node *newNode(Course *x);

Node *search(Node *root, int x);

Node *insert(Node *root, Course *x);

Node *minimum(Node *root);

Node *delete(Node *root, int x);

void print(Node *root);
// Cria uma árvore vazia
//Node *createTree();

// Libera o espaço alocado para a árvore
void freeTree(Node *tree);
//
//

//// Insere um curso na árvore
//void insertCourse(Node *tree, Node *course);
//
//// Deleta um curso da árvore
//void deleteCourse(Node **tree);
//
//// Printa apenas os códigos em forma de árvore
void printTree2d(Node *tree, int space);
//
//// Printa a árvore em ordem de inserção
//void printTree(Node *tree);
//
//// Printa em forma sequencial por código
//void printSequential(Node *tree);
//
//// Insere um aluno em um curso
//void insertStudentCourse(Node **tree);
//
//// Deleta um aluno de um curso
//void deleteStudentCourse(Node **tree);
//
//// Printa os alunos de um curso
//void printStudentCourse(Node **tree);
//
//// Printa todos os alunos matriculados e seus cursos
//void printAllStudents(Node **tree);

#endif //TRABALHO_05_TREE_H
