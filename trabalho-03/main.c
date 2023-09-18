/* Bruna Caetano - SI - 2023 */

#include <menu.h>

int main() {
    puts("Locadora de veículos");
    ListaLocacao *listaLocacoes;
    ListaCliente *listaClientes;
    ListaVeiculo *listaVeiculos;
    listaLocacoes = inicializarLocacoes(listaLocacoes);
    listaClientes = inicializarClientes(listaClientes);
    listaVeiculos = inicializarVeiculos(listaVeiculos);


    while (menuPrincipal(&listaLocacoes, &listaClientes, &listaVeiculos) != 0);

    puts("Até logo!");
    puts("Encerrando programa...");
    free(listaLocacoes);
    free(listaClientes);
    free(listaVeiculos);

    return 0;
}