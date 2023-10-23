// Bruna e Lucas - SI

#include "tables.c"

int menu(Queue *line, Table **tables, Stack *stack, int l, int c) {
    int opcao;
    puts("\nEscolha uma opção:");
    puts("1 - Chegada de clientes ao restaurante.");
    puts("2 - Finalizar refeição/liberar mesa.");
    puts("3 - Desistir de esperar.");
    puts("4 - Arrumar mesa.");
    puts("5 - Repor pratos.");
    puts("6 - Imprimir pilha de pratos, fila de espera e ocupação das mesas.");
    puts("0 - Terminar programa.");
    scanf("-> %d", &opcao);
    switch (opcao) {
        case 1:
            fillTable(line, tables, l, c);
        case 2:
            releaseTable(tables);
        case 3:
            removeGroup(line);
        case 4:
            cleanTable(tables, stack, l, c);
        case 5:

    }
    return opcao;
}

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

    freeTables(tables, l);
    freeLine(line);

    return 0;
}