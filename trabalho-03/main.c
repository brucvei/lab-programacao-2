/* Bruna Caetano - SI - 2023 */

#include <menu.c>

int main() {
    puts("Locadora de veículos");
    ListaLocacao *listaLocacoes;
    ListaCliente *listaClientes;
    ListaVeiculo *listaVeiculos;
    *listaLocacoes = inicializarLocacoes(&listaLocacoes);
    *listaClientes = inicializarClientes(&listaClientes);
    *listaVeiculos = inicializarVeiculos(&listaVeiculos);

    while (menuPrincipal(&listaLocacoes, &listaClientes, &listaVeiculos) != 0);

    return 0;
}