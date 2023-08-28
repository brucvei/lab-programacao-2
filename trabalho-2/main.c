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
    puts("-----------run");
    puts("\nVamos começar!\n");
    int maior;
    if (partida.heigth > partida.width) {
        maior = partida.heigth;
    } else {
        maior = partida.width;
    }

    char *chute = (char *) malloc(sizeof(char) * maior);
    do {
        printf("\nDigite seu chute: \n"
               "? - regras\n"
               "! - printar matriz\n"
               "# - Terminar o jogo\n"
               "- ");
        scanf("%s", chute);

        if      (strcmp(chute, "?") == 0) rules();
        else if (strcmp(chute, "!") == 0) printMatrix(partida);
        else if (strcmp(chute, "#") == 0) partida.giveUp = true;
        else if (isspace(chute) == 0) process(partida, chute);
    } while (partida.giveUp == false);

    printMatrix(partida);
    printf("\nForam encontradas %d palavras!\n", partida.quantity);
    puts("As palavras encontradas foram: ");
    printAllWords(partida);

    free(chute);
    for (int i = 0; i < partida.quantity; ++i) {
        free(partida.finded[i]);
    }
    free(partida.finded);

    puts("Até logo!");
}

void process(JOGO partida, char *chute) {
    puts("-----------Process");
//    if (search(partida, chute)) {
//        partida.quantity++;
//        partida.finded = (char **) realloc(partida.finded, sizeof(char *) * partida.quantity);
//        partida.finded[partida.quantity - 1] = (char *) malloc(sizeof(char) * strlen(chute));
//        strcpy(partida.finded[partida.quantity - 1], chute);
//        puts("Palavra encontrada!");
//    } else {
//        puts("Palavra não encontrada!");
//    }
}

bool search(JOGO partida, char *chute) {
    puts("-----------Search");
    if (strcmp(chute, " ") == 0) {
        return false;
    }
    if (horizontal(partida, chute) || vertical(partida, chute) || diagonal(partida, chute)) {
        return true;
    }

    return false;
}

bool horizontal(JOGO partida, char *chute) {
    puts("-----------Horizontal");
//    char *aux = (char *) malloc(sizeof(char) * strlen(chute));
//    strcpy(aux, invert(chute));
//    int i = 0;
//    while (i < partida.heigth) {
//        if (strstr(partida.matriz[i], chute) != NULL) {
//            return true;
//        }
//        if (strstr(partida.matriz[i], aux) != NULL) {
//            return true;
//        }
//        i++;
//    }

    return false;
}

bool vertical(JOGO partida, char *chute) {
    puts("-----------Vertical");
//    char *aux = (char *) malloc(sizeof(char) * strlen(chute));
//    strcpy(aux, invert(chute));
//    int i = 0;
//    while (i < partida.width) {
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
//        i++;
//    }

    return false;
}

bool diagonal(JOGO partida, char *chute) {
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
    return false;
}

//char *invert(char *s) {
//    puts("-----------Invert");
//    int length = strlen(s);
//    int c, i, j;
//
//    for (i = 0, j = length - 1; i < j; i++, j--) {
//        c = s[i];
//        s[i] = s[j];
//        s[j] = c;
//    }
//
//    return s;
//}

void printAllWords(JOGO partida) {
    puts("-----------PrintAllWords");
    for (int i = 0; i < partida.quantity; ++i) {
        printf("%s\n", partida.finded[i]);
    }
}

void rules() {
    puts("-----------rules");
//    puts("Regras:\n");
//    puts("1. O jogo consiste em encontrar palavras em uma matriz de caracteres.");
//    puts("2. As palavras podem estar na direção horizontal, vertical ou diagonal, em qualquer sentido (direto ou reverso).");
//    puts("3. As palavras podem estar em qualquer posição da matriz.");
//    puts("4. As palavras podem se sobrepor.");
//    puts("5. As palavras podem ser formadas por letras maiúsculas ou minúsculas.");
//    puts("6. O jogo termina quando o usuário digitar #.");
}

void fillMatrix(JOGO partida) {
    puts("-----------fillMatrix");
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
                printf("%d", count);
                if (count == partida.width * partida.heigth) {
                    break;
                }
            }
        }
        i++;
    }
}

void printMatrix(JOGO partida) {
    puts("-----------printMatrix");
    printf("\nMatriz:\n");
    for (int i = 0; i < partida.heigth; ++i) {
        for (int j = 0; j < partida.width; ++j) {
            printf("%c ", partida.matriz[i][j]);
        }
        printf("\n");
    }
}