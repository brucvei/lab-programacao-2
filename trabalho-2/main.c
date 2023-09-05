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

    partida.finded = (PALAVRA *) malloc(sizeof(PALAVRA) * partida.quantity);
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
        else if (strcmp(chute, "") != 0) process(partida, chute);
        free(chute);
    } while (partida.giveUp == false);

    printMatrix(partida);
    printf("\nForam encontradas %d palavras!\n", partida.quantity);
    puts("As palavras encontradas foram: ");
    printAllWords(partida);

    for (int i = 0; i < partida.quantity; ++i) {
        free(partida.finded[i].palavra);
    }
    free(partida.finded);

    puts("Até logo!");
}

void process(JOGO partida, char *chute) {
    PONTO point = search(partida, chute);
    printf("point[x] -> %d\n", point.x);
    if (point.x != -1) {
        partida.quantity++;
        partida.finded = (PALAVRA *) malloc(sizeof(PALAVRA) * partida.quantity);
        partida.finded[partida.quantity - 1].palavra = (char *) malloc(sizeof(char) * strlen(chute));
        strcpy(partida.finded[partida.quantity - 1].palavra, chute);
        partida.finded[partida.quantity - 1].point = point;
        puts("Palavra encontrada!");
    } else {
        puts("Palavra não encontrada!");
    }
}

PONTO search(JOGO partida, char *chute) {
    PONTO point;
    point.x = -1;

    point = horizontal(partida, chute);
    if (point.x != -1) {
        puts("-----------Horizontal");
        return point;
    }

    point = vertical(partida, chute);
    printf("point[x] -> %d\n", point.x);
    printf("point[y] -> %d\n", point.y);
    printf("point[w] -> %d\n", point.w);
    printf("point[z] -> %d\n", point.z);
    if ((point.x != -1)) {
        puts("-----------Vertical");
        return point;
    }
//
//    point = diagonal(partida, chute);
//    if ((point.x != -1)) {
//        puts("-----------Diagonal");
//        return point;
//    }
    return point;
}

PONTO horizontal(JOGO partida, char *chute) {
    PONTO point;
    point.x = -1;

    char *aux = (char *) malloc(sizeof(char) * strlen(chute));
    strcpy(aux, chute);
    invert(aux);
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
                k = 0;
                while (k < size) {
                    if (partida.matriz[i][j + k] != aux[k]) break;
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
    puts("AAAAAAAAAAAAAAAAAA");
    char *aux = (char *) malloc(sizeof(char) * strlen(chute));
    strcpy(aux, chute);
    invert(aux);
    int i = 0, size = strlen(chute);
    while (i < partida.width) {
        for (int j = 0; j < partida.heigth; ++j) {
            printf("%c ", partida.matriz[i][j]);
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
                k = 0;
                while (k < size) {
                    if (partida.matriz[i][j + k] != aux[k]) break;
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
//        char *aux2 = (char *) malloc(sizeof(char) * partida.heigth);
//        for (int j = 0; j < partida.heigth; ++j) {
//            aux2[j] = partida.matriz[j][i];
//        }
//        if (strstr(aux2, chute) != NULL) {
//            return true;
//        }
//        if (strstr(aux2, aux) != NULL) {
//            return true;
//        }
        i++;
    }
    return point;
}

PONTO diagonal(JOGO partida, char *chute) {
    puts("-----------Diagonal");
//    char *aux = (char *) malloc(sizeof(char) * strlen(chute));
//    strcpy(aux, invert(chute));
//    int i = 0;
//    while (i < partida.heigth) {
//        int j = 0;
//        while (j < partida.width) {
//            if (partida.matriz[i][j] == chute[0]) {
//                int k = 0;
//                while (k < strlen(chute)) {
//                    if (partida.matriz[i + k][j + k] != chute[k]) {
//                        break;
//                    }
//                    k++;
//                }
//                if (k == strlen(chute)) {
//                    return true;
//                }
//                k = 0;
//                while (k < strlen(chute)) {
//                    if (partida.matriz[i + k][j + k] != aux[k]) {
//                        break;
//                    }
//                    k++;
//                }
//                if (k == strlen(chute)) {
//                    return true;
//                }
//            }
//            j++;
//        }
//        i++;
//    }
}

char *invert(char *s) {
    int length = strlen(s);
    int c, i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }

    return s;
}

void printAllWords(JOGO partida) {
    puts("----------- Palavras encontradas -----------");
    for (int i = 0; i < partida.quantity; ++i) {
        printf("-> %s nos pontos (%d, %d), (%d, %d)\n", partida.finded[i].palavra, partida.finded[i].point.x,
               partida.finded[i].point.y, partida.finded[i].point.w, partida.finded[i].point.z);
    }
}

void rules() {
    puts("Regras:\n");
    puts("1. O jogo consiste em encontrar palavras em uma matriz de caracteres.");
    puts("2. As palavras podem estar na direção horizontal, vertical ou diagonal, em qualquer sentido (direto ou reverso).");
    puts("3. As palavras podem estar em qualquer posição da matriz.");
    puts("4. As palavras podem se sobrepor.");
    puts("5. As palavras podem ser formadas por letras maiúsculas ou minúsculas.");
    puts("6. O jogo termina quando o usuário digitar #.");
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