/* Bruna Caetano - SI
1. Implemente uma função que calcule e mostre a área da superfície e o volume de uma esfera de raio r. O raio
da esfera é informado pelo usuário.
 Esta função deve obedecer ao protótipo:
void calc_esfera (float r, float *area, float *volume)
*/

#include <stdio.h>

void calc_esfera(float r, float *area, float *volume) {
    *area = 4 * 3.14 * (r * r);
    *volume = (4 * 3.14 * (r * r * r)) / 3;
}

int main() {
    float raio, area, volume;

    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);

    calc_esfera(raio, &area, &volume);
    printf("Área: %.2f\nVolume: %.2f", area, volume);

    return 0;
}
