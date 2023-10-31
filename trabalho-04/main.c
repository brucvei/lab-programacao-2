// Bruna Caetano e Lucas Jost - SI

#include "tables.h"

// negócio p ignorar warnings de qnt return type
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type"

int menu(Queue *line, Table **tables, Stack *stack, int l, int c) {
    int opcao;
    puts("\nEscolha uma opção:");
    puts("1 - Chegada de clientes ao restaurante.");
    puts("2 - Finalizar refeição/liberar mesa.");
    puts("3 - Desistir de esperar.");
    puts("4 - Arrumar mesa.");
    puts("5 - Repor pratos.");
    puts("6 - Imprimir pilha de pratos, fila de espera e ocupação das mesas.");
    printf("0 - Fechar restaurante. \n-> ");
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            fillTable(line, tables, l, c, 0);
            return 1;
        case 2:
            releaseTable(tables, stack, l, c);
            return 2;
        case 3:
            removeGroup(line, -1);
            return 3;
        case 4:
            cleanTable(tables, stack, l, c);
            return 4;
        case 5:
            resetTable(tables, line, stack, l, c);
            return 5;
        case 6:
            showStack(stack);
            showLine(line);
            showTables(tables, l, c);
            return 6;
        case 0:
            return 0;
    }
}

#pragma clang diagnostic pop

int main() {
    int l, c;

    printf("Digite o numero de linhas: ");
    scanf("%d", &l);
    printf("Digite o numero de colunas: ");
    scanf("%d", &c);

    /* Matriz de mesas */
    Table **tables = (Table **) malloc(c * sizeof(Table));
    createTables(tables, l, c);

    /* Fila de espera */
    Queue *line = (Queue *) malloc(sizeof(Queue));
    createLine(line);

    /* Pilha de pratos */
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    createStack(stack);

    while (menu(line, tables, stack, l, c) != 0);

    puts("Expediente finalizado!\nAté mais!");

    freeTables(tables, l);
    freeLine(line);
    freeStack(stack);

    return 0;
}