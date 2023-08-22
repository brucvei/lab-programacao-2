/* Bruna Caetano - SI
5. Faça um programa que leia a quantidade de aulas ministradas em uma disciplina. Para esta disciplina
informada, considere 5 alunos. Para cada aluno, leia as duas notas obtidas pelo aluno na disciplina e o número de
aulas assistidas. A seguir, calcule e mostre a média final deste aluno e verifique se ele foi aprovado (status = ‘A’) ou
reprovado (status = ‘B’). Condição para ser aprovado: média >= 6 e mínimo de 75% de frequência.*/


#include "stdio.h"
#include "stdlib.h"

typedef struct aluno {
    float nota1;
    float nota2;
    int aulasAssistidas;
    float media;
    char status;
} Aluno;

typedef struct disciplina {
    Aluno vet[5];
    int aulasMinistradas;
} Disciplina;


void leVetor(int tamanho, Aluno *vet) {
    for (int i = 0; i < tamanho; ++i) {
        printf("Digite a nota 1 do aluno %d: ", i + 1);
        scanf("%f", &vet[i].nota1);
        printf("Digite a nota 2 do aluno %d: ", i + 1);
        scanf("%f", &vet[i].nota2);
        printf("Digite a quantidade de aulas assistidas pelo aluno %d: ", i + 1);
        scanf("%d", &vet[i].aulasAssistidas);
    }
}

void calculaMedia(int tamanho, Aluno *vet) {
    for (int i = 0; i < tamanho; ++i) {
        vet[i].media = (vet[i].nota1 + vet[i].nota2) / 2;
    }
}

Disciplina verificaStatus(int tamanho, Disciplina d) {
    for (int i = 0; i < tamanho; ++i) {
        if (d.vet[i].media >= 6.0 && d.vet[i].aulasAssistidas >= (0.75 * d.aulasMinistradas))
            d.vet[i].status = 'A';
        else
            d.vet[i].status = 'B';
    }

    return d;
}

int main() {
    Disciplina d;
    printf("Digite a quantidade de aulas ministradas: ");
    scanf("%d", &d.aulasMinistradas);

    leVetor(5, d.vet);
    calculaMedia(5, d.vet);
    d = verificaStatus(5, d);

    for (int i = 0; i < 5; ++i) {
        printf("O aluno %d obteve media %.2f e status %c\n", i + 1, d.vet[i].media, d.vet[i].status);
    }

    return 0;
}