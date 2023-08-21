/* Bruna Caetano - SI */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/* Escreva um programa em C que implemente um jogo de caça-palavras. O programa deve
representar uma matriz de caracteres (alocada dinamicamente) de dimensão mxn e buscar a
ocorrência de palavras nesta matriz. As palavras podem estar na direção horizontal, vertical ou
diagonal, em qualquer sentido (direto ou reverso). */

//boolean searchWord(int heigth, int width, char **matriz, char *word){
//
//}

void printMatrix(char **matriz, int heigth, int width){
    for (int i = 0; i < heigth; ++i) {
        for (int j = 0; j < width; ++j) {
            puts(&matriz[i][j]);
        }
        puts("\n");
    }
}

void fillMatrix(char *string, char **matriz, int heigth, int width){
    for (int i = 0; i < heigth; ++i) {
        for (int j = 0; j < width; ++j) {
            if (strcmp(&string[i], " ") != -1) strcpy(&matriz[i][j], &string[i]);
        }
    }
}

void startGame(){
    int altura  = (int) malloc(sizeof (int)),
        largura = (int) malloc(sizeof(int));

    printf("Insira a altura da matriz: ");
    scanf("%d", &altura);
    printf("Insira a largura: ");
    scanf("%d", &largura);

    char *string = (char *) malloc(sizeof(char) * altura * largura);
    printf("Tamanho da string: %d\n", altura * largura);
    printf("Digite a string para preencher o tabuleiro: ");
//    scanf("%s", string);
    gets(string);
//    fgets(&string, altura * largura, stdin);
    puts(string);
//    fillMatrix(string, matriz, altura, largura);
//    free((void *) string);
//    printMatrix(matriz, altura, largura);

//    free(matriz);
}

int main(){
    puts("Bem vindo ao jogo de caça-palavras!");
    startGame();

    return 0;
}