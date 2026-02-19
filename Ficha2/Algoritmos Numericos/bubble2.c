void trocar(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbles(int *vec, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (vec[j] > vec[j + 1]) {
        trocar(&vec[j], &vec[j + 1]);
        printf("  [Troca: %d por %d]\n", vec[j], vec[j + 1]);
      }
    }
printf("Passda %d",i+1);
for(int k = 0; k < n;k++) {
        printf("%d", vec[k]);
      if (k < n - 1)
        printf(" -> ");
    }
printf("\n");
}
}
int main() {
    int bubbles[] = {5,2,3};
    bubble(bubbles,5);
    for(int i=0; i < 5;i++) {
        printf("%d",bubbles[i]);
    }
    


}