// Bruna Caetano, Lucas Jost e Bruno Cantarelli - SI

#ifndef TRABALHO_05_RESOURCES_H
#define TRABALHO_05_RESOURCES_H

#include "tree.h"

// Cria um curso e insere na arvore
Node *createCourse(Node *tree);

// Remove um curso da arvore
Node *removeCourse(Node *tree);

// Insere um aluno em um curso
Node *putStudentInCourse(Node *tree);

// Remove um aluno de um curso
Node *deleteStudentFromCourse(Node *tree);

// Printa todos os cursos
void printCourses(Node *tree);

// Printa todos os alunos de um curso
void printStudentOfCourse(Node *tree);

// Printa todos os alunos de todos os cursos
void printStudentsOfAllCourses(Node *tree);

void printMenu();
#endif //TRABALHO_05_RESOURCES_H
