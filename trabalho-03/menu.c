/* Bruna Caetano - SI - 2023 */

#include "menu.h"
#include <lista.c>
#include <manipulacao-datas.c>

void listasLocacoesAtivas(ListaLocacao *listaLocacoes) {
    Date dataInicial, dataFinal;
    printf("Data inicial: ");
    scanf("%d/%d/%d", &dataInicial.day, &dataInicial.month, &dataInicial.year);
    printf("Data final: ");
    scanf("%d/%d/%d", &dataFinal.day, &dataFinal.month, &dataFinal.year);
    ListaLocacao *aux = listaLocacoes;
    while (aux != NULL) {
        if (compararDatas(dataInicial, aux->locacao.retirada) == true &&
            compararDatas(aux->locacao.devolucao, dataFinal) == true) {
            printf("Cliente: %s\n", aux->locacao.cliente.nome);
            printf("Veículo: %s\n", aux->locacao.veiculo.modelo);
            printf("Retirada: %d/%d/%d\n", aux->locacao.retirada.day, aux->locacao.retirada.month,
                   aux->locacao.retirada.year);
            printf("Devolução: %d/%d/%d\n", aux->locacao.devolucao.day, aux->locacao.devolucao.month,
                   aux->locacao.devolucao.year);
            printf("Valor: %.2f\n", aux->locacao.valor);
            printf("\n");
        }
        aux = aux->prox;
    }
}

void listarLocacoesCliente(ListaLocacao *listaLocacoes) {
    Cliente cliente;
    printf("CNH: ");
    scanf("%s", cliente.cnh);
    ListaLocacao *aux = listaLocacoes;
    while (aux != NULL) {
        if (strcmp(aux->locacao.cliente.cnh, cliente.cnh) == 0) {
            printf("Cliente: %s\n", aux->locacao.cliente.nome);
            printf("Veículo: %s\n", aux->locacao.veiculo.modelo);
            printf("Retirada: %d/%d/%d\n", aux->locacao.retirada.day, aux->locacao.retirada.month,
                   aux->locacao.retirada.year);
            printf("Devolução: %d/%d/%d\n", aux->locacao.devolucao.day, aux->locacao.devolucao.month,
                   aux->locacao.devolucao.year);
            printf("Valor: %.2f\n", aux->locacao.valor);
            printf("\n");
        }
        aux = aux->prox;
    }
}

void listarFaturamento(ListaLocacao *listaLocacoes) {
    ListaLocacao *aux = listaLocacoes;
    float faturamento = 0;
    while (aux != NULL) {
        faturamento += aux->locacao.valor;
        aux = aux->prox;
    }
    printf("Faturamento: %.2f\n", faturamento);
}

void listarVeiculosMaisRodados(ListaVeiculo *listaVeiculos) {
    ListaVeiculo *aux = listaVeiculos;
    ListaVeiculo *maisRodado = listaVeiculos;
    while (aux != NULL) {
        if (aux->veiculo.km > maisRodado->veiculo.km) {
            maisRodado = aux;
        }
        aux = aux->prox;
    }
    printf("Placa: %s\n", maisRodado->veiculo.placa);
    printf("Modelo: %s\n", maisRodado->veiculo.modelo);
    printf("KM: %.2f\n", maisRodado->veiculo.km);
    printf("\n");
    aux = listaVeiculos;
    ListaVeiculo *segundoMaisRodado = listaVeiculos;
    while (aux != NULL) {
        if (aux->veiculo.km > segundoMaisRodado->veiculo.km && aux->veiculo.km < maisRodado->veiculo.km) {
            segundoMaisRodado = aux;
        }
        aux = aux->prox;
    }
    printf("Placa: %s\n", segundoMaisRodado->veiculo.placa);
    printf("Modelo: %s\n", segundoMaisRodado->veiculo.modelo);
    printf("KM: %.2f\n", segundoMaisRodado->veiculo.km);
    printf("\n");
    aux = listaVeiculos;
    ListaVeiculo *terceiroMaisRodado = listaVeiculos;
    while (aux != NULL) {
        if (aux->veiculo.km > terceiroMaisRodado->veiculo.km && aux->veiculo.km < segundoMaisRodado->veiculo.km) {
            terceiroMaisRodado = aux;
        }
        aux = aux->prox;
    }
    printf("Placa: %s\n", terceiroMaisRodado->veiculo.placa);
    printf("Modelo: %s\n", terceiroMaisRodado->veiculo.modelo);
    printf("KM: %.2f\n", terceiroMaisRodado->veiculo.km);
    printf("\n");
}

void listarVeiculosDisponiveis(ListaVeiculo *listaVeiculos) {
    ListaVeiculo *aux = listaVeiculos;
    while (aux != NULL) {
        if (aux->veiculo.disponibilidade == true) {
            printf("Placa: %s\n", aux->veiculo.placa);
            printf("Modelo: %s\n", aux->veiculo.modelo);
            printf("\n");
        }
        aux = aux->prox;
    }
}

void menuListas(ListaLocacao **listaLocacoes, ListaCliente **listaClientes, ListaVeiculo **listaVeiculos) {
    int opcao;
    printf("1 - Cadastrar veículo\n");
    printf("2 - Listar veículos\n");
    printf("3 - Cadastrar cliente\n");
    printf("4 - Listar clientes\n");
    printf("5 - Locar carro\n");
    printf("6 - Devolver carro\n");
    printf("7 - Listar locações\n");
    printf("0 - Voltar\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            cadastrarVeiculo(listaVeiculos);
            break;
        case 2:
            listarVeiculos(*listaVeiculos);
            break;
        case 3:
            cadastrarCliente(listaClientes);
            break;
        case 4:
            listarClientes(*listaClientes);
            break;
        case 5:
            locarVeiculo(listaLocacoes, listaVeiculos, listaClientes);
            break;
        case 6:
            devolverVeiculo(listaVeiculos, listaLocacoes);
            break;
        case 7:
            listarLocacoes(*listaLocacoes);
            break;
        case 0:
            menuPrincipal(listaLocacoes, listaClientes, listaVeiculos);
            break;
        default:
            printf("Opção inválida!\n");
            menuListas(listaLocacoes, listaClientes, listaVeiculos);
            break;
    }
}

void menuRelatorios(ListaLocacao **listaLocacoes, ListaCliente **listaClientes, ListaVeiculo **listaVeiculos) {
    int opcao;
    printf("1 - Listar locações ativas em um período de tempo\n");
    printf("2 - Listar locações já realizadas por um cliente\n");
    printf("3 - Listar faturamento da locadora por mês\n");
    printf("4 - Listar placa dos 3 veículos mais rodados\n");
    printf("5 - Listar placa e modelo de todos os veículos disponíveis\n");
    printf("0 - Voltar\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            listasLocacoesAtivas(*listaLocacoes);
            break;
        case 2:
            listarLocacoesCliente(*listaLocacoes);
            break;
        case 3:
            listarFaturamento(*listaLocacoes);
            break;
        case 4:
            listarVeiculosMaisRodados(*listaVeiculos);
            break;
        case 5:
            listarVeiculosDisponiveis(*listaVeiculos);
            break;
        case 0:
            menuPrincipal(listaLocacoes, listaClientes, listaVeiculos);
            break;
        default:
            printf("Opção inválida!\n");
            menuRelatorios(listaLocacoes, listaClientes, listaVeiculos);
            break;
    }
}
