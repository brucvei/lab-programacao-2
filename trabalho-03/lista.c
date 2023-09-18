/* Bruna Caetano - SI - 2023 */
#include "lista.h"

ListaVeiculo *inicializarVeiculos(ListaVeiculo *listaVeiculos) {
    listaVeiculos = (ListaVeiculo *) malloc(sizeof(ListaVeiculo));
    return listaVeiculos;
}

ListaCliente *inicializarClientes(ListaCliente *listaClientes) {
    listaClientes = (ListaCliente *) malloc(sizeof(ListaCliente));
    return listaClientes;
}

ListaLocacao *inicializarLocacoes(ListaLocacao *listaLocacoes) {
    listaLocacoes = (ListaLocacao *) malloc(sizeof(ListaLocacao));
    return listaLocacoes;
}

Veiculo *encontrarVeiculo(ListaVeiculo *listaVeiculos, char placa[]) {
    puts("\nEncontrando veículo...");
    ListaVeiculo *aux = listaVeiculos;
    while (aux != NULL) {
        if (strcmp(aux->veiculo.placa, placa) == 0) {
            return &aux->veiculo;
        }
        aux = aux->prox;
    }
    return NULL;
}

Cliente *encontrarCliente(ListaCliente *listaClientes, char cnh[]) {
    puts("\nEncontrando cliente...");
    ListaCliente *aux = listaClientes;
    while (aux != NULL) {
        if (strcmp(aux->cliente.cnh, cnh) == 0) {
            return &aux->cliente;
        }
        aux = aux->prox;
    }
    return NULL;
}

void cadastrarVeiculo(ListaVeiculo **listaVeiculos) {
    puts("\nCadastrando veículo...");
    puts("Insira informacoes sobre o veículo:");
    ListaVeiculo *novoVeiculo = (ListaVeiculo *) malloc(sizeof(ListaVeiculo));
    printf("Placa: ");
    scanf("%s", novoVeiculo->veiculo.placa);
    Veiculo *veiculo = encontrarVeiculo(*listaVeiculos, novoVeiculo->veiculo.placa);
    if (veiculo != NULL) {
        puts("Veículo já cadastrado!");
    } else {
        printf("Marca: ");
        scanf("%s", novoVeiculo->veiculo.marca);
        printf("Modelo: ");
        scanf("%s", novoVeiculo->veiculo.modelo);
        printf("Ano: ");
        scanf("%d", &novoVeiculo->veiculo.ano);
        printf("Kilometragem percorrida: ");
        scanf("%f", &novoVeiculo->veiculo.km);
        printf("Valor da diaria: ");
        scanf("%f", &novoVeiculo->veiculo.valor);
        novoVeiculo->veiculo.disponibilidade = true;
        novoVeiculo->prox = *listaVeiculos;
        *listaVeiculos = novoVeiculo;
    }
}

void listarVeiculos(ListaVeiculo *listaVeiculos) {
    puts("\nListando veículos...");
    puts("\nVeículos cadastrados: ");
    ListaVeiculo *aux = listaVeiculos;
    if (strcmp(aux[0].veiculo.placa, "") == 0) {
        puts("Nenhum veículo cadastrado!");
    } else {
        while (aux != NULL) {
            printf("Placa: %s\n", aux->veiculo.placa);
            printf("Marca: %s\n", aux->veiculo.marca);
            printf("Modelo: %s\n", aux->veiculo.modelo);
            printf("Ano: %d\n", aux->veiculo.ano);
            printf("Kilometragem: %.2f\n", aux->veiculo.km);
            printf("Valor da diaria: %.2f\n", aux->veiculo.valor);
            printf("Disponibilidade: %s\n", aux->veiculo.disponibilidade ? "Disponível" : "Indisponível");
            printf("\n");
            aux = aux->prox;
        }
    }
}

void cadastrarCliente(ListaCliente **listaClientes) {
    puts("\nCadastrando cliente...");
    puts("\nInsira informacoes sobre o cliente: ");
    ListaCliente *novoCliente = (ListaCliente *) malloc(sizeof(ListaCliente));
    printf("CNH: ");
    scanf("%s", novoCliente->cliente.cnh);
    Cliente *cliente = encontrarCliente(*listaClientes, novoCliente->cliente.cnh);
    if (cliente != NULL) {
        puts("Cliente já cadastrado!");
    } else {
        printf("Nome: ");
        scanf("%s", novoCliente->cliente.nome);
        printf("Telefone: ");
        scanf("%s", novoCliente->cliente.telefone);
        novoCliente->prox = *listaClientes;
        *listaClientes = novoCliente;
    }
}

