#include <stdio.h>
void swapM(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void swap(int v[], int i, int j) {
  int temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
int soma(int v[], int N) {
  int soma = 0;
  for (int i = 0; i < N; i++) {
    soma += v[i];
  }
  return soma;
}

int maximum(int v[], int N, int *m) {
  if (N <= 0) {
    return 1;
  }
  int currentMax = 0;
  for (int k = 1; k < N; k++) {
    if (v[k] > v[currentMax])
      currentMax = k;
  }
  *m = v[currentMax];
  return 0;
}

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
  //   int x = 3, y = 5;
  //   int x_orig = x;
  //   int y_orig = y;
  //   swapM(&x, &y);
  //   printf("antes (%d,%d) e depois (%d,%d)\n", x_orig, y_orig, x, y);
  int x_orig = v[0];
  int y_orig = v[2];
  int m;
  int size = sizeof(v) / sizeof(v[0]);

  int res = maximum(v, size, &m);
  printf("antes (%d,%d)\n", x_orig, y_orig);
  swap(v, 0, 2);
  printf("Vetor após a troca: %d, %d", v[0], v[2]);
  printf("\n");

  printf("A soma é %d", soma(v, (sizeof(v) / sizeof(v[0]))));
  printf("\n");

  if (res == 0) {

    printf("O maximo é %d", m);
    printf("\n");
  }

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

   quadrados2(v, size);
  for (int i = 0; i < size; i++) {
    printf("O quadrado de %d é %d\n", i, v[i]);
  }
}