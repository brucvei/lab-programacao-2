/* Bruna Caetano - SI */
#include "main.h"

int main() {
    puts("\nBem vindo ao jogo de caça-palavras!\n");
    game();

    return 0;
}

void game() {
    JOGO partida;
    partida.quantity = 0;
    partida.giveUp = false;

    printf("Insira a altura da matriz: ");
    scanf("%d", &partida.heigth);
    printf("Insira a largura: ");
    scanf("%d", &partida.width);

    partida.matriz = (char **) malloc(sizeof(char *) * partida.heigth);
    for (int i = 0; i < partida.heigth; ++i) {
        partida.matriz[i] = (char *) malloc(sizeof(char) * partida.width);
    }

    if (partida.matriz == NULL) {
        puts("Houve um erro inesperado. Tente novamente!");
        exit(1);
    }

    fillMatrix(partida);
    printMatrix(partida);

    run(partida);

    for (int i = 0; i < partida.heigth; ++i) {
        free(partida.matriz[i]);
    }
    free(partida.matriz);
}

void run(JOGO partida) {
    puts("\nVamos começar!");
    int maior;
    if (partida.heigth > partida.width) {
        maior = partida.heigth;
    } else {
        maior = partida.width;
    }

    partida.finded = (PALAVRA *) malloc(sizeof(PALAVRA));
    do {
        fflush(stdin);
        printf("Digite seu chute: \n"
               "? - Regras\n"
               "! - Printar matriz\n"
               "# - Terminar o jogo\n"
               "% - Palavras encontradas\n"
               "- ");
        char *chute = (char *) malloc(sizeof(char) * maior);
        scanf("%s", chute);

        if (strcmp(chute, "?") == 0) rules();
        else if (strcmp(chute, "!") == 0) printMatrix(partida);
        else if (strcmp(chute, "#") == 0) partida.giveUp = true;
        else if (strcmp(chute, "%") == 0) printAllWords(partida);
        else if (strcmp(chute, "") != 0) process(&partida, chute);
        free(chute);
    } while (partida.giveUp == false);

    printMatrix(partida);
    printAllWords(partida);

    for (int i = 0; i < partida.quantity; ++i) {
        free(partida.finded[i].palavra);
    }
    free(partida.finded);

    puts("Até logo!");
}

void process(JOGO *partida, char *chute) {
    PONTO point = search(*partida, chute);
    if (point.x != -1) {
        partida->quantity += 1;
        partida->finded = (PALAVRA *) realloc(partida->finded, sizeof(PALAVRA) * partida->quantity);
        partida->finded[partida->quantity - 1].palavra = (char *) malloc(sizeof(char) * strlen(chute));
        strcpy(partida->finded[partida->quantity - 1].palavra, chute);
        partida->finded[partida->quantity - 1].point.x = point.x;
        partida->finded[partida->quantity - 1].point.y = point.y;
        partida->finded[partida->quantity - 1].point.w = point.w;
        partida->finded[partida->quantity - 1].point.z = point.z;
        puts("Palavra encontrada!");
    } else {
        puts("Palavra não encontrada!");
    }
}

PONTO search(JOGO partida, char *chute) {
    PONTO h = horizontal(partida, chute);
    if (h.x != -1) return h;

    PONTO v = vertical(partida, chute);
    if (v.x != -1) return v;

    PONTO point;
    point.x = -1;
    return point;
}

PONTO horizontal(JOGO partida, char *chute) {
    PONTO point;
    point.x = -1;

    int i = 0, size = strlen(chute);
    while (i < partida.heigth) {
        for (int j = 0; j < partida.width; ++j) {
            if (partida.matriz[i][j] == chute[0]) {
                int k = 0;
                while (k < size) {
                    if (partida.matriz[i][j + k] != chute[k]) break;
                    k++;
                }
                if (k == size) {
                    point.x = i;
                    point.y = j;
                    point.w = i;
                    point.z = j + size - 1;
                    return point;
                }
            }
        }
        i++;
    }
    return point;
}

PONTO vertical(JOGO partida, char *chute) {
   PONTO point;
    point.x = -1;

    int i = 0, size = strlen(chute);
    while (i < partida.heigth) {
        for (int j = 0; j < partida.width; ++j) {
            int k = 0;
            if (partida.matriz[i][j] == chute[0]) {
                while (k < size) {
                    if (partida.matriz[i + k][j] != chute[k]) break;
                    k++;
                }
                if (k == size) {
                    point.x = j;
                    point.y = i;
                    point.w = j;
                    point.z = i + size - 1;
                }
            }
        }
        i++;
    }
    return point;
}

void printAllWords(JOGO partida) {
    puts("----------- Palavras encontradas -----------");
    printf("Foram encontradas %d palavras!\n", partida.quantity);
    for (int i = 0; i < partida.quantity; ++i) {
        printf("\"%s\" -> (%d, %d), (%d, %d)\n", partida.finded[i].palavra, partida.finded[i].point.x,
               partida.finded[i].point.y, partida.finded[i].point.w, partida.finded[i].point.z);
    }
}

void rules() {
    puts("\nRegras:\n");
    puts("1. O jogo consiste em encontrar palavras em uma matriz de caracteres.");
    puts("2. As palavras podem estar na direção horizontal, vertical ou diagonal, em qualquer sentido (direto ou reverso).");
    puts("3. As palavras podem estar em qualquer posição da matriz.");
    puts("4. As palavras podem se sobrepor.");
    puts("5. As palavras podem ser formadas por letras maiúsculas ou minúsculas.");
    puts("6. O jogo termina quando o usuário digitar #.\n");
}

void fillMatrix(JOGO partida) {
    char aux;
    int count = 0;

    printf("Insira a frase: ");
    int i = -1;
    while (i < partida.heigth) {
        int j = 0;
        while (j < partida.width) {
            scanf("%c", &aux);
            if (aux == '\n') {
                break;
            } else if (aux != ' ') {
                partida.matriz[i][j] = tolower(aux);
                j++;
                count++;
                if (count == partida.width * partida.heigth) {
                    break;
                }
            }
        }
        i++;
    }
}

void printMatrix(JOGO partida) {
    printf("\nMatriz:\n");
    for (int i = 0; i < partida.heigth; ++i) {
        for (int j = 0; j < partida.width; ++j) {
            printf("%c ", partida.matriz[i][j]);
        }
        printf("\n");
    }
}