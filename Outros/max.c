#include <stdio.h>
#include <unistd.h>
typedef struct {
  int *data;
  int total;
} DataList;
void trocar(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void bubblesort(DataList *list) {
  for (int i = 0; i < list->total - 1; i++) {
    for (int j = 0; j < list->total - i - 1; j++) {
      if (list->data[j] > list->data[j + 1]) {
        printf("  [Troca: %d por %d]\n", list->data[j], list->data[j + 1]);
        trocar(&list->data[j], &list->data[j + 1]);
      }
    }
  }
}
int main() {
  int arr[] = {2, 7, 1, 4, 5, 6};
  int max = 0;
  DataList list;
  list.data = arr;
  list.total = sizeof(arr)/ sizeof(arr[0]);
  bubblesort(&list);
  for(int j = 0; j < list.total; j++) {
    printf("[%d]",arr[j]);
    if(j < list.total - 1) {
        printf(", ");
    }
  }
  printf("\n");
  sleep(3);
  for (int i = 0; i < list.total; i++) {
    if (arr[i] > arr[max])
      max = i;
  }
  printf("%d\n", arr[max]);
}