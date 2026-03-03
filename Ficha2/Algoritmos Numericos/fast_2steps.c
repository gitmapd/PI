#include <stdio.h>
#include <stdlib.h>

// Replicating miniteste.h structure
typedef struct nodo {
  int valor;
  struct nodo *prox;
} * LInt;

LInt build_list(int n) {
  LInt head = NULL;
  LInt temp = NULL;
  for (int i = n; i >= 0; i--) {
    LInt new_node = (LInt)malloc(sizeof(struct nodo));
    new_node->valor = i;
    new_node->prox = head;
    head = new_node;
  }
  return head;
}

void print_lista(LInt l) {
  LInt atual = l; // Use a temporary pointer so we don't lose the head

  printf("List: ");
  while (atual != NULL) {
    printf("[%d]->", atual->valor);
    atual = atual->prox;
  }
  printf("NULL\n");
}
LInt procura(LInt l) {
    LInt fast = l;
    LInt slow = l;

    while (fast != NULL && fast->prox != NULL) {
        slow = slow->prox;
        fast = fast->prox->prox;
    }

    return slow;
}
int main() {
    LInt my_list = build_list(15);

    //print_lista(my_list);

    printf("Testing with a list of 15 nodes...\n");

    // 2. Run your search
    LInt result = procura(my_list);
    
    // 4. Cleanup memory
    LInt current = my_list;
    while (current != NULL) {
        LInt next = current->prox;
        free(current);
        current = next;
    }

    return 0;
}