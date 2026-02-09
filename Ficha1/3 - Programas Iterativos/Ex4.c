#include <stdio.h>

int circle(int r) {
  int contador = 0;
  for (int y = r; y >= -r; y--) {
    for (int x = -r; x <= r; x++) {
      if(x*x+y*y <= r * r) {
      printf("#");
      contador++;
    }
    else{
      printf(" ");
    }    
  }
    printf("\n");
  }
  return contador;
}
int main() {

  int n;
  printf("Introduza o número de #: ");
  scanf("%d", &n);
  int total = circle(n);
  printf("\nTotal de '#' impressos: %d\n", total);
  return 0;
}