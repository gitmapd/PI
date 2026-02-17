#include <math.h>
#include <stdio.h>

int fib1(int n, int *ops) {
  (*ops)++;
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  return fib1((n - 1), ops) + fib1((n - 2), ops);
}

int main() {
  int n = 30;
  int conta_ciclos=0;
  int resultado = fib1(n, &conta_ciclos);
  printf("O Fibonnaci de %d é %d\n", n, resultado);
  printf("Ciclos são %d\n", conta_ciclos);
  return 0;
}