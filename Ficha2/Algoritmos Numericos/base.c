#include <stdio.h>

// O parâmetro 'int rastro[]' é o mesmo que 'int *rastro'
void calcular_potencia(int base, int expoente, int *rastro,
                       int *tamanho_rastro) {
  int resultado = 1;
  *tamanho_rastro = 0;
  for (int i = 0; i < expoente; i++) {
    resultado *= base;
    rastro[(*tamanho_rastro)++] = base;
  }
}

int main() {
  int n_passos;
  int r[10];
  int base = 2, exp = 2;
  calcular_potencia(base, exp, r, &n_passos);
  printf("%d^%d = ", base, exp);
  for (int i = n_passos - 1; i >= 0; i--) {
    printf("%d", r[i]);

    if (i > 0) {
      printf(
          " * "); // Só imprime se NÃO for o último elemento do rastro invertido
    }
  }
  return 0;
}