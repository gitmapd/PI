#include <stdio.h>

int maximum(int v[], int N, int *m) {
  if (N <= 0) {
    return 1;
  }
  int max = 0;
  for (int k = 1; k < N; k++) {
    if (v[k] > v[max])
      max = k;
  }
  *m = v[max];
  return 0;
}
int main() {
    int v[] = {1, 2, 3, 4, 5};
      int m;
  int size = sizeof(v) / sizeof(v[0]);
  int res = maximum(v, size, &m);
  if (res == 0) {

    printf("O maximo é %d", m);
    printf("\n");
  }
}