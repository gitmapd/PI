#include <stdio.h>

int func(int x) {
    int r = 0;
    while( x > 0) {
        r+=2;
        x = x -r;
    }
return r;
}
int main() {
int a = 7;
int b = 8;
int c = 9;
int d = 10;
int e = 11;
int f = 12;


printf("%d",func(a));
printf("%d",func(b));
printf("%d",func(c));
printf("%d",func(d));
printf("%d",func(e));
printf("%d",func(f));
}