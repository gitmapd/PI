#include <stdio.h>

typedef struct {
    int x, y;
} Posicao;

Posicao nesimo(Posicao a[], int N) {
    int i,j;
    Posicao temp;
    long dist1,dist2;

    for(i = 0; i < N - 1;i++) {
        for(j = 0; j < N -i -1;j++) {
            dist1 = (long)a[j].x * a[j].x + (long)a[j].y * a[j].y;
            dist2 = (long)a[j+1].x * a[j+1].x + (long)a[j+1].y * a[j+1].y;
            if(dist1 > dist2) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    return a[2]; 
}
int main() {

    Posicao pontos[] = {
    {4, 3},   // Ponto 0: x=4, y=3
    {3, 2},   // Ponto 1: x=3, y=2
    {0, 1},   // Ponto 2: x=0, y=1
    {1, 1}    // Ponto 3: x=1, y=1
};
int N = 4;

Posicao resultado = nesimo(pontos, N);

printf("{%d, %d}\n", resultado.x, resultado.y);

}