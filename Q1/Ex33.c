#include <stdio.h>

int main() {
  int x, y;
  x = 3;
  y = x + 1;
  x = x * y;
  y = x + y;
  printf("%d %d\n", x, y);
}