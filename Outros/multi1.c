#include <stdio.h>

double multInt1(int n, float m, int *ops) {
  double r = 0;
  *ops = 0;
  if (n < 0)
    return -multInt1(-n, m, ops);

  for (int i = 0; i < n; i++) {
    r = r + m;
    (*ops)++;
  }
  return r;
}

int main() {
  int n = 1000000;
  float m = 423.0;
  int contador_somas;
  double resultado = multInt1(n, m, &contador_somas);
  printf("Multiplicando %d por %.2f:\n", n, m);
  printf("------------------------------\n");
  printf("Resultado Final: %.2f\n", resultado);
  printf("Somas de floats realizadas: %d\n", contador_somas);
}