#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

// Simple comparison for qsort
int compare(const void *a, const void *b) {
    return (*(long long*)a - *(long long*)b);
}

bool is_prime(long long n) {
    if (n <=1) return false;
    if (n <=3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i+=6)
        if (n % i == 0 || n % (i+2)==0 ) return false;
    return true;
}

void print_divisors_pretty(long long n) {
    long long divs[2000]; // Array to hold divisors for sorting
    int count = 0;

    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i != n) divs[count++] = i;
            if (i != n / i && n / i != n) divs[count++] = n / i;
        }
    }

    // Sort them to make the list readable
    qsort(divs, count, sizeof(long long), compare);

    for (int i = 0; i < count; i++) {
        printf("%lld%s", divs[i], (i == count - 1 ? "" : ", "));
    }
}

int main() {
    printf("\n%-12s | %-12s | %-s\n", "Perfect Num", "M-Prime", "Proper Divisors List");
    printf("-------------|--------------|---------------------------------------\n");

    for (int p = 2; p <= 13; p++) {
        if (is_prime(p)) {
            long long m_prime = (long long)pow(2, p) - 1;
            if (is_prime(m_prime)) {
                long long perfect = (long long)pow(2, p - 1) * m_prime;
                
                printf("%-12lld | %-12lld | ", perfect, m_prime);
                print_divisors_pretty(perfect);
                printf("\n");
            }
        }
    }
    printf("-------------|--------------|---------------------------------------\n\n");
    return 0;
}