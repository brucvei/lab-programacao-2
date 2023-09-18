/* Bruna Caetano - SI - 2023 */

#ifndef TRABALHO_03_MENU_H
#define TRABALHO_03_MENU_H

#include "lista.h"

// Funções

/* Lista todas as locações ativas em um período de tempo fornecido */
void listasLocacoesAtivas(ListaLocacao *listaLocacoes);

/* Lista todas as locações já realizadas por um cliente */
void listarLocacoesCliente(ListaLocacao *listaLocacoes, ListaCliente *listaClientes);

/* Lista o faturamento da locadora */
void listarFaturamento(ListaLocacao *listaLocacoes);

/* Lista os 3 veículos mais rodados */
void listarVeiculosMaisRodados(ListaVeiculo *listaVeiculos);

/* Lista todos os veículos disponíveis */
void listarVeiculosDisponiveis(ListaVeiculo *listaVeiculos);

/* Menu de criação, listagem e deleção das listas declaradas no lista.h
 * Recebe as listas p passar para as próximas funções*/
void menuListas(ListaLocacao **listaLocacoes, ListaCliente **listaClientes, ListaVeiculo **listaVeiculos);

/* Menu de geração dos relatórios
 * Recebe as listas p passar para as próximas funções*/
void menuRelatorios(ListaLocacao **listaLocacoes, ListaCliente **listaClientes, ListaVeiculo **listaVeiculos);

/* Menu principal
 * Retorna um int pq ela é chamada na condição do while no main*/
int menuPrincipal(ListaLocacao **listaLocacoes, ListaCliente **listaClientes, ListaVeiculo **listaVeiculos);

#endif //TRABALHO_03_MENU_H
