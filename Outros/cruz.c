#include <stdio.h>

// void cruz_longa(int n) {
//     int mid_i = n / 2;
//     int mid_j = n; // Meio de uma grade mais larga

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n * 2; j++) {
//             // Desenha o centro e braços horizontais esticados
//             if (i == mid_i && (j >= mid_j - 2 && j <= mid_j + 2)) {
//                 printf("#");
//             }
//             // Desenha as "pernas" diagonais curtas para dar o formato de X
//             else if ((i == mid_i - 1 || i == mid_i + 1) &&
//                      (j == mid_j - 3 || j == mid_j + 3)) {
//                 printf("#");
//             } else {
//                 printf(" ");
//             }
//         }
//         printf("\n");
//     }
// }

void cruz_longa(int n) {
  int mid_i = n / 2;
  int mid_j = n / 2; // Meio de uma grade mais larga

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n * 2; j++) {
      // Desenha o centro e braços horizontais esticados
      if (j == mid_j || i == mid_i) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main() {
  cruz_longa(5);
  return 0;
}