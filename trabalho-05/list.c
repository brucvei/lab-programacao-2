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

List *sort(List *list, int n) {
    puts("sort");
    List aux;
    // order list by id
    for (int i = 0; i < n - 1; i++) {
        List *current = &aux;
        List *next = list;
        List *prev = NULL;
        while (next != NULL) {
            if (next->next != NULL && next->id > next->next->id) {
                // swap
                List *temp = next->next;
                next->next = next->next->next;
                temp->next = next;
                if (prev != NULL) prev->next = temp;
                prev = temp;
                if (current->next == next) current = current->next;
            } else {
                prev = next;
                next = next->next;
            }
        }
        list = aux.next;
    }

    return list;
}

bool existsStudent(List *list, int id) {
    List *aux = list;
    while (aux != NULL) {
        if (aux->id == id)
            return true;
        aux = aux->next;
    }
    return false;
}

void printOneStudent(List *student) {
    printf("\n%s\n", student->name);
    printf("Matrícula: %d\n", student->id);
    printf("Ano de ingresso: %d\n", student->year);
}

void printStudents(List *list) {
    if (list == NULL) {
        printf("Não há alunos cadastrados!\n");
        return;
    }
    List *aux = list;

    while (aux != NULL) {
        printOneStudent(aux);
        aux = aux->next;
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

    free(new);
    printf("Aluno inserido com sucesso!\n");

    if (lengthStudents(list) > 1)
        list = sort(list, lengthStudents(list));

    return list;
}

List *deleteStudent(List *list) {
    puts("deleteStudent");
    List *aux = list;
    List *prev = NULL;
    int id;

    if (aux == NULL) {
        printf("Não há alunos cadastrados!\n");
        return NULL;
    }

    printf("Digite a matrícula do aluno: ");
    scanf("%d", &id);

    if (!existsStudent(aux, id)) {
        printf("Matrícula não encontrada!\n");
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

