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
typedef struct veiculo {
    char placa[8];
    char marca[20];
    char modelo[20];
    int ano;
    float km;
    float valor;
    bool disponibilidade;
} Veiculo;

typedef struct cliente {
    char cnh[12];
    char nome[20];
    char telefone[12];
} Cliente;

typedef struct locacao {
    Cliente cliente;
    Veiculo veiculo;
    Date retirada;
    Date devolucao;
    float valor;
} Locacao;

// Listas encadeaddas
typedef struct lista {
    Veiculo veiculo;
    struct lista *prox;
} ListaVeiculo;

typedef struct lista2 {
    Cliente cliente;
    struct lista2 *prox;
} ListaCliente;

typedef struct lista3 {
    Locacao locacao;
    struct lista3 *prox;
} ListaLocacao;

// Funções auxiliares
ListaVeiculo *inicializarVeiculos(void);
ListaCliente *inicializarClientes(void);
ListaLocacao *inicializarLocacoes(void);

Veiculo *encontrarVeiculo(ListaVeiculo *listaVeiculos, char placa[]);
Cliente *encontrarCliente(ListaCliente *listaClientes, char cnh[]);

int tamanhoLista(ListaVeiculo *listaVeiculo);

void printarVeiculo(Veiculo *veiculo);
void printarCliente(Cliente *cliente);
void printarLocacao(Locacao *locacao);

// Funções principais
/* Cadastras veículo na lista */
void cadastrarVeiculo(ListaVeiculo **listaVeiculos);

/* Lista todos os veículos */
void listarVeiculos(ListaVeiculo *listaVeiculos);

/* Cadastras clientes na lista */
void cadastrarCliente(ListaCliente **listaClientes);

/* Lista todos os clientes */
void listarClientes(ListaCliente *listaClientes);

/* Locar um veículos */
void locarVeiculo(ListaLocacao **listaLocacoes, ListaVeiculo **listaVeiculos, ListaCliente **listaClientes);

/* Devolver um veículo */
void devolverVeiculo(ListaVeiculo **listaVeiculos, ListaLocacao **listaLocacoes);

/* Listar todas as locações */
void listarLocacoes(ListaLocacao *listaLocacoes);


#endif //TRABALHO_03_LISTA_H