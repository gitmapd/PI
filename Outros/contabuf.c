#include <stdio.h>

int count_internal_zeros(int n) {
  int count = 0;
  while (n > 0) {
    if (!(n & 1)) {
      count++;
    }
    n >>= 1;
  }
  return count;
}

int count_all_zeros(int n) {
  int count = 0;
  int size = sizeof(int) * 8;
  for (int i = 0; i < size; i++) {
    if (!((n >> i) & 1)) {
      count++;
    }
  }
  return count;
}
int count_ones(int n) {
  int count = 0;
  while (n) {
    if (n & 1) {
      count++;
    }
    n >>= 1;
  }
  return count;
}
int count_ones(int n, int size) {
  int count = 0;

  for (int i = 0; i < size; i++) {
    if ((n >> i) & 1) {
      count++;
    }
  }
  return count;
}

int count_Z(int n) {
  if (n == 0)
    return 32;
  int count = 0;

  while ((n & 1) == 0) {
    count++;
    n >>= 1;
  }
  return count;
}
int count_ones_fast(int n) {
  int count = 0;
  while (n > 0) {
    n = n & (n - 1); // The Magic Line n | (n + 1)
    count++;
  }
  return count;
}
int count_zeros(int n, int size) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (((n >> i) & 1) == 0) {
      count++;
    }
  }
  return count;
}
int count_bits_in_buffer(int buff[], int n) {
  int ones = 0;
  for (int i = 0; i < n; i++) {
    ones += count_ones(buff[i]);
  }
  return ones;
}

int count_zeros_in_buffer(int buff[], int n) {
  int zeros = 0;
  int bits = sizeof(int) * 8;
  for (int i = 0; i < n; i++) {
    zeros += count_zeros(buff[i], bits);
  }
  return zeros;
}
int main() {
  int x[] = {1, 2, 3, 4, 5};
  int size = sizeof(x) / sizeof(x[0]);

  int res_ones = count_bits_in_buffer(x, size);

  printf("Total 1s in buffer: %d\n", res_ones);

  int res_zeros = count_zeros_in_buffer(x, size);

  printf("Total 0s in buffer: %d\n", res_zeros);
  return 0;
}