// Bruna e Lucas - SI

#ifndef TRABALHO_04_STACKS_H
#define TRABALHO_04_STACKS_H

#define SEATS 4

typedef struct plates {
    int n;
    struct plates *next;
} Plates;

typedef struct stack {
    Plates *top;
} Stack;

void createStack(Stack *stack);
void push(Stack *stack);
void pop(Stack *stack);
void showStack(Stack *stack);
void freeStack(Stack *stack);

#endif //TRABALHO_04_STACKS_H
