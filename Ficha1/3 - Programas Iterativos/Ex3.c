#include <stdio.h>

void triangulo(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      printf("#");
    }
    printf("\n");
  }

  for (int i = n - 1; i >= 1; i--) {
    for (int j = 0; j < i; j++) {
      printf("#");
    }
    printf("\n");
  }
}

void triangulo2(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (n - i); j++) {
      printf(" ");
    }
    for (int k = 0; k < (2*i -1); k++) {
        printf("#");
      }
      printf("\n");
    }
  }
  int main() {

    int n;
    printf("Introduza o número de #: ");
    scanf("%d", &n);
    triangulo(n);
    triangulo2(n);
    return 0;
  }