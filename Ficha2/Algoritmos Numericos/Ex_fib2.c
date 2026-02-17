#include <math.h>
#include <stdio.h>

int fib2(int n, int *ops) {
  (*ops) = 0;
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  int ant2 = 0;
  int ant1 = 1;
  int atual = 0;
  for (int i = 2; i <= n; i++) {
    (*ops)++;
    atual = ant1 + ant2;
    ant2 = ant1;
    ant1 = atual;
  }
  return atual;
}

int main() {
  int n = 30;
  int conta_ciclos;
  int resultado = fib2(n, &conta_ciclos);
  printf("O Fibonnaci de %d é %d\n", n, resultado);
  printf("Ciclos são %d\n", conta_ciclos);
  return 0;
}