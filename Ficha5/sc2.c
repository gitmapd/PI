#include <stdio.h>

int i = 10, j, k, l;

int main() {
  scanf("%d", &j);
  if (i < j)
    k = i + j;
  else
    k = i - j;
  l = 3 * k;
}