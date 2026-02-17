#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "definicoes.h"

int main() {
    unsigned long  int text = 3700 * 32 * 2;
    unsigned long int photos = 50 * (1.2 * MiB);
    float total = text + photos;
    printf("%.1f",total);
    
    printf("--- Exerc. 2.2 ---\n");
    int ascii_codes[] = {0b1010101, 0b0101110, 0b0100000, 0b1001101, 0b1101001, 0b1101110, 0b1101000, 0b1101111};
    total = sizeof(ascii_codes)/sizeof(ascii_codes[0]);
    printf("Decoded ASCII string: ");
    for(int i = 0; i < total; i++) {
        printf("%c", (char)ascii_codes[i]);
    }
    printf("\n\n");
}