#include <stdio.h>

int twoDuplicates_rem(int nums[], int size) {
    if(size == 0) return 0;
  int ptr = 0;
  int temp = 0;
  for (int i = 1; i < size; i++) {
    if (nums[i] != nums[ptr]) {
      ptr++;
      nums[ptr] = nums[i];
    }
  }
  return ptr + 1;
}
int twoDuplicates(int nums[], int size) {
  int ptr = 1;
  int temp = 0;
  for (int i = 2; i < size; i++) {
    if (nums[i] != nums[ptr - 1]) {
      ptr++;
      temp = nums[i];
      nums[i] = nums[ptr];
      nums[ptr] = temp;
    }
  }
  return ptr + 1;
}
int main() {
  int b[7] = {1, 1, 1, 2, 2, 2, 3};
  int size_b = sizeof(b) / sizeof(b[0]);
  //int res = twoDuplicates(b, size_b);
  int res = twoDuplicates(b,size_b);
  // printf("O número de pares é %d e o número de ímpares é %d\n", res,
  //      (size_b - res));
  for (int i = 0; i < res; i++) {
    printf("%d", b[i]);
  }
  printf("\n");
  return 0;
}