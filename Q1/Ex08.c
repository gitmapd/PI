#include <stdio.h>

char *strcpy(char *dest, char *src) {
  char *p = dest;
  while (*p++ = *src++)
    ;
  return dest;
}

int main() {
  char s1[10];
  char s2[10] = "Worlsa!";

  strcpy(s1, s2);

  printf("%s\n", s1);

  return 0;
}