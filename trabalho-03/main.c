/* Bruna Caetano - SI - 2023 */

#include <menu.h>

int main(void) {
    puts("Locadora de veículos");
    ListaLocacao *listaLocacoes;
    ListaCliente *listaClientes;
    ListaVeiculo *listaVeiculos;
    listaLocacoes = inicializarLocacoes();
    listaClientes = inicializarClientes();
    listaVeiculos = inicializarVeiculos();

    while (menuPrincipal(&listaLocacoes, &listaClientes, &listaVeiculos) != 0);

    puts("Até logo!");
    free(listaLocacoes);
    free(listaClientes);
    free(listaVeiculos);

    return 0;
}