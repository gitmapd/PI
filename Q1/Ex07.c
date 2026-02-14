#include <stdio.h>

char *strcat(char s1[], char s2[]) {
  char *p = s1;
  while (*p != '\0') {
    p++;
  }
  while ((*p++ = *s2++))
    ;
  return s1;
}
int main() {
  char s1[10] = "Hello ";
  char s2[10] = "World!";

  printf("%s\n", s1);

  strcat(s1, s2);

  printf("%s\n", s1);

  return 0;
}