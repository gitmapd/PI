#include <stdio.h>

long long fat(int n) {
  int local[32];
  int p = 0;
  int n_original = n;
  int resultado = 1;

  if (n == 0 || n == 1) {
    printf("%d! = 1", n);
    return 1;
  }
  while (n > 0) 
    {
      local[p++] = n;
      resultado *= n;
      n--;
    }
    printf("%d! = ", n_original);
    for (int i = 0; i < p; i++) {
      printf("%d", local[i]);
      if (i < p - 1)
        printf(" * ");
    }
    printf(" = %llu", resultado);
  return resultado;
  }


int main() {

  fat(5);
  return 0;
}