#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mdc_while(int a, int b, int *ops) {
  *ops = 0;
  int restos[32];
  int p = 0;
  if (a == 0) return b;
  if (b == 0)  return a;
  if (a < 0)
    a = -a;
  if (b < 0)
    b = -b;
  int menor = (a < b) ? a : b;
  restos[p++] = a;
  while( b!=0){
    int resto = a % b;
    restos[p++] = b;
    if(resto == 0) {
      restos[p++] = 0;
    }
    // restos[p++] = a;
    // int temp = b;
    // b = a % b;
    // a = temp;

    a =  b;
    b = resto;
    (*ops)++;
    }
  printf("Passos do dividendo: ");
  for (int i = 0; i < p; i++) {
    printf("%d", restos[i]);
    if (i < p - 1) printf(" -> ");
  }
  //if(restos[p-1] != a) printf(" -> ");
  printf(" | %d \n", a);
  return a;
}
int main() {
  int n = 100;
  int m = 30;
  int ops;
  int resultado = mdc_while(n, m, &ops);
  printf("O mdc entre %d é %d = %d\n",n,m, resultado);
  printf("Este cálculo foi processado em %d vez(ez)\n", ops);
}