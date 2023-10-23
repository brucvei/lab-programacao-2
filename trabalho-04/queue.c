// Bruna e Lucas - SI

#include "queue.h"

void createLine(Queue *line) {
    line->first = NULL;
    line->last = NULL;
}

void insertGroup(Queue *line) {
    Group *newRow = (Group *) malloc(sizeof(Group));

    int qntd;
    printf("Quantas pessoas tem no grupo? ");
    scanf("%d", &qntd);

    newRow->qntd = qntd;
    newRow->next = NULL;

    Queue *aux = line;
    if (lineIsEmpty(aux)) {
        newRow->id = 1;
        aux->first = newRow;
    } else if (aux->last == NULL) {
        newRow->id = aux->last->id + 1;
        aux->last->next = newRow;
    }
    aux->last = newRow;
    puts("Grupo adicionado a fila de espera!");
}

bool lineIsEmpty(Queue *line) {
    return line->first == NULL;
}

void removeGroup(Queue *line) {
    if (lineIsEmpty(line)) {
        puts("A fila está vazia!");
    } else {
        Group *aux = line->first;
        line->first = aux->next;
        if (lineIsEmpty(line)) {
            line->last = NULL;
        }

        free(aux);
        puts("Grupo removido com sucesso!");
    }
}

void showLine(Queue *line) {
    if (lineIsEmpty(line)) {
        puts("A lista está vazia!");
    } else {
        Group *aux = line->first;
        while (aux != NULL) {
            printf("\nSenha %d: %d pessoas", aux->id, aux->qntd);
            aux = aux->next;
        }
    }
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