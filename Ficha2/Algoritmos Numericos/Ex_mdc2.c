#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mdc.h"
int mdc2(int a, int b, int *ops, int *somas_a, int *somas_b) {
  *somas_a = 0;
  *somas_b = 0;
  *ops = 0;
  if(a == 0) return b;
  if(b == 0) return a;
  if (a < 0)
    a = -a;
  if (b < 0)
    b = -b;
  while (a > 0 && b > 0) {
    (*ops)++;
    if (a > b) {
      a = a - b;
      (*somas_a)++;
    } else {
      b = b - a;
      (*somas_b)++;
    }
  }
return (a==0)? b : a;
}
//   int main() {
//     int n = 126;
//     int m = 45;
//     int ops;
//     int somas_a;
//     int somas_b;
//     int resultado = mdc2(n, m, &ops,&somas_a,&somas_b);
//     printf("O mdc entre %d é %d = %d\n", n, m, resultado);
//     printf("Este cálculo foi processado em %d vez(ez)\n", ops);
//     printf("Somas \"a\" => %d\n", somas_a);
//     printf("Somas \"b\" => %d\n", somas_b);
//   }