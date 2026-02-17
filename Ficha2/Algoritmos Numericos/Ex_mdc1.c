#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mdc1(int a, int b, int *ops) {
  int i;
  *ops = 0;
  if (a < 0)
    a = -a;
  if (b < 0)
    b = -b;
  if(a == 0) return b;
  if(b == 0) return a;
  int menor = (a < b) ? a : b;
  for (i = menor; i >= 1; i--) {
    (*ops)++;
    if ((a - (i * (a / i)) == 0) && (b - (i * (b / i)) == 0)) {
      return i;
    }
  }
  return 1;
}
// int main() {
//   int n = -100;
//   int m = 2;
//   int ops;
//   int resultado = mdc1(n, m, &ops);
//   printf("O mdc entre %d é %d = %d\n",n,m, resultado);
//   printf("Este cálculo foi processado em %d vez(ez)\n", ops);
// }