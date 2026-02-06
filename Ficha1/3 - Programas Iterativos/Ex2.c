#include <stdio.h>

void xadrez(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i + j) % 2 == 0) {
        printf("#");
      } else {
        printf("_");
      }
    }
    printf("\n");
  }
}
int main() {

  int n;
  printf("Introduza o número de #: ");
  scanf("%d", &n);
  xadrez(n);
  return 0;
}