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

void descodificar_binario_romano(char *sequencia) {
  printf("--- Descodificador Automático (Exerc 2.1) ---\n");
  printf("Input: %s\n", sequencia);

  char buffer[10] = ""; // Armazena temporariamente os bits lidos
  int total = 0;
  int i = 0;
  for (int j = 0; sequencia[j] != '\0'; j++) {
    int len = strlen(buffer);
    buffer[len] = sequencia[j];
    buffer[len + 1] = '\0';
    for (int k = 0; k < 6; k++) {
      if (strcmp(buffer,tabela[k].codigo) == 0) {
        printf("%s",tabela[k].simbolo);
        total += tabela[k].valor;
        buffer[0] = '\0';
        break;
      }
    }
  }
  printf("\nResultado Final: %d\n\n", total);
}