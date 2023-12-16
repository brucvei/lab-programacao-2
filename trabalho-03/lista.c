/* Bruna Caetano - SI - 2023 */
#include "lista.h"

//Funções principais
Veiculos *cadastrarVeiculo(Veiculos *list) {
    puts("\nInsira informações sobre o veículo:");
    Veiculos *novoVeiculo = (Veiculos *) malloc(sizeof(Veiculos));

    printf("Placa: ");
    scanf("%s", novoVeiculo->placa);
    Veiculos *veiculo = encontrarVeiculo(list, novoVeiculo->placa);
    if (veiculo != NULL) {
        puts("Veículo já cadastrado!");
        return list;
    }

    printf("Marca: ");
    scanf("%s", novoVeiculo->marca);
    printf("Modelo: ");
    scanf("%s", novoVeiculo->modelo);
    printf("Ano: ");
    scanf("%d", &novoVeiculo->ano);
    printf("Quilometragem percorrida: ");
    scanf("%f", &novoVeiculo->km);
    printf("Valor da diária: ");
    scanf("%f", &novoVeiculo->valor);
    novoVeiculo->disponibilidade = true;
    novoVeiculo->prox = list;
    list = novoVeiculo;
    puts("Veículo cadastrado com sucesso!");
    return list;
}

void listarVeiculos(Veiculos *list) {
    puts("\nVeículos cadastrados: ");
    Veiculos *aux = list;
    if (list == NULL) {
        puts("Nenhum veículo cadastrado!");
    } else {
        while (aux != NULL) {
            printarVeiculo(aux);
            aux = aux->prox;
        }
    }
}

Clientes *cadastrarCliente(Clientes *list) {
    puts("\nInsira informações sobre o cliente: ");
    Clientes *novoCliente = (Clientes *) malloc(sizeof(Clientes));

    printf("CNH: ");
    scanf("%s", novoCliente->cnh);
    Clientes *cliente = encontrarCliente(list, novoCliente->cnh);
    if (cliente != NULL) {
        puts("Cliente já cadastrado!");
        return list;
    }

    printf("Nome: ");
    scanf("%s", novoCliente->nome);
    printf("Telefone: ");
    scanf("%s", novoCliente->telefone);
    novoCliente->prox = list;
    list = novoCliente;
    puts("Cliente cadastrado com sucesso!");
    return list;
}

void listarClientes(Clientes *list) {
    puts("\nClientes cadastrados: ");
    Clientes *aux = list;
    if (list == NULL) {
        puts("Nenhum cliente cadastrado!");
    } else {
        while (aux != NULL) {
            printarCliente(aux);
            aux = aux->prox;
        }
    }
}

Locacoes *locarVeiculo(Locacoes *listaLocacao, Veiculos *listaVeiculos, Clientes *listaClientes) {
    puts("\nInsira informações sobre a locação: ");
    Locacoes *novaLocacao = (Locacoes *) malloc(sizeof(Locacoes));
    char cnh[12];

    printf("CNH: ");
    scanf("%s", cnh);
    Clientes *cliente = encontrarCliente(listaClientes, cnh);
    if (cliente == NULL) {
        puts("Cliente não cadastrado!");
        return listaLocacao;
    }

    novaLocacao->cliente = *cliente;
    char placa[8];

    printf("Placa: ");
    scanf("%s", placa);
    Veiculos *veiculo = encontrarVeiculo(listaVeiculos, placa);
    if (veiculo == NULL) {
        puts("Veículo não cadastrado!");
        return listaLocacao;
    }

    novaLocacao->veiculo = *veiculo;
    printf("Data de retirada (DD MM AAAA): ");
    scanf("%d %d %d", &novaLocacao->retirada.day, &novaLocacao->retirada.month,
          &novaLocacao->retirada.year);
    printf("Data de devolução (DD MM AAAA): ");
    scanf("%d %d %d", &novaLocacao->devolucao.day, &novaLocacao->devolucao.month,
          &novaLocacao->devolucao.year);
    novaLocacao->valor = 0;
    novaLocacao->prox = listaLocacao;
    Veiculos *aux = listaVeiculos;
    while (strcmp(aux->placa, "") != 0) {
        if (strcmp(aux->placa, novaLocacao->veiculo.placa) == 0) {
            if (aux->disponibilidade) {
                aux->disponibilidade = false;
                puts("Locação realizada com sucesso!");
                break;
            } else {
                puts("Veículo indisponível!");
                break;
            }
        }
        aux = aux->prox;
    }
    listaLocacao = novaLocacao;
    return listaLocacao;
}

