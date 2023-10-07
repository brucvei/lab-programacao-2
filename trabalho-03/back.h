#ifndef TRABALHO_03_BACK_H
#define TRABALHO_03_BACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "manipulacao-datas.h"

typedef struct client {
    char licence[12];
    char fone[12];
    char name[50];
    struct client *next;
} Client;

typedef struct car {
    int year;
    float km;
    float value;
    int isFree;
    char model[20];
    char plate[8];
    char brand[10];
    struct car *next;
} Car;

typedef struct rent {
    Car car;
    Client client;
    float value;
    Date in;
    Date out;
    struct rent *next;
} Rent;

// encontra clientes e carros
Client *findClient(Client *list, char licensce[]);
Car *findCar(Car *list, char plate[]);

// adiciona novos elementos
void newCar(Car **reg);
void newClient(Client **reg);
void newRent(Rent **list, Car **car, Client **cliet);

// lista todos os elementos
void listAllCars(Car *list);
void listAllClients(Client *list);
void listAllRents(Rent *list);

void returnCar(Car **car, Rent **list);

void rentsOn(Rent *list);
void rentFromClient(Rent *list, Client *client);
void amountFromMonth(Rent *list);
void carWithMoustKM(Car *list);
void carsIsFree(Car *list);

void subMenu(Rent **list, Client **clients, Car **cars);

#endif //TRABALHO_03_BACK_H