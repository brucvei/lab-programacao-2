/* Bruna Caetano - SI */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Escreva um programa em C que implemente um jogo de caça-palavras. O programa deve
representar uma matriz de caracteres (alocada dinamicamente) de dimensão mxn e buscar a
ocorrência de palavras nesta matriz. As palavras podem estar na direção horizontal, vertical ou
diagonal, em qualquer sentido (direto ou reverso). */

//boolean searchWord(int heigth, int width, char **matriz, char *word){
//
//}

void printMatrix(char **matriz, int heigth, int width) {
    printf("\nMatriz:\n");
    for (int i = 0; i < heigth; ++i) {
        for (int j = 0; j < width; ++j) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

// pega a string e coloca na matriz
void fillMatrix(char **matriz, int heigth, int width) {
    char aux;

    printf("Insira a frase: ");
    int i = -1;
    while (i < heigth) {
        int j = 0;
        while (j < width) {
            scanf("%c", &aux);
            if (aux == '\n') {
                break;
            } else if (aux != ' ') {
                matriz[i][j] = aux;
                j++;
            }
        }
        i++;
    }
}

void startGame() {
    int altura, largura;

    printf("Insira a altura da matriz: ");
    scanf("%d", &altura);
    printf("Insira a largura: ");
    scanf("%d", &largura);

    char **matriz = (char **) malloc(sizeof(char *) * altura);
    for (int i = 0; i < altura; ++i) {
        matriz[i] = (char *) malloc(sizeof(char) * largura);
    }

    if (matriz == NULL) {
        puts("Houve um erro inesperado. Tente novamente!");
        exit(1);
    }

    fillMatrix(matriz, altura, largura);
    printMatrix(matriz, altura, largura);

    for (int i = 0; i < altura; ++i) {
        free(matriz[i]);
    }
    free(matriz);
}

int main() {
    puts("\nBem vindo ao jogo de caça-palavras!\n");
    startGame();

    return 0;
}