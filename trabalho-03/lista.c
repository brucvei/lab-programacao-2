/* Bruna Caetano - SI - 2023 */
#include "lista.h"

//Funções principais
Veiculos *cadastrarVeiculo(Veiculos *veiculos) {
    puts("\nInsira informações sobre o veículo:");

    Carro *novoVeiculo = (Carro *) malloc(sizeof(Carro));
    printf("Placa: ");
    scanf("%s", novoVeiculo->placa);

    Carro *veiculo = encontrarVeiculo(veiculos, novoVeiculo->veiculo.placa);
    if (veiculo != NULL) {
        puts("Veículo já cadastrado!");
        return veiculos;
    }

    veiculos->prox = createVeiculo(novoVeiculo->placa);
    free(novoVeiculo);
    puts("Veículo cadastrado com sucesso!");
}

void listarVeiculos(Veiculos *veiculos) {
    puts("\nVeículos cadastrados: ");
    Veiculos *aux = veiculos;
    if (strcmp(aux[0].veiculo.placa, "") == 0) {
        puts("Nenhum veículo cadastrado!");
    } else {
        while (strcmp(aux->veiculo.placa, "") != 0) {
            printarVeiculo(&aux->veiculo);
            aux = aux->prox;
        }
    }
}

void cadastrarCliente(Clientes *clientes) {
    puts("\nInsira informações sobre o cliente: ");
    Clientes *novoCliente = (Clientes *) malloc(sizeof(Clientes));
    printf("CNH: ");
    scanf("%s", novoCliente->cliente.cnh);
    Pessoa *cliente = encontrarCliente(clientes, novoCliente->cliente.cnh);
    if (cliente != NULL) {
        puts("Pessoa já cadastrado!");
    } else {
        printf("Nome: ");
        scanf("%s", novoCliente->cliente.nome);
        printf("Telefone: ");
        scanf("%s", novoCliente->cliente.telefone);
        novoCliente->prox = clientes;
        clientes = novoCliente;
        puts("Pessoa cadastrado com sucesso!");
    }
}

void listarClientes(Clientes *clientes) {
    puts("\nClientes cadastrados: ");
    Clientes *aux = clientes;
    if (strcmp(aux[0].cliente.cnh, "") == 0) {
        puts("Nenhum cliente cadastrado!");
    } else {
        while (strcmp(aux->cliente.cnh, "") != 0) {
            printarCliente(&aux->cliente);
            aux = aux->prox;
        }
    }
}

void locarVeiculo(Locacoes *locacoes, Veiculos *veiculos, Clientes *clientes) {
    puts("\nInsira informações sobre a locação: ");
    Locacoes *novaLocacao = (Locacoes *) malloc(sizeof(Locacoes));
    char cnh[12];
    printf("CNH: ");
    scanf("%s", cnh);
    Pessoa *cliente = encontrarCliente(clientes, cnh);
    if (cliente == NULL) {
        puts("Pessoa não cadastrado!");
    } else {
        novaLocacao->locacao.cliente = *cliente;
        char placa[8];
        printf("Placa: ");
        scanf("%s", placa);
        Carro *veiculo = encontrarVeiculo(veiculos, placa);
        if (veiculo == NULL) {
            puts("Veículo não cadastrado!");
        } else {
            novaLocacao->locacao.veiculo = *veiculo;
            printf("Data de retirada (DD MM AAAA): ");
            scanf("%d %d %d", &novaLocacao->locacao.retirada.day, &novaLocacao->locacao.retirada.month,
                  &novaLocacao->locacao.retirada.year);
            printf("Data de devolução (DD MM AAAA): ");
            scanf("%d %d %d", &novaLocacao->locacao.devolucao.day, &novaLocacao->locacao.devolucao.month,
                  &novaLocacao->locacao.devolucao.year);
            novaLocacao->locacao.valor = 0;
            novaLocacao->prox = locacoes;
            locacoes = novaLocacao;
            Veiculos *aux = veiculos;
            while (strcmp(aux->veiculo.placa, "") != 0) {
                if (strcmp(aux->veiculo.placa, novaLocacao->locacao.veiculo.placa) == 0) {
                    if (aux->veiculo.disponibilidade) {
                        aux->veiculo.disponibilidade = false;
                        puts("Locação realizada com sucesso!");
                        break;
                    } else {
                        puts("Veículo indisponível!");
                        break;
                    }
                }
                aux = aux->prox;
            }
        }
    }
}

void devolverVeiculo(Veiculos *veiculos, Locacoes *locacoes) {
    puts("\nInsira informações sobre a locação para devolver o carro: ");
    char placa[8];
    printf("Placa: ");
    scanf("%s", placa);
    Carro encontrado = *encontrarVeiculo(veiculos, placa);
    if (strcmp(encontrado.placa, placa) != 0) {
        puts("Veículo não cadastrado!");
    } else if(encontrado.disponibilidade == true) {
        puts("Veículo não está locado!");
    } else {
        Veiculos *aux = veiculos;
        float km;
        while (aux != NULL) {
            if (strcmp(aux->veiculo.placa, placa) == 0) {
                aux->veiculo.disponibilidade = true;
                printf("Quilometragem percorrida: ");
                scanf("%f", &km);
                aux->veiculo.km += km;
                break;
            }
            aux = aux->prox;
        }
        Locacoes *aux2 = locacoes;
        while (aux2 != NULL) {
            if (strcmp(aux2->locacao.veiculo.placa, placa) == 0) {
                aux2->locacao.valor = (float) daysBetweenDates(aux2->locacao.retirada, aux2->locacao.devolucao) *
                                      aux2->locacao.veiculo.valor;
                printf("Valor total da locação: %.2f\n", aux2->locacao.valor);
                break;
            }
            aux2 = aux2->prox;
        }
        puts("Veículo devolvido com sucesso!");
    }
}

void listarLocacoes(Locacoes *locacoes) {
    puts("\nLocações cadastradas: ");
    Locacoes *aux = locacoes;
    if (strcmp(aux[0].locacao.veiculo.placa, "") == 0) {
        puts("Nenhuma locação cadastrada!");
    } else {
        while (strcmp(aux->locacao.cliente.cnh, "") != 0) {
            printarLocacao(&aux->locacao);
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

Carro *encontrarVeiculo(Veiculos *veiculos, char placa[]) {
    Veiculos *aux = veiculos;
    while (aux != NULL) {
        if (strcmp(aux->veiculo.placa, placa) == 0) {
            return &aux->veiculo;
        }
        aux = aux->prox;
    }
    return NULL;
}

Pessoa *encontrarCliente(Clientes *clientes, char cnh[]) {
    Clientes *aux = clientes;
    while (aux != NULL) {
        if (strcmp(aux->cliente.cnh, cnh) == 0) {
            return &aux->cliente;
        }
        aux = aux->prox;
    }
    return NULL;
}

int tamanhoLista(Veiculos *veiculos) {
    Veiculos *aux = veiculos;
    int length = 0;
    while (strcmp(aux->veiculo.placa, "") != 0) {
        length++;
        aux = aux->prox;
    }
    return length;
}