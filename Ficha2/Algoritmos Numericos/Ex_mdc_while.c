#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mdc_while(int a, int b, int *ops) {
  *ops = 0;
  if (a == 0) return b;
  if (b == 0)  return a;
  if (a < 0)
    a = -a;
  if (b < 0)
    b = -b;
  int menor = (a < b) ? a : b;
  while( b!=0){
    (*ops)++;
    int temp = b;
    b = a % b;
    a = temp;
    }
  return a;
}
int main() {
  int n = -100;
  int m = 2;
  int ops;
  int resultado = mdc_while(n, m, &ops);
  printf("O mdc entre %d é %d = %d\n",n,m, resultado);
  printf("Este cálculo foi processado em %d vez(ez)\n", ops);
}