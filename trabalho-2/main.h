/* Escreva um programa em C que implemente um jogo de caça-palavras. O programa deve
representar uma matriz de caracteres (alocada dinamicamente) de dimensão mxn e buscar a
ocorrência de palavras nesta matriz. As palavras podem estar na direção horizontal, vertical ou
diagonal, em qualquer sentido (direto ou reverso). */

#ifndef TRABALHO_2_MAIN_H
#define TRABALHO_2_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct ponto {
    int x, y, w, z;
} PONTO;

typedef struct palavra {
    char *palavra;
    PONTO point;
} PALAVRA;

typedef struct jogo {
    bool giveUp;
    int quantity;
    int heigth;
    int width;
    char **matriz;
    PALAVRA *finded;
} JOGO;

// Mostra a matriz na tela
void printMatrix(JOGO partida);

// Preenche a matriz com a frase que o usuario digita
void fillMatrix(JOGO partida);

// Mostra as regras e informações do jogo
void rules();

// Mostra todas as palavras encontradas
void printAllWords(JOGO partida);

// Inverte uma string
char *invert(char *s);

// Verifica se a palavra esta na diagonal da matriz
PONTO diagonal(JOGO partida, char *chute);

// Verifica se a palavra esta na vertical da matriz
PONTO vertical(JOGO partida, char *chute);

// Verifica se a palavra esta na horizontal da matriz
PONTO horizontal(JOGO partida, char *chute);

// Busca a palavra na matriz
PONTO search(JOGO partida, char *chute);

// Processa um chute do usuario
void process(JOGO partida, char *chute);

// Roda o jogo
void run(JOGO partida);

// Inicializa o jogo e as variáveis
void game();

#endif //TRABALHO_2_MAIN_H
