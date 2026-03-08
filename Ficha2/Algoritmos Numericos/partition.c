#include <stdio.h>

int ordenado(int v[], int N) {
  for (int i = 0; i < N - 1; i++) {
    if (v[i] > v[i + 1]) {
      return 0;
    }
  }
  return 1;
}

int partition(int v[], int N, int x) {
  int a = 0;

  for (int b = 0; b < N - 1; b++) {
    if (v[b] <= x) {
      int temp = v[a];
      v[a] = v[b];
      v[b] = temp;
      a++;
    }
  }
  int temp = v[a];
  v[a] = v[N - 1];
  v[N - 1] = temp;
  return a;
}
void quicksort(int v[], int n) {
  if (n <= 1)
    return;
  int x = v[n - 1];

  //   int limite = partition(v, n, x);
  //   quicksort(v, limite);
  //   quicksort(v + limite, n - limite);

  //   if (limite == n)
  //     limite--;
  int i = partition(v, n, x);
  quicksort(v, i);
  quicksort(v + i + 1, n - i - 1);
}
// Insere aqui as tuas funções: ordenado, merge, partition...

int main() {
  // Teste da Partição
  int v[] = {10, 2, 15, 7, 4, 20, 1};
  int n = 7;
  int x = 7;

  printf("Array original: ");
  for (int i = 0; i < n; i++)
    printf("%d ", v[i]);

  //   int limite = partition(v, n, x);

  //   printf("\nApós partição (x=%d): ", x);
  //   for (int i = 0; i < n; i++)
  //     printf("%d ", v[i]);
  //   printf("\nElementos <= %d: %d\n", x, limite);

  quicksort(v, 7);
  printf("Array ordenado: ");
  for (int i = 0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n");

  // Teste do Ordenado
  if (ordenado(v, n)) {
    printf("O array está ordenado!\n");
  } else {
    printf("O array ainda não está ordenado.\n");
  }

  return 0;
}