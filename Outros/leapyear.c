#include <stdio.h>

int main() {
  int y = 0;
  int b = 8;
  int valor = 0;
  int nums[] = {1, 2, 3, 4, 5};
  printf("Enter Year: ");
  scanf("%d", &y);

  if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
    printf("Its a leap year\n");
  } else {
    printf("Not a leap year\n");
  }
  for (int i = 0; i < 5; i++) {
    valor = valor + b * nums[i];
  }
  printf("%d", valor);
  return 0;
}