#include <stdio.h>

int main() {
    int x,y;
    for(y = 0;y<8;y++) {
        for(x=0;x<8;x++)
        {
            if(x == 0 || x == 7 || y==0 || y==7 || x==y || x+y==7) {
                putchar('#');
            }else {
                putchar('.');
            }
        }
    putchar('\n');
    }

}