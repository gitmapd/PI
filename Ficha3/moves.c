#include <stdio.h>

void moveZeroes(int nums[], int size) {
  int ptr = 0;
  for (int i = 0; i < size; i++) {
    if (nums[i] != 0) {
      nums[ptr] = nums[i];
      ptr++;
    }
  }
  for (int j = ptr; j < size; j++) {
    nums[j] = 0;
  }
}

void moveZeroes2(int nums[], int size) {
  int ptr = 0;
  int temp = 0;
  for (int i = 0; i < size; i++) {
    if (nums[i] != 0) {
      temp = nums[i];
      nums[i] = nums[ptr];
      nums[ptr] = temp;
      ptr++;
    }
  }
}
void moveZeroes3(int nums[], int size) {
  if (size < 2)
    return;
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
}
int main() {
  int a[5] = {0, 1, 0, 3, 12};
  int b[6] = {1, 1, 2, 2, 3, 3};
  int size = sizeof(b) / sizeof(b[0]);
  moveZeroes3(b, size);
  for (int i = 0; i < size; i++) {
    printf("%d", b[i]);
  }

  return 0;
}
