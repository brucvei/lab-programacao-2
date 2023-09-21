/* Bruna Caetano - SI - 2023 */
#include "lista.h"

//Funções principais
void cadastrarVeiculo(ListaVeiculo **listaVeiculos) {
    puts("\nInsira informações sobre o veículo:");
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
        printf("Quilometragem percorrida: ");
        scanf("%f", &novoVeiculo->veiculo.km);
        printf("Valor da diária: ");
        scanf("%f", &novoVeiculo->veiculo.valor);
        novoVeiculo->veiculo.disponibilidade = true;
        novoVeiculo->prox = *listaVeiculos;
        *listaVeiculos = novoVeiculo;
        puts("Veículo cadastrado com sucesso!");
    }
}

void listarVeiculos(ListaVeiculo *listaVeiculos) {
    puts("\nVeículos cadastrados: ");
    ListaVeiculo *aux = listaVeiculos;
    if (strcmp(aux[0].veiculo.placa, "") == 0) {
        puts("Nenhum veículo cadastrado!");
    } else {
        while (strcmp(aux->veiculo.placa, "") != 0) {
            printarVeiculo(&aux->veiculo);
            aux = aux->prox;
        }
    }
}

void cadastrarCliente(ListaCliente **listaClientes) {
    puts("\nInsira informações sobre o cliente: ");
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
        puts("Cliente cadastrado com sucesso!");
    }
}

void listarClientes(ListaCliente *listaClientes) {
    puts("\nClientes cadastrados: ");
    ListaCliente *aux = listaClientes;
    if (strcmp(aux[0].cliente.cnh, "") == 0) {
        puts("Nenhum cliente cadastrado!");
    } else {
        while (strcmp(aux->cliente.cnh, "") != 0) {
            printarCliente(&aux->cliente);
            aux = aux->prox;
        }
    }
}

void locarVeiculo(ListaLocacao **listaLocacao, ListaVeiculo **listaVeiculos, ListaCliente **listaClientes) {
    puts("\nInsira informações sobre a locação: ");
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

void devolverVeiculo(ListaVeiculo **listaVeiculos, ListaLocacao **listaLocacoes) {
    puts("\nInsira informações sobre a locação para devolver o carro: ");
    char placa[8];
    printf("Placa: ");
    scanf("%s", placa);
    Veiculo encontrado = *encontrarVeiculo(*listaVeiculos, placa);
    if (strcmp(encontrado.placa, placa) != 0) {
        puts("Veículo não cadastrado!");
    } else if(encontrado.disponibilidade == true) {
        puts("Veículo não está locado!");
    } else {
        ListaVeiculo *aux = *listaVeiculos;
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
        ListaLocacao *aux2 = *listaLocacoes;
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

void listarLocacoes(ListaLocacao *listaLocacao) {
    puts("\nLocações cadastradas: ");
    ListaLocacao *aux = listaLocacao;
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
ListaVeiculo *inicializarVeiculos(void) {
    return (ListaVeiculo *) malloc(sizeof(ListaVeiculo));
}

ListaCliente *inicializarClientes(void) {
    return (ListaCliente *) malloc(sizeof(ListaCliente));
}

ListaLocacao *inicializarLocacoes(void) {
    return (ListaLocacao *) malloc(sizeof(ListaLocacao));
}

Veiculo *encontrarVeiculo(ListaVeiculo *listaVeiculos, char placa[]) {
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
    ListaCliente *aux = listaClientes;
    while (aux != NULL) {
        if (strcmp(aux->cliente.cnh, cnh) == 0) {
            return &aux->cliente;
        }
        aux = aux->prox;
    }
    return NULL;
}

int tamanhoLista(ListaVeiculo *listaVeiculo) {
    ListaVeiculo *aux = listaVeiculo;
    int length = 0;
    while (strcmp(aux->veiculo.placa, "") != 0) {
        length++;
        aux = aux->prox;
    }
    return length;
}

void printarVeiculo(Veiculo *veiculo){
    printf("\nPlaca: %s\n", veiculo->placa);
    printf("Marca: %s\n", veiculo->marca);
    printf("Modelo: %s\n", veiculo->modelo);
    printf("Ano: %d\n", veiculo->ano);
    printf("Kilometragem: %.2f\n", veiculo->km);
    printf("Valor da diaria: %.2f\n", veiculo->valor);
    printf("Disponibilidade: %s\n", veiculo->disponibilidade ? "Disponível" : "Indisponível");
}

void printarCliente(Cliente *cliente){
    printf("\nCNH: %s\n", cliente->cnh);
    printf("Nome: %s\n", cliente->nome);
    printf("Telefone: %s\n", cliente->telefone);
}

void printarLocacao(Locacao *locacao){
    printf("\nCliente:");
    printarCliente(&locacao->cliente);
    printf("\nVeículo:");
    printarVeiculo(&locacao->veiculo);
    printf("Data de retirada: %d/%d/%d\n", locacao->retirada.day, locacao->retirada.month, locacao->retirada.year);
    printf("Data de devolução: %d/%d/%d\n", locacao->devolucao.day, locacao->devolucao.month, locacao->devolucao.year);
    printf("Valor: %.2f\n", locacao->valor);
}