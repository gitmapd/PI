#include <stdio.h> 
#include <stdlib.h> // Para a função abs()

void losango(int r) {
    for (int y = r; y >= -r; y--) {
        //int y = i - r; // Transforma o índice i em coordenada y (-r até r)
        
        // Para o y não ser negativo na conta de distância, usamos o valor absoluto
        int dist_y = (y < 0) ? -y : y; 

        for (int x = -r; x <= r; x++) {
            //int x = j - r; // Transforma o índice j em coordenada x (-r até r)
            int dist_x = (x < 0) ? -x : x;

            // Se a soma das distâncias for menor ou igual ao raio, temos o losango
            if (dist_x + dist_y <= r) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
void doisLosangos(int n, int r) {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            
            // Condição para o primeiro losango (centro no 0,0)
            int dist1 = abs(x - 0) + abs(y - 0);
            
            // Condição para o segundo losango (centro no n-1, n-1)
            int dist2 = abs(x - (n - 1)) + abs(y - (n - 1));
            
            if (dist1 <= r || dist2 <= r) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}