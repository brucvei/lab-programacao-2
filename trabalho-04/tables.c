// Bruna e Lucas - SI

#include "stacks.c"
#include "tables.h"

void createTables(Table **tables, int l, int c) {
    for (int i = 0; i < l; i++) {
        tables[i] = (Table *) malloc(c * sizeof(Table));
    }

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            tables[i][j].id = i * c + j + 1;
            tables[i][j].account = 0;
            tables[i][j].sitting = 0;
            tables[i][j].available = true;
            tables[i][j].clean = true;
        }
    }
}

void freeTables(Table **tables, int l) {
    for (int i = 0; i < l; i++) {
        free(tables[i]);
    }
    free(tables);
}

int findAvailableTable(Table **tables, int l, int c) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (tables[i][j].available) {
                return tables[i][j].id;
            }
        }
    }

    return -1;
}

void fillTable(Queue *line, Table **tables, int l, int c) {
    int id = findAvailableTable(tables, l, c);
    if (id != -1) {
        int qntd;
        printf("Quantas pessoas tem no grupo? ");
        scanf("%d", &qntd);

        tables[(id - 1) / c][(id - 1) % c].account = id;
        tables[(id - 1) / c][(id - 1) % c].sitting = qntd;
        tables[(id - 1) / c][(id - 1) % c].available = false;
        tables[(id - 1) / c][(id - 1) % c].clean = true;
    } else {
        insertGroup(line);
    }
}

void releaseTable(Table **tables) {
    int id;
    printf("Qual a mesa? ");
    scanf("%d", &id);

    tables[(id - 1) / SEATS][(id - 1) % SEATS].account = 0;
    tables[(id - 1) / SEATS][(id - 1) % SEATS].sitting = 0;
    tables[(id - 1) / SEATS][(id - 1) % SEATS].available = true;
    tables[(id - 1) / SEATS][(id - 1) % SEATS].clean = false;
    printf("Mesa %d liberada!", id);
}

void showTables(Table **tables, int l, int c) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("Mesa %d: ", tables[i][j].id);
            printf("Disponível: %s ", tables[i][j].available ? "Sim" : "Não");
            printf("Limpa: %s ", tables[i][j].clean ? "Sim" : "Não");
            printf("Comanda: %d ", tables[i][j].account);
            printf("Sentados: %d\n", tables[i][j].sitting);
        }
    }
}

void cleanTable(Table **tables, Stack *stack, int l, int c) {
    int id;
    printf("Qual a mesa? ");
    scanf("%d", &id);

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (tables[i][j].id == id) {
                tables[i][j].clean = true;
            }
        }
    }

    push(stack);
    printf("Mesa %d limpa!", id);
}
