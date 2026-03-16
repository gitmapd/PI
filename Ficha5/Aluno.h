#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno {
  int numero;
  char nome[100];
  int miniT[6];
  float teste;
} Aluno;

int nota(Aluno a);

// Sorting & Indexing
void ordenaPorNum(Aluno t[], int N);
void criaIndPorNum(Aluno t[], int N, int ind[]);
void criaIndPorNome(Aluno t[], int N, int ind[]);

// Search & Print
int procuraNum(int num, Aluno t[], int N);
void imprimeTurma(int ind[], Aluno t[], int N);

#endif
