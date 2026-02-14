#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int main() {

  int numero;
  int maior_elem = INT_MIN;
  int count = 0;
  long long sum = 0;

  printf("Introduza uma sequência e termina com 0:\n");

  if (scanf("%d", &numero) != 1) {
    printf("Erro a ler input.");
    return 1;
  }

  while (numero != 0) {
    sum += numero;
    count++;
    if (scanf("%d", &numero) != 1) {
      printf("Erro a ler input.");
      return 1;
    }
  }
  if (count > 0) {
    double average = (double)sum / count;
    printf("A Média da sequência é: %.2f\n", average);

  } else {
    printf("Não foram introduzidos inteiros.\n");
  }

  return 0;
}