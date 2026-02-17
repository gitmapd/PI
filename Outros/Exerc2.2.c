#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void transf_bits_strings(char *bits) {
  int total_bits = strlen(bits);
  int res_idx = 0;
  char resultado[100];
  for (int i = 0; i < total_bits; i += 7) {
    int valores_ascii = 0;
    for (int j = 0; j < 7; j++) {
      if (bits[i + j] == '1') {
        valores_ascii += pow(2, 6 - j); // (1 << (6-j))
      }
    }
    resultado[res_idx++] = (char)valores_ascii;
  }
  resultado[res_idx] = '\0';
  printf("%s\n", resultado);
}

int main() {
  char *bits = "10101010101110010000010011011101001110111011010001101111";
  transf_bits_strings(bits);
}