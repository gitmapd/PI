#include <stdio.h>
void corrige(char *s) {
    int alvo = 4683;
    int soma_atual = 0;
    int i;


    for (i = 0; s[i] != '\0'; i++) {
        soma_atual += (s[i] - '0');
    }

    int falta = alvo - soma_atual;

    // 2. Corrigir os zeros
    for (i = 0; s[i] != '\0' && falta > 0; i++) {
        if (s[i] == '0') {
            if (falta >= 9) {
                s[i] = '9';
                falta -= 9;
            } else {
                s[i] = (char)(falta + '0'); 
            }
        }
    }
}
int main() {
char s[]="932012";

corrige(s);

printf("%s\n",s);





}
