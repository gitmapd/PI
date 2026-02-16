#include <stdio.h>
#include <string.h>
typedef struct {
  char *codigo;
  char *simbolo;
} CodigoRomano;
CodigoRomano tabela[] = {{"0", "A"},
                         {"10", "B"}};

void descodificar_binario_romano(char *sequencia) {
  printf("--- Descodificador Automático (Exerc 2.1) ---\n");
  printf("Input: %s\n", sequencia);

  char buffer[10] = ""; // Armazena temporariamente os bits lidos
  int total = 0;
  for (int j = 0; sequencia[j] != '\0'; j++) {
    int len = strlen(buffer);
    buffer[len] = sequencia[j];
    buffer[len + 1] = '\0';
    for (int k = 0; k < 2; k++) {
      if (strcmp(buffer,tabela[k].codigo) == 0) {
        printf("%s",tabela[k].simbolo);
        buffer[0] = '\0';
        break;
      }
    }
  }
  printf("\nResultado Final: %d\n\n", total);
}
int main() {
  char str[] = "Hello";
  printf("Length: %zu\n", strlen(str)); // Output: 5

  descodificar_binario_romano("10010");
  return 0;
}