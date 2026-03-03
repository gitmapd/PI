#include <stdio.h>
#include <stdlib.h>


typedef struct  {
int* hashmap[10000];
int hashmap_sizes[10000];
} DivisorMap;
// Global HashMap: index is the Fibonacci number, value is an array of divisors


// Function to calculate sum of proper divisors and store them in the HashMap
int map_and_sum_divisors(int n, DivisorMap* map) {
    if (n <= 1) return 0;
    
    // 1. If we already mapped this number, just return the sum from the map
    if (map->hashmap[n] != NULL) {
        int existing_sum = 0;
        for (int i = 0; i < map->hashmap_sizes[n]; i++) {
            existing_sum += map->hashmap[n][i];
        }
        return existing_sum;
    }

    // 2. Count divisors to know how much memory to allocate
    int count = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) count++;
    }

    // 3. Allocate memory and store in HashMap
    map->hashmap[n] = (int*)malloc(count * sizeof(int));
    map->hashmap_sizes[n] = count;

    int current_sum = 0;
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            map->hashmap[n][index++] = i;
            current_sum += i;
        }
    }
    return current_sum;
}

void fib_analyzer(int n) {
    DivisorMap map = { {NULL}, {0} };
    int n_original = n;
    int a = 0, b = 1, aux;
    int abundant_count = 0;
    int evens = 0, odds = 0;
    int parcelas[95]; // To store the abundant values found

    printf("--- Starting Fibonacci Analysis (n=%d) ---\n\n", n);

    for (; n > 0; n--) {
        // 1. Track Parity (Even/Odd)
        if (a % 2 == 0) evens++;
        else odds++;

        // 2. Check Abundance using the HashMap logic
        int s = map_and_sum_divisors(a,&map);
        if (a > 0 && s > a) {
            parcelas[abundant_count] = a;
            
            printf("Found Abundant: %d | Sum: %d | Divisors: { ", a, s);
            for (int i = 0; i < map.hashmap_sizes[a]; i++) {
                printf("%d%s", map.hashmap[a][i], (i == map.hashmap_sizes[a] - 1) ? "" : ", ");
            }
            printf(" }\n");
            
            abundant_count++;
        }

        // 3. Fibonacci Step
        aux = a;
        a = b;
        b = (b + aux) % 10000;
    }

    // Summary
    printf("\n--- Final Report ---\n");
    printf("Total Terms: %d\n", n_original);
    printf("Parity: %d Evens, %d Odds\n", evens, odds);
    printf("Total Abundant Numbers Stored in Parcels: %d\n", abundant_count);

    // 4. Memory Cleanup (Freeing the HashMap)
    for (int i = 0; i < 10000; i++) {
        if (map.hashmap[i] != NULL) {
            free(map.hashmap[i]);
        }
    }
}

int main() {
    fib_analyzer(80);
    return 0;
}