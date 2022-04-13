#include <stdio.h>

int main(){
    double d = 7.723;
    int i = 27;
    char ch = 'f';

    printf("Double: %f\n", d);
    printf("Integer: %d\n", i);
    printf("Character: %c\n", ch);

    printf("Double sizeof: %zu\n", sizeof(d));
    printf("Integer sizeof: %zu\n", sizeof(i));
    printf("Character sizeof: %zu\n", sizeof(ch));

    double* p_d = &d;
    int* p_i = &i;
    char* p_ch = &ch;


    printf("Double pointer adress: %p\n", &p_d);
    printf("Integer pointer adress: %p\n", &p_i);
    printf("Character pointer adress: %p\n", &p_ch);


    printf("Double pointer value: %f\n", *p_d);
    printf("Integer pointer value: %d\n", *p_i);
    printf("Character pointer value: %c\n", *p_ch);

    printf("Double sizeof: %zu\n", sizeof(p_d));
    printf("Integer sizeof: %zu\n", sizeof(p_i));
    printf("Character sizeof: %zu\n", sizeof(p_ch));
    
    return 0;
}