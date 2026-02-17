#ifndef MDC_H
#define MDC_H

/* Protótipo da função mdc1: Força Bruta.
   Recebe dois inteiros e um ponteiro para contar as operações.
*/
int mdc1(int a, int b, int *ops);

/* Protótipo da função mdc2: Algoritmo de Euclides por subtrações.
   Recebe dois inteiros e um ponteiro para contar as iterações.
*/
int mdc2(int a, int b, int *ops, int *somas_a, int *somas_b);

/* Protótipo da função mdc_mod: Algoritmo de Euclides (Versão Otimizada).
   Utiliza o operador de resto (%) para reduzir drasticamente o número de iterações.
   Recebe dois inteiros e um ponteiro para contar as iterações.
*/
int mdc_mod(int a, int b, int *ops);

#endif