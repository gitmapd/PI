#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Função para verificar se um número é primo
bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    // Testamos divisores de 6k ± 1 para maior velocidade
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    long inicio = 2045644;
    long fim = 2145677;
    int contador = 0;

    for(long i = inicio; i <=fim;i++) {
        if(is_prime(i))
        contador++;
    }
    printf("Total de números primos encontrados: %d\n", contador);
    return 0;
}