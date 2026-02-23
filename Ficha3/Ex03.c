#include <stdio.h>

void swap(int v[], int i, int j) {
  int temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

int main() {
  int v[] = {1, 2, 3, 4, 5};
  swap(v, 0, 2);
  printf("V após a troca: %d, %d", v[0], v[2]);
  printf("\n");
}