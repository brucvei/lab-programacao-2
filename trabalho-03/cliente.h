#ifndef TRABALHO_03_CLIENTE_H
#define TRABALHO_03_CLIENTE_H

#include "veiculos.h"

typedef struct cliente {
    char cnh[12];
    char nome[20];
    char telefone[12];
} Pessoa;

void printarCliente(Pessoa *cliente);


#endif //TRABALHO_03_CLIENTE_H
