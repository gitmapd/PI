#include <stdio.h>

void findTwoSum(int nums[], int size, int target) {
  int esquerda = 0;
  int direita = size - 1;

  while (esquerda < direita) {
    int soma = nums[esquerda] + nums[direita];

    if (soma == target) {
      printf("Achamos! %d + %d = %d\n", nums[esquerda], nums[direita], soma);
      return;
    } else if (soma > target) {
      direita--;
    } else {
      esquerda++;
    }
  }
  printf("Nenhum par encontrado");
}

int main() {
  int arr[] = {2, 7, 11, 15};
  findTwoSum(arr, 4, 17);
  return 0;
}