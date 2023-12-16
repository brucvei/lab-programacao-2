/* Bruna Caetano - SI - 2023 */

#include "menu.h"

void listasLocacoesAtivas(Locacoes *list) {
    Date dataInicial, dataFinal;
    int achou = 0;
    printf("Data inicial (DD MM AAAA): ");
    scanf("%d %d %d", &dataInicial.day, &dataInicial.month, &dataInicial.year);
    printf("Data final (DD MM AAAA): ");
    scanf("%d %d %d", &dataFinal.day, &dataFinal.month, &dataFinal.year);
    Locacoes *aux = list;
    printf("\nLocações ativas no período de %d/%d/%d a %d/%d/%d:\n", dataInicial.day, dataInicial.month,
           dataInicial.year, dataFinal.day, dataFinal.month, dataFinal.year);
    while (aux != NULL) {
        if (isBetweenDates(aux->retirada, dataInicial, dataFinal) || isBetweenDates(aux->devolucao, dataInicial, dataFinal)) {
            printarLocacao(aux);
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
    Clientes cliente;
    printf("CNH: ");
    scanf("%s", cliente.cnh);
    Locacoes *aux = listaLocacoes;
    if (encontrarCliente(listaClientes, cliente.cnh) == NULL) {
        puts("Cliente não cadastrado!");
    } else {
        printf("Locações do cliente %s:\n", cliente.cnh);
        while (aux != NULL) {
            if (strcmp(aux->cliente.cnh, cliente.cnh) == 0) {
                printarLocacao(aux);
            }
            aux = aux->prox;
        }
    }
}

void listarFaturamentoMensal(Locacoes *list) {
    puts("\nFaturamento da locadora:");
    int mes, ano;
    printf("Insira o mês: ");
    scanf("%d", &mes);
    printf("Insira o ano: ");
    scanf("%d", &ano);
    Locacoes *aux = list;
    float faturamento = 0;
    if (aux[0].valor == 0.00) {
        puts("Nenhuma locação cadastrada!");
    } else {
        while (aux != NULL) {
            if (aux->devolucao.month == mes && aux->devolucao.year == ano) {
                faturamento += aux->valor;
            }
            aux = aux->prox;
        }
    }
    printf("Faturamento: %.2f\n", faturamento);
}

void listarVeiculosMaisRodados(Veiculos *list) {
    puts("\nListar os 3 veículos mais rodados:");
    Veiculos *aux = list;
    Veiculos *maisRodado = list;
    int length = tamanhoLista(list);
    if (length >= 1) {
        while (aux != NULL) {
            if (aux->km > maisRodado->km) {
                maisRodado = aux;
            }
            aux = aux->prox;
        }
        printarVeiculo(maisRodado);

        if (length >= 2) {
            aux = list;
            Veiculos *segundoMaisRodado = list;
            while (aux != NULL) {
                if (aux->km > segundoMaisRodado->km && aux->km < maisRodado->km) {
                    segundoMaisRodado = aux;
                }
                aux = aux->prox;
            }
            printarVeiculo(segundoMaisRodado);

            if (length >= 3) {
                aux = list;
                Veiculos *terceiroMaisRodado = list;
                while (aux != NULL) {
                    if (aux->km > terceiroMaisRodado->km &&
                        aux->km < segundoMaisRodado->km) {
                        terceiroMaisRodado = aux;
                    }
                    aux = aux->prox;
                }
                printarVeiculo(terceiroMaisRodado);
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

void listarVeiculosDisponiveis(Veiculos *list) {
    puts("\nVeículos disponíveis: ");
    Veiculos *aux = list;
    if (list == NULL) {
        puts("Nenhum veículo encontrado!");
    } else {
        while (aux != NULL) {
            if (aux->disponibilidade == true) {
                printarVeiculo(aux);
            }
            aux = aux->prox;
        }
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
    }
}