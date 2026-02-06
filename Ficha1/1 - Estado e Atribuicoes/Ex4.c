#include <stdio.h>

int main() {
  int x, y;
  x = 200;
  y = 100;
  x = x + y;
  y = x - y;
  x = x - y;
  printf("%d %d\n", x, y);
}