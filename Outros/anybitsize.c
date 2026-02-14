#include <stdio.h>
#include <stdlib.h>

int conta_bits(unsigned int n) {
  int count = 0;
  if (n == 0) return 1;
  while (n > 0) {
      count++;
    n >>= 1;
  }
  return count;
}

int imprimir_bin(int n, int total_bits) {

   for (int i = total_bits - 1; i >= 0; i--) 
   {
    int b = (n >> i) & 1;
   printf("%d", b);
 }

   printf("\n");
}
// int main() {
//   int b = 0b1010;
//   printf("%d",conta_bits(b));

// int numeros[] = {12, -12, 34, -34, 1, -1, 0};
//   int total_elementos = sizeof(numeros) / sizeof(numeros[0]);
//   printf(" NUMERO |  BINARIO   |    C1      |    C2      \n");
//   printf("--------|------------|------------|------------\n");

//   for (int i = 0; i < total_elementos; i++) {
//     int n = numeros[i];
//     int bin, c1, c2;

//     // Lógica de conversão
//     if (n >= 0) {
//       bin = n & 0xFF;
//       c1 = n & 0xFF;
//       c2 = n & 0xFF;
//     } else {
//       bin = abs(n) & 0xFF; // Apenas para mostrar o positivo como base
//       c1 = (~n) & 0xFF;
//       c2 = (c1 + 1) & 0xFF;
//     }

//     // Impressão da linha da tabela
//     printf("  %4 d  |  ", n);
//     imprimir_bin(n >= 0 ? n : abs(n), 8); // Mostra o binário "puro"
//     printf("  |  ");
//     imprimir_bin(c1, 8);
//     printf("  |  ");
//     imprimir_bin(c2, 8);
//     printf("\n");
//   }
// }


int main() {

int b = 0b0000;
printf("%d",conta_bits(b));
  // Nota: Usei 0b para o C entender como binário real
  int lista[] = {0b0000, 0b111, 0b1001, 0b10011, 0b1011000};
  int total = sizeof(lista) / sizeof(lista[0]);

  printf(" VALOR | LEN (BITS) | C1 BINARIO | C2 BINARIO \n");
  printf("--------|------------|------------|------------|\n");

  for (int i = 0; i < total; i++) {
    int n = lista[i];

    // 1. Descobrir o LEN (tamanho em bits)
    // int len = 0;
    // int temp = n;
    // while (temp > 0) {
    //   temp >>= 1;
    //   len++;
    // }
    // if (len == 0)
    //   len = 1;
    int len = conta_bits(n);
    // 2. Criar máscara e calcular C1
    int mascara = (1 << len) - 1;
    int c1 = (~n) & mascara;
    int c2 = (c1 + 1) & mascara;

    //printf("%d",c1);
    printf("%d",c2);
    printf("  |  %d  |", len);
    int space = 10 - len;
    for(int s=0; s<space; s++) printf(" ");
    // Loop de impressão usando o LEN dinâmico

    for (int b = len - 1; b >= 0; b--) {
      printf("%d", (n >> b) & 1);
    }
    for(int s=0; s<space; s++) printf(" ");
    // for (int b = len - 1; b >= 0; b--) {
    //   printf("%d", (c1 >> b) & 1);
    // }

  
    for(int s=0; s<space; s++) printf(" ");
    for (int b = len - 1; b >= 0; b--) {
      printf("%d", (c2 >> b) & 1);
    }

    printf("\n");
  }

  return 0;
}

