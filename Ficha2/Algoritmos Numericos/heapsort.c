#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Sua função de barras, agora com suporte a destacar o Pai e os Filhos
void printBars(int *arr, int n, int pai, int filho, int tamanho_atual) {
    printf("\033[H\033[J\n === HEAP SORT VISUAL === \n\n");
    for (int i = 0; i < n; i++) {
        if (i == pai || i == filho) printf("\033[1;33m"); // Amarelo: Comparando
        else if (i >= tamanho_atual) printf("\033[1;32m"); // Verde: Já ordenado no fim
        else printf("\033[0m");

        printf(" %2d |", arr[i]);
        for (int j = 0; j < arr[i]; j++) printf("🟩");
        printf("\033[0m\n");
    }
    usleep(250000);
}

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Transforma uma sub-árvore em um "Max-Heap" (Pai maior que os filhos)
void heapify(int *arr, int n, int i, int tamanho_total) {
    int maior = i; 
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    // Visualizamos a comparação com o filho da esquerda
    if (esquerda < n) {
        printBars(arr, tamanho_total, i, esquerda, n);
        if (arr[esquerda] > arr[maior]) maior = esquerda;
    }

    // Visualizamos a comparação com o filho da direita
    if (direita < n) {
        printBars(arr, tamanho_total, i, direita, n);
        if (arr[direita] > arr[maior]) maior = direita;
    }

    if (maior != i) {
        trocar(&arr[i], &arr[maior]);
        // Recursão para garantir que o elemento trocado não quebre o heap abaixo
        heapify(arr, n, maior, tamanho_total);
    }
}

void heapSort(int *arr, int n) {
    // Passo 1: Construir o Heap (Organizar a bagunça inicial)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, n);

    // Passo 2: Extrair um por um do topo do heap
    for (int i = n - 1; i > 0; i--) {
        // O maior está sempre no topo (arr[0]). Jogamos ele para o fim (o "muro verde")
        trocar(&arr[0], &arr[i]);
        
        // Chamamos o heapify no heap reduzido (i)
        heapify(arr, i, 0, n);
    }
}

int main() {
    int arr[] = {4, 10, 3, 5, 1, 8, 7};
    int n = 7;
    
    heapSort(arr, n);
    printBars(arr, n, -1, -1, 0); // Foto final
    printf("\n Heap Sort Completo!\n");
    
    return 0;
}