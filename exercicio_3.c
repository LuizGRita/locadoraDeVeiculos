#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE_VEHICLE 200
#define SIZE_PLATE 10
#define SIZE_BRAND 20

typedef struct
{
   char plate[SIZE_PLATE];
   char brand[SIZE_BRAND];
   float day_price;
   char disp;
} Car;

int menu();
int insertVehicle(Car cars_list[], int totalVehicles);
void display_cars(Car car_list[], int total_vehicles);
void display_car(Car car_list[], int totalVehicles, int i);
int search_plate(Car car_list[], char plate[], int total_vehicles);
void getplate(char plate[]);
void allocateVehicle(Car cars_list[], int total_vehicles);
void deallocateVehicle(Car cars_list[], int total_vehicles);
int organize_list(Car car_list[], int total_vehicles, int index);
int remove_plate(Car car_list[], int total_vehicles);

int main()
{
   Car cars[SIZE_VEHICLE];
   int totalVehicles = 0;

   bool flag = true;
   while (flag)
   {
      int option = menu();
      switch (option)
      {
      case 0:
         printf("\nEncerrando Programa...\n");
         flag = false;
         break;
      case 1:
         totalVehicles = insertVehicle(cars, totalVehicles);
         break;
      case 2:
         display_cars(cars, totalVehicles);
         break;
      case 3:
      {
         printf("\n+++Buscar Veículo pela Placa+++\n");
         char car_plate[SIZE_PLATE];
         getplate(car_plate);
         int search = search_plate(cars, car_plate, totalVehicles);

         if (search != -1)
         {
            display_car(cars, totalVehicles, search);
         }
         else
         {
            printf("\n===VEÍCULO NÃO ENCONTRADO===\n");
         }
         break;
      }
      case 4:
         allocateVehicle(cars, totalVehicles);
         break;
      case 5:
         deallocateVehicle(cars, totalVehicles);
         break;
      case 6:
         totalVehicles = remove_plate(cars, totalVehicles);
         break;
      default:
         printf("\nOpção inválida");
         printf("\nTente Novamente\n\n");
         break;
      }
   }
   return 0;
}

int menu()
{
   printf("\n+++++++++++++++++");
   printf("\n===OPÇÕES===\n");
   printf("1 - Cadastrar Veículo\n");
   printf("2 - Exibir Veículos\n");
   printf("3 - Buscar Veículo por Placa\n");
   printf("4 - Alugar Veículo\n");
   printf("5 - Devolver Veículo\n");
   printf("6 - Remover Veículo\n");
   printf("0 - Sair do Programa\n");

   printf("\nDigite a opção desejada: ");
   int option;
   scanf("%d", &option);
   getchar();
   return option;
}

int insertVehicle(Car cars_list[], int totalVehicles)
{
   if (totalVehicles >= SIZE_VEHICLE)
   {
      printf("\nLimite de veiculos atingidos!!!\n");
      return totalVehicles;
   }

   Car new_car;

   printf("\n===CADASTRAR VEÍCULO===\n");

   printf("Digite a placa do carro [ex:ABC1D23]: ");
   fgets(new_car.plate, sizeof(new_car.plate), stdin);
   new_car.plate[strcspn(new_car.plate, "\n")] = '\0';

   printf("Digite a marca do carro: ");
   fgets(new_car.brand, sizeof(new_car.brand), stdin);
   new_car.brand[strcspn(new_car.brand, "\n")] = '\0';

   printf("Digite o preço da diária: ");
   scanf("%f", &new_car.day_price);
   getchar();

   printf("Digite a disponibilidade(S/N): ");
   scanf("%c", &new_car.disp);
   getchar();

   int i = totalVehicles - 1;
   while (i >= 0 && strcmp(cars_list[i].plate, new_car.plate) > 0)
   {
      cars_list[i + 1] = cars_list[i];
      i--;
   }

   cars_list[i + 1] = new_car;

   printf("\nVeículo adicionado com sucesso\n");

   return totalVehicles + 1;
}

void display_cars(Car car_list[], int total_vehicles)
{
   if (total_vehicles == 0)
   {
      printf("\nNenhum veículo cadastrado.\n");
      return;
   }
   printf("\n\n+++EXIBIR TODOS OS VEÍCULOS+++\n");
   for (int i = 0; i < total_vehicles; i++)
   {
      display_car(car_list, total_vehicles, i);
   }
}

void display_car(Car car_list[], int totalVehicles, int i)
{
   if (totalVehicles == 0)
   {
      printf("\n\n---NENHUM VEICULO ENCONTRADO---\n");
      return;
   }

   printf("\n---VEÍCULO %d---\n", i + 1);
   printf("Placa: %s\n", car_list[i].plate);
   printf("Marca: %s\n", car_list[i].brand);
   printf("Preço da Alocação: R$ %.2f\n", car_list[i].day_price);
   if (car_list[i].disp == 'S' || car_list[i].disp == 's')
   {
      printf("Status: +DISPONÍVEL+\n");
   }
   else
   {
      printf("Status: =INDISPONÍVEL=\n");
   }
}

int search_plate(Car car_list[], char plate[], int total_vehicles)
{
   int i = 0;

   while (i < total_vehicles)
   {
      if (strcmp(car_list[i].plate, plate) == 0)
      {
         return i;
      }
      i++;
   }

   return -1;
}

void getplate(char plate[])
{
   printf("Digite a placa do carro [ex:ABC1D23]: ");
   fgets(plate, SIZE_PLATE, stdin);
   plate[strcspn(plate, "\n")] = '\0';
}

void allocateVehicle(Car cars_list[], int total_vehicles)
{
   char plate[SIZE_PLATE];
   getplate(plate);
   int search = search_plate(cars_list, plate, total_vehicles);

   if (search == -1)
   {
      printf("\n===VEICULO NAO ENCONTRADO===\n");
   }
   else
   {
      if (cars_list[search].disp == 'S')
      {
         cars_list[search].disp = 'N';
         printf("\n+++VEICULO ALUGADO COM SUCESSO+++\n");
      }
      else
      {
         printf("\n===O VEICULO JÁ ESTA ALOCADO===\n");
      }
   }
}

void deallocateVehicle(Car cars_list[], int total_vehicles)
{
   char plate[SIZE_PLATE];
   getplate(plate);
   int search = search_plate(cars_list, plate, total_vehicles);

   if (search == -1)
   {
      printf("\n===VEICULO NAO ENCONTRADO===\n");
   }
   else
   {
      if (cars_list[search].disp == 'N')
      {
         cars_list[search].disp = 'S';
         printf("\n+++VEICULO DEVOLVIDO COM SUCESSO+++\n");
      }
      else
      {
         printf("\n===O VEICULO NÃO ESTÁ ALOCADO===\n");
      }
   }
}

int organize_list(Car car_list[], int total_vehicles, int index)
{
   for (int i = index; i < total_vehicles - 1; i++)
   {
      car_list[i] = car_list[i + 1];
   }

   return total_vehicles - 1;
}

int remove_plate(Car car_list[], int total_vehicles)
{
   char plate[SIZE_PLATE];
   getplate(plate);
   int search = search_plate(car_list, plate, total_vehicles);

   if (search == -1)
   {
      printf("\n---VEICULO NÃO ENCONTRADO---\n");
      return total_vehicles;
   }

   total_vehicles = organize_list(car_list, total_vehicles, search);
   printf("\n+++VEICULO REMOVIDO COM SUCESSO+++\n");
   return total_vehicles;
}