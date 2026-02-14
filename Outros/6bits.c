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
int main() {
  int b = 0b1010;
  printf("%d",conta_bits(b));
}

int imprimir_bin(int n, int total_bits) {

   for (int i = total_bits - 1; i >= 0; i--) 
   {
    int b = (n >> i) & 1;
   printf("%d", b);
 }

   printf("\n");
}

// // int print_bits(int n, int total_bits) {

// //   for (int i = total_bits - 1; i >= 0; i--) {
// //     int b = (n >> i) & 1;
// //     printf("%d", b);
// //   }

// //   printf("\n");
// // }


//   if (n >= 0) {
//     c1 = (unsigned char)(n);
//     c2 = (unsigned char)(n);
//   } else {
//     c1 = (unsigned char)~(abs(n));
//     c2 = c1 + 1;
//   }

//   imprimir_bin(n, total_bits);

//   imprimir_bin(c1, total_bits);

//   imprimir_bin(c2, total_bits);



// #include <stdio.h>
// #include <stdlib.h>

// // Função que apenas imprime os 8 bits de um número
// void mostrar_8_bits(int valor) {
//   for (int i = 7; i >= 0; i--) {
//     printf("%d", (valor >> i) & 1);
//   }
// }

// int main() {

// // Teu array de números para a tabela
// int lista[] = {12,-68,101,-128};
// int total = sizeof(lista) / sizeof(lista[0]);

// printf(" NUM |  BINARIO  |    C1     |    C2    \n");
// printf("-----|-----------|-----------|----------\n");

// for (int i = 0; i < total; i++) {
//     int n = lista[i];
//     int c1, c2;

//     if (n >= 0) {
//         c1 = n;
//         c2 = n;
//     } else {
//         c1 = (~abs(n)) & 0xFF; // (unsigned char)(n) e & 0xFF limpam os bits extras 
//         c2 = (c1 + 1) & 0xFF;
//     }
    
//     printf("%4d | ", n);
//     mostrar_8_bits(abs(n));
//     printf(" | ");
//     mostrar_8_bits(c1);
//     printf(" | ");
//     mostrar_8_bits(c2);
//     printf("\n");
// }
// return 0;
// }

//   // Teu array de números para a tabela
//   int lista[] = {101, 110, 1010, 11101, 1110101};
//   int total = sizeof(lista) / sizeof(lista[0]);

//   printf(" VALOR | LEN (BITS) |   C1 BINARIO \n");
//   printf("-------|------------|--------------\n");

//   for (int i = 0; i < total; i++) {
//     int n = lista[i];
//     int len = 0;
//     int temp = n;
//     while (temp > 0) {
//       temp >>= 1;
//       len++;
//     }
//     if (len == 0)
//       len = 1;
//     int mascara = (1 << len) - 1;
//     int c1 = (~n & mascara);
//     printf(" %5d |     %d      | ", n, len);

//     for (int b = len - 1; b >= 0; b--) {
//       printf("%d", (c1 >> b) & 1);
//     }
//   }
//   printf("\n");
//   return 0;
// }

