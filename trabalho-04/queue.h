// Bruna Caetano e Lucas Jost - SI
#ifndef TRABALHO_04_QUEUE_H
#define TRABALHO_04_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

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

/* Fila de espera
 * first -> primeiro da fila
 * last  -> último da fila
*/
typedef struct queue {
    Group *first;
    Group *last;
} Queue;

/* Cria a linha */
void createLine(Queue *line);

/* Insere um grupo na fila de espera pela quantidade de pessoas */
void insertGroup(Queue *line, int qntd);

/* Verifica se existe pessoas na fila */
bool lineIsEmpty(Queue *line);

/* Remove um grupo na fila de espera pela senha, ent pode ser de qualquer parte da fila */
void removeGroup(Queue *line, int id);

/* Printa toda a fila */
void showLine(Queue *line);

/* Libera memória */
void freeLine(Queue *line);

#endif //TRABALHO_04_QUEUE_H
