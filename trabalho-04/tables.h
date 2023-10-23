// Bruna e Lucas - SI

#ifndef TRABALHO_04_TABLES_H
#define TRABALHO_04_TABLES_H

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

/* Encontra uma mesa disponivel para o grupo ou o coloca na fila de espera */
void fillTable(Queue *line, Table **tables, int l, int c);

/* Libera a mesa / termina uma refeição */
void releaseTable(Table **tables);

/* Mostra todas as mesas */
void showTables(Table **tables, int l, int c);

/* Limpa a mesa */
void cleanTable(Table **tables, Stack *stack, int l, int c);


#endif //TRABALHO_04_TABLES_H
