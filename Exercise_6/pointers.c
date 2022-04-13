#include <stdio.h>

int main(){
    int* a;
    int* b;
    int c = 5;
    a = &c;
    c++;
    *a = -10;
    b = &c;
    c = 15;
    *b = *a / 2;
    printf("%d -- %d\n", *a, *b);
    return 0;
}