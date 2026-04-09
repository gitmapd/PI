#include <stdio.h>

#define Max 100

typedef struct staticStack {
  int sp;
  int values[Max];
} STACK, *SStack;

typedef struct staticQueue {
int front;
int length;
int values [Max];
} QUEUE, *SQueue;

//LIFO
void SinitStack(SStack s) { s->sp = 0; }

int SisEmpty(SStack s) {
    return (s->sp == 0);
}

int Spush(SStack s, int x) {
    if(s->sp == Max) return 1;
    s->values[s->sp] = x;
    s->sp++;
    return 0;
}

int Spop(SStack s, int *x) {
    if (s->sp == 0) return 1; // Stack Underflow
    
    s->sp--;              // Desce o ponteiro para o elemento real
    *x = s->values[s->sp]; // "Entrega" o valor para a variável x
    return 0;
}

int Stop(SStack s, int *x) {
    if (s->sp == 0) return 1; // Stack Underflow

    *x = s->values[s->sp - 1]; // "Entrega" o valor para a variável x
    return 0;
}


//FIFO
void SinitQueue(SQueue q) { q->front = 0; q->length = 0; }

int SisEmptyQ(SQueue q) {
     return (q->length == 0);
}

int Senqueue(SQueue q, int x) {
     if(q->length == Max) return 1;
     int pos = (q->front + q->length) % Max;
     q->values[pos] = x;
     q->length++;
     return 0;
}

int Sdequeue(SQueue q, int *x) {
     if(q->length == 0) return 1;
     *x = q->values[q->front];
     q->front = (q->front + +1) % Max;
     q->length--;
     return 0;
}
/int Sfront (SQueue q, int *x) {
    if (q->length == 0) return 1;

    *x = q->values[q->front]; // Apenas copia, não mexe em nada
    return 0;
}
int main() {
    // STACK minhaPilha; // Criamos uma pilha real
    // int guardado;
    // // Antes de inicializar, o sp tem "lixo" (um número qualquer)
    // printf("Antes de inicializar, sp = %d\n", minhaPilha.sp);
    
    // // Chamamos a função passando o ENDEREÇO da pilha (&)
    // // Nota: &minhaPilha transforma STACK em SStack (ponteiro)
    // SinitStack(&minhaPilha);
    
    // // Agora verificamos se o sp passou a ser 0
    // printf("Depois de inicializar, sp = %d\n", minhaPilha.sp);
    
    // if (minhaPilha.sp == 0) {
    //     printf("Sucesso! A pilha foi inicializada.\n");
    // }
    // printf("Pilha vazia? %d\n", SisEmpty(&minhaPilha));

    // Spush(&minhaPilha, 10); // Passo 2: Inserir o 10
    // Spush(&minhaPilha, 20); // Passo 3: Inserir o 20
    
    // printf("Agora o sp e: %d\n", minhaPilha.sp); // Deve ser 2
    
    // if (Spop(&minhaPilha, &guardado) == 0) {
    //     printf("Tirei o numero: %d\n", guardado);
    // }


    QUEUE minhaFila; // Criamos uma pilha real
    int guardado;
    // Antes de inicializar, o sp tem "lixo" (um número qualquer)
    printf("Antes de inicializar, front = %d e length = %d\n", minhaFila.front,minhaFila.length);
    
    // Chamamos a função passando o ENDEREÇO da pilha (&)
    // Nota: &minhaPilha transforma STACK em SStack (ponteiro)
    // SinitStack(&minhaPilha);
    
    // // Agora verificamos se o sp passou a ser 0
    // printf("Depois de inicializar, sp = %d\n", minhaPilha.sp);
    
    // if (minhaFila.front == 0) {
    //      printf("Sucesso! A pilha foi inicializada.\n");
    //  }
    printf("Fila vazia? %d\n", SisEmptyQ(&minhaFila));

    // Spush(&minhaPilha, 10); // Passo 2: Inserir o 10
    // Spush(&minhaPilha, 20); // Passo 3: Inserir o 20
    
    //printf("Agora o sp e: %d\n", minhaPilha.sp); // Deve ser 2
    
    // if (Spop(&minhaPilha, &guardado) == 0) {
    //     printf("Tirei o numero: %d\n", guardado);
    // }
    return 0;
}