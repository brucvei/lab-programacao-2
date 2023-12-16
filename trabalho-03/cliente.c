#include "cliente.h"

void printarCliente(Pessoa *cliente){
    printf("\nCNH: %s\n", cliente->cnh);
    printf("Nome: %s\n", cliente->nome);
    printf("Telefone: %s\n", cliente->telefone);
}