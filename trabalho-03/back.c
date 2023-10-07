#include "back.h"

Client *findClient(Client *list, char licensce[]) {
  Client *tmp = list;
  while (tmp != NULL) {
    if (strcmp(tmp->licence, licensce) == 0) {
      return tmp;
    }
    tmp = tmp->next;
  }
  return NULL;
}

Car *findCar(Car *list, char plate[]) {
  Car *tmp = list;
  while (tmp != NULL) {
    if (strcmp(tmp->plate, plate) == 0) {
      return tmp;
    }
    tmp = tmp->next;
  }
  return NULL;
}

void newClient(Client **reg) {
  printf("\nNovo cliente: ");
  Client *new = (Client *) malloc(sizeof(Client));
  printf("\nCarteira: ");
  scanf("%s", new->licence);
  Client *cliente = findClient(*reg, new->licence);
  if (cliente == NULL) {
    printf("Telefone: ");
    scanf("%s", new->fone);
    printf("Nome: ");
    scanf("%s", new->name);
    new->next = *reg;
    *reg = new;
    printf("\nCliente cadastrado!");
  } else
    printf("\nCliente já cadastrado!");
}

void newCar(Car **reg) {
  printf("\nNovo veiculo:");
  Car *new = (Car *) malloc(sizeof(Car));
  printf("\nPlaca: ");
  scanf("%s", new->plate);
  Car *veiculo = findCar(*reg, new->plate);
  if (veiculo == NULL) {
    printf("Ano: ");
    scanf("%d", &new->year);
    printf("KMs: ");
    scanf("%f", &new->km);
    printf("Valor: ");
    scanf("%f", &new->value);
    printf("Modelo: ");
    scanf("%s", new->model);
    printf("Marca: ");
    scanf("%s", new->brand);
    new->isFree = 0;
    new->next = *reg;
    *reg = new;
    printf("\nCarro cadastrado!");
  } else {
    printf("\nCarro já cadastrado!");
  }
}

void newRent(Rent **list, Car **car, Client **cliet) {
  printf("\nNova locação: ");
  char licensce[12];
  char placa[8];

  printf("\nCarteira do cliente: ");
  scanf("%s", licensce);
  printf("\nPlaca do carro: ");
  scanf("%s", placa);

  Rent *new = (Rent *) malloc(sizeof(Rent));
  Client *cliente = findClient(*cliet, licensce);
  Car *carrinho = findCar(*car, placa);

  if (cliente != NULL || carrinho != NULL) {
    new->client = *cliente;
    new->car = *carrinho;
    new->value = 0;
    new->next = *list;
    *list = new;
    Car *aux = *car;

    printf("\nData de in (DD MM AAAA): ");
    scanf("%d %d %d", &new->in.day, &new->in.month, &new->in.year);
    printf("Data de devolução (DD MM AAAA): ");
    scanf("%d %d %d", &new->out.day, &new->out.month, &new->out.year);

    while (strcmp(aux->plate, "") != 0) {
      if (strcmp(aux->plate, new->car.plate) == 0) {
        if (aux->isFree == 0) {
          aux->isFree = 1;
          printf("\nLocação realizada!");
          break;
        } else {
          printf("\nVeículo indisponível!");
          break;
        }
      }
      aux = aux->next;
    }
  } else {
    printf("\nCliente ou carro não cadastrado!");
  }
}

void listAllCars(Car *list) {
  printf("\nCarros: ");
  Car *aux = list;
  if (strcmp(aux[0].plate, "") == 0) {
    printf("\nNenhum carro encontrado!");
  } else {
    while (strcmp(aux->plate, "") != 0) {
      printf("\nAno: %d\n", aux->year);
      printf("KMs: %.2f\n", aux->km);
      printf("Valor: %.2f\n", aux->value);
      printf("Status: %s\n", aux->isFree == 0 ? "Livre" : "Alugado");
      printf("Modelo: %s\n", aux->model);
      printf("Marca: %s\n", aux->brand);
      printf("Placa: %s\n", aux->plate);
      aux = aux->next;
    }
  }
}

void listAllClients(Client *list) {
  printf("\nClientes: ");
  Client *aux = list;
  if (strcmp(aux[0].licence, "") == 0) {
    printf("\nNenhum cliente cadastrado!");
  } else {
    while (strcmp(aux->licence, "") != 0) {
      printf("\nCarteira: %s\n", aux->licence);
      printf("Nome: %s\n", aux->name);
      printf("Telefone: %s\n", aux->fone);
      aux = aux->next;
    }
  }
}

