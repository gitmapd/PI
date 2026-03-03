#include <stdio.h>

int soma_divisores_e_print(int n) {
    if (n <= 1) return 0;
    int soma = 0;
    printf("Divisors of %d: ", n);
    
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            printf("%d, ", i);
            soma += i;
        }
    }
    printf("\nSum: %d ", soma);
    return soma;
}

void fib_abundante_acumulado(int n) {
    int n_original = n;
    int a = 0, b = 1, aux;
    int parcelas[32]; // To store the abundant Fibonacci numbers found
    int conta = 0;

    for (; n > 0; n--) {
        int s = 0;
        // Check for proper divisors sum
        for (int i = 1; i < a; i++) {
            if (a % i == 0) s += i;
        }

        if (a > 0 && s > a) {
            parcelas[conta] = a; // Accumulate the value in our parcel array
            
            printf("--- Found Abundant #%d ---\n", conta + 1);
            printf("Value: %d\n", parcelas[conta]);
            
            // Recalculate and print divisors nicely
            int final_sum = soma_divisores_e_print(a);
            printf("(Abundant because %d > %d)\n\n", final_sum, a);
            
            conta++;
        }

        // Fibonacci step
        aux = a;
        a = b;
        b = (b + aux) % 10000;
    }

    printf("Finished processing %d terms.\n", n_original);
    printf("Total parcels (Abundant numbers) stored: %d\n", conta);
}

int main() {
    fib_abundante_acumulado(95);
    return 0;
}