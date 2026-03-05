#include <stdio.h>


int main() {
long long n = 18802236;
long long maior = -1;
long parcelas[15];
long p = 0;
    // Remove fatores 2
    while (n % 2 == 0) {
        maior = 2;
        n /= 2;
    }
    parcelas[0] = n;
    while (n % 3 == 0) {
        parcelas[p++]=n % 10;
                n /= 3;
    }
    
for(long i = 0; i < 15; i++) {
    printf("%lld",parcelas[i]);
}

printf("%lld",n);
}