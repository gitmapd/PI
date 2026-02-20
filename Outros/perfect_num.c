#include <stdio.h>
#include <math.h>

int find_per(int n) {
    int sum = 1;
    int sqrtN = sqrt(n);
    for(int i = 2; i <= sqrtN;i++) {
        if (n % i == 0)
        {
            sum += i;
            if (i != n / i)
            sum += n / i;
        }

    }
}

int main() {
    int res = find_per(28);
    printf("%d",res);
}