#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int main() {

  int numero;
  int maior_elem = INT_MIN;

  printf("Introduza uma sequência e termina com 0:\n");

  if (scanf("%d", &numero) != 1) {
    printf("Erro a ler input.");
    return 1;
  }

  while (numero != 0) {
    if (numero > maior_elem) {
      maior_elem = numero;
    }
    if (scanf("%d", &numero) != 1) {
      printf("Erro a ler input.");
      return 1;
    }
  }
  if (maior_elem == INT_MIN) {
    printf("Não houve inteiros válidos introduzidos.\n");
  } else {
    printf("O valor mais alto desta sequência foi: %d\n", maior_elem);
  }

  return 0;
}