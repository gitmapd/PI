#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = -1;
  int total_bits = 6;
  int sinal = (n < 0) ? 1 : 0;
  int mag = abs(n);
  printf("%d", sinal);
  for (int i = total_bits - 2; i >= 0; i--) {
    int b = (mag >> i) & 1;
    printf("%d", b);
  }
}