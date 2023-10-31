// Bruna Caetano e Lucas Jost - SI

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
    puts("Grupo adicionado a fila de espera!");
}

bool lineIsEmpty(Queue *line) {
    return line->first == NULL;
}

void removeGroup(Queue *line, int id) {
    if (lineIsEmpty(line)) {
        puts("A fila está vazia!\n");
    } else {
        int cod = id;
        if (id == -1) {
            printf("Qual a senha do grupo? \n-> ");
            scanf("%d", &cod);
        }

        Group *aux = line->first;
        Group *prev = NULL;
        while (aux != NULL) {
            if (aux->id == cod) {
                if (aux == line->first) {
                    line->first = aux->next;
                } else if (aux == line->last) {
                    line->last = prev;
                    prev->next = NULL;
                } else {
                    prev->next = aux->next;
                }
                puts("Grupo removido com sucesso!\n");
                break;
            }
            prev = aux;
            aux = aux->next;
        }

        if (aux == NULL)
            puts("Senha não encontrada!\n");

        free(aux);
    }
}

void showLine(Queue *line) {
    int qntd = 0;
    Group *aux = line->first;
    while (aux != NULL) {
        qntd += aux->qntd;
        printf("\nSenha %d: %d pessoas", aux->id, aux->qntd);
        aux = aux->next;
    }
    printf("\n%d pessoas na fila de espera!\n\n", qntd);
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