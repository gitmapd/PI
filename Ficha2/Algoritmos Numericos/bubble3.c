#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// void printBars(int *arr, int size) {
//   printf("\n BUBBLE SORT \n\n");
//   for (int i = 0; i < size; i++) {
//   printf(" %d |", arr[i]);
// }
// }

int main() {
  int arr[] = {5, 7, 2, 4, 9, 6, 1, 8, 10};
  int n = 9;

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  for (int i = 0; i < 9; i++) {
    printf("%d\n", arr[i]);
  }
  return 0;
}
// void printBars(int *arr, int size) {
//   printf("\033[H\033[J");
//   printf("\n BUBBLE SORT \n\n");
//   for (int i = 0; i < size; i++) {
//     printf(" %d |", arr[i]);
//     printf("\033[1;036m");
//     for (int j = 0; j < arr[i]; j++)
//       printf("*");
//     printf("\033[3m \n");
//   }
//   usleep(200000);
// }

// int main() {
//   int arr[] = {5, 7, 2, 4, 9, 6, 1};
//   int n = 7;

//   for (int i = 0; i < n - 1; i++) {
//     for (int j = 0; j < n - i - 1; j++) {
//         printBars(arr, n);
//       if (arr[j] > arr[j + 1]) {
//         int temp = arr[j];
//         arr[j] = arr[j + 1];
//         arr[j + 1] = temp;
//       }
//     }
//   }
//   printBars(arr, n);
//   printf("\n Complete");

//   return 0;
// }