#include <stdio.h>

int strcmp(char s1[], char s2[]) {
  while (*s1 == *s2) {
    if (*s1 == '\0') {
      return 0;
    }
    s1++;
    s2++;
  }
  return (unsigned char)*s1 - (unsigned char)*s2;
}

int main() {
  char s1[10] = "World!";
  char s2[10] = "World!";

  printf("%d\n", strcmp(s1, s2));

  return 0;
}