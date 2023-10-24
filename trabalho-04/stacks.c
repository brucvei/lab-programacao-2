// Bruna e Lucas - SI

#include "stacks.h"

void createStack(Stack *stack) {
    stack->top = NULL;
}

void push(Stack *stack) {
    Plates *newPlate = (Plates *) malloc(sizeof(Plates));
    newPlate->n = 4;
    newPlate->next = stack->top;
    stack->top = newPlate;
    puts("Pratos adicionados a pilha!\n");
}

void pop(Stack *stack) {
    if (stack->top == NULL) {
        puts("A pilha está vazia!\n");
    } else {
        Plates *aux = stack->top;
        stack->top = aux->next;
        free(aux);
        puts("Pratos removidos da pilha!\n");
    }
}

void showStack(Stack *stack) {
    int qntd = 0;
    if (stack->top != NULL) {
        Plates *aux = stack->top;
        while (aux != NULL) {
            qntd += aux->n;
            aux = aux->next;
        }
    }
    printf("\n%d pratos no total!\n", qntd);
}

void freeStack(Stack *stack) {
    Plates *aux = stack->top;
    while (aux != NULL) {
        Plates *aux2 = aux->next;
        free(aux);
        aux = aux2;
    }
    free(stack);
}