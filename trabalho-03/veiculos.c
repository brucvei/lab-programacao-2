#include "veiculos.h"

void printarVeiculo(Carro *veiculo){
    printf("\nPlaca: %s\n", veiculo->placa);
    printf("Marca: %s\n", veiculo->marca);
    printf("Modelo: %s\n", veiculo->modelo);
    printf("Ano: %d\n", veiculo->ano);
    printf("Kilometragem: %.2f\n", veiculo->km);
    printf("Valor da diaria: %.2f\n", veiculo->valor);
    printf("Disponibilidade: %s\n", veiculo->disponibilidade ? "Disponível" : "Indisponível");
}

Carro createVeiculo(char *placa){
    Carro veiculo;
    strcpy(veiculo.placa, placa);
    printf("Marca: ");
    scanf("%s", veiculo.marca);
    printf("Modelo: ");
    scanf("%s", veiculo.modelo);
    printf("Ano: ");
    scanf("%d", &veiculo.ano);
    printf("Quilometragem percorrida: ");
    scanf("%f", &veiculo.km);
    printf("Valor da diária: ");
    scanf("%f", &veiculo.valor);
    veiculo.disponibilidade = true;
    return veiculo;
}