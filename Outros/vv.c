#include <stdio.h>
#include <limits.h>

void min_max(int *array, int tam, int *min, int *max) {
*min = INT_MAX;
*max = INT_MIN;

for(int i = 0; i < tam; i++) {
    if(array[i] < *min) {
        *min = array[i];
    }
}

for(int i = 0; i < tam; i++) {
    if(array[i] > *max) {
        *max = array[i];
    }
}
}
void troca_valores(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b; 
    *b = temp;
}

int main() {
    int x = 10;
    int y = 20;

    printf("Antes da troca: x = %d, y = %d\n", x, y);


    troca_valores(&x, &y);

    printf("Depois da troca: x = %d, y = %d\n", x, y);

    int tamanho = 7;
    int valores[] = {15, 3, 42, 8, 21, 1, 99};
    int menor, maior;

    min_max(valores, tamanho, &menor, &maior);

    printf("Menor valor encontrado: %d\n", menor);
    printf("Maior valor encontrado: %d\n", maior);
    return 0;
}
