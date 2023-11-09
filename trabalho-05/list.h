// Bruna Caetano, Lucas Jost e Bruno Cantarelli - SI

#ifndef TRABALHO_05_LIST_H
#define TRABALHO_05_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Lista de alunos:
 * id   -> matricula
 * name -> nome
 * year -> ano de ingresso
 * next -> ponteiro para o proximo aluno
*/

typedef struct student {
    int id;
    char name[50];
    int year;
} Student;

typedef struct list {
    Student *student;
    struct list *next;
} List;


// Cria uma lista vazia
List *createList();

// Retorna o tamanho da lista
int lengthStudents(List *list);

// Ordena a lista por id (matrícula) do aluno
void shellSort(List *list, int n);

// Verifica se um aluno existe na lista
bool existsStudent(List *list, int id);

// Printa um aluno
void printOneStudent(Student student);

// Printa toda a lista de alunos
void printStudents(List *list);

// Inserer um aluno na lista
void insertStudent(List *list);

// Deleta um aluno da lista
void deleteStudent(List *list);

// Libera o espaço alocado para a lista
void freeList(List *list);

#endif //TRABALHO_05_LIST_H
