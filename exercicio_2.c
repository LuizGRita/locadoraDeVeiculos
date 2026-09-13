#include <stdio.h>

#define TOTAL_SCHOOLS 4
#define TOTAL_CATEGORIES 3
#define TOTAL_GRADES 2

void readGrid(float grid[TOTAL_SCHOOLS][TOTAL_CATEGORIES][TOTAL_GRADES]);
float calcTotal(int escola, float grid[TOTAL_SCHOOLS][TOTAL_CATEGORIES][TOTAL_GRADES]);
float mediaCategoria(int escola, int categoria, float grid[TOTAL_SCHOOLS][TOTAL_CATEGORIES][TOTAL_GRADES]);
int campeao(float grid[TOTAL_SCHOOLS][TOTAL_CATEGORIES][TOTAL_GRADES]);

int main() {
   float grid[TOTAL_SCHOOLS][TOTAL_CATEGORIES][TOTAL_GRADES];

   readGrid(grid);

   int escola;
   printf("Digite a Escola que deseja saber o total de notas obtidas: ");
   scanf("%d", &escola);

   float sumGrades = calcTotal(escola, grid);
   printf("A soma de todas as notas da escola %d foi: %.2f", escola, sumGrades);

   int escola, categoria;
   printf("Digite a Escola e a categoria que deseja saber a média das notas obtidas: ");
   scanf("%d %d", &escola, &categoria);

   float media = mediaCategoria(escola, categoria, grid);
   printf("A media da escola %d na categoria %d foi: %.2f", escola, categoria, media);

   campeao = campeao(grid);
   printf("O campeao do desfile foi a escola %d", campeao);

   return 0;
}

void readGrid(float grid[TOTAL_SCHOOLS][TOTAL_CATEGORIES][TOTAL_GRADES]) {
   printf("=== LEITURA DE NOTAS ===\n\n");

   for (int school = 0; school < TOTAL_SCHOOLS; school++) {
      printf("--- Escola %d ---\n", school + 1);
        
      for (int category = 0; category < TOTAL_CATEGORIES; category++) {
         for (int grade = 0; grade < TOTAL_GRADES; grade++) {
            printf("  [Categoria %d] Digite a nota %d: ", category + 1, grade + 1);
            scanf("%f", &grid[school][category][grade]);
         }
      }
      printf("\n");
   }
}

float calcTotal(int escola, float grid[TOTAL_SCHOOLS][TOTAL_CATEGORIES][TOTAL_GRADES]){
   float somaEscola = 0;
   for(int categories = 0; categories < TOTAL_CATEGORIES; categories++){
      for(int grades = 0; grades < TOTAL_GRADES; grades++){
         float grade = grid[escola - 1][categories][grades];
         somaEscola += grade;
      }
   }
   return somaEscola;
}

float mediaCategoria(int escola, int categoria, float grid[TOTAL_SCHOOLS][TOTAL_CATEGORIES][TOTAL_GRADES]){
   float sum = 0;
   for(int grades = 0; grades < TOTAL_GRADES; grades++){
      sum += grid[escola][categoria][grades];
   }

   float media = sum / TOTAL_GRADES;
   
   return media;
}

int campeao(float grid[TOTAL_SCHOOLS][TOTAL_CATEGORIES][TOTAL_GRADES]){
   int campeao = 0;
   float maior = 0;

   for(int schools = 0; schools < TOTAL_SCHOOLS; schools++){
      float soma = 0;
      for(int categories = 0; categories < TOTAL_CATEGORIES; categories++){
         for(int grades = 0; grades < TOTAL_GRADES; grades++){
            soma += grid[schools][categories][grades];
         }
         float media = soma / (TOTAL_CATEGORIES + TOTAL_GRADES);

         if(media > maior){
            maior = media;
            campeao = schools;
         }
      }
   }

   return campeao;
}