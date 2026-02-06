#include <stdio.h>

int main() {
  int x, y;
  x = y = 0;
  while (x != 11) {
    x = x + 1;
    y += x;
  }
  printf("%d %d\n", x, y);

  return 0;
}