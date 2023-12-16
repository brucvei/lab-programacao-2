/* Bruna Caetano - SI - 2023 */
// Controle de locação de veículos a clientes

#ifndef TRABALHO_03_LISTA_H
#define TRABALHO_03_LISTA_H

#include "locacoes.h"

// Listas
typedef struct lista {
    Carro veiculo;
    struct lista *prox;
} Veiculos;

typedef struct lista2 {
    Pessoa cliente;
    struct lista2 *prox;
} Clientes;

typedef struct lista3 {
    Aluguel locacao;
    struct lista3 *prox;
} Locacoes;

// Funções auxiliares
Veiculos *inicializarVeiculos(void);
Clientes *inicializarClientes(void);
Locacoes *inicializarLocacoes(void);

Carro *encontrarVeiculo(Veiculos *veiculos, char placa[]);
Pessoa *encontrarCliente(Clientes *clientes, char cnh[]);

int tamanhoLista(Veiculos *veiculos);

// Funções principais
/* Cadastras veículo na lista */
Veiculos *cadastrarVeiculo(Veiculos *veiculos);

/* Cadastras clientes na lista */
Clientes *cadastrarCliente(Clientes *clientes);

/* Locar um veículos */
Locacoes *locarVeiculo(Locacoes *locacoes, Veiculos *veiculos, Clientes *clientes);

/* Devolver um veículo */
Locacoes *devolverVeiculo(Veiculos *veiculos, Locacoes *locacoes);

/* Lista todos os veículos */
void listarVeiculos(Veiculos *veiculos);

/* Lista todos os clientes */
void listarClientes(Clientes *clientes);

/* Listar todas as locações */
void listarLocacoes(Locacoes *locacoes);


#endif //TRABALHO_03_LISTA_H