#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(long long n) {
    if (n <2) return false;
    for (long long i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void print_divisors(long long n) {
    for (long long i = 1; i*i <= n; i++) {
        if (n % i == 0){
            if (i == n) continue;
            printf("%lld",i);
            if(i != n / i && n / i != n) {
                printf("%lld ", n / i);
            }

        }
}
}
int main() {
    printf("%-10s | %-15s | %-s\n", "Perfect #", "Mersenne Prime", "Divisors");
    printf("------------------------------------------------------------\n");
    for (int p = 2; p <= 13; p++) {
        if (is_prime(p)) {
        long long mer_cand = pow(2,p) - 1;
        if (is_prime(mer_cand)) {
            long long perfec_num = pow(2,p-1) * mer_cand;
            printf("%-10lld | %-15lld\n", perfec_num,mer_cand);
            print_divisors(perfec_num);
            printf("\n");
        }
        }
    }
}