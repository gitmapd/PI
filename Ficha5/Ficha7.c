#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
char *palavra;
int ocorr;
struct celula * prox;
} * Palavras;

void libertaLista(Palavras l) {
    Palavras temp;
    while (l != NULL) {
        temp = l;
        l = l->prox;
        free(temp->palavra); // Liberta a string
        free(temp);          // Liberta a célula
    }
}

int quantasP(Palavras l) {
    int contador = 0;
    while (l != NULL) {
        contador++;
        l = l->prox;
    }
    return contador;
}
void listaPal(Palavras l) {
    while (l != NULL) {
        printf("%s %d\n", l->palavra, l->ocorr);
        l = l->prox;
    }
}
char* ultima(Palavras l) {
    if (l == NULL) return NULL;
    while (l->prox != NULL) {
        l = l->prox;
    }
    return l->palavra;
}
Palavras acrescentaInicio(Palavras l, char *p) {
    Palavras novo = malloc(sizeof(struct celula));
    novo->palavra = strdup(p);
    novo->ocorr = 1;
    novo->prox = l;
    return novo;
}
Palavras acrescentaFim(Palavras l, char *p) {
    Palavras novo = malloc(sizeof(struct celula));
    novo->palavra = strdup(p);
    novo->ocorr = 1;
    novo->prox = NULL;

    if (l == NULL) return novo;

    Palavras temp = l;
    while (temp->prox != NULL) temp = temp->prox;
    temp->prox = novo;
    return l;
}
Palavras acrescenta(Palavras l, char *p) {
    Palavras ant = NULL, atual = l;

    // Procura a posição ou a palavra
    while (atual != NULL && strcmp(atual->palavra, p) < 0) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual != NULL && strcmp(atual->palavra, p) == 0) {
        atual->ocorr++; // Palavra já existe
    } else {
        // Inserção de nova célula ordenadamente
        Palavras novo = malloc(sizeof(struct celula));
        novo->palavra = strdup(p);
        novo->ocorr = 1;
        novo->prox = atual;
        if (ant == NULL) l = novo;
        else ant->prox = novo;
    }
    return l;
}
struct celula maisFreq(Palavras l) {
    struct celula max;
    max.ocorr = 0;
    max.palavra = NULL;

    while (l != NULL) {
        if (l->ocorr > max.ocorr) {
            max = *l; // Copia os dados da célula
        }
        l = l->prox;
    }
    return max;
}
