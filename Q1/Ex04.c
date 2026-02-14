#include <stdio.h>
int bitsUm(unsigned int n) {
  int count = 0;
  while (n) {
    if (n & 1) {
      count++;
    }
    n >>= 1;
  }
  return count;
}
int bitsZ(unsigned int n) {
  if (n == 0)
    return 32;
  int count = 0;
  while ((n & 1) == 0) {
    count++;
    n >>= 1;
  }
  return count;
}

int bitsTotalZ(unsigned int n) { return sizeof(n) * 8 - bitsUm(n); }
int main() {
  int unsigned n = 100;
  printf("%d\n", bitsUm(n));

  printf("%d\n", bitsZ(n));

  printf("%d\n", bitsTotalZ(n));
}