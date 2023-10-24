// Bruna e Lucas - SI

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

void fillTable(Queue *line, Table **tables, int l, int c, int group) {
    int qntd;
    if (group == 0) {
        printf("Quantas pessoas tem no grupo? \n-> ");
        scanf("%d", &qntd);
    } else {
        qntd = group;
    }
    int id = findAvailableTable(tables, l, c);
    if (id != -1) {

        tables[(id - 1) / c][(id - 1) % c].account = id + 30;
        tables[(id - 1) / c][(id - 1) % c].available = false;
        tables[(id - 1) / c][(id - 1) % c].clean = true;

        if (qntd > 4) {
            int aux = qntd - 4;
            qntd = 4;
            fillTable(line, tables, l, c, aux);
        }

        tables[(id - 1) / c][(id - 1) % c].sitting = qntd;
    } else {
        insertGroup(line, qntd);
    }
}

void releaseTable(Table **tables, int l, int c) {
    int id;
    printf("Qual a mesa? \n-> ");
    scanf("%d", &id);

    tables[(id - 1) / c][(id - 1) % c].account = 0;
    tables[(id - 1) / c][(id - 1) % c].sitting = 0;
    tables[(id - 1) / c][(id - 1) % c].available = true;
    tables[(id - 1) / c][(id - 1) % c].clean = false;
    printf("Mesa %d liberada!\n", id);
}

void showTables(Table **tables, int l, int c) {
    int opcao;
    printf("Deseja mostrar todas as mesas? \n(1 - Sim / 0 - Não)\n-> ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) {
                printTable(tables[i][j]);
            }
        }
    } else if (opcao == 0) {
        int id;
        printf("Qual a mesa? \n-> ");
        scanf("%d", &id);
        printTable(tables[(id - 1) / c][(id - 1) % c]);
    }
}

void cleanTable(Table **tables, Stack *stack, int l, int c) {
    int id;
    printf("Qual a mesa? \n-> ");
    scanf("%d", &id);

    tables[(id - 1) / c][(id - 1) % c].clean = true;
    tables[(id - 1) / c][(id - 1) % c].available = false;

    push(stack);
    printf("Mesa %d limpa!\n", id);
}

void resetTable(Table **tables, Queue *line, Stack *stack, int l, int c) {
    int id;
    printf("Qual a mesa? \n-> ");
    scanf("%d", &id);

    tables[(id - 1) / c][(id - 1) % c].available = true;

    pop(stack);
    printf("Pratos repostos na mesa %d!\n", id);
    int opcao;
    printf("Deseja preencher a mesa com outro grupo? \n(1 - Sim / 0 - Não)\n-> ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        fillTable(line, tables, l, c, 0);
    } else if (opcao == 0) {
        printf("Mesa %d disponível!\n", id);
    }
}

void printTable(Table table){
    printf("\nMesa %d: ", table.id);
    printf("\nDisponível: %s ", table.available ? "Sim" : "Não");
    printf("\tLimpa: %s ", table.clean ? "Sim" : "Não");
    printf("\nComanda: %d ", table.account);
    printf("\tSentados: %d\n", table.sitting);
}
