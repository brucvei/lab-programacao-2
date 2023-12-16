#ifndef TRABALHO_03_VEICULOS_H
#define TRABALHO_03_VEICULOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "manipulacao-datas.h"

typedef struct veiculo {
    char placa[8];
    char marca[20];
    char modelo[20];
    int ano;
    float km;
    float valor;
    bool disponibilidade;
} Carro;

void printarVeiculo(Carro *veiculo);

Carro createVeiculo(char *placa);

#endif //TRABALHO_03_VEICULOS_H
