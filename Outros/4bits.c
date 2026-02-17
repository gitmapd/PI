#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void separar_em_4_bits(char *bits) {

  int total_bits = strlen(bits);
  char buffer[5]; // Espaço para 4 bits + '\0'

  for (int i = 0; i < total_bits; i += 4) {

    // 1. Copiamos 4 bits para o buffer temporário
    for (int j = 0; j < 4; j++) {
      // Verificamos se ainda há bits para ler (segurança)
      if (i + j < total_bits) {
        buffer[j] = bits[i + j];
      }
    }
    buffer[4] = '\0'; // Fechamos o mini-buffer

    // 2. Aqui fazes o que quiseres com o grupo de 4
    printf("Grupo: %s\n", buffer);

    // Exemplo: Se quiseres converter para Decimal (0-15)
    int valor = 0;
    for (int k = 0; k < 4; k++) {
      if (buffer[k] == '1') {
        valor += (1 << (3 - k)); // Pesos: 8, 4, 2, 1
      }
    }
    printf("Valor: %d\n", valor);
  }
}
int main() {
  char *bits = "111101000101";
  separar_em_4_bits(bits);
}