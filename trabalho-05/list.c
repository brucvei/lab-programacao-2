// Bruna Caetano, Lucas Jost e Bruno Cantarelli - SI

#include "list.h"

List *createList() { return NULL; }

bool isEmpty(List *list) { return list == NULL; }

int lengthStudents(List *list) {
  int length = 0;
  while (!isEmpty(list)) {
    length++;
    list = list->next;
  }
  return length;
}

bool existsStudent(List *list, int id) {
  List *aux = list;
  while (!isEmpty(aux)) {
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
  if (isEmpty(list)) {
    printf("Não há alunos cadastrados!\n");
    return;
  }
  List *aux = list;

  while (!isEmpty(aux)) {
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

  List *new = (List *)malloc(sizeof(List));
  new->id = id;
  strcpy(new->name, name);
  new->year = year;

  List *prev = NULL;
  List *aux = list;
  while (!isEmpty(aux) && aux->id < id) {
    prev = aux;
    aux = aux->next;
  }

  if (prev == NULL) {
    new->next = list;
    list = new;
  } else {
    new->next = prev->next;
    prev->next = new;
  }

  printf("Aluno inserido com sucesso!\n");
  return list;
}

List *deleteStudent(List *list) {
  List *aux = list;
  List *prev = NULL;
  int id;

  if (isEmpty(aux)) {
    printf("Não há alunos cadastrados!\n");
    return NULL;
  }

  printf("Digite a matrícula do aluno: ");
  scanf("%d", &id);

  if (!existsStudent(aux, id)) {
    printf("Matrícula não encontrada!\n");
    return aux;
  }

  while (!isEmpty(aux) && aux->id != id) {
    prev = aux;
    aux = aux->next;
  }
  if (isEmpty(prev)) {
    list = aux->next;
  } else {
    prev->next = aux->next;
  }

  free(aux);
  printf("Aluno removido com sucesso!\n");
  return list;
}

void freeList(List *list) {
  List *aux;
  while (!isEmpty(list)) {
    aux = list;
    list = list->next;
    free(aux);
  }
  free(list);
}
