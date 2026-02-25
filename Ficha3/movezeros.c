#include <stdio.h>

void moveZeroes(int v[], int size) {
  int ptr = 0;
  int temp = 0;
  for (int i = 0; i < size; i++) {
    if (v[i] != 0) {
      temp = v[i];
      v[i] = v[ptr];
      v[ptr] = temp;
      ptr++;
    }
  }
}

int main() {

  int a[5] = {0, 1, 0, 3, 12};
  int b[6] = {1, 1, 2, 2, 3, 3};
  int size_a = sizeof(a) / sizeof(a[0]);
  int size_b = sizeof(b) / sizeof(b[0]);
moveZeroes(a,size_a);
  for (int i = 0; i < size_a; i++) {
    printf("%d", a[i]);
  }
  printf("\n");

  return 0;
}