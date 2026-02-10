#include <stdio.h>

int soma(int a, int b)
{
  int soma;
  soma = a + b;
  return soma;
}

int subtrai(int a, int b)
{
  int sub;
  sub = a - b;
  return sub;
}

float divide(int a, int b) {
   float div;
   if (b == 0) {
    printf("Erro não pode dividir por zero\n");
    return 0;
   }
   div = a/b;
   return div;
}
int ler_inteiro(void)
{
  int a;
  printf("Introduza um numero inteiro: ");
  scanf("%d", &a);
  return a;
}

char ler_operacao(void)
{
  char op;
  printf("Introduza a operacao (+ ou -): ");
  scanf(" %c", &op);
  return op;
}

int calcula(int a, int b, char op)
{
  int r;

  if (op == '+') {
    r = soma(a, b);

  } else if (op == '-') {
    r = subtrai(a, b);
  }
  else if (op == '/') {
    r = divide(a, b);
  } else {
    r = -1;                     // faz sentido??
  }

  return r;
}

int main(void)
{
  int a, b, r;
  char op;

while (1) {

  op = ler_operacao();
  if (op == 'q' || op == 'Q') {
    break;
  }
  a = ler_inteiro();
  b = ler_inteiro();
  r = calcula(a, b, op);
  printf("Resultado: %d\n", r);
}
  return 0;
}