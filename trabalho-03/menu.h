/* Bruna Caetano - SI - 2023 */

#ifndef TRABALHO_03_MENU_H
#define TRABALHO_03_MENU_H

#include "lista.h"

// Funções

/* Lista todas as locações ativas em um período de tempo fornecido */
void listasLocacoesAtivas(Locacoes *list);

/* Lista todas as locações já realizadas por um cliente */
void listarLocacoesCliente(Locacoes *listaLocacoes, Clientes *listaClientes);

/* Lista o faturamento da locadora por mês */
void listarFaturamentoMensal(Locacoes *list);

/* Lista os 3 veículos mais rodados */
void listarVeiculosMaisRodados(Veiculos *list);

/* Lista todos os veículos disponíveis */
void listarVeiculosDisponiveis(Veiculos *list);

/* Menu de geração dos relatórios
 * Recebe as listas p passar para as próximas funções*/
void menuRelatorios(Locacoes *listaLocacoes, Clientes *listaClientes, Veiculos *listaVeiculos);

#endif //TRABALHO_03_MENU_H
