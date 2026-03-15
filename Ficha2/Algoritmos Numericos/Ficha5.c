#include <stdio.h>
#include <string.h>

typedef struct aluno {
  int numero;
  char nome[100];
  int miniT[6];
  float teste;
} Aluno;

int nota(Aluno a) {
  float somaMT = 0;
  for (int i = 0; i < (sizeof(a.miniT)) / (sizeof(a.miniT[0])) - 1; i++) {
    somaMT += a.miniT[i];
  }
  float miniT20 = somaMT * 2.0;

  if (miniT20 < 8.0) {
    return 0; // Reprovado por nota mínima nos mini-testes
  }

  // 3. Cálculo da Nota Final (Frequência)
  // Mini-testes (20%): como a soma dá 10, 20% de 20 valores = 4 valores max.
  // Logo: (soma / 10) * 4  OU simplesmente soma * 0.4
  // Teste (80%): nota do teste * 0.8
  float notaFrequencia = (somaMT * 0.4) + (a.teste * 0.8);

  // 4. Arredondamento e Verificação de Aprovação
  int resultado = (int)(notaFrequencia + 0.5);

  return (resultado >= 10) ? resultado : 0;
}

void ordenaPorNum(Aluno t[], int N) {
  int i, j, min_idx;
  for (int i = 0; i < N - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < N; j++) {
      if (t[j].numero < t[min_idx].numero) {
        min_idx = j;
      }
    }
    if (min_idx != i) {
      Aluno temp = t[i];
      t[i] = t[min_idx];
      t[min_idx] = temp;
    }
  }
}
void criaIndPorNum(Aluno t[], int N, int ind[]) {
  int i, j, k, min_idx;
  for (k = 0; k < N; k++) {
    ind[k] = k;
  }
  for (int i = 0; i < N - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < N; j++) {
      if (t[ind[j]].numero < t[ind[min_idx]].numero) {
        min_idx = j;
      }
    }
    int temp = ind[i];
    ind[i] = ind[min_idx];
    ind[min_idx] = temp;
  }
}
int procuraNum(int num, Aluno t[], int N) {
  int inicio = 0;
  int fim = N - 1;
  int meio;
  while (inicio <= fim) {
    meio = inicio + (fim - inicio) / 2;
    if (t[meio].numero == num) {
      return meio;
    }
    if (t[meio].numero < num) {
      inicio = meio + 1;
    } else {
      fim = meio - 1;
    }
  }
  return -1;
}

void criaIndPorNome(Aluno t[], int N, int ind[]) {
  int i, j, k, min_idx;
  for (k = 0; k < N; k++) {
    ind[k] = k;
  }
  for (int i = 0; i < N - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < N; j++) {
      if (strcmp(t[ind[j]].nome, t[ind[min_idx]].nome) < 0) {
        min_idx = j;
      }
    }
    int temp = ind[i];
    ind[i] = ind[min_idx];
    ind[min_idx] = temp;
  }
}

void imprimeTurma(int ind[], Aluno t[], int N) {
  for (int i = 0; i < N; i++) {
    int idx = ind[i];
    printf("Num: %d | Nome: %-20s | Nota: %d\n", t[idx].numero, t[idx].nome,
           nota(t[idx]));
  }
}
int main() {
  Aluno Turma1[7] = {{4444, "André", {2, 1, 0, 2, 2, 2}, 10.5},
                     {3333, "Paulo", {0, 0, 2, 2, 2, 1}, 8.7},
                     {8888, "Carla", {2, 1, 2, 1, 0, 1}, 14.5},
                     {2222, "Joana", {2, 0, 2, 1, 0, 2}, 3.5},
                     {7777, "Maria", {2, 2, 2, 2, 2, 1}, 5.5},
                     {6666, "Bruna", {2, 2, 2, 1, 0, 0}, 12.5},
                     {5555, "Diogo", {2, 2, 1, 1, 1, 0}, 8.5}};
  int ind[7];
  printf("--- Pauta da Turma 1 ---\n");
  for (int i = 0; i < 7; i++) {
    int n = nota(Turma1[i]);
    printf("Nº: %d | Nome: %-10s | Nota Final: %2d\n", Turma1[i].numero,
           Turma1[i].nome, n);
  }

  ordenaPorNum(Turma1, sizeof(Turma1) / sizeof(Turma1[0]));

  int pos = procuraNum(3333, Turma1, sizeof(Turma1) / sizeof(Turma1[0]));

  if (pos != -1) {
    // Se encontrou, 'pos' é o índice (ex: 0, 1, 2...)
    printf("Encontrado no indice: %d\n", pos);
    printf("Nome: %s\n", Turma1[pos].nome);
  } else {
    // Se não encontrou (pos == -1)
    printf("Aluno nao encontrado.\n");
  }
  criaIndPorNum(Turma1, 7, ind);

  printf("--- Alunos por Ordem de Numero ---\n");
  for (int i = 0; i < 7; i++) {
    // O i-ésimo aluno na ordem está na posição 'ind[i]' do array Turma1
    int idx = ind[i];
    printf("Posicao: %d | Numero: %d | Nome: %s\n", i, Turma1[idx].numero,
           Turma1[idx].nome);
  }

  criaIndPorNome(Turma1, 7, ind);

  printf("--- Alunos por Ordem de Nome ---\n");
  for (int i = 0; i < 7; i++) {
    // O i-ésimo aluno na ordem está na posição 'ind[i]' do array Turma1
    int idx = ind[i];
    printf("Posicao: %d | Numero: %d | Nome: %s | Nota: %d\n", i,
           Turma1[idx].numero, Turma1[idx].nome, nota(Turma1[idx]));
  }
  return 0;

  // imprimeTurma(ind,Turma1,7);
}