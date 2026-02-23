#include <stdio.h>

int main() {
  int i, j, *a, *b;
  i = 3;
  j = 5;
  a = b = 42;
  a = &i;
  b = &j;
  i++;
  j = i + *b;
  b = a;
  j = j + *b;
  printf("%d\n", j);
  return 0;
}