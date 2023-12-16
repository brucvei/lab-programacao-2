/* Bruna Caetano - SI - 2023 */

#include <menu.h>

int main(void) {
    puts("Locadora de veículos");
    Locacoes *listaLocacoes;
    Clientes *listaClientes;
    Veiculos *listaVeiculos;
    listaLocacoes = inicializarLocacoes();
    listaClientes = inicializarClientes();
    listaVeiculos = inicializarVeiculos();

    int opcao;
    do {
        puts("\nEscolha uma opção:");
        printf("1 - Cadastrar veículo\n");
        printf("2 - Listar veículos\n");
        printf("3 - Cadastrar cliente\n");
        printf("4 - Listar clientes\n");
        printf("5 - Locar carro\n");
        printf("6 - Devolver carro\n");
        printf("7 - Listar locações\n");
        printf("8 - Relatorios\n");
        printf("0 - Voltar\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                listaVeiculos = cadastrarVeiculo(listaVeiculos);
                break;
            case 2:
                listarVeiculos(listaVeiculos);
                break;
            case 3:
                listaClientes = cadastrarCliente(listaClientes);
                break;
            case 4:
                listarClientes(listaClientes);
                break;
            case 5:
                listaLocacoes = locarVeiculo(listaLocacoes, listaVeiculos, listaClientes);
                break;
            case 6:
                puts("\nInsira informações sobre a locação para devolver o carro: ");
                char placa[8];
                printf("Placa: ");
                scanf("%s", placa);
                listaVeiculos = devolverVeiculo(listaVeiculos, placa);
                listaLocacoes = finalizarLocacao(listaLocacoes, placa);
                break;
            case 7:
                listarLocacoes(listaLocacoes);
                break;
            case 8:
                menuRelatorios(listaLocacoes, listaClientes, listaVeiculos);
                return 2;
            case 0:
                return 0;
        }
    } while (opcao != 0);

    puts("Até logo!");
    free(listaLocacoes);
    free(listaClientes);
    free(listaVeiculos);

    return 0;
}