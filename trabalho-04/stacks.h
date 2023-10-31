// Bruna Caetano e Lucas Jost - SI
#ifndef TRABALHO_04_STACKS_H
#define TRABALHO_04_STACKS_H

#include "queue.h"

typedef struct plates {
    int qnt;
    struct plates *next;
} Plates;

typedef struct stack {
    Plates *top;
} Stack;

/* Cria pilha */
void createStack(Stack *stack);

/* Adiciona 4 pratos a pilha */
void push(Stack *stack);

/* Remove 4 pratos da pilha */
void pop(Stack *stack);

/* Printa a pilha */
void showStack(Stack *stack);

/* Libera a memória */
void freeStack(Stack *stack);

#endif //TRABALHO_04_STACKS_H
