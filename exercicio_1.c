#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TMN 200

void lerFrase(char *frase, int tamanho);
int calcVogais(char *frase);
int calcPalavras(char *frase);
void limparEspacos(char *frase, char *fraseLimpa);
int eh_palindromo(char *frase);

int main()
{
   char frase[TMN];

   printf("Digite a Frase: ");
   lerFrase(frase, sizeof(frase));

   int quantVogais = calcVogais(frase);
   printf("A quantidade de vogais da frase é: %d", quantVogais);

   int quantPalavras = calcPalavras(frase);
   printf("\nA quantidade de palavras da frase é: %d\n", quantPalavras);

   char fraseLimpa[TMN];
   limparEspacos(frase, fraseLimpa);

   int palindromo = eh_palindromo(fraseLimpa);
   if (palindromo == 1)
   {
      printf("Sua frase é um palindromo.");
   }
   else
   {
      printf("Sua frase não é um palindromo.");
   }

   return 0;
}

void lerFrase(char *frase, int tamanho)
{
   if (fgets(frase, tamanho, stdin) != NULL)
   {
      frase[strcspn(frase, "\n")] = '\0';
   }
}

int calcVogais(char *frase)
{
   int quant = 0;

   char vogais[] = "aeiouAEIOU";

   for (int i = 0; frase[i] != '\0'; i++)
   {
      for (int j = 0; vogais[j] != '\0'; j++)
      {
         if (frase[i] == vogais[j])
         {
            quant++;
            break;
         }
      }
   }

   return quant;
}

int calcPalavras(char *frase)
{
   if (frase[0] == '\0')
   {
      int quant = 0;
      return quant;
   }

   int quant = 1;
   for (int i = 0; frase[i] != '\0'; i++)
   {
      if (frase[i] == ' ' && frase[i + 1] != ' ' && frase[i + 1] != '\0')
      {
         quant++;
      }
   }

   return quant;
}

void limparEspacos(char *frase, char *fraseLimpa)
{
   int j = 0;
   for (int i = 0; frase[i] != '\0'; i++)
   {
      if (frase[i] != ' ')
      {
         fraseLimpa[j] = tolower(frase[i]);
         j++;
      }
   }
   fraseLimpa[j] = '\0';
}

int eh_palindromo(char *frase)
{
   int i = 0;
   int j = strlen(frase) - 1;

   while (i <= j)
   {
      if (frase[i] != frase[j])
         return 0;
      i++;
      j--;
   }
   return 1;
}
