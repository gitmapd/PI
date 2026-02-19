#include <math.h>
#include <stdio.h>
void print_bin(int n, int total_bits) {
  for (int i = total_bits - 1; i >= 0; i--) {
    int bit = (n >> i) & 1;
    printf("%u", bit);
    if (i % 4 == 0 && i != 0)
      printf(" ");
  }
  printf("\n");
}
float multInt2(int n, float m, int *ops, int *iteracoes) {
  int n_original = n;
    float m_original = m;
  float parcelas[32];
  float r = 0;
  *iteracoes = 0;
  *ops = 0;
  int p = 0;
  while (n > 0) {
    if (n & 1) {
      parcelas[p++]=m;
      r = r + m;
      (*ops)++;
    }
    n >>= 1;
    m *= 2;
    (*iteracoes)++;
  }
  for(int i = 0 ; i < p; i++) {
    printf("%0.f",parcelas[i]);
    if(i < p - 1) printf(" + ");
  }
  // 3. Impressão do resultado e da expressão original na mesma linha
    printf(" = %.0f = %d * %.0f.\n", r, n_original, m_original);
  return r;
}

int main() {
  int n = 81;
  float m = 423.0;
  int total_bits = (int)log2(n) + 1;
  print_bin(n, total_bits);
  int contador_somas;
  int conta_ciclos;
  float resultado = multInt2(n, m, &contador_somas, &conta_ciclos);
  printf("Multiplicando %d por %.2f:\n", n, m);
  printf("------------------------------\n");
  printf("Resultado Final: %.2f\n", resultado);
  printf("Somas realizadas: %d\n", contador_somas);
  printf("Ciclos: %d\n", conta_ciclos);
  return 0;
}