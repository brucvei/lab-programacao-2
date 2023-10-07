#include <back.h>

int main(void) {
  puts("Bom dia!");
  Rent *rents;
  Client *cleints;
  Car *cars;
  cars = (Car *) malloc(sizeof(Car));
  cleints = (Client *) malloc(sizeof(Client));
  rents = (Rent *) malloc(sizeof(Rent));

  int option;
  do {
    puts("\nO que deseja fazer?");
    printf("1: Cadastrar carro\n");
    printf("2: Listar carros cadastrados\n");
    printf("3: Cadastrar cliente\n");
    printf("4: Listar clientes cadastrados\n");
    printf("5: Locar carro\n");
    printf("6: Devolver carro\n");
    printf("7: Listar locações cadastradas\n");
    printf("8: Relatórios\n");
    printf("0: Sair\n");
    printf("- ");
    scanf("%d", &option);

    if (option == 1) newCar(&cars);
    else if (option == 2) listAllCars(cars);
    else if (option == 3) newClient(&cleints);
    else if (option == 4) listAllClients(cleints);
    else if (option == 5) newRent(&rents, &cars, &cleints);
    else if (option == 6) returnCar(&cars, &rents);
    else if (option == 7) listAllRents(rents);
    else if (option == 8) subMenu(rents, cleints, cars);
  } while (option != 0);

  free(rents);
  free(cleints);
  free(cars);
  puts("Adeus!");

  return 0;
}