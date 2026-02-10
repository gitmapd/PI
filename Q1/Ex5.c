#include <stdio.h>
int trainlingZ(unsigned int n) {
  int count = 0;
  while (n > 0 && (n & 1)==0) {
      count++;
    n>>=1;
  }
return count;
}
int main() {
  int unsigned n = 8;
  printf("%d\n", trainlingZ(n));
}