#include <stdio.h>
char *sttrevs(char *s1) {

  int i = 0;
  char *p = s1;
  // while (s1[i] != '\0') {
  //   i++;
  // }
  while(*p != '\0') {
    p++;
    i++;
  }
  int length = i;

  int start = 0;
  int end = length - 1;
  char temp;

  while (start < end) {
    temp = s1[start];
    s1[start] = s1[end];
    s1[end] = temp;
    start++;
    end--;
  }
  return s1;
}

int main() {
  char s[] = "Hello";
  sttrevs(s);

  printf("%s\n", s);
}