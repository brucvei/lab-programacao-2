/* Bruna Caetano - SI - 2023 */
#include "lista.h"

ListaVeiculo inicializarVeiculos(ListaVeiculo **listaVeiculos) {
    *listaVeiculos = NULL;
    return **listaVeiculos;
}

ListaCliente inicializarClientes(ListaCliente **listaClientes) {
    *listaClientes = NULL;
    return **listaClientes;
}

ListaLocacao inicializarLocacoes(ListaLocacao **listaLocacoes) {
    *listaLocacoes = NULL;
    return **listaLocacoes;
}

void cadastrarVeiculo(ListaVeiculo **listaVeiculos){
    ListaVeiculo *novoVeiculo = (ListaVeiculo *) malloc(sizeof(ListaVeiculo));
    printf("Placa: ");
    scanf("%s", novoVeiculo->veiculo.placa);
    printf("Marca: ");
    scanf("%s", novoVeiculo->veiculo.marca);
    printf("Modelo: ");
    scanf("%s", novoVeiculo->veiculo.modelo);
    printf("Ano: ");
    scanf("%d", &novoVeiculo->veiculo.ano);
    printf("Km: ");
    scanf("%f", &novoVeiculo->veiculo.km);
    printf("Valor: ");
    scanf("%f", &novoVeiculo->veiculo.valor);
    novoVeiculo->veiculo.disponibilidade = true;
    novoVeiculo->prox = *listaVeiculos;
    *listaVeiculos = novoVeiculo;
}

void listarVeiculos(ListaVeiculo *listaVeiculos){
    ListaVeiculo *aux = listaVeiculos;
    while (aux != NULL){
        printf("Placa: %s\n", aux->veiculo.placa);
        printf("Marca: %s\n", aux->veiculo.marca);
        printf("Modelo: %s\n", aux->veiculo.modelo);
        printf("Ano: %d\n", aux->veiculo.ano);
        printf("Km: %.2f\n", aux->veiculo.km);
        printf("Valor: %.2f\n", aux->veiculo.valor);
        printf("Disponibilidade: %s\n", aux->veiculo.disponibilidade ? "Disponível" : "Indisponível");
        printf("\n");
        aux = aux->prox;
    }
}

void cadastrarCliente(ListaCliente **listaClientes){
    ListaCliente *novoCliente = (ListaCliente *) malloc(sizeof(ListaCliente));
    printf("CNH: ");
    scanf("%s", novoCliente->cliente.cnh);
    printf("Nome: ");
    scanf("%s", novoCliente->cliente.nome);
    printf("Telefone: ");
    scanf("%s", novoCliente->cliente.telefone);
    novoCliente->prox = *listaClientes;
    *listaClientes = novoCliente;
}

void listarClientes(ListaCliente *listaClientes){
    ListaCliente *aux = listaClientes;
    while (aux != NULL){
        printf("CNH: %s\n", aux->cliente.cnh);
        printf("Nome: %s\n", aux->cliente.nome);
        printf("Telefone: %s\n", aux->cliente.telefone);
        printf("\n");
        aux = aux->prox;
    }
}

void locarVeiculo(ListaLocacao **ListaLocacao, ListaVeiculo **listaVeiculos, ListaCliente **listaClientes){
    ListaLocacao *novaLocacao = (ListaLocacao *) malloc(sizeof(ListaLocacao));
    printf("CNH: ");
    scanf("%s", novaLocacao->locacao.cliente.cnh);
    printf("Placa: ");
    scanf("%s", novaLocacao->locacao.veiculo.placa);
    printf("Data de retirada (DD MM AAAA): ");
    scanf("%d %d %d", &novaLocacao->locacao.retirada.day, &novaLocacao->locacao.retirada.month, &novaLocacao->locacao.retirada.year);
    printf("Data de devolução (DD MM AAAA): ");
    scanf("%d %d %d", &novaLocacao->locacao.devolucao.day, &novaLocacao->locacao.devolucao.month, &novaLocacao->locacao.devolucao.year);
    novaLocacao->locacao.valor = 0;
    novaLocacao->prox = *ListaLocacao;
    *ListaLocacao = novaLocacao;
    ListaVeiculo *aux = *listaVeiculos;
    while (aux != NULL){
        if (strcmp(aux->veiculo.placa, novaLocacao->locacao.veiculo.placa) == 0){
            aux->veiculo.disponibilidade = false;
            break;
        }
        aux = aux->prox;
    }
}

void devolverVeiculo(ListaVeiculo **listaVeiculos, ListaLocacao **listaLocacoes){
    char placa[8];
    printf("Placa: ");
    scanf("%s", placa);
    ListaVeiculo *aux = *listaVeiculos;
    while (aux != NULL){
        if (strcmp(aux->veiculo.placa, placa) == 0){
            aux->veiculo.disponibilidade = true;
            break;
        }
        aux = aux->prox;
    }
    ListaLocacao *aux2 = *listaLocacoes;
    while (aux2 != NULL){
        if (strcmp(aux2->locacao.veiculo.placa, placa) == 0){
            aux2->locacao.valor = 0;
            break;
        }
        aux2 = aux2->prox;
    }
}

void listarLocacoes(ListaLocacao *listaLocacao){
    ListaLocacao *aux = listaLocacao;
    while (aux != NULL){
        printf("CNH: %s\n", aux->locacao.cliente.cnh);
        printf("Placa: %s\n", aux->locacao.veiculo.placa);
        printf("Data de retirada: %d/%d/%d\n", aux->locacao.retirada.day, aux->locacao.retirada.month, aux->locacao.retirada.year);
        printf("Data de devolução: %d/%d/%d\n", aux->locacao.devolucao.day, aux->locacao.devolucao.month, aux->locacao.devolucao.year);
        printf("Valor: %.2f\n", aux->locacao.valor);
        printf("\n");
        aux = aux->prox;
    }
}