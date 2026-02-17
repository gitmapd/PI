#include "mdc.h"
#include <stdio.h>
#include <time.h>

void testar(int a, int b) {
  int o1, o2, o3;
  clock_t s, e;

  printf("### MDC(%d, %d) ###\n", a, b);

  s = clock();
  int r1 = mdc1(a, b, &o1);
  e = clock();
  printf("MDC1:   Res=%d | Ops=%-10d | Tempo=%.6fs\n", r1, o1,
         (double)(e - s) / CLOCKS_PER_SEC);

  s = clock();
  int r2 = mdc2(a, b, &o1, &o2, &o3);
  e = clock();
  printf("MDC2:   Res=%d | Ops=%-10d | Ops=%-10d Ops=%-10d |Tempo=%.6fs\n", r2,
         o1, o2, o3, (double)(e - s) / CLOCKS_PER_SEC);

  s = clock();
  int r2 = mdc2(a, b, &o1, &o2, &o3);
  e = clock();
  printf("MDC3:   Res=%d | Ops=%-10d | Ops=%-10d Ops=%-10d |Tempo=%.6fs\n", r2,
         o1, o2, o3, (double)(e - s) / CLOCKS_PER_SEC);
}

int main() {
  testar(2, 45);
  // testar(1000000, 3);    // O mdc1 vai sofrer aqui!
  // testar(1000000000, 7); // Diferença abismal entre mdc2 e mdc_mod
  return 0;
}