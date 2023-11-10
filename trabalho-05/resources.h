// Bruna Caetano, Lucas Jost e Bruno Cantarelli - SI

#ifndef TRABALHO_05_RESOURCES_H
#define TRABALHO_05_RESOURCES_H

#include "tree.h"

// Cria um curso e insere na arvore
Node *createCourse(Node *tree);

// Remove um curso da arvore
Node *removeCourse(Node *tree);

Node *putStudentInCourse(Node *tree);

Node *deleteStudentFromCourse(Node *tree);

void printCourses(Node *tree);

void printStudentOfCourse(Node *tree);

void printStudentsOfAllCourses(Node *tree);

void printMenu();
#endif //TRABALHO_05_RESOURCES_H