void listarClientes(ListaCliente *listaClientes) {
    puts("\nListando clientes...");
    puts("\nClientes cadastrados: ");
    ListaCliente *aux = listaClientes;
    if (strcmp(aux[0].cliente.cnh, "") == 0) {
        puts("Nenhum cliente cadastrado!");
    } else {
        while (aux != NULL) {
            printf("CNH: %s\n", aux->cliente.cnh);
            printf("Nome: %s\n", aux->cliente.nome);
            printf("Telefone: %s\n", aux->cliente.telefone);
            printf("\n");
            aux = aux->prox;
        }
    }
}

void locarVeiculo(ListaLocacao **listaLocacao, ListaVeiculo **listaVeiculos, ListaCliente **listaClientes) {
    puts("\nLocando veículo...");
    puts("\nInsira informacoes sobre a locação: ");
    ListaLocacao *novaLocacao = (ListaLocacao *) malloc(sizeof(ListaLocacao));
    char cnh[12];
    printf("CNH: ");
    scanf("%s", cnh);
    Cliente *cliente = encontrarCliente(*listaClientes, cnh);
    if (cliente == NULL) {
        puts("Cliente não cadastrado!");
    } else {
        novaLocacao->locacao.cliente = *cliente;
        char placa[8];
        printf("Placa: ");
        scanf("%s", placa);
        Veiculo *veiculo = encontrarVeiculo(*listaVeiculos, placa);
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
            novaLocacao->prox = *listaLocacao;
            *listaLocacao = novaLocacao;
            ListaVeiculo *aux = *listaVeiculos;
            while (aux != NULL) {
                if (strcmp(aux->veiculo.placa, novaLocacao->locacao.veiculo.placa) == 0) {
                    if (aux->veiculo.disponibilidade) {
                        aux->veiculo.disponibilidade = false;
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

void devolverVeiculo(ListaVeiculo **listaVeiculos, ListaLocacao **listaLocacoes) {
    puts("\nDevolvendo veículo...");
    puts("\nInsira informacoes sobre a locacao para devolver o carro: ");
    char placa[8];
    printf("Placa: ");
    scanf("%s", placa);
    if (!encontrarVeiculo(*listaVeiculos, placa)) {
        puts("Veículo não cadastrado!");
    } else {
        ListaVeiculo *aux = *listaVeiculos;
        while (aux != NULL) {
            if (strcmp(aux->veiculo.placa, placa) == 0) {
                aux->veiculo.disponibilidade = true;
                break;
            }
            aux = aux->prox;
        }
        ListaLocacao *aux2 = *listaLocacoes;
        while (aux2 != NULL) {
            if (strcmp(aux2->locacao.veiculo.placa, placa) == 0) {
                aux2->locacao.valor = (float)
                                              daysBetweenDates(aux2->locacao.retirada, aux2->locacao.devolucao) *
                                      aux2->locacao.veiculo.valor;
                break;
            }
            aux2 = aux2->prox;
        }
        puts("Veículo devolvido com sucesso!");
    }
}

void listarLocacoes(ListaLocacao *listaLocacao) {
    puts("\nListando locações...");
    puts("\nLocações cadastradas: ");
    ListaLocacao *aux = listaLocacao;
    if (strcmp(aux[0].locacao.veiculo.placa, "") == 0) {
        puts("Nenhuma locação cadastrada!");
    } else {
        while (aux != NULL) {
            printf("CNH: %s\n", aux->locacao.cliente.cnh);
            printf("Placa: %s\n", aux->locacao.veiculo.placa);
            printf("Data de retirada: %d/%d/%d\n", aux->locacao.retirada.day, aux->locacao.retirada.month,
                   aux->locacao.retirada.year);
            printf("Data de devolução: %d/%d/%d\n", aux->locacao.devolucao.day, aux->locacao.devolucao.month,
                   aux->locacao.devolucao.year);
            printf("Valor: %.2f\n", aux->locacao.valor);
            printf("\n");
            aux = aux->prox;
        }
    }
}