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
    char name[50];
    char center[50];
    List *students;
} Course;

typedef struct node {
    Course course;
    struct node *left;
    struct node *right;
} Tree;

// Cria uma árvore vazia
Tree *createTree();

// Libera o espaço alocado para a árvore
void freeTree(Tree *tree);

// Insere um curso na árvore
void insertCourse(Tree **tree);

// Deleta um curso da árvore
void deleteCourse(Tree **tree);

// Printa apenas os códigos em forma de árvore
void printTree2d(Tree *tree, int space);

// Printa a árvore em ordem de inserção
void printTree(Tree *tree);

// Printa em forma sequencial por código
void printSequential(Tree *tree);

// Insere um aluno em um curso
void insertStudentCourse(Tree **tree);

// Deleta um aluno de um curso
void deleteStudentCourse(Tree **tree);

// Printa os alunos de um curso
void printStudentCourse(Tree **tree);

// Printa todos os alunos matriculados e seus cursos
void printAllStudents(Tree **tree);

#endif //TRABALHO_05_TREE_H
