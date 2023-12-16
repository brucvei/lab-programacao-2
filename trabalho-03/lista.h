/* Bruna Caetano - SI - 2023 */
// Controle de locação de veículos a clientes

#ifndef TRABALHO_03_LISTA_H
#define TRABALHO_03_LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "manipulacao-datas.h"

// Structs
typedef struct lista {
    char placa[8];
    char marca[20];
    char modelo[20];
    int ano;
    float km;
    float valor;
    bool disponibilidade;
    struct lista *prox;
} Veiculos;

typedef struct lista2 {
    char cnh[12];
    char nome[20];
    char telefone[12];
    struct lista2 *prox;
} Clientes;

typedef struct lista3 {
    Clientes cliente;
    Veiculos veiculo;
    Date retirada;
    Date devolucao;
    float valor;
    struct lista3 *prox;
} Locacoes;

// Funções auxiliares
Veiculos *inicializarVeiculos(void);
Clientes *inicializarClientes(void);
Locacoes *inicializarLocacoes(void);

Veiculos *encontrarVeiculo(Veiculos *listaVeiculos, char placa[]);
Clientes *encontrarCliente(Clientes *listaClientes, char cnh[]);

int tamanhoLista(Veiculos *list);

void printarVeiculo(Veiculos *veiculo);
void printarCliente(Clientes *cliente);
void printarLocacao(Locacoes *locacao);

// Funções principais
/* Cadastras veículo na lista */
Veiculos *cadastrarVeiculo(Veiculos *list);

/* Lista todos os veículos */
void listarVeiculos(Veiculos *list);

/* Cadastras clientes na lista */
Clientes *cadastrarCliente(Clientes *list);

/* Lista todos os clientes */
void listarClientes(Clientes *list);

/* Locar um veículos */
Locacoes *locarVeiculo(Locacoes *listaLocacoes, Veiculos *listaVeiculos, Clientes *listaClientes);

/* Devolver um veículo */
Veiculos *devolverVeiculo(Veiculos *listaVeiculos, char *placa);
Locacoes *finalizarLocacao(Locacoes *listaLocacoes, char *placa);
/* Listar todas as locações */
void listarLocacoes(Locacoes *list);


#endif //TRABALHO_03_LISTA_H