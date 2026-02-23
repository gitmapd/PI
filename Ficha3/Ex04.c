#include <stdio.h>

int soma(int v[], int N) {
  int soma = 0;
  for (int i = 0; i < N; i++) {
    soma += v[i];
  }
  return soma;
}

int main() {
  int v[] = {1, 2, 3, 4, 5};

  printf("A soma é %d", soma(v, (sizeof(v) / sizeof(v[0]))));
  printf("\n");
}