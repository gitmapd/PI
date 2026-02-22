#include <stdio.h>

void pascal(int v[], int N) {
  if (N <= 0)
    return;

  v[0] = 1;
  for (int i = 1; i < N; i++) {
    v[i] = 1;
    for (int j = i - 1; j > 0; j--) {
      v[j] += v[j - 1];
    }
  }
}

void pascal_a(int v[], int N) {
  if (N <= 0)
    return;

  v[0] = 1;
  for (int i = 0; i < N; i++) {
    if (i > 0) {
      v[i] = 1;
      for (int j = i - 1; j > 0; j--) {
        v[j] += v[j - 1];
      }
    }
  }
}

void pascal_b(int v[], int N) {
  if (N <= 0)
    return;

  v[0] = 1;
  for (int i = 0; i < N; i++) {
    for (int s = 0; s < N - 1 - i; s++) {
      printf(" ");
    }

    if (i > 0) {
      v[i] = 1;
      for (int j = i - 1; j > 0; j--) {
        v[j] += v[j - 1];
      }
    }
    for (int k = 0; k <= i; k++) {
      printf("%d ", v[k]);
    }
    printf("\n");
  }
}
void matrizPascal(int N) {
  int matriz[N][N];
  for (int i = 0; i < N; i++) {
    matriz[i][0] = 1;
    matriz[i][i] = 1;
    for (int j = 1; j < i; j++) {
      matriz[i][j] = matriz[i - 1][j - 1] + matriz[i - 1][j];
    }

    for (int s = 0; s < N - 1 - i; s++)
      printf("  "); // Espaços maiores

    for (int k = 0; k <= i; k++) {
      printf("%4d", matriz[i][k]); // %4d reserva 4 espaços para o número
    }
    printf("\n");
  }
}
int main() {
  int v[6];
  int N = 6;
  pascal_b(v, N);
  // printf("Linha %d: ", N);
  //  for (int k = 0; k < N; k++) {
  //    printf("%d ", v[k]);
  //  }
  //  printf("\n");
  //  matrizPascal(6);
}