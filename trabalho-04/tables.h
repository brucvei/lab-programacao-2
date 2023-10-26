// Bruna e Lucas - SI

#ifndef TRABALHO_04_TABLES_H
#define TRABALHO_04_TABLES_H

#include "stacks.h"

/*
 * id        -> número da mesa
 * account   -> comanda
 * sitting   -> quantidade de pessoas sentadas
 * available -> disponibilidade
 * clean     -> se está com pratos sujos ou não
*/
typedef struct {
    int id;
    int account;
    int sitting;
    bool available;
    bool clean;
} Table;

/* Cria matriz com as mesas */
void createTables(Table **tables, int l, int c);
void freeTables(Table **tables, int l);

/* Encontra a primeira mesa disponível */
int findAvailableTable(Table **tables, int l, int c);

/* Encontra uma mesa disponivel para o grupo ou o coloca na fila de espera
 * -1 - primeiro da fila
 *  0 - novo grupo
 * >0 - qntd */
void fillTable(Queue *line, Table **tables, int l, int c, int option);

/* Libera a mesa / termina uma refeição */
void releaseTable(Table **tables, int l, int c);

/* Mostra todas as mesas */
void showTables(Table **tables, int l, int c);

/* Limpa a mesa */
void cleanTable(Table **tables, Stack *stack, int l, int c);

/* Repõe pratos na mesa e fornece a opção de sentar um grupo*/
void resetTable(Table **tables, Queue *line, Stack *stack, int l, int c);

void printTable(Table table);
#endif //TRABALHO_04_TABLES_H
