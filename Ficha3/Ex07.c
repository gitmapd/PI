#include <stdio.h>
void quadrados(int q[], int N) {
  q[0] = 0;
  for (int i = 0; i < N - 1; i++) {
    q[i + 1] = q[i] + (2 * i + 1);
  }
}

void quadrados2(int q[], int N) {
  for (int i = 0; i < N; i++) {
    q[i] = i * i;
  }
}

void quadrados3(int q[], int N) {
  if (N <= 0)
    return;
  int valorAtual = 1;
  int valorImpar = 3;
  for (int i = 0; i < N; i++) {
    q[i] = valorAtual;
    valorAtual += valorImpar;
    valorImpar += 2;
  }
}
void comeca_um(int q[], int N) {
  q[0] = 0;
  for (int i = 1; i < N; i++) {
    q[i] = q[i - 1] + (2 * (i - 1) + 1);
  }
}

int main() {
  int v[] = {1, 2, 3, 4, 5};
  int size = sizeof(v) / sizeof(v[0]);

  quadrados(v, size);
  for (int i = 0; i < size; i++) {
    printf("O quadrado de %d é %d\n", i, v[i]);
  }

  quadrados2(v, size);
  for (int i = 0; i < size; i++) {
    printf("O quadrado de %d é %d\n", i, v[i]);
  }

  comeca_um(v, size);
  for (int i = 0; i < size; i++) {
    printf("O quadrado de %d é %d\n", i, v[i]);
  }
}