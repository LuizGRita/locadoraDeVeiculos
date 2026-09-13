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
void display_car(Car car_list[], int i);
int search_plate(Car car_list[], char plate[], int total_vehicles);

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
         printf("\nEncerrando Programa...");
         flag = false;
         break;
      case 1:
         totalVehicles = insertVehicle(cars, totalVehicles);
         break;
      case 2:
         display_cars(cars, totalVehicles);
         break;
      case 3:
         printf("+++Buscar Veículo pela Placa+++");
         char car = getplate();
         int search = search_plate(cars, car, totalVehicles);

         if (search != -1)
         {
            display_car(cars, search);
         }
         else
         {
            printf("===VEÍCULO NÃO ENCONTRADO===");
         }
         break;
      case 4:

         break;
      case 5:
         break;
      case 6:
         break;
      case 7:
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
   printf("\n1 - Cadastrar Veículo\n");
   printf("2 - Exibir Veículos\n");
   printf("3 - Buscar Veículo por Placa\n");
   printf("4 - Alugar Veículo\n");
   printf("5 - Devolver Veículo\n");
   printf("6 - Remover Veículo\n");
   printf("0 - Sair do Programa\n");

   printf("\nDigite a opção desejada: ");
   int option;
   scanf("%d", &option);
   return option;
}

int insertVehicle(Car cars_list[], int totalVehicles)
{
   if (totalVehicles >= SIZE_VEHICLE)
   {
      printf("\nLimite de veiculos atingidos!!!\n");
      return totalVehicles;
   }

   Car new;

   printf("\n===CADASTRAR VEÍCULO===\n");

   printf("Digite a placa do carro [ex:ABC1D23]: ");
   fgets(new.plate, sizeof(new.plate), stdin);
   new.plate[strcspn(new.plate, "\n")] = '\0';

   printf("Digite a marca do carro: ");
   fgets(new.brand, sizeof(new.brand), stdin);
   new.brand[strcspn(new.brand, "\n")] = '\0';

   printf("Digite o preço da diária: ");
   scanf("%f", &new.day_price);
   getchar();

   printf("Digite a disponibilidade(S/N): ");
   scanf("%c", &new.disp);
   getchar();

   int i = totalVehicles - 1;
   while (i >= 0 && strcmp(cars_list[i].plate, new.plate) > 0)
   {
      cars_list[i + 1] = cars_list[i];
      i--;
   }

   cars_list[i + 1] = new;

   printf("\nVeículo adicionado com sucesso\n");

   return totalVehicles + 1;
}

void display_cars(Car car_list[], int total_vehicles)
{
   printf("\n\n+++EXIBIR TODOS OS VEÍCULOS+++\n");
   for (int i = 0; i < total_vehicles; i++)
   {
      display_car(car_list, i);
   }
}

void display_car(Car car_list[], int i)
{
   printf("\n---VEÍCULO %d---\n", i + 1);
   printf("\nPlaca: %s", car_list[i].plate);
   printf("\nMarca: %s", car_list[i].brand);
   printf("\nPreço da Alocação: %.2f", car_list[i].day_price);
   if (car_list[i].disp == 'S')
   {
      printf("\n+DISPONÍVEL+\n");
   }
   else
   {
      printf("\n=INDISPONÍVEL=\n");
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

char getplate()
{
   printf("\nDigite a placa do carro [ex:ABC1D23]: ");
   char car[SIZE_PLATE];
   fgets(car, sizeof(car), stdin);
   car[strcspn(car, "\n")] = "\0";

   return car;
}