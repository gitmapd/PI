#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{ int valor;
 struct nodo *prox;
}*LInt;

LInt procura(LInt l, int x) {
    LInt atual = l; 
    while (atual != NULL) {
        if (atual->valor == x) {
            return atual; // Return the address of the node found
        }
        atual = atual->prox; 
    }
    return NULL; 
}

int main() {
    // 1. Create a simple list: [10] -> [20] -> [30] -> NULL
    LInt n3 = (LInt)malloc(sizeof(struct nodo));
    n3->valor = 30;
    n3->prox = NULL;

    LInt n2 = (LInt)malloc(sizeof(struct nodo));
    n2->valor = 20;
    n2->prox = n3;

    LInt head = (LInt)malloc(sizeof(struct nodo));
    head->valor = 10;
    head->prox = n2;

    // 2. Apply the search
    int target = 20;
    LInt result = procura(head, target);

    // 3. Handle the result
    if (result != NULL) {
        printf("Found value %d at address %p\n", result->valor, (void*)result);
    } else {
        printf("Value %d not found in the list.\n", target);
    }

    // Cleanup (Free memory)
    free(head); free(n2); free(n3);

    return 0;
}