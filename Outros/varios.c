#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  int total_numeros, num;
  int pares = 0, impares = 0, soma = 0;
  int maior = INT_MIN;
  float media;

  printf("Quantos números deseja inserir? ");
  scanf("%d", &total_numeros);

  if (total_numeros <= 0) {
    printf("Ordem inválida\n");
    return 1;
  }
  for (int i = 1; i <= total_numeros; i++) {
    printf("Numero %d:", i);
    scanf("%d", &num);
    soma += num;

    if (num % 2 == 0) {
      pares++;
    } else {
      impares++;
    }

    if (num > maior) {
      maior = num;
    }
  }

#ifdef _WIN32
  system("cls");

#else
  system("clear");
#endif

  media = (float)soma / total_numeros;
  printf("Soma: %d\n", soma);

  printf("Quantidade de numeros pares: %d\n", pares);

  printf("Quantidade de numeros pares: %d\n", impares);

  printf("Maior numero: %d\n", maior);

  printf("Média: %.1f\n", media);
}