void listAllRents(Rent *list) {
  printf("\nLocações: ");
  Rent *aux = list;
  if (strcmp(aux[0].car.plate, "") == 0) {
    printf("\nNenhum aluguel cadastrado!");
  } else {
    while (strcmp(aux->client.licence, "") != 0) {
      printf("\nCliente:");
      printf("\nCarteira: %s\n",aux->client.licence);
      printf("Telefone: %s\n", aux->client.fone);
      printf("Nome: %s\n", aux->client.name);

      printf("\nCarro:");
      printf("\nAno: %d\n", aux->car.year);
      printf("KMs: %.2f\n", aux->car.km);
      printf("Valor: %.2f\n", aux->car.value);
      printf("Status: %s\n", aux->car.isFree == 0 ? "Livre" : "Alugado");
      printf("Modelo: %s\n", aux->car.model);
      printf("Placa: %s\n", aux->car.plate);
      printf("Marca: %s\n", aux->car.brand);

      printf("\nData de inicio: %d/%d/%d\n", aux->in.day, aux->in.month, aux->in.year);
      printf("Data de devolução: %d/%d/%d\n", aux->out.day, aux->out.month, aux->out.year);
      printf("Preco: %.2f\n", aux->value);
      aux = aux->next;
    }
  }
}

void returnCar(Car **car, Rent **list) {
  printf("\nDevolver o carro: ");
  char plate[8];
  printf("\nPlaca: ");
  scanf("%s", plate);
  Car finded = *findCar(*car, plate);
  Car *aux = *car;
  if (strcmp(finded.plate, plate) != 0) {
    printf("\nCarro não encontrado!");
  } else if (finded.isFree == 0) {
    printf("\nCarro não está alugado!");
  } else {
    float km;
    while (aux != NULL) {
      if (strcmp(aux->plate, plate) == 0) {
        aux->isFree = 1;
        printf("KMs percorrida: ");
        scanf("%f", &km);
        aux->km += km;
        break;
      }
      aux = aux->next;
    }
    Rent *aux2 = *list;
    while (aux2 != NULL) {
      if (strcmp(aux2->car.plate, plate) == 0) {
        aux2->value = (float) daysBetweenDates(aux2->in, aux2->out) * aux2->car.value;
        printf("Preco: %.2f\n", aux2->value);
        break;
      }
      aux2 = aux2->next;
    }
    printf("\nCarro devolvido!");
  }
}

void rentsOn(Rent *list) {
  Rent *aux = list;
  Date initialDate, finalDate;
  int finded = 0;

  printf("\nData inicial (DD MM AAAA): ");
  scanf("%d %d %d", &initialDate.day, &initialDate.month, &initialDate.year);
  printf("Data final (DD MM AAAA): ");
  scanf("%d %d %d", &finalDate.day, &finalDate.month, &finalDate.year);
  printf("\nAlugueis ativas em %d/%d/%d a %d/%d/%d:\n", initialDate.day, initialDate.month, initialDate.year, finalDate.day, finalDate.month, finalDate.year);

  while (aux != NULL) {
    if (isBetweenDates(aux->in, initialDate, finalDate) || isBetweenDates(aux->out, initialDate, finalDate)) {
      printf("\nCliente:");
      printf("\nCarteira: %s\n", aux->client.licence);
      printf("Telefone: %s\n", aux->client.fone);
      printf("Nome: %s\n", aux->client.name);

      printf("\nCarro:");
      printf("\nAno: %d\n", aux->car.year);
      printf("KMs: %.2f\n", aux->car.km);
      printf("Valor: %.2f\n", aux->car.value);
      printf("Status: %s\n", aux->car.isFree == 0 ? "Livre" : "Alugado");
      printf("Modelo: %s\n", aux->car.model);
      printf("Placa: %s\n", aux->car.plate);
      printf("Marca: %s\n", aux->car.brand);

      printf("\nData de in: %d/%d/%d\n", aux->in.day, aux->in.month, aux->in.year);
      printf("Data de devolução: %d/%d/%d\n", aux->out.day, aux->out.month, aux->out.year);
      printf("Preco: %.2f\n", aux->value);
      finded++;
    }
    aux = aux->next;
  }
  if (finded == 0) {
    printf("Nenhum registro encontrado!\n");
  }
}

void rentFromClient(Rent *list, Client *client) {
  printf("\nAlugueis por cliente: ");
  Client cliente;
  printf("\nCarteira: ");
  scanf("%s", cliente.licence);
  Rent *aux = list;
  if (findClient(client, cliente.licence) == NULL) {
    printf("\nCliente não encontrado!");
  } else {
    printf("Alugueis do cliente %s:\n", cliente.licence);
    while (aux != NULL) {
      if (strcmp(aux->client.licence, cliente.licence) == 0) {
        printf("\nCliente:");
        printf("\nCarteira: %s\n", aux->client.licence);
        printf("Telefone: %s\n", aux->client.fone);
        printf("Nome: %s\n", aux->client.name);

        printf("\nCarro:");
        printf("\nAno: %d\n", aux->car.year);
        printf("KMs: %.2f\n", aux->car.km);
        printf("Valor: %.2f\n", aux->car.value);
        printf("Status: %s\n", aux->car.isFree == 0 ? "Livre" : "Alugado");
        printf("Modelo: %s\n", aux->car.model);
        printf("Placa: %s\n", aux->car.plate);
        printf("Marca: %s\n", aux->car.brand);

        printf("\nData de in: %d/%d/%d\n", aux->in.day, aux->in.month, aux->in.year);
        printf("Data de devolução: %d/%d/%d\n", aux->out.day, aux->out.month, aux->out.year);
        printf("Preco: %.2f\n", aux->value);
      }
      aux = aux->next;
    }
  }
}

