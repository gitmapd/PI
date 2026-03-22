#include <stdio.h>
int dec2bin(int n) {
  int c;
  for (c = 15; c >= 0; c--) {
    if ((n >> c) & 1)
      printf("1");
    else
      printf("0");
  }
  printf("\n");
}

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  if (n % 2 == 0)
    dec2bin(16);
  else
    dec2bin(44);

  return 0;
}