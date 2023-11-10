// Bruna Caetano, Lucas Jost e Bruno Cantarelli - SI

#include "list.h"

int lengthStudents(List *list) {
    int length = 0;
    while (list != NULL) {
        length++;
        list = list->next;
    }
    return length;
}

void shellSort(List *list, int n) {
    int i, j, h;
    List aux;

    h = 1;
    while (h < n / 3) h = (3 * h) + 1;

    while (h > 0) {
        for (i = h; i < n; i++) {
            aux = list[i];
            j = i;

            while (j >= h && aux.id < list[j - h].id) {
                list[j] = list[j - h];
                j = j - h;
            }
            list[j] = aux;
        }
        h = (h - 1) / 3;
    }
}

bool existsStudent(List *list, int id) {
    while (list != NULL) {
        if (list->id == id)
            return true;
        list = list->next;
    }
    return false;
}

void printOneStudent(List *student) {
    printf("%s\n", student->name);
    printf("%d\t %d\n", student->id, student->year);
}

void printStudents(List *list) {
    if (list == NULL) {
        printf("Nao ha alunos cadastrados!\n");
        return;
    }
    List *aux = list;

    while (aux != NULL) {
        printf("%d\n", aux->id);
        printOneStudent(aux);
        aux = list->next;
    }
}

List *insertStudent(List *list) {
    int id, year;
    char name[50];

    printf("Digite a matrícula do aluno: ");
    scanf("%d", &id);

    if (existsStudent(list, id)) {
        printf("Matrícula já cadastrada!\n");
        return list;
    }

    fflush(stdin);
    printf("Digite o nome do aluno: ");
    getchar();
    scanf(" %[^\n]s", name);
    fflush(stdin);
    printf("Digite o ano de ingresso do aluno: ");
    scanf("%d", &year);

    List *new = (List *) malloc(sizeof(List));
    new->id = id;
    strcpy(new->name, name);
    new->year = year;
    new->next = list;
    list = new;
    printf("Aluno inserido com sucesso!\n");
    if (lengthStudents(list) > 1)
        shellSort(list, lengthStudents(list));

    return list;
}

List *deleteStudent(List *list) {
    puts("deleteStudent");
    List *aux = list;
    List *prev = NULL;
    int id;

    if (aux == NULL) {
        printf("Lista vazia!\n");
        return NULL;
    }

    printf("Digite a matricula do aluno: ");
    scanf("%d", &id);

    if (!existsStudent(aux, id)) {
        printf("Matrícula não cadastrada!\n");
        return aux;
    }

    while (aux != NULL && aux->id != id) {
        prev = aux;
        aux = aux->next;
    }

    prev->next = aux->next;

    printf("Aluno removido com sucesso!\n");
    return aux;
}

void freeList(List *list) {
    List *aux;
    while (list != NULL) {
        aux = list;
        list = list->next;
        free(aux);
    }
    free(list);
}

