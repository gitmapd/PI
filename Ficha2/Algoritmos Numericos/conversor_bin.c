#include <stdio.h>

void conversor_bin(int n) {
  int local[32];
  int restos[32];
  int p = 0;

  while (n > 0) {
    local[p] = n;
    restos[p] = n & 1;
    n>>=1;
    p++;
  }
  for(int i = 0; i < p;i++) {
    printf("%d",local[i]);
    printf(" -> ");
  }
  printf("0");
  printf(" | Binario -> ");
  for(int j = p - 1; j >= 0; j--) {
    printf("%d",restos[j]);
  }
  }

  int main() {
    conversor_bin(100);
    return 0;
}