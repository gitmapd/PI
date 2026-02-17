#include <stdio.h>
#include <string.h>

typedef struct {
  char *codigo;
  int valor;
  char *simbolo;
} CodigoRomano;


CodigoRomano tabela[] = {{"01", 1, "I"},    {"100", 5, "V"},
                         {"00", 10, "X"},   {"101", 50, "L"},
                         {"110", 100, "C"}, {"111", 500, "D"}};

#define NUM_SIMBOLOS 6
void descodificar_binario_romano(char *sequencia) {
  printf("Input: %s\n", sequencia);

  char buffer[10] = ""; 
  int total = 0;
  for (int j = 0; sequencia[j] != '\0'; j++) {
    int len = strlen(buffer);
    buffer[len] = sequencia[j];
    buffer[len + 1] = '\0';
    for (int k = 0; k < NUM_SIMBOLOS; k++) {
      if (strcmp(buffer, tabela[k].codigo) == 0) {
        printf("%s ", tabela[k].simbolo);
        total += tabela[k].valor;
        buffer[0] = '\0';
        break;
      }
    }
  }
  printf("\nResultado Final: %d\n\n", total);
}

int main() {
  descodificar_binario_romano("111101000101");
  return 0;
}
