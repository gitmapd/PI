#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "definicoes.h"
void print_bin(int n, int total_bits) {
  for (int i = total_bits - 1; i >= 0; i--) {
    int bit = (n >> i) & 1;
    printf("%u", bit);
    if (i % 4 == 0 && i != 0)
      printf(" ");
  }
}

int main() {
  unsigned long long pixels = CALC_PIXELS(IMG24_WIDTH, IMG24_HEIGHT);

  float bits_ch = CALC_BITS_CH(EX24_SIZE_KIB, pixels, 3);
  int v_max = (int)pow(2, (int)bits_ch) - 1;

  float bytes_por_pixel = (float)EX24_SIZE_KIB * KiB / pixels;

  printf("Bytes por pixel: %.1f Bytes\n", bytes_por_pixel);
  printf("Bits por canal: %.0f\n", bits_ch);
  printf("Valor maximo (Decimal): %d\n", v_max);
  printf("Valor maximo (Binario): ");
  print_bin(v_max, (int)bits_ch);
  printf("\n");
}