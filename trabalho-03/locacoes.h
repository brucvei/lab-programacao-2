#ifndef TRABALHO_03_LOCACOES_H
#define TRABALHO_03_LOCACOES_H

#include "cliente.h"

typedef struct locacao {
    Pessoa cliente;
    Carro veiculo;
    Date retirada;
    Date devolucao;
    float valor;
} Aluguel;

void printarLocacao(Aluguel *locacao);


#endif //TRABALHO_03_LOCACOES_H
