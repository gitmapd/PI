#include <math.h>
#include <stdio.h>

int fib3(int n, int *fibonacci, int *ops) {
  *ops = 0;
  int soma = 0;
  if (n >= 1) {
    fibonacci[0] = 0;
    (*ops)++;
  }
  if (n >= 2) {
    fibonacci[1] = 1;
    (*ops)++;
  }
  for (int i = 2; i < n; i++) {
    fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    (*ops)++;
  }
  for (int j = 0; j < n; j++) {
    soma += fibonacci[j];
  }
  return soma;
}

int main() {
  int n;
  int ops;
  printf("Introduzir quantos números pretende: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Por favor insira um número positivo.\n");
    return 1;
  }
  int fibonacci[n];
  int resultado = fib3(n, fibonacci, &ops);
  printf("Sequência: ");
  for (int j = 0; j < n; j++) {
    printf("%d", fibonacci[j]);
    if (j < n - 1) {
      printf(", ");
    }
  }
  printf("\n");
  printf("Soma da sequência de Fibonacci: %d\n", resultado);
  printf("Número de operações são %d\n", ops);
  return 0;
}