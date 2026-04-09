#include <stdio.h>

typedef struct dinStack {
int size; // guarda o tamanho do array values
int sp;
int *values;
} *DStack;

typedef struct dinQueue {
int size; // guarda o tamanho do array values
int front;
int length;
int *values;
} *DQueue;

int push(DStack s, int x) {
    if(s->sp == s->size) {
        int newSize = s->size * 2;
        int *newValues = malloc(newSize * sizeof(int));
        if(newValues == NULL) return 1;
        for(int i = 0; i< s->size; i++) {
            newValues[i] = s->values[i];
        }
    free(s->values);
    s->values = newValues;
    s->size = newSize;
    }
    s->values[s->sp++] = x;
    return 0;
}

int push(DQueue q, int x) {
    if(q-> length == q->size) {
        int newSize = q->size * 2;
        int *newValues = malloc(newSize * sizeof(int));
        if(newValues == NULL) return 1;
        for(int i = 0; i< q->length; i++) {
            int posAntiga = (q->front + i) % q->size;
            newValues[i] = q->values[posAntiga];
        }
    free(q->values);
    q->values = newValues;
    q->size = newSize;
    q->front = 0;
    }
    int tail = (q->front + q->length) % q->size;
    q->values[tail] = x;
    q->length++;
    return 0;
}

int pop(DStack s, int *x) {
    if (s->sp == 0) return 1; // Stack Underflow
    
    s->sp--;              // Desce o ponteiro para o elemento real
    *x = s->values[s->sp]; // "Entrega" o valor para a variável x
    return 0;
}
int main() {

}