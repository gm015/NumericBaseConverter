#include <stdio.h>

void    convert(int x, char bin[]) {

    int i = 0, pos = 0;
    for (; (pos = x >> i); ++i)
        printf("[ %d ] value: %d\n",i,pos);
    bin[0]='x';
    bin[1]='x';
    bin[2]='x';
    bin[3]='x';
    bin[4]='x';
    bin[5]='x';
    bin[6]='x';
    bin[7]='x';
    bin[8]='\0';

}

int main() {
    __int8_t     m[] = {256, 255, 150, 149, 99, 33};
    __int8_t     n[] = {128,64,32,16,8,4};
    __int8_t     o[] = {-1,-2,-4,-127,0,-128};

    char    a[7][9] = {0};

    convert(m[0],a[0]);
//    convert(n[0],a[0]);
//    convert(o[0],a[0]);

    printf("value: %s\n", (char *)a[0]);
    return 0;
}

