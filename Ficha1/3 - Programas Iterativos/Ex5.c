#include <stdio.h>

void Quadrado(int n) {
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      if (y == 0 || y == n - 1 || x == 0 || x == n - 1) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

void cruz(int n) {
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      if (y == 0 || y == n - 1 || x == 0 || x == y || x + y == n - 1 ||
          x == n - 1 || x == n / 2 || y == n / 2) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

void met_quad(int n) {
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      if (x + y  == n-1) {
        printf("#");
      }
      else  {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main() {
  int n = 5;
  // Quadrado(n);
  // cruz(n);
  met_quad(n);
}