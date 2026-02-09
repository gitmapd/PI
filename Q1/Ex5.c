#include <stdio.h>

int strlens(char *s) {
  char *p = s;
  while (*p != '\0') {
    p++;
  }
  return p - s;
}
char *strcpy(char *s1, char *s2) {
  char *p = s1;
  while (*p++ = *s2++)
    ;
  return s1;
}

int strcmp(char *s1, char *s2) {
  while (*s1++ == *s2++) {
    if (*s1 == '\0') {
      return 0;
    }
    s1++;
    s2++;
  }
  return (unsigned char)*s1 - (unsigned char)*s2;
}
int main() {
  char s1[10] = "Wrld";
  char s2[10] = "World!";

  //strcpy(s1, s2);

  //printf("%s\n", s1);

  printf("%d\n", strcmp(s1, s2));

  printf("%d", strlens(s1));
  return 0;
}