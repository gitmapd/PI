#include <stdio.h>

int moveUnique(int nums[], int size) {
  if (size == 0)
    return 0;
  int ptr = 0;
  int temp = 0;
  for (int i = 1; i < size; i++) {
    if (nums[i] != nums[ptr]) {
      ptr++;
      temp = nums[i];
      nums[i] = nums[ptr];
      nums[ptr] = temp;
    }
  }
  return ptr + 1;
}
int main() {
  int b[6] = {1, 1, 2, 2, 3, 3};
  int size_b = sizeof(b) / sizeof(b[0]);
  int res = moveUnique(b, size_b);
  printf("%d\n",res);
  for (int i = 0; i < size_b; i++) {
    printf("%d", b[i]);
  }
  printf("\n");
  return 0;
}
