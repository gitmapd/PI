#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void calcular_valor(char *bits, int e_bits, int f_bits) {
    int s = bits[0] - '0';
    
    // 1. Converter bits do expoente para decimal (e)
    int e_decimal = 0;
    for (int i = 0; i < e_bits; i++) {
        if (bits[1 + i] == '1')
            e_decimal += pow(2, e_bits - 1 - i);
    }
// 2. Converter bits da fração para valor decimal (f)
    double f_decimal = 0.0;
    for (int i = 0; i < f_bits; i++) {
        if (bits[1 + e_bits + i] == '1')
            f_decimal += pow(2, -(i + 1));
    }
    
    int bias = pow(2, e_bits - 1) - 1;
    int e_max = pow(2, e_bits) - 1;
    double valor = 0.0;

    // 3. Lógica de Decisão (Normal, Subnormal, Especial)
    if (e_decimal == e_max) {
        if (f_decimal == 0) printf("%s: %s\n", bits, s ? "-Infinity" : "+Infinity");
        else printf("%s: NaN\n", bits);
        return;
    } 
    
    if (e_decimal == 0) {
        // Subnormal
        if (f_decimal == 0) {
            printf("%s: %s0.0\n", bits, s ? "-" : "");
        } else {
            valor = pow(-1, s) * f_decimal * pow(2, 1 - bias);
            printf("%s: %.10g\n", bits, valor);
        }
    } else {
        // Normal
        valor = pow(-1, s) * (1.0 + f_decimal) * pow(2, e_decimal - bias);
        printf("%s: %.10g\n", bits, valor);
    }
}
// Função para gerar todos os padrões possíveis (Recursiva)
void gerar_todos(char *padrao, int pos, int total, int e_bits, int f_bits) {
    if (pos == total) {
        padrao[total] = '\0';
        calcular_valor(padrao, e_bits, f_bits);
        return;
    }
    padrao[pos] = '0'; gerar_todos(padrao, pos + 1, total, e_bits, f_bits);
    padrao[pos] = '1'; gerar_todos(padrao, pos + 1, total, e_bits, f_bits);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s [bit_pattern] <e_bits> <f_bits>\n", argv[0]);
        return 1;
    }

    if (argc == 3) { // Sem padrão: listar todos
        int e = atoi(argv[1]);
        int f = atoi(argv[2]);
        char *buffer = malloc(1 + e + f + 1);
        gerar_todos(buffer, 0, 1 + e + f, e, f);
        free(buffer);
    } else { // Com padrão específico
        calcular_valor(argv[1], atoi(argv[2]), atoi(argv[3]));
    }

    return 0;
}