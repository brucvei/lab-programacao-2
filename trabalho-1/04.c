/* Bruna Caetano - SI
4. Em uma pesquisa de campo, uma editora solicitou os seguintes dados para os entrevistados: sexo, idade e
quantidade de livros que leu no ano de 2022. Faça um programa que leia os dados de 50 usuários. Depois, calcule e
imprima:
a) A quantidade total de livros lidos pelos entrevistados menores de 10 anos.
b) A quantidade de mulheres que leu 5 livros ou mais.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct usuario {
    char sexo;
    int idade;
    int qtdade;
} Usuario;

void leVetor(int tamanho, Usuario *vet) {
    for (int i = 0; i < tamanho; ++i) {
        fflush(stdin);
        printf("Digite a idade do usuario %d: ", i + 1);
        scanf("%d", &vet[i].idade);
        printf("Digite a quantidade de livros lidos pelo usuario %d: ", i + 1);
        scanf("%d", &vet[i].qtdade);
        printf("Digite o sexo do usuario %d: ", i + 1);
        scanf("%c", &vet[i].sexo);
    }
}

int calculaQtidadeLivros(int tamanho, Usuario *vet) {
    int aux = 0;
    for (int i = 0; i < tamanho; ++i) {
        if (vet[i].idade < 10)
            aux += vet[i].qtdade;
    }
    return aux;
}

int calculaQtidadeMulheres(int tamanho, Usuario *vet) {
    int aux = 0;
    for (int i = 0; i < tamanho; ++i) {
        if (strcmp(&vet[i].sexo, (char *)'F') == 0 && vet[i].qtdade >= 5)
            aux++;
    }
    return aux;
}

int main() {
    Usuario vet[5];

    leVetor(5, vet);
    printf("A quantidade total de livros lidos pelos entrevistados menores de 10 anos eh: %d",
           calculaQtidadeLivros(5, vet));
    printf("A quantidade de mulheres que leu 5 livros ou mais eh: %d", calculaQtidadeMulheres(5, vet));

    return 0;
}