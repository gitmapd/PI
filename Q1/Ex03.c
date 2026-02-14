#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int main() {

  int numero;
  int maior_elem = INT_MIN;
  int seg_maior_elem = INT_MIN;

  printf("Introduza uma sequência e termina com 0:\n");

  if (scanf("%d", &numero) != 1) {
    printf("Erro a ler input.");
    return 1;
  }

  while (numero != 0) {
    if (numero > maior_elem) {
      seg_maior_elem = maior_elem;
      maior_elem = numero;
    } 
    else if(numero > seg_maior_elem && numero != maior_elem)
    {
        seg_maior_elem = numero;
    }

    if (scanf("%d", &numero) != 1) {
      printf("Erro a ler input.");
      return 1;
    }
  }
   if (seg_maior_elem != INT_MIN) {
        if (maior_elem == INT_MIN) { 
             printf("Não houve inteiros introduzidos\n");
        } else if (seg_maior_elem == maior_elem) {
            printf("Todos os números eram iguais ou poucas modicações.\n");
        } else {
            printf("O segundo maior da sequência é: %d\n", seg_maior_elem);
        }
    } else {
        printf("Não havia algarismos suficientes para distinguir.\n");
    }

  return 0;
}