// Bruna Caetano, Lucas Jost e Bruno Cantarelli - SI

#include "list.h"

List *createList() {
    return NULL;
}

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

            while (j >= h && aux.student->id < list[j - h].student->id) {
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
        if (list->student->id == id)
            return true;
        list = list->next;
    }
    return false;
}

void printOneStudent(Student student) {
    printf("Matricula: %d\n", student.id);
    printf("Nome: %s\n", student.name);
    printf("Ano de ingresso: %d\n", student.year);
}

void printStudents(List *list) {
    puts("Listando todos os alunos...");
    Student *aux = list->student;
    if (aux == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    printf("Lista de alunos:\n");
    while (aux != NULL) {
        printOneStudent(*aux);
        aux = list->next->student;
    }

}

void insertStudent(List **list) {
    puts("Inserindo aluno...");
    int id, year;
    char name[50];

    printf("Digite a matrícula do aluno: ");
    scanf("%d", &id);
    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]s", name);
    printf("Digite o ano de ingresso do aluno: ");
    scanf("%d", &year);

    if (existsStudent(*list, id)) {
        printf("Matrícula já cadastrada!\n");
        return;
    }
    List *new = (List *) malloc(sizeof(List));
    Student *student = (Student *) malloc(sizeof(Student));
    student->id = id;
    strcpy(student->name, name);
    student->year = year;
    new->student = student;
    new->next = *list;
    *list = new;
    printf("Aluno inserido com sucesso!\n");
    shellSort(*list, lengthStudents(*list));
}

void deleteStudent(List **list) {
    puts("Removendo aluno...");
    List *aux = *list;
    List *prev = NULL;
    int id;

    printf("Digite a matricula do aluno: ");
    scanf("%d", &id);

    if (aux == NULL) {
        printf("Lista vazia!\n");
        return;
    } else if (!existsStudent(*list, id)) {
        printf("Matrícula não cadastrada!\n");
        return;
    }

    while (aux != NULL && aux->student->id != id) {
        prev = aux;
        aux = aux->next;
    }

    prev->next = aux->next;

    printf("Aluno removido com sucesso!\n");
    free(aux);
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

