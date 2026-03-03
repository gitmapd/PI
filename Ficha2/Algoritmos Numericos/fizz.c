#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int valor;
  struct nodo *prox;
} * LInt;

void print_list(LInt l) {
  LInt atual = l;
  printf("List: ");
  while (atual != NULL) {
    printf("[%d]->", atual->valor);
    atual = atual->prox;
  }
  printf("NULL\n");
}
LInt build_list(int n) {
  LInt head = NULL;
  LInt temp = NULL;
  for (int i = n; i >= 0; i--) {
    LInt new_node = (LInt)malloc(sizeof(struct nodo));
    if (i % 3 == 0 && i % 5 == 0) {
      new_node->valor = -15;
    } else if (i % 3 == 0) {
      new_node->valor = -3;
    } else if (i % 5 == 0) {
      new_node->valor = -5;
    } else {
      new_node->valor = i;
    }
    new_node->prox = head;
    head = new_node;
  }
  return head;
}

int distancia(LInt l) {
  int conta = 0;
  int FB = 0;
  LInt atual = l;
  while (atual != NULL) {
    if (atual->valor == -15) {
      if (!FB) {
        FB = 1;
        atual = atual->prox;
        continue;
      }
    }
    if (FB) {
        if(atual->valor == -5) {
      return conta;
        }
      conta++;
    }
    atual = atual->prox;

  }
  return -1;
}

  int main() {
    LInt lista = build_list(20);
    print_list(lista);
    int d = distancia(lista);
    
    if (d != -1) {
        printf("A distancia entre o primeiro FizzBuzz e o primeiro Buzz e: %d\n", d);
    } else {
        printf("Sequencia nao encontrada.\n");
    }
    return 0;
  }