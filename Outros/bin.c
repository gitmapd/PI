#include <stdio.h>
#include <stdlib.h>

int conta_bits(unsigned int n) {
  int count = 0;
  while (n) {
    count++;
    n >>= 1;
  }
  return count;
}
void imprimir_bin(int n, int total_bits) {
  // printf("0b");
  for (int i = total_bits - 1; i >= 0; i--) {
    int b = (n >> i) & 1;
    printf("%d", b);
    if (i % 4 == 0 && i != 0)
      printf(" ");
  }

  // printf("\n");
}
int c1(unsigned int n, int total) { return ((~n) & (1 << total) - 1); }

int c2(unsigned int n, int total) {
  return (c1(n, total) + 1) & ((1 << total) - 1);
}

int main() {
  int b = 0b1010;
  // printf("%d\n", conta_bits(b));
  printf("Original: ");
  imprimir_bin(b, conta_bits(b));
  printf("\n");
  printf("Comp. de 1:  ");
  imprimir_bin(c1(b, conta_bits(b)), conta_bits(b));
  printf("\n");
  printf("Comp. de 2:  ");
  imprimir_bin(c2(b, conta_bits(b)), conta_bits(b));
  printf("\n");

  int lista[] = {12, -68, 101, -128};
  int total = sizeof(lista) / sizeof(lista[0]);

  printf(" NUM  |       BINARIO       |         C1          |         C2       "
         "   \n");
  printf("------|---------------------|---------------------|------------------"
         "---\n");

  for (int i = 0; i < total; i++) {
    int n = lista[i];
    int val_abs = (n < 0) ? -n : n;
    int tam = (val_abs > 0x07FF) ? 16 : (val_abs > 0x007F) ? 12 : 8;

    printf("%4d | ", n);

    imprimir_bin(n, tam);
    if (tam == 8)
      printf("        ");
    else if (tam == 12)
      printf("    ");

    printf(" | ");

    // Imprimir C1
    imprimir_bin(c1(n, tam), tam);
    if (tam == 8)
      printf("          ");
    else if (tam == 12)
      printf("    ");

    printf(" | ");

    // Imprimir C2
    imprimir_bin(c2(n, tam), tam);
    printf("\n");
  }
  return 0;
}