Veiculos *devolverVeiculo(Veiculos *listaVeiculos, char *placa) {
    Veiculos encontrado = *encontrarVeiculo(listaVeiculos, placa);
    if (strcmp(encontrado.placa, placa) != 0) {
        puts("Veículo não cadastrado!");
        return listaVeiculos;
    }
    if (encontrado.disponibilidade == true) {
        puts("Veículo não está locado!");
        return listaVeiculos;
    }

    Veiculos *aux = listaVeiculos;
    float km;
    while (aux != NULL) {
        if (strcmp(aux->placa, placa) == 0) {
            aux->disponibilidade = true;
            printf("Quilometragem percorrida: ");
            scanf("%f", &km);
            aux->km += km;
            break;
        }
        aux = aux->prox;
    }

    return aux;
}

Locacoes *finalizarLocacao(Locacoes *listaLocacoes, char *placa) {
    Locacoes *aux = listaLocacoes;
    while (aux != NULL) {
        if (strcmp(aux->veiculo.placa, placa) == 0) {
            aux->valor = (float) daysBetweenDates(aux->retirada, aux->devolucao) *
                                 aux->valor;
            printf("Valor total da locação: %.2f\n", aux->valor);
            break;
        }
        aux = aux->prox;
    }

    puts("Veículo devolvido com sucesso!");
    return aux;
}

void listarLocacoes(Locacoes *list) {
    puts("\nLocações cadastradas: ");
    Locacoes *aux = list;
    if (list == NULL) {
        puts("Nenhuma locação cadastrada!");
    } else {
        while (aux != NULL) {
            printarLocacao(aux);
            aux = aux->prox;
        }
    }
}

// Funções auxiliares
Veiculos *inicializarVeiculos(void) {
    return (Veiculos *) malloc(sizeof(Veiculos));
}

Clientes *inicializarClientes(void) {
    return (Clientes *) malloc(sizeof(Clientes));
}

Locacoes *inicializarLocacoes(void) {
    return (Locacoes *) malloc(sizeof(Locacoes));
}

Veiculos *encontrarVeiculo(Veiculos *listaVeiculos, char placa[]) {
    Veiculos *aux = listaVeiculos;
    while (aux != NULL) {
        if (strcmp(aux->placa, placa) == 0) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

Clientes *encontrarCliente(Clientes *listaClientes, char cnh[]) {
    Clientes *aux = listaClientes;
    while (aux != NULL) {
        if (strcmp(aux->cnh, cnh) == 0) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

int tamanhoLista(Veiculos *list) {
    Veiculos *aux = list;
    int length = 0;
    while (strcmp(aux->placa, "") != 0) {
        length++;
        aux = aux->prox;
    }
    return length;
}

void printarVeiculo(Veiculos *veiculo) {
    printf("\nPlaca: %s\n", veiculo->placa);
    printf("Marca: %s\n", veiculo->marca);
    printf("Modelo: %s\n", veiculo->modelo);
    printf("Ano: %d\n", veiculo->ano);
    printf("Kilometragem: %.2f\n", veiculo->km);
    printf("Valor da diaria: %.2f\n", veiculo->valor);
    printf("Disponibilidade: %s\n", veiculo->disponibilidade ? "Disponível" : "Indisponível");
}

void printarCliente(Clientes *cliente) {
    printf("\nCNH: %s\n", cliente->cnh);
    printf("Nome: %s\n", cliente->nome);
    printf("Telefone: %s\n", cliente->telefone);
}

void printarLocacao(Locacoes *locacao) {
    printf("\nCliente:");
    printarCliente(&locacao->cliente);
    printf("\nVeículo:");
    printarVeiculo(&locacao->veiculo);
    printf("Data de retirada: %d/%d/%d\n", locacao->retirada.day, locacao->retirada.month, locacao->retirada.year);
    printf("Data de devolução: %d/%d/%d\n", locacao->devolucao.day, locacao->devolucao.month, locacao->devolucao.year);
    printf("Valor: %.2f\n", locacao->valor);
}