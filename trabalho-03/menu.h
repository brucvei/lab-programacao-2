/* Bruna Caetano - SI - 2023 */

#ifndef TRABALHO_03_MENU_H
#define TRABALHO_03_MENU_H

#include "lista.h"

// Funções

/* Lista todas as locações ativas em um período de tempo selecionado */
void listasLocacoesAtivas(ListaLocacao *listaLocacoes);

/* Lista todas as locações já realizadas por um cliente */
void listarLocacoesCliente(ListaLocacao *listaLocacoes);

/* Lista o faturamento da locadora por mês */
void listarFaturamento(ListaLocacao *listaLocacoes);

/* Lista a placa dos 3 veículos mais rodados */
void listarVeiculosMaisRodados(ListaVeiculo *listaVeiculos);

/* Lista a placa e o modelo de todos os veículos disponíveis */
void listarVeiculosDisponiveis(ListaVeiculo *listaVeiculos);

/* Menu de criação, listagem e deleção das listas declaradas no lista.h */
void menuListas(ListaLocacao **listaLocacoes, ListaCliente **listaClientes, ListaVeiculo **listaVeiculos);

/* Menu de geração dos relatórios */
void menuRelatorios(ListaLocacao **listaLocacoes, ListaCliente **listaClientes, ListaVeiculo **listaVeiculos);

/* Menu principal */
void menuPrincipal(ListaLocacao **listaLocacoes, ListaCliente **listaClientes, ListaVeiculo **listaVeiculos);

#endif //TRABALHO_03_MENU_H
