#include <stdio.h>

void retangulo(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("#");
    }
    printf("\n");
  }
}
int main() {
  int n;
  printf("Introduza o número de #: ");
  scanf("%d", &n);
  retangulo(n);
  return 0;
}