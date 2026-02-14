#include <stdio.h>
#include <stdlib.h>

int conta_bits(unsigned int n) {
  int count = 0;
  if (n == 0)
    return 1;
  while (n > 0) {
    count++;
    n >>= 1;
  }
  return count;
}

int main() {
  int n = -143;
  int sinal = (n < 0) ? 1 : 0;
  unsigned int mag = abs(n);
  int bits_magnitude = conta_bits(mag);
  printf("%d", sinal);

  for (int i = bits_magnitude - 1; i >= 0; i--) {
    int b = ((mag >> i) & 1);
    printf("%d", b);
  }
}