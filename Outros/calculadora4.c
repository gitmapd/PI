#include <stdio.h>


int soma(int a, int b) {
    return a + b;
}

int subtrai(int a, int b) {
    return a - b;
}

int multiplica(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        printf("Erro: Divisao por zero!\n");
        return 0;
    }
    return a / b;
}


int ler_inteiro(void) {
    int a;
    printf("Introduza um numero inteiro: ");
    scanf("%d", &a);
    return a;
}

char ler_operacao(void) {
    char op;
    printf("Introduza a operacao (+, -, *, /) ou 'q' para sair: ");
    scanf(" %c", &op);
    return op;
}


int calcula(int a, int b, char op) {
    int r;
    if (op == '+') {
        r = soma(a, b);
    } else if (op == '-') {
        r = subtrai(a, b);
    } else if (op == '*') {
        r = multiplica(a, b);
    } else if (op == '/') {
        r = divide(a, b);
    } else {
        r = 0; 
    }
    return r;
}


int main(void) {
    int a, b, r;
    char op;

    while (1) {
        op = ler_operacao();

        if (op == 'q') {
            printf("A sair...\n");
            break; 
        }


        a = ler_inteiro();
        b = ler_inteiro();

        r = calcula(a, b, op);
        
        if (op == '+' || op == '-' || op == '*' || op == '/') {
            printf("Resultado: %d\n\n", r);
        } else {
            printf("Operacao invalida!\n\n");
        }
    }

    return 0;
}