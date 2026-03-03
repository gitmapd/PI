#include <math.h>
#include <stdio.h>


int soma_divisores(int n) {
    if (n < 1) return 0;
    int soma = 0;
    for(int i = 1; i*i <=n;i++) {
            if(n % i == 0) {
                soma += i;
                if(i * i != n) {
                    soma+= (n/i);
                }

            }
    }
    return soma - n;
}
void fib4(int n) {
int a=0, b=1, aux, conta=0;
int n_original = n;
int parcelas[32];
int current_slot = 0;
int evens = 0, odds = 0;
for(; n >0; n--) {
    if(a % 2 == 0) evens++;
    else odds++;
    int s = soma_divisores(a);
    if(a > 0 && s>a) {
    printf("Value %d is Abundant (Sum of proper divisors: %d)\n", a, s);
    conta++;
    }
    aux = a;
    a=b;
    b = (b+aux) % 10000;

}
printf("Parity: %d Evens, %d Odds\n", evens, odds);
printf("Total abundant numbers found: %d\n", conta);
}


int main() {
int n = 80;
fib4(n);
return 0;
}