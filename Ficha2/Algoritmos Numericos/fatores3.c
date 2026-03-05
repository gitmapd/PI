#include <stdio.h>

// Função que calcula a soma e preenche o array
int calcularSomaEDigitos(long long n, int digitos[], int *tamanho) {
  int p = 0;
  int soma = 0;
  long long temp = n;

  while (temp > 0) {
    int d = temp % 10;
    digitos[p++] = d;
    soma += d;
    temp /= 10;
  }
  *tamanho = p;
  return soma;
}

int main() {
  long long n = 18802236;
  long long maior = -1;
  int digitos[20], tam;

  printf("Analisando o numero inicial: %lld\n", n);
  printf("------------------------------------------\n");
  // 1. Limpeza do fator 2
  while (n % 2 == 0) {
    maior = 2;
    n /= 2;
    printf("Dividido por 2 -> Novo valor: %lld\n", n);
  }
  //   // 2. Analise do fator 3 com soma de digitos
  printf("\nIniciando verificacao de divisibilidade por 3:\n");
  while (n > 0) {
    int soma = calcularSomaEDigitos(n, digitos, &tam);
    // printf("Numero atual: %lld | Soma dos digitos: %d", n, soma);

    printf("\n");
    printf("------------------------------------------\n");
    printf("Soma dos digitos (%lld) ", n);
    //printf(" = %d\n", soma);
    for (int i = tam - 1; i >= 0; i--) {
      printf("%d%s", digitos[i], (i == 0) ? "" : " + ");
    }
    printf(" = %d\n", soma);
    if (soma % 3 == 0) {
      printf(" (Divisivel por 3!)\n");
      maior = 3;
      n /= 3;
    } else {
      printf(" (NAO e divisivel por 3.)\n");
      break;
    }
  }

  //   // 3. Busca por outros fatores primos (5, 7, 11...)
    for (long long i = 5; i * i <= n; i += 6) {
      while (n % i == 0) {
        maior = i;
        n /= i;
      }
      while (n % (i + 2) == 0) {
        maior = i + 2;
        n /= i + 2;
      }
    }

    // 4. Captura o que sobrou
    if (n > 2) {
      maior = n;
  }

    printf("------------------------------------------\n");
    printf("MAIOR DIVISOR PRIMO FINAL: %lld\n", maior);

  return 0;
}