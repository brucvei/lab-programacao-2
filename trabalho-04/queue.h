// Bruna e Lucas - SI
#ifndef TRABALHO_04_QUEUE_H
#define TRABALHO_04_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Fila de espera
 * id   -> senha
 * qntd -> quantidade de pessoas no grupo
 * next -> próximo da fila
*/
typedef struct group {
    int id;
    int qntd;
    struct group *next;
} Group;

typedef struct queue {
    Group *first;
    Group *last;
} Queue;

void createLine(Queue *line);

/* Insere um grupo na fila de espera pela quantidade de pessoas */
void insertGroup(Queue *line);

bool lineIsEmpty(Queue *line);

/* Remove um grupo na fila de espera pele senha, ent pode ser de qualquer parte da fila */
void removeGroup(Queue *line);

/* Printa toda a fila */
void showLine(Queue *line);

/*  */
void freeLine(Queue *line);

#endif //TRABALHO_04_QUEUE_H