void amountFromMonth(Rent *list) {
  printf("\nGanhos:");
  int mounth, year;
  printf("Mês: ");
  scanf("%d", &mounth);
  printf("Ano: ");
  scanf("%d", &year);
  Rent *aux = list;
  float amount = 0;
  if (aux[0].value == 0.00) {
    printf("\nNenhum aluguel encontrado!");
  } else {
    while (aux != NULL) {
      if (aux->out.month == mounth && aux->out.year == year) {
        amount += aux->value;
      }
      aux = aux->next;
    }
  }
  printf("\nGanhos: %.2f\n", amount);
}

void carWithMoustKM(Car *list) {
  printf("\n3 carros com mais KMs:");
  Car *aux = list;
  Car *first = list;

  int length = 0;
  while (strcmp(aux->plate, "") != 0) {
    length++;
    aux = aux->next;
  }

  if (length >= 1 && strcmp(aux->plate, "") != 0) {
    while (strcmp(aux->plate, "") != 0) {
      if (aux->km > first->km) {
        first = aux;
      }
      aux = aux->next;
    }
    printf("\nAno: %d\n", first->year);
    printf("KMs: %.2f\n", first->km);
    printf("Valor: %.2f\n", first->value);
    printf("Status: %s\n", first->isFree == 0 ? "Livre" : "Alugado");
    printf("Modelo: %s\n", first->model);
    printf("Placa: %s\n", first->plate);
    printf("Marca: %s\n", first->brand);

    if (length >= 2) {
      aux = list;
      Car *second = list;
      while (strcmp(aux->plate, "") != 0) {
        if (aux->km > second->km && aux->km < first->km) {
          second = aux;
        }
        aux = aux->next;
      }
      printf("\nAno: %d\n", second->year);
      printf("KMs: %.2f\n", second->km);
      printf("Valor: %.2f\n", second->value);
      printf("Status: %s\n", second->isFree == 0 ? "Livre" : "Alugado");
      printf("Modelo: %s\n", second->model);
      printf("Placa: %s\n", second->plate);
      printf("Marca: %s\n", second->brand);

      if (length >= 3) {
        aux = list;
        Car *third = list;
        while (strcmp(aux->plate, "") != 0) {
          if (aux->km > third->km &&
              aux->km < second->km) {
            third = aux;
          }
          aux = aux->next;
        }
        printf("\nAno: %d\n", third->year);
        printf("KMs: %.2f\n", third->km);
        printf("Valor: %.2f\n", third->value);
        printf("Status: %s\n", third->isFree == 0 ? "Livre" : "Alugado");
        printf("Modelo: %s\n", third->model);
        printf("Placa: %s\n", third->plate);
        printf("Marca: %s\n", third->brand);

      } else {
        printf("\nTem apenas 2 carros cadastrados!");
      }
    } else {
      printf("\nTem apenas 1 carro cadastrado!");
    }
  } else {
    printf("\nNao tem carros cadastrados!");
  }
}

void carsIsFree(Car *list) {
  printf("\nCarros disponíveis: ");
  Car *aux = list;
  if (strcmp(aux[0].plate, "") == 0) {
    printf("Nenhum carro encontrado!");
  } else {
    while (strcmp(aux->plate, "") != 0) {
      if (aux->isFree == 1) {
        printf("\nAno: %d\n", aux->year);
        printf("KMs: %.2f\n", aux->km);
        printf("Valor: %.2f\n", aux->value);
        printf("Status: %s\n", aux->isFree == 0 ? "Livre" : "Alugado");
        printf("Modelo: %s\n", aux->model);
        printf("Placa: %s\n", aux->plate);
        printf("Marca: %s\n", aux->brand);
      }
      aux = aux->next;
    }
  }
}

void subMenu(Rent **list, Client **clients, Car **cars) {
  printf("\nEscolha uma opção:");
  int menu;
  printf("1 - Listar locações ativas em um período de tempo\n");
  printf("2 - Listar locações já realizadas por um cliente\n");
  printf("3 - Listar faturamento da locadora por mês\n");
  printf("4 - Listar plate dos 3 veículos mais rodados\n");
  printf("5 - Listar plate e model de todos os veículos disponíveis\n");
  printf("0 - Voltar\n");
  printf("Opção: ");
  scanf("%d", &menu);
  if (menu == 1) rentsOn(*list);
  else if (menu == 2) rentFromClient(*list, *clients);
  else if (menu == 3) amountFromMonth(*list);
  else if (menu == 4) carWithMoustKM(*cars);
  else if (menu == 5) carsIsFree(*cars);
}