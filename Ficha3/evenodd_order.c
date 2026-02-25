#include <stdio.h>

int moveEvenOdd(int nums[], int size) {
  int ptr = 0;
  int temp = 0;
  for (int i = 0; i < size; i++) {
    if (nums[i] % 2 == 0) {
      temp = nums[i];
      nums[i] = nums[ptr];
      nums[ptr] = temp;
      ptr++;
    }
  }
  return ptr;
}
int main() {
  int b[6] = {1, 1, 2, 2, 3, 3};
  int size_b = sizeof(b) / sizeof(b[0]);
  int res =  moveEvenOdd(b, size_b);
  printf("O número de pares é %d e o número de ímpares é %d\n",res,(size_b - res));
  for (int i = 0; i < res; i++) {
    printf("%d", b[i]);
  }
  printf("\n");

    for (int i = res; i < size_b; i++) {
    printf("%d", b[i]);
  }
  printf("\n");
  return 0;
}
