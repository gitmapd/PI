#include <stdio.h>

int main() {
  int n = 5;
  int larguratotal = (2 * n - 1);
  printf("+");
  for (int i = 0; i < larguratotal + 2; i++) {printf("-");}
  printf("+\n");
  for (int i = 1; i <= n; i++) {
    printf("| ");
    
    for (int j = 0; j < (n - i); j++) {printf(" ");}

    for (int k = 1; k <= (2 * i - 1); k++) {
      if (k == 1 || k == (2 * i - 1) || i == n) {
        printf("#");
      } else {
        printf(" ");
      }
    }

    for (int j = 0; j < (n - i); j++) { printf(" ");}
    
    printf(" |\n");
  }
  printf("+");
  for (int k = 0; k < larguratotal + 2; k++) {printf("-");}
  printf("+\n");
  return 0;
}