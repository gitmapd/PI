#include <stdio.h>
#include <unistd.h>

typedef struct {
  int *data;
  int total;
} DataList;

void trocar(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printBars(DataList *list, int idx1, int idx2, int troca, int maxIdx) {
  printf("\033[H\033[J");

  for (int i = 0; i < list->total; i++) {
    // 1. Escolha da cor
    if (i == maxIdx) {
      printf("\033[1;34m"); // AZUL
    } else if (i == idx1 || i == idx2) {
      if (troca)
        printf("\033[1;31m"); // VERMELHO
      else
        printf("\033[1;33m"); // AMARELO
    } else {
      printf("\033[0m"); // NORMAL
    }

    // 2. Imprimir o número e a barra
    printf(" %2d | ", list->data[i]);

    for (int j = 0; j < list->data[i]; j++) {
      // Usamos um caractere de texto em vez de emoji para garantir a cor
      printf("🟩");
    }

    // 3. Reset da cor no fim da linha
    printf("\033[0m\n");
  }
  usleep(200000);
}
void bubblesort(DataList *list) {
  for (int i = 0; i < list->total - 1; i++) {
    for (int j = 0; j < list->total - i - 1; j++) {

      // Localizar o índice do maior elemento a cada passo
      int currentMax = 0;
      for (int k = 1; k < list->total; k++) {
        if (list->data[k] > list->data[currentMax])
          currentMax = k;
      }

      printBars(list, j, j + 1, 0, currentMax);

      if (list->data[j] > list->data[j + 1]) {
        printBars(list, j, j + 1, 1, currentMax);
        trocar(&list->data[j], &list->data[j + 1]);
        printBars(list, j, j + 1, 1, currentMax);
      }
    }
  }
}

int main() {
  int arr[] = {2, 7, 1, 4, 5, 6, 9, 3};
  DataList list = {arr, sizeof(arr) / sizeof(arr[0])};

  bubblesort(&list);
  return 0;
}