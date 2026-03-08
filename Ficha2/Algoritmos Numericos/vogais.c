    #include <stdio.h>
    #include <string.h>

    char *strchrs(char const *ch, int c) {

    while (*ch != '\0') {
        if (*ch == (char)c) {
        return (char *)ch;
        }
        ch++;
    }
    return 0;
    }

    int contaVogais(char *s) {
    int contador = 0;
    char *vogais = "aeiouAEIOU";

    while (*s != '\0') {
        if (strchrs(vogais, *s) != 0) {
        contador++;
        }
        s++;
    }
    return contador;
    }

    int retiraVogaisRep(char *s) {
    int j = 0;
    int removidas = 0;
    char *vogais = "aeiouAEIOU";

    for (int i = 0; s[i] != 0; i++) {
        if (strchrs(vogais, s[i]) == 0) {
        s[j] = s[i];
        j++;
        } else {
        removidas++;
        }
    }
    s[j] = '\0';

    return removidas;
    }

    int retiraVogaisRep2(char *s) {
    int i=0,j = 0;
    int removidas = 0;
    char *vogais = "aeiouAEIOU";

    while(s[i] != 0) {
        if (strchrs(vogais, s[i]) == 0) {
        s[j] = s[i];
        j++;
        } else {
        removidas++;
        }
        i++;
    }
    s[j] = '\0';
    return removidas;
    }

    int duplicaVogais(char *dest, char *src) {
    int i=0,j = 0;
    int acrescentadas = 0;
    char *vogais = "aeiouAEIOU";

    while(src[i] != 0) {
        dest[j] = src[i];
        j++;
        if (strchrs(vogais, src[i]) != 0) {
        dest[j] = src[i];
        j++;
        acrescentadas++;
        }
        i++;
    }
    dest[j] = '\0';
    return acrescentadas;
    }
    int main() {
    int x;
    char s1[100] = "Estaa e umaa string coom duuuplicadoos";
    char s2[100] = "C e fixe";
    char s3[200];

    printf("Testes\n");
    printf("A string \"%s\" tem %d vogais\n", s1, contaVogais(s1));

    x = retiraVogaisRep2(s1);
    printf("Foram retiradas %d vogais, resultando em \"%s\"\n", x, s1);

    x = duplicaVogais(s3,s2);
    printf("Foram acrescentadas %d vogais, resultando em \"%s\"\n", x, s3);

    printf("\nFim dos testes\n");
    }