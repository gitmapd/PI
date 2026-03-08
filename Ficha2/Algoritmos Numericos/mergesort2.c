#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int v[], int m, int n, int aux[]) {
  int i = 0;
  int j = m;
  int k = 0;

  while(i < m && j < n) {
    if(v[i] <= v[j]) {
        aux[k++] = v[i++];
    }
    else {
        aux[k++] = v[j++];
    }

  }
  while(i < m) {
    aux[k++] = v[i++];
  }
  while(j < n) {
    aux[k++] = v[j++];

  }
  for(int x = 0; x < n;x++) {
    v[x] = aux[x];
  }
}
void mergesort(int v[], int n) {
  if (n <= 1)
    return;
  int m = n / 2;
  mergesort(v,m);
  mergesort(v+m,n-m);
  int aux[n];
  merge(v,m,n,aux);
}

int partition(int v[], int N, int x) {
int a = 0;
for(int b = 0; b < N;b++) {
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}
    int temp = v[a];
    v[a] = v[N-1];
    v[N-1] = temp;
    return a;
}
void quicksort(int v[], int n) {

if(n <=1) return;

int x = v[n-1];
int i = partition(v,n,x);
quicksort(v,i);
quicksort(v+i+1,n-i-1);
}
void comparar_algoritmos() {
  int N = 50000; // Vamos testar com 50 mil números
  int *v1 = malloc(N * sizeof(int));
  int *v2 = malloc(N * sizeof(int));

  // Preencher arrays com números aleatórios
  for (int i = 0; i < N; i++) {
    v1[i] = rand() % 100000;
    v2[i] = v1[i]; // v2 é uma cópia exata de v1
  }

  // Medir Quicksort
  clock_t start_q = clock();
  quicksort(v1, N);
  clock_t end_q = clock();
  double tempo_q = ((double)(end_q - start_q)) / CLOCKS_PER_SEC;

  // Medir Mergesort
  clock_t start_m = clock();
  mergesort(v2, N);
  clock_t end_m = clock();
  double tempo_m = ((double)(end_m - start_m)) / CLOCKS_PER_SEC;

  printf("Resultados para N = %d:\n", N);
  printf("Quicksort: %f segundos\n", tempo_q);
  printf("Mergesort: %f segundos\n", tempo_m);

  free(v1);
  free(v2);
}

int main() {
  srand(time(NULL)); // Inicializa a semente aleatória
  comparar_algoritmos();
  return 0;
}