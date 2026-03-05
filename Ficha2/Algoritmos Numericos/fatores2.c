#include <stdio.h>

// Função que extrai dígitos, guarda no array, soma e divide por 3 repetidamente
int processarPor3(long long *n, int digitos[], int *tamanho) {
    int p = 0;
    int soma = 0;

    long long temp = *n;

    // Primeiro, divide por 3 enquanto possível
    while (temp % 3 == 0) {
        temp /= 3;
    }

    // Guarda os dígitos do número resultante
    long long temp2 = temp;
    while (temp2 > 0) {
        int d = temp2 % 10;
        digitos[p++] = d;
        soma += d;
        temp2 /= 10;
    }

    *tamanho = p;

    // Atualiza n para o valor final após dividir por 3
    *n = temp;

    // Retorna 1 se o número original era divisível por 3 pelo menos uma vez
    return (soma % 3 == 0);
}

int main() {
    long long numero = 4700559;
    int digitos[20];
    int quantidade;

    int resultado = processarPor3(&numero, digitos, &quantidade);

    printf("Número final após dividir por 3: %lld\n", numero);

    printf("Dígitos guardados: ");
    for (int i = quantidade - 1; i >= 0; i--) {
        printf("%d ", digitos[i]);
    }

    if (resultado)
        printf("\nSoma dos dígitos do número final é divisível por 3\n");
    else
        printf("\nSoma dos dígitos do número final não é divisível por 3\n");

    return 0;
}