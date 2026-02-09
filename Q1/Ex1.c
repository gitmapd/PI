#include <stdio.h>
int bitsUm(unsigned int n) {
  int count = 0;
  while (n) {
    if(n & 1 ) {
      count++;
    }
    n>>=1;
  }
return count;
}
int main() {
  int unsigned n = 100;
  printf("%d\n", bitsUm(n));
}