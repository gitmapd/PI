#include <stdio.h>

void troca(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void inverteArray(int v[], int N) {
  for (int i = 0; i < N / 2; i++) {
    troca(&v[i], &v[N - 1 - i]);
  }
}

void inverteArray2(int v[], int N) {
  int *inicio = v;
  int *fim = v + (N - 1);

  while (inicio < fim) {
    troca(inicio, fim);
    inicio++;
    fim--;
  }
}

void inverteOutro(int v[], int s[], int N) {
    for (int i = 0; i < N; i++) {
    s[N - 1 - i]=v[i];
  }
}

int main() {
  int v[5] = {1, 2, 3, 4, 5};
  int s[5];

  //inverteArray(v, 5);

  inverteOutro(v,s, 5);

  for (int i = 0; i < 5; i++) {
    printf("%d\n", s[i]);
  }
}