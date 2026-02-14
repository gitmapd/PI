#include <stdio.h>
int qDig(unsigned int n) {
  int count = 0;
while (n != 0) {
  count++;
  n/=10;
}
return count;
}
int main() {
  int unsigned n = 440;
  printf("%d\n", qDig(n));
}