#include <stdio.h>

int main() {
  int x, y;
  x = 3;
  y = 5;
  if (x > y)
    y = 6;
  printf("%d %d\n", x, y);
}