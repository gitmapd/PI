#include <stdint.h>
#include <stdio.h>

void printBinary(int n) {
  for (int i = 7; i >= 0; i--) { // Printing 8 bits for simplicity
    int bit = (n >> i) & 1;
    printf("%d", bit);
    if (i == 4)
      printf(" "); // Space for readability
  }
}

int main() {

  // uint32_t a = 0b11100010011100000000000000000000;
  unsigned char a = 0x5C;
  printf("%d", a);
  int b = (a & 0x70F) >> 4;
  printf("%d",b);
  return 0;
}