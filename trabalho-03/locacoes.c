#include "locacoes.h"


void printarLocacao(Aluguel *locacao){
    printf("\nCliente:");
    printarCliente(&locacao->cliente);
    printf("\nVeículo:");
    printarVeiculo(&locacao->veiculo);
    printf("Data de retirada: %d/%d/%d\n", locacao->retirada.day, locacao->retirada.month, locacao->retirada.year);
    printf("Data de devolução: %d/%d/%d\n", locacao->devolucao.day, locacao->devolucao.month, locacao->devolucao.year);
    printf("Valor: %.2f\n", locacao->valor);
}