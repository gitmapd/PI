#include <stdio.h>
int is_vowel(char c) {
  if (c >= 'A' && c <= 'Z') {
    c = c + ('a' - 'A');
  }
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
    return 1;
  }
  return 0;
}

char *strnoV(char *s1) {
  char *read_ptr = s1;
  char *write_ptr = s1;

  while (*read_ptr != '\0') {
    if (!is_vowel(*read_ptr)) {
      *write_ptr = *read_ptr;
      write_ptr++;
    }
    read_ptr++;
  }
  *write_ptr = '\0';
  return s1;
}
int main() {
  char s1[20] = "Hello World";
  printf("%s\n", s1);

  printf("%s\n", strnoV(s1));
}