/* Bruna Caetano - SI - 2023 */

#include "menu.h"

void listasLocacoesAtivas(Locacoes *listaLocacoes) {
    Date dataInicial, dataFinal;
    int achou = 0;
    printf("Data inicial (DD MM AAAA): ");
    scanf("%d %d %d", &dataInicial.day, &dataInicial.month, &dataInicial.year);
    printf("Data final (DD MM AAAA): ");
    scanf("%d %d %d", &dataFinal.day, &dataFinal.month, &dataFinal.year);
    Locacoes *aux = listaLocacoes;
    printf("\nLocações ativas no período de %d/%d/%d a %d/%d/%d:\n", dataInicial.day, dataInicial.month,
           dataInicial.year, dataFinal.day, dataFinal.month, dataFinal.year);
    while (aux != NULL) {
        if (isBetweenDates(aux->locacao.retirada, dataInicial, dataFinal) || isBetweenDates(aux->locacao.devolucao, dataInicial, dataFinal)) {
            printarLocacao(&aux->locacao);
            achou++;
        }
        aux = aux->prox;
    }
    if (achou == 0) {
        puts("Nenhuma locação ativa no período informado!\n");
    }
}

void listarLocacoesCliente(Locacoes *listaLocacoes, Clientes *listaClientes) {
    puts("\nLocações por cliente: ");
    Pessoa cliente;
    printf("CNH: ");
    scanf("%s", cliente.cnh);
    Locacoes *aux = listaLocacoes;
    if (encontrarCliente(listaClientes, cliente.cnh) == NULL) {
        puts("Pessoa não cadastrado!");
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

void listarFaturamentoMensal(Locacoes *listaLocacoes) {
    puts("\nFaturamento da locadora:");
    int mes, ano;
    printf("Insira o mês: ");
    scanf("%d", &mes);
    printf("Insira o ano: ");
    scanf("%d", &ano);
    Locacoes *aux = listaLocacoes;
    float faturamento = 0;
    if (aux[0].locacao.valor == 0.00) {
        puts("Nenhuma locação cadastrada!");
    } else {
        while (aux != NULL) {
            if (aux->locacao.devolucao.month == mes && aux->locacao.devolucao.year == ano) {
                faturamento += aux->locacao.valor;
            }
            aux = aux->prox;
        }
    }
    printf("Faturamento: %.2f\n", faturamento);
}

void listarVeiculosMaisRodados(Veiculos *listaVeiculos) {
    puts("\nListar os 3 veículos mais rodados:");
    Veiculos *aux = listaVeiculos;
    Veiculos *maisRodado = listaVeiculos;
    int length = tamanhoLista(listaVeiculos);
    if (length >= 1 && strcmp(aux->veiculo.placa, "") != 0) {
        while (strcmp(aux->veiculo.placa, "") != 0) {
            if (aux->veiculo.km > maisRodado->veiculo.km) {
                maisRodado = aux;
            }
            aux = aux->prox;
        }
        printarVeiculo(&maisRodado->veiculo);

        if (length >= 2) {
            aux = listaVeiculos;
            Veiculos *segundoMaisRodado = listaVeiculos;
            while (strcmp(aux->veiculo.placa, "") != 0) {
                if (aux->veiculo.km > segundoMaisRodado->veiculo.km && aux->veiculo.km < maisRodado->veiculo.km) {
                    segundoMaisRodado = aux;
                }
                aux = aux->prox;
            }
            printarVeiculo(&segundoMaisRodado->veiculo);

            if (length >= 3) {
                aux = listaVeiculos;
                Veiculos *terceiroMaisRodado = listaVeiculos;
                while (strcmp(aux->veiculo.placa, "") != 0) {
                    if (aux->veiculo.km > terceiroMaisRodado->veiculo.km &&
                        aux->veiculo.km < segundoMaisRodado->veiculo.km) {
                        terceiroMaisRodado = aux;
                    }
                    aux = aux->prox;
                }
                printarVeiculo(&terceiroMaisRodado->veiculo);
            } else {
                puts("\nFoi possível listar apenas 2 veículos!");
            }
        } else {
            puts("\nFoi possível listar apenas 1 veículo!");
        }
    } else {
        puts("\nNenhum veículo cadastrado!");
    }
}

void listarVeiculosDisponiveis(Veiculos *listaVeiculos) {
    puts("\nVeículos disponíveis: ");
    Veiculos *aux = listaVeiculos;
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

void menuListas(Locacoes *listaLocacoes, Clientes *listaClientes, Veiculos *listaVeiculos) {
    puts("\nEscolha uma opção:");
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
            listarVeiculos(listaVeiculos);
            break;
        case 3:
            cadastrarCliente(listaClientes);
            break;
        case 4:
            listarClientes(listaClientes);
            break;
        case 5:
            locarVeiculo(listaLocacoes, listaVeiculos, listaClientes);
            break;
        case 6:
            devolverVeiculo(listaVeiculos, listaLocacoes);
            break;
        case 7:
            listarLocacoes(listaLocacoes);
            break;
        case 0:
            menuPrincipal(listaLocacoes, listaClientes, listaVeiculos);
            break;
    }
}

void menuRelatorios(Locacoes *listaLocacoes, Clientes *listaClientes, Veiculos *listaVeiculos) {
    puts("\nEscolha uma opção:");
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
            listasLocacoesAtivas(listaLocacoes);
            break;
        case 2:
            listarLocacoesCliente(listaLocacoes, listaClientes);
            break;
        case 3:
            listarFaturamentoMensal(listaLocacoes);
            break;
        case 4:
            listarVeiculosMaisRodados(listaVeiculos);
            break;
        case 5:
            listarVeiculosDisponiveis(listaVeiculos);
            break;
        case 0:
            menuPrincipal(listaLocacoes, listaClientes, listaVeiculos);
            break;
    }
}

int menuPrincipal(Locacoes *listaLocacoes, Clientes *listaClientes, Veiculos *listaVeiculos) {
    puts("\nEscolha uma opção:");
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
