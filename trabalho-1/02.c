/* Bruna Caetano - SI
2. Considere um vetor de 5 retângulos. Faça um programa que leia a base e a altura de cada retângulo e a seguir
chame uma função que calcule e mostre na tela o perímetro e a área deste retângulo.
*/

#include "stdio.h"

typedef struct retangulo {
    float base;
    float altura;
    float perimetro;
    float area;
} Retangulo;

void calculaPeriArea(Retangulo ret){
    ret.perimetro = 2 * (ret.base + ret.altura);
    ret.area = ret.base * ret.altura;

    printf("Perímetro: %.2f\nÁrea: %.2f", ret.perimetro, ret.area);
}

int main() {
    Retangulo ret;

    printf("Digite a altura: ");
    scanf("%f", &ret.altura);
    printf("Digite a base: ");
    scanf("%f", &ret.base);

    calculaPeriArea(ret);

    return 0;
}
