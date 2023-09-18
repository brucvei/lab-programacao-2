/* Bruna Caetano - SI - 2023 */

#include "menu.h"

void listasLocacoesAtivas(ListaLocacao *listaLocacoes) {
    Date dataInicial, dataFinal;
    printf("Data inicial (DD MM AAAA): ");
    scanf("%d %d %d", &dataInicial.day, &dataInicial.month, &dataInicial.year);
    printf("Data final (DD MM AAAA): ");
    scanf("%d %d %d", &dataFinal.day, &dataFinal.month, &dataFinal.year);
    ListaLocacao *aux = listaLocacoes;
    printf("Locações ativas no período de %d/%d/%d a %d/%d/%d:\n", dataInicial.day, dataInicial.month,
           dataInicial.year, dataFinal.day, dataFinal.month, dataFinal.year);
    while (aux != NULL) {
        if (isBetweenDates(aux->locacao.retirada, dataInicial, dataFinal) == true) {
            printarLocacao(&aux->locacao);
        }
        aux = aux->prox;
    }
}

void listarLocacoesCliente(ListaLocacao *listaLocacoes, ListaCliente *listaClientes) {
    puts("\nLocações por cliente: ");
    Cliente cliente;
    printf("CNH: ");
    scanf("%s", cliente.cnh);
    ListaLocacao *aux = listaLocacoes;
    if (encontrarCliente(listaClientes, cliente.cnh) == NULL) {
        puts("Cliente não cadastrado!");
    } else {
        printf("Locações do cliente %s:\n", cliente.cnh);
        while (aux != NULL) {
            if (strcmp(aux->locacao.cliente.cnh, cliente.cnh) == 0) {
                printarLocacao(&aux->locacao);
            }
            aux = aux->prox;
        }
    }
}

void listarFaturamento(ListaLocacao *listaLocacoes) {
    puts("\nFaturamento da locadora:");
    ListaLocacao *aux = listaLocacoes;
    float faturamento = 0;
    if (aux[0].locacao.valor == 0.00) {
        puts("Nenhuma locação cadastrada!");
    } else {
        while (aux != NULL) {
            faturamento += aux->locacao.valor;
            aux = aux->prox;
        }
    }
    printf("Faturamento: %.2f\n", faturamento);
}

void listarVeiculosMaisRodados(ListaVeiculo *listaVeiculos) {
    puts("Listar os 3 veículos mais rodados:");
    ListaVeiculo *aux = listaVeiculos;
    ListaVeiculo *maisRodado = listaVeiculos;
    int length = tamanhoLista(listaVeiculos);
    if (length >= 1) {
        while (strcmp(aux->veiculo.placa, "") != 0) {
            if (aux->veiculo.km > maisRodado->veiculo.km) {
                maisRodado = aux;
            }
            aux = aux->prox;
        }
        printarVeiculo(&maisRodado->veiculo);

        if (length >= 2) {
            aux = listaVeiculos;
            ListaVeiculo *segundoMaisRodado = listaVeiculos;
            while (strcmp(aux->veiculo.placa, "") != 0) {
                if (aux->veiculo.km > segundoMaisRodado->veiculo.km && aux->veiculo.km < maisRodado->veiculo.km) {
                    segundoMaisRodado = aux;
                }
                aux = aux->prox;
            }
            printarVeiculo(&segundoMaisRodado->veiculo);

            if (length >= 3) {
                aux = listaVeiculos;
                ListaVeiculo *terceiroMaisRodado = listaVeiculos;
                while (strcmp(aux->veiculo.placa, "") != 0) {
                    if (aux->veiculo.km > terceiroMaisRodado->veiculo.km &&
                        aux->veiculo.km < segundoMaisRodado->veiculo.km) {
                        terceiroMaisRodado = aux;
                    }
                    aux = aux->prox;
                }
                printarVeiculo(&terceiroMaisRodado->veiculo);
            } else {
                puts("Foi possível listar apenas 2 veículos!");
            }
        } else {
            puts("Foi possível listar apenas 1 veículo!");
        }
    } else {
        puts("Nenhum veículo cadastrado!");
    }
}

void listarVeiculosDisponiveis(ListaVeiculo *listaVeiculos) {
    puts("Veículos disponíveis: ");
    ListaVeiculo *aux = listaVeiculos;
    if (strcmp(aux[0].veiculo.placa, "") == 0) {
        puts("Nenhum veículo encontrado!");
    } else {
        while (strcmp(aux->veiculo.placa, "") != 0) {
            if (aux->veiculo.disponibilidade == true) {
                printarVeiculo(&aux->veiculo);
            }
            aux = aux->prox;
        }
    }
}

void menuListas(ListaLocacao **listaLocacoes, ListaCliente **listaClientes, ListaVeiculo **listaVeiculos) {
    puts("Escolha uma opção:");
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
    }
}

void menuRelatorios(ListaLocacao **listaLocacoes, ListaCliente **listaClientes, ListaVeiculo **listaVeiculos) {
    puts("Escolha uma opção:");
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
            listarLocacoesCliente(*listaLocacoes, *listaClientes);
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
    }
}

int menuPrincipal(ListaLocacao **listaLocacoes, ListaCliente **listaClientes, ListaVeiculo **listaVeiculos) {
    puts("Escolha uma opção:");
    int opcao;
    printf("1 - Listas\n");
    printf("2 - Relatórios\n");
    printf("0 - Sair\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            menuListas(listaLocacoes, listaClientes, listaVeiculos);
            return 1;
        case 2:
            menuRelatorios(listaLocacoes, listaClientes, listaVeiculos);
            return 2;
        case 0:
            return 0;
    }
}
