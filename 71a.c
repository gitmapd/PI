#include <stdio.h>

int strlens(char *s) {
  char *p = s;
  while (*p != '\0') {
    p++;
  }
  return p - s;
}

void abreviar(char *s) {
  int n = strlens(s);
  if (n > 10) {
    printf("%c%d%c\n", s[0], n - 2, s[n - 1]);
  } else {
    printf("%s\n", s);
  }
}
int main() {
  char *palavras[] = {"word", "localization", "internationalization",
                      "pneumonoultramicroscopicsilicovolcanoconiosis"};

 for(int i = 0; i <4;i++) {
        abreviar(palavras[i]);
 }
}