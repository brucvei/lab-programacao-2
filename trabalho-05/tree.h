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
} Courses;

// Cria uma árvore vazia
Courses *createTree();

// Libera o espaço alocado para a árvore
void freeTree(Courses *tree);

void createCourse(Courses *tree);
// Insere um curso na árvore
void insertCourse(Courses *tree, Courses *course);

// Deleta um curso da árvore
void deleteCourse(Courses **tree);

// Printa apenas os códigos em forma de árvore
void printTree2d(Courses *tree, int space);

// Printa a árvore em ordem de inserção
void printTree(Courses *tree);

// Printa em forma sequencial por código
void printSequential(Courses *tree);

// Insere um aluno em um curso
void insertStudentCourse(Courses **tree);

// Deleta um aluno de um curso
void deleteStudentCourse(Courses **tree);

// Printa os alunos de um curso
void printStudentCourse(Courses **tree);

// Printa todos os alunos matriculados e seus cursos
void printAllStudents(Courses **tree);

#endif //TRABALHO_05_TREE_H
