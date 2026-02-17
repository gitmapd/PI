#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void transf_bits_strings(char *texto) {
  char bits_final[500];
  for (int i = 0; texto[i] != '\0'; i++) {
    int valor = (int)texto[i];
    for (int j = 6; j >= 0; j--) {
      if ((valor >> j) & 1) {
        strcat(bits_final, "1");
      } else {
        strcat(bits_final, "0");
      }
    }
  }
  printf("%s\n", bits_final);
}

int main() {
  char *bits = "ABCD";
  transf_bits_strings(bits);
}