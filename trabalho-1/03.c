/* Bruna Caetano - SI
3. Desenvolva um programa que efetue a leitura de três valores para os lados de um triângulo, considerando
lados como: A, B e C. O programa deverá verificar se os lados fornecidos formam realmente um triângulo (cada lado
é menor que a soma dos outros dois lados). Se for esta condição verdadeira, deverá ser indicado qual tipo de
triângulo foi formado: isósceles (dois lados iguais e um diferente), escaleno (todos os lados diferentes) ou equilátero
(todos os lados são iguais).
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct triangulo {
    int ladoA;
    int ladoB;
    int ladoC;
    char ehTriangulo;
    char tipo[20];
} Triangulo;

void verificaTriangulo (Triangulo t) {
    if (t.ladoA < t.ladoB + t.ladoC && t.ladoB < t.ladoA + t.ladoC && t.ladoC < t.ladoA + t.ladoB)
        strcpy((char *) t.ehTriangulo, "S");
    else
        strcpy((char *) t.ehTriangulo, "N");
}

void verificaTipo(Triangulo t){
    if (t.ladoA == t.ladoB && t.ladoB == t.ladoC)
        strcpy(t.tipo, "Equilatero");
    else if (t.ladoA == t.ladoB || t.ladoA == t.ladoC || t.ladoB == t.ladoC)
        strcpy(t.tipo, "Isosceles");
    else
        strcpy(t.tipo, "Escaleno");

    printf("O triangulo eh %s", t.tipo);
}

int main() {
    Triangulo t;

    printf("Digite o lado A: ");
    scanf("%d", &t.ladoA);
    printf("Digite o lado B: ");
    scanf("%d", &t.ladoB);
    printf("Digite o lado C: ");
    scanf("%d", &t.ladoC);

    verificaTriangulo(t);
    if (t.ehTriangulo == "S") verificaTipo(t);
    else printf("Nao e um triangulo");

    return 0;
}
