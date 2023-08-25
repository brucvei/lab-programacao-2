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

//void printMatrix(char **matriz, int heigth, int width) {
//    for (int i = 0; i < width; ++i) {
//        for (int j = 0; j < heigth; ++j) {
//            puts(&matriz[i][j]);
//        }
//        puts("\n");
//    }
//}

void fillMatrix(char **matriz, int heigth, int width) {
    char aux;
    printf("Insira a frase: ");

    int i = 0;
    while (((aux = getchar()) != '\n' && aux != EOF) || i < heigth){
        int j = 0;
        while (j < width) {
            if (aux != ' ') {
                matriz[i][j] = aux;
                j++;
            }
        }
        i++;
    }

//    puts(*matriz);
}

void startGame() {
    int *altura = (int *) malloc(sizeof(int)),
            *largura = (int *) malloc(sizeof(int));
    char **matriz = (char **) malloc(sizeof(char *) * *largura);

    if (altura == NULL || largura == NULL || matriz == NULL) {
        puts("Houve um erro inesperado. Tente novamente!");
        exit(1);
    }

    printf("Insira a altura da matriz: ");
    scanf("%d", altura);
    printf("Insira a largura: ");
    scanf("%d", largura);

    puts("Insira as palavras que deseja encontrar: ");
    fillMatrix(matriz, *altura, *largura);
    puts("\nAAAAAAAAAAAAa");
//    free((void *) string);
//    printMatrix(matriz, altura, largura);

    free(altura);
    free(largura);
    free(matriz);
}

int main() {
    puts("\nBem vindo ao jogo de caça-palavras!\n");
    startGame();

    return 0;
}