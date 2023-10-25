// Bruna e Lucas - SI

#include "queue.h"

void createLine(Queue *line) {
    line->first = NULL;
    line->last = NULL;
}

void insertGroup(Queue *line, int qntd) {
    Group *newRow = (Group *) malloc(sizeof(Group));
    newRow->qntd = qntd;
    newRow->next = NULL;

    if (lineIsEmpty(line)) {
        newRow->id = 1;
        line->first = newRow;
    } else {
        newRow->id = line->last->id + 1;
        line->last->next = newRow;
    }
    line->last = newRow;
    puts("Grupo adicionado a fila de espera!\n");
}

bool lineIsEmpty(Queue *line) {
    return line->first == NULL;
}

void removeGroup(Queue *line) {
    if (lineIsEmpty(line)) {
        puts("A fila está vazia!\n");
    } else {
        Group *aux = line->first;
        line->first = aux->next;
        if (lineIsEmpty(line)) {
            line->last = NULL;
        }

        free(aux);
        puts("Grupo removido com sucesso!\n");
    }
}

void showLine(Queue *line) {
    int qntd = 0;
    Group *aux = line->first;
    while (aux != NULL) {
        qntd += aux->qntd;
        printf("Senha %d: %d pessoas\n", aux->id, aux->qntd);
        aux = aux->next;
    }
    printf("\n%d pessoas na fila de espera!\n", qntd);
}

void freeLine(Queue *line) {
    if (!lineIsEmpty(line)) {
        Group *aux = line->first;
        while (aux != NULL) {
            Group *next = aux->next;
            free(aux);
            aux = next;
        }
        free(line);
    }
}