#include <stdio.h>

// void merge(int a[], int na, int b[], int nb, int r[]) {
//   int i = 0, j = 0, k = 0;

//   while (i < na && j < nb) {
//     if (a[i] <= b[j]) {
//       r[k++] = a[i++];
//     } else {
//       r[k++] = b[j++];
//     }
//   }
//   while (i < na) {
//     r[k++] = a[i++];
//   }

//   while (j < nb) {
//     r[k++] = b[j++];
//   }
// }

void merge(int v[], int m, int n, int aux[]) {
  int i = 0;
  int j = m;
  int k = 0;

  while (i < m && j < n) {
    if (v[i] <= v[j]) {
      aux[k++] = v[i++];
    } else {
      aux[k++] = v[j++];
    }
  }
  while (i < m) {
    aux[k++] = v[i++];
  }

  while (j < n) {
    aux[k++] = v[j++];
  }
  for (int x = 0; x < n; x++) {
    v[x] = aux[x];
  }
}
void mergesort(int v[], int n) {
  if (n <= 1)
    return;

  int m = n / 2;
  mergesort(v, m);
  mergesort(v + m, n - m);

  int aux[n];
  merge(v, m, n, aux);
}

int main() {
  int v[] = {10, 2, 15, 7, 4, 20, 1};
  int n = 7;

  mergesort(v, n);

  for (int i = 0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n");
}